#include <iostream>

using namespace std;

int main() {
    int x;
    cout << "Enter number of integars: ";
    cin >> x;

    int* integars = new int[x];

    cout << "Enter integers: " << endl;

    int* ptr = integars;
    for (int i = 0; i < x; i++) {
        cin >> *ptr;
        ptr++;
    }

    cout << "Array: ";
    ptr = integars;
    for (int i = 0; i < x; i++) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    int sum = 0;
    ptr = integars;
    for (int i = 0; i < x; i++) {
        sum = sum + *ptr;
        ptr++;
    }
    cout << "Sum: " << sum << endl;

    delete[] integars;

    return 0;
}