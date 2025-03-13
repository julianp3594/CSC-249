#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

class Node {
public:
   int data;
   Node* next;
   Node* previous;

   Node(int initialData) {
      data = initialData;
      next = nullptr;
      previous = nullptr;
   }
};

class LinkedList {
private:
   Node* head;
   Node* tail;

public:
   LinkedList() {
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
         newNode->previous = tail;
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
         head->previous = newNode;
         head = newNode;
      }
   }
   
   void InsertAfter(Node* currentNode, Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         newNode->previous = tail;
         tail = newNode;
      }
      else {
         Node* successor = currentNode->next;
         newNode->next = successor;
         newNode->previous = currentNode;
         currentNode->next = newNode;
         successor->previous = newNode;
      }
   }
   
   void Remove(Node* currentNode) {
      Node* successor = currentNode->next;
      Node* predecessor = currentNode->previous;
      
      if (successor) {
         successor->previous = predecessor;
      }
      if (predecessor) {
         predecessor->next = successor;
      }
         
      if (currentNode == head) {
         head = successor;
      }
      if (currentNode == tail) {
         tail = predecessor;
      }
      
      delete currentNode;
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

   // Moves nodeToMove to immediately after nodeBefore. If nodeBefore is null, 
   // nodeToMove is moved to the front of the list.
   void MoveAfter(Node* nodeToMove, Node* nodeBefore) {
      // First remove nodeToMove from the list, but do not deallocate
      Node* successor = nodeToMove->next;
      Node* predecessor = nodeToMove->previous;
      if (successor) {
         successor->previous = predecessor;
      }
      if (predecessor) {
         predecessor->next = successor;
      }
      if (nodeToMove == head) {
         head = successor;
      }
      if (nodeToMove == tail) {
         tail = predecessor;
      }
      nodeToMove->next = nullptr;
      nodeToMove->previous = nullptr;
      
      // If nodeBefore is non-null, use InsertAfter(), otherwise use Prepend()
      if (nodeBefore) {
         InsertAfter(nodeBefore, nodeToMove);
      }
      else {
         Prepend(nodeToMove);
      }
   }

   // Sorts the list ascending by node data value
   void InsertionSortDoublyLinked() {
      Node* currentNode = head->next;
      while (currentNode) {
         Node* nextNode = currentNode->next;
         Node* searchNode = currentNode->previous;
         
         while (searchNode && searchNode->data > currentNode->data) {
            searchNode = searchNode->previous;
         }
         
         // Move currentNode after searchNode
         MoveAfter(currentNode, searchNode);

         // Advance to next node
         currentNode = nextNode;
      }
   }
};

#endif