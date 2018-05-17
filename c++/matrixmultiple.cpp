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

    int sizeX, sizeY, sizeZ, sum;

	for (int q = 0; q < lineCount; q++)
	{
        fin >> sizeX >> sizeY >> sizeZ;

        vector < vector < int > > ary;
        vector < vector < int > > ary2;
        vector < vector < int > > ary3;

        for ( int i = 0; i < sizeX; ++i)
        {
            vector<int> elem;
            elem.resize(sizeY);
            ary.push_back(elem);
        }
        
        for ( int i = 0; i < sizeY; ++i)
        {
            vector<int> elem;
            elem.resize(sizeZ);
            ary2.push_back(elem);
        }

        for ( int i = 0; i < sizeX; ++i)
        {
            vector<int> elem;
            elem.resize(sizeZ);
            ary3.push_back(elem);
        }


        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeY; ++j)
            {
                fin >> ary[i][j];
            }
        }

        for(int i = 0; i < sizeY; ++i)
        {
            for(int j = 0; j < sizeZ; ++j)
            {
                fin >> ary2[i][j]; 
            }
        }


        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeZ; ++j)
            {
                sum = 0;
                for(int k = 0; k < sizeY; ++k)
                {
                    sum += ary[i][k]*ary2[k][j];
                }
                ary3[i][j] = sum;
            }
        }

        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeZ; ++j)
            {
                cout << ary3[i][j] << " "; 
            }
            cout << endl;
        }


    }

}
