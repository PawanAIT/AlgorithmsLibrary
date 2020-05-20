#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int r=1,c=1,num;
	for(int i=1; i<=k; i++){
		if(i==k){
			num = n*m - 2*(k-1);
			printf("%d ", num);
		}
		else{
			num = 2;
			printf("2 ");
		}
		while(num--){
			if(r%2){
				printf("%d %d ",r,c);
				c++;
				if(c==m+1){
					c=m;
					r++;
				}
			}
			else{
				printf("%d %d ",r, c);
				c--;
				if(c==0){
					c=1;
					r++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
