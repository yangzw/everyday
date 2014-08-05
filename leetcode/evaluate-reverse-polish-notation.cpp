/* evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * valid operators are +,-,*,/. each operand may be an integer or another expression.
 * some examples:
 *     ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *       ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution{
	public:
		int evalRPN(vector <string> &tokens){
			stack<int> re;
			int i;
			int a,b;
			for(i = 0; i < tokens.size(); i++)
			{
				//better solution: string operators = "+-*/" and then use operators.contains(tokens[i])
				if((tokens[i][0] >= '0' && tokens[i][0] <= '9') || (tokens[i][0] == '-' && tokens[i].size() >= 2))
				{
					a = stoi(tokens[i]);
					re.push(a);
				}
				else{
					if(re.size() < 2)
					{
					//	cout << "missing operand" << endl;
						return 0;
					}
					if(tokens[i] == "+")
					{
						a = re.pop();
						b = re.pop();
						re.push(a+b);
					}
					else if(tokens[i] == "-")
					{
						a = re.pop();
						b = re.pop();
						re.push(b-a);
					}
					else if(tokens[i] == "*")
					{
						a = re.pop();
						b = re.pop();
						re.push(a*b);
					}
					else if(tokens[i] == "/")
					{
						a = re.pop();
						b = re.pop();
						if(a == 0)
						{
					//		cout << "can't divide 0" << endl;
							return 0;
						}
						re.push(b/a);
					}
					else{
					//	cout << "invalid input" << endl;
						return 0;
					}
				}
			}
			if(i > 0)
				return re.top();
			else
				return 0;
		}
};
