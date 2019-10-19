#include "stdc++.h"
using namespace std;
class UnionFind
{
private:
	vector<int> parent;
public :
	UnionFind(int N) {
		parent.resize(N + 1);
		iota(parent.begin(), parent.end(), 0);
	}
	int root(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	void merge(int x, int y) {
		int xRoot = root(x);
		int yRoot = root(y);
		if (xRoot != yRoot) {
			parent[xRoot] = yRoot;
		}
	}
	bool Connected(int x, int y) {
		return root(x) == root(y);
	}
};
class Solution {
	int n, m;
	bool IsOnBoundary(int x, int y) {
		return (x == 0) || (y == 0) || (x == n - 1) || (y == m - 1);
	}
	int CoordinateMapper(int x, int y) {
		return x * m + y;
	}
	int dummyNode() {
		return n * m + 1;
	}
public:
	void solve(vector<vector<char>>& board) {
		n = board.size();
		if(n > 0)
			m = board[0].size();
		UnionFind uf(n * m + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O' && IsOnBoundary(i, j)) {
					uf.merge(CoordinateMapper(i, j), dummyNode());
				}
				else if (board[i][j] == 'O') {
					if (board[i - 1][j] == 'O')
						uf.merge(CoordinateMapper(i, j), CoordinateMapper(i - 1, j));
					if (board[i + 1][j] == 'O')
						uf.merge(CoordinateMapper(i, j), CoordinateMapper(i + 1, j));
					if (board[i][j - 1] == 'O')
						uf.merge(CoordinateMapper(i, j), CoordinateMapper(i, j - 1));
					if (board[i][j + 1] == 'O')
						uf.merge(CoordinateMapper(i, j), CoordinateMapper(i, j + 1));
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!uf.Connected(CoordinateMapper(i, j), dummyNode())) {
					board[i][j] = 'X';
				}
			}
		}
	}
};
int main() {
	Solution s;
	vector<vector<char>> board(
		{
			{'X','X','X','X'},
			{'X','O','O','X'},
			{'X','X','O','X'},
			{'X','O','X','X'} 
		});
	s.solve(board);
	for (auto x : board) {
		for(auto y : x){
			cout << y << " ";
		}
		cout << endl;
	}
	int x;
	cin >> x;
}