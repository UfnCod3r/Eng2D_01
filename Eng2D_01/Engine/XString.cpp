#include "XString.h"

namespace X
{
	size_t StrHash( const char* str )
	{
		XASSERT(str);
		size_t hash = 0;
		while (*str)
		{
			hash = ((hash << 5) + hash) + *str;
			str++;
		}
		return hash;
	}

};