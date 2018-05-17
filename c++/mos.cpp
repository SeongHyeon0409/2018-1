#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	ifstream fin;
	fin.open("input.txt");

	int lineCount = 0;
    int count = 0;
	fin >> lineCount;
    string inmorse;

    string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
                         "--.", "....", "..", ".---", "-.-", ".-..",
                          "--", "-.", "---", ".--.", "--.-", ".-.", 
                          "...", "-", "..-", "...-", ".--", "-..-", 
                          "-.--", "--.."};

    for (int q = 0; q < lineCount; q++)
	{
        fin >> inmorse;
        string changeWord;
        string compareText;

        while(inmorse.length()>0){
            int index = inmorse.find("|");  //5
            int index2 = inmorse.find("#"); // -1
            if((index2<1)&&(index2!=-1)){
                changeWord="";
                inmorse.erase(0,2);
                compareText.append("_");
            }
            else if ((index2 <= index) && (index2 != -1)){
                changeWord=inmorse.substr(0,index2);
                inmorse.erase(0, index2+1);
            }
            else{
                changeWord=inmorse.substr(0,index);
                if (index == -1)
                    inmorse.clear();
                else
                    inmorse.erase(0, index+1);
            }

            for(int i = 0; i<26; i++){
                if(changeWord == morse[i]){
                    char word1 = i + 65;
                    char word[2] = {word1, '\0'};
                    compareText.append(&word[0]);
                    if((index2 < index) && (index2 != -1))
                        compareText.append("_");
                    break;
                }
            }
        }
        cout << compareText << endl;
    }//end lineCount

    return 0;
}