#include <iostream>

template<class T> struct stack{

	struct Node{
		T data;
		Node* next;

		Node(T val){
			data = val;
			next = NULL;
		}
	}

	Node* head;
	int size;

	stack(){
		head = NULL;
		size = 0;
	}

	void push(T val){
		Node* node = new Node(val);
		if (size==0){
			head = node;
		}else{
			node->next = head;
			head = node;
		}
		size++;
	}

	T top(){
		if (size==0)
			throw runtime_error("stack is empty");
		return head->data;
	}

	void pop(){
		if (size==0){
			throw runtime_error("stack is empty");
		head = head->next;
		size--;
	}

	bool empty(){	return size==0; }
};
