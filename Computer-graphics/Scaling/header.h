/*
 * header.h
 *
 *  Created on: 12-Apr-2015
 *      Author: goldy
 */

#ifndef HEADER_H_
#define HEADER_H_
#include<math.h>
#include<iostream>
using namespace std;
#define wsize 600
int v[50][2];
int count=0;
bool done=false,first=true;
enum Etask { Scaling , Rotation , Translation , Nothing };
enum Estatus { Start , Stop };
enum Edirection { All , Xdir , Ydir };
int action=Nothing,status=Stop,baseX,baseY,direction=All;
float factor;
void myinit()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-wsize/2,wsize/2,-wsize/2,wsize/2);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i( -wsize/2 , 0 );		glVertex2i( wsize/2 , 0 );
	glVertex2i( 0 , -wsize/2 );		glVertex2i( 0 , wsize/2 );
	glEnd();
	glFlush();
}
void mouse(int button,int state,int x,int y)
{
	x=x-wsize/2;	y=wsize/2-y;
	if( state==GLUT_DOWN && button==GLUT_LEFT_BUTTON && done==false)
	{
		glColor3f(0,0,0);	glPointSize(3);
		glBegin(GL_POINTS);	glVertex2i(x,y);	glEnd();
		glFlush();

		v[count][0]=x;	v[count++][1]=y;
		if(count>1)
		{
			glColor3f(0,0,0);	glLineWidth(3);
			glBegin(GL_LINES);
			glVertex2i( v[count-2][0] , v[count-2][1] );
			glVertex2i( x , y );
			glEnd();	glFlush();
		}

	}
	else if( state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON && done==false && count>2)
	{
		glColor3f(0,0,0);	glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2i( v[count-1][0] , v[count-1][1] );
		glVertex2i( v[0][0] , v[0][1] );
		glEnd();	glFlush();
		done=true;
		glutAttachMenu(GLUT_MIDDLE_BUTTON);
	}
	else if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON && done==true)
	{
		status=Stop;

		if(action==Scaling)
		{
		if(direction==All)
		for(int i=0;i<count;++i)
		{
			v[i][0]*=factor;	v[i][1]*=factor;
		}

		if(direction==Xdir)
		for(int i=0;i<count;++i)
			v[i][0]*=factor;

		if(direction==Ydir)
		for(int i=0;i<count;++i)
			v[i][1]*=factor;
		return;
		}
		if(action==Translation)
		{
			if(direction==All)
				for(int i=0;i<count;++i)
				{
					v[i][0]+=factor;	v[i][1]+=factor;
				}

			if(direction==Xdir)
				for(int i=0;i<count;++i)
					v[i][0]+=factor;

			if(direction==Ydir)
				for(int i=0;i<count;++i)
					v[i][1]+=factor;
			return;
		}
		if(action==Rotation)
		{
			for(int i=0;i<count;++i)
			{
				int temp1=( v[i][0]*cos(factor) )+ ( v[i][1]*sin(factor) );
				int temp2=( -v[i][0]*sin(factor) ) + ( v[i][1]*cos(factor) );
				v[i][0]=temp1;
				v[i][1]=temp2;
			}
		return;
		}
	}

}
void passiveMouse(int x,int y)
{
	if(status==Stop)
		return;
	x=x-wsize/2;	y=wsize/2-y;
	if(action==Scaling)
	{
		if(first==true)
		{
			baseX=x;	baseY=y;	first=false;	return;
		}
		factor=1+(float)(x-baseX)/50;
		if(factor<0)
			factor*=-1;

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);	glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2i( -wsize/2 , 0 );		glVertex2i( wsize/2 , 0 );
		glVertex2i( 0 , -wsize/2 );		glVertex2i( 0 , wsize/2 );
		glEnd();

		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		if(direction==All)
		for(int i=0;i<count;++i)
			glVertex2i( v[i][0]*factor , v[i][1]*factor );
		else if(direction==Xdir)
			for(int i=0;i<count;++i)
				glVertex2i( v[i][0]*factor , v[i][1] );
		else if(direction==Ydir)
			for(int i=0;i<count;++i)
				glVertex2i( v[i][0] , v[i][1]*factor );

		glEnd();
		glFlush();
		return;
	}
	if(action==Translation)
	{
		if(first==true)
		{
			baseX=x;	baseY=y;	first=false;	return;
		}
		factor=(x-baseX);

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);	glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2i( -wsize/2 , 0 );		glVertex2i( wsize/2 , 0 );
		glVertex2i( 0 , -wsize/2 );		glVertex2i( 0 , wsize/2 );
		glEnd();

		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		if(direction==All)
		for(int i=0;i<count;++i)
			glVertex2i( v[i][0]+factor , v[i][1]+factor );
		else if(direction==Xdir)
			for(int i=0;i<count;++i)
				glVertex2i( v[i][0]+factor , v[i][1] );
		else if(direction==Ydir)
			for(int i=0;i<count;++i)
				glVertex2i( v[i][0] , v[i][1]+factor );

		glEnd();
		glFlush();
		return;
	}
	if(action==Rotation)
	{
		if(first==true)
		{
			baseX=x;	baseY=y;	first=false;	return;
		}

		factor=(float)(x-baseX)*M_PI/180;

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);	glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2i( -wsize/2 , 0 );		glVertex2i( wsize/2 , 0 );
		glVertex2i( 0 , -wsize/2 );		glVertex2i( 0 , wsize/2 );
		glEnd();

		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<count;++i)
			glVertex2i( v[i][0]*cos(factor)+v[i][1]*sin(factor) , -v[i][0]*sin(factor)+v[i][1]*cos(factor) );

		glEnd();
		glFlush();
		return;
	}

}
void menu(int option)
{
	switch(option)
	{
	case 1:
		action=Scaling;
		status=Start;
		first=true;
		direction=All;
		break;
	case 2:
		action=Translation;
		status=Start;
		first=true;
		direction=All;
		break;
	case 3:
		action=Rotation;
		status=Start;
		first=true;
		break;
	case 4:
		action=Nothing;
		status=Stop;
		first=false;
		count=0;
		done=false;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);	glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2i( -wsize/2 , 0 );		glVertex2i( wsize/2 , 0 );
		glVertex2i( 0 , -wsize/2 );		glVertex2i( 0 , wsize/2 );
		glEnd();
		break;
	case 5:
		exit(0);
	}
}
void keyboard(unsigned char key,int x,int y)
{
	if(key=='a')
		direction=All;
	if(key=='x')
		direction=Xdir;
	if(key=='y')
		direction=Ydir;
}

#endif /* HEADER_H_ */












