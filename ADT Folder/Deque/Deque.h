#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class Deque {
public:
   // Member functions that may change the queue
   virtual bool PushFront(int item) = 0;
   virtual bool PushBack(int item) = 0;
   virtual int PopFront() = 0;
   virtual int PopBack() = 0;
   
   // Member functions that do not change the queue
   virtual int GetLength() const = 0;
   virtual bool IsEmpty() const = 0;
   virtual int PeekFront() const = 0;
   virtual int PeekBack() const = 0;
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const = 0;
};

#endif
/* Experiment
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class Node {
public:
   int data;
   Node* next;
   Node* prev;

   Node(int initialData) {
      data = initialData;
      next = nullptr;
      prev = nullptr
   }
};

class Node {
private:
   Node* head;
   Node* tail;
   
public:
   Deque() {
      head = nullptr;
      tail = nullptr;
   }
   
   virtual ~LinkedList() {
      Node* currentNode = head;
      while (currentNode) {
         Node* toBeDeleted = currentNode;
         currentNode = currentNode->next;
         delete toBeDeleted;
      }
   }
    
   void Append(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         tail = newNode;
      }
   }
   
   void Prepend(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head = newNode;
      }
   }
   
   void PrintList(std::ostream& printStream, const std::string& separator = ", ") {
      Node* node = head;
      if (node) {
          // Head node is not preceded by separator
          printStream << node->data;
          node = node->next;
      }
      while (node) {
         printStream << separator << node->data;
         node = node->next;
      }
      printStream << std::endl;
   }
   
   void InsertAfter(Node* currentNode, Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         tail = newNode;
      }
      else {
         newNode->next = currentNode->next;
         currentNode->next = newNode;
      }
   }
   
   void RemoveAfter(Node* currentNode) {
      if (currentNode == nullptr && head) {
         // Special case: remove head
         Node* nodeBeingRemoved = head;
         head = head->next;
         delete nodeBeingRemoved;
         
         if (head == nullptr) {
             // Last item was removed
             tail = nullptr;
         }
      }
      else if (currentNode->next) {
         Node* nodeBeingRemoved = currentNode->next;
         Node* succeedingNode = currentNode->next->next;
         currentNode->next = succeedingNode;
         delete nodeBeingRemoved;
         if (succeedingNode == nullptr) {
            // Remove tail
            tail = currentNode;
         }
      }
   }
   
   void InsertionSortSinglyLinked() {
      Node* beforeCurrent = head;
      Node* currentNode = head->next;
      while (currentNode) {
         Node* nextNode = currentNode->next;
         Node* position = FindInsertionPosition(currentNode->data);
         if (position == beforeCurrent) {
            beforeCurrent = currentNode;
         }
         else {
            // Remove, but do not deallocate, currentNode
            Node* succeedingNode = currentNode->next;
            beforeCurrent->next = succeedingNode;
            if (succeedingNode == nullptr) {
               // Remove tail
               tail = beforeCurrent;
            }
            currentNode->next = nullptr;

            // Insert currentNode back into list in sorted position
            if (position == nullptr) {
               Prepend(currentNode);
            }
            else {
               InsertAfter(position, currentNode);
            }
         }
         currentNode = nextNode;
      }
   }

   Node* FindInsertionPosition(int dataValue) {
      Node* positionA = nullptr;
      Node* positionB = head;
      while (positionB && dataValue > positionB->data) {
         positionA = positionB;
         positionB = positionB->next;
      }
      return positionA;
   }
};

#endif
*/