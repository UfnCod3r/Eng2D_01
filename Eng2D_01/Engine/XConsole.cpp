#include "XConsole.h"
#include <iostream>

namespace X
{
	Console GConsole;

	const WORD CONSOLE_COLOR_GREEN	= 10;
	const WORD CONSOLE_COLOR_WHITE	= 7;
	const WORD CONSOLE_COLOR_YELLOW	= 14;
	const WORD CONSOLE_COLOR_RED	= 12;


	void Console::init()
	{
		m_hConsole = ::GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void Console::release()
	{

	}

	void Console::setFocus()
	{

	}

	void Console::clear()
	{

	}

	void Console::show()
	{

	}

	void Console::hide()
	{

	}

	void Console::printMessage( char* format, ... ) const
	{
		va_list args;
		va_start (args, format);
		std::vprintf (format, args);
		va_end (args);
	}

	void Console::printWarning( char* format, ... ) const
	{
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_YELLOW);
		va_list args;
		va_start (args, format);
		std::vprintf (format, args);
		va_end (args);
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_WHITE);
	}

	void Console::printError( char* format, ... ) const
	{
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_RED);
		va_list args;
		va_start (args, format);
		std::vprintf (format, args);
		va_end (args);
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_WHITE);
	}

	void Console::printSuccess( char* format, ... ) const
	{
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_GREEN);
		va_list args;
		va_start (args, format);
		std::vprintf (format, args);
		va_end (args);
		::SetConsoleTextAttribute(m_hConsole, CONSOLE_COLOR_WHITE);
	}

}