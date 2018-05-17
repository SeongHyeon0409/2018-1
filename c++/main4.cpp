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
        int sum = 0, count = 0;
        for(int j = 1; j <=sqrt(num); j++)
        {
            if (num%j == 0){
                count++;
                sum += j;
                if(num!=j*j)
                    sum += num/j;
                    count++;
            }
        }
        sum -= num;
        count--;
    

        cout << count << " " << sum << endl;
    }
}


