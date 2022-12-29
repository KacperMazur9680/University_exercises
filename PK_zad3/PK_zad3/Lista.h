#pragma once
#include <functional>

template <typename T>
class Node {
	public:
		Node<T>* next;
		T val;
		Node(Node<T>* next, const T& val) : next(next), val(val) {}
		Node(Node<T>* next = nullptr) : next(next) {}
};

template <typename T>
class List {
	private:
		Node<T>* head;
		Node<T>* last_empty;
		Node<T>* last;
		size_t size;

	public:
		class ConstIterator {
			public:
				Node<T>* pointer;
				ConstIterator(Node<T>* ptr) : pointer(ptr) {}
				ConstIterator& operator++() noexcept {
					pointer = pointer->next;
					return *this;
				}
				ConstIterator operator++(int) noexcept {
					auto temp = pointer;
					pointer = pointer->next;
					return temp;
				}
				const T& operator*() const {
					return pointer->val;
				}
				const Node<T>* operator->() const {
					return pointer;
				}
				bool operator!=(const ConstIterator& it) const {
					return pointer != it.pointer;
				}
		};
		class Iterator : public ConstIterator {
			public:
				using ConstIterator::ConstIterator;
				T& operator*() {
				return ConstIterator::ConstIterator::pointer->val;
				}
				Node<T>* operator->() {
				return ConstIterator::ConstIterator::pointer;
				}
		};

		ConstIterator begin() const noexcept {
			return ConstIterator(head->next);
		}
		ConstIterator end() const noexcept {
			return ConstIterator(last_empty);
		}
		Iterator begin() {
			return Iterator(head->next);
		}
		Iterator end() {
			return Iterator(last_empty);
		}

		size_t Size() const noexcept { return size; }

		List() : size(0) {
			last_empty = new Node<T>();
			last = head = new Node<T>(last_empty);
		}

		List(const int size, std::function<T(const size_t)> f) : size(size) {
			last_empty = new Node<T>();
			Node<T>* next = last_empty;
			for (int i = size; i > 0; i--) {
				next = new Node<T>(next, f(i));
				if (i == size) last = next;
			}

			head = new Node<T>(next);
		}

		~List() {
			Node<T>* curr = head;
			Node<T>* next = curr->next;
			while (curr) {
				delete curr;
				curr = next;
				if (curr) next = curr->next;
			}
		}

		void push_back(const T value) {
			last = last->next = new Node<T>(last_empty, value);
			size++;
		}

		void insert(ConstIterator it, T value) {
			if (it != end()) {
				Node<T>* nNode = new Node<T>(it.pointer->next, *it);
				it.pointer->next = nNode;
				it.pointer->val = value;
			}
			else { push_back(value); }
		}

		void erase(ConstIterator it) {
			if (it != end()) {
				it.pointer->val = (it.pointer->next)->val;
				auto toDel = it.pointer->next;
				it.pointer->next = (it.pointer->next)->next;
				delete toDel;
			}
		}
};