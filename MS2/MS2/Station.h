//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 15th, 2021
// Project: 			Assembly Line Simulation
// Module:				Station
// Filename:			Station.h
// ----------------------------------------------
// Revision History
// Date					Reason
// 2021/11/14			Completed and tested Utilities module
// 2021/11/15			Completed and tested Station module		
// 2021/11/17			Completed and tested CustomerOrder module
// I confirm that I am the only author of this file
// and the content was created entirely by me.
//==============================================

#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__
#include <iostream>
#include <string>
namespace sdds {
	// Station object manages single station on the assembly line. 
	// Each station handles a specific item for filling customer orders.
	class Station {
		int m_id{};
		std::string m_itemName{}; 
		std::string m_desc{}; 
		size_t m_serialNum{}; 
		size_t m_numOfItems{};
		static size_t m_widthField; 
		static int id_generator;
	public: 
		Station(const std::string& str);
		const std::string& getItemName() const { return m_itemName; }
		size_t getNextSerialNumber() { return m_serialNum++; }
		size_t getQuantity() const { return m_numOfItems; }
		void updateQuantity();
		void display(std::ostream& os, bool full)const; 
	}; 
}
#endif
