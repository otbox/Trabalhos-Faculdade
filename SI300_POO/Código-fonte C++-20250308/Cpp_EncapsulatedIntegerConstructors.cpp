/*
 * Cpp_EncapsulatedInteger.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: andre
 *
 *    Crie uma classe C++ com único atributo inteiro encapsulado
 *    em modo privativo (private) e os respectivos métodos getters,
 *    setters, construtores padrão (default) e parametrizado.
 *    Use o ponteiro this dentro dos métodos para diferenciar atributo
 *    e parâmetro. Escreva uma função main() que use a classe,
 *    exercitando todos os seus métodos.
 */

#include <iostream>
using namespace std;

void welcome(string programName);

class EncapsulatedIntegerConstructors
	{
	private:
		int value;

	public:

		EncapsulatedIntegerConstructors(int value = 0) :
				value(value)
			{
			}

		int getValue() const
			{
			return value;
			}

		void setValue(int value)
			{
			this->value = value;
			}
	};

int main(int argc, char *argv[])
	{
	welcome(argv[0]);

	EncapsulatedIntegerConstructors firsObject;
	EncapsulatedIntegerConstructors secondObject(2048);

	cout << firsObject.getValue() << endl;
	cout << secondObject.getValue() << endl;

   firsObject.setValue(-1);
   secondObject.setValue(99);

	cout << firsObject.getValue() << endl;
	cout << secondObject.getValue() << endl;
	return 0;
	}

void welcome(string programName)
	{
	cout << programName << " is running..." << endl;
	}

