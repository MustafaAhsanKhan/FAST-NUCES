// Name: Mustafa Ahsan Khan
// Roll Number: 23i-0549
// Section: CS-B

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX_WORDS = 1000;
const int MAX_LINE_LENGTH = 1000;


//////////////////////////////////
// CUSTOM STRING DATATYPE CLASS //
//////////////////////////////////

class String
{
private:
	char* data;  // Character Array
	int len;  // length of the string

public:
	// Default constructor
	String();

	// Constructor from char array
	String(const char* c_str);

	// Copy constructor
	String(const String& other);

	// Assignment operator
	String& operator=(const String& other);

	// Return len of the string
	int getlen() const;

	// Return the char array
	char* getData() const;

	// Access character at index
	char& operator[](int index);
	const char& operator[](int index) const;

	// Overloaded + operator to concatenate two String objects
	String operator+(const String& other) const;

	// Overloaded + operator to concatenate a String object and a char array
	String operator+(const char* c_str) const;

	// Overloaded + operator to concatenate a String object and a single character
	String operator+(char x) const;

	// Remove all extra spaces  // Reduce spaces between words to 1  // Also shorten the array
	void reduceSpaces();

	// Compare with another string object
	bool compare(const String& other) const;

	// Destructor
	~String();

private:
	// Helper functions
	int strlen(const char* c_str) const;
	void strcpy(char* dest, const char* src) const;
	bool strcmp(const char* c_str_1, const char* c_str_2) const;
};

String::String()
{
	data = NULL;
	len = 0;
}

// Constructor from C-string
String::String(const char* c_str)
{
	len = strlen(c_str);
	data = new char[len + 1];
	strcpy(data, c_str);
}

// Copy constructor
String::String(const String& other)
{
	len = other.len;
	data = new char[len + 1];
	strcpy(data, other.data);
}

// Assignment operator
String& String::operator=(const String& other)
{

	delete[] data;  // Clear the current array

	// Making a copy of the "other" string object
	len = other.len;
	data = new char[len + 1];
	strcpy(data, other.data);

	return *this;
}

// length of the string
int String::getlen() const
{
	return len;
}

// The char array
char* String::getData() const
{
	return data;
}

// Access character at index
char& String::operator[](int index)
{
	if (index >= len || index < 0)  // Bounds check
	{
		exit(EXIT_FAILURE);
	}
	return data[index];
}

// Access character at index (const version)
const char& String::operator[](int index) const
{
	if (index >= len || index < 0)  // Bounds check
	{
		exit(EXIT_FAILURE);
	}
	return data[index];
}

// Overloaded + operator to concatenate two String objects
String String::operator+(const String& other) const
{
	int new_len = len + other.len;  // New len
	char* new_Data = new char[new_len + 1];  // Allocate memory

	if (data)
	{
		for (int i = 0; i < len; ++i)  // Left string
		{
			new_Data[i] = data[i];
		}
	}

	for (int i = 0; i < other.len; ++i)
	{
		new_Data[len + i] = other.data[i];  // Right string
	}

	new_Data[new_len] = '\0';  // Null terminate

	String result;  // New string object
	result.data = new_Data;
	result.len = new_len;

	return result;
}

// Overloaded + operator to concatenate a String object and a char array
String String::operator+(const char* c_str) const
{
	String new_s(c_str);  // String object from c-string  // Makes it easier to concatenate, as length and data will be allocated auto

	return *this + new_s;  // Concatenating a string object with another string object
}

// Overloaded + operator to concatenate a String object and a single character
String String::operator+(char x) const
{
	String new_s;  // Same logic  // Making the c-string into a String object
	new_s.len = 1;
	new_s.data = new char[2];  // One for the character and one for null terminator
	new_s.data[0] = x;
	new_s.data[1] = '\0';

	return *this + new_s;  // Concatenating a string object with another string object
}


// Remove all extra spaces  // Reduce spaces between words to 1  // Also shorten the array
void String::reduceSpaces()
{
	if (data)
	{
		int l = 0;  // Left pointer
		while (l < len && data[l] == ' ')  // Spaces before
		{
			++l;
		}

		int r = len;  // Right pointer
		while (r > l && data[r - 1] == ' ')  // Spaces after
		{
			--r;
		}

		if (l > 0 || r < len)  // If trailing spaced found
		{
			char* new_data = new char[r - l + 1];  // Just enough space for the words

			int i = l;

			while (i < r)
			{
				new_data[i - l] = data[i];
				++i;
			}
			new_data[r - l] = '\0';  // Null termination
			delete[] data;
			// Updating the char array and length
			data = new_data;
			len = r - l;
		}

		int short_len = 0;
		bool multipleSpace = false;

		for (int i = 0; i < len; ++i)  // Calculating the new shorter length  // With reduced spaces
		{
			if (data[i] != ' ')
			{
				multipleSpace = false;
				++short_len;
			}
			else if (multipleSpace == false)
			{
				multipleSpace = true;
				++short_len;
			}
		}

		// Allocate new data with the correct len
		char* new_data = new char[short_len + 1];
	
		multipleSpace = false;

		for (int i = 0, j = 0; i < len; ++i)  // Copying characters
		{
			if (data[i] != ' ')
			{
				multipleSpace = false;
				new_data[j] = data[i];
				++j;
			}
			else if (multipleSpace == false)
			{
				multipleSpace = true;
				new_data[j] = ' ';
				++j;
			}
		}
		new_data[short_len] = '\0';  // Null termination

		// Replace old data with new data
		delete[] data;
		data = new_data;
		len = short_len;
	}
}


// Compare with another string
bool String::compare(const String& other) const
{
	if (len != other.len)
	{
		return false;
	}
	return strcmp(data, other.data);
}

// Destructor
String::~String()
{
	delete[] data;
}

// Helper functions for string operations
int String::strlen(const char* c_str) const
{
	int len = 0;
	while (c_str[len] != '\0')  // End of char array isnt reached
	{
		++len;
	}
	return len;
}

void String::strcpy(char* dest, const char* src) const
{
	char* ptr = dest;
	while (*src)  // Loop until the end of src is reached
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
}


bool String::strcmp(const char* c_str_1, const char* c_str_2) const
{
	const char* temp1 = c_str_1;
	const char* temp2 = c_str_2;

	while (*temp1 && (*temp1 == *temp2))
	{
		++temp1;
		++temp2;
	}
	if (*temp1 == '\0' && *temp2 == '\0')  // Reached the end of both strings
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char* getText(int documentNumber);

//////////////////////////////////////////////////////
// CLASS TO PROCESS THE DOCUMENTS FOR PLAG CHECKING //
//////////////////////////////////////////////////////

class DocumentProcessing
{
public:
	String stop_words;
	int num_docs;
	String* document_paths;  // Path of the document for file open
	String* document_text;  // Array to store the text of the respective document

	String* stop_words_array;
	int stop_words_count;


	// These are just soft copies so we can use the data across functions
	char** uniqueWords;
	int uniqueCount;
	int** documentFrequency;

	double** similarities;

	DocumentProcessing()
	{
		num_docs = 0;
		document_paths = NULL;
		document_text = NULL;

		stop_words_array = NULL;
		stop_words_count = 0;

		uniqueWords = NULL;
		documentFrequency = NULL;
		uniqueCount = 0;

		similarities = NULL;
	}

	void readInput(const char* pathofInputFile)
	{
		ifstream inputFile(pathofInputFile);

		if (!inputFile.is_open())
		{
			exit(EXIT_FAILURE);  // File open error
		}

		char buffer[MAX_LINE_LENGTH];
		inputFile.getline(buffer, MAX_LINE_LENGTH);  // Stop words line

		// Skip the "Stop Words: "(12 characters)
		const int skip_len = 12;
		if (charLen(buffer) > skip_len)
		{
			stop_words = String(buffer + skip_len);
		}

		inputFile.getline(buffer, MAX_LINE_LENGTH);  // Number of documents

		num_docs = 0;

		for (int i = 0; buffer[i] != '\0'; ++i)
		{
			// Convert character to its integer equivalent
			num_docs = num_docs * 10 + (buffer[i] - '0');
		}

		// Allocate memory for document files and contents
		document_paths = new String[num_docs];
		document_text = new String[num_docs];

		for (int i = 0; i < num_docs; ++i)  // Read document file names
		{
			inputFile.getline(buffer, MAX_LINE_LENGTH);
			document_paths[i] = String(buffer); // Store filename

			// Read the content of the document
			ifstream file(document_paths[i].getData());
			if (!file.is_open())
			{
				exit(EXIT_FAILURE);
			}

			String fileContent;
			while (file.getline(buffer, MAX_LINE_LENGTH))
			{
				fileContent = fileContent + buffer;
			}

			document_text[i] = fileContent; // Store content in array
			file.close();
		}

		inputFile.close();
	}

	void removePunctuationMarks()
	{
		for (int i = 1; i <= num_docs; ++i) // For all documents
		{
			String S1(getText(i));
			char* text = S1.getData(); // Get the text for the current document
			for (int i = 0; text[i] != '\0'; ++i)
			{
				if (!isLetter(text[i]))  // Anything that isnt a letter will be replaced with ' '  // That can further be removed
				{
					text[i] = ' ';
				}
			}
			S1.reduceSpaces();  // Remove the extra spaces
			document_text[i - 1] = S1;  // Storing the updated text
		}
	}

	void convertUpperToLowerCase()
	{
		for (int i = 1; i <= num_docs; ++i)  // For all documents
		{
			String S1(getText(i));
			char* text = S1.getData(); // Get the text for the current document
			for (int i = 0; text[i] != '\0'; ++i)
			{
				if (text[i] >= 'A' && text[i] <= 'Z')
				{
					text[i] = text[i] + 32;  // Change to lower case
				}
			}
			document_text[i - 1] = S1;  // Storing the updated text
		}
	}

	void removeStopWords()
	{
		splitStopWords(stop_words);
		char temp_c = ' ';
		for (int d = 0; d < num_docs; ++d)  // For all documents
		{
			String word;
			for (int i = 0; i < document_text[d].getlen(); ++i)
			{
				temp_c = document_text[d][i];
				if (temp_c == ' ')
				{
					if (isStopWord(word, stop_words_array))  // If word is a stop word
					{
						// Replace the stop word with spaces in the document

						int j = i - word.getlen();

						while (j < i)
						{
							document_text[d][j] = ' ';
							++j;
						}
					}
					word = "";  // Reset for the next word
				}
				else
				{
					word = word + temp_c;  // Add the character
				}
			}

			// Handling the last word
			if (word.getlen() > 0 && isStopWord(word, stop_words_array))
			{

				int j = document_text[d].getlen() - word.getlen();

				while (j < document_text[d].getlen())
				{
					document_text[d][j] = ' ';
					++j;
				}
			}

			document_text[d].reduceSpaces();  // Removing extra spaces

		}

	}

	void generateFrequencies(char**& uniqueWords, int& uniqueCount, int**& documentFrequency)
	{
		uniqueCount = 0;

		uniqueWords = new char* [MAX_WORDS];
		documentFrequency = new int* [num_docs];

		this->uniqueWords = uniqueWords;  // Soft copy
		this->documentFrequency = documentFrequency;

		for (int i = 0; i < num_docs; ++i)
		{
			documentFrequency[i] = new int[MAX_WORDS]();  // Initialize with 0s
		}

		for (int document_index = 0; document_index < num_docs; ++document_index)  // Loop for each document
		{
			String word;
			String& d_text = document_text[document_index];

			for (int i = 0; i < d_text.getlen(); ++i)
			{
				char c = d_text[i];
				if (c == ' ')
				{
					// Process the word if it's non-empty
					if (word.getlen() > 0)
					{
						int uWord_Index = -1;
						for (int j = 0; j < uniqueCount; ++j)  // Searching the uniqueWords array to check if it already exists
						{
							if (strCompare(word.getData(), uniqueWords[j]))
							{
								uWord_Index = j;  // If word found
								break;
							}
						}

						if (uWord_Index == -1)  // If word not found
						{
							uniqueWords[uniqueCount] = new char[word.getlen() + 1];  // Allocate memory
							strCopy(uniqueWords[uniqueCount], word.getData());
							uWord_Index = uniqueCount;
							uniqueCount++;
						}

						documentFrequency[document_index][uWord_Index]++;  // Increment the frequency of the most recent word

						// Reset the word for the next one
						word = "";
					}
				}
				else
				{
					word = word + c;  // Add the current character to generate the word
				}
			}

			// Handle the last word in the document
			if (word.getlen() > 0)
			{
				int uWord_Index = -1;
				for (int j = 0; j < uniqueCount; ++j)
				{
					if (strCompare(word.getData(), uniqueWords[j]))
					{
						uWord_Index = j;
						break;
					}
				}

				if (uWord_Index == -1)
				{
					uniqueWords[uniqueCount] = new char[word.getlen() + 1];
					strCopy(uniqueWords[uniqueCount], word.getData());
					uWord_Index = uniqueCount;
					uniqueCount++;
				}

				documentFrequency[document_index][uWord_Index]++;
			}
		}

		this->uniqueCount = uniqueCount;

	}

	int getFrequency(char* word, int documentNum)
	{
		documentNum--;  // 0 indexing

		for (int i = 0; i < uniqueCount; ++i)  // Searching for the specified word
		{
			if (strCompare(uniqueWords[i], word) == 1)  // If word found
			{
				return documentFrequency[documentNum][i];
			}
		}

		// If the word is not found, return -1
		return -1;
	}

	void calculateAllCosineSimilarities(double**& similarities, int** documentFrequency)
	{
		similarities = new double* [num_docs];  // Allocate memory

		for (int i = 0; i < num_docs; ++i)
		{
			similarities[i] = new double[num_docs];
		}

		this->similarities = similarities;

		for (int i = 0; i < num_docs; ++i)  // For all documents
		{
			for (int j = i; j < num_docs; ++j)
			{
				// Calculate dot product and magnitudes
				double dotProduct = 0.0;
				double A_magnitude = 0.0;
				double B_magnitude = 0.0;
				int freqA = 0;
				int freqB = 0;

				// Iterate over all unique words
				for (int uWord_Index = 0; uWord_Index < uniqueCount; ++uWord_Index)
				{
					freqA = documentFrequency[i][uWord_Index];
					freqB = documentFrequency[j][uWord_Index];

					// Dot product of the two vectors
					dotProduct += freqA * freqB;

					// Magnitude of the vectors
					A_magnitude += freqA * freqA;
					B_magnitude += freqB * freqB;
				}

				A_magnitude = sqrt(A_magnitude);
				B_magnitude = sqrt(B_magnitude);

				// Handle the case where both magnitudes are zero (documents have no words in common)
				if (A_magnitude == 0 || B_magnitude == 0)
				{
					similarities[i][j] = 0.0;  // Set similarity to 0 if either vector has no magnitude
				}
				else
				{
					// Calculate cosine similarity in percentage and round to two decimal places
					similarities[i][j] = round((dotProduct / (A_magnitude * B_magnitude)) * 100 * 100) / 100.0;
				}

				similarities[j][i] = similarities[i][j];  // As the matrix is symmetric
			}
		}
	}

	double similarityIn(int documentNum1, int documentNum2)
	{
		documentNum1--;  // 0 indexing
		documentNum2--;
		return similarities[documentNum1][documentNum2];
	}

	
	~DocumentProcessing()
	{
		delete[] document_paths;
		document_paths = NULL;
		
		delete[] document_text;
		document_text = NULL;
		
		delete[] stop_words_array;
		stop_words_array = NULL;

		for (int i = 0; i < uniqueCount; ++i)
		{
			delete[] uniqueWords[i];
		}
		delete[] uniqueWords;
		uniqueWords = NULL;

		for (int i = 0; i < num_docs; ++i)
		{
			delete[] documentFrequency[i];
		}
		delete[] documentFrequency;
		documentFrequency = NULL;
		
		for (int i = 0; i < num_docs; ++i)
		{
			delete[] similarities[i];
		}
		delete[] similarities;
		similarities = NULL;
	}


	// Helper Functions
private:
	// Function to check whether a char is a letter or not
	bool isLetter(char x)
	{
		return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'));
	}

	// Function to split the stop words String into an array of words
	void splitStopWords(const String& stop_words)
	{
		char temp_c = ' ';
		stop_words_array = new String[MAX_WORDS];

		String word;
		for (int i = 0; i < stop_words.getlen(); ++i)
		{
			temp_c = stop_words[i];
			if (temp_c == ' ')  // Using the space as the delimiter
			{
				stop_words_array[stop_words_count] = word;  // Add word to the array
				++stop_words_count;
				word = "";  // Reset for the next word
			}
			else
			{
				word = word + temp_c;  // Append character to the current word
			}
		}

		// Add the last word
		if (word.getlen() > 0)
		{
			stop_words_array[stop_words_count] = word;
			++stop_words_count;
		}
	}

	// Function to check if a word is a stop word
	bool isStopWord(const String& word, String* stop_words_array)
	{
		for (int i = 0; i < stop_words_count; ++i)
		{
			if (word.compare(stop_words_array[i]))
			{
				return true;  // If word matches any stop word
			}
		}
		return false;
	}

	bool strCompare(const char* c_str_1, const char* c_str_2) const
	{

		if (charLen(c_str_1) != charLen(c_str_2))
		{
			return false;
		}
		const char* temp1 = c_str_1;
		const char* temp2 = c_str_2;

		while (*temp1 && (*temp1 == *temp2))
		{
			++temp1;
			++temp2;
		}
		if (*temp1 == '\0' && *temp2 == '\0')  // Reached the end of both strings
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void strCopy(char* dest, const char* src) const
	{
		char* ptr = dest;
		while (*src)  // Loop until the end of src is reached
		{
			*ptr = *src;
			ptr++;
			src++;
		}
		*ptr = '\0';
	}

	int charLen(const char* c_str) const
	{
		int len = 0;
		while (c_str[len] != '\0')  // End of char array isnt reached
		{
			++len;
		}
		return len;
	}

};



DocumentProcessing proc;

// Function to read input from a file and document contents
void readInput(const char* pathofInputFile)
{
	proc.readInput(pathofInputFile);
}

// Function to get the number of documents
int getNumberOfDocument()
{
	return proc.num_docs;
}

// Function to get the content of a document by its number
char* getText(int documentNumber)
{
	documentNumber--; // 0 indexing
	return proc.document_text[documentNumber].getData();
}


// Function to remove punctuation marks from documents
void removePunctuationMarks()
{
	proc.removePunctuationMarks();
}

// Function to convert all characters in documents to lowercase
void convertUpperToLowerCase()
{
	proc.convertUpperToLowerCase();
}

// Function to remove stop_words from documents
void removeStopWords()
{
	proc.removeStopWords();
}

// Function to generate frequencies of each unique word in each document
void generateFrequencies(char**& uniqueWords, int& uniqueCount, int**& documentFrequency)
{
	proc.generateFrequencies(uniqueWords, uniqueCount, documentFrequency);
}


int getFrequency(char* word, int documentNum)   // -1 if not found
{
	return proc.getFrequency(word, documentNum);
}

void calculateAllCosineSimilarities(double**& similarities, int** documentFrequency)
{
	proc.calculateAllCosineSimilarities(similarities, documentFrequency);
}

double similarityIn(int doucmentNum1, int documentNum2)
{
	return proc.similarityIn(doucmentNum1, documentNum2);
}

//int main()
//{
//	return 0;
//}