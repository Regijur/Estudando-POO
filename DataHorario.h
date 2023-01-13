#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class DataHorario
{
public:
	DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo);
	~DataHorario();
	int compare(DataHorario&) const;
	int getDia() const; 
	int getMes() const; 
	int getAno() const; 
	int getHora() const; 
	int getMinuto() const; 
	int getSegundo() const; 
	void imprime(bool usar_AMPM) const;
	void imprimePorExtenso() const;
private:
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
	int segundo;
};

