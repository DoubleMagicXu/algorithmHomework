#include<iomanip>
#include "标头.h"

int main()
{
	vector<vector<int>> a(4, vector<int>(4,1));
	vector<vector<int>> b(4, vector<int>(4,1));
	vector<vector<int>> c(4, vector<int>(4, 0));
	matrixMultiply(a, b, c, 4, 4, 4, 4);
	for (int i = 0; i < c.size(); i++)
	{
		int line = 0;
		for (int j = 0; j < c[i].size(); j++)
		{
			cout << left << setw(6) << c[i][j];
			if ((line + 1) % 4 == 0)
				cout << endl;
			line++;
		}
	}
	//cout << a << endl;

	return 0;
	//总结：vector 作为函数参数的话，注意是值传递，函数内操作不会改变原值!
	
}