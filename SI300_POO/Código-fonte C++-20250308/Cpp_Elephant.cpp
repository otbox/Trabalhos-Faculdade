//============================================================================
// Name        : Cpp_Elephant.cpp
// Author      : Andre F. de Angelis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Program
	{
	private:
		int max = 7;
	public:
		void go(void);
	};

int main()
	{
	cout << "!!!Elefante que Incomoda!!!\n" << endl;

	Program *program = new Program();
	program->go();
	delete program;

	return (0);
	}

void Program::go()
	{
	int current = 1;

	while (current <= max)
		{
		if ((current % 2))
			{
			cout << current << " elefante(s) incomoda(m) muita gente!" << endl;
			}
		else
			{
			cout << current << " elefantes" << endl;
			for (int count = 0; count < current; count++)
				{
				cout << "\tincomodam" << endl;
				}
			cout << "\t\tmuito mais!" << endl;
			}
		current++;
		}
	}
