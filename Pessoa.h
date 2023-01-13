#pragma once
#include <iostream>

using namespace std;

class Pessoa
{
public:
	Pessoa(string nome, string cpf);
	string getCPF() const;
	string getNome() const;
	void imprime() const;

private:
	string nome;
	string cpf;
};

