#include <iostream>
using namespace std;

int main() {
    string food = "Pizza";
    string* foodPointer = &food;

    cout << "Food before: " << food << endl;
    cout << "Food pointer addrees before: " << foodPointer << endl;
    cout << "Food pointer value before: " << *foodPointer << "\n\n";

    //Change variable
    *foodPointer = "Hamburger";

    cout << "Food after: " << food << endl;
    cout << "Food pointer addrees after: " << foodPointer << endl;
    cout << "Food pointer value after: " << *foodPointer << endl;

}