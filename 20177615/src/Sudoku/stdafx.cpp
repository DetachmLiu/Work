/*
	实现solveSudoku类中的成员函数
*/
#include "stdafx.h" 

/*
	@param board 盘面
	@param size  盘面大小
	该函数用于读入盘面前的初始化，预分配空间。
*/
void solveSudoku::init(vector<vector<char>>& board, int size)
{
	board.resize(size);
	for (int i = 0; i < size; i++)
	{
		board[i].resize(size);
	}
}

/*
	@param m 盘面大小
	@param n 盘面个数
	@param in 输入文件名
	@param out 输出文件名
	该函数整合了输入输出操作以及填写数独的回溯函数。
*/
void solveSudoku::solve(int m, int n, string in, string out)
{
	fs::path p_in{ in }, p_out{ out };
	ifstream input{ p_in };
	ofstream output{ p_out };
	vector<vector<char>> board, temp;

	if (input.fail())
	{
		cout << in << " can not open!" << endl;		// notice
		return;
	}

	init(board, m);
	for (int cnt = 0; cnt < n; cnt++)	// matrix's count
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				input >> board[i][j];	// read matrix
			}
		}

		temp = board;
		helper(board, m);
		
		if (temp == board)	// judge
		{
			output << "This board can not be solved!!!" << endl;
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (j != 0)  output << " ";
					output << board[i][j];	// read matrix
				}
				output << endl;
			}
		}

		if (cnt != n - 1)  output << endl;
	}

	cout << "Program running success!!!" << endl;
}

/*
	@param board 盘面
	@param size  盘面大小
	该函数为数独的回溯函数，通过反复调用和回溯达到解决问题的目的。
*/
bool solveSudoku::helper(vector<vector<char>>& board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == '0')
			{
				char max_num = size + '0';
				for (char num = '1'; num <= max_num; num++)
				{
					if (isValid(board, size, i, j, num))
					{
						board[i][j] = num;
						if (helper(board, size))  return true;
						board[i][j] = '0';
					}
				}
				return false;
			}
		}
	}

	return true;
}

/*
	@param board 盘面
	@param size  盘面大小
	@param row   当前空位所在的行数
	@param col   当前空位所在的列数
	@param num   想要填入的数字
	该函数用于判断数字填入当前空位是否合法，根据数独规则，
	同行同列不能出现相同的数字，对于9、8、6、4阶数独做宫内合法判断。
*/
bool solveSudoku::isValid(vector<vector<char>>& board, int size, int row, int col, char num)
{
	for (int i = 0; i < size; i++)
	{
		if (board[i][col] == num)  return false;
		if (board[row][i] == num)  return false;
		if (size != 3 && size != 5 && size != 7)
		{
			int rowCheck{ 0 }, colCheck{ 0 };

			switch (size)
			{
				case 9: {
					rowCheck = 3 * (row / 3) + i / 3;
					colCheck = 3 * (col / 3) + i % 3;
					break;
				}

				case 8: {
					rowCheck = 4 * (row / 4) + i / 2;
					colCheck = 2 * (col / 2) + i % 2;
					break;
				}

				case 6: {
					rowCheck = 2 * (row / 2) + i / 3;
					colCheck = 3 * (col / 3) + i % 3;
					break;
				}

				case 4: {
					rowCheck = 2 * (row / 2) + i / 2;
					colCheck = 2 * (col / 2) + i % 2;
					break;
				}
			}

			if (board[rowCheck][colCheck] == num)  return false;
		}
	}

	return true;
}