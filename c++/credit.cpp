#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
    int sum = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
        string creditNum;
        fin >> creditNum;
        int first = (int)creditNum[0] - 48;
        int cardlen = creditNum.size();
        int checkSum = 0;
        int answer = 1;

        if (first == 3)
            if ((cardlen != 15) && (cardlen != 14))
                answer = 0;
        if ((first == 6) || (first ==5))
            if (cardlen != 16)
                answer = 0;
        if (first == 4)
            if ((cardlen != 13) && (cardlen != 16))
                answer = 0;
        if (first != 3 && first != 4 && first != 5 && first != 6)
                answer = 0;

        if (answer == 1)
        {
            for ( int i = creditNum.length() - 2 ; i>=0; i -= 2)
            {   
                sum = (int(creditNum[i])-48) * 2;
                if (sum >= 10)
                    sum -= 9;
                checkSum += sum;
            }

            for ( int i = creditNum.size() -3; i>=0; i -= 2)
            {   
                sum = int(creditNum[i])-48;
                checkSum += sum;
            }

            int stack = 0;

            while (checkSum % 10 != 0)
            {
                checkSum++;
                stack++;
            }
            
            checkSum = int(creditNum[creditNum.size()-1])-48;
            if(stack != checkSum)
                answer = 0;
        }//end if
        cout << answer << endl;

    }//end lineCount
}


