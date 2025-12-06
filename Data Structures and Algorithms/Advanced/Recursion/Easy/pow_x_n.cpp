#include<iostream>
using namespace std;

double power(double x, long long n){
    if(n == 0) return 1;

    if(n == 1) return x;

    if(n % 2 == 1){
        return x * power(x, n - 1);
    }

    return power(x * x, n / 2);
}

double myPow(double x, int n) {

    long long num = n;

    if(num < 0){
        return (1.0 / power(x, -num));
    }

    return power(x, num);
}

int main(){
    
    cout << myPow(2.0, 20);
    return 0;
}