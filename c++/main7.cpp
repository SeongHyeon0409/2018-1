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

	for (int i = 0; i < lineCount; i++)
	{   
        int answer = 1;
        int num, count;
        int divide2 = 0, divide5 = 0, divide10 = 0;
        fin >> count;

        for ( int j = 0; j < count; j++)
        {
            fin >> num;
            while((num % 2 ==0 )||(num % 5 == 0))
            {
                if(num % 2 == 0)
                {
                    divide2++;
                    num /= 2;
                }
                if(num % 5 == 0)
                {
                    divide5++;
                    num /= 5;
                }
            }
            num %= 10;
            answer *= num;
            answer %= 10;
        }



        while(divide2 > 0 && divide5 > 0)
        {
            divide10++;
            divide2--;
            divide5--;
        }
        for(int i=0;i<divide2;i++)
        {
            answer *= 2;
            answer %= 10;
        }
        for(int i=0;i<divide5;i++)
        {
            answer *= 5;
            answer %= 10;
        }

        cout << answer << " " << divide10 << endl;
        
    }
        
}


