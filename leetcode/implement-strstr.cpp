/* Implement strStr().
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 
 *
 * accepted 2014-03-30
 */
#include<iostream>
using namespace std;

void KMP(int* array, char *str, int len)
{
	int k = 0;
	for(;k < len; k++)
		array[k] = 0;
	k = 1;
	int tmp;
	while(k < len)
	{
		tmp = k;
		while(tmp > 0)
		{
			tmp = array[tmp-1];
			if(str[tmp] == str[k])
			{
				array[k] = tmp + 1;
				break;
			}
		}
		k++;
	}
}

char *strStr(char *haystack, char *needle){
	int i = 0;
	int len_needle,len_hay;
	while(needle[i] != '\0')
		i++;
	len_needle = i;
	i = 0;
	while(haystack[i] != '\0')
		i++;
	len_hay = i;
	if(len_needle == 0)
		return haystack;
	if(len_hay == 0)
		return NULL;
	int next[len_needle];
	KMP(next,needle,len_needle);
	//for(i = 0; i < len_needle; i++)
	//	cout << next[i] << " ";
	//cout << endl;
	int j = 0;
	for(i = 0; i < len_hay && j < len_needle; i++)
	{
	//	cout << i << " " << j << endl;
		if(needle[j] != haystack[i])
		{
			if(j != 0)
			{
				j = next[j-1];
				i--;
			}
			else
				j = 0;
		}
		else
			j++;
	}
	if(j == len_needle)
		return (haystack + i - j);
	else
		return NULL;
}

int main()
{
	char a[13] = "abcdabababab";
	char b[10] = "abababab";
	cout << strStr(a,b) << endl;
	return 0;
}
