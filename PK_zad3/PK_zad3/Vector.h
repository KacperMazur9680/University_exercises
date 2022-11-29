#pragma once
#include <functional>
#include <string>
#include <typeinfo>

template <typename T> T DefValue() { throw std::exception(); }
template <> int DefValue() { return 0; }
template <> double DefValue() { return 0.0; }
template <> std::string DefValue() { return ""; }

template <typename T>
class Vector {
public:
	class ConstIterator {
	protected:
		T* pointer;
	
	public:
		ConstIterator(T* pointer) : pointer(pointer) {};

		ConstIterator& operator++ () noexcept {
			++pointer;
			return *this;
		}

		bool operator!=(const ConstIterator& it) const noexcept {
			return pointer != it.pointer;
		}

		T operator*() const noexcept {
			return *pointer;
		}

		const T* operator->() const noexcept {
			return pointer;
		}
	};

	class Iterator : ConstIterator {
		T* pointer;

		T& operator*() const noexcept {
			return *pointer;
		}

		/*const T& operator->() const noexcept {
			return pointer;
		}*/
	};

private:
	size_t size;
	T* data;

public:
	Vector(const size_t size, const T& defValue = DefValue<T>()) :
		size(size),
		data(new T[size]) {
		for (size_t i = 0; i < size; ++i) {
			data[i] = defValue;
		}

	}

	Vector(const size_t size, const std::function<T(const size_t)>& f) :
		size(size),
		data(new T[size]) {
		for (size_t i = 0; i < size; ++i) {
			data[i] = f(i);
		}
	}

	Vector(const Vector<T>& vector) :
		size(vector.Size()),
		data(new T[size]) {
		for (size_t i = 0; i < size; ++i) {
			data[i] = vector[i];
		}
	}

	Vector(Vector<T>&& vector) noexcept :
		size(vector.Size()),
		data(vector.Data()) {
		vector.size = 0;
		vector.data = nullptr;
	}

	~Vector() noexcept {
		delete[] data;
	}

	size_t Size() const noexcept {
		return size;
	}

	T* Data() const noexcept {
		return data;
	}

	Vector<T> operator= (const Vector<T>& vector) {
		delete[] data;

		size = vector.Size();
		data = new T[size];

		for (size_t i = 0; i < size; i++) {
			data[i] = vector[i];
		}

		return *this;
	}

	Vector<T> operator= (Vector<T>&& vector) noexcept {
		delete[] data;

		data = vector.Data();
		size = vector.Size();

		vector.data = nullptr;
		vector.size = 0;

		return *this;
	}

	bool operator== (const Vector<T>& vector) {
		if (this->Size() != vector.Size()) {
			return false;
		}

		for (size_t i = 0; i < this->Size(); i++) {
			if (data[i] != vector[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!= (const Vector<T>& vector) {
		if (this->Size() != vector.Size()) {
			return true;
		}

		for (size_t i = 0; i < this->Size(); i++) {
			if (data[i] != vector[i]) {
				return true;
			}
		}

		return false;
	}

	const T& operator[](const size_t index) const {
		return data[index];
	}

	T& operator[](const size_t index) {
		return data[index];
	}

	ConstIterator begin() const noexcept { return ConstIterator(data); };
	ConstIterator end() const noexcept { return ConstIterator(data + size); };

	Iterator begin() const noexcept { return Iterator(data); };
	Iterator end() const noexcept { return Iterator(data + size); };

	void push_back(T el) {
		Vector<T> vector(size + 1);

		for (size_t i = 0; i < Size(); i++) {
			vector[i] = data[i];
		}

		vector[Size()] = el;
		delete[] data;

		data = vector.data;
		vector.data = nullptr;
		size = vector.Size();

	}

};
