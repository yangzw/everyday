//3.7队列中去最大值操作问题
//用最大堆实现的话，每个元素需要有指针来描述队列的先后顺序
//用栈实现
//
#include<iostream>
using namespace std;

class stack
{
	public:
		stack()
		{
			stackTop = -1;
			maxStackItemIndex = -1;
		}
		void Push(Type x)
		{
			stackTop ++;
			if(stackTop >= MAXN); //超出栈的最大存储量
			else
			{
				stackItem[stackTop] = x;
				if(x > Max())
				{
					link2NetxMaxItem[stackTop] = maxStackItemIndex; //用来维护最大值序列
					maxStackItemIndex = stackTop;
				}
				else
					link2NetxMaxItem[stackTop] = -1;
			}
		}
		Type Pop()
		{
			Type ret;
			if(stackTop < 0)
				ThrowException();
			else
			{
				ret = stackItem[stackTop];
				if(stackTop == maxStackItemIndex)
					maxStackItemIndex = link2NextMatxItem[stackTop];
				stackTop--;
			}
			return ret;
		}
		Type Max()
		{
			if(maxStackItemIndex >= 0)
				return stackItem[maxStackItemIndex];
			else
				return -INF;
		}
	private:
		Type stackItem[MAXN];
		int stackTop;
		int link2NextMaxItem[MAXN];
		int maxStackIndex;
}

class Quere
{
	public:
		Type MaxValue(Type x, Type y)
		{
			if(x > y)
				return x;
			else
				return y;
		}
		Type Queue::Max()
		{
			return MaxValue(stackA.Max(),stackB.Max());
		}
		EnQueue(v)
		{
			stackB.push(v);
		}
		Type DeQueue()
		{
			if(stackA.empty())
			{
				while(!stackB.empty())
					stackA.push(stackB.pop());
			}
			return stackA.pop();
		}

	private:
		stack stackA;
		stack stackB;
}
