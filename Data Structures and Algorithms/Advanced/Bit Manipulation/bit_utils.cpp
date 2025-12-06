#include<iostream>
using namespace std;

// Returns true if the i-th bit of n is 1
bool isBitSet(int num, int i){
    return ((num & (1 << i)) != 0);
}

// Sets the i-th bit of n to 1
int setBit(int num, int i){
    return (num | (1 << i));
}

// Clears the i-th bit of n (sets it to 0)
int clearBit(int num, int i){
    return (num & ~(1 << i));
}

// Toggles the i-th bit
int toggleBit(int num, int i){
    return (num ^ (1 << i));
}


int main(){

    int num = 13;  
    int i = 2;

    cout << "Original number: " << num << endl;

    cout << "isBitSet: " << (isBitSet(num, i) ? "YES" : "NO") << endl;
    cout << "After setBit: " << setBit(num, i) << endl;
    cout << "After clearBit: " << clearBit(num, i) << endl;
    cout << "After toggleBit: " << toggleBit(num, i) << endl;

    return 0;
}