#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
#define ABS (a) a>0 ? a : -b

struct Point{
    int x , y;
};

struct Square{
    int x1, y1, x2, y2;
};


double Distance(const Point p1, const Point p2){
    double distance;
    distance = pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2);
    return distance;
}

double RDistance(const Point p1, const Point p2){
    double distance;
    distance = ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
    return distance;
}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

    int x1, y1, x2, y2, a, b;
    int d1, d2;
    double side1, side2, side3;
	for (int i = 0; i < lineCount; i++)
	{
        fin >> x1 >> y1 >> x2 >> y2 >> a >> b;

        Square s = { x1, y1, x2, y2 };
        Point p = { a, b };
        Point t;

        //���� �簢�� �ȿ� ��ġ�ϴ� ���
        if ((s.x1 <= p.x && p.x <= s.x2) && (s.y1 <= p.y && p.y <= s.y2))
        {
            d1 = 0;
            d2 = 0;
        }

        //���� �ٱ��� ��ġ�ϴ� ���
        //���� �簢�� ���ʿ� ��ġ�ϴ� ���
        else if (p.y > s.y2 && (s.x1 <= p.x && p.x <= s.x2))
        {
            Point t = { p.x, s.y2 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� ���ʿ� ��ġ�ϴ� ���
        else if (p.y < s.y1 && (s.x1 <= p.x && p.x <= s.x2))
        {
            Point t = { p.x, s.y1 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� ���ʿ� ��ġ�ϴ� ���
        else if (p.x > s.x2 && (s.y1 <= p.y && p.y <= s.y2))
        {
            Point t = { s.x2, p.y };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� ���ʿ� ��ġ�ϴ� ���
        else if (p.x < s.x1 && (s.y1 <= p.y && p.y <= s.y2))
        {
            Point t = { s.x1, p.y };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }

        //�밢���ʿ� ��ġ�ϴ� ���
        //���� �簢�� �ϵ��ʿ� ��ġ
        else if (p.y > s.y2 && p.x > s.x2)
        {
            Point t = { s.x2, s.y2 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� �ϼ��ʿ� ��ġ
        else if (p.y > s.y2 && p.x < s.x1)
        {
            Point t = { s.x1, s.y2 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� �����ʿ� ��ġ
        else if (p.y < s.y1 && p.x > s.x2)
        {
            Point t = { s.x2, s.y1 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        //���� �簢�� �����ʿ� ��ġ
        else if (p.y < s.y1 && p.x < s.x1)
        {
            Point t = { s.x1, s.y1 };
            d1 = Distance(p, t);
            d2 = RDistance(p, t);
        }
        
        cout << d1 << " " << d2 << endl;
    }
}


