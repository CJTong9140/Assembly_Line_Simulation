//==============================================
// Name:				CJ Jingren Tong	
// Seneca Student ID:	152464194
// Seneca email:		jtong22@myseneca.ca
// Date of completion:	Nov 15th, 2021
// Section:				OOP345NAA
// OOP Project MS1
// Module:				Utilities
// Filename:			Utilities.h
// ----------------------------------------------
// Revision History
// Date					Reason
// 2021/11/14			Completed and tested Utilities module
// 2021/11/15			Completed and tested Station module
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
