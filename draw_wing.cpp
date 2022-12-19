//
//  draw_wing.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 08/11/22.
//

#include "draw_wing.hpp"
#include "glut.h"
#include "geometry.h"
#include <iostream>

void draw_wing(float ang){
    glRotatef(ang, 0, 1, 0);
    glScalef(0.3,0.3,0.3);
    glTranslatef(0, 0, 4);
    
    glPushMatrix();
    
	    glPushMatrix();
		    glTranslatef(0, 0, -4.9);
		    glBegin(GL_POLYGON);
			    point(-3.24,2.33,2); //Inicio
				point(-3.3,1.93,2);
				point(-3.46,1.51,2);
				point(-3.68,1.27,2);
				point(-3.86,1.13,2);
				point(-4,1,2);
				point(-4.18,0.91,2);
				point(-4.38,0.87,2);
				point(-4.58,0.83,2);
				point(-4.86,0.81,2);
				point(-5.1,0.83,2);
				point(-5.32,0.91,2);
				point(-5.54,1.03,2);
				point(-5.74,1.15,2);
				point(-5.94,1.31,2);
				point(-6.1,1.47,2);
				point(-6.2,1.65,2);
				point(-6.28,1.83,2);
				point(-6.36,2.01,2);
				point(-6.4,2.41,2); //Fim
				point(-6.4,2.41,0);//Fim
				point(-6.36,2.01,0);
				point(-6.28,1.83,0);
				point(-6.2,1.65,0);
				point(-6.1,1.47,0);
				point(-5.94,1.31,0);
				point(-5.74,1.15,0);
				point(-5.54,1.03,0);
				point(-5.32,0.91,0);
				point(-5.1,0.83,0);
				point(-4.86,0.81,0);
				point(-4.58,0.83,0);
				point(-4.38,0.87,0);
				point(-4.18,0.91,0);
				point(-4,1,0);
				point(-3.86,1.13,0);
				point(-3.68,1.27,0);
				point(-3.46,1.51,0);
				point(-3.3,1.93,0);
				point(-3.24,2.33,0);//Inicio
	    	glEnd();
	    glPopMatrix();
    
//    //conexão das asas - parte de cima
//    glPushMatrix();
//    glTranslatef(0, 0, -4.9);
//    glBegin(GL_LINE_LOOP);
//    point(0, 1, 0.05);
//    point(0, 1, -0.18);
//    
//    //subindo por z negativo
//    point(2, 1.5, -0.25);
//    point(3.5, 2, -0.28);
//    point(5, 2, -0.29);
//    point(7, 2.3, -0.31);
//    point(9, 3.3, -0.37);
//    
//    point(9, 3.3, 0.25);
//    point(7, 2.3, 0.2);
//    point(5, 2, 0.16);
//    point(3.5, 2, 0.14);
//    point(2, 1.5, 0.12);
//    
//    glEnd();
//    glPopMatrix();
//
//    
//    //asa direita
//    glPushMatrix();
//    glTranslatef(0, 0, -4.95);
//    glRotatef(5, 1, 0, 0);
//    glBegin(GL_LINE_LOOP);
//    
//    //base
//    point(0, 0, 0);
//    point(0, 1, 0);
//    
//    //seguindo para cima
//    point(2, 1.5, 0);
//    point(3.5, 2, 0);
//    point(5, 2, 0);
//    point(7, 2.3, 0);
//    point(9, 3.3, 0);
//
//    //descendo
//    point(8.5, 2.3, 0);
//    point(7, 1, 0);
//    point(5, 0, 0);
//    point(3.8, -0.5, 0);
//    point(3, -0.2, 0);
//    point(2.5, -0.1, 0);
//    
//    //voltou pra base 2d
//    point(0, 0, 0);
//    glEnd();
//    glPopMatrix();
//    
//    //asa esquerda
//    glPushMatrix();
//    glTranslatef(0, 0, -5);
//    glRotatef(-5, 1, 0, 0);
//    glBegin(GL_LINE_LOOP);
//    
//    //base
//    point(0, 0, 0);
//    point(0, 1, 0);
//    
//    //seguindo para cima
//    point(2, 1.5, 0);
//    point(3.5, 2, 0);
//    point(5, 2, 0);
//    point(7, 2.3, 0);
//    point(9, 3.3, 0);
//
//    //descendo
//    point(8.5, 2.3, 0);
//    point(7, 1, 0);
//    point(5, 0, 0);
//    point(3.8, -0.5, 0);
//    point(3, -0.2, 0);
//    point(2.5, -0.1, 0);
//    
//    //voltou pra base 2d
//    point(0, 0, 0);
//    glEnd();
//    glPopMatrix();
//    
//    glPopMatrix();
}
