#ifndef OPENGL_H_
#define OPENGL_H_

#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "Cavalo.h"

/*===================== Teclas =====================*/
const unsigned char TECLA_CIMA = GLUT_KEY_UP;
const unsigned char TECLA_BAIXO = GLUT_KEY_DOWN;
const unsigned char TECLA_ESQUERDA = GLUT_KEY_LEFT;
const unsigned char TECLA_DIREITA = GLUT_KEY_RIGHT;
const unsigned char TECLA_ESC = 27;
const unsigned char TECLA_F2 = GLUT_KEY_F2;
const unsigned char TECLA_F3 = GLUT_KEY_F3;
/*==================================================*/

/*============== Atributos da Janela ===============*/
int janela;
bool telaCheia = false;
unsigned int larguraJanela = 800;
unsigned int alturaJanela = 600;
/*==================================================*/

/*======== Configuração da Luz e Material ==========*/
GLfloat luzDifusa[] = {0.5f, 0.5f, 0.5f, 1.0};
GLfloat luzAmbiente[] = {0.5f, 0.5f, 0.5f, 0.7};
GLfloat posicaoLuz[] = {300.0f, 300.0f, 300.0f, 0.0f};
GLfloat matSpec[] = {0.8f, 0.2f, 0.2f, 1.0};
GLfloat	matDiff[] = {0.8f, 0.2f, 0.2f, 1.0};
GLfloat	matShin[] = {10.0f};
/*==================================================*/

/*============ Configuração do Modelo ==============*/
bool modoCaminhada = true;
double quantidadeDeslocamento = 0.3;
double deslocar = 0;
double anguloModelo = 0;
GLfloat posicaoModelo[3] = {0, -2, -8};
int estagioModelo = 0;
int numeroEstagios = Cavalo::ESTAGIOS_CAMINHADA;
/*==================================================*/

/**
 * Desenhar o chão.
 */
void desenharChao() {
	glPushMatrix();
	glColor3f(0.29f, 0.6f, 0.0f);
	glTranslatef(0,-190, -550);
	glRotatef(90, 1.0, 0.0,0.0);
	glRectf(-10000, -10000, 10000, 10000);
	glPopMatrix();
}

/**
 * Redesenhar o mundo.
 */
void redesenharMundo() {
	// Limpar a janela
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzDifusa);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShin);

	desenharChao();

	posicaoModelo[0] +=  cos(anguloModelo) * deslocar;
	posicaoModelo[2] +=  sin(anguloModelo) * deslocar;

	glTranslatef(posicaoModelo[0], posicaoModelo[1], posicaoModelo[2]);
	glRotatef(anguloModelo, 0.0f, 1.0f, 0.0f);

	deslocar = 0;

	Cavalo cavalo;
	cavalo.desenhar(estagioModelo, modoCaminhada);

	// Trocar o buffer da memória para ser desenhado
	glutSwapBuffers();
	usleep(150000);
	estagioModelo++;
	estagioModelo = estagioModelo % numeroEstagios;
}

/**
 * Mostrar mundo (Idle function - quando nada está sendo feito).
 */
void mostrarMundo() {
	redesenharMundo();
}

/**
 * Redimensionar a janela.
 */
void redimensionarJanela(int largura, int altura) {
    larguraJanela  = largura;
    alturaJanela = altura;

    // Reiniciar a Viewport
    glViewport(0, 0, larguraJanela, alturaJanela);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, (float)larguraJanela / (float)alturaJanela, 1.0, 5000.0);

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
 * Tecla comum pressionada.
 */
void tecla(unsigned char tecla, int x, int y) {
	switch(tecla) {
		case TECLA_ESC:
			glutDestroyWindow(janela);
			exit(0);
			break;
		default:
			break;
	}
}

/**
 * Tecla especial pressionada.
 */
void teclaEspecial(int tecla, int x, int y) {
	switch(tecla) {
		case TECLA_F2: // Alternar para tela cheia
			if(telaCheia) {
				glutReshapeWindow(640, 480);
			} else {
				glutFullScreen();
			}

			telaCheia = !telaCheia;
			break;
		case TECLA_F3: // Alternar entre modo caminhada e corrida
			if(modoCaminhada)
				numeroEstagios = Cavalo::ESTAGIOS_TROTE;
			else
				numeroEstagios = Cavalo::ESTAGIOS_CAMINHADA;

			modoCaminhada = !modoCaminhada;
			break;
		case TECLA_CIMA: // Andar para frente
			deslocar += quantidadeDeslocamento;
			estagioModelo++;
			estagioModelo = estagioModelo % numeroEstagios;

			break;
		case TECLA_BAIXO: // Andar para tras
			deslocar -= quantidadeDeslocamento;
			estagioModelo--;

			if(estagioModelo < 0)
				estagioModelo = numeroEstagios - 1;
			break;
		case TECLA_ESQUERDA: // Girar para a esquerda
			anguloModelo += 5;
			break;
		case TECLA_DIREITA: // Girar para a direita
			anguloModelo -= 5;
			break;
		default:
			break;
	}
}

/**
 * Inicializar configurações do OpenGL.
 */
void inicializarOpenGL() {
	glClearColor(0.0, 0.29f, 0.6f, 0.0);
	glClearDepth(5.0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glMatrixMode(GL_MODELVIEW);
}

/**
 * Função principal do programa.
 */
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// Criar a janela
	glutInitWindowSize(larguraJanela, alturaJanela);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - larguraJanela)/2,
	                       (glutGet(GLUT_SCREEN_HEIGHT) - alturaJanela)/2);
	janela = glutCreateWindow("OpenGL - Modelo Hierárquico: Cavalo");

	// Funções
	glutReshapeFunc(redimensionarJanela);
	glutDisplayFunc(redesenharMundo);
	glutKeyboardFunc(tecla);
	glutSpecialFunc(teclaEspecial);
	glutIdleFunc(mostrarMundo);
	inicializarOpenGL();

	glutMainLoop();
	return 0;
}

#endif /* OPENGL_H_ */
