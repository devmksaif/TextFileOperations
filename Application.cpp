#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>

#define Log(x) cout << x << endl;

using namespace std;

class Menu
{
public:
    vector<string> menuString = {"File Operations:", "Sort text within file", "Encrypt text within file"};
    vector<string> Lines;
    string FilenameS;
    string FileName()
    {
        string Filename;
        do
        {
            cout << "Enter file name" << endl;
            cin >> Filename;
        } while (Filename == "");
        return Filename;
    }

    void MainMenu()
    {
        int Selection;
        Menu menu;
        for (int i = 0; i < menuString.size(); i++)
        {
            cout << i + 1 << " " + menuString[i] << endl;
        }

        do
        {
            cout << "Enter the number corresponding to the operation" << endl;
            cin >> Selection;
        } while (Selection < 1 || Selection > menuString.size());
        if (Selection == 1)
        {
            MainMenu();
        }else if (Selection == 2)
        {
            SortingAlgo(FilenameS);
        }else if(Selection==3)
        {
            EncryptionAlgo(FilenameS);
        }
    }

    void SortingAlgo(string FileName)
    {
        Menu menu;
        ifstream file(FileName);
        ofstream fileOut("Sorted.txt");
        string line;

        if (!file.is_open())
        {
            Log("File failed to open");
            return;
        }else
        {
            while (getline(file, line))
        {
            Lines.push_back(line);
        }
        }

        

        sort(Lines.begin(), Lines.end());

        for (const auto &line : Lines)
        {
            fileOut << line << "\n";
        }
        fileOut.close();
    }

    void EncryptionAlgo(string FileName)
    {
        vector<string> NormalState;
        vector<string> EncryptedState;
        vector<int> CodeAscii;
        ifstream file(FileName);
        ofstream fileOut("Encrypted.txt");
        char key ='&';
        string line;
        if(file.is_open())
        {
            while(getline(file,line))
            {
                NormalState.push_back(line);
            }
            for(const auto& line : NormalState)
            {
                string aux="";
                for(int i =0 ; i <= line.length(); i++)
                {
                    aux += to_string((int)line[i] + (int)key);
                    if(line[i]==' ')
                    {
                        aux += "$";
                    }
                }
                EncryptedState.push_back(aux);
                aux = "";
            }
             for(const auto& line : EncryptedState)
            {
                fileOut << line << "\n";
            }
            fileOut.close();
        }


    }
};



int main()
{

    Menu menu;
    menu.FilenameS = menu.FileName();
    menu.MainMenu();

    return 0;
}
