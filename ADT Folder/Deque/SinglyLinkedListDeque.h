
#ifndef SINGLYLINKEDLISTDEQUE_H
#define SINGLYLINKEDLISTDEQUE_H

#include <iostream>

class Node {
   public:
      int data;
      Node* next;
   
      Node(int initialData) {
         data = initialData;
         next = nullptr;
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
         else {
            Node* savedNode = head;
            Node* newTail = head;
            while (newTail->next->next) {
               newTail = newTail->next;
            }
            newTail->next = nullptr;
            tail = newTail;
            Node* nodeBeingRemoved = currentNode;
            delete nodeBeingRemoved;

         }
      }
      
      int GetLength() {
         Node* lengthNode = head;
         int length = 0;
         for (int i = 0; lengthNode; i++) {
            lengthNode = lengthNode->next;
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

class SinglyLinkedListDeque {
private:
   LinkedList linkedList;

public:
   SinglyLinkedListDeque() {
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
      
      // Remove list head
      linkedList.RemoveAfter(nullptr);
      
      // Return pushed item
      return pushedItem;
   }

   int PopBack() {
    // Copy list tail's data
      int pushedItem = linkedList.GetTailData();

      // Create a node for the tail to go into
      Node* tailNode = new Node(pushedItem);
      std::cout << linkedList.GetTailData() << std::endl;
    // Remove list tail
      linkedList.RemoveAfter(tailNode);

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
