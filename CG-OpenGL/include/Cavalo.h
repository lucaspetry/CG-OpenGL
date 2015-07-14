#ifndef CAVALO_H_
#define CAVALO_H_

#include <GL/glut.h>
#include <vector>

class Cavalo {

public:
	static const int NUMERO_MEMBROS = 16;
	static const int ESTAGIOS_CAMINHADA = 7;
	static const int ESTAGIOS_TROTE = 4;

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
	void desenharTronco(const int estagio, const bool caminhada);
	void desenharAntebraco(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna);
	void desenharCanela(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna);
	void desenharCasco(const int estagio, const bool caminhada, const Cavalo::PosicaoPerna perna);

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
			{ 0, 0, 0, 0, 0, 0, 0 }, /* CABEÇA */
			{ 0, 0, 0, 0, 0, 0, 0 }, /* PESCOÇO */
			{ 0, 0, 0, 0, 0, 0, 0 }, /* TRONCO */

			{ 2, -5, -16, -3, 15, 33, 40 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ -5, 27, 35, 6, 2, -2, -14 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ -27, -35, -33, -10, -7.5, -5, -16 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ -1, -11, -21, -30, -35, -40, -35 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */

			{ 3, 0, 0, -30, -49, -68, -40 }, /* CANELA FRONTAL DIREITA */
			{ -27, -76, -34, 1, 0.5, 0, 1 }, /* CANELA FRONTAL ESQUERDA */
			{ 38, 41, 55, 59, 46, 33, 27 }, /* CANELA TRASEIRA DIREITA */
			{ 47, 40, 33, 35, 39, 43, 80 }, /* CANELA TRASEIRA ESQUERDA */

			{ 32, 42, 35, -3, -13, -23, -3 }, /* CASCO FRONTAL DIREITO */
			{ -3, -3, 1, 32, 35, 38, 41 }, /* CASCO FRONTAL ESQUERDO */
			{ 35, -35, -59, -54, -18, 21, 38 }, /* CASCO TRASEIRO DIREITO */
			{ -46, 13, 0, 28, -1, -30, -80 }, /* CASCO TRASEIRO ESQUERDO */

			{ 0, 0, 0, 0, 0, 0, 0 } /* RABO */
	};

	/**
	 * Angulos de trote. Cada ângulo é relativo ao membro anteriormente desenhado.
	 */
	const double angulosTrote[NUMERO_MEMBROS][ESTAGIOS_TROTE] = {
			{ 0, 0, 0, 0 }, /* CABEÇA */
			{ 0, 0, 0, 0 }, /* PESCOÇO */
			{ 0, 0, 0, 0 }, /* TRONCO */

			{ -10, 23, 61, 47 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ 56, 47, -20, 39 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ -27, -62, -49, -56 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ -51, 4, -28, -2 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */

			{ -3, -80, -54, 0 }, /* CANELA FRONTAL DIREITA */
			{ -57, -4, 1, -87 }, /* CANELA FRONTAL ESQUERDA */
			{ 75, 41, 53, 77 }, /* CANELA TRASEIRA DIREITA */
			{ 44, 67, 85, 51 }, /* CANELA TRASEIRA ESQUERDA */

			{ 44, -5, -40, -2 }, /* CASCO FRONTAL DIREITO */
			{ -21, -2, 48, -3 }, /* CASCO FRONTAL ESQUERDO */
			{ -31, -5, 32, -45 }, /* CASCO TRASEIRO DIREITO */
			{ 47, -35, -71, -7 }, /* CASCO TRASEIRO ESQUERDO */

			{ 0, 0, 0, 0 } /* RABO */
	};

};

#endif /* CAVALO_H_ */
