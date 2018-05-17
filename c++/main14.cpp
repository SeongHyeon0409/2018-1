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
    int n,stack,d;

    vector<int> v;

	for (int q = 0; q < lineCount; q++)
	{
        fin >> n;
        v.clear();

        for(int i = 2; i<=n; i++)
        {

            stack = 0;
            for(int j = 2; j < i; j++)
            {
                d = 1;
                if (i%j==0)
                {
                    d = 0;
                    break;
                }
            }

            if ((d == 1) && (n % i == 0))
            {
                v.push_back(i);
                while(n%i==0)
                {
                    n /= i;
                    stack++;
                }
                v.push_back(stack);
            }

        }
        cout << v.size()/2 << " ";
        for (int i = 0; i<v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout<<endl;
    }

}


