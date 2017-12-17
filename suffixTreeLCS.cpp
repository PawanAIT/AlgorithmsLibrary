#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 
struct State {  
    State *pre,*go[26];  
    int step;  
    void clear() {  
        pre=0;  
        step=0;  
        memset(go,0,sizeof(go));  
    }  
} *root,*last;    
State statePool[N * 2],*cur;  
  
void init() {  
    cur=statePool;  
    root=last=cur++;  
    root->clear();  
}  
  
void Insert(int w) {  
    State *p=last;  
    State *np=cur++;  
    np->clear();  
    np->step=p->step+1;  
    while(p&&!p->go[w]) p->go[w]=np,p=p->pre;  
    if(p==0) np->pre=root;  
    else {  
        State *q=p->go[w];  
        if(p->step+1==q->step) np->pre=q;  
        else {  
            State *nq=cur++;  
            nq->clear();  
            memcpy(nq->go,q->go,sizeof(q->go));  
            nq->step=p->step+1;  
            nq->pre=q->pre;  
            q->pre=nq;  
            np->pre=nq;  
            while(p&&p->go[w]==q) p->go[w]=nq, p=p->pre;  
        }  
    }  
    last=np;  
}  
 
int lcs(string B) {
    int m;  
    m=B.size(); 
    int ans = 0, len = 0, bestpos = 0;  
    State *p=root;  
    for(int i = 0; i < m; i++) {  
        int x = B[i]-'a';  
        if(p->go[x]) {  
            len++;  
            p = p->go[x];  
        } else {  
            while (p && !p->go[x]) p = p->pre;  
            if(!p) p = root, len = 0;  
            else   len = p->step+1, p = p->go[x];  
        }
        if (len > ans)
            ans = len, bestpos = i;
    }  
    return ans;
}

int main(){
    init();
    string a , b;
    cin >> a >> b;
    for(int i = 0; i < a.size() ; i++){
        Insert(a[i] - 'a');
    }
    cout << lcs(b);
}
