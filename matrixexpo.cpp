#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix
{
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
   	{
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const 
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % MOD;
                }
            }
        return Matrix(result);
    }

};

Matrix fx(Matrix m, int power)
{
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
	Matrix M({
			{1,1},
			{1,0} 
             });
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Matrix ans = fx(M,n+1);
		printf("%d\n",ans.mat[0][0]);
	}
	
	return 0;
}