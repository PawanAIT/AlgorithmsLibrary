/*
 * line.cpp
 *
 *  Created on: 08-Mar-2015
 *      Author: rupinder
 */
#include<iostream>
#include<GL/gl.h>
#include<GL/freeglut.h>
using namespace std;
#define wSize 500		 //window size in pixels

int algoChoice=0;	//1-bres	2-dda
int abs(int a)
{
	if(a<0)
		return a*(-1);
	else
		return a;
}
int sign(float a);
int x1=0,y1=0;
void initialize();
void dispFunc();
void mouse(int,int,int,int);
void keyboard(unsigned char,int,int);
void setpixel(int,int);
void mouse2(int,int);
void passivemouse(int,int);
void bres(int,int,int,int);
void dda(int x1,int y1,int x2,int y2);
void choice(int);
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(wSize,wSize);
	glutInitWindowPosition(780,100);
	glutCreateWindow("Line Drawing");
	//glutDisplayFunc(dispFunc);
	initialize();
	choice(0);
	glPointSize(10);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse2);
	glutPassiveMotionFunc(passivemouse);
	//glutKeyboardFunc(keyboard);
	glutSetCursor(GLUT_CURSOR_INFO);


	glutMainLoop();

}
void choice(int a)
{
	if(a==0)
	glColor3f(1,1,1);
	if(a==1)
		glColor3f(0,0,0);
	if(a==2)
		glColor3f(1,1,1);

	glRasterPos2f(-135,9);
	char dda[]={"DDA"};
	for(int i=0;dda[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,dda[i]);

	if(a==1)
		glColor3f(1,1,1);
	if(a==2)
		glColor3f(0,0,0);

	glRasterPos2f(40,9);
	char bres[]={"Bresehnam"};
	for(int i=0;bres[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,bres[i]);

	glFlush();
}
void initialize()
{
	glClearColor(0,0,0,0);
	//glClearColor(0,0.654,0.65,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-wSize/2,wSize/2,-wSize/2,wSize/2);

	glColor3f(0,0,0);
			glPointSize(2);
			for(int i=-wSize;i<wSize;++i)
			{
				glBegin(GL_POINTS);
				glVertex2f(i,0);
				glVertex2f(0,i);
				glEnd();

			}
			glFlush();
}
void dispFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
		glPointSize(2);
		for(int i=-wSize/2;i<wSize/2;++i)
		{
			glBegin(GL_POINTS);
			glVertex2f(i,0);
			glVertex2f(0,i);
			glEnd();

		}
		glFlush();
}
void mouse(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON)
	{
		x1=x-250;
		y1=250-y;
	}
	if(state==GLUT_UP && button==GLUT_LEFT_BUTTON && algoChoice==0)
	{
		glClearColor(0,0.654,0.65,0);
		dispFunc();
		if((x-250)<0)
			algoChoice=1;
		else
			algoChoice=2;
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}

}
void mouse2(int x,int y)
{
	if(algoChoice==0)
		return;
	dispFunc();
	if(algoChoice==2)
		bres(x1,y1,x-250,250-y);
	else
		dda(x1,y1,x-250,250-y);
/*
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x-250,250-y);
	glEnd();
	glFlush();*/
	glFlush();
}
void setpixel(int x,int y)
{
	//glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}
void bres(int x1,int y1,int x2,int y2)
{
	int s1,s2,exchange,y,x,i;
	float dx,dy,g,temp;
	dx=abs(x2-x1);
	dy=abs(y1-y2);
	x=x1;
	y=y1;
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		exchange=1;
	}
	else
		exchange=0;
	g=2*dy-dx;
	i=1;
	while(i<=dx)
	{
		setpixel(x,y);
		while(g>=0)
		{
			if(exchange==1)
				x=x+s1;
			else
				y=y+s2;
			g=g-2*dx;
		}
		if(exchange==1)
			y=y+s2;
		else
			x=x+s1;
		g=g+2*dy;
		i++;
	}
}
int sign(float a)
{
	if(a<0)
		return -1;
	return 1;
}
void dda(int x1,int y1,int x2,int y2)
{
	int i,dx,dy,steps;
	float x,y;
	float xinc,yinc;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;
	xinc=(float)dx/steps;
	yinc=(float)dy/steps;
	x=x1;
	y=y1;
	setpixel(x,y);
	for(i=1;i<steps;++i)
	{
		x+=xinc;
		y+=yinc;
		x1=x+0.5;
		y1=y+0.5;
		setpixel(x,y);
	}
}
void passivemouse(int x,int y)
{
	if(algoChoice!=0)
		return;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	if(x-250<0)
	{

		glColor3f(1,1,1);
		glLineWidth(2);
		glBegin(GL_LINES);
		for(int i=-wSize/2;i<0;++i)
			{
			glVertex2f(i,-wSize/2);
			glVertex2f(i,wSize/2);

			}
		glEnd();
		choice(1);
		glFlush();
		return;
	}

	glColor3f(1,1,1);
	glLineWidth(2);
	glBegin(GL_LINES);
	for(int i=0;i<wSize/2;++i)
		{
		glVertex2f(i,-wSize/2);
				glVertex2f(i,wSize/2);
		}
	glEnd();
	choice(2);
	glFlush();


}



