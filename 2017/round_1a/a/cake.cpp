#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;


struct point{
	int x;
	int y;
	char c;

	point() {
		x = 0;
		y = 0;
		c = '?';
	}

	point(int a, int b, char m) {
		x = a;
		y = b;
		c = m;
	}
};

class compare {
	public:
		bool operator() (point a, point b) {
			if(a.x < b.x) {
				return true;
			} else if (a.x == b.x) {
				return a.y < b.y;
			} 

			return false;
		}
};

bool compare_2(const point a, const point b) {
	if(a.y < b.y) {
			return true;
		} else if (a.y == b.y) {
			return a.x < b.x;
		} 

		return false;
}

void editor(vector<vector<char> > & grid, int r, int c) {
	vector<point> s;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] != '?') {
				point temp(j, i, grid[i][j]);
				s.push_back(temp);
			}
		}
	}

	sort(s.begin(), s.end(), compare_2);

	point current;
	point next;
	int index = 0;
	int row = r-1;
	int col = c-1;

	for(int i = 0; i < s.size() - 1; i++) {
		current = s[i];
		next = s[i+1];

		if(current.x > next.x) {
			row = current.y;
			col = c-1;
		} else if (next.y == current.y) {
			row = current.y;
			col = next.x - 1;
		} else {
			row = next.y - 1;
			col = c-1;
		}

		for(int m = row; m >= 0; m--) {
			for(int n = col; n >= 0; n--) {
				if(grid[m][n] == '?') {
					grid[m][n] = current.c;
				}
			}
		}
	}

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] == '?') {
				grid[i][j] = s[s.size() - 1].c;
			}
		}
	}

	return;
}

int main() {
	int rounds;

	char temp;

	int r;
	int c;

	cin >> rounds;

	for(int i = 0; i < rounds; i++) {
		cin >> r >> c;
		vector<char> columns(c, '?');
		vector<vector<char> > grid(r, columns);

		for(int row = 0; row < r; row++) {
			for(int col = 0; col < c; col++) {
				cin >> grid[row][col];
			}
		}

		editor(grid, r, c);

		cout << "Case #" << i + 1 << ":" << endl;
		for(int row = 0; row < r; row++) {
			for(int col = 0; col < c; col++) {
				cout << grid[row][col];
			}
			cout << endl;
		}
	}

	return 0;
}