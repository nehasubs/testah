#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
 
const int SIZE = 60;
 
const int MAX_PRINTABLE_ASCII = '~';
const int MIN_PRINTABLE_ASCII = ' ';
const int ASCII_PRINTABLE_RANGE = MAX_PRINTABLE_ASCII - MIN_PRINTABLE_ASCII + 1;
 
void printRight(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
 
void printRight_upsideDown_rightJustified(int n) {
    for (int i = n; i > 0; i--) {
        for (int x = 0; x < n - i; x++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
 
void printArray(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}
 
void printArray(const char arr[][SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printArray(arr[i], cols);
    }
}
 
void add(char arr[], int size, int val) {
    for(int i = 0; i < size; i++){
        char character = arr[i];
        int asciiCode = (int)character;
        asciiCode += val;
        
        if(asciiCode < MIN_PRINTABLE_ASCII){
            asciiCode += ASCII_PRINTABLE_RANGE;
        }
        
        else if(asciiCode > MAX_PRINTABLE_ASCII){
            asciiCode -= ASCII_PRINTABLE_RANGE;
        }
        
        character = (char)asciiCode;
        arr[i] = character;
    }
}


void add(char arr[][SIZE], int rows, int cols, int val) {
    for(int i = 0; i < rows; i++){
        add(arr[i], strlen(arr[i]), val);
    }
}
 
void rotateLeft(char arr[], int size) {
    char buffer = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = buffer;
}
 
void rotateLeft(char arr[][SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        rotateLeft(arr[i], cols);
    }
}
 
void rotateRight(char arr[], int size) {
    char buffer = arr[size - 1];
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = buffer;
}
 
void rotateRight(char arr[][SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        rotateRight(arr[i], cols);
    }
}
 
void reverse(char arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        char buffer = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = buffer;
    }
}
 
void swapRange(char arr1[], int size1, int index1,
    char arr2[], int size2, int index2, int len) {
    for (int i = 0; i < len; i++) {
        char buffer = arr1[i + index1];
        arr1[index1 + i] = arr2[index2 + i];
        arr2[index2 + i] = buffer;
    }
}
 
void swapWithinOneRow(char arr[], int size, int len) {
    int interval = 0;
    while (interval + len + len <= size) {
        swapRange(arr, size, interval, arr, size, interval + len, len);
        interval = interval + len + len;
    }
}
 
void swapRows(char arr[][SIZE], int rows, int cols) {
    for (int i = 0; rows - i >= 2; i += 2) {
        swapRange(arr[i], cols, 0, arr[i + 1], cols, 0, cols);
    }
}

int main(){
    char testee[5] = {'a', '#', '~', ' ', '*'};
    add(testee, 5, 5);
    printArray(testee,5);
}
