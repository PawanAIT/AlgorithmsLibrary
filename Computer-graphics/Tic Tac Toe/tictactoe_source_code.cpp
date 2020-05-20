/*

 tictactoe_source_code.cpp

   Created on: 06-Mar-2015
       Author: rupinder singh

 */

#include<iostream>
#include<math.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
using namespace std;
#define h 300
#define w 300
#define white 1,1,1
#define red 1,0,0
#define blue 0,0,1
int toggle=1;
int a[10]={0};
int gameOver=0;

void win();
void put(int a);
void initialize();
void circle(int x,int y);
void mouse(int button,int state,int x,int y);
void keyboard(unsigned char key,int x,int y);
int chk(int x,int y);
void instructions();

int main(int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (h, w);
	glutInitWindowPosition (500,100);
	glutDisplayFunc(instructions);
	glutCreateWindow ("TIC TAC TOE");
	instructions();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop ();

	return 0;
}
void put(int a)
{
	cout<<"switch="<<a<<endl;
	switch(a)
	{
	case 1:
			if(toggle==1)
			{
			glLineWidth(10);
			glColor3f(red);
			glBegin(GL_LINES);
				glVertex2f(-65,65);
				glVertex2f(-115,115);
				glVertex2f(-115,65);
				glVertex2f(-65,115);
			glEnd();
			toggle=0;
			}
			else
			{
				circle(-90,90);
				toggle=1;
			}
		break;
	case 2:
					if(toggle==1)
					{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(-25,65);
						glVertex2f(25,115);
						glVertex2f(-25,115);
						glVertex2f(25,65);
					glEnd();
					toggle=0;
					}
					else
					{
						circle(0,90);
						toggle=1;
					}break;
	case 3:
		if(toggle==1)
		{
			glLineWidth(10);
			glColor3f(red);
			glBegin(GL_LINES);
				glVertex2f(65,65);
				glVertex2f(115,115);
				glVertex2f(65,115);
				glVertex2f(115,65);
			glEnd();
			toggle=0;
		}
		else
		{
			circle(90,90);
			toggle=1;
		}break;
	case 4:
				if(toggle==1)
				{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(-65,-25);
						glVertex2f(-115,25);
						glVertex2f(-115,-25);
						glVertex2f(-65,25);
					glEnd();
					toggle=0;
				}
				else
				{
					circle(-90,0);
					toggle=1;
				}break;
	case 5:
				if(toggle==1)
				{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(-25,-25);
						glVertex2f(25,25);
						glVertex2f(-25,25);
						glVertex2f(25,-25);
					glEnd();
					toggle=0;
				}
				else
				{
					circle(0,0);
					toggle=1;
				}break;
	case 6:
			if(toggle==1)
			{
				glLineWidth(10);
				glColor3f(red);
				glBegin(GL_LINES);
					glVertex2f(65,-25);
					glVertex2f(115,25);
					glVertex2f(115,-25);
					glVertex2f(65,25);
				glEnd();
				toggle=0;
			}
			else
			{
				circle(90,0);
				toggle=1;
			}break;
	case 7:
				if(toggle==1)
				{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(-65,-65);
						glVertex2f(-115,-115);
						glVertex2f(-115,-65);
						glVertex2f(-65,-115);
					glEnd();
					toggle=0;
				}
				else
				{
					circle(-90,-90);
					toggle=1;
				}break;
	case 8:
				if(toggle==1)
				{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(-25,-65);
						glVertex2f(25,-115);
						glVertex2f(25,-65);
						glVertex2f(-25,-115);
					glEnd();
					toggle=0;
				}
				else
				{
					circle(0,-90);
					toggle=1;
				}break;
	case 9:
				if(toggle==1)
				{
					glLineWidth(10);
					glColor3f(red);
					glBegin(GL_LINES);
						glVertex2f(65,-65);
						glVertex2f(115,-115);
						glVertex2f(115,-65);
						glVertex2f(65,-115);
					glEnd();
					toggle=0;
				}
				else
				{
					circle(90,-90);
					toggle=1;
				}break;
	}

	glFlush();

	win();

}
void initialize()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);

	glLineWidth(4);
	glColor3f(white);
	glBegin(GL_LINES);
		glVertex2f(-50,130);
		glVertex2f(-50,-130);
		glVertex2f(50,130);
		glVertex2f(50,-130);

		glVertex2f(-130,50);
		glVertex2f(130,50);
		glVertex2f(-130,-50);
		glVertex2f(130,-50);
	glEnd();
	glFlush();
}

void circle(int x,int y)
{
	glLineWidth(5);
	glColor3f(blue);
		const int sides = 360;
		const double radius = 30;
		glBegin(GL_LINE_LOOP);

	   // glVertex2f(x,y);
		  for (int a = 0; a < 360; a += 360 / sides)
		  {
		    double heading = a * 3.1415926535897932384626433832795 / 180;
		    glVertex2f(x-(cos(heading) * radius), y-(sin(heading) * radius));
		  }

		glEnd();
		glFlush();
}

void mouse(int button,int state,int x,int y)
{
	if(a[chk(x-150,150-y)]!=0)
		return;
	if(state==GLUT_DOWN && gameOver==0)
	if(button==GLUT_LEFT_BUTTON)
	{
		if(toggle==1)
			a[chk(x-150,150-y)]=1;
		else if(toggle==0)
				a[chk(x-150,150-y)]=2;
		put(chk(x-150,150-y));
	}
}
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)
		exit(0);
	if(key==32)
		{cout<<"clear\n"; initialize();
		for(int i=1;i<10;++i)
		a[i]=0;
		gameOver=0;
		}
	if(key==13)
		initialize();
}
int chk(int x,int y)
{
	if(x<-50 && y>50)
			return 1;
	if(x>-50 && x<50 && y>50)
			return 2;
	if(x>50 && y>50)
			return 3;
	if(x<-50 && y<50 && y>-50)
			return 4;
	if(x>-50 && x<50 && y<50 && y>-50)
			return 5;
	if(x>50 && y<50 && y>-50)
			return 6;
	if(x<-50 && y<-50)
			return 7;
	if(x>-50 && x<50 && y<-50)
			return 8;
	if(x>50 && y<-50)
			return 9;
	return 0;
}
void win()
{
	if(a[1]==1 && a[2]==1 && a[3]==1)
	{	glColor3f(red);		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex2f(-120,80);
			glVertex2f(130,100);
		glEnd();		glFlush();		gameOver=1;		return;	}
	if(a[1]==2 && a[2]==2 && a[3]==2)
		{	glColor3f(blue);	glLineWidth(5);
			glBegin(GL_LINES);
				glVertex2f(-135,100);
				glVertex2f(130,87);
			glEnd();	glFlush();	gameOver=1;			return;		}
	if(a[4]==1 && a[5]==1 && a[6]==1)
		{	glColor3f(red);		glLineWidth(5);		glBegin(GL_LINES);
				glVertex2f(-120,10);
				glVertex2f(130,-5);
			glEnd();	glFlush();	gameOver=1;		return;		}
		if(a[4]==2 && a[5]==2 && a[6]==2)
			{	glColor3f(blue);	glLineWidth(5);
				glBegin(GL_LINES);
					glVertex2f(-125,3);
					glVertex2f(135,-5);
				glEnd();	glFlush();	gameOver=1;		return;			}
		if(a[7]==1 && a[8]==1 && a[9]==1)
			{	glColor3f(red);		glLineWidth(5);
				glBegin(GL_LINES);
					glVertex2f(-120,-100);
					glVertex2f(130,-90);
				glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[7]==2 && a[8]==2 && a[9]==2)
				{	glColor3f(blue);	glLineWidth(5);
					glBegin(GL_LINES);
						glVertex2f(-135,-100);
						glVertex2f(130,-80);
					glEnd();	glFlush();	gameOver=1;	return;	}

			if(a[1]==1 && a[4]==1 && a[7]==1 )
			{	glColor3f(red);	glLineWidth(5);
				glBegin(GL_LINES);
					glVertex2f(-95,125);
					glVertex2f(-85,-120);
				glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[2]==1 && a[5]==1 && a[8]==1 )
			{	glColor3f(red);	glLineWidth(5);
				glBegin(GL_LINES);
					glVertex2f(-6,115);
					glVertex2f(5,-120);
				glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[3]==1 && a[6]==1 && a[9]==1 )
			{	glColor3f(red);	glLineWidth(5);
				glBegin(GL_LINES);
					glVertex2f(100,130);
					glVertex2f(90,-120);
				glEnd();	glFlush();	gameOver=1;	return;	}
						if(a[1]==2 && a[4]==2 && a[7]==2 )
						{	glColor3f(blue);	glLineWidth(5);
							glBegin(GL_LINES);
								glVertex2f(-95,125);
								glVertex2f(-85,-120);
							glEnd();	glFlush();	gameOver=1;	return;	}
						if(a[2]==2 && a[5]==2 && a[8]==2 )
						{	glColor3f(blue);	glLineWidth(5);
							glBegin(GL_LINES);
								glVertex2f(-6,115);
								glVertex2f(5,-120);
							glEnd();	glFlush();	gameOver=1;	return;	}
						if(a[3]==2 && a[6]==2 && a[9]==2 )
						{	glColor3f(blue);	glLineWidth(5);
							glBegin(GL_LINES);
								glVertex2f(100,130);
								glVertex2f(90,-120);
							glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[1]==1 && a[5]==1 && a[9]==1 )
			{	glColor3f(red);	glLineWidth(6);
				glBegin(GL_LINES);
					glVertex2f(-135,110);
					glVertex2f(120,-100);
				glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[1]==2 && a[5]==2 && a[9]==2 )
			{	glColor3f(blue);	glLineWidth(6);
				glBegin(GL_LINES);
					glVertex2f(-120,115);
					glVertex2f(135,-110);
				glEnd();	glFlush();	gameOver=1;	return;	}

			if(a[3]==1 && a[5]==1 && a[7]==1 )
			{	glColor3f(red);	glLineWidth(6);
				glBegin(GL_LINES);
					glVertex2f(100,125);
					glVertex2f(-90,-100);
				glEnd();	glFlush();	gameOver=1;	return;	}
			if(a[3]==2 && a[5]==2 && a[7]==2 )
			{	glColor3f(blue);	glLineWidth(6);
				glBegin(GL_LINES);
					glVertex2f(120,115);
					glVertex2f(-135,-110);
				glEnd();	glFlush();	gameOver=1;	return;	}
}
void instructions()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(white);
	glRasterPos2f(-0.41,0.4);
	char x1[]={"TIC TAC TOE"};
	for(int i=0;x1[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,x1[i]);
	glRasterPos2f(-0.5,0.1);
	char x2[]={"SPACE : new game"};
	for(int i=0;x2[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,x2[i]);
	glRasterPos2f(-0.5,-0.0);
	char x3[]={"ESC : exit"};
	for(int i=0;x3[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,x3[i]);
	glRasterPos2f(-0.55,-0.2);
	char x4[]={"Press Enter to continue"};
	for(int i=0;x4[i]!='\0';++i)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,x4[i]);


	glFlush();
}

