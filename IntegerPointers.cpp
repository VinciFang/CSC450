#include <iostream>
using namespace std;

int main()
{
    // Three integer variables
    int number1;
    int number2;
    int number3;

    cout << "Integer Pointers Program" << endl;
    cout << "------------------------" << endl;

    // Get three integer values from the user
    cout << "Enter the first integer: ";
    cin >> number1;

    cout << "Enter the second integer: ";
    cin >> number2;

    cout << "Enter the third integer: ";
    cin >> number3;

    // Validate input
    if (cin.fail())
    {
        cout << "Invalid input. Please enter integers only." << endl;
        return 1;
    }

    // Allocate dynamic memory and copy each variable's value
    int* pointer1 = new int(number1);
    int* pointer2 = new int(number2);
    int* pointer3 = new int(number3);

    // Display the original variables
    cout << "\nOriginal Variables" << endl;
    cout << "------------------" << endl;
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    cout << "number3 = " << number3 << endl;

    // Display pointer addresses and dereferenced values
    cout << "\nDynamic Memory Pointers" << endl;
    cout << "-----------------------" << endl;

    cout << "pointer1 address: "
         << static_cast<void*>(pointer1) << endl;
    cout << "Value at pointer1: " << *pointer1 << endl;

    cout << "\npointer2 address: "
         << static_cast<void*>(pointer2) << endl;
    cout << "Value at pointer2: " << *pointer2 << endl;

    cout << "\npointer3 address: "
         << static_cast<void*>(pointer3) << endl;
    cout << "Value at pointer3: " << *pointer3 << endl;

    // Release dynamically allocated memory
    delete pointer1;
    delete pointer2;
    delete pointer3;

    // Prevent dangling pointers
    pointer1 = nullptr;
    pointer2 = nullptr;
    pointer3 = nullptr;

    cout << "\nDynamic memory was released successfully." << endl;

    return 0;
}