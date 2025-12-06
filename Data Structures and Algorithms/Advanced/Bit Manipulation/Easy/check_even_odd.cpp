#include<iostream>
#include<string>
using namespace std;

// Returns "Odd" or "Even" based on the LSB.
string evenOrOdd(int num){
    if((num & 1) != 0){
        return "Odd";
    }

    return "Even";
}

int main(){

    int num = 10;

    cout << num << " is " << evenOrOdd(num) << endl;
    return 0;
}