#include "DataHorario.h"

DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo){
	bool erro = false;
	this->dia = 1;
	this->mes = 1;
	this->ano = 1;
	this->hora = 0;
	this->minuto = 0;
	this->segundo = 0;
	if (ano >= 0) {
		this->ano = ano;
		if (mes > 0 && mes <= 12) {
			this->mes = mes;
			switch (mes)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (dia > 0 && dia < 32) {
					this->dia = dia;
				}
				else erro = true;
			case 4:
			case 6:
			case 9:
			case 11:
				if (dia > 0 && dia < 31) {
					this->dia = dia;
				}
				else erro = true;
			case 2:
				if (ano % 4 == 0 && ano % 100 != 4 || ano % 400 == 0) {
					if (dia > 0 && dia < 30) {
						this->dia = dia;
					}
					else erro = true;
				}
				else {
					if (dia > 0 && dia < 29) {
						this->dia = dia;
					}
					else erro = true;
				}
			default:
				erro = true;
				break;
			}
		}
		else erro = true;
	}
	else erro = true;

	
	if (segundo >= 0 && segundo < 60) {
		this->segundo = segundo;
		if (minuto >= 0 && minuto < 60) {
			this->minuto = minuto;

			if (hora >= 0 && hora < 24) {
				this->hora = hora;
			}
			else erro = true;
		}
		else erro = true;
	}
	else erro = true;
	
	if (!erro) {
		this->dia = 1;
		this->mes = 1;
		this->ano = 1;
		this->hora = 0;
		this->minuto = 0;
		this->segundo = 0;
	}
}

DataHorario::~DataHorario(){
}

int DataHorario::compare(DataHorario& data) const{
	int outra_data = data.dia + 100 * data.mes + 10000 * data.ano;
	int esta_data = this->dia + 100 * this->mes + 10000 * this->ano;

	if (outra_data == esta_data) {
		
		int este_horario = this->segundo + 100 * this->minuto + 10000 * this->hora;
		int outro_horario = data.segundo + 100 * data.minuto + 10000 * data.hora;
		
		if (outro_horario == este_horario) {
			return 0;
		}
		else {
			if (outro_horario > este_horario) return -1;
			else return 1;
		}
	}
	else {
		if (outra_data > esta_data) return -1;
		else return 1;
	}
}

int DataHorario::getDia() const{
	return this->dia;
}

int DataHorario::getMes() const{
	return this->mes;
}

int DataHorario::getAno() const {
	return this->ano;
}

int DataHorario::getHora() const {
	return this->hora;
}

int DataHorario::getMinuto() const {
	return this->minuto;
}

int DataHorario::getSegundo() const {
	return this->segundo;
}

void DataHorario::imprime(bool usar_AMPM) const {
	bool isAM = true;
	
	cout << setfill('0') << setw(2);
	cout << this->dia << '/';
	cout << setfill('0') << setw(2);
	cout << this->mes << '/';
	cout << setfill('0') << setw(4);
	cout << this->ano << ' ';
	cout << setfill('0') << setw(2);
	
	if (usar_AMPM) {
		int hora_ampm = this->hora;
		if (hora_ampm >= 12) {
			hora_ampm -= 12;
			isAM = false;
		}
		cout << hora_ampm << ':';
	}
	else {
		cout << this->hora << ':';
	}

	cout << setfill('0') << setw(2);
	cout << this->minuto << ':';
	cout << setfill('0') << setw(2);
	cout << this->segundo;

	if (usar_AMPM) {
		if (isAM) cout << ' AM' << endl;
		else cout << ' PM' << endl;
	}
	else cout << endl;
}

void DataHorario::imprimePorExtenso() const {
	string nomes_meses[12] = { "Janeiro", "Fevereiro", "Marco", "Abril", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };
	
	cout << this->dia << " de ";
	cout << nomes_meses[this->mes - 1] << " de ";
	cout << this->ano << " - ";
	cout << this->hora << " hora";
	if (this->hora > 1) cout << 's';
	cout << ", " << this->minuto << " minuto";
	if (this->minuto > 1) cout << 's';
	cout << " e " << this->segundo << " segundo";
	if (this->segundo > 1) cout << 's';
	cout << endl;
}
