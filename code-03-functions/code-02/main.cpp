#include <iostream>
using namespace std;

void printMinArray(int array[], int length)
{
    int min = array[0];
    cout << "Array size: " << length << endl;

    for (int i = 0; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    cout << "Minimum element is " << min << endl;
}

int main()
{
    int ar[5] = {30, 10, 20, 40, 50};
    int length = sizeof(ar) / sizeof(ar[0]);

    printMinArray(ar, length);
}