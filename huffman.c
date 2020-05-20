#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct huffman
{
	char id;
	int freq;
	struct huffman* left, * right;
}huffman;
void swap(huffman& a, huffman& b)
{
	huffman temp = a;
	a = b;
	b = temp;
}
void minheapifydown(huffman Array[], int i, int n)
{
	int left = i << 1;
	int right = i << 1 | 1;
	int minimum = i;
	if (left <= n && Array[minimum].freq > Array[left].freq)
	{
		minimum = left;
	}
	if (right <= n && Array[minimum].freq > Array[right].freq)
	{
		minimum = right;
	}
	if (minimum != i)
	{
		swap(Array[minimum], Array[i]);
		minheapifydown(Array, minimum, n);
	}
}
void makeminheap(huffman Array[], int n)
{
	for (int i = n / 2; i >= 1; --i)
	{
		minheapifydown(Array, i, n);
	}
}
void minheapifyup(huffman Array[], int n)
{
	while (n > 1)
	{
		if (Array[(n >> 1)].freq > Array[n].freq)
			swap(Array[(n >> 1)], Array[n]);
		n >>= 1;
	}
}
void displaytree(huffman* root)
{
	if (root)
	{
		displaytree(root->left);
		printf("\n%c %d\n", root->id, root->freq);
		displaytree(root->right);
	}
}
huffman maketree(huffman Array[], int n)
{
	while (n > 1)
	{
		huffman* lc = (huffman*)malloc(sizeof huffman);
		*lc = Array[1];
		swap(Array[1], Array[n]);
		n--;
		minheapifydown(Array, 1, n);
		huffman* rc = (huffman*)malloc(sizeof huffman);
		*rc = Array[1];
		swap(Array[1], Array[n]);
		minheapifydown(Array, 1, n - 1);
		Array[n].left = lc;
		Array[n].right = rc;
		Array[n].freq = lc->freq + rc->freq;
		Array[n].id = '#';
		minheapifyup(Array, n);
	}

	return Array[1];
}
void Encode(huffman* root, int index, char* str, char* map[])
{
	if (root->left != NULL)
	{
		str[index] = '0';
		Encode(root->left, index + 1, str, map);
		str[index] = '1';
		Encode(root->right, index + 1, str, map);
	}
	if (root->left == NULL)
	{
		int key = root->id - 'a';
		map[key] = (char*)malloc((sizeof(char)) * (index));
		for (int i = 0; i < index; i++)
		{
			map[key][i] = str[i];
		}
		map[key][index] = '\0';
	}
}
void decode(huffman* root, char* str)
{
	//int n = strlen(str);
	huffman* temp = root;
	char disp[20];
	int index = 0;
	int i = 0;
	for (; str[i]; )
	{
		if (temp->left != NULL)//&&i<n)
		{
			if (str[i] == '0')temp = temp->left;
			else if (str[i] == '1') temp = temp->right;
			else
			{
				printf("Invalid String\n");
				return;
			}
			i++;
		}
		else
		{
			//if(temp->left == NULL)
			disp[index++] = (temp)->id;
			temp = root;
		}
	}
	if (temp->left != NULL)
	{
		printf("Invalid String\n");
		//printf("hello String\n");
		return;
	}
	disp[index++] = (temp)->id;
	disp[index] = '\0';
	printf("%s\n", disp);
}
void displayEncoded(char* map[])
{
	for (int i = 0; i < 26; i++)
	{
		if (map[i] != NULL)
		{
			printf("%c = %s\n", 'a' + i, map[i]);
		}
	}
}
huffman Enterdata(int n)
{
	char hashmap[26] = { 0 };
	huffman* Array = (huffman*)malloc((n + 1) * sizeof(huffman));
	for (int i = 1; i <= n;)
	{
		scanf(" %c", &Array[i].id);
		scanf("%d", &Array[i].freq);
		if (!hashmap[Array[i].id - 'a'] && (Array[i].id >= 'a' && Array[i].id <= 'z'))
		{
			hashmap[Array[i].id - 'a'] = 1;
			Array[i].left = Array[i].right = NULL;
			i++;
		}
		else
			printf("\nDon't be Evil..Enter unique Id OR Enter smallcase alphabets only\n");
	}
	makeminheap(Array, n);
	//free(Array + n);
	huffman Tree = maketree(Array, n);
	free(Array);
	return Tree;
}
void deleteTree(huffman* root)
{
	if (!root)return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}
void delTree(huffman** root)
{
	deleteTree(*root);
	*root = NULL;
}
void freeMap(char* map[])
{
	for (int i = 0; i < 26; i++)
	{
		if (map[26] != NULL)
		{
			free(map[i]);
		}
	}
}
void clearmap(char* map[])
{
	for (int i = 0; i < 26; i++)
	{
		map[i] = NULL;
	}
}
void LOT(huffman* root)
{
	huffman* queue[100] = { 0 };
	int rear = 0;
	int front = 0;
	huffman* temp = root;
	while (temp)
	{
		printf("\n%c %d\n", temp->id, temp->freq);
		if (temp->left)
		{
			queue[rear++] = temp->left;
		}

		if (temp->right)
		{
			queue[rear++] = temp->right;
		}
		temp = queue[front++];
	}
}

int main()
{
	char* map[26];
	clearmap(map);
	huffman* root = NULL;
	int n;
	while (1)
	{
		char ch;
		printf("\nEnter Choice\n1.Enter Data\n2.Encoding\n3.Decoding\n4.Clear screen\n5.Display Inorder Traversal\n6.Display level Order Traversal\n7.Exit\n");
		scanf(" %c", &ch);
		switch (ch)
		{
		case '1':
			printf("Enter the number of Elements\n");
			delTree(&root);
			//root = NULL;
			freeMap(map);
			clearmap(map);

			scanf("%d", &n);
			root = (huffman*)malloc(sizeof huffman);
			*root = Enterdata(n);
			break;
		case '2':
			if (root == NULL)
			{
				printf("Make Huffman Tree first!!\n");
			}
			else
			{
				char* str = (char*)malloc(sizeof(char) * (n + 1));
				Encode(root, 0, str, map);
				displayEncoded(map);
				free(str);
			}
			break;
		case '3':
			if (root != NULL)
			{
				char* str = (char*)malloc(sizeof(char) * (5 * n));
				printf("Enter the string to be decoded !\n");
				scanf("%s", str);
				decode(root, str);
				free(str);
			}
			else
			{
				printf("Make Huffman Tree first!!\n");
			}
			break;
		case '4':system("cls");
			break;
		case '5':displaytree(root);
			printf("\n"); break;
		case '6':
			LOT(root);
			printf("\n");
			break;
		case '7':
			delTree(&root);
			freeMap(map);
			return 0;
		default:
			printf("Enter Correct Choice\n");
		}
	}
	return 0;
}
