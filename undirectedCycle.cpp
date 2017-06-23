/* Contest   : SWERC 97
 * Problem E : Pushing Boxes
 * Method    : generalized breadth-first search
 * Author    : Mark Dettinger
 */

#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define oo 1000000000

typedef struct { char mani,manj,boxi,boxj; int d; } state;

FILE* input;
int kase=0;
int rows,cols;
char maze[32][32];
char color[32][32][32][32];
char pred[32][32][32][32];
state queue[160008];
int phead,whead,tail;

void skip_line() { while (fgetc(input)!='\n'); }

void enqueue (int mi, int mj, int bi, int bj, int dist)
{
  color[mi][mj][bi][bj] = GRAY;
  queue[tail].mani = mi;
  queue[tail].manj = mj;
  queue[tail].boxi = bi;
  queue[tail].boxj = bj;
  queue[tail].d = dist;
  tail++;
}

void dequeue (int *head, int *mi, int *mj, int *bi, int *bj, int *dist)
{
  *mi = queue[*head].mani;
  *mj = queue[*head].manj;
  *bi = queue[*head].boxi;
  *bj = queue[*head].boxj;
  *dist = queue[*head].d;
  (*head)++;
}

void visit (int mi, int mj, int bi, int bj, int dist, char from)
{
  if (mi<0 || mi>= rows || mj<0 || mj>=cols ||
      bi<0 || bi>= rows || bj<0 || bj>=cols ||
      (mi==bi && mj==bj) || 
      maze[mi][mj]=='#' || maze[bi][bj]=='#' ||
      color[mi][mj][bi][bj]!=WHITE) return;
  pred[mi][mj][bi][bj] = from;
  enqueue(mi,mj,bi,bj,dist);
}

void printpath (int mi, int mj, int bi, int bj)
{
  switch (pred[mi][mj][bi][bj])
    {
    case 'n' : printpath(mi+1,mj,bi,bj);   printf("n"); break;
    case 's' : printpath(mi-1,mj,bi,bj);   printf("s"); break;
    case 'e' : printpath(mi,mj-1,bi,bj);   printf("e"); break;
    case 'w' : printpath(mi,mj+1,bi,bj);   printf("w"); break;
    case 'N' : printpath(mi+1,mj,bi+1,bj); printf("N"); break;
    case 'S' : printpath(mi-1,mj,bi-1,bj); printf("S"); break;
    case 'E' : printpath(mi,mj-1,bi,bj-1); printf("E"); break;
    case 'W' : printpath(mi,mj+1,bi,bj+1); printf("W"); break;
    } 
}

int main()
{ 
  int mani,manj,boxi,boxj,targeti,targetj;
  int dist,i,j,ii,jj;

  input = fopen("pushing.in","r");
  while (1)
    {
      /* 1. read input */

      fscanf(input,"%d %d",&rows,&cols);
      if (rows==0 && cols==0) break;
      skip_line();
      for (i=0; i<rows; i++)
	fgets(maze[i],32,input);
      for (i=0; i<rows; i++)
	for (j=0; j<cols; j++)
	  {
	    for (ii=0; ii<rows; ii++)
	      for (jj=0; jj<cols; jj++)
		color[i][j][ii][jj] = WHITE;
	    if (maze[i][j]=='S') { mani=i;    manj=j;    }
	    if (maze[i][j]=='B') { boxi=i;    boxj=j;    }
	    if (maze[i][j]=='T') { targeti=i; targetj=j; }
	  }

      /* 2. generalized breadth-first search */

      phead = whead = tail = 0;
      visit(mani,manj,boxi,boxj,0,'-');
      while (phead!=tail)
	if (whead!=tail && queue[whead].d+1<queue[phead].d+10000)
	  {
	    dequeue(&whead,&mani,&manj,&boxi,&boxj,&dist);
	    visit(mani-1,manj,boxi,boxj,dist+1,'n');
	    visit(mani+1,manj,boxi,boxj,dist+1,'s');
	    visit(mani,manj-1,boxi,boxj,dist+1,'w');
	    visit(mani,manj+1,boxi,boxj,dist+1,'e');
	  }
	else
	  {
	    dequeue(&phead,&mani,&manj,&boxi,&boxj,&dist);
	    if (boxi==targeti && boxj==targetj) break;
	    if (mani-1==boxi && manj==boxj)
	      visit(mani-1,manj,boxi-1,boxj,dist+10000,'N');
	    if (mani+1==boxi && manj==boxj)
	      visit(mani+1,manj,boxi+1,boxj,dist+10000,'S');
	    if (mani==boxi && manj-1==boxj)
	      visit(mani,manj-1,boxi,boxj-1,dist+10000,'W');
	    if (mani==boxi && manj+1==boxj)
	      visit(mani,manj+1,boxi,boxj+1,dist+10000,'E');	 
	  }

      /* 3. generate output */

      printf("Maze #%d\n",++kase);
      if (boxi==targeti && boxj==targetj)
	printpath(mani,manj,targeti,targetj);
      else
	printf("Impossible.");
      printf("\n\n");
    }
  return 0;
}