#include <iostream>

using namespace std;

bool isFull(char seatChar[7][5]);
void checkSeat(char seatChar[7][5],int row,char seat);
void printSeats(char seatChart[7][5]);

int main() {
	char seatChart[7][5] = {{'1','A','B','C','D'},
				{'2','A','B','C','D'},
				{'3','A','B','C','D'},
				{'4','A','B','C','D'},
				{'5','A','B','C','D'},
				{'6','A','B','C','D'},
				{'7','A','B','C','D'}}; 
	int row = 0;
	char seat = ' ',
	     enterAgain = 'N';	

	do {
		printSeats(seatChart);
		cout << "Enter row number:";
		cin  >> row;
		while (row < 1 || row > 7) {
			cout << "Enter a value between 1 and 7:";
			cin  >> row;
		}
		cout << "Enter seat letter:";
		cin  >> seat;
		// Use ASCII values for A - D to validate input
		while (seat < 'A' || seat > 'D') {
			cout << "Enter A, B, C, or D:";
			cin  >> seat;
		}

		checkSeat(seatChart,row,seat);
		cout << "\nWould you like to book another seat?" << endl
		     << "Enter Y for yes and anything else to quit:";
		cin  >> enterAgain;
	} while(enterAgain == 'Y' && !(isFull(seatChart)));
 
	if (isFull(seatChart))
		cout << "Sorry, there are no more empty seats on this plane." << endl;
 
	return 0;
}

bool isFull(char seatChar[7][5]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 4; j++) {
			if (seatChar[i][j] != 'X')
				return false;
		}
	}
	return true;
}

void checkSeat(char seatChart[7][5], int row, char seat) {
	int i = 0;

}

void printSeats(char seatChart[7][5]) {
	cout << "AVAILABLE SEATS:" << endl;
	
}
