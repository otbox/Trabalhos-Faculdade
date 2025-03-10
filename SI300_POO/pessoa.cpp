#include <iostream>
#include <string>
using namespace std;

class Person {
    public: 
        int age;
        string name;
        string skinColor;
        int weight;
        void run();
        Person(int age, string name, string skinColor, int weight){
            this->age = age;
            this->name = name;
            this->skinColor = skinColor;
            this->weight = weight;
        }

};

void Person::run() {
    cout << "Corre negada" << endl;
}

int main ()  {
    Person julio(19, "Julio", "pardo", 61);
    julio.run();
    cout << julio.name << endl;


}