#pragma once
#include "XBasic.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////Thread Access Control
	class TAC
	{
		CRITICAL_SECTION	m_csec;

	public:
		void init()			{ ::InitializeCriticalSection(&m_csec);		}
		void release()		{ ::DeleteCriticalSection(&m_csec);			}
		void lock()			{ ::EnterCriticalSection(&m_csec);			}
		void unlock()		{ ::LeaveCriticalSection(&m_csec);			}
	};

	//////////////////////////////////////////////////////////////////////////TACScopedLock
	class TACScopedLock
	{
		TAC& m_tac;
	public:
		TACScopedLock(TAC& t) : m_tac(t) { m_tac.lock(); }
		~TACScopedLock() { m_tac.unlock(); }
	};


	//////////////////////////////////////////////////////////////////////////IThread
	class IThread
	{
		HANDLE	m_handle;
		DWORD	m_id;
		


		static DWORD WINAPI ThreadFunc(IThread* t) { t->onExec(); return 1; }

	public:
		void run() { m_handle = ::CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, this, 0, &m_id); }

		inline HANDLE	getHandle() const	{ return m_handle;	}
		inline uint		getId() const		{ return m_id;		}

		IThread() : m_handle(0), m_id(0) {}
		~IThread() { close(); }

		void suspend()	{ ::SuspendThread(m_handle); }
		void resume()	{ ::ResumeThread(m_handle); }
		void close()
		{
			if(m_handle) ::CloseHandle(m_handle);
			m_handle = nullptr;
			m_id = 0;
		}

	protected:
		virtual void onExec(){}
	};

	//////////////////////////////////////////////////////////////////////////Atomic
	typedef long Atomic;
	inline Atomic Atomic_Inc(volatile Atomic* a)				{ return ::InterlockedIncrement(a); }
	inline Atomic Atomic_Dec(volatile Atomic* a)				{ return ::InterlockedDecrement(a); }
	inline Atomic Atomic_Set(volatile Atomic* a, long value)	{ ::InterlockedExchange(a, value); return value; }

	inline void ThisThread_Sleep(uint milliseconds) { ::Sleep(milliseconds); }
	inline uint ThisThread_ID() { return ::GetCurrentThreadId(); }


	class  WaitEvent
	{
		HANDLE	m_handle;
	public:
		void init()					{ m_handle = ::CreateEvent(nullptr, true, true, nullptr); }
		void release()				{ ::CloseHandle(m_handle);	}
		void waiting()				{ ::WaitForSingleObject(m_handle, INFINITE); }
		void setWaitable()			{ ::ResetEvent(m_handle);	}
		void breakWaits()			{ ::SetEvent(m_handle); }
	};
};