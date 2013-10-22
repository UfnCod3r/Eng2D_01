#pragma once
#include "XBasic.h"

namespace X
{
	//Thread Access Control
	class TAC
	{
		CRITICAL_SECTION	m_csec;

	public:
		void init()			{ ::InitializeCriticalSection(&m_csec);		}
		void release()		{ ::DeleteCriticalSection(&m_csec);			}
		void lock()			{ ::EnterCriticalSection(&m_csec);			}
		void unlock()		{ ::LeaveCriticalSection(&m_csec);			}
	};

};