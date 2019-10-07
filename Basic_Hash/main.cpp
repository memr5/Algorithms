#include <iostream>
#include "HASH.h"

using namespace std;

int main() {
    Hash<int> myTableHash;

    int num1;

    cout << "Tape a number: ";
    cin >> num1;

    myTableHash.insertData(1, &num1);
    myTableHash.toString();
    cout << "__________________________" << endl;
    myTableHash.findData(1);
    cout << "__________________________" << endl;

    myTableHash.deleteData(1);

    return 0;
    }
