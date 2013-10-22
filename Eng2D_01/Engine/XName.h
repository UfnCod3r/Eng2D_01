#pragma 

#include "XArray.h"

namespace X
{
	class Name
	{
	public:
		static const uint MAX_NAME_LENGTH = 128;

		struct Instance
		{
			uint	m_index;
			uint	m_strLen;
			char	m_cstr[MAX_NAME_LENGTH];
		};

	private:

		static Array<uint>			Hashes;
		static Array<Instance>		Instances;

		Instance*	m_instance;

	public:
		inline const char* cstr() const		{ return m_instance->m_cstr;	}
		inline uint length() const			{ return m_instance->m_strLen;	}
		inline uint hash() const;
	};
};
