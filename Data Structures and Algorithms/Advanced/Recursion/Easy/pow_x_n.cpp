#include<iostream>
using namespace std;

double myPow(double x, int n){

    if(x == 1.0 || n == 0){
        return 1.0;
    }

    long long temp = n;  // convert to long long to avoid overflow

    if(n < 0){
        x = 1 / x;
        temp = -1 * 1ll * n; // convert n to a positive long long value

    }

    double result = 1;

    for(long long i = 0; i < temp; i++){
        result *= x;
    }

    return result;
}