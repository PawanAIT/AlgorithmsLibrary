/*
 * scaling.cpp
 *
 *  Created on: 12-Apr-2015
 *      Author: goldy
 */
#include<GL/gl.h>
#include<GL/freeglut.h>
#include "header.h"

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wsize,wsize);
	glutInitWindowPosition(500,50);
	glutCreateWindow("2D : Scaling");
	myinit();
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(passiveMouse);

	glutCreateMenu(menu);
	glutAddMenuEntry("Scaling",1);
	glutAddMenuEntry("Translation",2);
	glutAddMenuEntry("Rotation",3);
	glutAddMenuEntry("Clear",4);
	glutAddMenuEntry("Exit",5);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}



