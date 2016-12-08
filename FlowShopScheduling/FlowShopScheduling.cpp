#include<iostream>
#include<iomanip>
using namespace std;
const int N = 5;
class Jobtype
{
public:
	int key;
	int index;
	bool job;
	int operator <=(Jobtype a)const//read only
	{
		return  (key <= a.key);
	}
};
int FlowShopScheduling(int n, int a[], int b[], int c[]);
void BubbleSort(Jobtype *d, int n);
int main()
{
	int a[] = { 2, 4, 3, 6, 1 };
	int b[] = { 5, 2, 3, 1, 7 };
	int c[N];
	int minTime = FlowShopScheduling(N, a, b, c);
	for (int i=0; i < N; i++)
	{
		cout <<setw(4)<<c[i];
	}
	cout <<  endl<< "The least time is :" << minTime << endl;
	return 0;
}
int FlowShopScheduling(int n, int a[], int b[], int c[])
{
	Jobtype *d = new Jobtype[n];
	for (int i = 0; i < n; i++)
	{
		d[i].key = a[i] >=b[i] ? b[i] : a[i];//key word      warning! a[i]>=b[i]  N2    
		d[i].job = a[i] <b[i];     //N1 :True 
		d[i].index = i;
	}
	BubbleSort(d, n);
	int j = 0;
	int k = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (d[i].job)
		{
			c[j++] = d[i].index;

		}
		else
		{
			c[k--] = d[i].index;
		}
	}
	j = a[c[0]];
	k = j+b[c[0]];
	for (int i = 1; i < n; i++)
	{
		j += a[c[i]];
		k = j < k ? k + b[c[i]] : j + b[c[i]];
	}
	delete d;
	return k;
}
void BubbleSort(Jobtype *d, int n)
{
	int i, j ,flag;
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (j = n - 1; j > i; j--)
		{
			if (d[j] <= d[j - 1])
			{
				Jobtype temp = d[j];
				d[j] = d[j - 1];
				d[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}

}


