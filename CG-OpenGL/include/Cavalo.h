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

	enum PosicaoPerna {
		FRONTAL_DIREITA,
		FRONTAL_ESQUERDA,
		TRASEIRA_DIREITA,
		TRASEIRA_ESQUERDA
	};

	enum MembroCorpo {
		CABECA,
		PESCOCO,
		TRONCO,
		ANTEBRACO_FRONTAL_DIREITO,
		ANTEBRACO_FRONTAL_ESQUERDO,
		ANTEBRACO_TRASEIRO_DIREITO,
		ANTEBRACO_TRASEIRO_ESQUERDO,
		CANELA_FRONTAL_DIREITA,
		CANELA_FRONTAL_ESQUERDA,
		CANELA_TRASEIRA_DIREITA,
		CANELA_TRASEIRA_ESQUERDA,
		CASCO_FRONTAL_DIREITO,
		CASCO_FRONTAL_ESQUERDO,
		CASCO_TRASEIRO_DIREITO,
		CASCO_TRASEIRO_ESQUERDO,
		RABO
	};

	Cavalo();
	virtual ~Cavalo();
	void desenhar(const int estagio, const bool caminhada);
	std::vector<double> obterAngulosMembros(const int estagio, const bool caminhada) const;

private:
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
