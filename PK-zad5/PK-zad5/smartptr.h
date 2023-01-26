#pragma once

namespace ap {

	template<class T>
	class SmartPtr {
		T* ptr;
		SmartPtr() = delete;
		SmartPtr(const SmartPtr&) = delete;
		SmartPtr& operator=(const SmartPtr&) = delete;
	public:
		explicit SmartPtr(T* ptr) : ptr(ptr) {
		}
		~SmartPtr() noexcept {
			delete ptr;
		}
		explicit SmartPtr(SmartPtr&& smartPtr) : ptr(smartPtr.ptr) {
			smartPtr.ptr = nullptr;
		}
		SmartPtr& operator=(SmartPtr&& smartPtr) {
			if (this == smartPtr) return *this;
			delete ptr;
			ptr = smartPtr.ptr;
			smartPtr.ptr = nullptr;
			return *this;
		}
		T& operator*() noexcept {
			return *ptr;
		}
		T* operator->() noexcept {
			return ptr;
		}
		operator T* () noexcept {
			return *ptr;
		}
	};

}
