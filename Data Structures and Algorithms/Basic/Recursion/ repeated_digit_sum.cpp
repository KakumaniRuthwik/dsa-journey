#include <iostream>
using namespace std;

int digitSum(int num, int sum) {
    if (num == 0) return sum;
    return digitSum(num / 10, sum + (num % 10));
}

int addDigits(int num) {
    if (num < 10) return num;
    return addDigits(digitSum(num, 0));
}

int main() {
    int num;
    cin >> num;
    cout << "Single digit result: " << addDigits(num) << endl;
    return 0;
}