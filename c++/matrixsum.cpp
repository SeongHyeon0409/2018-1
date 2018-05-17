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

    int sizeX, sizeY;

	for (int q = 0; q < lineCount; q++)
	{
        fin >> sizeX >> sizeY;

        vector < vector < int > > ary;
        vector < vector < int > > ary2;

        for ( int i = 0; i < sizeX; ++i)
        {
            vector<int> elem;
            elem.resize(sizeY);
            ary.push_back(elem);
        }
        
        for ( int i = 0; i < sizeX; ++i)
        {
            vector<int> elem;
            elem.resize(sizeY);
            ary2.push_back(elem);
        }


        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeY; ++j)
            {
                fin >> ary[i][j];
            }
        }

        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeY; ++j)
            {
                fin >> ary2[i][j]; 
            }
        }

        for(int i = 0; i < sizeX; ++i)
        {
            for(int j = 0; j < sizeY; ++j)
            {
                cout << ary[i][j] + ary2[i][j] << " ";
            }
            cout << endl;
        }


    }

}
