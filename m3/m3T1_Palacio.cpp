// CSC 249
// m3T1
// Julian Palacio
// 3/9/25


#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main() {
   LinkedList numList;
   Node* nodeA = new Node(76);
   Node* nodeB = new Node(7);
   Node* nodeC = new Node(7683);
   Node* nodeD = new Node(37);
   Node* nodeE = new Node(768);
   Node* nodeF = new Node(17);

   numList.Append(nodeB);   
   numList.Append(nodeC);   
   numList.Append(nodeE);   

   numList.Prepend(nodeA);  

   numList.InsertAfter(nodeC, nodeD);  
   numList.InsertAfter(nodeE, nodeF);  

   // Output list
   cout << "List after adding nodes: ";
   numList.PrintList(cout);

   // Remove the tail node, then the head node
   numList.RemoveAfter(nodeE);
   numList.RemoveAfter(nullptr);

   // Output final list
   cout << "List after removing nodes: ";
   numList.PrintList(cout);
   
   // LinkedList destructor frees remaining nodes
}