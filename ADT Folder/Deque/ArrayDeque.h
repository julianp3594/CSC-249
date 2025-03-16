#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

class ArrayDeque {
private:
   int allocationSize;
   int* array;
   int frontIndex;
   int length;
   int maxLength;
   
   void ResizeBack() {
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

   void ResizeFront() {
    // Allocate new array and copy existing items
    int newSize = allocationSize * 2;
    if (maxLength >= 0 && newSize > maxLength) {
       newSize = maxLength;
    }
    int* newArray = new int[newSize];
    for (int i = 0; i < length; i++) {
       int itemIndex = (frontIndex + i) % allocationSize;
       newArray[i + 1] = array[itemIndex];
    }
       
    // Delete old array, assign new array, and assign new allocation size
    delete[] array;
    array = newArray;
    allocationSize = newSize;
     
    // Reset frontIndex to 0
    frontIndex = 0;
 }

public:
   ArrayDeque(int maximumLength = -1) {
      allocationSize = (0 == maximumLength) ? 0 : 1;
      array = new int[allocationSize];
      length = 0;
      frontIndex = 0;
      maxLength = maximumLength;
   }
   
   virtual ~ArrayDeque() {
      delete[] array;
   }
    
   int GetLength() {
      return length;
   }
        
   int GetMaxLength() {
      return maxLength;
   }
        
   bool PushBack(int item) {
      // If at max length, return false
      if (length == maxLength) {
         return false;
      }
          
      // Resize if length equals allocation size
      if (length == allocationSize) {
         ResizeBack();
      }

      // Push back the item and return true
      int itemIndex = (frontIndex + length) % allocationSize;
      array[itemIndex] = item;
      length++;
      return true;
   }

   bool PushFront(int item) {
    //If at max length, return false
    if (length == maxLength) {
        return false;
    }

    //Resize if length equals allocation size
    if (length == allocationSize) {
        ResizeFront();
    }

    //Push front the item and return true
    int itemIndex = frontIndex;
    if (array[itemIndex] >= 0 || array[itemIndex] < 0) {
        int itemMover;
        for (int i = length; i > 0; i--) {
            itemMover = array[(i + (frontIndex - 1)) % allocationSize];
            array[(i + frontIndex) % allocationSize] = itemMover;
        }
        array[itemIndex] = item;
    }
    else{
        array[itemIndex] = item;
    }
    length++;
    return true;
   }

   int PeekBack() {
    // Get the item at the end of the deque
    int toReturn = array[(frontIndex + (length - 1)) % allocationSize];

    // Return the back item
    return toReturn;
   }

   int PeekFront() {
    // Get the item at the front of the array
    int toReturn = array[frontIndex];

    // Return the front item
    return toReturn;
   }
        
   int PopFront() {
      // Get the item at the front of the deque
      int toReturn = array[frontIndex];
      
      // Decrement length and advance frontIndex
      length--;
      frontIndex = (frontIndex + 1) % allocationSize;
      
      // Return the front item
      return toReturn;
   }

   int PopBack() {
    // Get the item at the back of the deque
    int toReturn = array[(frontIndex + (length - 1)) % allocationSize];

    //Decrement length return
    length--;
    return toReturn;
   }
};

#endif
