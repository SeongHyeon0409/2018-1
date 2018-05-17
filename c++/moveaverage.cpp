#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;
    int n, num, period, sum;
    vector <int> ary;

	for (int q = 0; q < lineCount; q++)
	{
        fin >> n;
        ary.clear();

        for ( int i = 0; i < n; ++i)
        {
            fin >> num;
            ary.push_back(num);
        }

        fin >> period;
        cout << n - period + 1 << " ";
        for ( int i = 0; i <(ary.size()-period+1); ++i)
        {
            sum = 0;
            for (int j = 0; j < period; ++j)
            {
                sum += ary[i+j];
            }
            cout << sum/period << " ";
        }
        cout << endl;
    }

}
