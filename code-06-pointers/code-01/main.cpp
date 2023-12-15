#include <iostream>
using namespace std;

int main() {
    string Food = "food";
    string* pointerFood = &Food; 

    cout << Food << endl;   
    cout << &Food << endl;   
    cout << pointerFood << endl; 
    cout << *pointerFood << endl; 

}