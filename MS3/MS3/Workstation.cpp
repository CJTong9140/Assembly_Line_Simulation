//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 30th, 2021
// Project: 			Assembly Line Simulation
// Module:				Workstation
// Filename:			Workstation.cpp
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
#include "Workstation.h"

namespace sdds {
	std::deque<CustomerOrder> pending;
	std::deque<CustomerOrder> completed;
	std::deque<CustomerOrder> incomplete;
	Workstation::Workstation(const std::string& str) : Station(str){}

	// Fill the order at the front of m_orders if the work station is not empty
	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}

	// Check to see if we can move the order in the front to the next station
	bool Workstation::attemptToMoveOrder()
	{
		bool move = false; 
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(this->getItemName()) || !getQuantity()) {
				if (m_pNextStation) {
					*m_pNextStation += std::move(m_orders.front());
				}
				else {
					if (m_orders.front().isFilled()) {
						completed.push_back(std::move(m_orders.front()));
					}
					else {
						incomplete.push_back(std::move(m_orders.front()));
					}
				}
				m_orders.pop_front();
				move = true;
			}
		}
		return move;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << this->getItemName() << " --> "
			<< (m_pNextStation ? m_pNextStation->getItemName() : "End of Line")
			<< std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this; 
	}
}