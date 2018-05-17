#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print(int a[][7] )
{
    for(int j = 5; j>=0; j--){
        for(int k = 0; k < 7; k++)
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
        int num;
        int winner = 0;
        fin >> num;
        
        int board[6][7]={0,};
        int stack[7] = {0,};

        for(int i = 1; i<= num; i++)
        {
            int n;
            fin >> n;
            if(i%2 != 0)
                board[stack[n-1]++][n-1] = 1;
            else
                board[stack[n-1]++][n-1] = 2;
        }

        for(int j = 0; j<6; j++){
            for(int k = 0; k< 7; k++)
            {
                if ( board[j][k] != 0 ){
                    if (k < 4)
                        if( board[j][k] == board[j][k+1] && board[j][k+1] == board[j][k+2] &&
                            board[j][k+2] == board[j][k+3])
                            winner = board[j][k];
                    if (j < 3)
                        if( board[j][k] == board[j+1][k] && board[j+1][k] == board[j+2][k] &&
                            board[j+2][k] == board[j+3][k])
                            winner = board[j][k];
                    if (j  < 3 && k  < 4)
                        if(board[j][k] == board[j+1][k+1] && board[j+1][k+1] == board[j+2][k+2] &&
                            board[j+2][k+2] == board[j+3][k+3])
                            winner = board[j][k];
                    if (j  < 3 && k  >= 3)
                        if( board[j][k] == board[j+1][k-1] && board[j+1][k-1] == board[j+2][k-2] &&
                            board[j+2][k-2] == board[j+3][k-3])
                            winner = board[j][k];
                }
                
            }
        }//end j for

        cout << winner << endl;
    }
}