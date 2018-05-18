#include <iostream>
#include <fstream>
using namespace std;

void Print(int a[][5] )
{
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++)
            cout << a[j][k] << " ";
        cout << endl;
    }
}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
        int num, n;
        int winner = 0;
        int board[5][5]={0,};
        int bingo = 1;
        int count = 0;

        for(int j = 0; j<5; j++)
        {
            for(int k = 0; k<5; k++)
            {  
                fin >> n; 
                board[j][k] = n;
            }
        }//end j for

        while(bingo)
        {
            count++;
            fin >> n;
            for(int j = 0; j<5; j++)
                for(int k = 0; k<5; k++)
                    if(n == board[j][k])
                        board[j][k] = 0;

            if (board[0][0] == 0 && board[0][4] == 0 && board[4][0] == 0 && board[4][4] == 0)
                bingo = 0;

            if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0 )
                bingo = 0;

            if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0)
                bingo = 0;

            for(int j = 0; j<5; j++)
                if(board[j][0] == 0 && board[j][1] == 0 && board[j][2] == 0 && board[j][3] == 0 && board[j][4] == 0)
                    bingo = 0;

            for(int j = 0; j<5; j++)
                if(board[0][j] == 0 && board[1][j] == 0 && board[2][j] == 0 && board[3][j] == 0 && board[4][j] == 0)
                    bingo = 0;

        }//end while

        cout << count << endl;

        while(count < 75)
        {
            fin >> n;
            count++;
        }

    }//end lineCunt
}//end main