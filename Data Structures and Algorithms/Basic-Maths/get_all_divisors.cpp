#include<iostream>
using namespace std;

vector<int> divisors(int number) {
    vector<int> result;

    for(int i = 1; i <= number / 2; i++){
        if(number % i == 0){
            result.push_back(i);
        }
    }
    result.push_back(number);
    return result;
}

int main(){

    int number;

    cout << "Enter number: ";
    cin >> number;

    vector<int> result = divisors(number);

    for(auto it : result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}