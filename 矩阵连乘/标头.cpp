#include"��ͷ.h"
void matrixMultiply(vector<vector<int>> a, vector<vector<int>>b, vector<vector<int>>&c, int ra, int ca, int rb, int cb)//������������ֵ����
{
	if (ca != rb)
	{
		cout << "���󲻿������!" << endl;
		return;
	}


	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			int sum = 0;
			for (int k = 0; k < ca; k++)
			{
				sum += a[i][k] + b[k][j];

			}
			cout << sum << endl;
			c[i][j] = sum;
		}
	}
}