#pragma once
#include <iostream>

// Node structure
template <typename T>
struct Node {
	T data;
	Node* next;
	Node* prev;
	Node(): data(), next(nullptr), prev(nullptr) {};
	Node(const T& data): data(data), next(nullptr), prev(nullptr) {};
};

// LinkedList class
template <typename T>
class LinkedList {

public:

	// Behaviors
	void printForward() const{

		Node<T>* currentNode = head;
		if(currentNode){

			for(unsigned int i = 0; i < count; ++i){

				std::cout << currentNode -> data << " ";
				currentNode = currentNode -> next;
			}
		}
	};

	void printReverse() const{

		Node<T>* currentNode = tail;
		if(currentNode){
			for(unsigned int i = 0; i < count; ++i){

				std::cout << currentNode -> data << " ";
				currentNode = currentNode -> prev;
			}
		}
	};

	// Accessors
	[[nodiscard]] unsigned int getCount() const{return count;};
	Node<T>* getHead(){return head;};
	const Node<T>* getHead() const{return head;};
	Node<T>* getTail(){return tail;};
	const Node<T>* getTail() const{return tail;};

	// Insertion
	void addHead(const T& data){

		Node<T>* newHead = new Node<T>(data);
		newHead -> next = head;

		if (head) {head -> prev = newHead;} 
		else {tail = newHead;}
		
		head = newHead;
		count ++;
	};

	void addTail(const T& data){

		Node<T>* newTail = new Node<T>(data);
		newTail -> prev = tail;

		if (tail) {tail -> next = newTail;} 
		else {head = newTail;}

		tail = newTail;
		count ++;
	};

	// Removal
	bool removeHead(){

		if (head == nullptr) {return false;};
		Node<T>* oldHead = head;
		head = head -> next;
		if(head) {head -> prev = nullptr;}
		else{tail = nullptr;}
		delete oldHead;
		count --;
		return true;
	};

	bool removeTail(){

		if (tail == nullptr) {return false;}
		Node<T>* oldTail = tail;
		tail = tail -> prev;
		if(tail) {tail -> next = nullptr;}
		else{head = nullptr;}
		delete oldTail;
		count --;
		return true;
	};

	void clear(){

		for(unsigned int i = 0; i < count; i++){
			Node<T>* temp = head;
			head = head -> next;
			delete temp;
		}

		head = nullptr;
		tail = nullptr;
		count = 0;
	};

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept{

		if(this == &other){
			return *this;
		}

		clear();
		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
		return *this;
	};

	LinkedList<T>& operator=(const LinkedList<T>& rhs){

		if(this == &rhs){
			return *this;
		}

		clear();
		const Node<T>* temp = rhs.getHead();

		while(temp){

			addTail(temp -> data);
			temp = temp -> next;
		}

		return *this;
	};

	// Construction/Destruction
	LinkedList() : head(nullptr), tail(nullptr), count(0){};

	LinkedList(const LinkedList<T>& list): head(nullptr), tail(nullptr), count(0){

		const Node<T>* temp = list.getHead();

		while(temp){

			addTail(temp -> data);
			temp = temp -> next;
		}
	};

	LinkedList(LinkedList<T>&& other) noexcept{

		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	};

	~LinkedList(){
		clear();
	};

private:
	// Stores pointers to first and last nodes and count
	Node<T>* head;
	Node<T>* tail;
	unsigned int count;

};


