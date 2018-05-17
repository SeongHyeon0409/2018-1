#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	string number[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", 
					   "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
					   "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
					   "Nineteen"};
	string tenNumber[] = {"0", "1", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
						  "Seventy", "Eighty", "Ninety" };

	for (int q = 0; q < lineCount; q++)
	{
		int num, numA, numB, numC, numD;
		int ten, hund, one, ten1;
		string egNum = "";
		fin >> num;
		
		numD = num%1000; // zero
		numC = num%1000000 / 1000; // thousand
		numB = num%1000000000 / 1000000; // million
		numA = num /1000000000;  //billion
		
		//cout << numA << " " << numB << " " << numC << " " << numD << endl;

		if(numA>0)
		{
			egNum.append(number[numA]);
			egNum.append("_Billion");
		}
		if(numB>0)
		{
			ten = numB % 100;
			if(numB>99)
			{	
				if(egNum.size() != 0)
					egNum.append("_");
				hund = numB / 100;
				egNum.append(number[hund]);
				egNum.append("_Hundred");

			}
			if(ten>19)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				ten1 = numB % 100 /10;
				egNum.append(tenNumber[ten1]);
				if ( numB % 10 != 0){
					if(egNum.size() != 0)
					egNum.append("_");
					one = numB % 10;
					egNum.append(number[one]);
				}
			}
			if(ten<20 && ten != 0)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				egNum.append(number[ten]);
			}

			egNum.append("_Million");
		}
		if(numC>0)
		{
			ten = numC % 100;
			if(numC>99)
			{	
				if(egNum.size() != 0)
					egNum.append("_");
				hund = numC / 100;
				egNum.append(number[hund]);
				egNum.append("_Hundred");
			}
			if(ten>19)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				ten1 = numC % 100 /10;
				egNum.append(tenNumber[ten1]);
				if ( numC % 10 != 0){
					if(egNum.size() != 0)
					egNum.append("_");
					one = numC % 10;
					egNum.append(number[one]);
				}
			}
			if(ten<20 && ten != 0)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				egNum.append(number[ten]);
			}

			egNum.append("_Thousand");
		}
		if(numD>0)
		{
			ten = numD % 100;
			if(numD>99)
			{	
				if(egNum.size() != 0)
					egNum.append("_");
				hund = numD / 100;
				egNum.append(number[hund]);
				egNum.append("_Hundred");
			}
			if(ten>19)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				ten1 = numD % 100 /10;
				egNum.append(tenNumber[ten1]);
				if ( numD % 10 != 0){
					egNum.append("_");
					one = numD % 10;
					egNum.append(number[one]);
				}
			}
			if(ten<20 && ten != 0)
			{
				if(egNum.size() != 0)
					egNum.append("_");
				egNum.append(number[ten]);
			}
		}
		cout << egNum << endl;

    }
}


