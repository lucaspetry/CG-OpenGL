#ifndef OPENGL_H_
#define OPENGL_H_

#include <GL/glut.h>

/*===================== Teclas =====================*/
const unsigned char TECLA_ESC = 27;
const unsigned char TECLA_CIMA = GLUT_KEY_UP;
const unsigned char TECLA_BAIXO = GLUT_KEY_DOWN;
/*==================================================*/

/*============== Atributos da Janela ===============*/
int janela;
unsigned int larguraJanela;
unsigned int alturaJanela;
/*==================================================*/

/**
 * Inicializar configurações do OpenGL.
 */
void inicializarOpenGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Limpar a janela para preto
	glClearDepth(1.0);						// Habilitar limpeza do buffer de profundidade
	glDepthFunc(GL_LEQUAL);					// Tipo do teste de profundidade
	glEnable(GL_DEPTH_TEST);				// Habilitar teste de profundidade
	glShadeModel(GL_SMOOTH);				// Habilitar Smooth Color Shading
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();						// Carregar a matriz identidade como inicial
	glMatrixMode(GL_MODELVIEW);
}

/**
 * Redesenhar o mundo.
 */
void redesenharMundo() {
	// Limpar a janela
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	/**
	 * DESENHAR ALGO
	 */

	// Trocar o buffer da memória para ser desenhado
	glutSwapBuffers();
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
void teclas_de_seta( int tecla, int x, int y ) {
	switch(tecla) {
		case TECLA_CIMA:
			glutFullScreen();
			break;
		case TECLA_BAIXO:
			glutReshapeWindow(640, 480);
			break;
		default:
			//printf("Teclaram: %d\n", tecla);
			break;
	}
}

/**
 * Função principal do programa.
 */
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	janela = glutCreateWindow("Título da Janela");
	glutReshapeFunc(redimensionarJanela);
	glutDisplayFunc(redesenharMundo);
	glutKeyboardFunc(tecla);
	glutSpecialFunc(teclas_de_seta);
	glutIdleFunc(mostrarMundo);
	inicializarOpenGL();
	glutMainLoop();
	return 0;
}

#endif /* OPENGL_H_ */
