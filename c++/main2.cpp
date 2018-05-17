#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Point{
    int x , y;
};

double Distance(const Point p1, const Point p2){
    double distance;
    distance = sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2));
    return distance;
}

bool IsEqual(const Point* p1, const Point* p2) {

    if ((p1->x == p2->x) && (p1->y == p2->y))
        return true;
    return false;

}

void Swap(Point *p1, Point *p2) {

    Point temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int a1, a2, b1, b2, c1, c2, d1, d2;
    int temp;
	for (int i = 0; i < lineCount; i++)
	{
        fin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;

        Point a = { a1, a2 };
        Point b = { b1, b2 }; 

        Point c = { c1, c2 };
        Point d = { d1, d2 };
        
		// 계산의 편의를 위해 읽어온 값을 크기순으로 재배열한다. a쪽이b보다 항상 작거나 같은값을 갖는다.

        if (a.y > b.y)
            Swap(&a,&b);
        if (c.x > d.x)
            Swap(&c,&d);
        
        //ab가 y축에 평행한 직선으로 만들어줌
        if (a.y == b.y){
            Swap(&a,&c);
            Swap(&b,&d);
        }


        if (((c.x < a.x) && (a.x < d.x)) && ((a.y < c.y) && (c.y < b.y))) 
            cout << "1" << endl;
            
        else if (((a.y < c.y) && (c.y < b.y) && (c.x == a.x)) || ((a.y < d.y) && (d.y < b.y) && (d.x == a.x)) || 
                ((c.x < a.x) && (a.x < d.x) && (a.y == c.y)) || ((c.x < b.x) && (b.x < d.x) && (b.y == c.y)))
            cout << "2" <<endl; 

        else if ((IsEqual(&a, &c)) || (IsEqual(&a, &d)) || (IsEqual(&b, &c)) || (IsEqual(&b, &d)))
            cout << "2" << endl;
        
        else
            cout << "0" << endl;


    }
}


