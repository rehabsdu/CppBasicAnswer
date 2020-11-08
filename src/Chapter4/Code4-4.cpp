// Code 4-4

#include<iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "运算矩阵A和矩阵B相加" << endl ;
    cout << "请输入矩阵A、B的行数和列数：" << endl;
    cin >> m;
    cin >> n;

    int A[10][10];
    int B[10][10];
    int C[10][10];
    //为A矩阵赋值
    cout << "请输入矩阵A的元素:" << endl ;
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < n;j++) 
            cin >> A[i][j];
    }
    //为A矩阵赋值
    cout  << "请输入矩阵B的元素:" << endl;
    for (int i = 0;i < m;i++) 
    {
        for (int j = 0;j < n;j++) 
            cin >> B[i][j];
    }
    //矩阵加法运算
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < n;j++)
            C[i][j]=A[i][j]+ B[i][j];
    }
    

    //输出C矩阵
    cout  << "矩阵A和B的相加结果C：" << endl;
    for (int i = 0;i < m;i++) 
    {
        for (int j = 0;j < n;j++) 
        {
            cout << C[i][j] << '\t';
        }
        cout << '\n';//每输出完一行进行换行
        cout << endl;
    }
    return 0;
}