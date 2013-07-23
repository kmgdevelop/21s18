// 04_STL.Ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

class Base
{
	int num;
public:
	Base(){}
	Base(int a): num(a){}

	virtual void Print()
	{ 
		cout << " num = " << num << endl;
	}
	~Base()
	{
		cout << "\tBase class destructor" << endl;
	}
};

class Child1 : public Base
{
	string str;

public: 
	Child1(){}
	Child1(string str, int num): str(str), Base(num){}

	void Print()
	{
		Base::Print();
		cout << "str = " << str << endl;
	}
};

class Child2 : public Base
{
	double d;
	char * test;
public:
	Child2()
	{
		this->test = 0;
	}
	Child2(double d, int n,  char * test): d(d), Base(n)
	{
		this->test = new char[strlen(test)+1];
		strcpy_s(this->test, strlen(test)+1, test);
	}
	void Print()
	{
		Base::Print();
		cout << "d=" << d << "  test=" << this->test << endl;
	}
	void SetTest(char* txt)
	{
		delete[] this->test;
		this->test = new char[strlen(txt) + 1];
		strcpy_s(this->test, strlen(txt)+1, txt);
	}
};

int main(int argc, _TCHAR* argv[])
{
	/*
	int * aa, *bb;

	aa = new int(10);
	bb = aa;

	delete aa;
	//delete bb;

	//cout << *bb << endl;

	auto_ptr<int> a(new int) , b, c;
	*a.get() = 123;
	cout << "a.get() = " << a.get() << "*a.get() = " << *a.get() << endl;
	*a = 222;
	cout << "*a = " << *a << endl;

	b = a;
	if(a.get() == NULL)
	{
		cout << "a is empty" << endl;
	}

	c = b;

	shared_ptr<int> sp0(new int(11)), sp1(new int(20)), sp2;
	cout << "*sp0 = " << *sp0 << endl;
	cout << "*sp1 = " << *sp1 << endl;

	sp2 = sp1;
	cout << "*sp1 = " << *sp1 << endl;
	*/
	//cout << "*sp2 = " << *sp2 << endl;
	//cout << "*sp1 = " << *sp1 << endl;

	{
		shared_ptr<Base> obj1 (new Child1("String", 10)), obj3;
		shared_ptr<Base> obj2(new Child2(2.55, 11, "Ha-ha"));

		//obj3 = obj1;

		obj3 = obj2;
		((Child2*)obj3.get())->SetTest("Ho-ho");

		obj1->Print();
		obj2->Print();
		obj3->Print();
	}
	

	return 0;
}

