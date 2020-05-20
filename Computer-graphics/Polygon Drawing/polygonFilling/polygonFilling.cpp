/*
 * polygonFilling.cpp
 *
 *  Created on: 18-Mar-2015
 *      Author: rupinder
 */

#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#include "myHeaderPolygonFilling.h"


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WindowSize,WindowSize);
	glutInitWindowPosition(750,80);
	glutCreateWindow("Polygon Filling Using Scan-Line");
	initialize();
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glutMouseFunc(mouse_normal);
	glutMotionFunc(mouse_motion);
	glutPassiveMotionFunc(mouse_passive);
	options(0);


	glutMainLoop();
	return 0;
}
