#include<bits/stdc++.h>
using namespace std;
struct node
{
	node* pos[26];
	int count[26];
};

node *getnode()
{
	node *temp=(node *)malloc(sizeof(node));

	for(int i=0;i<26;i++)
	{
		temp->pos[i]=NULL;
		temp->count[i]=0;
	}
	return temp;
}
void Add(node *root,string ss)
{
	for(int i=0;i<ss.size();i++)
	{
		if(root->pos[ss[i]-'a']==NULL)
		{
			root->pos[ss[i]-'a']=getnode();

			root->count[ss[i]-'a']++;
			root=root->pos[ss[i]-'a'];
		}
		else
		{
			root->count[ss[i]-'a']++;
			root=root->pos[ss[i]-'a'];
		}
	}
}
int Find(node *root,string ss)
{
	int i=0;
	for(;i<ss.size();i++)
	{
				if(root->pos[ss[i]-'a']==NULL)return 0;
			if(i==ss.size()-1)
			return root->count[ss[i]-'a'];
			else
			{
				root=root->pos[ss[i]-'a'];
			}
	}
    
    return 0;
	
}
int main()
{
	int t;
	scanf("%d",&t);
	node *root=getnode();
	while(t--)
	{
		string Query,str;
		cin>>Query>>str;
		if(Query=="add")
		{
			Add(root,str);
		}
		else
		{
			printf("%d\n",Find(root,str));
		}
	}
	
	return 0;
}
