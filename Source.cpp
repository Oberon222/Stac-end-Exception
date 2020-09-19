#include<iostream>
#include<exception>
#include<stdexcept>
#include<stack>
using namespace std;

class StackIsFullException : public exception
{
public: 
	StackIsFullException(const char* message) : exception(message) {}

};

class StackIsEmptyException : public exception
{
public:
	StackIsEmptyException(const char* message) : exception(message) {}

};

class StackIsEmptyPeekException : public exception
{
public:
	StackIsEmptyPeekException(const char* message) : exception(message) {}
};



class Stack
{
	int empty;
	int full;

	int* data;
	int topIndex;
public:
	Stack() 
	{
		empty = -1;
		full = 0;
		data = nullptr;
		topIndex = empty;
	}

	Stack(int maxSizeStack)
	{
		full = maxSizeStack - 1;
		data = new int[maxSizeStack];
		empty = -1;
		topIndex = empty;

	}

	~Stack()
	{
		if (data != nullptr) delete[]data;
	}

	int GetCount()const
	{
		return topIndex + 1;
	}

	bool IsEmpty()const
	{
		return data[topIndex];
	}

	bool IsFull()const
	{
		return topIndex == full;
	}

	bool Push(int newElem)
	{
		if (!IsFull())
		{
			int *tmp = new int[full + 1];
			tmp = data;
			delete data;
			tmp[topIndex++]= newElem;
			data = tmp;
			delete[]tmp;
			return true;
		}
		throw StackIsFullException("The stack is full. Adding another item will overflow the stack.");
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			return data[topIndex--];
		}

		else
		{
			throw StackIsEmptyException(" The stack is empty. No items to delete.");
		}

	}


	int Peek()/*const*/
	{
		if (!IsEmpty())
		{
			return data[topIndex];
		}

		else
		{
			throw StackIsEmptyPeekException("The stack is empty.No items to display.");
		}

	}

	void Print()/*const*/
	{
		for (int i = topIndex - 1; i >= 0; i--) {
			cout << data[i] << ",";
		}
	}

};

int main()
{
	Stack st(5);
	st.Push(8);
	st.Push(4);
	st.Push(11);
	cout << st.Peek() << endl;
	st.Print();
	int a = 4;

	try
	{
		st.Push(a);
		st.Pop();
		st.Peek();
	}

	catch (StackIsFullException& ex)
	{
		cout << ex.what() << endl;
	}

	catch (StackIsEmptyException& ex)
	{
		cout << ex.what() << endl;
	}

	catch (StackIsEmptyPeekException& ex)
	{
		cout << ex.what() << endl;
	}




	system("pause");
	return 0;
}
