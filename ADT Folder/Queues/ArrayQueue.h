#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
private:
   int allocationSize;
   int* array;
   int frontIndex;
   int length;
   int maxLength;
   
   void Resize() {
      // Allocate new array and copy existing items
      int newSize = allocationSize * 2;
      if (maxLength >= 0 && newSize > maxLength) {
         newSize = maxLength;
      }
      int* newArray = new int[newSize];
      for (int i = 0; i < length; i++) {
         int itemIndex = (frontIndex + i) % allocationSize;
         newArray[i] = array[itemIndex];
      }
         
      // Delete old array, assign new array, and assign new allocation size
      delete[] array;
      array = newArray;
      allocationSize = newSize;
       
      // Reset frontIndex to 0
      frontIndex = 0;
   }

public:
   ArrayQueue(int maximumLength = -1) {
      allocationSize = (0 == maximumLength) ? 0 : 1;
      array = new int[allocationSize];
      length = 0;
      frontIndex = 0;
      maxLength = maximumLength;
   }
   
   virtual ~ArrayQueue() {
      delete[] array;
   }
    
   int GetLength() {
      return length;
   }
        
   int GetMaxLength() {
      return maxLength;
   }
        
   bool Enqueue(int item) {
      // If at max length, return false
      if (length == maxLength) {
         return false;
      }
          
      // Resize if length equals allocation size
      if (length == allocationSize) {
         Resize();
      }

      // Enqueue the item and return true
      int itemIndex = (frontIndex + length) % allocationSize;
      array[itemIndex] = item;
      length++;
      return true;
   }
        
   int Dequeue() {
      // Get the item at the front of the queue
      int toReturn = array[frontIndex];
      
      // Decrement length and advance frontIndex
      length--;
      frontIndex = (frontIndex + 1) % allocationSize;
      
      // Return the front item
      return toReturn;
   }
};

#endif