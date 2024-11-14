//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 15th, 2021
// Project: 			Assembly Line Simulation
// Module:				Station
// Filename:			Station.cpp
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

#include <algorithm>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace sdds {
	size_t Station::m_widthField{ 0u };
	int Station::id_generator{ 0 };

	Station::Station(const std::string& str)
	{
		Utilities util; 
		size_t pos = 0u; 
		bool more = true; 

		m_itemName = util.extractToken(str, pos, more);
		m_serialNum = std::stoul(util.extractToken(str, pos, more)); 
		m_numOfItems = std::stoul(util.extractToken(str, pos, more));
		Station::m_widthField = std::max(Station::m_widthField, util.getFieldWidth());
		m_desc = util.extractToken(str, pos, more); 
		m_id = ++Station::id_generator; 
	}

	void Station::updateQuantity()
	{
		if (m_numOfItems)
			m_numOfItems--;
		else
			m_numOfItems = 0u; 
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << '[' << std::right << std::setw(3) << std::setfill('0') << m_id 
			<< "] Item: " << std::left << std::setw(Station::m_widthField) << std::setfill(' ') << m_itemName
			<< " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNum << ']';
		if (full) {
			os << " Quantity: " << std::left << std::setfill(' ') << std::setw(Station::m_widthField) << m_numOfItems << " Description: " << m_desc;
		}
		os << std::endl; 
	}
}