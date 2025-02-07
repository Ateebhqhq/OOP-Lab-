#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int x;
    cout << "Enter number of strings: ";
    cin >> x;

    string* strings = new string[x];

    cout << "Enter words: " << endl;

    for(int i=0; i<x; i++) {
        getline(cin, strings[i]);

    }

    sort(strings, strings + x); //saw this method from deepseek

    for(int i=0; i<x; i++) {
        cout << strings[i] << endl;

    }

    delete[] strings;

    return 0;
}
