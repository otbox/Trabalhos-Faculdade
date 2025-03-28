#include <iostream>
using namespace std;

class Forno {
private:
    float temperatura;
public:
    Forno(float temperatura = 0.0f) {
        setTemperatura(temperatura);
    }
    float getTemperatura() { return temperatura; }
    void setTemperatura(float temperatura) { 
        if (!(temperatura > 280.0f || temperatura < 0.0f)) {
            this->temperatura = temperatura;
        } else {
            this->temperatura = 280.0f;
            cout << "Ajustado para o limite de 280ºC" << endl;
        }
    }
    void getStatus() {
        cout << "Forno cozinhando a " << temperatura << " graus" << endl;
    }
};

class FornoEletrico : public Forno {
private:
    int potencia;
public:
    FornoEletrico(float temperatura, int potencia) : Forno(temperatura) {
        this->potencia = potencia;
    }
    void setPotencia(int potencia) { this->potencia = potencia; }
    int getPotencia() { return potencia; }

    void getStatus()  {
        cout << "Forno Elétrico trabalhando a " << getTemperatura() << " graus a uma potência de " << potencia << " watts" << endl;
    }
};

class FornoResistivo : public FornoEletrico {
private:
    int resistencia;
public:
    FornoResistivo(float temperatura, int potencia, int resistencia) : FornoEletrico(temperatura, potencia) {
        this->resistencia = resistencia;
    }

    void setResistencia(int resistencia) { this->resistencia = resistencia; }
    int getResistencia() { return resistencia; }

    void getStatus() {
        cout << "Forno Resistivo trabalhando a " << getTemperatura() << " graus a uma potência de " << getPotencia() << " watts com resistência de " << resistencia << " ohms" << endl;
    }
};

class FornoInducao : public FornoEletrico {
private:
    float amperagem;
public:
    FornoInducao(float temperatura, int potencia, float amperagem) : FornoEletrico(temperatura, potencia) {
        this->amperagem = amperagem;
    }

    void setAmperagem(float amperagem) { this->amperagem = amperagem; }
    float getAmperagem() { return amperagem; }

    void getStatus() {
        cout << "Forno a Indução trabalhando a " << getTemperatura() << " graus a uma potência de " << getPotencia() << " watts com corrente de " << amperagem << " amperes" << endl;
    }
};

class FornoGas : public Forno {
private:
    float pressao;
public:
    FornoGas(float temperatura, float pressao) : Forno(temperatura) {
        this->pressao = pressao;
    }

    void setPressao(float pressao) { this->pressao = pressao; }
    float getPressao() { return pressao; }

    void getStatus() {
        cout << "Forno a Gás trabalhando a " << getTemperatura() << " graus a uma pressão de " << pressao << " psi" << endl;
    }
};

class FornoGasNatural : public FornoGas {
private:
    float fluxoGas;
public:
    FornoGasNatural(float temperatura, float pressao, float fluxoGas) : FornoGas(temperatura, pressao) {
        this->fluxoGas = fluxoGas;
    }

    void setFluxoGas(float fluxoGas) { this->fluxoGas = fluxoGas; }
    float getFluxoGas() { return fluxoGas; }

    void getStatus() {
        cout << "Forno a Gás Natural trabalhando a " << getTemperatura() << " graus a uma pressão de " << getPressao() << " psi e um fluxo de " << fluxoGas << " l/s" << endl;
    }
};

class FornoPetroleo : public FornoGas {
private:
    float fluxoPetroleo;
public:
    FornoPetroleo(float temperatura, float pressao, float fluxoPetroleo) : FornoGas(temperatura, pressao) {
        this->fluxoPetroleo = fluxoPetroleo;
    }

    void setFluxoPetroleo(float fluxoPetroleo) { this->fluxoPetroleo = fluxoPetroleo; }
    float getFluxoPetroleo() { return fluxoPetroleo; }

    void getStatus() {
        cout << "Forno a Petróleo trabalhando a " << getTemperatura() << " graus a uma pressão de " << getPressao() << " psi e um fluxo de " << fluxoPetroleo << " l/s" << endl;
    }
};

class FornoLenha : public Forno {
private:
    int qntTroncos;
public:
    FornoLenha(float temperatura, int qntTroncos) : Forno(temperatura) {
        this->qntTroncos = qntTroncos;
    }
    void getStatus() {
        cout << "Forno a Lenha trabalhando a " << getTemperatura() << " graus com " << qntTroncos << " troncos" << endl;
    }
};

int main() {
    Forno* FornoClassico = new Forno(100.0f);
    cout << "Forno Clássico Temperatura Inicial: " << FornoClassico->getTemperatura() << endl;
    FornoClassico->setTemperatura(3000.0f);
    FornoClassico->getStatus();
    delete FornoClassico;

    FornoEletrico* FornoEletrico1 = new FornoEletrico(100.0f, 230);
    FornoEletrico1->getStatus();
    delete FornoEletrico1;

    FornoResistivo* FornoResistivo1 = new FornoResistivo(110.0f, 200, 30);
    FornoResistivo1->getStatus();
    delete FornoResistivo1;

    FornoInducao* FornoInducao1 = new FornoInducao(140.0f, 200, 30.0f);
    FornoInducao1->getStatus();
    delete FornoInducao1;

    FornoGas* FornoGas1 = new FornoGas(230.0f, 23.0f);
    FornoGas1->getStatus();
    delete FornoGas1;

    FornoGasNatural* FornoGasNatural1 = new FornoGasNatural(220.0f, 20.0f, 5.0f);
    FornoGasNatural1->getStatus();
    delete FornoGasNatural1;

    FornoPetroleo* FornoPetroleo1 = new FornoPetroleo(210.0f, 25.0f, 3.0f);
    FornoPetroleo1->getStatus();
    delete FornoPetroleo1;

    FornoLenha* FornoLenha1 = new FornoLenha(250.0f, 500);
    FornoLenha1->getStatus();
    delete FornoLenha1;

    return 0;
}
