#include "Pessoa.h"

Pessoa::Pessoa(string nome, string cpf) :nome(nome), cpf(cpf) {};

string Pessoa::getCPF() const {
	return this->cpf;
}

string Pessoa::getNome() const {
	return this->nome;
}

void Pessoa::imprime() const {
	cout << "Nome: " << this->getNome() << endl;
	cout << "CPF: " << this->getCPF() << endl;
}