/*
 * circle_drawing.cpp
 *
 *  Created on: 11-Mar-2015
 *      Author: rupinder
 */
#include<iostream>
using namespace std;
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<math.h>
#define wSize 500

void mouse(int,int,int,int);
void passiveMouse(int,int);
void motionMouse(int x,int y);
void initialize();
void options(int);
void midPoint(int,int,int);
void bres(int,int,int);
int step=0;
int algo=1; 	//		1-midpoint		2-bres		3- DDA
int x_center,y_center;
int main(int argv,char **argc)
{
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(wSize,wSize);
	glutInitWindowPosition(780,100);
	glutCreateWindow("Circle Drawing");
	initialize();
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(-60,0);
	glEnd();
	options(0);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(passiveMouse);
	glutMotionFunc(motionMouse);
	glutSetCursor(GLUT_CURSOR_INFO);

	glutMainLoop();

	return 0;
}
void mouse(int button,int state,int x,int y)			// simple mouse function
{
	if(state==GLUT_UP && button==GLUT_LEFT_BUTTON && step==0)
	{
		if(x-250<-100 || x-250>100 || 250-y>70 || 250-y<-70)
			return;
		step=1;
		cout<<"step 0 done\n";
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
		if(x-250>-100 && x-250<100 && 250-y>20 && 250-y<70)
			algo=1;
		else if(x-250>-100 && x-250<100 && 250-y>-20 && 250-y<20)
			algo=2;
		else if(x-250>-100 && x-250<100 && 250-y>-70 && 250-y<-20)
			algo=3;
	}
	if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON && step!=0)
	{
		x_center=x-250;
		y_center=250-y;
	}
}
void motionMouse(int x,int y)			// button is pressed
{
	if(step==0)
		return;
	if(algo==1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2f(x_center,y_center);
		glEnd();
		glPointSize(1);
		int radious=sqrt( pow(abs(x_center-(x-250)),2) + pow(abs(y_center-(250-y)),2) );
		midPoint(x_center,y_center,radious);
		glFlush();
	}
	if(algo==2)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2f(x_center,y_center);
		glEnd();
		glPointSize(1);
		int radious=sqrt( pow(abs(x_center-(x-250)),2) + pow(abs(y_center-(250-y)),2) );
		bres(x_center,y_center,radious);
		glFlush();
	}
	if(algo==3)
	{
		/*glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2f(x_center,y_center);
		glEnd();
		glPointSize(1);
		int radious=sqrt( pow(abs(x_center-(x-250)),2) + pow(abs(y_center-(250-y)),2) );
		midPoint(x_center,y_center,radious);
		glFlush();*/
	}
}
void passiveMouse(int x,int y)			// no button is clicked
{
	if(step!=0)
		return;
	if(x-250>-100 && x-250<100 && 250-y>20 && 250-y<70)
		options(1);
	else if(x-250>-100 && x-250<100 && 250-y>-20 && 250-y<20)
		options(2);
	else if(x-250>-100 && x-250<100 && 250-y>-70 && 250-y<-20)
		options(3);
	else
		options(0);

}
void initialize()
{
	//glClearColor(0,0.6,0.546,0);
	glClearColor(0.0,0.7,0.75,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-wSize/2,wSize/2,-wSize/2,wSize/2);
}
void options(int key)
{

	if(key==1)
	{
		glClearColor(0.0,0.7,0.75,0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0.0,1);
		glRasterPos2f(-50,40);		//	midpoint
		char a[]={"Mid Point"};
		for(int i=0;a[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
		glColor3f(1,1,1);
		glRasterPos2f(-55,-6);		// bres
		char b[]={"Bresenham"};
		for(int i=0;b[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[i]);
		glColor3f(1,1,1);
		glRasterPos2f(-33,-52);		//dda
		char c[]={"D D A"};
		for(int i=0;c[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
	}
	else if(key==2)
	{
		glClearColor(0.0,0.7,0.75,0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);		// mid point
		glRasterPos2f(-50,40);
		char a[]={"Mid Point"};
		for(int i=0;a[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
		glColor3f(0,0,1);		// bres
		glRasterPos2f(-55,-6);
		char b[]={"Bresenham"};
		for(int i=0;b[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[i]);
		glColor3f(1,1,1);
		glRasterPos2f(-33,-52);		//dda
		char c[]={"D D A"};
		for(int i=0;c[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
	}
	else if(key==3)
	{
		glClearColor(0.0,0.7,0.75,0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);		// mid point
		glRasterPos2f(-50,40);
		char a[]={"Mid Point"};
		for(int i=0;a[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
		glColor3f(1,1,1);		// bres
		glRasterPos2f(-55,-6);
		char b[]={"Bresenham"};
		for(int i=0;b[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[i]);
		glColor3f(0,0,1);
		glRasterPos2f(-33,-52);		//dda
		char c[]={"D D A"};
		for(int i=0;c[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
	}
	else
	{
		glClearColor(0.0,0.7,0.75,0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);
		glRasterPos2f(-50,40);		// mid point
		char a[]={"Mid Point"};
		for(int i=0;a[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
		glRasterPos2f(-55,-6);		// bres
		char b[]={"Bresenham"};
		for(int i=0;b[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[i]);
		glRasterPos2f(-33,-52);		//dda
		char c[]={"D D A"};
		for(int i=0;c[i]!='\0';++i)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
	}

	glFlush();
}
void midPoint(int x,int y,int r)
{
	int x1=0,y1=r;
	float dp=1-r;
	while(x1<=y1)
	{
		if(dp<=0)
		{
			x1++;
			dp+=(2*x1)+1;
		}
		else
		{
			x1++;
			y1--;
			dp+=2*(x1-y1)+1;
		}
		glBegin(GL_POINTS);
		glVertex2f(x1+x,y1+y);
		glVertex2f(x1+x,y-y1);
		glVertex2f(x-x1,y1+y);
		glVertex2f(x-x1,y-y1);
		glVertex2f(x+y1,y+x1);
		glVertex2f(x+y1,y-x1);
		glVertex2f(x-y1,y+x1);
		glVertex2f(x-y1,y-x1);

		glVertex2f(x+r,y);
		glVertex2f(x,y+r);
		glVertex2f(x-r,y);
		glVertex2f(x,y-r);
		glEnd();
	}

}
void bres(int x,int y,int r)
{
	int x1=0,y1=r;
	float dp=3-(2*r);
	while(x1<=y1)
	{
		if(dp<=0)
		{
			dp+=(4*x1)+6;
		}
		else
		{
			dp+=4*(x1-y1)+10;
			y1--;
		}
		x1++;

		glBegin(GL_POINTS);
		glVertex2f(x1+x,y1+y);
		glVertex2f(x1+x,y-y1);
		glVertex2f(x-x1,y1+y);
		glVertex2f(x-x1,y-y1);
		glVertex2f(x+y1,y+x1);
		glVertex2f(x+y1,y-x1);
		glVertex2f(x-y1,y+x1);
		glVertex2f(x-y1,y-x1);

		glVertex2f(x+r,y);
		glVertex2f(x,y+r);
		glVertex2f(x-r,y);
		glVertex2f(x,y-r);
		glEnd();
	}
}




