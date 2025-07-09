#include<iostream>
using namespace std;

int countOddDigits(int number){
    if(number == 0){
        return 0;
    }

    int count = 0;
    while(number != 0){
        int remainder = number % 10;
        number /= 10;
        if((remainder % 2) != 0){
            count++;
        }
    }
    return count;
}

int main(){

    int number;

    cout << "Enter number: ";
    cin >> number;

    cout << countOddDigits(number) << endl;

    return 0;
}