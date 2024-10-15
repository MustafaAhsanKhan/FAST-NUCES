#pragma once
#include <iostream>
using namespace std;

// Main is at the bottom of this file
// It has two test cases

// Q1
template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;

		if (front == nullptr)
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	T dequeue()
	{
		if (front == nullptr)
		{
			return -1;
		}
		else
		{
			Node<T>* temp = front;
			T data = front->data;
			front = front->next;
			delete temp;
			return data;
		}
	}

	T Front()
	{
		if (front == nullptr)
		{
			return -1;
		}
		else
		{
			return front->data;
		}
	}

	bool is_empty()
	{
		return front == nullptr;
	}

	T size()
	{
		Node<T>* temp = front;
		int count = 0;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	bool helper(const string& str, int start, int end)
	{
		if (start >= end)  // 1 or 0 characters
		{
			return true;
		}

		if (str[start] != str[end])  // If not palindrome
		{
			return false;
		}

		return helper(str, start + 1, end - 1);  // Recursive call  // Moving towards the middle
	}


	bool isPalindrome(string str)
	{
		return helper(str, 0, str.length() - 1);
	}

	void print()
	{
		Node<T>* temp = front;
		cout << "FRONT -> ";
		while (temp != nullptr)
		{
			cout << temp->data << " " << "-> ";
			temp = temp->next;
		}
		cout << "REAR";
		cout << endl;
	}

	//Q2
	void roundRobin(Queue Q)
	{
		while (!Q.is_empty())
		{
			int time = Q.Front();
			Q.dequeue();
			cout << "Excecution time: " << time << endl;
			cout << "Remaining time: " << time - 10 << endl;
			if (time > 10)
			{
				time -= 10;
				Q.enqueue(time);
				cout << "Task is not completed, it is being re-scheduled" << endl;
				continue;
			}
			cout << "Task is completed, it is removed from the queue" << endl;
		}
	}
};

int main()
{
	Queue<int> q;
	// Test case 1
	q.enqueue(10);
	q.enqueue(50);
	q.enqueue(30);
	q.enqueue(20);
	q.enqueue(40);

	// Test case 2
	/*q.enqueue(10);
	q.enqueue(10);
	q.enqueue(10);
	q.enqueue(10);
	q.enqueue(10);*/

	q.roundRobin(q);
}
