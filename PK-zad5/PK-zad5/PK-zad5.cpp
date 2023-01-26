#include "Singleton.h"
#include "smartptr.h"
#include <iostream>
#include <string.h>

template<class T>
std::ostream& operator << (std::ostream& out, ap::SmartPtr<T>& smartPtr) {
	if ((T*)smartPtr != nullptr) out << *smartPtr;
	else out << "(nullptr)";
	return out;
}
std::string str(const std::string* s) {
	return s == nullptr ? "(nullptr)" : *s;
}
int main() {
	std::string* s1 = nullptr;
	std::string* s2 = nullptr;
	std::cout << "s1: " << str(s1) << std::endl;
	std::cout << "s2: " << str(s2) << std::endl;
	{
		s1 = new std::string("asdasdasdasdadasdasdasd");
		s2 = new std::string("12312321");
		std::cout << "s1: " << str(s1) << std::endl;
		std::cout << "s2: " << str(s2) << std::endl << std::endl;
		ap::SmartPtr<std::string> sp(new std::string("aaaa"));
		ap::SmartPtr<std::string> sp1(s1);
		std::cout << "s1: " << str(s1) << std::endl;
		std::cout << "s2: " << str(s2) << std::endl;
		std::cout << "sp: " << sp << std::endl;
		std::cout << "sp1: " << sp1 << std::endl << std::endl;
		sp = std::move(sp1);
		std::cout << "s1: " << str(s1) << std::endl;
		std::cout << "s2: " << str(s2) << std::endl;
		std::cout << "sp: " << sp << std::endl;
		std::cout << "sp1: " << sp1 << std::endl << std::endl;

		sp = s2;
		//std::cout << "s1: " << str (s1) << std::endl; //po odkomentowaniu ta instrukcja powinna powodowa ć błąd
		std::cout << "s2: " << str(s2) << std::endl;
		std::cout << "sp: " << sp << std::endl;
		std::cout << "sp1: " << sp1 << std::endl << std::endl;
	}
	//delete s2;//po odkomentowaniu ta instrukcja powinna powodowa ć błąd
	//delete s1;//po odkomentowaniu ta instrukcja powinna powodowa ć błąd
}