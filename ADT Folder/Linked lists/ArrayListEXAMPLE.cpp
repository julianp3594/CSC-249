#include <iostream>
#include <string>
#include <vector>
#include "ArrayList.h"
using namespace std;

void InstructionSplit(const string& str, vector<string>& output) {
   size_t startIndex = 0;
   size_t endIndex = str.find(' ', startIndex);
   while (endIndex != string::npos) {
      output.push_back(str.substr(startIndex, endIndex - startIndex));
      startIndex = endIndex + 1;
      endIndex = str.find(' ', startIndex);
   }
   output.push_back(str.substr(startIndex));
}

int main() {
   int numbers[] = { 3, 2, 84, 18, 91, 6, 19, 12 };
      
   // Initialize a new ArrayList and add numbers
   ArrayList myList;
   for (int number : numbers) {
      myList.Append(number);
   }

   // Show the array before the operation
   cout << "-- Array before operation --" << endl;
   myList.PrintInfo(cout);
   cout << endl;
   myList.Print(cout);
   cout << endl;
      
   // Read an instruction
   string instructionLine;
   cout << "Provide an operation: " << endl;
   getline(cin, instructionLine);
   vector<string> instruction;
   InstructionSplit(instructionLine, instruction);
   string functionName = instruction[0];
      
   int item, index;
   if (functionName == "Append") {
      item = stoi(instruction[1]);
      myList.Append(item);
   }
   else if (functionName == "InsertAfter") {
      index = stoi(instruction[1]);
      item = stoi(instruction[2]);
      myList.InsertAfter(index, item);
   }
   else if (functionName == "Prepend") {
      item = stoi(instruction[1]);
      myList.Prepend(item);
   }
   else if (functionName == "RemoveAt") {
      index = stoi(instruction[1]);
      myList.RemoveAt(index);
   }
   else if (functionName == "Search") {
      item = stoi(instruction[1]);
      cout << "Search result: " << myList.Search(item) << endl;
   }
   else {
      cout << "Unknown function: " << functionName << endl;
   }
      
   cout << endl;
   cout << "-- Array after operation --" << endl;
   myList.PrintInfo(cout);
   cout << endl;
   myList.Print(cout);
   cout << endl;
}