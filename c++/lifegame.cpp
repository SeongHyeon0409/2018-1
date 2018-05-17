#include <iostream>
#include <fstream>

using namespace std;

void Print(char** a, int row, int col)
{
    for(int j = 0; j < row; j++){
        for(int k = 0; k < col; k++)
            cout << a[j][k] ;
        cout << endl;
    }
}

int Crush(int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return 0;
    else
        return 1;
}

int Neighbor(char** a, int row, int col, int r, int c)
{
    int count = 0;
    if (Crush(row, col, r-1 ,c-1) == 1 && a[r-1][c-1] == 'O')
        count++;
    if (Crush(row, col, r ,c-1) == 1 && a[r][c-1] == 'O')
        count++;
    if (Crush(row, col, r+1 ,c-1) == 1 && a[r+1][c-1] == 'O')
        count++;
    if (Crush(row, col, r-1 ,c) == 1 && a[r-1][c] == 'O')
        count++;
    if (Crush(row, col, r+1 ,c) == 1 && a[r+1][c] == 'O')
        count++;
    if (Crush(row, col, r-1 ,c+1) == 1 && a[r-1][c+1] == 'O')
        count++;
    if (Crush(row, col, r ,c+1) == 1 && a[r][c+1] == 'O')
        count++;
    if (Crush(row, col, r+1 ,c+1) == 1 && a[r+1][c+1] == 'O')
        count++;
    
    return count;
}

void Copy(char** a, char** b, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            //strcpy(&a[i][j], &b[i][j]);
            a[i][j] = b[i][j];
        }
    }
}

void Change(char** a, char** b, int row, int col, int r, int c)
{
    int count = Neighbor(a, row, col, r, c);
    if (count == 3)
        b[r][c] = 'O';
    else if (count == 2 && a[r][c] == 'O')
        b[r][c] = 'O';
    else
        b[r][c] = 'X';
}


int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int row, col, decade ,count;
    char** board;
    char** oldBoard;

	for (int q = 0; q < lineCount; q++)
	{
        count = 0;
        fin >> row >> col >> decade;

        board = new char*[row];

        for (int i = 0; i<row; i++)
        {
            board[i] = new char[col];
        }
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
                fin >> board[i][j];
        }

        oldBoard = new char*[row];

        for (int i = 0; i<row; i++)
        {
            oldBoard[i] = new char[col];
        }
        
        // for(int i = 0; i<row; i++)
        // {
        //     for(int j = 0; j<col; j++)
        //     {
        //         //board[i][j] = Change(oldBoard,row,col,i,j);
        //         cout << Neighbor(board, row, col, i,j) << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for (int k = 0; k < decade ; k++)
        {
            Copy(oldBoard, board , row, col);
            for(int i = 0; i<row; i++)
            {
                for(int j = 0; j<col; j++)
                {
                    Change(oldBoard,board,row,col,i,j);
                }
            }
        }
        for(int i =0; i<row; i++)
        {
            for(int j = 0; j < col; j++)
                if (board[i][j] == 'O')
                    count++;
        }

        cout << count << endl;
        Print(board, row, col);

    }//end lineCount
}
