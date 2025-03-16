#include <iostream>
#include "SinglyLinkedListStack.h"
using namespace std;

int main() {
   int numbers[] = { 83, 27, 44, 55, 66, 16, 42, 73, 75 };
      
   // Initialize a new Stack and add numbers
   SinglyLinkedListStack numStack;
   for (int number : numbers) {
      numStack.Push(number);
   }

   // Output stack
   cout << "Stack after initial pushes:   ";
   numStack.Print(cout);
      
   // Pop and print, push 99 and print, pop and print again
   numStack.Pop();
   cout << "Stack after first pop:        ";
   numStack.Print(cout);
   numStack.Push(99);
   cout << "Stack after pushing 99:       ";
   numStack.Print(cout);
   numStack.Pop();
   cout << "Stack after second pop:       ";
   numStack.Print(cout);
      
   // Print a blank line before the Queue demo
   cout << endl;
      
}