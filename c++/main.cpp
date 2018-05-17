#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point{
    int x , y;
};

double Distance(const Point p1, const Point p2){
    double distance;
    distance = pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2);
    return distance;
}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int a1, a2, b1, b2, c1, c2;
    double side1, side2, side3;
	for (int i = 0; i < lineCount; i++)
	{
        fin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        Point a = { a1, a2 };
        Point b = { b1, b2 }; 
        Point c = { c1, c2 };

        side1 = Distance(a,b);
        side2 = Distance(a,c);
        side3 = Distance(b,c);

        double sides[3] = {side1, side2, side3};
        sort(sides , sides + 3);
        
        if (sqrt(sides[2]) >= (sqrt(sides[0]) + sqrt(sides[1])))
            cout << "0" << endl;
        else if (sides[2] == (sides[0] + sides[1]))
            cout << "1" << endl;
        else if (sides[2] > (sides[0] + sides[1]))
            cout << "2" << endl;
        else if (sides[2] < (sides[0] + sides[1]))
            cout << "3" << endl;
    }
}


