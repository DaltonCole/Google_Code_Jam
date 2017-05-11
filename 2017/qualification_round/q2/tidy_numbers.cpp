#include <iostream>
#include <string> 

using namespace std;



bool isTidy(long number) {
	string s = to_string(number);

	for(long i = 0; i < s.length() - 1; i++) {
		if(s[i] > s[i+1]) {
			if(s == "99999999999999999") {
				cout << i << endl;
			}
			return false;
		}
	}
	return true;
}

char next_number(char num) {
	switch(num){
		case 57:
			return 56;
		case 56:
			return 55;
		case 55:
			return 54;
		case 54:
			return 53;
		case 53:
			return 52;
		case 52:
			return 51;
		case 51:
			return 50;
		case 50:
			return 49;
		case 49:
			return 48;
		case 48:
			return 57;
		default:
			return 57;
	}
}

void decrement(string & number, int spot) {
	number[spot] = next_number(number[spot]);
	for(int i = spot + 1; i < number.length(); i++) {
		number[i] = '9';
	}
	if(number[0] == '0') {
		number = number.substr(1, number.length() - 1);
	}

	return;
}

int isTidy(string number) {
	for(long i = 0; i < number.length() - 1; i++) {
		if(number[i] > number[i+1]) {
			return i;
		}
	}
	return -1;
}

int main() {
	int rounds;
	string number;
	int spot;

	cin >> rounds;

	for(int j = 0; j < rounds; j++) {
		cin >> number;

		while(true) {
			spot = isTidy(number);
			if(spot == -1) {
				cout << "Case #" << j + 1 << ": " << number << endl;
				break;
			} else {
				decrement(number, spot);
			}
		}
	}

	return 0;
}














