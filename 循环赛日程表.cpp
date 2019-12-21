#include<bits/stdc++.h>
#include<math.h>
#include<windows.h>
using namespace std;
//迭代实现
void tournament_1(int **a, int k)
{
	a[0][0] = 1;
	int n = 2;
	int s = 0, i = 0, j = 0;
	for (s = 0; s<k; s++)
	{

		for (i = 0; i<n / 2; i++)
			for (j = 0; j<n / 2; j++)
			{
			    a[i][j + n / 2] = a[i][j] + n / 2;
			    a[i + n / 2][j] = a[i][j] + n / 2;
				a[i + n / 2][j + n / 2] = a[i][j];
			}
		n *= 2;
	}
}
//递归实现
void tournament_2(int **a, int n)
{
	int i = 0, j = 0;
	if (n == 1)
	{
		a[0][0] = 1;
		return;
	}
	else
	{
		tournament_2(a, n / 2);
		for (i = 0; i<n / 2; i++)
			for (j = 0; j<n / 2; j++)
			{
				a[i][j + n / 2] = a[i][j] + n / 2;
				a[i + n / 2][j] = a[i][j] + n / 2;
				a[i + n / 2][j + n / 2] = a[i][j];
			}
		return;
	}
}


int main()
{
    clock_t startTime,endTime;
	int k, i, j;
	cout << "请输入循环赛日程表的k值：";
	cin >> k;
	int **a = new int *[(int)pow(2, k)];
	for (i = 0; i<(int)pow(2, k); i++)
		a[i] = new int[(int)pow(2, k)];
    //使用迭代法
    startTime = clock();
    tournament_1(a, k);
    endTime = clock();
    cout << "迭代法 Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    startTime = clock();
	tournament_2(a, (int)pow(2, k));
	endTime = clock();
	cout << "递归法 Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	ofstream outFile;
    outFile.open("Tournament_result.csv", ios::out);
    for(int i=0;i<(int)pow(2, k);i++)
       {
         for(int j=0;j<(int)pow(2, k);j++)
         outFile<<a[i][j]<<",";
         outFile<<endl;
       }
	/*for(i=0;i<(int)pow(2,k);i++)
	{
	for(j=0;j<(int)pow(2,k);j++)
	cout<<a[i][j]<<" ";
	cout<<endl;
	}*/
	for(int i = 0;i < (int)pow(2, k);i++){
          delete[] a[i];
      }
      delete[] a;
}
