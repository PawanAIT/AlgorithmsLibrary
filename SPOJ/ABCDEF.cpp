    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        ios::sync_with_stdio(false);
        int t;
        int n;
        int b,c,d,e,f;
        int a[100];
        long long ans=0LL;
       vector<int> lhs,rhs;
        t=1;
        while(t--){
                cin>>n;
                int ncube=n*n*n;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
     
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        lhs.push_back(a[i]*a[j]+a[k]);
     
                        if(a[i]!=0){
                            rhs.push_back(a[i]*(a[j]+a[k]));    
                            
                        }
                        
                    }
                }
            }
            sort(lhs.begin(),lhs.end());
            sort(rhs.begin(),rhs.end());
            
            for(int i=0;i<lhs.size();i++){
                int ub=upper_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
                int lb=lower_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
                ans+=ub-lb;
            }
            cout<<ans;
        }
     
        return 0;
    }
     
