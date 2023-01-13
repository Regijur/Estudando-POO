#pragma once
#include "Pessoa.h"

class Aluno : public Pessoa
{
public:
	Aluno(string nome, string cpf, int RA, double nota_prova1, double nota_prova2, double nota_trabalho);
	int getRA() const;
	double media() const; 
	bool aprovado() const;
	bool sac() const;
	double notaSAC() const;
	void imprime() const;

private:
	int RA;
	double nota_prova1;
	double nota_prova2;
	double nota_trabalho;

	const int peso_provas = 7;
	const int peso_trabalho = 6;
	const double media_aprovativa = 6;
	const double minimo_para_sac = 5;
};

