#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Point{
    int x , y;
};

int Area(const Point a, const Point b, const Point c)
{   
    int area;
    area =  ((b.x - a.x)*(c.y -a.y) - (c.x - a.x)*(b.y - a.y));
    return area;
}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int a1, a2, b1, b2, c1, c2;
    int area, direction;
	for (int i = 0; i < lineCount; i++)
	{
        fin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        Point a = { a1, a2 };
        Point b = { b1, b2 }; 
        Point c = { c1, c2 };

        area = Area(a, b, c);
        direction = area<0 ? -1 : 1;
        area = area<0 ? -area : area;

        if (area == 0)
            direction = 0;

        cout << area << " " << direction << endl;


    }
}


