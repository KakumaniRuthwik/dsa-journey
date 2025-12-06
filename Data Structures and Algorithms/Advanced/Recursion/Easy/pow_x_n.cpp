#include<bits/stdc++.h>
using namespace std;

double myPow(double x, long long n){

    if(n == 0) return 1;

    if(n < 0){
        return myPow((1 / x), -n);
    }

    if((n % 2) == 1){
        return (x * myPow(x, n - 1));
    }

    return myPow((x * x), n / 2);
}

int main(){
    
    cout << myPow(2.0, 20);
    return 0;
}