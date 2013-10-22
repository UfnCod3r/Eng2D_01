#include "XMath.h"
#include "XArray.h"
#include <iostream>
#include "XList.h"

int main(int argc, char** argv)
{
	X::gGenericAllocator.init();
// 	X::gTempAllocator.init(4096*4096);

	X::Vector<int> vec;
	X::Vector<int> vec2;

	vec.flushBuffer();
	for (int i = 0; i < 10; i++)
	{
		vec.push(i);
	}
	vec2 = vec;
	for (int i = 0; i < vec2.length(); i++)
	{
		std::cout << vec2[i];
	}
	vec.clear();
	vec2.clear();

// 	int* ptr = (int*)X::gGenericAllocator.alloc(sizeof(int[100]));
// 	*ptr = 45;
// 	std::cout << *ptr;
// 	X::gGenericAllocator.free(ptr);
	
	::system("pause");
	X::gGenericAllocator.release();
}