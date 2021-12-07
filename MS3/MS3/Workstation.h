//==============================================
// Name:				CJ Jingren Tong	
// Seneca Student ID:	152464194
// Seneca email:		jtong22@myseneca.ca
// Date of completion:	Nov 30th, 2021
// Section:				OOP345NAA
// OOP Project 
// Module:				Workstation
// Filename:			Workstation.h
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

#ifndef SDDS_WORKSTATION_H__
#define SDDS_WORKSTATION_H__
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
	// orders to be placed onto the assembly line at the first station
	extern std::deque<CustomerOrder> pending;
	// orders have been removed from last station, have been filled 
	extern std::deque<CustomerOrder> completed;
	// orders have been removed from last station, could not be filled
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{ nullptr };
	public: 
		Workstation(const std::string& str);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		// Set the next Workstation to the address of station
		void setNextStation(Workstation* station = nullptr) { m_pNextStation = station; }
		// Return the address of next Workstation
		Workstation* getNextStation() const { return m_pNextStation; }
		void display(std::ostream& os)const;
		Workstation& operator += (CustomerOrder&& newOrder);

		// Workstation object represents a single location on the assembly line, the object cannot be copied or moved
		Workstation(const Workstation& cp) = delete; 
		Workstation& operator = (const Workstation& cp) = delete;
		Workstation(Workstation&& mv) = delete;
		Workstation& operator = (Workstation&& mv) = delete;
	};
}
#endif
