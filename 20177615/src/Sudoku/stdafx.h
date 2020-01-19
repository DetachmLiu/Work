/*
	声明Sudoku类及其成员函数，将两个cpp文件需要用到的头文件及名字空间全部声明。
	封装其他间接用于解决数独的成员函数，将完整解决数独的函数公开，以便实例化对象后直接调用。
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