i/*Given a non-negative number represented as an array of digits, plus one to the number.

   The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution{
	public:
		vector<int> plusOne(vector<int> &digits){
			int end = digits.size() - 1;
			do{
				if(digits[end] == 9)
				{
					digits[end] = 0;
					end--;
				}
				else
				{
					digits[end] = digits[end] + 1;
					return digits;
				}
			}while(end >= 0);
			if(end < 0){
				vector<int>::iterator it;
				it = digits.begin();
				digits.insert(it,1);
			}
			return digits;
		}
}
