//==============================================
// Name:				CJ Jingren Tong
// Date of completion:	Nov 14th, 2021
// Project: 			Assembly Line Simulation
// Module:				Utilities
// Filename:			Utilities.h
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

#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__
#include <string>
namespace sdds {
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter; 
	public: 
		void setFieldWidth(size_t newWidth) { m_widthField = newWidth; }
		size_t getFieldWidth() const { return m_widthField; }
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }
		static char getDelimiter() { return m_delimiter; }
	};
}
#endif 

