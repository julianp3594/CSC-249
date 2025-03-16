// CSC 249
// m3H1
// Julian Palacio
// 3/23/25


#include <iostream>
#include "ArrayQueue.h"
#include "SinglyLinkedListQueue.h"
#include "SinglyLinkedListStack.h"

using namespace std;

void ArrayQueues();
void LLStackQueue();

int main() {
    
    cout << "Choose the ADT you want to use for the assignment (1. ArrayQueue; 2. LinkedList(Stacks + Queues)): " << endl;
    string answer;
    cin >> answer;
    while (answer != "1" && answer != "2") {
        cout << "Please enter a valid option (1 or 2): " << endl;
        cin >> answer;
    }
    if (answer == "1") {
        ArrayQueues();
    }
    else if (answer == "2") {
        LLStackQueue();
    }
    else {
        cout << "Fatal error occured, ending program!";
        return 0;
    }
    return 0;
}

void ArrayQueues() {
    // Make two queues, one bounded to 4 items and the other bounded
    ArrayQueue boundedQueue(4);
    ArrayQueue unboundedQueue;
        
    // Enqueue 8 items in each
    cout << "Enqueueing values 1 through 7 to each queue" << endl;
    for (int i = 1; i <= 7; i++) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }
       
   // Dequeue two items from each queue
   cout << "Dequeuing" << endl;
   for (int i = 0; i < 3; i++) {
      cout << "  Dequeued " << boundedQueue.Dequeue();
      cout << " from bounded queue" << endl;
      cout << "  Dequeued " << unboundedQueue.Dequeue();
      cout << " from unbounded queue" << endl;
   }

   // Enqueue 4 more items
   cout << "Enqueueing values:" << endl;
   for (int i = 10; i <= 40; i+=7) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }
        
   // Display contents of each queue
   cout << "Bounded queue (maxLength=";
   cout << boundedQueue.GetMaxLength();
   cout << ") contents:" << endl;
   while (boundedQueue.GetLength() > 0) {
      cout << "  " << boundedQueue.Dequeue() << endl;
   }
   cout << "Unbounded queue contents:" << endl;
   while (unboundedQueue.GetLength() > 0) {
      cout << "  " << unboundedQueue.Dequeue() << endl;
   }
   return;
}

void LLStackQueue() {
    int numbers[] = { 801, 2257, 446, 755, 686, 116, 402, 734, 735 };
      
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
    return;
}