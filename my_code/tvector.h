#include <iostream>
#include <algorithm>
const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

using namespace std;

template <typename T>
class MyVec {
	

public:
	MyVec() : sz(0) {
		capacity = DEF_CAPACITY;
		data = new int[DEF_CAPACITY];
	}


	MyVec(int sz, T val) {
		capacity = max(DEF_CAPACITY, sz * CAPACITY_MULT);
		data = new T[capacity];
		for (int i = 0; i < sz; i++) data[i] = val;
	}


	void push_back(T val) {
		if (sz == capacity) {
			// get new array of capacity * 2
			capacity *= 2;
			int* new_data = new int[capacity];

			// copy over existing data
			for (int i = 0; i < size(); i++) {
				new_data[i] = data[i];
			}
			// delete old array
			delete[] data;
			//set pointer to new array
			data = new_data;
		}
		data[sz++] = val;
	}


	// copy control:


	MyVec(const MyVec<T>& v2) {
		copy(v2);
	}


	~MyVec() {
		delete[] data;
	}


	MyVec<T>& operator=(const MyVec<T>& v2) {
		if (&v2 != this) {
			delete[] data;
			capacity = v2.capacity;
			sz = v2.size();
			data = new int[capacity];
			for (int i = 0; i < size(); ++i) {
				data[i] = v2.data[i];
			}
		}
		return *this;
	}
	//Iterator begin() const;
	//Iterator end() const;


	T operator[](int i) const {
		return data[i];
	}


	T& operator[](int i) {
		return data[i];
	}

	int size() const { return sz; }
	
private:
	void copy(const MyVec<T>& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new int[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}

	T* data;
	int sz;
	int capacity;
};


template <typename T>
void print_vector(const MyVec<T>& v) {
	for (int i = 0; i < v.size(); i++) cout << i << " ";
	cout << endl;
}


template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	if (v1.size() == v2.size() || (v1 == v2)) {
		return true;
	}
	else {
		return false;
	}
}