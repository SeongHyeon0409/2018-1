#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void num2st(string &egNum , int a, string b);

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
    
        unsigned int num, numA, numB, numC, numD;

		string egNum = "";
		fin >> num;
		
		numD = num%1000; // zero
		numC = num%1000000 / 1000; // thousand
		numB = num%1000000000 / 1000000; // million
		numA = num /1000000000;  //billion
		
        num2st(egNum, numA, "_Billion");
        num2st(egNum , numB , "_Million");
        num2st(egNum , numC , "_Thousand");
        num2st(egNum , numD , "");
		
		cout << egNum << endl;

    }
}

void num2st(string &egNum , int a, string b)
{
    int ten, hund, one, ten1;

    string number[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", 
					   "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
					   "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
					   "Nineteen"};
    string tenNumber[] = {"0", "1", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
						  "Seventy", "Eighty", "Ninety" };
    if(a>0)
		{
			ten = a % 100;
			if(a>99)
			{	
				if(egNum.size() != 0)
					egNum.append("_");
				hund = a / 100;
				egNum.append(number[hund]);
				egNum.append("_Hundred");

			}
			if(ten>19)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				ten1 = a % 100 /10;
				egNum.append(tenNumber[ten1]);
				if ( a % 10 != 0){
					if(egNum.size() != 0)
					egNum.append("_");
					one = a % 10;
					egNum.append(number[one]);
				}
			}
			if(ten<20 && ten != 0)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				egNum.append(number[ten]);
			}

			egNum.append(b);
		}
}


