/*
 * Cpp_EncapsulatedString.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: andre
 *
 *      Crie uma classe C++ com único atributo string encapsulado em
 *      modo privativo (private) e os respectivos métodos getters,
 *      setters e construtor padrão (default) com parâmetro padrão
 *      (default parameter) para que, em caso de omissão, a string
 *      seja preenchida com o valor “Unicamp”. Se disponível, use o
 *      recurso de geração automática de getters e setters do seu IDE.
 *      Use o ponteiro this dentro dos métodos para diferenciar
 *      atributo e parâmetro. Escreva uma função main() que use a classe,
 *      alocando dinamicamente (new) os objetos, exercitando todos
 *      os seus métodos e liberando a memória (delete).
 */

#include <iostream>
using namespace std;

void welcome(string programName);

class EncapsulatedString
	{
	private:
		string value;

	public:

		EncapsulatedString(string value = "Unicamp") :
				value(value)
			{
			}

		string getValue() const
			{
			return value;
			}

		void setValue(string value)
			{
			this->value = value;
			}
	};

int main(int argc, char *argv[])
	{
	welcome(argv[0]);

	EncapsulatedString *firsObject = new EncapsulatedString();
	EncapsulatedString *secondObject = new EncapsulatedString("Covid-19");

	cout << firsObject->getValue() << endl;
	cout << secondObject->getValue() << endl;

   firsObject->setValue("Exercicio de aula");
   secondObject->setValue("String & encapsulamento");

	cout << firsObject->getValue() << endl;
	cout << secondObject->getValue() << endl;

	delete secondObject;
	delete firsObject;
	return 0;
	}

void welcome(string programName)
	{
	cout << programName << " is running..." << endl;
	}
