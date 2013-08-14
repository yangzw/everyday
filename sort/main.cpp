//���������㷨
//ð�ݣ�ѡ�� ���룬ϣ��������,�鲢���ѡ���������
#include <iostream>

using namespace std;

//����Ԫ��
void swp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//��ӡ����
void print(int* array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
//ð������,ʱ�临�Ӷ�o(n*n)���ȶ�����
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
//ֱ�Ӳ�������ʱ�临�Ӷ��o(n*n)�������o(n),�ȶ�����
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
//ѡ������,ʱ�临�Ӷ���o(n*n)�����ȶ�������
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

//ϣ������,���ȶ�������
void shellpass(int* array, int increase, int size)//��ÿһ��С����в�������
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

/*��������,����ʱ�临�Ӷ�o(n*n) �ռ临�Ӷ�O(n)��
���ʱ�临�Ӷ�O(n log n)�ռ临�Ӷ�O(log n),���ȶ�������*/
int dividearray(int* array, int lt, int rt)
{
    /*ѡ�������Ϊrʱ,pivotIndex����ѡ����������������߿���ѡ��l+(r - l)/2
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

/*�鲢����ʱ�临�ӶȾ�ΪO(n log n)���ռ临�Ӷ�ΪO(n)
Ҳ����ͬ��ֱ�Ӳ����������������������У����������鲢���ȶ�����*/
void merge(int* array, int l, int m, int r)//�ϲ�������������
{
    int i(0), j(0);
    int left_number = m - l + 1;
    int* tmparray = new int [r - l + 1];//��ԭ�������鸴�Ƶ���ʱ����
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
    //������������黹��ʣ��ʱ
    while(i < left_number)
        array[p++] = tmparray[i++];
    while(j <= r-l)
        array[p++] = tmparray[j++];
    delete [] tmparray;
}
void mergesort(int* array, int lft, int rgt)//���η����Զ����¹鲢
{
    if(lft < rgt)
    {
        int middle = (rgt - lft)/2 + lft;
        mergesort(array, lft, middle);//����������
        mergesort(array, middle+1, rgt);
        merge(array, lft, middle, rgt);//�ٹ鲢
    }
}

//������,���ô���ѡ�ʱ�临�ӶȾ�ΪO(n log n)���͵����򣬲��ȶ�����
void shift_down(int* array, int i, int heap_size)//���µ��������ָ�������
{
    int l = 2*i + 1;
    while(l < heap_size)
    {
        if(l+1 < heap_size && array[l+1] > array[l])//������������������ʱ
            l++;
        if(array[l] > array[i])//����ӱȸ���
            swp(array[i], array[l]);
        i = l;
        l = l*2 + 1;
    }
}
void buildheap(int* array, int heap_size)//����
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

//��������ʱ�临�Ӷ�o(n)���ȶ�����
void radixsort(int* array, int array_size)
{
}

int main()
{
    int n;
    cout << "�������ĸ���" << endl;
    cin >> n;
    int array[n];
    cout << "��������"<< endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << "����ǰ��" << endl;
    print(array, n);
    //bubllesort(array, n);//ð������
    insertsort(array, n);//��������
    //shellsort(array, n);//ϣ������
    //selectsort(array, n);//ѡ������
    //quicksort(array, 0, n-1);//��������
    //mergesort(array, 0, n-1);//�鲢����
    //heapsort(array, n);//������
    //radixsort(array, n);//��������
    cout << "�����"<< endl;
    print(array, n);
    return 0;
}
