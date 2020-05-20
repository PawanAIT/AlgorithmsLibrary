//Source:http://codeforces.com/blog/entry/11337
#include <bits/stdc++.h>

using namespace std;

const int alph=256;

const int INF=1e9;
const int MPOW=16;
const int N=1<<MPOW-1;
const int N2=N<<1;
struct sg_tree
{
    int arr[N2];

    void build(vector<int> x,int n)
    {
        fill(arr,arr+N2,INF);
        for(int i=0;i<n;i++)
            arr[i+N]=x[i];
        for(int i=N-1;i>0;i--)
            arr[i]=min(arr[i<<1],arr[(i<<1)+1]);
    }

    int get_min(int c,int cl,int cr,int l,int r)
    {
        if(l==cl && r==cr)
            return arr[c];
        if(l>r)
            return INF;
        int cm=cl+cr>>1;
        return min(get_min(c<<1,cl,cm,l,min(r,cm)),get_min((c<<1)+1,cm+1,cr,max(l,cm+1),r));
    }

    int get_min(int l,int r)
    {
        return get_min(1,0,N-1,l,r);
    }
};

pair<vector<int>,vector<int>> compute(string &s)
{
    int n=s.size();
    int maxn=n+alph;

    vector<int> p(n),c(n),cnt(maxn,0);
    for(int i=0;i<n;i++)
        cnt[s[i]]++;
    for(int i=1;i<maxn;i++)
        cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)
        p[--cnt[s[i]]]=i;
    int cl=0;
    c[p[0]]=cl;
    for(int i=1;i<n;i++)
    {
        if(s[p[i]]!=s[p[i-1]])cl++;
        c[p[i]]=cl;
    }
    vector<int> lcp(n,0);
    for(int i=1;i<n;i++)
        lcp[i]=c[p[i]]==c[p[i-1]];
    vector<int> pn(n),cn(n),lcpn(n);
    vector<int> rpos(n),lpos(n);
    sg_tree rmq;
    int k=1;
    while(k<n)
    {
        fill(begin(cnt),end(cnt),0);
        for(int i=0;i<n;i++)
            rpos[c[p[i]]]=i;
        for(int i=n-1;i>=0;i--)
            lpos[c[p[i]]]=i;
        for(int i=0;i<n;i++)
        {
            pn[i]=p[i]-k;
            if(pn[i]<0)pn[i]+=n;
        }
        for(int i=0;i<n;i++)
            cnt[c[i]]++;
        for(int i=1;i<maxn;i++)
            cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[c[pn[i]]]]=pn[i];
        cl=0;
        cn[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            int m1=(p[i]+k)%n,m2=(p[i-1]+k)%n;
            if(c[p[i]]!=c[p[i-1]] || c[m1]!=c[m2])cl++;
            cn[p[i]]=cl;
        }
        rmq.build(lcp,n);
        for(int i=1;i<n;i++)
        {
            int a=p[i],b=p[i-1];
            if(c[a]!=c[b])
                lcpn[i]=lcp[lpos[c[a]]];
            else
            {
                int aa=(a+k)%n,bb=(b+k)%n;
                if(c[aa]==c[bb])
                    lcpn[i]=k<<1;
                else
                    lcpn[i]=k+rmq.get_min(lpos[c[bb]]+1,rpos[c[aa]]);
            }
            lcpn[i]=min(n,lcpn[i]);
        }
        copy(begin(cn),end(cn),begin(c));
        copy(begin(lcpn),end(lcpn),begin(lcp));
        k<<=1;
    }
    return {p,lcp};
}


struct suffix_tree
{
    struct edge
    {
        int from;
        int to;
        int next_vert;
        int suffix_here;
    };

    struct vertex
    {
        vector<edge> go;
    };

    string str;
    vector<vertex> data;

    static bool comp(const edge &b,const char &a)
    {
        return 1;
    }

    void build(string &s)
    {
        // Получим суффиксный массив строки, а также массив lcp
        pair<vector<int>,vector<int>> info=compute(s);
        vector<int> p=info.first,lcp=info.second;

        int n=s.size();
        str=s;

        // Будем хранить здесь стек рёбер, из которых мы ещё не вышли
        vector<int> p_vert;
        vector<int> p_edge;
        vector<int> p_dist;

        // Добавим первую строку в дерево
        vertex v;
        edge e;
        e.from=p[0];
        e.to=n;
        e.next_vert=-1;
        e.suffix_here=p[0];
        v.go.push_back(e);
        data.push_back(v);

        p_vert.push_back(0);
        p_edge.push_back(0);
        p_dist.push_back(0);

        for(int i=1;i<n;i++)
        {
            int c_lcp=lcp[i];
            // Поднимаемся до lcp.
            while(p_dist.back()>c_lcp)
            {
                // Найдём минимальный суффикс, покрывающий ребро для ответа на задачу. Опционально.
                edge &E=data[p_vert.back()].go[p_edge.back()];
                if(E.next_vert+1)
                {
                    int m=data[E.next_vert].go.size();
                    for(int j=0;j<m;j++)
                        E.suffix_here=min(E.suffix_here,data[E.next_vert].go[j].suffix_here);
                }
                // Удалим ребро из стека. Больше мы в него не вернёмся
                p_vert.pop_back();
                p_edge.pop_back();
                p_dist.pop_back();
            }
            vertex v;
            edge e;
            int c_v=p_vert.back();
            int c_e=p_edge.back();
            int At=data[c_v].go[c_e].from+c_lcp-p_dist.back(); // Индекс для разделения ребра

            p_dist.push_back(c_lcp);

            // Ребро, которое надо добавить
            e.next_vert=-1;
            e.suffix_here=p[i];
            e.from=p[i]+c_lcp;
            e.to=n;

            // Либо добавляем ребро к вершине, либо разделяем текущее
            if(At==data[c_v].go[c_e].from)
            {
                data[c_v].go.push_back(e);
                p_vert.push_back(c_v);
                p_edge.push_back(data[c_v].go.size()-1);
            }
            else
            {
                v.go.push_back(data[c_v].go[c_e]);
                v.go.back().from=At;
                v.go.push_back(e);
                data.push_back(v);
                data[c_v].go[c_e].next_vert=data.size()-1;
                data[c_v].go[c_e].to=At;
                p_vert.push_back(data.size()-1);
                p_edge.push_back(1);
            }
        }

        while(!p_dist.empty())
        {
            // Найдём минимальный суффикс, покрывающий ребро для ответа на задачу. Опционально.
            edge &E=data[p_vert.back()].go[p_edge.back()];
            if(E.next_vert+1)
            {
                int m=data[E.next_vert].go.size();
                for(int j=0;j<m;j++)
                    E.suffix_here=min(E.suffix_here,data[E.next_vert].go[j].suffix_here);
            }

            // Удалим ребро из стека. Больше мы в него не вернёмся
            p_vert.pop_back();
            p_edge.pop_back();
            p_dist.pop_back();
        }
    }

    int search_str(string &s)
    {
        int n=s.size();
        int cur_v=0;
        int cur_e;
        char t;

        for(int i=0;i<n;)
        {
            if(cur_v==-1)break;
            t=s[i];
            int cur_e;
            for(cur_e=0;cur_e<data[cur_v].go.size();cur_e++)
                if(str[data[cur_v].go[cur_e].from]>=t)break;
            for(int j=data[cur_v].go[cur_e].from;i<n && j<data[cur_v].go[cur_e].to;j++,i++)
                if(str[j]!=s[i])
                    i=n+1;
            if(i==n)
                return data[cur_v].go[cur_e].suffix_here;
            cur_v=data[cur_v].go[cur_e].next_vert;
        }
        return -1;
    }

    int print(int x)
    {
        if(x==-1)return 0;
        int ans=0;
        for(int i=0;i<data[x].go.size();i++)
            ans+=data[x].go[i].to-data[x].go[i].from+print(data[x].go[i].next_vert)-(data[x].go[i].to==str.size());
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    a+='#';
    suffix_tree sf;
    sf.build(a);
    cout<<sf.print(0)<<endl;
}
