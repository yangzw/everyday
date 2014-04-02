/*用四则运算实现加减乘除
 * 由于除法边界值如果仅仅用int类型处理，不太好处理。所以直接用了long long型, 也直接用了比较运算。
 *Divide two integers without using multiplication, division and mod operator.
 *
 *
 * accepted 2014-04-01
 */
#include<iostream>
#include<cstdlib>
#define MAX_SIZE        sizeof(int)*8
#define MAX     2147483647
#define MIN     (-2147483648)
#define HALF_MIN        ((1<<(MAX_SIZE-1)) ^ (1 << (MAX_SIZE-2)))
using namespace std;

inline int add(int a, int b)
{
        int re = a,carry = 0;
        while(b)
        {
                re = a^b;
                carry = a&b;
                a = re; 
                b = carry << 1;
        }
        return re; 
}

//判断正负    
inline int ispos( int a )   
{ //正   
        return (a&(add(1<<(MAX_SIZE-1),-1))) && !(a&(1<<(MAX_SIZE-1)));  
}  

inline int isneg( int a )
{ //负   
        return a&(1<<(MAX_SIZE-1));
}

inline int iszero( int a )
{ //0   
        return !(a&add(~1,1));
}

inline int sub(int a, int b)
{
        int re = 0;
        b = add(~b, 1);
        re = add(a,b);
        return re;
}

inline int pos_mul(int a, int b)
{
        int re = 0;
        //cout << a << b << endl;
        while(b)
        {
                if(b&1)
                        re = add(re,a);
                a = a << 1;
                b = b >> 1;
        }
        return re;
}

inline int mul(int a, int b)
{
        if(iszero(a) || iszero(b))
                return 0;
        if(a == MIN)
        {
                if(isneg(b))
                        return MAX;
                return MIN;
        }
        if(b == MIN)
        {
                if(isneg(a))
                        return MAX;
                return MIN;
        }
        if(ispos(a) && ispos(b))
                return pos_mul(a,b);
        else if(isneg(a))
        {
                if(isneg(b))
                        return pos_mul(add(~a,1),add(~b,1));
                else
                        return add(~(pos_mul(add(~a,1),b)),1);
        }
        return add(~(pos_mul(a,add(~b,1))),1);
}

inline int pos_divide(long long a, long long b){
        int ans = 0;
        //cout << a << b << ans << endl;
        if(a < b || a == 0)
                return 0;
        if(b == 1)
                return a;
        for(int i = 32; i >= 0; i--)
        {
                if((a >> i) >= b)
                {
                        a = a - (b << i);
                        ans = ans + (1 << i);
                }
        }
        return ans;
}


int divide(int dividend, int divisor) {
        long long dividend1 = (long long)dividend;
        long long divisor1 = (long long) divisor;
        if(divisor1 == 0)
        {
                cout << "error" << endl;
                exit(1);
        }
        if(dividend1 >= 0 && divisor1 > 0)
                return pos_divide(dividend1,divisor1);
        else if(dividend1 < 0)
        {
                cout << "here" << endl;
                if(divisor1 < 0)
                        return pos_divide(~dividend1+1,~divisor1+1);
                return (~(pos_divide(~dividend1+1,divisor1))+1);
        }
        cout << "and here " << endl;
        return (~(pos_divide(dividend1,~divisor1+1))+1);

}

int main()
{
        int a,b;
        cin >> a >> b;
//      cout << MIN << " "<< MAX << endl;
//      cout << add(a,b) << endl;
//      cout << sub(a,b) << endl;
        cout << mul(a,b) << endl;
//      cout << divide(a,b) << endl;
        return 0;
}

