 #include<iostream>  
 #include<vector>  
 #include<math.h>  
 #include<array>  
 using namespace std;  
 int main()  
 {  
    long n,m; 
      long answer=0,t,i;  
    long a,b,k,ii,jj,kk;  
   cin>>n>>m;  
   vector<long> array(n);  
   t = m;  
   while(t--){  
     cin>>a>>b>>k;  
     answer = answer + (abs(a-b)+1)*k;  
   }  
   answer = floor(answer/n);  
   cout<<answer<<endl;  
   return 0;  
 }  
