/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * accepted 3014-3-25
 */
double findKth(int A[], int m, int B[], int n, int k){
	if (m == 0) 
		return B[k-1];
	if (n == 0) 
		return A[k-1];
	if (k == 1) 
		return min(A[0], B[0]);
	if (m < n) 
		return findKth(B, n, A, m, k);
	int i = m/2;
	int low = 0, high = n-1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (B[mid] <= A[i]) 
			low = mid + 1; 
		else 
			high = mid - 1;
	}
	int j = high; //B[j] is the maximum number which <= A[i]
	if (i+j+2 == k) //i+j+2 is the rank of A[i]
		return A[i];
	else if (i+j+2 < k)
		return findKth(A+i+1, m-i-1, B+j+1, n-j-1, k-i-j-2);
	else
		return findKth(A, i, B, j+1, k);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if((n+m) % 2 == 1)
		return findKth(A,m,B,n,(n+m)/2 + 1);
	else
	{
		float a = findKth(A,m,B,n,(n+m)/2);
		float b = findKth(A,m,B,n,(n+m)/2+1);
		return (a+b)/2.0;
	}
}
