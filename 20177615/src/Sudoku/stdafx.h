/*
	����Sudoku�༰���Ա������������cpp�ļ���Ҫ�õ���ͷ�ļ������ֿռ�ȫ��������
	��װ����������ڽ�������ĳ�Ա��������������������ĺ����������Ա�ʵ���������ֱ�ӵ��á�
*/
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;
namespace fs = std::filesystem;

class solveSudoku {
private:
	void init(vector<vector<char>>& board, int size);
	bool helper(vector<vector<char>>& board, int size);
	bool isValid(vector<vector<char>>& board, int size, int row, int col, char num);

public:
	void solve(int m, int n, string in, string out);
};