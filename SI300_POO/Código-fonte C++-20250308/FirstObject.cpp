/*
 * FirstObject.cpp
 *
 *  Created on: Mar 20, 2022
 *      Author: andre
 */


using namespace std;

#include <iostream>

class FirstObject
	{
	private:

		int value;

	public:

		FirstObject(int initialValue) :
				value(initialValue)
			{
			// nothing to do
			cout << "Parametrized constructor: Only to say \"I'm here.\" (" << this->value << ")"<< endl;
			}

		FirstObject() :
				FirstObject(0)
			{
			// nothing to do
			cout << "Default constructor: Only to say \"I'm here.\" (" << this->value << ")" << endl;
			}

		~FirstObject()
			{
			cout << "Destructor: Only to say \"I'm here.\" (" << this->value << ")" << endl;
			}

		void setValue(int value)
			{
			this->value = value;
			}

		int getValue(void)
			{
			return (this->value);
			}
	};

int main(int argc, char *argv[])
	{
	cout << argv[0] << endl << "First object!" << endl;
	cout << endl;

	FirstObject firstObject1;
	FirstObject firstObject2;
	FirstObject firstObject3;

	firstObject1.setValue(-9);
	firstObject2.setValue(1024);

	cout << "firstObject 1: " << firstObject1.getValue() << endl;
	cout << "firstObject 2: " << firstObject2.getValue() << endl;
	cout << "firstObject 3: " << firstObject3.getValue() << endl;

	cout << endl;

	FirstObject firstObject4(2000);
	FirstObject firstObject5(-480);
	FirstObject firstObject6;

	cout << "firstObject 1: " << firstObject4.getValue() << endl;
	cout << "firstObject 2: " << firstObject5.getValue() << endl;
	cout << "firstObject 3: " << firstObject6.getValue() << endl;

	cout << endl;

	}



