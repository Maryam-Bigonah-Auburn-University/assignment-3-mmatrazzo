#include <iostream>

using namespace std;

bool isFull(char seatChar[7][5]);     // Check if all seats are full
void checkSeat(char seatChar[7][5],int row,char seat);     // Check if a given seat is full and book seat if it is open
void printSeats(char seatChart[7][5]);     // Print all currently available seats

int main() {
	// Declare variable for use in the following program
	char seatChart[7][5] = {{'1','A','B','C','D'},     // 7x5 matrix of seats
				{'2','A','B','C','D'},
				{'3','A','B','C','D'},
				{'4','A','B','C','D'},
				{'5','A','B','C','D'},
				{'6','A','B','C','D'},
				{'7','A','B','C','D'}};
	int row = 0;
	char seat = ' ',
	     enterAgain = 'N';

	// Loop that runs until the user explicitly terminates the program or all seats are full
	do {
		printSeats(seatChart);     // Call function to display all open seats

		// Prompt for and obtain user input for the desired row
		cout << "Enter row number:";
		cin  >> row;

		// Loop that runs while an invalid row is entered
		// Prompt for and obtain corrected user row input
		while (row < 1 || row > 7) {
			cout << "Invalid input. Please enter a value between 1 and 7:";
			cin  >> row;
		}

		// Prompt for and obtain user input for the desired seat
		cout << "Enter seat letter:";
		cin  >> seat;

		// Use ASCII values for A - D to validate input
		// Loop that runs while an invalid seat is entered
		// Prompt for and obtain corrected user seat input
		while (seat < 'A' || seat > 'D') {
			cout << "Invalid input. Enter A, B, C, or D:";
			cin  >> seat;
		}

		// Call function to check the status of a given seat and book it if it is available
		checkSeat(seatChart,row,seat);

		// Propmpt for and obtain user input to determine if the program should continue to run
		cout << "\nWould you like to book another seat?" << endl
		     << "Enter Y for yes and anything else to quit:";
		cin  >> enterAgain;
	} while(enterAgain == 'Y' && !(isFull(seatChart)));

	// Run if all seats on the plane are full
	// Output a message indicating to the user that no more seats are available
	if (isFull(seatChart))
		cout << "Sorry, there are no more empty seats on this plane." << endl;

	return 0;     // Terminate the program
}

// Function to check if all seats on the plane are full
// Returns true or false (bool type)
bool isFull(char seatChar[7][5]) {
	// Nested for loops to loop through all elements in the 7x5 array seatChar
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 4; j++) {
			if (seatChar[i][j] != 'X')
				return false;     // Returns false only if not all elements in seatChar are set to 'X'
		}
	}
	return true;     // Returns true if all elements in seatChar are set to 'X'
}

// Function to check if a seat is available and, if so, book the seat
// Does not return a value (void type)
void checkSeat(char seatChart[7][5], int row, char seat) {
	int i = 0;

	// Switch statement to assign seats A-D to integers 1-4
	switch(seat) {
		case 'A':
			i=1;
			break;
		case 'B':
			i=2;
			break;
		case 'C':
			i=3;
			break;
		case 'D':
			i=4;
			break;
	}

	// Run if the seat is not already booked
	if (seatChart[row-1][i] != 'X')
	{
		seatChart[row-1][i] = 'X';     // Mark the seat as unavailable
		cout << "Your seat in row " << row << " and seat " << seat << " has been booked." << endl;
	}

	// Run if a seat has already been booked
	else
	{
		cout << "Sorry, this seat is not available." << endl;
	}
}

// Function to print all currently available seats
void printSeats(char seatChart[7][5]) {
	cout << "AVAILABLE SEATS:" << endl;
	// Nested for loops to check all seats and print those that are available
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 4; j++) {
			if (seatChart[i][j] != 'X')
			{
				cout << " " << i+1 << seatChart[i][j] << " ";     // Print row and seat number
			}
		}
	}
	cout << endl;
}
