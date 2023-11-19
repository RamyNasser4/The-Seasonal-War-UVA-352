#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool valid(int r,int c,int n){
	if(r > n-1 || r < 0 || c > n-1 || c < 0){
		return false;
	}
	return true;
}
void cntReachableCells(int r, int c, int n, int image[25][25]) {
	if (!valid(r,c,n) ||  !image[r][c]) {
		return;		// invalid position or block position
	}
	image[r][c] = 0;	// we just visited it, don't allow any one back to it
	// Try the 8 neighbor cells
	cntReachableCells(r, c - 1, n, image);
	cntReachableCells(r, c + 1, n, image);
	cntReachableCells(r - 1, c, n, image);
	cntReachableCells(r - 1, c - 1, n, image);
	cntReachableCells(r - 1, c + 1, n, image);
	cntReachableCells(r + 1, c, n, image);
	cntReachableCells(r + 1, c - 1, n, image);
	cntReachableCells(r + 1, c + 1, n, image);
}
int main() {
	int n;
	int imageCount = 1;
	while (cin >> n) {
		int image[25][25];
		for (int i = 0; n > i; ++i) {
			string input;
			cin >> input;
			for (int j = 0; n > j; ++j) {
				image[i][j] = int(input[j]) - 48;
			}
		}
		int cnt = 0;
		for (int i = 0; n > i; ++i) {
			for (int j = 0; n > j; ++j) {
				if (image[i][j]) {
					++cnt;
					cntReachableCells(i, j, n, image);
				}
			}
		}
		cout << "Image number " << imageCount << " contains " << cnt
				<< " war eagles." << endl;
		++imageCount;
	}
}

