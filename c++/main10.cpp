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

    unsigned int num;

	for (int i = 0; i < lineCount; i++)
	{
        fin >> num;
        int binary[32];
        int stack = 0;
        
        for (int i = 31; i >= 0; i--) 
            binary[31-i] = num >> i & 1 ? 1 : 0;

        for (int i =1; i < 32; i++)
            if (binary[i] == 1)
                stack++;
        if (stack % 2 != 0)
        {
            if (binary[0] == 0){
                binary[0] = 1;
                num += 2147483648;
            }
        }

        else if (stack % 2 == 0)
        {
            if (binary[0] == 1){
                binary[0] = 0;
                num -= 2147483648;
            }
        }
        cout << num << endl;
    }    
}


