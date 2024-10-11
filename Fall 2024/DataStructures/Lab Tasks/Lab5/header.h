#pragma once

template <class T>
class List
{
private:
	int capacity;
	int counter;

public:
	T* values;

	List(int cap)
	{
		capacity = cap;
		counter = 0;
		values = new T[capacity];
	}

	bool insert(T item)
	{
		if (counter < capacity)
		{
			values[counter++] = item;
			return true;
		}
		else
			return false;
	}

	bool insertAt(T item, int index)
	{
		if (counter == capacity)
		{
			return false;

		}
		for (int i = counter; i > index; i--)
		{
			values[i] = values[i - 1];
		}
		counter++;

		values[index] = item;
		return true;
	}

	bool insertAfter(T itemTobeInserted, T item)
	{
		if (counter == capacity)
		{
			return false;

		}
		int found_index = 0;
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				found_index = i;
				break;
			}
		}
		for (int i = capacity - 1; i >= found_index; --i)
		{
			values[i] = values[i - 1];
		}
		counter++;

		values[found_index + 1] = itemTobeInserted;
		return true;
	}

	bool insertBefore(T itemTobeInserted, int item)
	{
		if (counter == capacity)
		{
			return false;
		}

		int found_index = -1;
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				found_index = i;
				break;
			}
		}

		if (found_index == -1)
		{
			return false;
		}

		for (int i = counter; i > found_index; i--)
		{
			values[i] = values[i - 1];
		}

		values[found_index] = itemTobeInserted;
		counter++;

		return true;
	}

	bool isEmpty()
	{
		return(counter == 0);
	}
	
	bool isFull()
	{
		return(counter == capacity);
	}

	bool remove(T item)
	{
		int found_index = -1;
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				found_index = i;
				break;
			}
		}

		if (found_index == -1)
		{
			return false;
		}

		for (int i = found_index; i < counter; ++i)
		{
			values[i] = values[i + 1];
		}

		counter--;
		return true;
	}

	bool removeAfter(T item)
	{
		int found_index = -1;
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				found_index = i;
				break;
			}
		}

		if (found_index == -1)
		{
			return false;
		}

		for (int i = found_index + 1; i < counter; ++i)
		{
			values[i] = values[i + 1];
		}

		counter--;
		return true;
	}

	bool removeBefore(T item)
	{
		int found_index = -1;
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				found_index = i;
				break;
			}
		}

		if (found_index == -1 || found_index == 0)
		{
			return false;
		}

		for (int i = found_index - 1; i < counter; ++i)
		{
			values[i] = values[i + 1];
		}

		counter--;
		return true;
	}

	int search(T item)
	{
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == item)
			{
				return item;
			}
		}
		return -1;
	}

	void print()
	{
		for (int i = 0; i < counter; ++i)
		{
			//cout << values[i] << endl;
		}
	}

	bool operator==(List& L)
	{
		if (counter != L.counter)
		{
			return false;
		}

		for (int i = 0; i < counter; ++i)
		{
			if (values[i] != L.values[i])
			{
				return false;
			}
		}
		return true;
	}

	void reverse()
	{
		for (int i = 0; i <= counter / 2; ++i)
		{
			T temp = values[i];
			values[i] = values[counter - i - 1];
			values[counter - i - 1] = temp;
		}
	}

	~List()
	{
		delete[] values;
	}

};

// Question 2

class DynamicList
{
private:
	int size;
public:
	int* arr;

	void resizeUP()
	{
		int* newArr = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		size = size + 1;
	}

	void resizeDOWN()
	{
		int* newArr = new int[size - 1];

		for (int i = 0; i < size - 1; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		size = size - 1;
	}
	
	DynamicList(int* a, int s)
	{
		arr = a;
		size = s;
	}

	void addEnd(int val)
	{
		resizeUP();

		arr[size - 1] = val;
	}

	void addStart(int val)
	{
		addGivenP(val, 0);
	}

	void addGivenP(int val, int pos)
	{
		resizeUP();
		for (int i = size - 1; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[pos] = val;
	}

	void delStart()
	{
		delGivenP(0);
	}

	void delEnd()
	{
		resizeDOWN();
	}

	void delGivenP(int pos)
	{
		for (int i = pos; i < size; ++i)
		{
			arr[i] = arr[i + 1];
		}
		resizeDOWN();
	}

	int Next(int pos)
	{
		if (pos + 1 < size)
		{
			return arr[pos + 1];
		}
	}

	int Previous(int pos)
	{
		if (pos > 0)
		{
			return arr[pos - 1];
		}
	}

	bool checkDupli()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = i+1; j < size-1; ++j)
			{
				if (arr[i] == arr[j])
				{
					return true;
				}
			}
		}
		return false;
	}

	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			//cout << arr[i] << endl;
		}
	}
};