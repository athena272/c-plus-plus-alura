// C++ Program to demonstrate working of
// function using pointers


void fun(int x)
{
    // definition of
    // function
    x = 30;
}

void funPointer(int *ptr)
{
    *ptr = 45;
}

int main()
{
    int x = 20;
    fun(x);
    cout << "Function without reference x = " << x << endl;

    funPointer(&x);
    cout << "Function Pointer x = " << x;

    return 0;
}
