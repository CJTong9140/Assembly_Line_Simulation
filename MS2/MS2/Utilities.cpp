//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 14th, 2021
// Project: 			Assembly Line Simulation
// Module:				Utilities
// Filename:			Utilities.cpp
// ----------------------------------------------
// Revision History
// Date					Reason
// 2021/11/14			Completed and tested Utilities module
// 2021/11/15			Completed and tested Station module
// 2021/11/17			Completed and tested CustomerOrder module
// I confirm that I am the only author of this file
// and the content was created entirely by me.
//==============================================

#include <algorithm>
#include "Utilities.h"
namespace sdds {
	char Utilities::m_delimiter{}; 

	// Extract a token from a string starting from certain position based on its delimiter
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string temp{};
		if (next_pos < str.length()) {
			size_t found = str.find_first_of(m_delimiter, next_pos);
			if (found != std::string::npos) {
				if (next_pos != found) {
					temp = str.substr(next_pos, found - next_pos);
					next_pos = found + 1;
					more = true;
				}
				else {
					more = false; 
					throw next_pos;
				}
			}
			else {
				temp = str.substr(next_pos);
				more = false; 
			}
			m_widthField = std::max(temp.length(), m_widthField);
		}
		else {
			more = false;
			throw "Outside of bounds!"; 
		}
		return temp; 
	}
}