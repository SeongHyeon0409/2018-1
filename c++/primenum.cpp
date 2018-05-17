#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int num;

	for (int i = 0; i < lineCount; i++)
	{
        fin >> num;
        int sum = 0, answer = 1;
        for(int j = 2; j <num; j++)
        {
            if (num%j == 0){
                answer = 0;
                break;
            }
        }

        cout << answer << endl;
    }
}


