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
        int arr1[10000]; //���ܵǴ� ���� �̿ܿ� ���ڵ��� ����.
        int ss, bs; // strike stack, ball stack.
        int s , b; // �Է¹��� strike, ball. 
        int n[4]; //  0~9999 ���ư��� ���ڵ��� �ڸ����� �ϳ��� �־���. 
        int n1[4]; // input���� num�� �ڸ����� �ϳ����־���.
        int count = 0; //���ǿ� �մ��ϴ� �������� ����;

        fin >> dataCount;

        //arr�� 0 ���� 9999���� ����.
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
                //input���� num�� ���ʴ�� 1000���ڸ� , 100�� �ڸ�, 10���ڸ�, 1���ڸ��� �־���.
                n1[0] = num/1000; n1[1] = num / 100 % 10; n1[2] = num / 10 % 10; n1[3] = num % 10; 
                //���ʴ�� 1000���ڸ� , 100�� �ڸ�, 10���ڸ�, 1���ڸ��� �־���.
                n[0] = j / 1000; n[1] = j / 100 % 10; n[2] = j / 10 % 10; n[3] = j % 10; 
                
                //�� �ڸ��� ���ڰ� ��ġ�ϸ� ss++ �ϰ� 10���� ���ܽ�����.
                for(k = 0; k<4; k++)
                {
                    if (n1[k] == n[k])
                    {
                        n1[k] = 10;
                        n[k] = 10;
                        ss++;
                    }
                }

                //�� �ڸ��� ���ڰ� �ٸ� ��ġ�� �����ϸ� bs++ �ϰ� 10���� ���ܽ�����.
                for(k = 0; k<4; k++)
                {
                    for(l = 0; l<4; l++)
                    {
                        if (n1[l] == 10) //�̹� ���ܵ� ���ڴ� �Ѿ.
                            continue;
                        if (n1[l] == n[k])
                        {
                            n1[l] = 10;
                            n[k] = 10;
                            bs++;
                        }
                    }
                }
                
                //ss,s bs,b�� ��ġ���� ������ 10000���� ���ܽ�����.
                if ((ss != s) || (bs != b))
                    arr[j] = 10000;
            }
        }


        //���ܵ��� ���� ������ arr1�� �־���.
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