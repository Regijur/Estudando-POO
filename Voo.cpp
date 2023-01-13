#include "Voo.h"

Voo::Voo(int numero_do_voo, DataHorario& data):numero_do_voo(numero_do_voo),data(data) {
	this->quantidade_de_passageiros = 0;
	for (int i = 1; i <= 100; i++) {
		this->desocupa(i);
	}
}

int Voo::proximoLivre() const{
	if (this->vagas() == 0) return 0;
	for (int i = 1; i <= 100; i++) {
		if (!this->verifica(i)) return i;
	}
}

bool Voo::verifica(int assento) const{
	return this->assentos[assento - 1] != NULL;
}

bool Voo::ocupa(int assento, Pessoa& passageiro){
	if (this->verifica(assento) || assento < 1 || assento > 100) return false;

	this->assentos[assento - 1] = &passageiro;
	this->quantidade_de_passageiros++;
	return true;
}

bool Voo::desocupa(int assento){
	if (!this->verifica(assento) || assento < 1 || assento > this->total_assentos)  {
		return false;
	}
	if(this->quantidade_de_passageiros > 0) this->quantidade_de_passageiros--;
	this->assentos[assento - 1] = NULL;
	return true;
}

int Voo::vagas() const{
	return this->total_assentos - this->quantidade_de_passageiros;
}

int Voo::getNumeroDoVoo() const{
	return this->numero_do_voo;
}

DataHorario Voo::getData() const{
	return this->data;
}

void Voo::setNumeroDoVoo(int novo_numero){
	this->numero_do_voo = novo_numero;
}

void Voo::setData(DataHorario& data){
	this->data = data;
}

void Voo::imprime() const{
	cout << "Numero do Voo: " << this->numero_do_voo << endl;
	cout << "Data e Horario do Voo: ";
	this->data.imprime(false);
	cout << "Vagas disponiveis: " << this->vagas() << endl;

	if (this->vagas() == 100) {
		cout << "Nao ha passageiros nesse voo" << endl;
	}
	else {
		cout << "Passageiros:" << endl << endl;
	
		int impressoes = 0;
		int i = 1;
		while (impressoes < 100 - this->vagas() && i <= 100) {
			if (this->verifica(i)) {
				this->assentos[i - 1]->imprime();
				cout << endl;
				impressoes++;
			}
			i++;
		}
	}
}
