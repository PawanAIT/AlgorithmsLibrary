#include<iostream>
#include<vector>


using namespace std;

 int rowandcoloumn(int x,int y,int n,int grid[9][9])
        {
        int i;
        for(i=0;i<9;i++)
            {
            if(grid[i][x]==n||grid[y][i]==n)
                return 0;

        }
        return 1;
    }

    int box(int x,int y,int n,int grid[9][9])
        {
        int i,j,k,l;
        if(i>=0&&i<3)i=0;
        else if(i>=3&&i<6)i=3;
        else if(i>=6&&i<9)i=6;
        if(j>=0&&j<3)i=0;
        else if(j>=3&&j<6)i=3;
        else if(j>=6&&j<9)i=6;
            k=i;l=j;

            for(;i<k+3;i++)
            for(;j<l+3;j++)
            if(grid[i][j]==n)
            return 0;

            return 1;

    }

int unused(int &x,int &y,int grid[9][9])
    {
    int i,j;
     for(i=0;i<9;i++)
        {
        for(j=0;j<9;j++)
            {
            if(grid[i][j]==0)
                return 1;
        }
     }
         return 0;
}
int sudoku_solve(int grid[9][9]) {
             int i,j;
            if(!unused(i,j,grid))
                return 1;

                int l;
                for(l=1;l<9;l++)
                    {
                    if(rowandcoloumn(i,j,l,grid)&&box(i,j,l,grid))
                        grid[i][j]=l;
                    if(sudoku_solve(grid))
                        return 1;

                    grid[i][j]=0;

                }

     return 0;
    //your logic here
}
int main(void) {
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);

    for(int j=0;j<9;j++) {
        cout<<'\n';
            for(int k=0;k<9;k++) {
                cout<<board[i][j];
            }
    }
    }
    return 0;
}
