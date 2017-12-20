#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int matrix[N][N];
int main(){
    int t ;
    cin >> t;
    while(t--){
        int n = 4 ;
        for(int i = 0 ;i < n; i++)
            for(int j = 0; j < n ; j++)
                cin >> matrix[i][j];
        int dir = 0;
        int top = 0 , bottom = n - 1 , left = 0 , right = n - 1;
        while(top <= bottom and left <= right){
            if(dir == 0){
                for(int i = left ; i <= right ; i++)
                    cout << matrix[top][i] << " ";
                top ++;
            }
            else if(dir == 1){
                for(int i = top ; i <= bottom ; i++)
                    cout << matrix[i][right] << " ";
                right--;
            }
            else if(dir == 2){
                for(int i = right ; i >= left ; i--)
                    cout << matrix[bottom][i] << " ";
                bottom --;
            }
            else{
                for(int i = bottom ; i >= top ; i--)
                    cout << matrix[i][left] << " ";
                left++;
            }
            dir = (dir + 1) % 4;
        }
    }
}
