#include <iostream>
#include "GenStack.h"
#include <string>

using namespace std;

class file
{
  public:
    file();
    file(string filename);

    string fileLoc;
    string *contents;
    int fileLength;




    bool isDelimeter(char delimeter);
    int getSize();
    bool isClosingDelimeter(char delimeter);
    bool isOpeningDelimeter(char delimeter);
    void printFile();
    bool compareDelimeters(char delim1, char delim2);
    void analyzeDelimeters();
};
