#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<process.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
int * GetMemory(int n)
{
	return (int*)calloc(((n + 1)*n*n), sizeof(int));
}
void Init(int *Matrix, int n)
{
	int k = (n + 1)*n*n;
	for (int i = 0; i < k; i++)
		Matrix[i] = INT_MAX;
}
void displayFloyd(int *Matrix, int n)
{
	for (int k = 1; k <= n; k++)
	{
		printf("For K=%d\n", k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					printf("0 ");
				else
					if (Matrix[k*n*n + i*n + j] == INT_MAX)
						printf("~ ");
					else
						printf("%d ", Matrix[k*n*n + i*n + j]);
			}
			printf("\n");
		}
	}
}
void displayWarshall(int *Matrix, int n)
{
	for (int k = 1; k <= n; ++k)
	{
		printf("For K=%d\n", k);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					Matrix[k*n*n + i*n + j] = 1;
				}
				printf("%d%c", Matrix[k*n*n + i*n + j], " \n"[j == n - 1]);
			}
		}
	}
}
void Floyd(int *Matrix, int N)
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if ((Matrix[i*N + k] != INT_MAX&&Matrix[k*N + j] != INT_MAX) && Matrix[i*N + j]>Matrix[i*N + k] + Matrix[k*N + j])
				{
					Matrix[i*N + j] = Matrix[i*N + k] + Matrix[k*N + j];
				}
				Matrix[k*N*N + i*N + j] = Matrix[i*N + j];
			}
		}
	}
}
void Warshall(int *Matrix, int N)
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				Matrix[i*N + j] |= Matrix[i*N + k] & Matrix[k*N + j];
				Matrix[k*N*N + i*N + j] = Matrix[i*N + j];
			}
		}
	}
}
int main()
{
	int *AdjWar = NULL, *AdjFloyd = NULL, N;
	char ch;
	int L, R, W;
	while (1)
	{
		printf("1.Warshall\n2.Floyd	\n3.Exit\n");
		scanf(" %c", &ch);
		system("cls");
		switch (ch)
		{
		case '1':
			if (AdjWar != NULL)
				free(AdjWar);
			AdjWar = NULL;

			printf("Enter the Number of Node\n");
			scanf("%d", &N);
			AdjWar = GetMemory(N);

			printf("Enter the Edges and Weight...! To stop Entering edges enter -1 -1\n");
			while (1)
			{
				scanf("%d%d", &L, &R);
				if (L == -1 || R == -1)break;
				if (L<1 || L>N || R<1 || R>N)
				{
					printf("Out of Bound\n");
				}
				L--, R--;
				if (AdjWar[L*N + R] != 0)
				{
					printf("Edge already present\n");
				}
				AdjWar[L*N + R] = 1;
			}
			Warshall(AdjWar, N);
			displayWarshall(AdjWar, N);
			break;
		case '2':
			if (AdjFloyd != NULL)
				free(AdjFloyd);
			AdjFloyd = NULL;
			printf("Enter the Number of Node\n");
			scanf("%d", &N);
			AdjFloyd = GetMemory(N);
			Init(AdjFloyd, N);
			printf("Enter the Edges and Weight...! To stop Entering edges enter -1 -1 -1 \n");
			while (1)
			{
				scanf("%d%d%d", &L, &R, &W);
				if (L == -1 || R == -1)break;
				if (L<1 || L>N || R<1 || R>N)
				{
					printf("Out of Bound\n");
				}
				L--, R--;
				if (AdjFloyd[L*N + R] != INT_MAX)
				{
					printf("Edge already present\n");
				}
				AdjFloyd[L*N + R] = W;
			}
			Floyd(AdjFloyd, N);
			displayFloyd(AdjFloyd, N);
			break;
		case '3':
			return 0;

		}

	}

}
