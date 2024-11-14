//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Dec 1st, 2021
// Project: 			Assembly Line Simulation
// Module:				LineManager
// Filename:			LineManager.cpp
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

#include <fstream>
#include <algorithm>
#include <utility>
#include "Utilities.h"
#include "LineManager.h"
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream fin(file); 
		if (!fin) {
			throw std::string("File not found");
		}
		std::string line{};
		Utilities utils; 
		utils.setDelimiter('|');

		while (std::getline(fin, line)) {
			bool more = true;
			size_t pos = 0u;
			/*
			// Can be also implemented as: (Changed due to only able to use one while loop)
			Workstation* temp{nullptr};
			Workstation* current_ws{nullptr};
			while (more) {
				std::string workstation = utils.extractToken(line, pos, more);
				temp = *std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
					return ws->getItemName() == workstation;
					});
				
				if (current_ws && temp != current_ws) {
					current_ws->setNextStation(temp);
				}
				else {
					current_ws = temp;
				}
			}
			*/
			std::string workstation = utils.extractToken(line, pos, more);
			Workstation* current_ws = *std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
				return ws->getItemName() == workstation;
				});
			if (more) {
				std::string next_workstation = utils.extractToken(line, pos, more);
				Workstation* next_ws = *std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
					return ws->getItemName() == next_workstation;
					});
				current_ws->setNextStation(next_ws);
			}
			activeLine.push_back(current_ws);
		}
		m_firstStation = activeLine.front();
		m_cntCustomerOrder = pending.size();
	}

	void LineManager::linkStations()
	{
		std::vector<Workstation*> organized; 
		Workstation* temp = m_firstStation;
		while (temp) {
			organized.push_back(temp);
			temp = temp->getNextStation();
		}
		activeLine = organized; 
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t counter{ 0u };
		os << "Line Manager Iteration: " << ++counter << std::endl;
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front(); 
		}
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* ws) {
			ws->fill(os);
			});
		std::for_each(activeLine.begin(), activeLine.end(), [](Workstation* ws) {
			ws->attemptToMoveOrder();
			});
		return m_cntCustomerOrder == (completed.size() + incomplete.size());
	}

	void LineManager::display(std::ostream& os) const
	{
		std::for_each(activeLine.cbegin(), activeLine.cend(), [&](const Workstation* w) {
			w->display(os);
			});
	}
}