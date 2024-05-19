#include <iostream>
#include <string>
using namespace std;

char charArray[100]; 
int maksimal = 100, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushChar(char data) {
    if (isFull()) {
        cout << "Stack penuh" << endl;
    } else {
        charArray[top] = data;
        top++;
    }
}

void popChar() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
    } else {
        charArray[top - 1] = '\0';
        top--;
    }
}

char peekChar() {
    if (!isEmpty()) {
        return charArray[top - 1];
    } else {
        return '\0';
    }
}

int main() {
    string input;
    cout << "Masukkan Kalimat: ";
    getline(cin, input);

    int lengthInput = input.length();
    for (int i = 0; i < lengthInput; ++i) {
        pushChar(input[i]);
    }

    cout << "Hasil: ";
    while (!isEmpty()) {
        cout << peekChar();
        popChar();
    }

    return 0;
}
