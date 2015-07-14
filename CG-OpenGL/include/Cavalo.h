#ifndef CAVALO_H_
#define CAVALO_H_

#include <GL/glut.h>
#include <vector>

class Cavalo {

public:
	static const int NUMERO_MEMBROS = 16;
	static const int ESTAGIOS_CAMINHADA = 6;
	static const int ESTAGIOS_TROTE = 12;

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
		0.09, 0.05, 0.02, 0.09, 0.05, 0.02, /*0.08, 0.05, 0.03, 0.03, 0.02, 0, 0.03*/
	};

	const double alturaTroncoTrote[ESTAGIOS_TROTE] = {
		0, 0.1, 0.35, 0.5, 0.35, 0.1, 0, 0.1, 0.35, 0.5, 0.35, 0.1
	};

	/**
	 * Angulos de caminhada. Cada �ngulo � relativo ao membro anteriormente desenhado.
	 */
	const double angulosCaminhada[NUMERO_MEMBROS][ESTAGIOS_CAMINHADA] = {
			{ 90, 90, 90, 90, 90, 90 }, /* CABE�A */
			{ 45, 45, 45, 45, 45, 45 }, /* PESCO�O */
			{ 0, 0, 0, 0, 0, 0 }, /* TRONCO */

			{ 4, -4, -15, -4, 20, 37 }, /* ANTEBRA�O FRONTAL DIREITO */
			{ -4, 20, 37, 4, -4, -15 }, /* ANTEBRA�O FRONTAL ESQUERDO */
			{ -28, -37, -34, -6, -8, -18 }, /* ANTEBRA�O TRASEIRO DIREITO */
			{ -6, -8, -18, -28, -37, -34 }, /* ANTEBRA�O TRASEIRO ESQUERDO */

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
	 * Angulos de trote. Cada �ngulo � relativo ao membro anteriormente desenhado.
	 */
	const double angulosTrote[NUMERO_MEMBROS][ESTAGIOS_TROTE] = {
			{ 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70 }, /* CABE�A */
			{ 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55 }, /* PESCO�O */
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, /* TRONCO */

			{ -10, 1, 12, 23, 35.6, 48.2, 61, 55.5, 51, 47, 28, 9 }, /* ANTEBRA�O FRONTAL DIREITO */
			{ 56, 53, 50, 47, 24.5, 2, -20, 0.5, 20, 39, 45, 50.5 }, /* ANTEBRA�O FRONTAL ESQUERDO */
			{ -27, -38.6, -50.2, -62, -57.5, -53, -49, -51, -53.5, -56, -45.2, -36.6 }, /* ANTEBRA�O TRASEIRO DIREITO */
			{ -51, -32, -14.5, 4, -6.5, -17.5, -28, -19, -10.5, -2, -18.3, -35 }, /* ANTEBRA�O TRASEIRO ESQUERDO */

			{ -3, -28.5, -54.5, -80, -71.5, -62.5, -54, -36, -18, 0, 0, -3 }, /* CANELA FRONTAL DIREITA */
			{ -57, -39, -21.5, -4, -3, -0.5, 1, -28, -57.5, -87, -77, -67 }, /* CANELA FRONTAL ESQUERDA */
			{ 75, 63.5, 52.5, 41, 45, 49, 53, 61, 69, 77, 76.5, 75.5 }, /* CANELA TRASEIRA DIREITA */
			{ 44, 51.5, 59.5, 67, 73, 79, 85, 68.5, 59.5, 51, 49, 46.5 }, /* CANELA TRASEIRA ESQUERDA */

			{ 44, 360, 360, -5, 360, 360, -40, 360, 360, -2, 360, 360 }, /* CASCO FRONTAL DIREITO */
			{ -21, 360, 360, -2, 360, 360, 48, 360, 360, -3, 360, 360 }, /* CASCO FRONTAL ESQUERDO */
			{ -31, 360, 360, -5, 360, 360, 32, 360, 360, -45, 360, 360 }, /* CASCO TRASEIRO DIREITO */
			{ 47, 360, 360, -35, 360, 360, -71, 360, 360, -7, 360, 360 }, /* CASCO TRASEIRO ESQUERDO */

			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } /* RABO */
	};

};

#endif /* CAVALO_H_ */
