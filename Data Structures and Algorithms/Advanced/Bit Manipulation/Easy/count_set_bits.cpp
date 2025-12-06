#include<iostream>
using namespace std;

int countSetBits(int num){

    int count = 0;

    while(num > 0){
        if(num % 2 == 1){
            count++;
        }

        num /= 2;
    }

    return count;
}

int main(){

    int num = 13;

    cout << countSetBits(num) << " bits are present in " << num << endl;

    return 0;
}