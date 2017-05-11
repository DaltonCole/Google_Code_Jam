#include <iostream>
#include <string>

using namespace std;

int main() {
	int rounds;
	int flips;
	int flip_at_once;
	string pancakes;

	cin >> rounds;

	for(int i = 0; i < rounds; i++) {
		flips = 0;
		cin >> pancakes >> flip_at_once;

		// Small data set, so let's just brute force this. :)
		for(int j = 0; j <= pancakes.length() - flip_at_once; j++) {
			// If we run into a sad pancake, Flip it and the following flip_at_once amount
			if(pancakes[j] == '-') {
				flips++;
				// Switch the next flip_at_once amount to the other side
				for(int k = j; k < j + flip_at_once; k++) {
					if(pancakes[k] == '+') {
						pancakes[k] = '-';
					} else {
						pancakes[k] = '+';
					}
				}
			}
		}

		cout << "Case #" << i + 1 << ": ";
		// See if there is a sad pancake
		if(pancakes.find('-') == string::npos) {
			cout << flips << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}