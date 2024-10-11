#include <iostream>
using namespace std;

int main() {
    // Declare variables for use in the following program
    string first;
    string second;
    int added[21];     // Result can have up to 21 digits if there is an extra carry digit at the end
    int carry = 0;     // Integer value for the carry digit

    // Prompt for and obtain user input for the two char arrays representing the two numbers to be added
    cout << "Enter the first number:";
    cin  >> first;
    cout << "Enter the second number:";
    cin  >> second;

    // If statements to zero-pad as needed to make the two arrays the same length
    if (first.length() > second.length())
    {
        second.insert(second.begin(), first.length()-second.length(), '0');
    }
    else if (first.length() < second.length())
    {
        first.insert(first.begin(), second.length()-first.length(), '0');
    }


    // Initialize the two integer arrays
    int firstIntArray[first.length()];
    int secondIntArray[second.length()];

    int n = 0;
    // Convert char array to an int array by subtracting ASCII value 0 from each item in the char array
    // The array is stored in reverse. The last digit is stored in the first index of the array.
    for (int i = first.length()-1; i >= 0; i--)
    {
        firstIntArray[n] = first[i] - '0';
        n++;
    }

    int m = 0;
    // Perform the same char to int conversion for the second array
    for (int j = second.length()-1; j >= 0; j--)
    {
        secondIntArray[m] = second[j] - '0';
        m++;
    }

    // Add the two int arrays
    for (int i = 0; i < first.length(); i++)
    {
        if (firstIntArray[i] + secondIntArray[i] >= 10)     // Run if the sum of two digits is 10 or greater
        {
            added[i] = ((firstIntArray[i] + secondIntArray[i]) + carry) % 10;     // Add the corresponding digits (and carry digit if applicable)
            carry = (firstIntArray[i] + secondIntArray[i]) / 10;     // Obtain the carry digit
        }

        else     // Run if the sum of two digits is less than 10 (no carry digit generated)
        {
            added[i] = (firstIntArray[i] + secondIntArray[i]) + carry;     // Add the corresponding digits (and carry digit if applicable)
            carry = 0;     // No carry digit
        }
    }

    if (carry > 0)     // Check if there is a carry digit left at the end of the addition
    {
        added[first.length()] = carry;     // Append the carry digit to the end of the array
        cout << "The sum is: ";
        for (int i = first.length(); i >= 0; i--)     // Loop to print the added array, reversed so that it is in the proper order
        {
            cout << added[i];
        }
    }
    else     // Run if there is no leftover carry digit
    {
        added[first.length()] = 0;     // Append the carry digit to the end of the array
        cout << "The sum is: ";
        for (int i = first.length()-1; i >= 0; i--)     // Loop to print the added array, excluding the final 0 and reversed into the proper order
        {
            cout << added[i];
        }
    }

    return 0;     // Terminate the program
}
