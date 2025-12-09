#include <iostream>
#include <string>
using namespace std;

class Cliente {
private: 
    string nome;
    string cpf; 

public:
    Cliente(string nome, string cpf) {
        this->nome = nome;
        this->cpf = cpf;
    }
    string getNome() const {
        return nome;
    }

    string getCpf() const {
        return cpf;
    }
};
class ContaBancaria {
private: 
    int numeroConta;
    Cliente titular;
    double saldo;

public: 
    ContaBancaria(int numeroConta, Cliente titular, double saldoInicial = 0.0)
        : numeroConta(numeroConta), titular(titular), saldo(saldoInicial) {}
    void depositar(double valor) {
        if (valor > 0)
            saldo += valor;
        else
            cout << "Valor de deposito invalido." << endl;
    }
    void sacar(double valor) {
        if (valor <= 0)
            cout << "Valor de saque invalido." << endl;
        else if (saldo >= valor)
            saldo -= valor;
        else 
            cout << "Saldo insuficiente." << endl;
    }

    void transferir(double valor, ContaBancaria &destino) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino.depositar(valor);
        } else {
            cout << "Transferencia nao realizada: saldo insuficiente." << endl;
        }
    }

    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        double metade = valor / 2.0;
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
        } else {
            cout << "Transferencia nao realizada: saldo insuficiente." << endl;
        }
    }

    void exibirSaldo() const {
        cout << "Conta " << numeroConta << " - Saldo atual: R$ " << saldo << endl;
    }
    void exibirInformacoes() const {
        cout << "Conta: " << numeroConta 
             << " | Titular: " << titular.getNome()
             << " | CPF: " << titular.getCpf()
             << " | Saldo: R$ " << saldo << endl;
    }
};

int main() {
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    conta1.exibirSaldo();

    conta1.transferir(200.0, conta2);
    conta1.transferir(300.0, conta2, conta3);

    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
