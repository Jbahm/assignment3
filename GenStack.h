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
bool GenStack<T>::isFull(){//checks if stack is full
    return (top == (size-1));
}

template <class T>
GenStack<T>::~GenStack() // desctructor
  {
    delete myArray;

  }

template <class T>
void GenStack<T>::push(const T& d)
  {//puts an item on top of the stack
    if(isFull() == false){
    myArray[++top] = d;
  }else{
    cout << "Error, stack full!" << endl;
  }

  }

template <class T>
T GenStack<T>::pop(){//removes the first item on the stack
    if(top == -1){
      cout << "Error: Empty stack" << endl;
      return 0;
    }
    return myArray[top--];
  }

template <class T>
T GenStack<T>::peek(){//shows the top item on the stack without removing it
    return myArray[top];
}



template <class T>
void GenStack<T>::resize(int increment){//increases the size of the stack by one and copies old contents over
  newArray = new T[size+increment];
  for(int i = 0; i < size; size++){
    newArray[i] = myArray[i];
  }
  myArray = newArray;
}

template <class T>
void GenStack<T>::printStack(){//prints out the stack
  for(int i = 0; i < size; i++){
    cout << myArray[i] << endl;
  }
}


template <class T>
bool GenStack<T>::isEmpty(){//checks if the stack is empty
    return (top == -1);
}
