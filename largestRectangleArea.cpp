#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& height) {
	if(height.size() == 0) return 0;
	stack<int> s;
	int i = 0;
	int maxArea = 0;
	while(i <= height.size()){
		if(s.empty() || i < height.size() && height[s.top()] <= height[i]){
			s.push(i++);
		}else if(s.empty()){
			break;
		}else {
			int t = s.top();
			s.pop();
			maxArea = max(maxArea, height[t] * (s.empty() ? i : i - s.top() - 1));
		}
	}
	return maxArea;
}

int main(){
	vector<int> v(2);
	v[0] = 1;
	v[1] = 1;
	
	cout << largestRectangleArea(v) << endl;
}