// C program to illustrate macros
#include <iostream>
using namespace std;
// Multi-line Macro definition
#define ELE 1, \
            2, \
            3

// Driver Code
int main()
{

    // Array arr[] with elements
    // defined in macros
    int arr[] = { ELE };

    // Print elements
    cout << "Elements of Array are:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
