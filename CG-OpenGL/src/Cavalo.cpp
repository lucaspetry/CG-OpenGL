#include "Cavalo.h"
#include <iostream>

Cavalo::Cavalo() {
}

Cavalo::~Cavalo() {
}

void Cavalo::desenhar(const int estagio, const bool caminhada) {
	this->desenharTronco(estagio, caminhada);
}

void Cavalo::desenharTronco(const int estagio, const bool caminhada) {
	glPushMatrix();
	glColor3f(0.72f, 0.65f, 0.13f);

	double alturaTronco = 0;
	double metadeTronco = COMPRIMENTO_TRONCO/(double) 2;
	double metadeNadegas = LARGURA_NADEGAS/(double) 2;

	if(caminhada)
		alturaTronco = this->alturaTroncoCaminhada[estagio];
	else
		alturaTronco = this->alturaTroncoTrote[estagio];

	glTranslatef(0, alturaTronco, 0);

	glRotatef(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92, LARGURA_TRONCO * 1, metadeTronco, 30, 30); // Parte frontal
	glRotatef(-180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92, LARGURA_TRONCO * 1.07, metadeTronco, 30, 30); // Parte traseira
	glRotatef(90, 0, 1, 0);

	glTranslatef(-metadeTronco * 0.95, 0, 0);
	glScalef(1.5, 1.2, LARGURA_NADEGAS);
	glutSolidSphere(1, 20, 20); // Nádegas

	glPushMatrix();
	// Desenhar rabo
	glPopMatrix();

	glTranslatef(0, -alturaTronco, 0);

	glTranslatef(0, 0, -metadeNadegas * 0.9);
	this->desenharAntebraco(estagio, caminhada, PosicaoPerna::TRASEIRA_ESQUERDA);
	glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
	this->desenharAntebraco(estagio, caminhada, PosicaoPerna::TRASEIRA_DIREITA);

	glTranslatef(0, alturaTronco, 0);
	glTranslatef(COMPRIMENTO_TRONCO * 0.8, 0, -metadeNadegas * 0.9);
	glScalef(1.2, 1, LARGURA_NADEGAS);
	glutSolidSphere(1, 20, 20); // Peitoral
	glTranslatef(0, -alturaTronco, 0);

	glTranslatef(0, 0, -metadeNadegas * 0.9);
	this->desenharAntebraco(estagio, caminhada, PosicaoPerna::FRONTAL_ESQUERDA);
	glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
	this->desenharAntebraco(estagio, caminhada, PosicaoPerna::FRONTAL_DIREITA);
	glTranslatef(0, 0, -metadeNadegas * 0.9);

	glTranslatef(0, alturaTronco, 0);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);

	if(caminhada)
		glRotatef(this->angulosCaminhada[PESCOCO][estagio], 0, 1, 0);
	else
		glRotatef(this->angulosTrote[PESCOCO][estagio], 0, 1, 0);

	gluCylinder(gluNewQuadric(), 0.7, 0.25, 2, 30, 30); // Pescoço
	glTranslatef(0, 0, 2);

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glutSolidCone(0.3, 1, 20, 20);

	glRotatef(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), 0.5, 0.18, 1.5, 30, 30); // Cabeça
	glPopMatrix();

	glPopMatrix();
}

void Cavalo::desenharAntebraco(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna) {
	glPushMatrix();

	if(caminhada)
		glRotatef(this->angulosCaminhada[perna][estagio], 0, 0, 1);
	else
		glRotatef(this->angulosTrote[perna][estagio], 0, 0, 1);

	glRotatef(90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 0.35, 0.17, 1.4, 30, 30);
	glTranslatef(0, 0, 1.4);

	glPushMatrix();
	glScalef(0.17, 0.17, 0.17);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	this->desenharCanela(estagio, caminhada, perna);
	glPopMatrix();
}

void Cavalo::desenharCanela(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna) {
	glPushMatrix();

	if(caminhada)
		glRotatef(this->angulosCaminhada[perna + 4][estagio], 0, 1, 0);
	else
		glRotatef(this->angulosTrote[perna + 4][estagio], 0, 1, 0);

	gluCylinder(gluNewQuadric(), 0.13, 0.08, 1, 30, 30);
	glTranslatef(0, 0, 1);

	glPushMatrix();
	glScalef(0.08, 0.08, 0.08);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	this->desenharCasco(estagio, caminhada, perna);
	glPopMatrix();
}

void Cavalo::desenharCasco(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna) {
	glPushMatrix();

	if(caminhada)
		glRotatef(this->angulosCaminhada[perna + 8][estagio], 0, 1, 0);
	else
		glRotatef(this->angulosTrote[perna + 8][estagio], 0, 1, 0);

	gluCylinder(gluNewQuadric(), 0.06, 0.06, 0.2, 30, 30);
	glTranslatef(0, 0, 0.2);

	glPushMatrix();
	glScalef(0.05, 0.05, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}
