#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
protected:
	T* arr;
	int currentSize;
	int maxSize;
public:
	virtual void push(T s) = 0;
	virtual T top() = 0;
	virtual T pop() = 0;
	virtual bool isFullStack() = 0;
	virtual bool isEmptyStack() = 0;
	Stack(int size);
};
template <class T>
Stack<T>::Stack(int s)
{
	arr = new T[s];
	currentSize = 0;
	maxSize = s;
}