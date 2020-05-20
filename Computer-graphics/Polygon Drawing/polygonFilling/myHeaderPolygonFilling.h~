/*
 * myHeaderPolygonFilling.h
 *
 *  Created on: 18-Mar-2015
 *      Author: rupinder
 */
#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

#ifndef MYHEADERPOLYGONFILLING_H_
#define MYHEADERPOLYGONFILLING_H_
#define WindowSize 600

enum enumalgo {SeedFill,ScanLine};
enum enumcolor {RED,GREEN,BLUE,buttonGrey};
#define ymax 0
#define ymin 1
#define xmax 2
#define xmin 3
#define slope 4
int edge[50][5]; 	  					// edge : ymax , ymin , xmax , xmin , slope
int lines[50][4];						// lines : x1,y1,x2,y2
int edge_count=0;
int vertex_count=0;
int x_temp,y_temp,firstX,firstY,done=0;
int FillColor=RED;
int intersect_count=0;
void fill();
void clear();
void sort();
void swap();
int intersect[100000][2];		// X	Y
void box(int x,int y,int h,int w,int color,char text[],int length,bool selected)
{
	if(color==RED)
		{glColor3f(1,0,0);	if(selected==true) FillColor=color;	}
	else if(color==GREEN)
		{glColor3f(0,1,0);	if(selected==true) FillColor=color;	}
	else if(color==BLUE)
		{glColor3f(0,0,1);	if(selected==true) FillColor=color;	}
	else if(color==buttonGrey)
		glColor3f(0.7,0.7,0.7);


	glPointSize(1);
	glBegin(GL_LINES);
	for(int i=y;i>(y-h);--i)
	{	glVertex2f(x,i);	glVertex2f(x+w,i);	}
	glEnd();

	if(selected==true)
	{
		glLineWidth(3);
		glColor3f(0,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(x,y);	glVertex2i(x,y-h);	glVertex2i(x+w,y-h);	glVertex2i(x+w,y);
		glEnd();
	}

	glColor3f(0,0,0);
	glRasterPos2f(x+5,y-h+12);
	while((length--)>0)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*(text++));
}
void options(int n)
{
	glLineWidth(3);
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_LINES);
	for(int i=240;i<303;i+=3)
	{
		glVertex2i(-300,i);
		glVertex2i(300,i);
	}
	glEnd();

	if(n==0)
	{
		if(FillColor==RED)
			n=1;
		if(FillColor==GREEN)
			n=2;
		if(FillColor==BLUE)
			n=3;
	}

	if(n==1)
	{box(-280,290,40,40,RED,NULL,0,true);	box(-220,290,40,40,GREEN,NULL,0,false);
	box(-160,290,40,40,BLUE,NULL,0,false);
	}
	else if(n==2)
	{box(-280,290,40,40,RED,NULL,0,false);	box(-220,290,40,40,GREEN,NULL,0,true);
	box(-160,290,40,40,BLUE,NULL,0,false);
	}
	else if(n==3)
	{box(-280,290,40,40,RED,NULL,0,false);	box(-220,290,40,40,GREEN,NULL,0,false);
	box(-160,290,40,40,BLUE,NULL,0,true);
	}

	glLineWidth(1);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(-100,295);		glVertex2i(-100,245);
	glEnd();

	box(-80,290,40,63,buttonGrey,"FILL",4,true);
	box(0,290,40,90,buttonGrey,"CLEAR",5,true);

	glFlush();

	//cout<<"n="<<n<<"  "<<FillColor<<endl;
}
void initialize()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-WindowSize/2,WindowSize/2,-WindowSize/2,WindowSize/2);
}
void setpixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void mouse_normal(int button,int state,int x,int y)
{
	if(300-y>240 && 300-y<300 && state==GLUT_DOWN)
		return;
	if(300-y>250 && 300-y<290 && state==GLUT_UP)
	{
		if(x-300>-280 && x-300<-240)
			options(1);
		else if(x-300>-220 && x-300<-180)
			options(2);
		else if(x-300>-160 && x-300<-120)
			options(3);
		else if(x-300>-80 && x-300<-17)
			fill();
		else if(x-300>0 && x-300<90)
			clear();
		return;
	}

	if(done==1)
		return;

	if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON)
	{
		if(vertex_count==0)
		{
			firstX=x_temp=x-300;	firstY=y_temp=300-y;
			vertex_count++;
		}
		else
		{
			x=x-300;	y=300-y;
			lines[edge_count][0]=x_temp;
			lines[edge_count][1]=y_temp;
			lines[edge_count][2]=x;
			lines[edge_count][3]=y;
			if(y>y_temp)
			{	edge[edge_count][0]=y;	edge[edge_count][1]=y_temp;	y_temp=y;	}
			else
			{	edge[edge_count][0]=y_temp;	edge[edge_count][1]=y;	y_temp=y;	}
			if(x>x_temp)
			{	edge[edge_count][2]=x;	edge[edge_count][3]=x_temp;	x_temp=x;	}
			else
			{	edge[edge_count][2]=x_temp;	edge[edge_count][3]=x;	x_temp=x;	}

			edge_count++;
			vertex_count++;

		}
	//cout<<"x_temp="<<x_temp<<"  y_temp="<<y_temp<<" edge="<<edge_count<<" vertex="<<vertex_count<<endl;
	}
	if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON)
	{
		x=x-300;	y=300-y;
		lines[edge_count][0]=firstX;
		lines[edge_count][1]=firstY;
		lines[edge_count][2]=x_temp;
		lines[edge_count][3]=y_temp;

		if(y_temp>firstY)
		{	edge[edge_count][0]=y_temp;	edge[edge_count][1]=firstY;	}
		else
		{	edge[edge_count][0]=firstY;	edge[edge_count][1]=y_temp;	}
		if(x_temp>firstX)
		{	edge[edge_count][2]=x_temp;	edge[edge_count][3]=firstX;	}
		else
		{	edge[edge_count][2]=firstX;	edge[edge_count][3]=x_temp;	}

		done=1;
		edge_count++;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);
		glLineWidth(3);
		glBegin(GL_LINES);
		for(int i=0;i<edge_count;++i)
		{	glVertex2i( lines[i][0] , lines[i][1] );	glVertex2i( lines[i][2] , lines[i][3] );	}
		glEnd();


		cout<<" edge="<<edge_count<<" vertex="<<vertex_count<<endl;
		/*for(int i=0;i<edge_count;++i)
		{
			cout<<"ymax="<<edge[i][0]<<" ymin="<<edge[i][1]<<" xmax="<<edge[i][2]<<" xmin="<<edge[i][3]<<endl;
		}*/
	}
	options(0);

}
void mouse_motion(int x,int y)
{

}
void mouse_passive(int x,int y)
{
	if(300-y>250 && 300-y<290 && ( (x-300>-280 && x-300<-240)||(x-300>-220 && x-300<-180)||(x-300>-160 && x-300<-120)||(x-300>-80 && x-300<-17)||(x-300>0 && x-300<90) ) )
		glutSetCursor(GLUT_CURSOR_INFO);
	else
		glutSetCursor(GLUT_CURSOR_INHERIT);

	if(vertex_count==0 || done==1||300-y>240)
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glLineWidth(3);
	glBegin(GL_LINES);
	for(int i=0;i<edge_count;++i)
	{	glVertex2i( lines[i][0] , lines[i][1] );	glVertex2i( lines[i][2] , lines[i][3] );	}

	glVertex2i(x_temp,y_temp);
	glVertex2i(x-300,300-y);
	glEnd();
	options(0);
}
void fill()
{
	sort();
	/*for(int i=0;i<edge_count;++i)
		cout<<edge[i][ymax]<<endl;*/
	for(int scanY=edge[0][ymax];scanY>edge[edge_count-1][ymin];--scanY)
	{
		for(int j=0;j<edge_count;++j)
		{
			if(edge[j][ymax]<scanY)
				break;
			if(edge[j][ymax]>scanY && edge[j][ymin]<scanY)
			{
				//cout<<"line : "<<j<<endl;
				intersect[intersect_count][1]=scanY;
				intersect[intersect_count][0]=edge[j][xmax]-((edge[j][ymax]-scanY)*(edge[j][xmax]-edge[j][xmin])/(edge[j][ymax]-edge[j][ymin]));
				intersect_count++;
			}
		}
	}
	if(FillColor==RED)
		glColor3f(1,0,0);
	else if(FillColor==GREEN)
		glColor3f(0,1,0);
	else if(FillColor==BLUE)
		glColor3f(0,0,1);

	glBegin(GL_LINES);
	for(int i=0;i<intersect_count;i+=2)
		{glVertex2i(intersect[i][0],intersect[i][1]);  glVertex2i(intersect[i+1][0],intersect[i+1][1]);}

	glEnd();

	glColor3f(0,0,0);
		glLineWidth(3);
		glBegin(GL_LINES);
		for(int i=0;i<edge_count;++i)
		{	glVertex2i( lines[i][0] , lines[i][1] );	glVertex2i( lines[i][2] , lines[i][3] );	}
		glEnd();
	glFlush();
}
void clear()
{
	edge_count=0;	vertex_count=0;	done=0;
	intersect_count=0;
	glClear(GL_COLOR_BUFFER_BIT);
	options(0);
}
void sort()
{
	for(int i=0;i<edge_count;++i)
	{
		for(int j=0;j<edge_count-1;++j)
		{
			if(edge[j][ymax]<edge[j+1][ymax])
				swap(edge[j],edge[j+1]);
		}
	}
}
void swap(int *a,int *b)
{
	int t;
	t=a[ymax];
	a[ymax]=b[ymax];
	b[ymax]=t;
	t=a[ymin];
	a[ymin]=b[ymin];
	b[ymin]=t;
	t=a[xmax];
	a[xmax]=b[xmax];
	b[xmax]=t;
	t=a[xmin];
	a[xmin]=b[xmin];
	b[xmin]=t;
	t=a[slope];
	a[slope]=b[slope];
	b[slope]=t;
}
#endif /* MYHEADERPOLYGONFILLING_H_ */
