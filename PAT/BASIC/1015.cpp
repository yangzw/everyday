#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct student
{
	string number;
	int scorea;
	int scoreb;
	int cat;
};
int number,N,M;

inline int clarify(int scorea,int scoreb)
{
	if(scorea >= M && scoreb >= M)
		return 3;
	else if(scorea >= M && scoreb < M)
		return 2;
	else if(scorea < M && scoreb < M && scorea >= scoreb)
		return 1;
	else
		return 0;
}

inline bool compare(student a, student b)
{
	int cata = -1,catb = -1;
	if(a.cat == b.cat)
	{
		if((a.scorea + a.scoreb) == (b.scorea+b.scoreb))
		{
			if(a.scorea == b.scorea)
				return a.number < b.number;
			else
				return a.scorea > b.scorea;
		}
		else (a.scorea + a.scoreb) > (b.scorea + b.scoreb);
	}
	else
		return a.cat > b.cat;
}

inline bool print(student a)
{
	cout << a.number << " " << a.scorea << " " << a.scoreb << endl;
}


int main()
{
	vector<student> vec;
	int count = 0;
	int a,b;
	string studentn;
	cin >> number >> N >> M;
	student tmp;
	while(number--)
	{
		cin >> studentn >> a >> b;
		if(a >= N && b >= N)
		{
			count ++;
			tmp.number = studentn;
			tmp.scorea = a;
			tmp.scoreb = b;
			tmp.cat = clarify(a,b);
			vec.push_back(tmp);
		}
	}
	cout << count << endl;
	sort(vec.begin(),vec.end(),compare);
	for_each(vec.begin(),vec.end(),print);
	return 0;
}
