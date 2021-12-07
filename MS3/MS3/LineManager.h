//==============================================
// Name:				CJ Jingren Tong	
// Seneca Student ID:	152464194
// Seneca email:		jtong22@myseneca.ca
// Date of completion:	Dec 1st, 2021
// Section:				OOP345NAA
// OOP Project 
// Module:				LineManager
// Filename:			LineManager.h
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

#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__
#include <vector>
#include "Workstation.h"
namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder; 
		Workstation* m_firstStation;
	public: 
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os); 
		void display(std::ostream& os)const;
	};
}
#endif
