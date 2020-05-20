#include<bits/stdc++.h>
using namespace std;
struct MOT
{
	string Name, Class, Opcode;
	int length;
}mot[20];
struct ConditionTable
{
	string Name;
	int Opcode;
}CT[10];

struct SymbolTable
{
	string Name;
	int SNo, Addr;
}ST[100];
struct LiteralTable
{
	string Name;
	int SNo, Addr;
}LT[100];
struct RegTable
{
	string Name;
	int Opcode;
}RT[5];
void InitializeAllTables()
{
	for (int i = 1; i <= 17; i++)
	{
		cin >> mot[i].Name >> mot[i].Opcode >> mot[i].Class;
		mot[i].length = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		cin >> RT[i].Name >> RT[i].Opcode;
	}
	for (int i = 1; i <= 6; i++)
	{
		cin >> CT[i].Name >> CT[i].Opcode;
	}
}
int IsInMOT(string Name)
{
	for (int i = 1; i <= 17; i++)
		if (Name == mot[i].Name)return i;
	return -1;
}
int IsInRegTable(string Name)
{
	for (int i = 1; i <= 4; i++)
		if (Name == RT[i].Name)return i;
	return -1;
}
int IsInSymbolTable(string Name, int n)
{
	for (int i = 1; i <= n; i++)
		if (Name == ST[i].Name)return i;
	return -1;
}
int IsInConditionTable(string Name)
{
	for (int i = 1; i <= 6; i++)
		if (Name == CT[i].Name)return i;
	return -1;
}
int IsInLiteralTable(string Name, int n)
{
	for (int i = n; i > 0; i--)
		if (Name == LT[i].Name)return i;
	return -1;
}
void DispLiteralTable(int n)
{
	for (int i = 1; i < n; i++)
		cout << LT[i].SNo << " " << LT[i].Name << " " << LT[i].Addr << endl;
}
void DispSymbolTable(int n)
{
	for (int i = 1; i < n; i++)
		cout << ST[i].SNo << " " << ST[i].Name << " " << ST[i].Addr << endl;
}

int IsAssemblyDirective(vector<string> &v)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] == "START" || v[i] == "END" || v[i] == "LTORG" || v[i] == "ORIGIN" || v[i] == "EQU")
			return 1;
	return 0;
}
int Quotetodigit(string ss)
{
	int ans = 0;
	for (int i = 1; i < ss.size() - 1; i++)
	{
		ans = ans * 10 + ss[i] - '0';
	}
	return ans;
}
int stoi(string ss)
{
	int ans = 0;
	for (int i = 0; i < ss.size(); i++)
	{
		ans = ans * 10 + ss[i] - '0';
	}
	return ans;
}
bool Checkifuninialized(int SYMTC)
{
	bool ok = false;
	for (int i = 1; i <= SYMTC; i++)
		if (ST[i].Addr == -1)
		{
			cout << ST[i].Name << " Symbol used But not defined \n";
			ok = true;
		}
	return ok;
}
int main()
{
	freopen("InitializeTables.txt", "r+", stdin);
	freopen("PassOneOutput.txt", "w+", stdout);
	InitializeAllTables();
	int LC = 0, n, index = 0, SYMTC = 1, LITTC = 1;
	cin.clear();
	freopen("AssemblerInput.txt", "r+", stdin);
	string ss;
	while (getline(cin, ss))
	{
		vector<string> v;
		istringstream iss(ss);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(v));
		if (IsAssemblyDirective(v) == 0)
		{
			LC++;
			cout << LC << " ";
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != ",")
			{
				index = IsInMOT(v[i]);
				if (index == -1)
				{
					index = IsInRegTable(v[i]);
					if (index == -1)
					{
						index = IsInConditionTable(v[i]);
						if (index == -1)
						{
							index = IsInLiteralTable(v[i], LITTC);
							if (v[i][0] == '=' && (index == -1 || LT[index].Addr != -1)) // check if Literal and already not present in table?
							{

								LT[LITTC].SNo = LITTC;
								LT[LITTC].Name = v[i];
								LT[LITTC].Addr = -1;
								LITTC++;
								//literal table count increment
							}

							index = IsInSymbolTable(v[i], SYMTC);
							if (isalpha(v[i][0]) && (i == 0 || i == v.size() - 1) && index == -1) //check if it is symbol 
							{
								ST[SYMTC].SNo = SYMTC;
								ST[SYMTC].Name = v[i];
								if (i == 0)
									ST[SYMTC].Addr = LC;
								else
								{
									ST[SYMTC].Addr = -1;
								}
								SYMTC++;
							}
						}
						else
						{
							cout << CT[index].Opcode << " ";
						}
					}
					else
					{
						cout << RT[index].Opcode << " ";
					}
				}
				else
				{
					cout << "(" << mot[index].Class << ',' << mot[index].Opcode << ")" << " ";
				}
				if (i > 0 && v[i - 1] == "START"&&isdigit(v[i][0]))
				{
					cout << "(C," << v[i] << ")" << " ";
					LC = stoi(v[i]) - 1; //converting string to int
				}
				if (v[i] == "LTORG" || v[i] == "END")
				{
					for (int i = 1; i <= LITTC; i++)
					{
						if (LT[i].Addr == -1)
						{
							LC++;
							LT[i].Addr = LC;
						}
					}
				}
				index = IsInSymbolTable(v[i], SYMTC);
				if (index != -1)
				{
					if (i == 0)
						ST[index].Addr = LC;
					else
						cout << "(S," << ST[index].SNo << ")" << " ";
				}
				index = IsInLiteralTable(v[i], LITTC);
				if (index != -1)
				{
					cout << "(L," << LT[index].SNo << ")" << " ";
				}
				if (i > 0 && v[i - 1] == "DC"&&isdigit(v[i][1]))
				{
					cout << "(C," << v[i] << ")" << " ";
					LC += Quotetodigit(v[i]) - 1;
				}
				if (i > 0 && v[i - 1] == "DS"&&isdigit(v[i][0]))
				{
					cout << "(C," << v[i] << ")" << " ";
				}
				if (v[i] == "EQU")
				{
					int right = IsInSymbolTable(v[i + 1], SYMTC);
					int left = IsInSymbolTable(v[i - 1], SYMTC);
					if (right != -1 && left != -1)
					{
						ST[left].Addr = ST[right].Addr;
					}
				}
			}
		}
		cout << endl;
	}
	cin.clear();
	cout.clear();
	freopen("Symbol_Litral_Table.txt", "w+", stdout);
	
	DispSymbolTable(SYMTC);
	DispLiteralTable(LITTC);
	if (Checkifuninialized(SYMTC))return 0;
	cin.clear();
	freopen("PassOneOutput.txt", "r+", stdin);
	freopen("PassTwoOutput.txt", "w+", stdout);
	while (getline(cin, ss))
	{
		vector<string> v;
		istringstream iss(ss);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(v));
		for (int i = 0; i < v.size(); i++)
		{
			if (isdigit(v[i][0]))
				cout << v[i] << " ";
			else if (v[i][1] == 'D' || v[i][1] == 'I')
				cout << v[i][4] << v[i][5] << " ";
			else if (v[i][1] == 'L')
				cout << LT[v[i][3] - '0'].Addr << " ";
			else if (v[i][1] == 'S')
				cout << ST[v[i][3] - '0'].Addr << " ";
			else
				cout << "---  ";
		}
		cout << endl;
	}
	return 0;
}