#include <iostream>
#include "DoublyLinkedListDeque.h"
using namespace std;

int main() {

    // Make a new deque
    DoublyLinkedListDeque newDeque;

    // Add values to the deque
    if (newDeque.isEmpty() == true) {
        cout << "The deque is empty..." << endl;
    }
    cout << "Adding numbers to deque... " << endl;
    for (int i = 1; i <= 10; i++) {
        int num = i;
        if (num % 2 == 0) {
            newDeque.PushBack((num+num)/2);
            cout << "Back: " << newDeque.PeekBack() << endl;
        }
        else {
            newDeque.PushFront((num+num)/2);
            cout << "Front: " << newDeque.PeekFront() << endl;
        }
    }
    if (newDeque.isEmpty() == false) {
        cout << "The deque contains data." << endl;
    }
    cout << "Current length: " << newDeque.GetLength() << endl;
    cout << endl;

    // Remove values from deque
    cout << "Removing numbers... " << endl;
    newDeque.PopFront();
    newDeque.PopBack();
    newDeque.PopBack();
    cout << endl;

    // Peek the head and tail values
    cout << "New length after removal: " << newDeque.GetLength() << endl;
    cout << "Front: " << newDeque.PeekFront() << endl;
    cout << "Back: " << newDeque.PeekBack() << endl;
    cout << endl;
    

    // Pop front and back
    cout << "Removing front and back again... " << endl;
    newDeque.PopFront();
    newDeque.PopBack();
    cout << endl;

    // Peek Again
    cout << "Final length: " << newDeque.GetLength() << endl;
    cout << "Front: " << newDeque.PeekFront() << endl;
    cout << "Back: " << newDeque.PeekBack() << endl;
    return 0;
}