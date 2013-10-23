#pragma 

#include "XArray.h"
#include "XString.h"

namespace X
{
	//////////////////////////////////////////////////////////////////////////NameManager
	class NameManager
	{
	public:
		static const uint MAX_NAME_LENGTH = 128;

		struct Instance : UseGenericAllocator<GGenericAllocator>
		{
			uint		m_index;
			uint		m_strLen;
			uint		m_hash;
			int			m_refCount;
			char		m_cstr[MAX_NAME_LENGTH];
		};
		
	private:


		Vector<uint>		m_hashes;
		Vector<Instance*>	m_instances;

	public:

		void init();
		void release();
		
		Instance*	getDefaultInstance() const;
		Instance*	getInstance(uint index);
		Instance*	createNewInstance(const char* str);
		Instance*	findInstance(uint strhash);
		uint		instanceCount() const;
		void		releaseUnusedInstance();
	};
	extern NameManager GNameManager;



	//////////////////////////////////////////////////////////////////////////Name
	class Name
	{
		NameManager::Instance*	m_pInstance;

	public:
		const char* cstr() const	{ return m_pInstance->m_cstr;		}
		uint length() const			{ return m_pInstance->m_strLen;		}
		uint hash() const			{ return m_pInstance->m_hash;		}
		int	 refCount() const		{ return m_pInstance->m_refCount;	}

		bln  isEmpty() const { return m_pInstance == GNameManager.getDefaultInstance(); }

		Name()					{ m_pInstance = GNameManager.getDefaultInstance();	}
		Name(const char* s)		{ m_pInstance = GNameManager.createNewInstance(s);	}
		Name(const Name& n)
		{
			m_pInstance = n.m_pInstance;
			m_pInstance->m_refCount++;
		}

		Name& operator = (const Name& n)
		{
			m_pInstance->m_refCount--;
			m_pInstance = n.m_pInstance;
			m_pInstance->m_refCount++;
			return *this;
		}
		Name& operator = (const char* str)
		{
			m_pInstance->m_refCount--;
			m_pInstance = GNameManager.createNewInstance(str);
			return *this;
		}
		
		bln operator == (const Name& name) { return m_pInstance == name.m_pInstance; }
		bln operator != (const Name& name) { return m_pInstance != name.m_pInstance; }
	};
};
