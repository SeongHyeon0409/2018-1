#include <iostream>
#include <fstream>

using namespace std;

void display(int a, int array[]){
    for(int j = 0; j<4; j++){
        cout << array[j] << " ";
    }
    cout<<endl;
}

int main(void) 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
	fin >> lineCount;

	for (int q = 0; q < lineCount; q++)
	{
        int dataCount;
        int i,j,k,l;
        int num;
        int arr[10000]; //0~9999
        int arr1[10000]; //제외되는 숫자 이외에 숫자들을 삽입.
        int ss, bs; // strike stack, ball stack.
        int s , b; // 입력받은 strike, ball. 
        int n[4]; //  0~9999 돌아가는 숫자들의 자리수를 하나씩 넣어줌. 
        int n1[4]; // input받은 num의 자리수를 하나씩넣어줌.
        int count = 0; //조건에 합당하는 수조합의 개수;

        fin >> dataCount;

        //arr에 0 부터 9999까지 넣음.
        for (i = 0; i<10000; i++)
        {
            arr[i] = i;
        }

        for (i = 0; i<dataCount; i++)
        {
            fin >> num >> s >> b;
            for(j = 0; j<10000; j++)
            {
                ss = 0, bs = 0;
                //input받은 num을 차례대로 1000의자리 , 100의 자리, 10의자리, 1의자리를 넣어줌.
                n1[0] = num/1000; n1[1] = num / 100 % 10; n1[2] = num / 10 % 10; n1[3] = num % 10; 
                //차례대로 1000의자리 , 100의 자리, 10의자리, 1의자리를 넣어줌.
                n[0] = j / 1000; n[1] = j / 100 % 10; n[2] = j / 10 % 10; n[3] = j % 10; 
                
                //각 자리의 숫자가 일치하면 ss++ 하고 10으로 제외시켜줌.
                for(k = 0; k<4; k++)
                {
                    if (n1[k] == n[k])
                    {
                        n1[k] = 10;
                        n[k] = 10;
                        ss++;
                    }
                }

                //각 자리의 숫자가 다른 위치에 존재하면 bs++ 하고 10으로 제외시켜줌.
                for(k = 0; k<4; k++)
                {
                    for(l = 0; l<4; l++)
                    {
                        if (n1[l] == 10) //이미 제외된 숫자는 넘어감.
                            continue;
                        if (n1[l] == n[k])
                        {
                            n1[l] = 10;
                            n[k] = 10;
                            bs++;
                        }
                    }
                }
                
                //ss,s bs,b가 일치하지 않으면 10000으로 제외시켜줌.
                if ((ss != s) || (bs != b))
                    arr[j] = 10000;
            }
        }


        //제외되지 않은 수들을 arr1에 넣어줌.
        for(j = 0; j<10000; j++)
        {
            if(arr[j] != 10000)
            {
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