#pragma once

#include "XBasic.h"

namespace X
{
	class Console
	{
		HANDLE	m_hConsole;

	public:

		void init();
		void release();

		void setFocus();
		void clear();
		void show();
		void hide();

		void printMessage(char* format, ...) const;
		void printWarning(char* format, ...) const;
		void printError(char* format, ...) const;
		void printSuccess(char* format, ...) const;
	};
	extern Console GConsole;
};
