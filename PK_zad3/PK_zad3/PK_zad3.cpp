#include "Lista.h"
#include <iostream>

int main() {
	List<double> lista(4, [](const size_t i) { return 1.0 + i; });
	std::cout << "Wypisanie: " << std::endl;
	for (const auto& el : lista) std::cout << el << std::endl;
	std::cout << std::endl;

	for (auto& el : lista) el *= 2.0;
	std::cout << "Wypisanie pomnozonej: " << std::endl;
	for (auto it = lista.begin(); it != lista.end(); ++it) std::cout << *it << std::endl;
	std::cout << std::endl;

	lista.push_back(13.3);
	std::cout << "Dopisanie 13.3 na koniec: " << std::endl;
	for (const auto& el : lista) std::cout << el << std::endl;
	std::cout << std::endl << std::endl;
	lista.insert(++(lista.begin()), 16.6);

	std::cout << "Postinkrementacja 16.6: " << std::endl;
	for (const auto& el : lista) std::cout << el << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Dopiasanie na poczatek 2 i na koniec 666:" << std::endl;
	lista.insert(lista.begin(), 2);
	lista.insert(lista.end(), 666);
	for (const auto& el : lista) std::cout << el << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Usuniecie pierwszego elementu: " << std::endl;
	lista.erase(lista.begin());
	for (const auto& el : lista) std::cout << el << std::endl;

	std::cout << std::endl;
	std::cout << "Erase.end() nic nie robi: " << std::endl;
	lista.erase(lista.end());
	for (const auto& el : lista) std::cout << el << std::endl;
	}
