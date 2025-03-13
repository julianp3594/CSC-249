#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
   int numbers[] = { 72, 91, 53, 12, 48, 19, 7, 1, 86 };
      
   // Initialize a new LinkedList
   LinkedList numList;
      
   // Create and append nodes with the numbers
   for (int number : numbers) {
       Node* node = new Node(number);
       numList.Append(node);
   }

   // Output list
   cout << "List after adding nodes:   ";
   numList.PrintList(cout);

   // Sort the list
   numList.InsertionSortDoublyLinked();

   // Output list
   cout <<"List after insertion sort: ";
   numList.PrintList(cout);
}