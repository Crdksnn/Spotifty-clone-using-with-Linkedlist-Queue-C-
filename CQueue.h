#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>
#include "LinkedList.h"

namespace std{

template <typename T>
class Queue{
protected:
	LinkedList<T> myList;
public:
	bool isEmpty() const{
		return myList.isEmpty();
	}
	bool isFull() const{
		return false;
	}

	void clearQueue(){
		myList.clearList();
	}

	T front() const{
		return myList.front();
	}

	T rear() const{
		return myList.back();
	}

	void add(const T &val){ //insert, push, enqueue, add
		myList.insertLast(val);
	}
	T remove(){ //Delete, serve, remove, dequeue, pop
		T item = myList.front();
		myList.deleteFirst();
		return item;
	}
	int size() const{
		return myList.length();
	}
};

}
#endif /* QUEUE_H_ */
