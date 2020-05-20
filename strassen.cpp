#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<process.h>
int * GetMemory(int n)
{
	return (int*)calloc((n*n), sizeof(int));
}
void BruteMatrixAddition(int *MatrixA, int *MatrixB, int *MatrixC, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			MatrixC[i*n + j] = MatrixA[i*n + j] + MatrixB[i*n + j];

		}
	}
}
void BruteMatrixSubtraction(int *MatrixA, int *MatrixB, int *MatrixC, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			MatrixC[i*n + j] = MatrixA[i*n + j] - MatrixB[i*n + j];
		}
	}
}
void strassen(int *a, int *b, int *c, int size) {
	//if (size == 0)return;
	if (size == 1)
	{
		c[0] = a[0] * b[0];
		return;
	}
	int n = size / 2;
	int *a11 = GetMemory(n), *a12 = GetMemory(n), *a21 = GetMemory(n), *a22 = GetMemory(n);
	int *b11 = GetMemory(n), *b12 = GetMemory(n), *b21 = GetMemory(n), *b22 = GetMemory(n);
	int *c11 = GetMemory(n), *c12 = GetMemory(n), *c21 = GetMemory(n), *c22 = GetMemory(n);
	int *p1 = GetMemory(n), *p2 = GetMemory(n), *p3 = GetMemory(n), *p4 = GetMemory(n), *p5 = GetMemory(n),
		*p6 = GetMemory(n), *p7 = GetMemory(n);
	int *IntermediateA = GetMemory(n);
	int *IntermediateB = GetMemory(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a11[i*n + j] = a[i*size + j];
			a12[i*n + j] = a[i*size + j + n];
			a21[i*n + j] = a[(i + n)*size + j];
			a22[i*n + j] = a[(i + n)*size + j + n];
			b11[i*n + j] = b[i*size + j];
			b12[i*n + j] = b[i*size + j + n];
			b21[i*n + j] = b[(i + n)*size + j];
			b22[i*n + j] = b[(i + n)*size + j + n];
		}
	}

	BruteMatrixAddition(a11, a22, IntermediateA, n);	// a11 + a22
	BruteMatrixAddition(b11, b22, IntermediateB, n);	// b11 + b22
	strassen(IntermediateA, IntermediateB, p1, n);		// p1 = (a11+a22) * (b11+b22)
	BruteMatrixAddition(a21, a22, IntermediateA, n);	// a21 + a22
	strassen(IntermediateA, b11, p2, n);				// p2 = (a21+a22) * (b11)
	BruteMatrixSubtraction(b12, b22, IntermediateB, n); // b12 - b22
	strassen(a11, IntermediateB, p3, n);				// p3 = (a11) * (b12 - b22)
	BruteMatrixSubtraction(b21, b11, IntermediateB, n); // b21 - b11
	strassen(a22, IntermediateB, p4, n);				// p4 = (a22) * (b21 - b11)
	BruteMatrixAddition(a11, a12, IntermediateA, n);	// a11 + a12
	strassen(IntermediateA, b22, p5, n);				// p5 = (a11+a12) * (b22)	
	BruteMatrixSubtraction(a21, a11, IntermediateA, n); // a21 - a11
	BruteMatrixAddition(b11, b12, IntermediateB, n);	// b11 + b12
	strassen(IntermediateA, IntermediateB, p6, n);		// p6 = (a21-a11) * (b11+b12)
	BruteMatrixSubtraction(a12, a22, IntermediateA, n); // a12 - a22
	BruteMatrixAddition(b21, b22, IntermediateB, n);	// b21 + b22
	strassen(IntermediateA, IntermediateB, p7, n);		// p7 = (a12-a22) * (b21+b22)
	BruteMatrixAddition(p3, p5, c12, n);				// c12 = p3 + p5
	BruteMatrixAddition(p2, p4, c21, n);				// c21 = p2 + p4
	BruteMatrixAddition(p1, p4, IntermediateA, n);		// p1 + p4
	BruteMatrixAddition(IntermediateA, p7, IntermediateB, n);	// p1 + p4 + p7
	BruteMatrixSubtraction(IntermediateB, p5, c11, n);			// c11 = p1 + p4 - p5 + p7
	BruteMatrixAddition(p1, p3, IntermediateA, n);				// p1 + p3
	BruteMatrixAddition(IntermediateA, p6, IntermediateB, n);	// p1 + p3 + p6
	BruteMatrixSubtraction(IntermediateB, p2, c22, n);			// c22 = p1 + p3 - p2 + p6


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i*size + j] = c11[i*n + j];
			c[i*size + j + n] = c12[i*n + j];
			c[(i + n)*size + j] = c21[i*n + j];
			c[(i + n)*size + j + n] = c22[i*n + j];
		}
	}
	free(a11); free(a12); free(a21); free(a22);
	free(b11); free(b12); free(b21); free(b22);
	free(c11); free(c12); free(c21); free(c22);
	free(p1); free(p2); free(p3); free(p4);
	free(p5); free(p6); free(p7); free(IntermediateA);
	free(IntermediateB);
}

void input(int *Matrix, int n, int sizeofstressen)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", Matrix + i*sizeofstressen + j);
		}
	}
}

void output(int *Matrix, int n, int sizeofstressen)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", *(Matrix + i*sizeofstressen + j));
		}
		printf("\n");
	}
}

void BruteMatrixMultiply(int *MatrixA, int *MatrixB, int *MatrixC, int n)
{
	//for (int i = 0; i < n*n; i++)MatrixC[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				MatrixC[i*n + j] += MatrixA[i*n + k] * MatrixB[k*n + j];
			}
		}
	}
}

int * Free(int *Matrix)
{
	if (Matrix != NULL)
		free(Matrix);
	return NULL;
}

int main()
{
	int n = 0, sizeofstressen = 0;
	int *MatrixA = NULL, *MatrixB = NULL, *MatrixC = NULL;
	while (1)
	{
		printf("1.Enter the Matrix\n2.Display\n3.Brute force Multiplication\n4.Stressen mutiplication\n5.Exit\n");
		char ch;
		scanf(" %c", &ch);
		system("cls");
		switch (ch)
		{
		case '1':
			MatrixA = Free(MatrixA);
			MatrixB = Free(MatrixB);
		
			int n;
			printf("Enter the size of 2D array\n");
			scanf("%d", &n);
			if (n > 0)
			{

				sizeofstressen = (ceil(log2(n)));
				sizeofstressen = (1 << sizeofstressen);

				MatrixA = GetMemory(sizeofstressen);
				MatrixB = GetMemory(sizeofstressen);
				
				printf("Enter First Matrix\n");
				input(MatrixA, n, sizeofstressen);
				printf("Enter Second Matrix\n");
				input(MatrixB, n, sizeofstressen);
			}
			else
			{
				printf("Enter correct input \n");
			}
			break;
		case '2':
			if (n > 0)
			{
				printf("Matrix A:\n");
				output(MatrixA, n, sizeofstressen);
				printf("Matrix B:\n");
				output(MatrixB, n, sizeofstressen);
			}
			else
			{
				printf("Enter correct input \n");
			}
			break;
		case '3':
			if (n > 0)
			{
				MatrixC = GetMemory(sizeofstressen);
				BruteMatrixMultiply(MatrixA, MatrixB, MatrixC, sizeofstressen);
				printf("Matrix A:\n");
				output(MatrixA, n, sizeofstressen);
				printf("Matrix B:\n");
				output(MatrixB, n, sizeofstressen);
				printf("Multiplication of A and B:\n");
				output(MatrixC, n, sizeofstressen);
				MatrixC = Free(MatrixC);
			}
			else
			{
				printf("Enter correct input \n");
			}
			break;
		case '4':
			if (n > 0)
			{
				
				MatrixC = GetMemory(sizeofstressen);
				strassen(MatrixA, MatrixB, MatrixC, sizeofstressen);
				printf("Matrix A:\n");
				output(MatrixA, n, sizeofstressen);
				printf("Matrix B:\n");
				output(MatrixB, n, sizeofstressen);
				printf("Multiplication of A and B By strassen:\n");
				output(MatrixC, n, sizeofstressen);
				MatrixC = Free(MatrixC);
			}
			else
			{
				printf("Enter correct input \n");
			}
			break;
		case '5':
			return 0;
			break;

		default:
			printf("Enter Correct option\n");
			break;
		}
	}
	MatrixA = Free(MatrixA);
	MatrixB = Free(MatrixB);
	return 0;
}
