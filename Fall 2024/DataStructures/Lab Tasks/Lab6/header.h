#pragma once

template <class T>
struct Node
{
	Node<T>* next;
	T dataItem;
};

template <class T>
class SingleList
{
private:
	Node<T>* tail;
	Node<T>* current;
	int size1;

public:
	Node<T>* head;

	SingleList()
	{
		head = nullptr;
		tail = nullptr;
		current = nullptr;
		size1 = 0;
	}

	void InsertFirst(T dataItem)
	{
		current = new Node<T>;
		current->dataItem = dataItem;

		if (head == nullptr)
		{
			current->next = nullptr;
			head = current;
			tail = current;
		}
		else
		{
			current->next = head;
			head = current;
		}
		size1++;
	}

	void InsertLast(T dataItem)
	{
		current = new Node<T>;
		current->dataItem = dataItem;

		if (tail == nullptr)
		{
			current->next = nullptr;
			head = current;
			tail = current;
		}
		else
		{
			current->next = nullptr;
			tail->next = current;
			tail = current;
		}
		size1++;
	}

	int Search(T DT)
	{
		current = head;
		int index = 0;

		while (current != nullptr)
		{
			if (current->dataItem == DT)
			{
				return index;
			}
			current = current->next;
			index++;
		}

		return -1;
	}

	void removeFirst()
	{
		current = head;
		head = head->next;
		delete current;
		size1--;
	}

	void removeLast()
	{
		if (head == nullptr)
		{
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size1--;
			return;
		}

		current = head;

		while (current->next != tail)
		{
			current = current->next;
		}

		delete tail;
		tail = current;
		current->next = nullptr;
		size1--;
	}

	int size()
	{
		return size1;
	}

	void setCurrentToHead()
	{
		current = head;
	}

	T CurrentDataItem()
	{
		return current->dataItem;
	}

	void remove(T DT)
	{
		int index = Search(DT);

		if (index == 0)
		{
			removeFirst();
			size1--;
		}
		else if (index == size1 - 1)
		{
			removeLast();
			size1--;
		}
		else if (index != -1)
		{
			current = head;
			Node<int>* prev = nullptr;

			while (current != nullptr)
			{
				if (current->dataItem == DT)
				{
					if (prev != nullptr)
					{
						prev->next = current->next;
					}
					delete current;
					size1--;
					return;
				}
				prev = current;
				current = current->next;
			}
		}
	}


	T NextDataItem()
	{
		current = current->next;
		return current->dataItem;
	}

	void Clear()
	{
		current = head;
		Node<T>* nextNode;

		while (current != nullptr)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = nullptr;
		tail = nullptr;
		size1 = 0;
	}

	void Ascendsort()
	{
		if (head == nullptr)
		{
			return;
		}

		bool swapped;
		Node<T>* r_ptr;
		Node<T>* l_ptr = nullptr;

		do
		{
			swapped = false;
			r_ptr = head;

			while (r_ptr->next != l_ptr)
			{
				if (r_ptr->dataItem > r_ptr->next->dataItem)
				{
					// Swap the dataItem between two nodes
					int temp = r_ptr->dataItem;
					r_ptr->dataItem = r_ptr->next->dataItem;
					r_ptr->next->dataItem = temp;

					swapped = true;
				}
				r_ptr = r_ptr->next;
			}
			l_ptr = r_ptr;
		} while (swapped);
	}

	void displayList()
	{
		current = head;
		while (current != nullptr)
		{
			cout << current->dataItem << "->";
			current = current->next;
		}
	}
};