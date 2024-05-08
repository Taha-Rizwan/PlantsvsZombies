#pragma once
template<class E>
class Vector {
	int size;
	int current;
	E** ptr;
public:
	Vector(int size = 100):size(size),current(0), ptr(new E*[size]) {
		
	}

	E** getPtr() {
		return ptr;
	}

	int getCurrent() {
		return current;
	}

	void add(E* obj) {
		if (obj != nullptr) {
			if (current <= size - 1) {
				ptr[current++] = obj;
			}
			else {
				extend();
				ptr[current++] = obj;
			}
		}
	}

	void extend() {
		int newSize = size * 2;
		E** ptr2 = new E*[newSize];
		for (int i = 0; i < size; i++) {
			ptr2[i] = ptr[i];
		}

		delete[] ptr;
		ptr = ptr2;
		size = newSize;
	}
	
};