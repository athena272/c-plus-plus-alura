#include <iostream>
using namespace std;

int main() {
    string food = "Pizza";
    string meal = food;

    cout << "Food: " << food << endl;
    cout << "Meal: " << meal << endl;

    
    cout << "\nDIF 1\n";
    food = "Hamburger";
    string &meal2 = food;

    cout << "Food: " << food << endl;
    cout << "Meal: " << meal << endl;
    cout << "Meal2: " << meal2 << endl;

    cout << "\nDIF 2\n";
    food = "Fritas";
    cout << "Food: " << food << endl;
    cout << "Meal: " << meal << endl;
    cout << "Meal 2: " << meal2 << endl;
}