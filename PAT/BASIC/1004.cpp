#include<iostream>
#include<string>

using namespace std;

struct STUDENT
{
	string name;
	string number;
	int score;
};

int main()
{
	int numberOfStudent;
	cin >> numberOfStudent;
	STUDENT students[numberOfStudent];
	int i;
	int max,min;
	max = min = 0;
	for(i = 0;i < numberOfStudent;i++)
	{
		cin >> students[i].name >> students[i].number >> students[i].score;
		if(students[i].score > students[max].score)
			max = i;
		else if(students[i].score < students[min].score)
			min = i;
	}
	cout << students[max].name << " " << students[max].number << endl;
	cout << students[min].name << " " << students[min].number;
	return 0;
}
