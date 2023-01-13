#include "Aluno.h"

Aluno::Aluno(string nome, string cpf, int RA, double nota_prova1, double nota_prova2, double nota_trabalho) : Pessoa(nome, cpf), RA(RA), nota_prova1(nota_prova1), nota_prova2(nota_prova2), nota_trabalho(nota_trabalho) {}

int Aluno::getRA() const{
	return this->RA;
}

double Aluno::media() const{
	return (this->peso_provas * (this->nota_prova1 + this->nota_prova2) + this->peso_trabalho * this->nota_trabalho) / (2 * this->peso_provas + this->peso_trabalho);
}

bool Aluno::aprovado() const{
	return this->media() >= this->media_aprovativa;
}

bool Aluno::sac() const{
	return !this->aprovado() && this->media() >= this->minimo_para_sac;
}

double Aluno::notaSAC() const{
	if (!this->sac()) return 0;

	return 2 * this->media_aprovativa - this->media();
}

void Aluno::imprime() const{
	Pessoa::imprime();
	cout << "RA: " << this->getRA() << endl;
	cout << "Media Final: " << this->media() << endl;
}