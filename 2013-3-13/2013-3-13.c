/*定义字符串的左旋转操作：把字符串前面的若干个（K个）字符移动到字符串的尾部。
 *
 * 　　如把字符串abcdef左旋转2位得到字符串cdefab。
 *
 * 　　请实现字符串左旋转的函数，要求对长度为n的字符串操作的时间复杂度为O(n)，空间复杂度为O(1)。
 */
#include <stdio.h>  
#include <string.h>  
#define ARRAY_SIZE 100

char *reverse(char *start, char *end)  
{     
	char tmp, *ptmp = start;      
	while (start != NULL && end != NULL && start < end)    
	{     
		tmp = *start;     
		*start = *end;        
		*end = tmp;       
		start ++;     
		end --;   
	}  
	return ptmp;  
}  

char *left(char *s, int pos)   //pos为要旋转的字符个数，或长度，下面主函数测试中，pos=3。  
{  
	int len = strlen(s);  
	reverse(s, s + (pos - 1));  //如上，X->X^T，即 abc->cba  
	reverse(s + pos, s + (len - 1)); //如上，Y->Y^T，即 def->fed  
	reverse(s, s + (len - 1));  //如上，整个翻转，(X^TY^T)^T=YX，即 cbafed->defabc。  
	return s;  
}  

int main()  
{     
	char array[ARRAY_SIZE];
	gets(array);
	int pos;
	scanf("%d",&pos);
	puts(left(array,pos));  
	return 0;  
}  
