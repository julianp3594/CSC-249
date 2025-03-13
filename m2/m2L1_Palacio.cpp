// CSC 249
// m2L1
// Julian Palacio
// 2/23/25


#include <iostream>

using namespace std;

int LinearSearch(string* words, int wordsSize, string key) {
   for (int i = 0; i < wordsSize; i++) {
      if (words[i] == key) {
         return i;
      }
   }
   return -1; // not found
}

int main() {
   string words[] = { "Apple", "Banana", "Grape", "Orange", "Pineapple", "Pear", "Radish", "Lemon", "Strawberry"};
   int wordsSize = sizeof(words) / sizeof(words[0]);
   cout << "WORDS: [" << words[0];
   for (int i = 1; i < wordsSize; i++) {
      cout << ", " << words[i];
   }
   cout << "]" << endl;
      
   // Prompt for a fruit to search for
   cout << "Enter an random fruit (capitalize the first letter): ";
   string key;
   cin >> key;

   int keyIndex = LinearSearch(words, wordsSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}