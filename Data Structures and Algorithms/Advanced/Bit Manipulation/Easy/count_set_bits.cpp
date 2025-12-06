#include<iostream>
using namespace std;

int countSetBits(int num){

    int count = 0;

   while(num != 0){
        num &= (num - 1); // removes the lowest set bit
        count++;         // count how many bits were removed
    }

    return count;
}

int main(){

    int num = 13;

    cout << countSetBits(num) << " bits are present in " << num << endl;

    return 0;
}