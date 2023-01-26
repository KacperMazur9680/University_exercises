#pragma once

namespace ap {

	//Singleton
	// - trzeba usun�� pewne konstruktory
	// - 
	// Zalety: bezpieczny wielowtkowo
	// Wady: zawsze si� tworzy, nawet je�eli nie jest utworzony

	class Singleton {
		Singleton() = default;
		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	public:
		static Singleton& instance() { //zwraca obiekt 
			static Singleton instance;
			return instance;
		};
	};

	/* Singleton Dynamiczny
		Zalety: tworzy si� tylko kiedy jest potrzebny
		Wady: niezabezpieczony wielow�tkowo (trzeba doda MUTEX)
	*/

	class SingletonD {
		static SingletonD* instance;
		SingletonD() = default;
		SingletonD(const SingletonD&) = delete;
		SingletonD(SingletonD&&) = delete;
		SingletonD& operator=(SingletonD&&) = delete;
		SingletonD& operator=(const SingletonD&) = delete;
	public:
		static SingletonD& Instance() { //zwraca obiekt
			if (instance == nullptr) {
				instance = new SingletonD();
			}
			return *instance;
		};
	};

	SingletonD* SingletonD::instance = nullptr;
}
