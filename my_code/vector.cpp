#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

MyVec::MyVec() {
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

MyVec::MyVec(const MyVec& v2) {
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	for (int i = 0; i < size(); i++) {
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec() {
	delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
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

bool operator==(MyVec& v1, MyVec& v2) {
	/*if (v1.size() != v2.size()) {
		return false;
	}
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2.size(); ++j) {
			if (v1[i] != v2[j]) {
				return false;
			}
		}
	}
	return true;*/

	if (v1.size() == v2.size() || (v1 == v2)) {
		return true;
	}
	else {
		return false;
	}
}

void MyVec::push_back(int val) {
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

int MyVec::operator[](int i) const {
	return data[i];
}

int& MyVec::operator[](int i){
	return data[i];
}