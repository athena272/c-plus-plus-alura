// C++ Program to demonstrate working of
// function using pointers
#include <iostream>
using namespace std;

void fun(int x)
{
    // definition of
    // function
    x = 30;
}

void fun(int *ptr)
{
    *ptr = 45;
}

int main()
{
    int x = 20;
    fun(&x);
    cout << "x = " << x;

    return 0;
}
