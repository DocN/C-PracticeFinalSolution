#include <iostream>
#include "AccountDynamic.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include "Records.hpp"

using namespace std;


/*
void print(int && i) {
	cout << i << endl;
}

void print(int & i) {
	cout << i << endl;
}

void print(int i) {
	cout << "here" << endl;
	cout << i << endl;
}
*/

void printList(std::vector<string> test) {
	for (int i = 0; i < test.size(); i++) {
		std::cout << test.at(i) << endl;
	}
}

//question 9
class base {
	virtual void f() {}
};
class test1 : public base {

};
class test2 : public base {

};

//question 10
struct myfuckyoufunctor {
	int first;
	int second;
	bool firstRun;
	myfuckyoufunctor() {
		first = 2;
		second = 3;
		firstRun = true;
	}

	int operator()() {
		if (firstRun == true) {
			firstRun = false;
			return first;
		}
		int newfirst = second;
		int newsecond = first +second;
		first = newfirst;
		second = newsecond;
		return newsecond;
	}
};


class MyFunctor
{
private:
	int x;
public:
	int operator()(int x) { return  2; }
};

void print(int & value) {
	cout << "print & " << value << endl;
}

void print(int && value) {
	cout << "print && "<< value << endl;
}

int main() {
	//question 1
	AccountDynamic test;

	//question 2
	//lvalue are values stored in memory and rvalues are temporary values only used in register 
	int valhue = 2;
	print(valhue); //lvalue
	print(55); //rvalue
	//we can't pass rvalues by reference because there's no memory address for them so the print goes to our second print function &&

	//question 3
	//a pointer is an address in memory so it has a destination. On the other hand an rvalue reference is temporary and doesn't have a place in memory we can reference with a pointer.

	//question 4
	//a move semantic is when the values are actually moved from one container to another. 
	//For example if we pass a new instance of foo(batman()) this will move the data in the batman object to another batman object using the move constructor.
	//If we have an lvalue of the batman() object stored in batman x = batman(); then when we do foo(x); it will call the copy constructor to copy the values instead of stealing them from x
	//foo(batman bat);

	//question 5
	//in java you can assign functions to enumerators so they can perform actions. For example if you have an enumerator in java with a function hello you could do COLOR.hello(); In c++ enums are just values
	//without the ability to have functions like a class.

	//question 6
	std::vector<std::string> myList;
	myList.push_back("hello");
	myList.push_back("bye");
	myList.push_back("fuckyouc++");
	
	printList(myList);

	//lambda memes
	sort(myList.begin(), myList.end(),
[](const std::string & a, const std::string & b) -> bool
	{
		return a.length() > b.length();
	});

	printList(myList);

	//question 7 passing variables to a lambda is passing the value of the variable to the lambda, 
	//on the other hand capturing variables takes all the variables the function that calls the lambda has access to.

	//question 8
	Records<std::string, std::string> testrecord = Records<std::string, std::string>("fucking ehhh");
	testrecord.addRecord("fuck you");

	//test type with dyanmic cast q9
	base * t1 = new test1();
	test1 * t1Dyn = dynamic_cast<test1*>(t1);
	if (t1Dyn) {
		cout << "it's a test 1" << endl;
	}
	test2 * t2Dyn = dynamic_cast<test2*>(t1);
	if (t2Dyn) {
		cout << "it's a test 2" << endl;
	}

	base * t2 = new test2();
	test1 * t1DynB = dynamic_cast<test1*>(t2);
	if (t1DynB) {
		cout << "it's a test 1" << endl;
	}
	test2 * t2DynB = dynamic_cast<test2*>(t2);
	if (t2DynB) {
		cout << "it's a test 2" << endl;
	}

	//question 10 check the struct brah
	myfuckyoufunctor p;
	for (int i = 0; i < 20; i++) {
		cout << p() << endl;
	}
	system("pause");
	return 0;
}