/*Given a string, find the length of the longest substring without repeating characters.
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 *
 * accepted 2014-03-26
 */
#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int cha[26];
	int i;
	for(i = 0; i < 26; i++)
		cha[i] = -1;
	int maxbg,maxlen,bg,len;
	maxbg = maxlen = bg = len = 0;
	for(i = 0; i < s.size(); i++)
	{
		//cout << "bg len" << bg << " " << len << endl;
		if(cha[s[i] - 'a'] < bg)
		{
			cha[s[i] - 'a'] = i;
			len++;
			if(len > maxlen)
			{
				maxlen = len;
				maxbg = bg;
			}
		}
		else
		{
			bg = cha[s[i] - 'a'] + 1;
			len = i - bg + 1;
			cha[s[i] - 'a'] = i;
		}
	}
	cout << "MAXLEN and MAXBG:" << maxlen << " " << maxbg << endl;
	return maxlen;
}

int main()
{
	string a = "qopubjguxhxdipfzwswybgfylqvjzhar";
	int b = lengthOfLongestSubstring(a);
	return 0;
}
