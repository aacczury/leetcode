#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define R 3
#define C 3

int maximalSquare(char matrix[R][C]) {
	if(R == 0) return 0;
	int maxSquare = 0;
	vector< vector<int> > s(R, vector<int>(C, 0));
	for(int i = 0; i < R; ++ i){
		s[i][0] = matrix[i][0] - 48;
		maxSquare = max(maxSquare, s[i][0]);
	}
	for(int j = 0; j < C; ++ j){
		s[0][j] = matrix[0][j] - 48;
		maxSquare = max(maxSquare, s[0][j]);
	}

	for(int i = 1; i < R; ++ i)
		for(int j = 1; j < C; ++ j){
			if(matrix[i][j] - 48){
				s[i][j] = min(s[i-1][j], s[i][j-1]);
				s[i][j] = min(s[i][j], s[i-1][j-1]) + 1;
				maxSquare = max(maxSquare, s[i][j]);
			}else{
				s[i][j] = 0;
			}
		}
	return maxSquare;
}

int main(){
	char M[R][C] =  {{'1', '1', '1'}, 
					{'1', '1', '1'},
					{'1', '1', '1'}};
	cout << maximalSquare(M) << endl;
}