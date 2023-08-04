#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string str = "Hello there General Kenobi";
    char *cPtr;

    cPtr = strrchr(str, ' ');
    cout << *cPtr << endl;
    cPtr = strrchr(cPtr, ' ');
    cout << *cPtr << endl;
    cPtr = strrchr(cPtr, ' ');
    cout << *cPtr << endl;
    cPtr = strrchr(cPtr, ' ');
    cout << *cPtr << endl;

    return 0;
}
