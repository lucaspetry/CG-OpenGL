#include "Cavalo.h"

Cavalo::Cavalo() {
}

Cavalo::~Cavalo() {
}

void Cavalo::desenhar(const int estagio, const bool caminhada) {
	this->desenharTronco(estagio, caminhada);
}

void Cavalo::desenharTronco(const int estagio, const bool caminhada) {
	glPushMatrix();

	if(caminhada) {
		glRotatef(35, 1, 0, 0);
		glColor3f(0.0, 1.0, 0);

		glScalef(1.2, 1.1, 2);
		glutSolidCube(1);
	} else {

	}

	glPopMatrix();
}

void Cavalo::desenharPerna(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna) {

}

std::vector<double> Cavalo::obterAngulosMembros(const int estagio, const bool caminhada) const {
	std::vector<double> angulos;

	if(caminhada) {
		for(int i = 0; i < NUMERO_MEMBROS; i++)
			angulos.push_back(this->angulosCaminhada[i][estagio]);
	} else {
		for(int i = 0; i < NUMERO_MEMBROS; i++)
			angulos.push_back(this->angulosTrote[i][estagio]);
	}

	return angulos;
}
