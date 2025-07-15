#include <iostream>
using namespace std;

long long int factorial(int n) {
    // Base Case
    if(n <= 1) {
        return 1;
    }
    // Recursive Step
    return n * factorial(n - 1);
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    }

    return 0;
}