#include<iostream>
using namespace std;

int countSetBits(int num){

    int count = 0;

    while(num > 0){
        count += (num & 1);   // Add 1 if the least significant bit is set
        num = num >> 1;       // Shift right to process the next bit
    }

    return count;
}

int main(){

    int num = 13;

    cout << countSetBits(num) << " bits are present in " << num << endl;

    return 0;
}