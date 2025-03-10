#include <iostream>
using namespace std;

class Person {
private:
    string text;
public:
    Person(string text = "Unicamp") {this->text = text;}

    string getText() {return text;}
    void setText(string text) {this->text = text;}
};

int main(){
    Person *estudante = new Person();
    cout << estudante->getText() << endl;
    Person *estudante1 = new Person("Fapesp");
    cout << estudante1->getText() << endl;
    delete estudante;
    delete estudante1;
    return 0;
} 
