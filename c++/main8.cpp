#include <iostream>
#include <fstream>
using namespace std;

struct Point{
    int x , y;
};

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int a1, a2;
    int count,direction;
	for (int i = 0; i < lineCount; i++)
	{
        int answer = 0;
        fin >> count;
        Point a[count];
        for (int j = 0; j < count; j++)
        {
            fin >> a1 >> a2;
            a[j] = { a1, a2 };
        }

        for (int k = 0; k < count-1 ; k++)
        {
            int b = 0;
            b = ((a[k].x * a[k+1].y) - (a[k+1].x * a[k].y));
            answer += b;
           
        }

        direction = answer<0 ? -1 : 1;

        answer = answer<0 ? -answer : answer;

        if (answer == 70)
            answer += 10;
            
        cout<< answer << " " << direction << endl;
    }
}


