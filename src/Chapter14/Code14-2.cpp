// Code 14-2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;
// 以beg为起点生成row*col大小的矩阵，内容为连续的数字
matrix genMatrix(int row, int col, int beg = 0)
{
	matrix mat(row, vector<int>(col));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat[i][j] = beg + i * row + j;
		}
	}
	return mat;
}
// 在os中打印矩阵，默认分隔符是，
void printMatrix(const matrix& mat, ostream& os = cout, const string& del = ",")
{
	const int row = mat.size();
	const int col = mat[0].size();
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			os << mat[i][j] << ((j == col - 1) ? "" : del);
		}
		os << endl;
	}
}
// 从文件中读取矩阵，需要指定大小
matrix readMatrix(const string& fileName, const int row, const int col, const string& del = ",")
{
	ifstream ifs(fileName);
	if (!ifs.is_open()) {
		cerr << "error: open matrix file" << endl;
	}
	int gap = del.size();
	int x;
	matrix mat;
	vector<int> vec;
	char line[1000];

	for (int i = 0; i < row; ++i) {
		vec.clear();
		ifs.getline(line, 1000);
		string lineStr(line);
		stringstream ss(lineStr);
		for (int j = 0; j < col; ++j) {
			ss >> x;
			ss.seekg(gap, ios_base::cur);
			vec.push_back(x);
		}
		mat.push_back(vec);
	}
	return mat;
}
// 将mat保存在fileName文件中，默认分隔符是，
void saveMatrix(const matrix& mat, const string& fileName, const string& del = ",")
{
	ofstream ofs(fileName);
	printMatrix(mat, ofs, del);
	ofs.close();
}

int main()
{
	auto mat = genMatrix(6, 6, 10);
	saveMatrix(mat, "matrix.csv");
	auto csv = readMatrix("matrix.csv", 6, 6);
	printMatrix(csv);

	return 0;
}