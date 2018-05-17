#include <iostream>
#include <fstream>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int y, m, d;

	for (int q = 0; q < lineCount; q++)
	{
        int c = 0;
        fin >> y >> m >> d;
        int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            monthArray[1] = 29;

        for (int i = 0; i<m-1; i++)
            c += monthArray[i];

        c += d;

        for (int i = 1; i<y; i++)
        {
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                c += 366;
            else
                c += 365;
        }
        // c += (y-1)*365;

        // c += y/4 - y/100 + y/400;

        cout << c%7 <<endl;
    }

}


