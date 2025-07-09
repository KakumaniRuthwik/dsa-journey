#include<iostream>
using namespace std;

int reverseNumber(int number) {
    int digit, reverse = 0;
    while(number != 0){
        digit = number % 10;
        number /= 10;
        reverse = (reverse * 10) + digit;
    }
    return reverse;
}

int main(){

    int number;

    cout << "Enter number: ";
    cin >> number;

    cout << reverseNumber(number) << endl;

    return 0;
}