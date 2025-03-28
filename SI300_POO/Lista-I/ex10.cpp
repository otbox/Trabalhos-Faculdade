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
    virtual ~Forno() {}

    virtual void getStatus() {
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

    void getStatus() {
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

    void getStatus() override {
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

    void getStatus() override {
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

    void getStatus() override {
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

    void getStatus() override {
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

    void getStatus() override {
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
    void getStatus() override {
        cout << "Forno a Lenha trabalhando a " << getTemperatura() << " graus com " << qntTroncos << " troncos" << endl;
    }
};

int main() {
    // vector<Forno*> Fornos;
    // cout << "Forno Clássico Temperatura Inicial: " ;

    // Forno* FornoClassico = new Forno(100.0f);
    // Fornos.push_back(FornoClassico);

    // FornoEletrico* FornoEletrico1 = new FornoEletrico(100.0f, 230);
    // FornoEletrico1->getStatus(); 
    // Fornos.push_back(FornoEletrico1);
    
    // FornoResistivo* FornoResistivo1 = new FornoResistivo(110.0f, 200, 30);
    // Fornos.push_back(FornoResistivo1);
    // Fornos.push_back(FornoResistivo1);
    
    // FornoInducao* FornoInducao1 = new FornoInducao(140.0f, 200, 30.0f);
    // Fornos.push_back(FornoInducao1);
    // FornoGas* FornoGas1 = new FornoGas(230.0f, 23.0f);
    // Fornos.push_back(FornoGas1);
    
    // FornoGasNatural* FornoGasNatural1 = new FornoGasNatural(220.0f, 20.0f, 5.0f);
    // Fornos.push_back(FornoGasNatural1);
    
    // FornoPetroleo* FornoPetroleo1 = new FornoPetroleo(210.0f, 25.0f, 3.0f);
    // Fornos.push_back(FornoPetroleo1);
    
    // FornoLenha* FornoLenha1 = new FornoLenha(250.0f, 500);
    // Fornos.push_back(FornoLenha1);

    // for (Forno * forno : Fornos){
    //     forno->getStatus();
    // }
    // for (Forno * forno : Fornos){
    //     delete forno;
    // }

    Forno* fornos[8];
    fornos[0] = new Forno(100.0f);
    fornos[1] = new FornoEletrico(120.0f, 250);
    fornos[2] = new FornoResistivo(150.0f, 300, 50);
    fornos[3] = new FornoInducao(180.0f, 350, 15.5f);
    fornos[4] = new FornoGas(200.0f, 20.0f);
    fornos[5] = new FornoGasNatural(220.0f, 18.0f, 2.5f);
    fornos[6] = new FornoPetroleo(250.0f, 22.0f, 3.0f);
    fornos[7] = new FornoLenha(200.0f, 100);
    
    




    for (Forno * forno : fornos){
        forno->getStatus();
    }
    for (Forno * forno : fornos){
        delete forno;
    }

    return 0;
}
