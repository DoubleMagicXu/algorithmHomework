#include<iostream>
#include<vector>
#include<string>
using namespace std;
void LCS(vector<vector<int>> &C,int r,int c);
void printLCS(vector<vector<int>>C, int r, int c);
string A, B;

int main()
{
	cout << "please input two string:" << endl;
	cout << "The first stirng:" << endl;
	cin >> A;
	cout << "The second string:" << endl;

	cin >> B;
	int lenB = B.length();
	int lenA = A.length();
	vector<vector<int>> C(lenA + 1,vector<int>(lenB+1));
	LCS(C, lenA, lenB);
	printLCS(C, lenA, lenB);
	return 0;
}
void LCS(vector<vector<int>> &C,int r,int c)// remind to add the reference
{
	for (int i = 0; i <= r; i++)
	{
		C[i][0] = 0;
	}
	for (int i = 0; i <= c; i++)
	{
		C[0][i] = 0;
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (A[i-1] == B[j-1])
			{
				C[i][j] = C[i - 1][j - 1]+1;
			}
			else if (C[i - 1][j] >= C[i][j - 1])
			{
				C[i][j] = C[i - 1][j];
			}
			else
			{
				C[i][j] = C[i][j - 1];
			}
		}
	}
	cout << "the longest length is:" << C[r][c] << endl;
}
void printLCS(vector<vector<int>>C, int r, int c)
{
	if (r == 0 || c == 0)
		return;
	if (A[r - 1] == B[c - 1])
	{
		printLCS(C, r - 1, c - 1);
		cout << A[r - 1] << endl;
	}
	else if (C[r - 1][c] >= C[r][c - 1])
	{
		printLCS(C, r - 1, c);
	}
		
	else
	{
		printLCS(C, r, c - 1);
	}
		
}