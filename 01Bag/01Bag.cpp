#include<iostream>
using namespace std;
void Knapsack(int *v, int *w, int c, int n, int m[][16]);
void Traceback(int *x, int *w, int c, int n, int m[][16]);//不可用 int **
int min(int a, int b);
int max(int a, int b);
int main()
{
	int w[4] = { 3, 4, 5, 6 };
	int v[4] = { 4, 5, 6, 7 };
	int c = 15;
	int n = 4;
	int m[4][16];
	int x[4];
	Knapsack(v, w, c, n, m);
	Traceback(x, w, c, n, m);
	for (int i = 0; i < 4; i++)
	{
		cout << x[i] << endl;
	}
	cout << m[0][c] << endl;

	return 0;
}
int min(int a, int b)
{
	return(a < b ? a : b);

}
int max(int a, int b)
{
	return (a > b ? a : b);

}
void Knapsack(int *v, int *w, int c, int n, int m[][16])
{
	int jMax = min(w[n - 1] - 1, c);
	for (int j = 0; j <= jMax; j++)
		m[n - 1][j] = 0;
	for (int j = w[n - 1]; j <= c; j++)
		m[n - 1][j] = v[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++)
			m[i][j] = m[i + 1][j];
		for (int j = w[i]; j <= c; j++)
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);

	}
	//为什么把第一项单独列出来
	m[0][c] = m[1][c];
	if (c >= w[0])
		m[0][c] = max(m[1][c], m[1][c - w[0]] + v[0]);
}
void Traceback(int *x, int *w, int c, int n, int m[][16])
{
	for (int i = 0; i < n - 1; i++)

	{
		if (m[i][c] == m[i + 1][c])
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n - 1] = (m[n - 1][c]) ? 1 : 0;

}