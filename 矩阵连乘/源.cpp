#include<iomanip>
#include "��ͷ.h"

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
	//�ܽ᣺vector ��Ϊ���������Ļ���ע����ֵ���ݣ������ڲ�������ı�ԭֵ!
	
}