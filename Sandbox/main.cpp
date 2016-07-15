#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myFile("example.txt");
    if(myFile.is_open())
    {
        myFile << "abcdefghijklm" << endl;
        myFile << "1234567890123" << endl;
        myFile << "ssssss" <<endl;
        myFile.close();
    }
    else cout << "Unable to open the file" << endl; 
    
    ifstream readFile("example.txt", ifstream::in);
    if(readFile.is_open())
    {
        string str;
        getline(readFile, str);
        while(readFile.good())
        {
            cout << str << endl;
            getline(readFile, str);
        }
    }
    else cout << "Unable to open the file2" << endl; 

   return 0;
}
