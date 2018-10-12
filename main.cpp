#include "file.h"
#include <fstream>
#include <iostream>



int main(int argc, char** argv){
  bool repeat = true;
  int choice;
  string filename;

  while(repeat == true){//Program Loop
  cout << "Enter the name of the file you want to analyze" << endl;
  cin >> filename;
  cout << "" << endl;
  ifstream isValid;
  isValid.open(filename);
  while(isValid.fail()){
    cout << "Error, file does not exsist, enter another filename" << endl;
    cin >> filename;
    cout << "" << endl;
    isValid.open(filename);
  }
  isValid.close();
  file test(filename);
  test.analyzeDelimeters();
  cout << "" << endl;
  cout << "Do you want to analyze another file?" << endl;
  cout << "Enter one of the following options" << endl;
  cout << "0: No" << endl;
  cout << "1: Yes" << endl;
  cin >> choice;
  if(choice == 0){
    repeat = false;
  }else{
    repeat = true;
  }
  }

}
