#include <iostream>
#include "SinglyLinkedListQueue.h"
using namespace std;

int main() {
   int numbers[] = { 83, 27, 44, 55, 66, 16, 42, 73, 75 };
      
   // Initialize a new Queue and add numbers
   SinglyLinkedListQueue numQueue;
   for (int number : numbers) {
       numQueue.Enqueue(number);
   }

   // Output queue
   cout << "Queue after initial enqueues: ";
   numQueue.Print(cout);
      
   // Dequeue 83 and print
   numQueue.Dequeue();
   cout << "Queue after first dequeue:    ";
   numQueue.Print(cout);
      
   // Enqueue 99 and print
   numQueue.Enqueue(99);
   cout << "Queue after enqueueing 99:    ";
   numQueue.Print(cout);
      
   // Dequeue 4 and print
   numQueue.Dequeue();
   cout << "Queue after second dequeue:   ";
   numQueue.Print(cout);
}