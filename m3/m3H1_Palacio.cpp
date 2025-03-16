// CSC 249
// m3H1
// Julian Palacio
// 3/23/25


#include <iostream>
#include "ArrayQueue.h"

using namespace std;

void ArrayQueue();
void LLStackQueue();

int main() {
    
    cout << "Choose the ADT you want to use for the assignment (1. ArrayQueue; 2. LinkedList(Stacks + Queues)): " << endl;
    int answer;
    cin >> answer;
    while (answer != 1 || answer != 2) {
        cout << "Please enter a valid option (1 or 2): " << endl;
        cin >> answer;
    }
    if (answer == 1) {
        ArrayQueue();
    }
    else if (answer == 2) {
        LLStackQueue();
    }
    else {
        cout << "Fatal error occured, ending program!";
        return 0;
    }
    return 0;
};

void ArrayQueue() {
    // Make two queues, one bounded to 4 items and the other bounded
    ArrayQueue boundedQueue(4);
    ArrayQueue unboundedQueue;
        
    // Enqueue 8 items in each
    cout << "Enqueueing values 1 through 8 to each queue" << endl;
    for (int i = 1; i <= 8; i++) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }
       
   // Dequeue two items from each queue
   cout << "Dequeuing twice" << endl;
   for (int i = 0; i < 2; i++) {
      cout << "  Dequeued " << boundedQueue.Dequeue();
      cout << " from bounded queue" << endl;
      cout << "  Dequeued " << unboundedQueue.Dequeue();
      cout << " from unbounded queue" << endl;
   }

   // Enqueue 4 more items
   cout << "Enqueueing values: 10, 20, 30 and 40" << endl;
   for (int i = 10; i <= 40; i+=10) {
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
}