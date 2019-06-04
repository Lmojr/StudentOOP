#ifndef POINTERS_H
#define POINTERS_H

#include <string>
#include <vector>

using namespace std;

void inc_by_value(int n);
void inc_with_pointer(int* n);
void inc_with_reference(int& n);


struct Thing {
	int val;
	Thing(int i) : val(i) {}
};

Thing** create_array_of_things(int n);
void print_all_things(Thing** things, int n);
void double_all_things(Thing** things, int n);
void delete_all_things(Thing** things, int n);

struct Student {
	string name;
	Student* ta;
	Student(string nm) : name(nm), ta(nullptr) {}
};

void assignTA(Student* s, Student* ta);
void printTAs(vector<Student*>& students);

#endif