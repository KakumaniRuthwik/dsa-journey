#include<iostream>
using namespace std;


long long mod = 1000000007;

long long myPow(long long x, long long n){

    if(n == 0) return 1;

    if(n == 1) return (x % mod);

    long long temp = n;
    long long result = 1;

    while(temp > 0){
        if((temp % 2) != 0){
            result = (result * x) % mod;
            temp -= 1;
        }

        x = (x * x) % mod;
        temp /= 2;
    }

    return result;
}

// Count good numbers based on:
// Even positions → 5 choices
// Odd positions  → 4 choices
int countGoodNumbers(long long n){
    
    long long evenPositions = (n + 1) / 2; // index 0,2,4...
    long long oddPositions  = n / 2;       // index 1,3,5...

    long long evenProduct = myPow(5, evenPositions);
    long long oddProduct = myPow(4, oddPositions);

    long long result = (evenProduct * oddProduct) % mod;

    return (int)result;
}

int main(){
    
    long long n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Count of good numbers: " << countGoodNumbers(n) << endl;

    return 0;
}