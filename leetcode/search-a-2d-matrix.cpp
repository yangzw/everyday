/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 *Given target = 3, return true.
 */

class Solution{
	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target){
			int m = matrix.size();
			int n = matrix[0].size();
			int low = 0, high = m*n - 1;
			int middle = 0;
			while(low <= high){
				middle = (high - low) / 2 + low;
				int j = middle % n;
				int i = (middle - j) / n;
				if(matrix[i][j] == target)
					return true;
				else if(matrix[i][j] > target)
					high = middle - 1;
				else
					low = middle + 1;
			}
			return false;
		}
}
