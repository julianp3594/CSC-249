// CSC 249
// m2H1
// Julian Palacio
// 3/2/25


#include <iostream>

using namespace std;

int RFibonacci(int);
int IFibonacci(int);
int RFactoral(int);
int IFactoral(int);

int main() {
    cout << "Enter an integer: " << endl;
    int number;
    cin >> number;
    cout << "Select recursion or iteration (1:Recursion, 2:Iteration): " << endl;
    int choice1 = 2;
    cin >> choice1;
    while (choice1 != 1 && choice1 != 2) {
        cout << "Invalid option! Choose 1 or 2: " << endl;
        cin >> choice1;
    }
    cout << "Select Fibonacci or Factoral (1:Fibonacci, 2:Factoral)" << endl;
    int choice2;
    cin >> choice2;
    while (choice2 != 1 && choice2 != 2) {
        cout << "Invalid option! Choose 1 or 2: " << endl;
        cin >> choice2;
    }
    int answer;
    if (choice1 == 1 && choice2 == 1) {
        answer = RFibonacci(number);
    }
    else if (choice1 == 1 && choice2 == 2) {
        answer = RFactoral(number);
    }
    else if (choice1 == 2 && choice2 == 1) {
        answer = IFibonacci(number);
    }
    else if (choice1 == 2 && choice2 == 2) {
        answer = IFactoral(number);
    }
    cout << "Your new number is: " << answer << endl;
    return 0;
}

//Fibonacci (Recursive)

int RFibonacci(int termIndex) {
    if (termIndex == 0) {
       return 0;
    }
    else if (termIndex == 1) {
       return 1;
    }
    else {
       return RFibonacci(termIndex - 1) + RFibonacci(termIndex - 2);
    }
}

//Fibonacci (Iterative)

int IFibonacci (int termIndex) {
    int loops = termIndex - 1;
    termIndex = 1;
    int changeIndex1 = 0;
    int changeIndex2;
    for (int i = 0; i < loops; i++) {
        changeIndex2 = termIndex;
        termIndex = termIndex + changeIndex1;
        if (i == loops - 1) {
            return termIndex;
        }
        changeIndex1 = changeIndex2;
    }
    return -1;
}

//Factoral (Recursive)

int RFactoral (int termIndex) {
    if (termIndex == 1) {
           return 1;
    }
    else {
        return termIndex * RFactoral(termIndex - 1);
    }
}

//Factoral (Iterative)

int IFactoral (int termIndex) {
    int start = termIndex - 1;
    for (int i = 0; i < start - 1; i++) {
        termIndex = termIndex * start; 
    }
    return termIndex;
}