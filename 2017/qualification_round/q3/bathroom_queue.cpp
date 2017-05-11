#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int rounds;
	long number_of_stalls;
	long users;
	priority_queue<long> stalls;

	long distance;
	long half_distance;

	cin >> rounds;

	for(int i = 0; i < rounds; i++) {
		stalls = priority_queue<long>();
		cin >> number_of_stalls >> users;

		stalls.push(number_of_stalls);

		for(long u = 0; u < users; u++) {
			distance = stalls.top();
			//cout << distance << endl;
			stalls.pop();

			if(u == users - 1) {
				cout << "Case #" << i + 1 << ": ";
				if(distance % 2 == 1) {
					cout << distance/2 << " " << distance/2 << endl;
				} else {
					cout << (distance/2 ) << " " << (distance/2 - 1) << endl;
				}
				break;
			}

			if(distance % 2 == 1) {
				distance /= 2;
				if(distance > 0) {
					stalls.push(distance);
					stalls.push(distance);
				}
			} else {
				distance /= 2;
				if(distance > 1) {
					stalls.push(distance - 1);
				}
				if(distance > 0) {
					stalls.push(distance);
				}
			}
		}
	}

	return 0;
}
















