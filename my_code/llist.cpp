#include <iostream>
#include "llist.h"

using namespace std;

ostream& operator<<(ostream& os, const Node* nd) {
	/*if (!nd) os << "nullptr";
	else {
		os << "data: " << nd->data << "next: " << nd->next;
	}*/
	os << nd->data;
	return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d, nullptr);
	}
	else {
		add_at_end(head->next, d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	if (!head) os << "nullptr" << endl;
	else {
		os << head << " --> ";
		print_list(os, head->next);
	}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);

}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (!head) return nullptr;
	else if (!head->next) return head;
	else return last(head->next);
}

bool del_head(Node*& head) {
	if (!head) return false;
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
}

bool del_tail(Node*& curr) {
	if (!curr) return false;
	else {
		if (curr->next == nullptr) {
			delete curr;
			curr = nullptr;
			return true;
		}
		else {
			del_tail(curr->next);
		}
	}
}

Node* reverse(Node* curr, Node* new_next) {
	if (!curr) return new_next;
	else {
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}

Node* duplicate(Node* head) {
	if (!head) return nullptr;
	else {
		Node* new_node = new Node(head->data, head->next);
		return new_node;
	}
}

Node* join(Node*& list1, Node* list2) {
	if (list1 == nullptr && list2 == nullptr) return nullptr;
	else if (list1 == nullptr) return list2;
	else if (list2 == nullptr) return list1;
	else {
		last(list1)->next = list2;
		return list1;
	}
}