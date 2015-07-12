#include "Cavalo.h"
#include <iostream>

Cavalo::Cavalo() {
}

Cavalo::~Cavalo() {
}

void Cavalo::rotacionarNaOrigem(double angulo, Cavalo::Eixo eixo) {
	GLdouble matriz[16];
	glGetDoublev(GL_MODELVIEW_MATRIX, matriz);
	glLoadIdentity();

	switch(eixo) {
		case EIXO_X:
			glRotatef(angulo, 1, 0, 0);
			break;
		case EIXO_Y:
			glRotatef(angulo, 0, 1, 0);
			break;
		default:
			glRotatef(angulo, 0, 0, 1);
			break;
	}

	GLdouble matrizRot[16];
	glGetDoublev(GL_MODELVIEW_MATRIX, matrizRot);

	glMultMatrixd(matriz);
}

void Cavalo::desenhar(const int estagio, const bool caminhada) {
	this->desenharTronco(estagio, caminhada);
}

void Cavalo::desenharTronco(const int estagio, const bool caminhada) {
	glPushMatrix();
	glColor3f(0.72f, 0.65f, 0.13f);

	double metadeTronco = COMPRIMENTO_TRONCO/(double) 2;
	double metadeNadegas = LARGURA_NADEGAS/(double) 2;

	glRotatef(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92, LARGURA_TRONCO * 1.07, metadeTronco, 10, 10);
	glRotatef(-180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92, LARGURA_TRONCO * 1.07, metadeTronco, 10, 10);
	glRotatef(90, 0, 1, 0);

	glTranslatef(-metadeTronco * 0.95, 0, 0);
	glScalef(1.5, 1.2, LARGURA_NADEGAS);
	glutSolidSphere(1, 10, 10);

	glTranslatef(0, 0, -metadeNadegas * 0.9);
	this->desenharPerna(estagio, caminhada, PosicaoPerna::TRASEIRA_ESQUERDA);
	glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
	this->desenharPerna(estagio, caminhada, PosicaoPerna::TRASEIRA_DIREITA);

	glTranslatef(COMPRIMENTO_TRONCO * 0.8, 0, -metadeNadegas * 0.9);
	glScalef(1.2, 1.1, LARGURA_NADEGAS);
	glutSolidSphere(1, 10, 10);

	glTranslatef(0, 0, -metadeNadegas * 0.9);
	this->desenharPerna(estagio, caminhada, PosicaoPerna::FRONTAL_ESQUERDA);
	glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
	this->desenharPerna(estagio, caminhada, PosicaoPerna::FRONTAL_DIREITA);
	glTranslatef(0, 0, -metadeNadegas * 0.9);
	// Desenhar pescoço e cabeça

	glPopMatrix();
}

void Cavalo::desenharPerna(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna) {
	glPushMatrix();

	glPopMatrix();
}
