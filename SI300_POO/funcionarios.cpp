#include <iostream>
#include <string>

using namespace std;

class Funcionario {
    protected:
        string nome;
        double salario;
        string cargo;
    public:
        Funcionario (string nome, double salario, string cargo) {
            this->nome = nome;
            this->cargo = cargo;
            this->salario = salario;
        }
        virtual double getSalario () {
            return salario;
        }
        string getCargo () {
            return cargo;
        }
        string getNome () {
            return  nome;
        } 
        
};

class Gerente : public Funcionario {
    private: 
        double bonus;
    public: 
        Gerente(string nome, double salario, double bonus) 
            : Funcionario(nome, salario, "Gerente"), bonus(bonus) {}
        double getBonus() {
            return bonus;
        }
        void setBonus(double bonus) {
            this->bonus = bonus;
        }
        double getSalario () override {
            return this-> salario + bonus;
        }

};

class Desenvolvedor : public Funcionario {
    private:
        double bonus;
        double desconto;
    public:
        double getSalario () override {
            return this-> salario + bonus - desconto;
        }
        Desenvolvedor (string nome, double salario, string cargo, double bonus,double desconto)
         : Funcionario(nome, salario, cargo) {
            this->nome = nome;
            this->cargo = cargo;
            this->salario = salario;
            this->bonus = bonus;
            this->desconto = desconto;
        }
};

int main () {
    Desenvolvedor Deyvin("David", 1500, "preguiçoso", 300,100);
    cout << Deyvin.getSalario();
    return 0;
}