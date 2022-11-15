#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>

template <typename T>
void delete_min_max(std::vector<T>& v) {
    auto key_value = minmax_element(v.begin(), v.end());
    v.erase(key_value.first);
    v.erase(key_value.second);
}

template <class T>
std::vector<T> CreateVector(const size_t size, std::function<T(const size_t)> f) {
    std::vector<T> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = f(i);
    }
    return result;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    for (const auto& el : v) {
        out << el << " ";
    }
    return out;
}

int main()
{
    // Zad 1 Potęga
    std::cout << "Zad.1 Potegi liczby 2:" << std::endl;
    auto v1 = CreateVector<double>(6, [](const auto i) {return std::pow(2, i); });
    std::cout << v1 << std::endl << std::endl;

    // Zad 2 Ciąg Fibonacciego
    std::cout << "Zad.2 Ciag Fibonacciego:" << std::endl;
    std::function<int(int)> fib;
    fib = [&fib](const int x) -> int {
        if ((x == 1) or (x == 0)) {
            return x;
        }
        else {
            return (fib(x - 1) + fib(x - 2));
        }
    };
    std::vector<int> v2 = CreateVector<int>(8, fib);
    std::cout << v2 << std::endl << std::endl;


    // Zad 3 Usuwanie największej i najmniejszej liczby
    std::cout << "Zad.3 Usuwanie min i max:" << std::endl;
    v1 = { 4, 5, 2, 1, 2 };
    std::cout << v1 << "-> ";
    delete_min_max(v1);
    std::cout << v1 << std::endl << std::endl;

    // Zad 4 Zwracanie parzystych elementów
    std::cout << "Zad.4 Zwracanie liczby parzystych elementow:" << std::endl;
    v2 = { 4, 2, 3, 1, 2, 1, 6 };
    int evens = std::count_if(v2.begin(), v2.end(), [](const int i) {return i % 2 == 0; });
    std::cout << v2 << "-> " << evens << std::endl << std::endl;

    // Zad 5 Usun powtorzenia
    std::cout << "Zad.5 Usuwanie powtorzen:" << std::endl;
    v2 = { 13, 13, 15, 16, 13, 15 };
    std::cout << v2 << "-> ";
    std::sort(v2.begin(), v2.end());
    auto it = std::unique(v2.begin(), v2.end(), [](const int a, const int b) {return a == b; });
    v2.erase(it, v2.end());
    std::cout << v2 << std::endl << std::endl;

    // Zad 6 Usuwanie elementow ujemnych
    std::cout << "Zad.6 Usuwanie elementow ujemnych:" << std::endl;
    v2 = {-5, 2, -6, 4, 3, -6};
    std::cout << v2 << "-> ";
    it = std::remove_if(v2.begin(), v2.end(), [](const int i) {return i < 0; });
    v2.erase(it, v2.end());
    std::cout << v2 << std::endl << std::endl;

    // Zad 7 Usuwanie parzystych
    std::cout << "Zad.7 Usuwanie elementow parzystych:" << std::endl;
    v2 = { 4, 5, 3, 8, 9, 2, 1 };
    std::cout << v2 << "-> ";
    it = std::remove_if(v2.begin(), v2.end(), [](const int i) {return i % 2 == 0; });
    v2.erase(it, v2.end());
    std::cout << v2 << std::endl << std::endl;

    // Zad 8 For each
    std::cout << "Zad.8 Nadpisywanie wartosci wiekszych i mniejszych od podanych:" << std::endl;
    v2 = { 3, 4, 5, 9, 1, 9 , 2, 7 };
    std::cout << v2 << "-> ";
    int par, par1;
    par = 6;
    par1 = 4;

    std::for_each(v2.begin(), v2.end(), [par, par1](int& x) mutable {if (x > par) x = par; else x = par1; });
    std::cout << v2 << std::endl << std::endl;




    





}


