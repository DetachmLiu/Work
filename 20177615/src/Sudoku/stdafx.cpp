/*
	ʵ��solveSudoku���еĳ�Ա����
*/
#include "stdafx.h" 

/*
	@param board ����
	@param size  �����С
	�ú������ڶ�������ǰ�ĳ�ʼ����Ԥ����ռ䡣
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
	@param m �����С
	@param n �������
	@param in �����ļ���
	@param out ����ļ���
	�ú���������������������Լ���д�����Ļ��ݺ�����
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
	@param board ����
	@param size  �����С
	�ú���Ϊ�����Ļ��ݺ�����ͨ���������úͻ��ݴﵽ��������Ŀ�ġ�
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
	@param board ����
	@param size  �����С
	@param row   ��ǰ��λ���ڵ�����
	@param col   ��ǰ��λ���ڵ�����
	@param num   ��Ҫ���������
	�ú��������ж��������뵱ǰ��λ�Ƿ�Ϸ���������������
	ͬ��ͬ�в��ܳ�����ͬ�����֣�����9��8��6��4�����������ںϷ��жϡ�
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