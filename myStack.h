#pragma once
#include "Stack.h"

template <class T>
class myStack:public Stack<T>
{
public:
	void push(T);
	T pop();
	T top();
	myStack(int);
	bool isEmptyStack();
	bool isFullStack();
	void initializeStack();
	void copyStack(const myStack<T>& otherStack);
	void display();
	int getCurrentSize();
	void infixtopostfix(myStack<T> st);
	int prec(char c);

};

template <class T>
int myStack<T>::getCurrentSize()
{
	return Stack<T>::currentSize;
}
template <class T>
bool myStack<T>::isEmptyStack()
{
	if (Stack<T>::currentSize == 0)
	{
		return true;

	}
	else
	{
		return false;
	}
}
template <class T>
bool myStack<T>::isFullStack()
{
	if (Stack<T>::currentSize != Stack<T>::maxSize)
	{
		return true;

	}
	else
	{
		return false;
	}
}
template <class T>
void myStack<T>::push(T el)
{
	if (isFullStack())
	{
		Stack<T>::arr[Stack<T>::currentSize++] = el;
	}
	else
	{
		cout << " Stack is full \n";
	}
}
template <class T>
T myStack<T>::pop()
{
	if (!isEmptyStack())
	{
		Stack<T>::currentSize--;
		return Stack<T>::arr[Stack<T>::currentSize];
	}
	else
	{
		cout << " Stack is Empty \n";
		return NULL;
	}
}
template <class T>
T myStack<T>::top()
{
	if (!isEmptyStack())
	{
		return Stack<T>::arr[Stack<T>::currentSize - 1];
	}
	else
	{
		cout << " Stack is Empty \n";
		return NULL;
	}
}
template <class T>
myStack<T>::myStack(int size):Stack<T>(size)
{

}
template <class T>
void myStack<T>::initializeStack()
{
	Stack<T>::currentSize = 0;
}
template <class T>
void myStack<T>::copyStack(const myStack<T>& otherStack)
{
	delete[] myStack<T>::arr;
	Stack<T>::maxSize = otherStack.Stack<T>::maxSize;
	Stack<T>::currentSize = otherStack.Stack<T>::currentSize;
	Stack<T>::arr = new T[Stack<T>::maxSize];
	for (int j = 0; j < Stack<T>::currentSize; j++)
		Stack<T>::arr[j] = otherStack.Stack<T>::arr[j];
}

template <class T>
void myStack<T>::display()
{
	cout << "Max Size: " << Stack<T>::maxSize << endl;
	cout << "Current Size: " << Stack<T>::currentSize << endl;

	for (int i = 0; i < Stack<T>::currentSize; i++)
	{
		cout << i << ". " << Stack<T>::arr[i] << endl;
	}
}

template <class T>
void myStack<T>::infixtopostfix(myStack<T> st)
{
	string result;

	for (int i = 0; i < st.currentSize; i++) {
		char c = st.arr[i];

		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		
		else if (c == '(')
			st.push('(');

		
		else if (c == ')') {
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.isEmptyStack() && prec(st.arr[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.isEmptyStack())
	{
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}
template <class T>
int myStack<T>:: prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}