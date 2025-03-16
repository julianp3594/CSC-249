#ifndef DOUBLYLINKEDLISTDEQUE_H
#define DOUBLYLINKEDLISTDEQUE_H

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

      void RemoveBack(Node* currentNode) {
         Node* successor = tail->previous;
         successor->next = nullptr;
         Node* nodeToDelete = tail;
         tail = successor;

         delete currentNode;
      }

      void RemoveFront(Node* currentNode) {
         Node* successor = head->next;
         successor->previous = nullptr;
         Node* nodeToDelete = head;
         head = successor;

         delete currentNode;
      }

      int GetLength() {
         Node* newNode = head;
         int length = 0;
         for (int i = 0; newNode; i++) {
            newNode = newNode->next;
            length++;
         }
         return length;
      }
      
      // Added for deque section
      int GetHeadData() {
         return head->data;
      }

      int GetTailData() {
        return tail->data;
      }
   };

class DoublyLinkedListDeque {
private:
   LinkedList linkedList;

public:
   DoublyLinkedListDeque() {
   }
   
   void PushBack(int newData) {
      // Create a new node
      Node* newNode = new Node(newData);
       
      // Insert as list tail (end of deque)
      linkedList.Append(newNode);
   }

   void PushFront(int newData) {
    // Create a new node
    Node* newNode = new Node(newData);

    //Insert as list head (start of deque)
    linkedList.Prepend(newNode);
   }
   
   int PopFront() {
      // Copy list head's data
      int pushedItem = linkedList.GetHeadData();

      // Create a node for the tail value to go into
      Node* headNode = new Node(pushedItem);

      //std::cout << headNode << std::endl;
      
      // Remove list head
      linkedList.RemoveFront(headNode);
      
      // Return pushed item
      return pushedItem;
   }

   int PopBack() {
    // Copy list tail's data
    int pushedItem = linkedList.GetTailData();

    // Create a node for the tail value to go into
    Node* tailNode = new Node(pushedItem);

    // Remove list tail
    linkedList.RemoveBack(tailNode);

    // Return pushed item
    return pushedItem;
   }

   int PeekFront() {
      // Copy list's head data
      int pushedItem = linkedList.GetHeadData();

      // Output the head data
      return pushedItem;
   }

   int PeekBack() {
      // Copy list's tail data
      int pushedItem = linkedList.GetTailData();

      // Output the tail data
      return pushedItem;
   }

   int GetLength() {
      int ValueToReturn = linkedList.GetLength();
      return ValueToReturn;
   }

   bool isEmpty() {
      if (linkedList.GetLength() == 0) {
         return true;
      }
      else {
         return false;
      }
   }
};

#endif
