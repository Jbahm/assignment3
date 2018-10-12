#include "file.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

file::file(){
  fileLoc = "";
  contents = new string[1];
  fileLength = 0;
}


file::file(string filename){ // Overloaded constructor
  fileLoc = filename;


  //Converts file to an array containing each line
  string currentLine;
  ifstream fileContents;
  fileContents.open(fileLoc);
  fileLength = getSize();
  contents = new string[fileLength];

  for(int i = 0; i < fileLength; i++){
    getline(fileContents, currentLine);
    if(currentLine[0] == '/' && currentLine[1] == '/'){ //Makes it ignore comments
      currentLine = "";
    }else{
    contents[i] = currentLine;
  }
  }
}

void file::printFile(){//Prints out each line of the file
  for(int i = 0; i < fileLength; i++){
    cout << contents[i] << endl;
  }
}

int file::getSize(){//Counts the amount of lines in the file
  string currentLine = "a";
  ifstream fileContents;
  fileContents.open(fileLoc);
  int fileLength = 0;

  while(!fileContents.eof()){
    getline(fileContents, currentLine);
    fileLength++;
  }
  return fileLength;
}

bool file::compareDelimeters(char delim1, char delim2){ // checks if the delimeters being compared are a pair
  if(delim1 == '(' && delim2 == ')'){
    return true;
  }else if(delim1 == '[' && delim2 == ']'){
    return true;
  }else if(delim1 == '{' && delim2 == '}'){
    return true;
  }else{
    return false;
  }
}

bool file::isClosingDelimeter(char delimeter){//Checks if the delimeter in question is a closing delimeter
  if(delimeter == ']' || delimeter == ')' || delimeter == '}'){
    return true;
  }else{
    return false;
  }
}

bool file::isOpeningDelimeter(char delimeter){//Checks if the delimeter in question is an opening delimeter
  if(delimeter == '[' || delimeter == '(' || delimeter == '{'){
    return true;
  }else{
    return false;
  }
}


bool file::isDelimeter(char delimeter){//Checks if the character in question is a delimeter of any sort
  if(delimeter == '(' || delimeter == ')'){
    return true;
  }else if(delimeter == '[' || delimeter == ']'){
    return true;
  }else if(delimeter == '{' || delimeter == '}'){
    return true;
  }else{
    return false;
  }
  return false;
}

void file::analyzeDelimeters(){//Analyzes the file
   GenStack<char> delimeters(10);
   GenStack<int> locations(10);

   for(int i = 0; i < fileLength; i++){//Goes through each line to try and find the delimeter and its pair
     for(int j = 0; j < contents[i].length(); j++){
      if(isOpeningDelimeter(contents[i][j]) == true){
        if(delimeters.isFull() == false){
          delimeters.push(contents[i][j]);
          locations.push(i+1);
        }else{
          delimeters.resize(1);
          locations.resize(1);
          delimeters.push(contents[i][j]);
          locations.push(i+1);
        }
      }else if(isClosingDelimeter(contents[i][j]) == true){
        if(compareDelimeters(delimeters.peek(), contents[i][j]) == false){
          cout << "Error on line " << locations.peek() << endl; //Error Message
          cout << delimeters.peek() << " with no ending delimeter" << endl;
          cout << "Exiting program..." << endl;
          exit(0);
        }else{
          delimeters.pop();
          locations.pop();
        }
      }
   }
  }

  if(delimeters.isEmpty() == false){ //Catches any delimeters remaining in the stack
    cout << "Error on line " << locations.peek() << endl;
    cout << delimeters.peek() << " with no ending delimeter" << endl;
    cout << "Exiting program..." << endl;
    exit(0);
  }
  cout << "No Errors!" << endl;
 }
