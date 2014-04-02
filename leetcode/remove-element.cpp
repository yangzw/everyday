/*Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
 *
 * accepted 2014-03-30
 */

int removeElement(int A[], int n, int elem) {
	int i,j;
	for(i = 0; i < n && A[i] != elem; i++);
	if(i == n)
		return n;
	j = i + 1;
	while(j < n)
	{
		while(j < n && A[j] == elem)
			j++;
		if(j == n)
			break;
		A[i++] = A[j++];
	}
	return i;
}
