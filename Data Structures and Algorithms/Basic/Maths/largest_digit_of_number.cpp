#include<iostream>
using namespace std;

int largestDigit(int number) {
    if (number == 0) return 0;
    if (number < 0) number = -number;  // Fix

    int digit = 0;
    int largest = 0;

    while (number != 0) {
        digit = number % 10;
        number /= 10;
        if (largest < digit) {
            largest = digit;
        }
    }

    return largest;
}

int main(){

    int number;

    cout << "Enter number: ";
    cin >> number;

    cout << largestDigit(number) << endl;

    return 0;
}