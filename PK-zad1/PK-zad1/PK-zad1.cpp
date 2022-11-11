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
	std::cout << "Konstruktor przyjmujacy jeden parametr:" << std::endl;
	Vector<double> v_d(3);
	Vector<int> v_i(3);
	Vector<std::string> v_s(3);
	out(v_d, "Double");
	out(v_i, "Int");
	out(v_s, "String");

	std::cout << "Konstruktor przyjmujacy dwa parametry:" << std::endl;
	Vector<double> v_d1(3, 5.1234);
	Vector<int> v_i1(3, 13);
	Vector<std::string> v_s1(3, "PK");
	out(v_d1, "Double");
	out(v_i1, "Int");
	out(v_s1, "String");
	
	std::cout << "Konstruktor kopiujacy:" << std::endl;
	Vector<double> v_d2 = v_d1;
	Vector<int> v_i2 = v_i1;
	Vector<std::string> v_s2 = v_s1;
	out(v_d2, "Double");
	out(v_i2, "Int");
	out(v_s2, "String");

	std::cout << "Konstruktor przenoszacy:" << std::endl;
	out_mem(v_d1, "Double");
	out_mem(v_i1, "Int");
	out_mem(v_s1, "String");

	Vector<double> v_d3(std::move(v_d1));
	Vector<int> v_i3(std::move(v_i1));
	Vector<std::string> v_s3(std::move(v_s1));

	out(v_d1, "Double");
	out(v_i1, "Int");
	out(v_s1, "String");

	out_mem(v_d3, "Double");
	out_mem(v_i3, "Int");
	out_mem(v_s3, "String");

	std::cout << "Operator przypisania:" << std::endl;
	v_d = v_d3;
	v_i = v_i3;
	v_s = v_s3;
	out(v_d, "Double");
	out(v_i, "Int");
	out(v_s, "String");

	std::cout << "Operator przeniesienia:" << std::endl;
	out_mem(v_d3, "Double");
	out_mem(v_i3, "Int");
	out_mem(v_s3, "String");

	v_d1 = std::move(v_d3);
	v_i1 = std::move(v_i3);
	v_s1 = std::move(v_s3);

	out_mem(v_d1, "Double");
	out_mem(v_i1, "Int");
	out_mem(v_s1, "String");

	std::cout << "Operator porownania:" << std::endl;
	
	std::cout << "v_double1 == v_double ->\t" << std::boolalpha << (v_d1 == v_d) << std::endl;
	std::cout << "v_int1 == v_int -> \t\t" << std::boolalpha << (v_i1 == v_i) << std::endl;
	std::cout << "v_string1 == v_string -> \t" << std::boolalpha << (v_s1 == v_s) << std::endl;

	std::cout << "v_double1 != v_double1 -> \t" << std::boolalpha << (v_d1 != v_d1) << std::endl;
	std::cout << "v_int1 != v_int1 -> \t\t" << std::boolalpha << (v_i1 != v_i) << std::endl;
	std::cout << "v_string1 != v_string1 -> \t" << std::boolalpha << (v_s1 != v_s) << std::endl;

	std::cout << std::endl << "Operator indeksowy:" << std::endl;
	std::cout << "v_double[2] = " << v_d1[2] << std::endl;
	std::cout << "v_int[2] = " << v_i1[2] << std::endl;
	std::cout << "v_string[2] = " << v_s1[2] << std::endl;

	std::cout << std::endl << "Metoda push_back:" << std::endl;
	out(v_d1, "Double");
	v_d1.push_back(1.2345);
	out(v_d1, "Double");

	out(v_i1, "Int");
	v_i1.push_back(6);
	out(v_i1, "Int");

	out(v_s1, "String");
	v_s1.push_back("PK sem 3");
	out(v_s1, "String");
}


