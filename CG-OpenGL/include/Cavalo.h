#ifndef CAVALO_H_
#define CAVALO_H_

#include <GL/glut.h>
#include <vector>

class Cavalo {

public:
	static const int NUMERO_MEMBROS = 16;
	static const int ESTAGIOS_CAMINHADA = 6;
	static const int ESTAGIOS_TROTE = 4;
	static const int ESCALA = 1;

	static constexpr double COMPRIMENTO_TRONCO = 3.2;
	static constexpr double LARGURA_TRONCO = 1;
	static constexpr double LARGURA_NADEGAS = 1.15;

	enum Eixo {
		EIXO_X,
		EIXO_Y,
		EIXO_Z
	};

	enum PosicaoPerna {
		FRONTAL_DIREITA = 3,
		FRONTAL_ESQUERDA = 4,
		TRASEIRA_DIREITA = 5,
		TRASEIRA_ESQUERDA = 6
	};

	enum MembroCorpo {
		CABECA = 0,
		PESCOCO = 1,
		TRONCO = 2,
		ANTEBRACO_FRONTAL_DIREITO = 3,
		ANTEBRACO_FRONTAL_ESQUERDO = 4,
		ANTEBRACO_TRASEIRO_DIREITO = 5,
		ANTEBRACO_TRASEIRO_ESQUERDO = 6,
		CANELA_FRONTAL_DIREITA = 7,
		CANELA_FRONTAL_ESQUERDA = 8,
		CANELA_TRASEIRA_DIREITA = 9,
		CANELA_TRASEIRA_ESQUERDA = 10,
		CASCO_FRONTAL_DIREITO = 11,
		CASCO_FRONTAL_ESQUERDO = 12,
		CASCO_TRASEIRO_DIREITO = 13,
		CASCO_TRASEIRO_ESQUERDO = 14,
		RABO = 15
	};

	Cavalo();
	virtual ~Cavalo();
	void desenhar(const int estagio, const bool caminhada);

private:
	void rotacionarNaOrigem(double angulo, Eixo eixo);
	void desenharTronco(const int estagio, const bool caminhada);
	void desenharPerna(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna);

	const double comprimentoMembros[NUMERO_MEMBROS] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	const double larguraMembros[NUMERO_MEMBROS] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	/**
	 * Angulos de caminhada. Cada ângulo é relativo ao membro anteriormente desenhado.
	 */
	const double angulosCaminhada[NUMERO_MEMBROS][ESTAGIOS_CAMINHADA] = {
			{ 0, 0, 0, 0, 0, 0 }, /* CABEÇA */
			{ 0, 0, 0, 0, 0, 0 }, /* PESCOÇO */
			{ 0, 0, 0, 0, 0, 0 }, /* TRONCO */
			{ -5, 0, 0, 0, 0, 0 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ 7, 0, 0, 0, 0, 0 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ 43, 0, 0, 0, 0, 0 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ 11, 0, 0, 0, 0, 0 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */
			{ 7, 0, 0, 0, 0, 0 }, /* CANELA FRONTAL DIREITA */
			{ 31.5, 0, 0, 0, 0, 0 }, /* CANELA FRONTAL ESQUERDA */
			{ -44, 0, 0, 0, 0, 0 }, /* CANELA TRASEIRA DIREITA */
			{ -40.5, 0, 0, 0, 0, 0 }, /* CANELA TRASEIRA ESQUERDA */
			{ -20, 0, 0, 0, 0, 0 }, /* CASCO FRONTAL DIREITO */
			{ 5, 0, 0, 0, 0, 0 }, /* CASCO FRONTAL ESQUERDO */
			{ -38, 32, 56.5, 50.5, -24, -33 }, /* CASCO TRASEIRO DIREITO */
			{ 35, 0, 0, 0, 0, 0 }, /* CASCO TRASEIRO ESQUERDO */
			{ 0, 0, 0, 0, 0, 0 } /* RABO */
	};

	/**
	 * Angulos de trote. Cada ângulo é relativo ao membro anteriormente desenhado.
	 */
	const double angulosTrote[NUMERO_MEMBROS][ESTAGIOS_TROTE] = {
			{ 0, 0, 0, 0 }, /* CABEÇA */
			{ 0, 0, 0, 0 }, /* PESCOÇO */
			{ 0, 0, 0, 0 }, /* TRONCO */
			{ 0, 0, 0, 0 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ 0, 0, 0, 0 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ 0, 0, 0, 0 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ 0, 0, 0, 0 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */
			{ 0, 0, 0, 0 }, /* CANELA FRONTAL DIREITA */
			{ 0, 0, 0, 0 }, /* CANELA FRONTAL ESQUERDA */
			{ 0, 0, 0, 0 }, /* CANELA TRASEIRA DIREITA */
			{ 0, 0, 0, 0 }, /* CANELA TRASEIRA ESQUERDA */
			{ 0, 0, 0, 0 }, /* CASCO FRONTAL DIREITO */
			{ 0, 0, 0, 0 }, /* CASCO FRONTAL ESQUERDO */
			{ 0, 0, 0, 0 }, /* CASCO TRASEIRO DIREITO */
			{ 0, 0, 0, 0 }, /* CASCO TRASEIRO ESQUERDO */
			{ 0, 0, 0, 0 } /* RABO */
	};

};

#endif /* CAVALO_H_ */
