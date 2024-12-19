#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(char c) {
        arr[++top] = c;
    }

    string reverse() {
        string reversed;
        for (int i = top; i >= 0; --i) {
            reversed += arr[i];
        }
        return reversed;
    }

    bool isPalindrome() {
        for (int i = 0; i <= top / 2; ++i) {
            if (arr[i] != arr[top - i]) return false;
        }
        return true;
    }

    void processString(string &str) {
        string temp;
        for (size_t i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (isalpha(c)) temp += tolower(c);
        }
        str = temp;
    }
};

int main() {
    Stack stack;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    stack.processString(input);

    for (size_t i = 0; i < input.size(); ++i) {
        stack.push(input[i]);
    }

    cout << "\nReversed string: " << stack.reverse();
    cout << "\nThe string is " << (stack.isPalindrome() ? "" : "not ") << "a palindrome.\n";

    return 0;
}
