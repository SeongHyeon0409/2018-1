#include <iostream>
#include <fstream>
using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    unsigned int num, num2;

	for (int i = 0; i < lineCount; i++)
	{
        fin >> num >> num2;
        int binary[32], binary2[32];
        int stack1 = 0;
        int stack2 = 0;
        int stack3 = 0;
        
        for (int i = 31; i >= 0; i--) 
            binary[31-i] = num >> i & 1 ? 1 : 0;
        
        for (int i = 31; i >= 0; i--) 
            binary2[31-i] = num2 >> i & 1 ? 1 : 0;

        for (int i = 0; i < 32; i++)
            if (binary[i] == 1)
                stack1++;
        
        for (int i = 0 ; i < 32; i++)
            if (binary2[i] == 1)
                stack2++;

        for (int i = 0; i < 32; i++)
            if (binary[i] != binary2[i])
                stack3++;

        cout << stack1 << " " << stack2 << " " << stack3 << endl;
    }    
}


