/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container. 
 *
 * accepted 2014-03-27
 */
#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> &height){
	int len = height.size();
	int low = 0;
	int high = len - 1;
	int maxarea = 0;
	int min;
	while(low < high)
	{
		if(height[high] > height[low])
			min = height[low];
		else
			min = height[high];
		if((high-low)*min > maxarea)
			maxarea = (high-low)*min;
		if(height[high] > height[low])
			low++;
		else
			high--;
	}
	return maxarea;
}

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(5);
	a.push_back(1);
	a.push_back(3);
	cout << maxArea(a) << endl;
	return 0;
}
