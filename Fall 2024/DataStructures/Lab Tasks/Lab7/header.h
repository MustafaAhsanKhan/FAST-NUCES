#include <iostream>
using namespace std;

//Q1

class DoublyNode
{
private:
	int data;
	DoublyNode* prev;
	DoublyNode* next;

public:
	DoublyNode()
	{
		data = 0;
		prev = nullptr;
		next = nullptr;
	}

	DoublyNode(int data_p, DoublyNode* prev_p = nullptr, DoublyNode* next_p = nullptr)
	{
		data = data_p;
		prev = prev_p;
		next = next_p;
	}

	int getData() { return data; }

	DoublyNode* getNext() { return next; }

	DoublyNode* getPrev() { return prev; }

	void setData(int data_p) { data = data_p; }

	void setNext(DoublyNode* next_p) { next = next_p; }

	void setPrev(DoublyNode* prev_p) { prev = prev_p; }
};

class DoublyLinkedList
{
private:
	DoublyNode* head;
	DoublyNode* tail;
	int length;

public:
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	DoublyNode* getHead()
	{
		return head;
	}

	void insert(int data_p)
	{
		DoublyNode* temp = new DoublyNode(data_p);
		if (head == nullptr)
		{
			head = tail = temp;
		}
		else
		{
			tail->setNext(temp);
			temp->setPrev(tail);
			tail = temp;
		}
		++length;
	}

	void insertToHead(int data_p)
	{
		DoublyNode* temp = new DoublyNode(data_p);
		if (head == nullptr)
		{
			head = tail = temp;
		}
		else
		{
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}
		++length;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	bool search(int data_p)
	{
		DoublyNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->getData() == data_p)
			{
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}

	void update(int s_data, int r_data)
	{
		DoublyNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->getData() == s_data)
			{
				temp->setData(r_data);
				return;
			}
			temp = temp->getNext();
		}
	}

	void insertAtIndex(int data_p, int pos)
	{
		if (pos < 0 || pos > length)
		{
			return;
		}

		if (pos == 0)
		{
			insertToHead(data_p);
		}
		else if (pos == length)
		{
			insert(data_p);
		}
		else
		{
			DoublyNode* temp = head;
			int count = 0;
			while (count < pos - 1)
			{
				temp = temp->getNext();
				++count;
			}

			DoublyNode* newNode = new DoublyNode(data_p);
			newNode->setNext(temp->getNext());
			newNode->setPrev(temp);

			if (temp->getNext() != nullptr)
			{
				temp->getNext()->setPrev(newNode);
			}
			temp->setNext(newNode);
			++length;
		}
	}

	void deleteData(int data_p)
	{
		if (head == nullptr)
			return;

		DoublyNode* temp = head;

		while (temp != nullptr && temp->getData() != data_p)
		{
			temp = temp->getNext();
		}

		if (temp == nullptr) return;

		if (temp == head)
		{
			head = temp->getNext();
			if (head != nullptr) head->setPrev(nullptr);
		}
		else if (temp == tail)
		{
			tail = temp->getPrev();
			if (tail != nullptr) tail->setNext(nullptr);
		}
		else
		{
			temp->getPrev()->setNext(temp->getNext());
			if (temp->getNext() != nullptr)
			{
				temp->getNext()->setPrev(temp->getPrev());
			}
		}

		delete temp;
		--length;
	}

	void print()
	{
		DoublyNode* temp = head;
		while (temp != nullptr)
		{
			cout << temp->getData() << "->";
			temp = temp->getNext();
		}
		cout << "NULL" << endl;
	}
};


//Q2

class CircularLinkedList
{
private:
	DoublyNode* head;
	DoublyNode* tail;

public:
	CircularLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insert(int data_p)
	{
		DoublyNode* temp = new DoublyNode(data_p);

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			tail->setNext(head);
		}
		else
		{
			tail->setNext(temp);
			temp->setNext(head);
			tail = temp;
		}
	}

	int findWinner(int M)
	{
		DoublyNode* prev = nullptr;
		DoublyNode* current = head;

		while (current->getNext() != current)
		{
			for (int i = 0; i < M; ++i)
			{
				prev = current;
				current = current->getNext();
			}
			current = current->getNext();
			delete prev->getNext();
			prev->setNext(current);
		}

		return current->getData();
	}

	void print()
	{
		DoublyNode* temp = head;
		do
		{
			cout << temp->getData() << "->";
			temp = temp->getNext();
		} while (temp != head);
	}
};
