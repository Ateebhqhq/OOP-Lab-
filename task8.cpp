#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int** arr = new int*[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = new int;
    }

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *arr[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << *arr[i] << " ";
    }
    cout << endl;


    delete[] arr;

    return 0;
}