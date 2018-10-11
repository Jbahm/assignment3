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

file::file(string filename){
  fileLoc = filename;


  //Converts file to an array containing each line
  string currentLine;
  ifstream fileContents;
  fileContents.open(fileLoc);
  fileLength = getSize();
  contents = new string[fileLength];

  for(int i = 0; i < fileLength; i++){
    getline(fileContents, currentLine);
    contents[i] = currentLine;
  }
}

void file::printFile(){
  for(int i = 0; i < fileLength; i++){
    cout << contents[i] << endl;
  }
}

int file::getSize(){
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

bool file::compareDelimeters(char delim1, char delim2){
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

bool file::isClosingDelimeter(char delimeter){
  if(delimeter == ']' || delimeter == ')' || delimeter == '}'){
    return true;
  }else{
    return false;
  }
}

bool file::isOpeningDelimeter(char delimeter){
  if(delimeter == '[' || delimeter == '(' || delimeter == '{'){
    return true;
  }else{
    return false;
  }
}


bool file::isDelimeter(char delimeter){
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

void file::analyzeDelimeters(){
   GenStack<char> delimeters(10);
   GenStack<int> locations(10);

   for(int i = 0; i < fileLength; i++){
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
          cout << "Error on line " << locations.peek() << endl;
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

  if(delimeters.isEmpty() == false){
    cout << "Error on line " << locations.peek() << endl;
    cout << delimeters.peek() << " with no ending delimeter" << endl;
    cout << "Exiting program..." << endl;
    exit(0);
  }
  cout << "No Errors!" << endl;
 }
