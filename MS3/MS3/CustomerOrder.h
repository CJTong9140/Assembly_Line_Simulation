//==============================================
// Name:				CJ Jingren Tong	
// Seneca Student ID:	152464194
// Seneca email:		jtong22@myseneca.ca
// Date of completion:	Nov 17th, 2021
// Section:				OOP345NAA
// OOP Project 
// Module:				CustomerOrder
// Filename:			CustomerOrder.h
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

#ifndef SDDS_CUSTOMERORDER_H__
#define SDDS_CUSTOMERORDER_H__
#include <iostream>
#include <string>
#include "Station.h"
namespace sdds {
	class CustomerOrder {
		struct Item
		{
			std::string m_itemName{};
			size_t m_serialNumber{ 0 }; 
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src){}
		};
		std::string m_name{}; 
		std::string m_product{}; 
		size_t m_cntItem{ 0u };
		Item** m_lstItem{nullptr};
		static size_t m_widthField;
	public: 
		CustomerOrder(){}
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& cp) { throw "Copy construtor is not allowed!"; }
		CustomerOrder& operator = (const CustomerOrder& cp) = delete;
		CustomerOrder(CustomerOrder&& mv)noexcept;
		CustomerOrder& operator = (CustomerOrder&& mv)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif
