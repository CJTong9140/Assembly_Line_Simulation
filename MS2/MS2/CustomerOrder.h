//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 17th, 2021
// Project: 			Assembly Line Simulation
// Module:				CustomerOrder
// Filename:			CustomerOrder.h
// ----------------------------------------------
// Revision History
// Date					Reason
// 2021/11/14			Completed and tested Utilities module
// 2021/11/15			Completed and tested Station module
// 2021/11/17			Completed and tested CustomerOrder module
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
		CustomerOrder(const CustomerOrder& cp) { throw std::string("Copy construtor is not allowed!"); }
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
