#include <iostream>
using namespace std;

int NnumbersSum(int N) {
    if (N == 0) {
        return 0;
    }

    return N + NnumbersSum(N - 1);
}

int main() {
    int N;
    cin >> N;
    cout << "Sum of first " << N << " natural numbers is: " << NnumbersSum(N) << endl;
    return 0;
}