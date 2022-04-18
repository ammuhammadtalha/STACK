#include "myStack.h"
void menu()
{
	cout << " Press 1 to add a new item to the stack.\n";
	cout << " Press 2 to remove and return the last element from the stack \n";
	cout << " Press 3 to check if the stack is full.\n";
	cout << " Press 4 to check if the stack is empty. \n";
	cout << " Press 5 to return the size of the stack. \n";
	cout << " Press 6 to display the stack.\n";
	cout << " Press 7 to convert infix to postfix \n";
	cout << " Press 0 to exit. \n";
}
int main()
{
	int size = 0;
	cout << " Enter the size of Stack = ";
	cin >> size;
	myStack<int> sk(size);
	while (true)
	{
		menu();
		cout << " ------------------------------------------------\n";
		int choice = 0;
		cout << " Enter your choice = ";
		cin >> choice;

		if (choice == 1)
		{
			float value = 0.0;
			cout << " Enter a new items to the stack = ";
			cin >> value;
			sk.push(value);
		}
		else if (choice == 2)
		{
			cout << " Remove and return the last element from the stack \n";
			cout << sk.pop() << endl;
		}
		else if (choice == 3)
		{
			if (!sk.isFullStack())
			{
				cout << " Stack is Full \n";
			}
			else
			{
				cout << " Stack is not Full \n";
			}
		}
		else if (choice == 4)
		{
			if (!sk.isEmptyStack())
			{
				cout << " Stack is Empty \n";
			}
			else
			{
				cout << " Stack is not Empty \n";
			}
		}
		else if (choice == 5)
		{
			cout << " Current Size = " << sk.getCurrentSize() << endl;

		}
		else if (choice == 6)
		{
			cout << " Stack is :- \n";
			sk.display();
		}
		else if (choice == 7)
		{
			sk.infixtopostfix(sk);

		}

		else if (choice == 0)
		{
			break;
		}
		
		else
		{
			cout << " You have entered wrong input \n";
		}
	}
	
	return 0;
}