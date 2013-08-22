//¸÷ÖÖÅÅÐòËã·¨
//Ã°ÅÝ£¬Ñ¡Ôñ£¬ ²åÈë£¬Ï£¶û£¬¿ìËÙ,¹é²¢¡¢¶Ñ¡¢»ùÊýÅÅÐò
#include <iostream>

using namespace std;

//½»»»ÔªËØ
void swp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//´òÓ¡Êý×é
void print(int* array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
//Ã°ÅÝÅÅÐò,Ê±¼ä¸´ÔÓ¶Èo(n*n)£¬ÎÈ¶¨ÅÅÐò
void bubllesort(int* array, int size)
{
    int i(0), j(0);
    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (array[j] < array[j-1])
                swp(array[j], array[j-1]);
        }
    }
}
//Ö±½Ó²åÈëÅÅÐò£¬Ê±¼ä¸´ÔÓ¶È×î»µo(n*n)£¬×îºÃÊÇo(n),ÎÈ¶¨ÅÅÐò
void insertsort(int* array, int size)
{
    int i(0), j(0);
    for (i = 1; i < size ; i++)
    {
        j = i;
        while (array[j] < array[j - 1])
        {
            swp(array[j], array[j-1]);
            j = j -1;
            if (!j)
                break;
        }
    }
}
//Ñ¡ÔñÅÅÐò,Ê±¼ä¸´ÔÓ¶ÈÊÇo(n*n)£¬²»ÎÈ¶¨µÄÅÅÐò
void selectsort(int* array, int size)
{
    int i(0), j(0);
    int min(0), minindex(0);
    for(i = 0; i < size; i ++)
    {
        min = array[i];
        minindex = i;
        for(j = i +1; j < size; j++)
        {
            if(array[j] < min)
            {
                minindex = j;
                min = array[j];
            }
        }
        if(min != i)
            swp(array[i], array[minindex]);
    }
}

//Ï£¶ûÅÅÐò,²»ÎÈ¶¨µÄÅÅÐò
void shellpass(int* array, int increase, int size)//¶ÔÃ¿Ò»¸öÐ¡×é½øÐÐ²åÈëÅÅÐò
{
    int i(0), j(0);
    for (i = increase; i < size ; i+= increase)
    {
        j = i;
        while (array[j] < array[j - increase])
        {
            swp(array[j], array[j-increase]);
            j = j - increase;
            if (!j)
                break;
        }
    }
}
void shellsort(int* array, int n)
{
    int increase = n;
    do
    {
        increase = increase/2;
        shellpass(array, increase, n);
    }
    while(increase > 1);
}

/*¿ìËÙÅÅÐò,×î»µÇé¿öÊ±¼ä¸´ÔÓ¶Èo(n*n) ¿Õ¼ä¸´ÔÓ¶ÈO(n)£¬
×îºÃÊ±¼ä¸´ÔÓ¶ÈO(n log n)¿Õ¼ä¸´ÔÓ¶ÈO(log n),²»ÎÈ¶¨µÄÅÅÐò*/
int dividearray(int* array, int lt, int rt)
{
    /*Ñ¡Ôñ»ùÊý²»ÎªrÊ±,pivotIndex¿ÉÒÔÑ¡ÔñÉú³ÉËæ»úÊý£¬»òÕß¿ÉÒÔÑ¡Ôñl+(r - l)/2
    get pivotIndex which >= l, and <= r
    swp(array[r], array[pivotIndex]);
    */
    int i = lt;
    for(int j = lt; j < rt; j++)
    {
        if(array[j] < array[rt])
        {
            swp(array[i], array[j]);
            i++;
        }
    }
    swp(array[i], array[rt]);
    return i;
}
void quicksort(int* array, int lt, int rt)
{
    if(lt < rt)
    {
        int q = dividearray(array, lt, rt);
        quicksort(array, lt, q - 1);
        quicksort(array, q + 1, rt);
    }
}

/*¹é²¢ÅÅÐò£¬Ê±¼ä¸´ÔÓ¶È¾ùÎªO(n log n)£¬¿Õ¼ä¸´ÔÓ¶ÈÎªO(n)
Ò²¿ÉÒÔÍ¬¹ýÖ±½Ó²åÈëÅÅÐòÀ´»ñµÃÓÐÐòµÄ×ÓÐòÁÐ£¬ÔÙÀ´Á½Á½¹é²¢£¬ÎÈ¶¨ÅÅÐò*/
void merge(int* array, int l, int m, int r)//ºÏ²¢Á½¸öÓÐÐòÊý×é
{
    int i(0), j(0);
    int left_number = m - l + 1;
    int* tmparray = new int [r - l + 1];//½«Ô­À´µÄÊý×é¸´ÖÆµ½ÁÙÊ±Êý×é
    for(i = 0; i < r-l+1; i++)
        tmparray[i] = array[l+i];
    int p = l;
    for(i = 0, j = left_number;(i < left_number)&&(j <= r-l);p++)
    {
        if(tmparray[i] > tmparray[j])
                array[p] = tmparray[j++];
        else
            array[p] = tmparray[i++];
    }
    //µ±×ó»òÕßÓÒÊý×é»¹ÓÐÊ£ÓàÊ±
    while(i < left_number)
        array[p++] = tmparray[i++];
    while(j <= r-l)
        array[p++] = tmparray[j++];
    delete [] tmparray;
}
void mergesort(int* array, int lft, int rgt)//·ÖÖÎ·¨£¬×Ô¶¥ÏòÏÂ¹é²¢
{
    if(lft < rgt)
    {
        int middle = (rgt - lft)/2 + lft;
        mergesort(array, lft, middle);//ÏÈ×óÓÒÅÅÐò
        mergesort(array, middle+1, rgt);
        merge(array, lft, middle, rgt);//ÔÙ¹é²¢
    }
}

//¶ÑÅÅÐò,ÀûÓÃ´ó¸ù¶Ñ¡£Ê±¼ä¸´ÔÓ¶È¾ùÎªO(n log n)£¬¾ÍµØÅÅÐò£¬²»ÎÈ¶¨ÅÅÐò
void shift_down(int* array, int i, int heap_size)//ÏòÏÂµ÷Õû£¬±£³Ö¸ùµÄÐÔÖÊ
{
    int l = 2*i + 1;
    while(l < heap_size)
    {
        if(l+1 < heap_size && array[l+1] > array[l])//µ±ÓÒ×ÓÊ÷±È×ó×ÓÊ÷´óÊ±
            l++;
        if(array[l] > array[i])//Èç¹û×Ó±È¸¸´ó
            swp(array[i], array[l]);
        i = l;
        l = l*2 + 1;
    }
}
void buildheap(int* array, int heap_size)//½¨¶Ñ
{
    for(int i = heap_size / 2 - 1; i >= 0; i--)
        shift_down(array, i, heap_size);
}
void heapsort(int* array, int array_size)
{
    int heap_size(0);
    buildheap(array, array_size);
    for(heap_size = array_size; heap_size>= 2; heap_size--)
    {
        swp(array[heap_size - 1], array[0]);
        shift_down(array, 0, heap_size - 1);
    }
}

//»ùÊýÅÅÐò£¬Ê±¼ä¸´ÔÓ¶Èo(n)£¬ÎÈ¶¨ÅÅÐò
void radixsort(int* array, int array_size)
{
}


void find_min(int * array, int array_size)
{
    int min = 0,i;
    for(i = 0;i <array_size;i++)
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

void find_max(int * array, int array_size)
{
    int max = 0,i;
    for(i = 0;i <array_size;i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

//count sort,stable，O(n), when  range is small
void countsort(int*array, int array_size)
{
    int min = find_min(array,array_size);
    int max = find_max(array,array_size);
    int range = max  - min + 1;
    int c[range],b[array_size];
    int i;
    for(i = 0;i < range;i++)
    {
        c[i] = 0;
    }
    for(i = 0;i < array_size;i++)
    {
        b[i] = array[i];
    }
    for(i =0;i < array_size;i++)
    {
        c[array[i] - min] += 1;
    }
    for(i = 1;i < range;i++)
    {
        c[i] += c[i-1];
    }
    for(i = array_size - 1;i > 0;i--)
    {
        array[c[b[i]-min] - 1] = b[i];
        c[b[i] - min]--;
    }
}

//select the ith element
int Randomized_select(int* array, int l, int r, int i)
{
	if (l == r)
	{
		return array[l];
	}
	int q; 
	q = dividearray(array,l,r);
    int k = q - l + 1;
    if(i == k)
        return a[q];
    else if(i < k)
        return Randomized_select(array,l,q-1,i);
    else
        return Randomized_select(array,q+1,r,i-k);
}

int main()
{
    int n;
    cout << "ÊäÈëÊýµÄ¸öÊý" << endl;
    cin >> n;
    int array[n];
    cout << "ÊäÈëÊý×é"<< endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << "ÅÅÐòÇ°£º" << endl;
    print(array, n);
    //bubllesort(array, n);//Ã°ÅÝÅÅÐò
    //insertsort(array, n);//²åÈëÅÅÐò
    //shellsort(array, n);//Ï£¶ûÅÅÐò
    //selectsort(array, n);//Ñ¡ÔñÅÅÐò
    //quicksort(array, 0, n-1);//¿ìËÙÅÅÐò
    //mergesort(array, 0, n-1);//¹é²¢ÅÅÐò
    //heapsort(array, n);//¶ÑÅÅÐò
    //radixsort(array, n);//»ùÊýÅÅÐò
	//countsort(array,n)
    cout << "ÅÅÐòºó£º"<< endl;
    print(array, n);
    return 0;
}
