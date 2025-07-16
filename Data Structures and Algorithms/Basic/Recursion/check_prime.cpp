#include <iostream>
using namespace std;

bool prime(int num, int x) {
    if (x * x > num) return true;
    if (num % x == 0 || num % (x + 2) == 0) return false;
    return prime(num, x + 6);
}

bool checkPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    return prime(num, 5);
}

int main() {
    int num;
    cin >> num;
    cout << (checkPrime(num) ? "Prime" : "Not Prime") << endl;
    return 0;
}