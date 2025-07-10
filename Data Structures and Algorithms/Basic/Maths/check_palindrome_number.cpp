#include<iostream>
using namespace std;

bool isPalindrome(int number) {
    if(number < 0){
        return false;
    }

    int original = number, digit = 0, reverse = 0;
    while(number != 0){
        digit = number % 10;
        number /= 10;
        reverse = (reverse * 10) + digit;
    }

    return reverse == original;
}

int main(){

    int number;
    
    cout << "Enter number: " ;
    cin >> number;

    cout << (isPalindrome(number) ? "Palindrome" : "Not a Palindrome") << endl;

    return 0;
}