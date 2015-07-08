/*
 *		Este código foi modificado e extendido por Aldo v.Wangenheim
 *		(awangenh@inf.ufsc.br - http://www.inf.ufsc.br/~awangenh/CG/)
 *		para utilização na:
 *		Disciplina ine 5341 - Computacao Grafica do Departamento de
 *		Informatica e Estatistica da Universidade Federal de Santa
 *		Catarina.
 *
 *		Florianopolis, Ilha de Santa Catarina, Maio/Junho de 2001
 *
 *
 *		This Code Was Originally Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing The Base Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 *
 *		Parts of this code were Written by Michael Sweet.
 *		The OpenGL SuperBible
 *
 */

#include <stdlib.h>		// incluimos stdlib para compatibilidade com
						// microsoft windows. Em Unix esta linha eh
						// sem efeito porque stdlib eh incluido por
						// default sempre. Se voce esquecer esta linha
						// em windows, seu compilador vai dizer que
						// nao conhece a funcao exit()...

#include <stdio.h>		// Incluimos stdio para podermos usar printf()
						// para debugar alguma coisa que queiramos.
						// Mais tarde vamos usar fscanf e fgets para
						// ler dados. Se voce esta usando uma versao
						// antiga de Borland C++ (ou Turbo C) ou mesmo
						// outro compilador C p/windows fora de padrao
						// ANSI, voce provavelmente tera de incluir
						// um headerfile obsoleto chamado conio.h aqui

#include <GL/glut.h>	// Aqui sao incluidas TODAS as definicoes
						// para tanto o OpenGL como o GLUT compilarem com
						// sucesso em QUALQUER sistema operacional.
						// NUNCA inclua windows.h ou outro headerfile
						// especifico a windows em seus programas, que
						// voce estara produzindo codigo que so compila
						// nesta plataforma. O glut.h resolve a independencia
						// de plataforma de todo codigo OpenGL de uma forma
						// extremamente elegante: a versao de glut.h para
						// cada plataforma inclue os headerfiles especificos
						// para aquela plataforma.

#define ESCAPE 27		/* ascii code for the escape key */



/*
 * Globals...
 */


int		window;				/* The number of our GLUT window */

int		Width;				/* Width of window */
int		Height;				/* Height of window */


/*
 * Functions...
 */


void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LEQUAL);			// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();					// Reset The Projection Matrix

  glMatrixMode(GL_MODELVIEW);
}

/*==========================================================*/
/*	The function called whenever a key is pressed.			*/
void
tecla(unsigned char tecla, int x, int y)
/*==========================================================*/
{
  switch ( tecla ) {
    case 27:			// When Escape Is Pressed...
		/* shut down our window */
		glutDestroyWindow(window);
		/* exit the program...normal termination. */
		exit(0);
		break;			// Ready For Next Case
    default:			// Now Wrap It Up
		break;
  }

}


/*==========================================================*/
/*	The function called whenever a special key is pressed.	*/
void
teclas_de_seta ( int tecla, int x, int y )
/*==========================================================*/
{
  switch ( tecla ) {
    case GLUT_KEY_UP:					// When Up Arrow Is Pressed...
      glutFullScreen ( );				// Go Into Full Screen Mode
      break;
    case GLUT_KEY_DOWN:					// When Down Arrow Is Pressed...
      glutReshapeWindow ( 640, 480 );	// Go Into A 640 By 480 Window
      break;
    default:
		printf("Teclaram: %d\n", tecla);
      break;
  }
}



/*==========================================================*/
/*  redesenhaMundo() - Redraw the window...					*/
void
redesenhaMundo(void)
/*==========================================================*/
    {
    /* Clear the window to black */
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	/* eh AQUI que você vai chamar todas as funcoes que
	   desenham algo */

	glutSwapBuffers();

    }



/*=====================================================	*/
/* redimensionaJanela() - Resize the window...			*/
void
redimensionaJanela(	int width,  /* I - Width of window	*/
					int height) /* I - Height of window	*/
/*=====================================================	*/
    {
    /* Save the new width and height */
    Width  = width;
    Height = height;

    /* Reset the viewport... */
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // Reset The Modelview Matrix

    }


/*===========================================================*/
/* Funcao que chama redraw.									 */
/* Endereco passado como a Idle Function, funcao que		 */
/* o laco do GLUT chama quando nao esta fazendo outra coisa. */
void
mostraMundo(void)
/*===========================================================*/
{

	redesenhaMundo();

}

/*==========================================================*/
/*	'main()' - Open a window and display some text.			*/
int                /* O - Exit status						*/
main(int  argc,    /* I - Number of command-line arguments	*/
     char *argv[]) /* I - Command-line arguments			*/
/*==========================================================*/
    {
	/* Initialize GLUT state - glut will take any command line arguments that pertain to it or
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */
    glutInit(&argc, argv);
	/*	Select type of Display mode:
		Double buffer
		RGBA color
		Alpha components supported
		Depth buffer */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/* get a 640 x 480 window */
    glutInitWindowSize(640, 480);

	/*	The window starts at the upper left corner of the screen	*/
	/*	Aparentemente esta funcao so faz sentido no X-Windows. Em	*/
	/*	MS-Windows a janela aparece sempre aa esquerda em cima de	*/
	/*	qualquer forma.												*/
	glutInitWindowPosition(0, 0);

	/* Abrimos aqui uma janela, Open a window						*/
	/* A variavel window guarda o numero da janela. Pode ser util.	*/
    window = glutCreateWindow("ine5341 Computação Gráfica UFSC - Rotação de Objetos Facetados e Modelos de Arame");

    /*	Register the function called when our window is resized.	*/
	glutReshapeFunc(redimensionaJanela);

	/*	Register the function to do all our OpenGL drawing.			*/
    glutDisplayFunc(redesenhaMundo);

	/* Register the function called when the keyboard is pressed.	*/
	glutKeyboardFunc(tecla);

	/* Resgitramos a funcao que é chamada quando uma tecla especial */
	/* foi teclada, como setas e teclas de funcao.					*/
	glutSpecialFunc(teclas_de_seta);


	/* Funcao chamada sempre que o Loop do GLUT esta ocioso			*/
	/* Esta funcao eh responsavel pelos efeitos de animacao.		*/
	glutIdleFunc(mostraMundo);

	/* Chamamos a funcao que realiza o resto das inicializacoes.	*/
	InitGL( 640, 480);

    /* Iniciamos a maquina de processamento de eventos do GLUT.		*/
	glutMainLoop();
    return (0);
    }

