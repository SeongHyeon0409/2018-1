#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int num,n;

	for (int i = 0; i < lineCount; i++)
	{

        fin >> num;
        int numList[num];
        int temporaryList[num];
        int highestFrequency = 0;
        int currentFrequency = 0;
        int frequencyCount = 0;

        for (int j = 0; j < num; j++)
        {
            fin >> n;
            numList[j] = n;
        }
        
        for (int j = 0; j < num; j++)
        {
            temporaryList[j] = 0;
        }

        sort(numList , numList + num);
        
        for (int k = 0; k < num; k++)
        {
            currentFrequency++;
            if((k+1 == num) || (numList[k] != numList[k + 1]))
            {
                if (currentFrequency > highestFrequency)
                {
                    highestFrequency = currentFrequency;
                }
                currentFrequency = 0;
            }
        }

        for (int q = 0; q < num; q++)
        {
            currentFrequency++;
            if((q+1 == num) || (numList[q] != numList[q + 1]))
            {
                if (currentFrequency == highestFrequency)
                {
                    temporaryList[frequencyCount] = numList[q];
                    frequencyCount++;
                }
                currentFrequency = 0;
            }
        }

        int frequencyList[frequencyCount];
       
        for (int i = 0; i < frequencyCount; i++)
        {
            frequencyList[i] = temporaryList[i];
        }
        
        cout << frequencyCount << " " << highestFrequency;

        for (int i = 0; i < frequencyCount; i++)
        {
            cout << " " << frequencyList[i];
        }

        cout << "\n";

    }
}


