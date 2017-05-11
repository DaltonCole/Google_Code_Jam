#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int rounds;
	long number_of_stalls;
	long users;
	list<long> stalls;

	list<long>::iterator max;
	long distance;
	long half_distance;

	cin >> rounds;

	for(int i = 0; i < rounds; i++) {
		stalls.clear();
		cin >> number_of_stalls >> users;

		stalls.push_back(number_of_stalls);

		for(long u = 0; u < users; u++) {
			max = max_element(stalls.begin(), stalls.end());

			if(max == stalls.end()) {
				distance = 1;
			} else {
				distance = *max;
			}

			half_distance = distance / 2;


			if(half_distance <= 1) {
			} else if(distance % 2 == 1) {
				stalls.insert(max, half_distance);
				stalls.insert(max, half_distance);
			} else {
				if(half_distance - 1 > 1) {
					stalls.insert(max, half_distance - 1);
				}
				stalls.insert(max, half_distance);
			}

			if(distance != 1) {
				stalls.erase(max);
			}

			if(u == users - 1) {
				cout << "Case #" << i + 1 << ": ";
				if(distance % 2 == 1) {
					cout << distance / 2 << " " << distance / 2 << endl;
				} else {
					cout << (distance / 2 ) << " " << (distance / 2 - 1) << endl;
				}
			}

			/*
			cout << "---" << endl;
			for(auto m : stalls) {
				cout << m << ", "; 
			}
			cout << endl << "---" << endl;
			*/
		}
		//stalls.pop_front();
		//stalls.pop_back();
		/*
			//cout << "---" << endl;
			for(auto m : stalls) {
				cout << m << ", "; 
			}
			cout << endl << "---" << endl;
		*/
	}

	return 0;
}
















