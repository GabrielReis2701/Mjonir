#include "glut.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "tgaload.h"
/* Defini��es da c�mera */
#define y_min 60
#define ro_min 120
#define MAX_NO_TEXTURES 4
#define CUBE_TEXTURE 0

GLuint texture_id[MAX_NO_TEXTURES];


float eyex = 0, eyey = y_min, eyez = ro_min;
float angle = 0;
int aux=0;

void initTexture (void)
{
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	image_t temp_image0;
	tgaLoad  ( "textura_escritura2.tga", &temp_image0, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	image_t temp_image1;
	tgaLoad  ( "lado_escritura.tga", &temp_image1, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
	image_t temp_image2;
	tgaLoad  ( "lado_escritura.tga", &temp_image2, TGA_FREE | TGA_LOW_QUALITY );
	
}
void make_tex(void){
    unsigned char data[256][256][3];
    for (int y = 0; y < 255; y++) {
		for (int x = 0; x < 255; x++) {
	    unsigned char *p = data[y][x];
	    p[0] = p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
		}
	}
   
    glGenTextures (3, texture_id);
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
}

//corpo da espada
void drawFirst(){
	glColor3f(0.4941,0.53726,0.58824);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
	glBegin(GL_POLYGON);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.68,1.77,2); //Ponto A
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.68,-1.77,2); //Ponto C
		glTexCoord2f(1.0, 1.0);glVertex3f(1.68, -1.77,2); //Ponto D
		glTexCoord2f(0.0, 1.0);glVertex3f(1.68, 1.77,2); // Ponto B
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(1.68, -1.77,2); //Ponto D
		glTexCoord2f(1.0, 0.0);glVertex3f(1.89,-1.5,2 ); //Ponto H
		glTexCoord2f(1.0, 1.0);glVertex3f(1.89,1.5,2 ); //Ponto G
		glTexCoord2f(0.0, 1.0);glVertex3f(1.68, 1.77,2); // Ponto B
	glEnd();
	
	glBegin(GL_POLYGON);
		
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.68,1.77,2); //Ponto A
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.89,1.5,2 ); //Ponto E
		glTexCoord2f(1.0, 1.0);glVertex3f(-1.89,-1.5,2); //Ponto F
		glTexCoord2f(0.0, 1.0);glVertex3f(-1.68,-1.77,2); //Ponto C
	glEnd();
	glDisable(GL_TEXTURE_2D); 
	
	glBegin(GL_POLYGON);
	//Parte de Baixo
		glVertex3f(-1.8,2.2,1); //Ponto I 
		glVertex3f(-2.3,1.7,1); //Ponto J 
		glVertex3f(-2.3,-1.7,1); //Ponto P
		glVertex3f(-1.8,-2.2,1); //Ponto O 
		glVertex3f(1.8, -2.2,1); //Ponto M 
		glVertex3f(2.3,-1.7,1); //Ponto N 
		glVertex3f(2.3,1.7,1); //Ponto L 
		glVertex3f(1.8,2.2,1); //Ponto K 
	glEnd();
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(1.68, 1.77,2); // Ponto B
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.68,1.77,2); //Ponto A
		glTexCoord2f(1.0, 1.0);glVertex3f(-1.8,2.2,1); //Ponto I
		glTexCoord2f(0.0, 1.0);glVertex3f(1.8,2.2,1); //Ponto K 
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(1.89,-1.5,2 ); //Ponto H
		glTexCoord2f(1.0, 0.0);glVertex3f(1.89,1.5,2 ); //Ponto G
		glTexCoord2f(1.0, 1.0);glVertex3f(2.3,1.7,1); //Ponto L 
		glTexCoord2f(0.0, 1.0);glVertex3f(2.3,-1.7,1); //Ponto N
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.68,-1.77,2); //Ponto C
		glTexCoord2f(1.0, 0.0);glVertex3f(1.68, -1.77,2); //Ponto D
		glTexCoord2f(1.0, 1.0);glVertex3f(1.8, -2.2,1); //Ponto M 
		glTexCoord2f(0.0, 1.0);glVertex3f(-1.8,-2.2,1); //Ponto O 
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.89,1.5,2 ); //Ponto E
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.89,-1.5,2); //Ponto F
		glTexCoord2f(1.0, 1.0);glVertex3f(-2.3,-1.7,1); //Ponto P
		glTexCoord2f(0.0, 1.0);glVertex3f(-2.3,1.7,1); //Ponto J 
	glEnd();
	glDisable(GL_TEXTURE_2D); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.89,-1.5,2); //Ponto F
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.68,-1.77,2); //Ponto C
		glTexCoord2f(1.0, 1.0);glVertex3f(-1.8,-2.2,1); //Ponto O
		glTexCoord2f(0.0, 1.0);glVertex3f(-2.3,-1.7,1); //Ponto P 
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(-1.68,1.77,2); //Ponto A
		glTexCoord2f(1.0, 0.0);glVertex3f(-1.89,1.5,2 ); //Ponto E
		glTexCoord2f(1.0, 1.0);glVertex3f(-2.3,1.7,1); //Ponto J
		glTexCoord2f(0.0, 1.0);glVertex3f(-1.8,2.2,1); //Ponto I
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(1.89,1.5,2 ); //Ponto G
		glTexCoord2f(1.0, 0.0);glVertex3f(1.68, 1.77,2); // Ponto B
		glTexCoord2f(1.0, 1.0);glVertex3f(1.8,2.2,1); //Ponto K 
		glTexCoord2f(0.0, 1.0);glVertex3f(2.3,1.7,1); //Ponto L
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);glVertex3f(1.68, -1.77,2); //Ponto D
		glTexCoord2f(1.0, 0.0);glVertex3f(1.89,-1.5,2 ); //Ponto H
		glTexCoord2f(1.0, 1.0);glVertex3f(2.3,-1.7,1); //Ponto N
		glTexCoord2f(0.0, 1.0);glVertex3f(1.8, -2.2,1); //Ponto M 
	glEnd();
	
	glDisable(GL_TEXTURE_2D); 
	
}

//void drawCabo(){
//	color(0.12,0.14,0.15);
//	glPushMatrix();
//		glutSolidSphere( 6, 16, 16 );
//	glPopMatrix();
//	
//	glRotatef(90,0,1,0);
//	
//	glPushMatrix();
//		glScalef(0.5,0.5,12);
//		glutSolidSphere( 4, 16, 16 );
//	glPopMatrix();
//	
//	glRotatef(-120,1,1,1);
//	glPushMatrix();
//		glScalef(1,1,13);
//		glutSolidSphere( 4, 16, 16 );
//	glPopMatrix();
//	
//	glTranslatef(-45,0,0);
//	glPushMatrix();
//		glutSolidSphere( 3, 16, 16 );
//	glPopMatrix();
//	
//	glTranslatef(90,0,0);
//	glPushMatrix();
//		glutSolidSphere( 3, 16, 16 );
//	glPopMatrix();
//	
//	glTranslatef(-45,0,-55);
//	glPushMatrix();
//		glutSolidSphere( 2, 16, 16 );
//	glPopMatrix();
//	
//}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Estabelece a cor da primitiva como preta */
    glColor3f (1.0, 1.0, 1.0);
    
    /* Define a posi��o do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
	glRotatef(angle, 0,1,0);
    
    	//glBegin(GL_LINE_LOOP);
    //glScalef(-0.8,0.8,-0.8);
    
    glPushMatrix();
    glScalef(10,10,10);
	    glPushMatrix();
	    
//	    	glTranslatef(0,20,3);
//	    	glScalef(20,25,5);
	    	glColor3f (0.65, 0.68, 0.64);
//	    	glRotatef(-120, 1,1,1);
	    	drawFirst();
	    glPopMatrix();
//	    glTranslatef(0,-65,0);
//		glScalef(-0.5,0.5,-0.5);
//		//glRotatef(60)
//		glPushMatrix();
//	    	drawCabo();
//	    glPopMatrix();
	glPopMatrix();
	//Executa os comandos OpenGL 
	glFlush();
}

void TimerFunc(int value) {
	angle += 1; 
    glutPostRedisplay();
    glutTimerFunc( 33, TimerFunc, 1);
}

void reshape(int width, int height) {
	glViewport(0,0,width,height); // Reset The Current Viewport
	
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(float)640/(float)480,0.1f,1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;
		case 'm': /* e key rotates at elbow */
	 	 aux = (int) (angle + 5);
		 angle = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'M': /* e key rotates at elbow */
	 	 aux = (int) (angle - 5);
		 angle = aux % 360;
		 glutPostRedisplay();
		 break;
			
	}
}

void init() {
	glClearColor(1,1,1,0);
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	make_tex();
    initTexture ();
    glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

/*
Funcao principal do programa.
*/
int main(int argc, char** argv)
{
	//Inicia a Telinha
	glutInit(&argc,argv);
	
    /*
    Estabelece o modo de exibicao a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer duplo, ou seja, a apresentacao
    execucao
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    
    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (450, 450);
    
    /*
    Estabelece a posicao inicial para criacao da
    janela
    */
    glutInitWindowPosition (100, 100);
    
    /*
    Cria uma janela com base nos parametros especificados
    nas funcoes glutInitWindowSize e glutInitWindowPosition
    com o nome de titulo especificado em seu argumento
    */
    glutCreateWindow ("Projeto Base");
    
    /*
    Especifica os parametros inicias para as variaveis
    de estado do OpenGL
    */
    init ();
    //TimerFunc(angle);
    // Associa a funcao display como uma funcao de callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    
    /*
    Inicia a execucao do programa OpenGL.
    O programa ira executar num loop infinito devendo
    o desenvolvedor especificar as condicoes de saida do mesmo
    atraves de interrupcoes no proprio programa ou atraves
    de comandos de mouse ou teclado como funcoes de callback
    */
    glutMainLoop();
    return 0;
}