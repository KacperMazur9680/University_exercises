#include <iostream>
#include "Vector.h"

template <typename T>
void out(Vector<T>& v, std::string type) {
	T* w = v.Data();
	std::cout << type << std::endl;
	for (size_t i = 0; i < v.Size(); i++)
	{
		std::cout << *w << std::endl;
		w++;
	}
	std::cout << std::endl;
}

template <typename T>
void out_mem(Vector<T>& v, std::string type) {
	T* w = v.Data();
	std::cout << type << std::endl;
	for (size_t i = 0; i < v.Size(); i++)
	{
		std::cout << w << " = " << *w << std::endl;
		w++;
	}
	std::cout << std::endl;
}

int main()
{


	/*Vector<int> v(5, 10);
	for(auto& el: v)*/
}
