#include<time.h>
#include<random>
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int rdm(int max);
void longestsubsequence(const vector<int> arry,vector<int>result);
int main()
{
	vector<int> arry;
	vector<int> result(10);
	srand((int)time(0));
	for (int i = 0; i < 10; ++i)
	{
		arry.push_back(rdm(100));
	}
	for (vector<int>::iterator it = arry.begin(); it != arry.end(); ++it)
	{
		cout << setw(8) << *it;
	}
	longestsubsequence(arry, result);
	return 0;

}
int rdm(int max)
{
	//srand 不可放这边
	unsigned int temp;
	temp = rand() % (max+1);
	return temp;
	
}
void longestsubsequence( vector<int> arry, vector<int>result)//zhe li bu neng jia const
{
	vector<int> list(10, 1);
	int max = 1;
	int k = 0;
	vector<int>pre(10);
	for (int i = 0; i < 10; i++)
	{
		pre[i] = i;
	}
	for (int i = 1; i < arry.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arry[j] < arry[i] && list[j] >= list[i])//以a[i]为序列末尾
			{
				list[i] = list[j] + 1;
				//
				pre[i] = j;
			}
			if (max<=list[i])
			{
				max = list[i];
				k = i;
			}
		}
	}
	int i = max - 1;
	while (pre[k] != k)
	{
		
		result[i--] = arry[k];
		k = pre[k];
	}
	result[i] = arry[k];
	cout << endl;
	cout << max << endl;
	for (int i = 0; i < max; i++)
	{
		
		cout << setw(8) << result[i];
	}
}