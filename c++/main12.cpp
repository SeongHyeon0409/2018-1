#include <iostream>
#include <fstream>

using namespace std;

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
        int i,j,k,l;
        int data;
        int arr[10000];
        int arr1[10000];
        int count=0;
        int count1 = 0;
        int ss, sb;
        int s, b;
        int num;
        int a[4], da[4];
        
        fin >> data;
 
        for (i = 0;i < 10000;i++) {
            arr[i] = i;
        }
        for (i = 0;i < data;i++) {
            fin >> num >> s >> b;
            count = 0;
            for (j = 0;j < 10000;j++) {
                ss = sb = 0;
                a[0] = arr[j] / 1000;
                a[1] = arr[j] % 1000 / 100;
                a[2] = arr[j] % 100 / 10;
                a[3] = arr[j] % 10;
                da[0] = num / 1000;
                da[1] = num % 1000 / 100;
                da[2] = num % 100 / 10;
                da[3] = num % 10;
 
                for (k = 0;k < 4;k++) {
                    if (a[k] == da[k]) {
                        da[k] = 10;
                        a[k] = 10;
                        ss++;
                    }
                }
 
                for (k = 0;k < 4;k++) {
                    for (l = 0;l < 4;l++) {
                        if (da[l] == 10)
                            continue;
                        if (a[k] == da[l]) {
                            da[l] = 10;
                            a[k] = 10;
                            sb++;
                        }
                    }
                }
                
                if (s != ss || b != sb)
                    arr[j] = 10000;
                if (arr[j] != 10000)
                    arr1[count++] = arr[j];
            }
        }
        if (count > 1)
            arr1[0] = -1;
        else if (count == 0)
            arr1[0] = -2;
        cout << arr1[0] << endl;
    }

}


