#include <iostream>
using namespace std;

class Forno {
    private:
        float temperatura;
    public:
        Forno (float temperatura = 0.0f) {
            setTemperatura(temperatura);
        }
        float getTemperatura() {return temperatura;}
        void setTemperatura(float temperatura) {if (!(temperatura > 280.0f || temperatura < 0.0f)) {this->temperatura = temperatura;} else {cout << "Temperatura Inválida" << endl;}}
        void getStatus () {
            cout << "Forno cozinhando a " << temperatura << " graus";
        }
};

class FornoEletrico : public Forno {
    private:
        int potencia;
    public:
        FornoEletrico(float temperatura, int potencia) : Forno(temperatura) {
            this->potencia = potencia;
        }
        void setPotencia (int potencia) {this->potencia = potencia;}
        int getPotencia () {return potencia;}

        void getStatus () {
            cout << "Forno Elétrico trabalhando a " << getTemperatura() << " graus a uma potencia de " << potencia << " watts" << endl; 
        }
};

class FornoResistivo : public FornoEletrico {
    private:
        int resistencia;
    public:
        FornoResistivo(float temperatura, int potencia, int resistencia) : FornoEletrico(temperatura, potencia) {
            this->resistencia = resistencia;
        }

        void setResistencia (int resistencia) {this->resistencia = resistencia;}
        int getResistencia () {return resistencia;}

        void getStatus () {
            cout << "Forno a Indução trabalhando a " << getTemperatura() << " graus a uma potencia de " << getPotencia() << " watts resistivo a " <<  resistencia << " ohms" << endl; 
        }
}; 

class FornoInducao : public FornoEletrico {
    private:
        float amperagem;
    public:
        FornoInducao(float temperatura, int potencia, int amperagem) : FornoEletrico(temperatura, potencia) {
            this->amperagem = amperagem;
        }

        void setAmperagem (int amperagem) {this->amperagem = amperagem;}
        float getAmperagem () {return amperagem;}

        void getStatus () {
            cout << "Forno a Indução trabalhando a " << getTemperatura() << " graus a uma potencia de " << getPotencia() << " watts induzido a " <<  amperagem << " amperes " << endl; 
        }
}; 

class FornoGas : public Forno {
    private:
        float pressao;
    public:
        FornoGas(float temperatura, float pressao) : Forno(temperatura) {
            this->pressao = pressao;
        }

        void setPressao (float pressao) {this->pressao = pressao;}
        float getPressao () {return pressao;}
        void getStatus () {
            cout << "Forno a gás trabalhando a " << getTemperatura() << " graus a uma pressao de " << pressao << " psi" << endl; 
        }
};

class FornoGasNatural : public FornoGas {
    private:
        float fluxoGas;
    public:
        FornoGasNatural(float temperatura, float pressao, float fluxoGas) : FornoGas(temperatura, pressao) {
            this->fluxoGas = fluxoGas;
        }

        void setFluxoGas (float fluxoGas) {this->fluxoGas = fluxoGas;}
        int getFluxoGas () {return fluxoGas;}

        void getStatus () {
            cout << "Forno a Gas Natural trabalhando a " << getTemperatura() << " graus a uma pressão de " << getPressao() << " psi a um fluxo de " << fluxoGas << " l/s" << endl; 
        }
}; 

class FornoPetroleo : public FornoGas {
    private:
        float fluxoPetroleo;
    public:
        FornoPetroleo(float temperatura, float pressao, float fluxoPetroleo) : FornoGas(temperatura, pressao) {
            this->fluxoPetroleo = fluxoPetroleo;
        }

        void setFluxoPetroleo (float fluxoPetroleo) {this->fluxoPetroleo = fluxoPetroleo;}
        int getFluxoPetroleo () {return fluxoPetroleo;}

        void getStatus () {
            cout << "Forno a petroleo trabalhando a " << getTemperatura() << " graus a uma pressão de " << getPressao() << " psi a um fluxo de " << fluxoPetroleo << " l/s" << endl; 
        }
}; 

class FornoLenha : public Forno {
    private:
        int potencia;
    public:
        FornoLenha(float temperatura, int potencia) : Forno(temperatura) {
            this->potencia = potencia;
        }
        void getStatus () {
            cout << "Trabalhando a " << getTemperatura() << " graus a uma potencia de " << potencia << " watts" << endl; 
        }
};

int main () {
    Forno *FornoClassico = new Forno(100.0f);
    FornoClassico->setTemperatura(3000.0f);

    FornoClassico->getStatus();

    FornoEletrico *FornoEletrico1 = new FornoEletrico(100.0f, 230);

    FornoResistivo * FornoResistivo1 = new FornoResistivo(110.0f,200, 30);
    
    FornoInducao * FornoInducao1 = new FornoInducao(140.0f,200, 30.0f);
    
    FornoPetroleo * FornoPetroleo1 = new FornoPetroleo(100,200, 30);

    FornoGas * FornoGas1 = new FornoGas(230.0f, 23.0f);
    
    return 0;
}