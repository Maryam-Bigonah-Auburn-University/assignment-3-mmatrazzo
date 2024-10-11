#include <iostream>
#include <iomanip>
using namespace std;

// Function definitions
int countOccurances(int arr[], int size, int n);     // Determines the number of times integer n appears in array arr
void sortArray(int arr[], int size);     // Sorts array arr in descending order

int main() {
	// Declare variables for use in the following program
	int size = 0;
	int arr[50];     // Max array size is 50 integer values
	int temp;

	// Prompt for and obtain user input for the first value in the array
	cout << "Enter a value:" << endl;
	cin >> temp;

	// Continue to prompt for and obtain user input for the remaining values in the array
	// Executes until "-1" is entered, or the max array size of 50 is reached
	while (size < 50 && temp != -1)
	{
		arr[size] = temp;
		size++;     // Increment size
		cout << "Enter another value, or enter -1 to terminate: " << endl;
		cin >> temp;
	}

	cout << "The sorted array is: ";
	sortArray(arr, size);     // Call the function to sort the array arr

	// Print the values stored in the sorted array
	for (int i = 0; i < size ; i++)
		{
		cout << arr[i] << " ";
		}

	// Format and print the "header" for the count table
	cout << endl;
	cout << left << setw(10) << "N" << setw(10) << "Count" << endl;

	// Format and print the number of occurances of each integer appearing in the array arr
	int previous = 0;
	for (int i = 0; i < size - 1; i++)
		if (arr[i] != previous)
		{
			previous = arr[i];
			cout << left << setw(10) << arr[i] << setw(10) << countOccurances(arr,size,previous) << endl;
		}


	return 0;     // Terminate the program
}

// Function to determine the number of times integer n appears in the array arr
int countOccurances(int *arr, int size, int n) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == n)     // Perform the following if the ith element in array arr matches the desired integer n
		{
			count++;     // Increment count
		}
	return count;     // Return the value of count
}

// Sort the array arr in descending order
// Function does not return a value (type void)
void sortArray(int *arr, int size) {
	int temp = 0;

	// Nested for loops to swap elements in the array as the sorting algorithm progresses
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[i])     // Perform is the jth element in array arr is greater than the ith element
			{
				// Swap the elements
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
}
