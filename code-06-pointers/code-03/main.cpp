#include <iostream>
using namespace std;

void swapValue(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

int main()
{
    int number1 = 10;
    int number2 = 20;

    cout << "Before swapValue" << endl;
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;

    swapValue(number1, number2);

    cout << "\nAfter swapValue" << endl;
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;
}