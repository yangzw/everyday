//各种排序算法
//冒泡，选择， 插入，希尔，快速,归并、堆、基数排序
#include <iostream>

using namespace std;

//交换元素
void swp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//打印数组
void print(int* array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
//冒泡排序,时间复杂度o(n*n)，稳定排序
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
//直接插入排序，时间复杂度最坏o(n*n)，最好是o(n),稳定排序
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
//选择排序,时间复杂度是o(n*n)，不稳定的排序
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

//希尔排序,不稳定的排序
void shellpass(int* array, int increase, int size)//对每一个小组进行插入排序
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

/*快速排序,最坏情况时间复杂度o(n*n) 空间复杂度O(n)，
最好时间复杂度O(n log n)空间复杂度O(log n),不稳定的排序*/
int dividearray(int* array, int lt, int rt)
{
    /*选择基数不为r时,pivotIndex可以选择生成随机数，或者可以选择l+(r - l)/2
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

/*归并排序，时间复杂度均为O(n log n)，空间复杂度为O(n)
也可以同过直接插入排序来获得有序的子序列，再来两两归并，稳定排序*/
void merge(int* array, int l, int m, int r)//合并两个有序数组
{
    int i(0), j(0);
    int left_number = m - l + 1;
    int* tmparray = new int [r - l + 1];//将原来的数组复制到临时数组
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
    //当左或者右数组还有剩余时
    while(i < left_number)
        array[p++] = tmparray[i++];
    while(j <= r-l)
        array[p++] = tmparray[j++];
    delete [] tmparray;
}
void mergesort(int* array, int lft, int rgt)//分治法，自顶向下归并
{
    if(lft < rgt)
    {
        int middle = (rgt - lft)/2 + lft;
        mergesort(array, lft, middle);//先左右排序
        mergesort(array, middle+1, rgt);
        merge(array, lft, middle, rgt);//再归并
    }
}

//堆排序,利用大根堆。时间复杂度均为O(n log n)，就地排序，不稳定排序
void shift_down(int* array, int i, int heap_size)//向下调整，保持根的性质
{
    int l = 2*i + 1;
    while(l < heap_size)
    {
        if(l+1 < heap_size && array[l+1] > array[l])//当右子树比左子树大时
            l++;
        if(array[l] > array[i])//如果子比父大
            swp(array[i], array[l]);
        i = l;
        l = l*2 + 1;
    }
}
void buildheap(int* array, int heap_size)//建堆
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

//基数排序，时间复杂度o(n)，稳定排序
void radixsort(int* array, int array_size)
{
}

int main()
{
    int n;
    cout << "输入数的个数" << endl;
    cin >> n;
    int array[n];
    cout << "输入数组"<< endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << "排序前：" << endl;
    print(array, n);
    //bubllesort(array, n);//冒泡排序
    insertsort(array, n);//插入排序
    //shellsort(array, n);//希尔排序
    //selectsort(array, n);//选择排序
    //quicksort(array, 0, n-1);//快速排序
    //mergesort(array, 0, n-1);//归并排序
    //heapsort(array, n);//堆排序
    //radixsort(array, n);//基数排序
    cout << "排序后："<< endl;
    print(array, n);
    return 0;
}
