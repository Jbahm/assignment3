#include <iostream>

using namespace std;
template <class T>
class GenStack
{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(const T& d);
    T pop();
    T peek();

    bool isFull();
    bool isEmpty();
    void printStack();
    void resize(int increment);

    int size;
    int top;
    T *myArray;
    T *newArray;
};

template <class T>
GenStack<T>::GenStack()//default constructor
{
    myArray = new T[1];
    size = 1;
    top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize) // overloaded constructor
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }



template <class T>
bool GenStack<T>::isFull(){
    return (top == (size-1));
}

template <class T>
GenStack<T>::~GenStack() // desctructor
  {
    delete myArray;

  }

template <class T>
void GenStack<T>::push(const T& d)
  {
    if(isFull() == false){
    myArray[++top] = d;
  }else{
    cout << "Error, stack full!" << endl;
  }

  }

template <class T>
T GenStack<T>::pop(){
    if(top == -1){
      cout << "Error: Empty stack" << endl;
      return 0;
    }
    return myArray[top--];
  }

template <class T>
T GenStack<T>::peek(){
    return myArray[top];
}



template <class T>
void GenStack<T>::resize(int increment){
  newArray = new T[size+increment];
  for(int i = 0; i < size; size++){
    newArray[i] = myArray[i];
  }
  myArray = newArray;
}

template <class T>
void GenStack<T>::printStack(){
  for(int i = 0; i < size; i++){
    cout << myArray[i] << endl;
  }
}


template <class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}
