#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define R 6
#define C 5

int maximalRectangle(int matrix[R][C]) {
	if(R == 0) return 0;
	int max = 0;
	vector< vector<int> > s(R, vector<int>(C, 0));
	for(int i = 0; i < R; ++ i)
		s[i][C-1] = matrix[i][C-1];
	for(int i = 0; i < R; ++ i)
		for(int j = C - 2; j >= 0; -- j)
			s[i][j] = (matrix[i][j] == 1) ? s[i][j + 1] + 1 : 0;
	
	for(int i = 0; i < R; ++ i)
		for(int j = 0; j < C; ++ j){
			if((C-j) * (R-i) <= max) break;
			int width = s[i][j];
			for(int k = i; k < R && width > 0; ++ k){
				if(width * (R-i) <= max) break;
				if(width > s[k][j]) width = s[k][j];
				if(max < width * (k-i+1)) max = width * (k-i+1);
			}
		}
	return max;
}

int main(){
	int M[R][C] =  {{0, 1, 1, 0, 1}, 
					{1, 1, 0, 1, 0}, 
					{0, 1, 1, 1, 0},
					{1, 1, 1, 1, 0},
					{1, 1, 1, 1, 1},
					{0, 0, 0, 0, 0}};
	cout << maximalRectangle(M) << endl;
}