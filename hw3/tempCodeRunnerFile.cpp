#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyPoint.h"
using namespace std;
int main()
{
    ifstream inStream;
    int numTestCases; 
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++)
    {
        int coordX, coordY;

        inStream >> coordX >> coordY;
        MyPoint p1(coordX, coordY);

        inStream >> coordX >> coordY;
        MyPoint p2(coordX, coordY);

        if(p1 == p2)
            cout << "1" << " ";
        if(p1 != p2)
            cout << "0" << " ";

        cout << p1.dist2sqr(p2) << " " << p1.dist1(p2) << " ";

        coordX = p1.getX();
        coordY = p1.getY();

        MyPoint p3(p1);

        p3.setX(coordY);
        p3.setY(coordX);

        cout << p1.dist2sqr(p3) << " " << p1.dist1(p3) << endl;
    }
    inStream.close();
    
    return 0;
} 
