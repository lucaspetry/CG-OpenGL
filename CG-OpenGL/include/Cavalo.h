#ifndef CAVALO_H_
#define CAVALO_H_

#include <GL/glut.h>

class Cavalo {

public:
	static const int NUMERO_MEMBROS = 16;
	static const int ESTAGIOS_CAMINHADA = 6;
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

	const double alturaTroncoCaminhada[ESTAGIOS_CAMINHADA] = {
		0.09, 0.05, 0.02, 0.09, 0.05, 0.02/*, 0.08, 0.05, 0.03, 0.03, 0.02, 0, 0.03*/
	};

	const double alturaTroncoTrote[ESTAGIOS_TROTE] = {
		0, 0.1, 0, 0.1/*, 0.35, 0.1, 0, 0.1, 0.35, 0.5, 0.35, 0.1*/
	};

	/**
	 * Angulos de caminhada. Cada ângulo é relativo ao membro anteriormente desenhado.
	 */
	const double angulosCaminhada[NUMERO_MEMBROS][ESTAGIOS_CAMINHADA] = {
			{ 90, 90, 90, 90, 90, 90 }, /* CABEÇA */
			{ 45, 45, 45, 45, 45, 45 }, /* PESCOÇO */
			{ 0, 0, 0, 0, 0, 0 }, /* TRONCO */

			{ 4, -4, -15, -4, 20, 37 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ -4, 20, 37, 4, -4, -15 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ -28, -37, -34, -6, -8, -18 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ -6, -8, -18, -28, -37, -34 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */

			{ 2, 0, 0, -28, -71, -37 }, /* CANELA FRONTAL DIREITA */
			{ -28, -71, -37, 2, 0, 0 }, /* CANELA FRONTAL ESQUERDA */
			{ 36, 42, 67, 53, 37, 30 }, /* CANELA TRASEIRA DIREITA */
			{ 53, 37, 30, 36, 42, 67 }, /* CANELA TRASEIRA ESQUERDA */

			{ 32, 40, 38, -3, -13, -1 }, /* CASCO FRONTAL DIREITO */
			{ -3, -13, -1, 32, 40, 38 }, /* CASCO FRONTAL ESQUERDO */
			{ 32, -32, -69, -50, 17, 19 }, /* CASCO TRASEIRO DIREITO */
			{ -50, 17, 19, 32, -32, -69 }, /* CASCO TRASEIRO ESQUERDO */

			{ 0, 0, 0, 0, 0, 0 } /* RABO */
	};

	/**
	 * Angulos de trote. Cada ângulo é relativo ao membro anteriormente desenhado.
	 */
	const double angulosTrote[NUMERO_MEMBROS][ESTAGIOS_TROTE] = {
			{ 70, 70, 70, 70 }, /* CABEÇA */
			{ 55, 55, 55, 55 }, /* PESCOÇO */
			{ 0, 0, 0, 0 }, /* TRONCO */

			{ -15, 20, 48, 22 }, /* ANTEBRAÇO FRONTAL DIREITO */
			{ 48, 22, -15, 20 }, /* ANTEBRAÇO FRONTAL ESQUERDO */
			{ -28, -2, -30, -56 }, /* ANTEBRAÇO TRASEIRO DIREITO */
			{ -30, -56, -28, -2 }, /* ANTEBRAÇO TRASEIRO ESQUERDO */

			{ -1, -63, -55, -2 }, /* CANELA FRONTAL DIREITA */
			{ -55, -2, -1, -63 }, /* CANELA FRONTAL ESQUERDA */
			{ 80, 46, 49, 72 }, /* CANELA TRASEIRA DIREITA */
			{ 49, 72, 80, 46 }, /* CANELA TRASEIRA ESQUERDA */

			{ 46, -4, -30, -2 }, /* CASCO FRONTAL DIREITO */
			{ -30, -2, 46, -4 }, /* CASCO FRONTAL ESQUERDO */
			{ -51, -6, 40, -40 }, /* CASCO TRASEIRO DIREITO */
			{ 40, -40, -51, -6 }, /* CASCO TRASEIRO ESQUERDO */

			{ 0, 0, 0, 0 } /* RABO */
	};

};

#endif /* CAVALO_H_ */
