#include <iostream>
using namespace std;

int* multiplyByTwo(const int* arr, int size) {
    int* newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i] * 2;
    }
    return newArr;
}

void printCharsBetweenKandV(const char* str) {
    cout << "Characters between 'k' and 'v': ";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 'k' && str[i] < 'v') {
            cout << str[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* doubledArr = multiplyByTwo(arr, size);

    cout << "New array: ";
    for (int i = 0; i < size; i++) {
        cout << doubledArr[i] << " ";
    }
    cout << endl;

    delete[] doubledArr;

    const char* text = "hello world kv zebra";
    printCharsBetweenKandV(text);

    return 0;
}
