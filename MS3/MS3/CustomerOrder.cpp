//==============================================
// Name:				CJ Jingren Tong	
// Seneca Student ID:	152464194
// Seneca email:		jtong22@myseneca.ca
// Date of completion:	Nov 17th, 2021
// Section:				OOP345NAA
// OOP Project 
// Module:				CustomerOrder
// Filename:			CustomerOrder.cpp
// ----------------------------------------------
// Revision History
// Date					Reason
// 2021/11/14			Completed and tested Utilities module
// 2021/11/15			Completed and tested Station module
// 2021/11/17			Completed and tested CustomerOrder module
// 2021/11/30			Completed and tested Workstation module
// 2021/12/01			Completed and tested LineManager module
// 2021/12/04			Modified the LineManager constructor. 
// I confirm that I am the only author of this file
// and the content was created entirely by me.
//==============================================

#include <utility>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
namespace sdds {
	size_t CustomerOrder::m_widthField{ 0u };
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util;
		size_t pos = 0u; 
		bool more = true;
		std::string tempStr; 
		
		m_name = util.extractToken(str, pos, more);
		m_product = util.extractToken(str, pos, more);

		while (more) {
			Item** temp = new Item * [m_cntItem + 1];
			if (m_cntItem > 0)
			{
				std::copy(m_lstItem, m_lstItem + m_cntItem, temp);
				delete[] m_lstItem;
			}
			temp[m_cntItem] = new Item(util.extractToken(str, pos, more));
			m_cntItem++;
			m_lstItem = temp;
		}
		CustomerOrder::m_widthField = (util.getFieldWidth() > CustomerOrder::m_widthField ? util.getFieldWidth() : CustomerOrder::m_widthField); 
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& mv) noexcept
	{
		*this = std::move(mv); 
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& mv) noexcept
	{
		if (this != &mv) {
			if (m_lstItem) {
				for (auto* it = m_lstItem; it < &m_lstItem[m_cntItem]; ++it)
					delete* it;
			}
			delete[] m_lstItem; 

			m_name = mv.m_name;
			mv.m_name = "";

			m_product = mv.m_product;
			mv.m_product = "";

			m_cntItem = mv.m_cntItem;
			mv.m_cntItem = 0u;

			m_lstItem = mv.m_lstItem;
			mv.m_lstItem = nullptr; 
		}
		return *this; 
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem) {
			for (auto* it = m_lstItem; it < &m_lstItem[m_cntItem]; ++it)
				delete* it;
		}
		delete[] m_lstItem;
	}

	// Checking if all the items in the customer order have been filled
	bool CustomerOrder::isFilled() const
	{
		return std::all_of(m_lstItem, m_lstItem + m_cntItem, [](const Item* item){
			return item->m_isFilled;
			});
	}

	// Checking if all the items that match itemName in the customer order have been filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		return std::all_of(m_lstItem, m_lstItem + m_cntItem, [=](const Item* item) {
			return item->m_itemName != itemName || item->m_isFilled;
			}); 
	}

	// Fill item information if the item handled by the station match with one item in the customer order
	// Basically just checking if the item exist in inventory (station)
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](Item* item) {
			if (item->m_itemName == station.getItemName()) {
				if (station.getQuantity() >= 1) {
					item->m_serialNumber = station.getNextSerialNumber();
					item->m_isFilled = true;
					station.updateQuantity();
					std::cout << "    Filled ";
				}
				else {
					std::cout << "    Unable to fill ";
				}
				std::cout << m_name << ", " << m_product << " [" << item->m_itemName << ']' << std::endl;
			}
			}); 
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl; 
		std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) {
			os << '[' << std::right << std::setw(6) << std::setfill('0') << item->m_serialNumber << "] " 
				<< std::left << std::setw(m_widthField) << std::setfill(' ') << item->m_itemName << " - "
				<< (item->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
			});
	}

}