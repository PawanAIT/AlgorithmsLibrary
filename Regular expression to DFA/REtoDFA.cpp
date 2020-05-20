#include <bits/stdc++.h>
using namespace std;
set<char> inp;
set<int> followpos[10];
map<int, char> position;
int pos = 1;
set<int> operator +(set<int> a, set<int>b)
{
	a.insert(b.begin(), b.end());
	return a;
}
struct node
{
	int pos;
	char ch;
	bool nullable;
	set<int>firstpos, lastpos;
	node *left, *right;
};

node *Get(int pos, char ch)
{
	node *temp = new node();
	temp->left = temp->right = NULL;
	temp->pos = pos;
	temp->ch = ch;
	temp->nullable = false;
	temp->firstpos.clear(), temp->lastpos.clear();
	return temp;
}
void postfix(node *root)
{
	if (root)
	{
		postfix(root->left);
		postfix(root->right);
		cout << root->pos << "    " << root->ch << setw(10) << root->nullable << setw(10);
		cout << " { ";
		for (auto i : root->firstpos)
			cout << i << setw(2);
		cout << "} " << setw(20) << " {";
		for (auto i : root->lastpos)
			cout << i << "  ";
		cout << "} " << endl;
	}
}
node* create(string str)
{
	stack<node *>st;
	node *rand;
	for (int i = 0; i<str.size(); i++)
	{
		if (isalpha(str[i]) || str[i] == '#')
		{

			rand = Get(pos, str[i]);
			rand->firstpos.insert(pos);
			rand->lastpos.insert(pos);
			if (str[i] != '#')
			{
				inp.insert(str[i]);
				position[pos] = str[i];
			}
			pos++;
			st.push(rand);
		}
		else if (str[i] == '*')
		{
			rand = st.top();
			st.pop();
			node* temp = Get(0, str[i]);
			temp->firstpos = rand->firstpos;
			temp->lastpos = rand->lastpos;
			temp->left = rand;
			temp->nullable = true;
			st.push(temp);
			for (auto H : temp->lastpos)
				followpos[H] = followpos[H] + temp->firstpos;

		}
		else if (str[i] == '|' || str[i] == '/')
		{
			node *right = st.top(); st.pop();
			node *left = st.top(); st.pop();
			node *temp = Get(0, str[i]);
			temp->nullable = left->nullable | right->nullable;
			temp->firstpos = left->firstpos + right->firstpos;
			temp->lastpos = left->lastpos + right->lastpos;
			temp->left = left;
			temp->right = right;
			st.push(temp);
		}
		else
		{
			node *right = st.top(); st.pop();
			node *left = st.top(); st.pop();
			node *temp = Get(0, str[i]);
			temp->nullable = left->nullable & right->nullable;
			temp->firstpos = left->nullable ? left->firstpos + right->firstpos : left->firstpos;
			temp->lastpos = right->nullable ? left->lastpos + right->lastpos : right->lastpos;
			temp->left = left;
			temp->right = right;
			st.push(temp);
			for (auto H : left->lastpos)
				followpos[H] = followpos[H] + right->firstpos;
		}
	}
	return st.top();
}
void dfa(node *root)
{
	set<int> Union;
	map<set<int>, char> redundant;
	map<set<int>, map<char, set<int> > > Final;
	int k = 1, cur = 1;
	set<int>states[10];
	char ch = 'A';
	states[cur++] = root->firstpos;
	redundant[root->firstpos] = ch++;
	while (1)
	{
		for (auto i : inp)
		{
			for (auto pos : states[k])
			{

				if (position[pos] == i)
					Union = Union + followpos[pos];
				

			}
			if (Union.size()>0 && redundant[Union] == 0)
			{
				redundant[Union] = ch++;
				states[cur++] = Union;

			}

			Final[states[k]][i] = Union;
			Union.clear();
		}
		if (k == cur - 1)
			break;
		k++;
	}
	for (auto i : Final)
	{
		cout << "{ ";
		for (auto j : i.first)
			cout << j << " ";
		cout << " } ";
		for (auto h : i.second)
		{
			cout << h.first << "  { ";
			for (auto m : h.second)
				cout << m << " ";
			cout << "  }  ";

		}
		cout << endl;

	}

}
int main()
{
	string str("ab|*a.b.b.#.");
	node *tree = create(str);
	cout << "Pos   name    nullable  firstpos   lastpos \n";
	postfix(tree);

	cout << "Follow position\n";
	for (int i = 1; i<pos - 1; i++)
	{
		cout << i << "        ";
		for (auto j : followpos[i])
			cout << j << " ";
		cout << endl;
	}
	dfa(tree);
}
