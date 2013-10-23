#include "XName.h"

namespace X
{
	NameManager GNameManager;


	void NameManager::init()
	{
		m_hashes.extendBuffer(128);
		m_instances.extendBuffer(128);
		Instance* lInsEmpty = new Instance;
		XZEROOBJECT(lInsEmpty);
		m_hashes.push(0);
		m_instances.push(lInsEmpty);
	}

	void NameManager::release()
	{
		for (uint i = 0; i < m_instances.length(); i++) 
			delete m_instances[i];
		m_instances.clear();
		m_hashes.clear();
	}

	NameManager::Instance* NameManager::getDefaultInstance() const
	{
		return m_instances[0];
	}

	NameManager::Instance* NameManager::getInstance( uint index )
	{
		return m_instances[index];
	}

	NameManager::Instance* NameManager::createNewInstance( const char* s )
	{
		if(s == nullptr) return getDefaultInstance();

		uint lHash = StrHash(s);
		Instance* lIns = findInstance(lHash);
		if(lIns)
		{
			lIns->m_refCount++;
			return lIns;
		}
		
		lIns = new Instance;
		lIns->m_index = m_instances.length();
		size_t lSLen = StrLen(s);
		lIns->m_strLen = lSLen;
		lIns->m_hash = lHash;
		lIns->m_refCount = 1;
		::memcpy(lIns->m_cstr, s, lSLen+1);
		m_hashes.push(lHash);
		m_instances.push(lIns);
		return lIns;
	}

	NameManager::Instance* NameManager::findInstance( uint hash )
	{
		for (uint i = 0; i < m_hashes.length(); i++) 
			if(m_hashes[i] == hash)
				return m_instances[i];
		return nullptr;
	}

	uint NameManager::instanceCount() const
	{
		return m_instances.length();
	}

	void NameManager::releaseUnusedInstance()
	{
		//@Note m_instances[0] == Default Instance

		uint lLen =  m_instances.length();
		for (uint i = 1; i < lLen; i++)
		{
			if(m_instances[i]->m_refCount < 0)
			{
				delete m_instances[i];
				m_hashes.removeAt(i);
				m_instances.removeAt(i);
				i--;
				lLen--;
			}
		}
	}

};