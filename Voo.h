#pragma once
#include "DataHorario.h";
#include "Pessoa.h";

class Voo
{
public:
	Voo(int, DataHorario&);
	int proximoLivre() const;
	bool verifica(int) const;
	bool ocupa(int, Pessoa&);
	bool desocupa(int);
	int vagas() const;
	int getNumeroDoVoo() const;
	DataHorario getData() const;
	void setNumeroDoVoo(int novo_numero);
	void setData(DataHorario&);
	void imprime() const;

private:
	int numero_do_voo;
	DataHorario& data;
	Pessoa* assentos[100];
	int quantidade_de_passageiros;

	const int total_assentos = 100;
};

