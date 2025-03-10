//============================================================================
// Name        : Hello_cpp.cpp
// Author      : Andre F. de Angelis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Escreva um programa C++ do tipo "hello-world'', para certificar-se da configuração do
// seu ambiente de trabalho. Compile e rode o programa, garantindo que não há erros ou avisos
// do compilador.

#include <iostream>
using namespace std;
/*
 int main()
 {
 cout << "!!!Hello World!!!" << endl;
 return (EXIT_SUCCESS);
 }
 */
#include <iostream>

// ANSI escape codes for text color

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main()
	{

	std::cout << "Teste" << std::endl;

	std::cout << "\033[H\033[2J" << std::endl;
	std::cout << "\033[2J\033[1;1H";

	std::cout << RED << "Red text" << RESET << std::endl;
	std::cout << GREEN << "Green text" << RESET << std::endl;
	std::cout << YELLOW << "Yellow text" << RESET << std::endl;
	std::cout << BLUE << "Blue text" << RESET << std::endl;
	std::cout << MAGENTA << "Magenta text" << RESET << std::endl;
	std::cout << CYAN << "Cyan text" << RESET << std::endl;

	return (0);
	}
