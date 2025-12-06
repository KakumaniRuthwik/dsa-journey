#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){

    if(x == 1.0 || n == 0){
        return 1;
    }

    long long temp = n;

    if(n < 0){
        x = 1 / x;
        temp = -1 * 1ll * n;
    }

    double result = 1;

    while(temp > 0){
        if(temp % 2 == 1){
            result *= x;
            temp -= 1;
        }else{
            x *= x;
            temp /= 2;
        }
    }

    return result;
}

int main(){
    
    cout << myPow(2.0, 20);
    return 0;
}