#include <iostream>
#include <fstream>
#include "MyPoint.h"
#include "MyLineSegment.h"
using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
        int ax, ay, bx, by, cx, cy, dx, dy;
 
        fin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        MyPoint p1(ax, ay);
        MyPoint p2(bx, by);
        MyPoint p3(cx, cy);
        MyPoint p4(dx, dy);

        MyLineSegment line1(p1,p2);
        MyLineSegment line2(p3,p4);

        if (line1.properIntersection(line2)) {
            cout << "1" << endl;
        }
        else if (line1.improperIntersection(line2)) {
            cout << "2" << endl;
        }
        else
            cout << "0" << endl;
    }//end lineCount
}

