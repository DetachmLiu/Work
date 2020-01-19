/** 
	数独
	思路：分为有宫和无宫两种情况，算法使用回溯法。
	实现方式：所有操作由stdafx.cpp完成，声明在stdafx.h中,
	参数接收由Sudoku.cpp完成，最终由编译器链接成为Sudoku.exe
	IO：C++ 17 filesystem
**/
#include "stdafx.h"

int main(int argc, char* argv[])
{
	int m{ atoi(argv[2]) };
	int n{ atoi(argv[4]) };
	string in{ argv[6] };
	string out{ argv[8] };
	string temp;
	solveSudoku sudoku;

	/*for (int i = 0; i < argc; i++)
	{
		temp = argv[i];
		cout << i << " " << temp << endl;
	}

	cout << in << " is input and " << out << " is output." << endl;*/

	sudoku.solve(m, n, in, out);

	return 0;
}
