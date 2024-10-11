#pragma once

// Question 1

template<typename T>

T findMostFrequentElement(T arr[], int size)
{
	T freq = 0;
	T most_freq_element = arr[0];

	for (int i = 0; i < size; ++i)
	{
		T curr_freq = 1;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] == arr[j])
			{
				curr_freq++;
			}
		}

		if (curr_freq > freq)
		{
			freq = curr_freq;
			most_freq_element = arr[i];
		}
	}

	return most_freq_element;
}

// Question 2

template<typename T>
void rearrangeArray(T arr[], int size)
{
	T* newarr = new T[size];

	for (int i = 0; i < size; ++i)
	{
		newarr[i] = arr[i];
	}

	int i = 0;
	int j = size - 1;

	for (int k = 0; k < size; ++k)
	{
		if (k % 2 == 0)  // Even
		{
			arr[k] = newarr[j];
			j--;
		}
		else  // Odd
		{
			arr[k] = newarr[i];
			i++;
		}
	}

	delete[] newarr;  // Free the dynamically allocated memory
}

// Question 3

template<typename T>

T* sumOfArrays(const T arr1[], const T arr2[], int size)
{
	T* newarr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		newarr[i] = arr1[i] + arr2[i];
	}
	return newarr;
}

// Question 4

template<typename T>

class Container {
private:

	T* arr;
	int size;
public:
	Container(T* arr, int size)
	{
		this->arr = arr;
		this->size = size;
	}
	T* sortInWaveForm()
	{
		T temp = 0;

		for (int i = 0; i < size - 1; ++i)
		{
			if ((i % 2 == 0) && (arr[i] < arr[i + 1]))
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			else if ((i % 2 != 0) && (arr[i] > arr[i + 1]))
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}

		return arr;
	}
};