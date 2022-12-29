#include <iostream>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

#include "stopwatch.h"

int main()
{
	//const size_t size = 10'000'000;
	//km::Stopwatch sw;
	//sw.Start();
	//std::vector<double> v(size);
	//sw.Stop();
	//std::cout << "Tworzenie wektora: " << sw.ToString() << std::endl;

	//sw.Start();
	//std::vector<double> v1;
	//for (size_t i = 0; i < size; ++i) v1.push_back(0.0);
	//sw.Stop();
	//std::cout << "Tworzenie wektora: " << sw.ToString() << std::endl;

	km::Stopwatch sw;
	const size_t size = 10'000;
	int element = 500;

	//--------------------------------VECTOR---------------------------------------
	std::vector<int> v(size);
	std::cout << "VECTOR" << std::endl;
	sw.Start();
	for (int i = 0; i < size; i++) v.insert(v.begin() + i, i * 2);
	sw.Stop();
	std::cout << "Dodawanie do wektora: " << sw.ToString() << std::endl;

	sw.Start();
	std::find(v.begin(), v.end(), element);
	sw.Stop();
	std::cout << "Wyszukiwanie w wektorze: " << sw.ToString() << std::endl;

	sw.Start();
	v.erase(v.begin()+499);
	sw.Stop();
	std::cout << "Usuwanie z wektora: " << sw.ToString() << std::endl;


	//--------------------------------SET---------------------------------------
	std::cout << "" << std::endl;
	std::cout << "SET" << std::endl;
	std::set<int> s;

	sw.Start();
	for (int i = 0; i < size; i++) s.insert(i);
	sw.Stop();
	std::cout << "Dodawanie do zbioru: " << sw.ToString() << std::endl;

	sw.Start();
	s.find(element);
	sw.Stop();
	std::cout << "Wyszukiwanie w zbiorze: " << sw.ToString() << std::endl;

	sw.Start();
	s.erase(element);
	sw.Stop();
	std::cout << "Usuwanie ze zbioru: " << sw.ToString() << std::endl;


	//--------------------------------MAP---------------------------------------
	std::cout << "" << std::endl;
	std::cout << "MAP" << std::endl;
	std::map<int, int> m;

	sw.Start();
	for (int i = 0; i < size; i++) m.insert({ i, i * 2 });
	sw.Stop();
	std::cout << "Dodawanie do mapy: " << sw.ToString() << std::endl;

	sw.Start();
	m.find(element);
	sw.Stop();
	std::cout << "Wyszukiwanie w mapie: " << sw.ToString() << std::endl;

	sw.Start();
	m.erase(element);
	sw.Stop();
	std::cout << "Usuwanie z mapy: " << sw.ToString() << std::endl;


	//--------------------------------UNORDERED MAP---------------------------------------
	std::cout << "" << std::endl;
	std::cout << "UNORDERED_MAP" << std::endl;
	std::map<int, int> u_m;

	sw.Start();
	for (int i = 0; i < size; i++) u_m.insert({ i, i * 2 });
	sw.Stop();
	std::cout << "Dodawanie do nieuporz. mapy: " << sw.ToString() << std::endl;

	sw.Start();
	u_m.find(element);
	sw.Stop();
	std::cout << "Wyszukiwanie w nieuporz. mapie: " << sw.ToString() << std::endl;

	sw.Start();
	u_m.erase(element);
	sw.Stop();
	std::cout << "Usuwanie z nieuporz. mapy: " << sw.ToString() << std::endl;


	//--------------------------------QUEUE---------------------------------------
	std::cout << "" << std::endl;
	std::cout << "QUEUE" << std::endl;
	std::queue<int> q;

	sw.Start();
	for (int i = 0; i < size; i++) q.push(i);
	sw.Stop();
	std::cout << "Dodawanie do kolejki: " << sw.ToString() << std::endl;

	std::cout << "Wyszukiwanie w kolejke: " << "BRAK" << std::endl;

	sw.Start();
	q.pop();
	sw.Stop();
	std::cout << "Usuwanie z kolejki: " << sw.ToString() << std::endl;


	//--------------------------------STACK---------------------------------------
	std::cout << "" << std::endl;
	std::cout << "STACK" << std::endl;
	std::stack<int> st;

	sw.Start();
	for (int i = 0; i < size; i++) st.push(i);
	sw.Stop();
	std::cout << "Dodawanie do stosu: " << sw.ToString() << std::endl;

	std::cout << "Wyszukiwanie w stosie: " << "BRAK" << std::endl;

	sw.Start();
	st.pop();
	sw.Stop();
	std::cout << "Usuwanie ze stosu: " << sw.ToString() << std::endl;
}