// 03_STL.Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

struct Student
{
	string Name;
	string Group;
	double mark;

	Student(string name, string group, double m) : Name(name), Group(group), mark(m){}

	void Print()
	{
		cout << setw(25) << Name << setw(25) <<  Group <<setw(25) << mark << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

	deque<Student> dq1, dq2;

	string strArr[] = {"John Smith", "Duncun MacCloud", "Mila Yolowich From 5 Element 12345679846541324165479857"};

	for(int i = 0; i < sizeof(strArr)/sizeof(string); i++)
	{
		cout << "Counter: " << sizeof(strArr)/sizeof(string) << " Arr:" << sizeof(strArr) << " Str:" << sizeof(string) << endl;
		dq1.push_back(Student(strArr[i], "21s18-1pr", rand()%13));
	}

	dq1.push_front(Student("Bruce Willis",	"21s18-1pr", rand()%13));
	dq1.push_front(Student("Chuck Norris",	"21s18-1pr", rand()%14));
	dq1.push_front(Student("Luck Skywalker", "21s18-1pr", rand()%13));
	dq1.push_front(Student("Gregory House", "21s18-1pr", rand()%13));
	dq1.push_front(Student("Harry Potter", "21s18-1pr", rand()%13));

	for(int i = 0; i < dq1.size(); i++)
	{
		dq1[i].Print();
	}

	dq1.pop_front();

	/*for(int i = 0; i < dq1.size(); i++)
	{
		dq1[i].Print();
	}*/

	// assign
	dq2.assign(dq1.begin(), dq1.end());
	cout << endl;
	for(int i = 0; i < dq2.size(); i++)
	{
		dq2[i].Print();
	}

	// insert 
	dq1.insert(++dq1.begin() /* dq1.begin()+3 */, Student("Black Arni", "21s18-1pr", rand()%13));
	cout << "insert" << endl;
	for(int i = 0; i < dq1.size(); i++)
	{
		dq1[i].Print();
	}


	// erase
	dq1.erase(dq1.begin()+1);
	dq1.erase(dq1.begin(), dq1.end()-3);
	cout << endl;
	for(int i = 0; i < dq1.size(); i++)
	{
		dq1[i].Print();
	}


	return 0;
}

