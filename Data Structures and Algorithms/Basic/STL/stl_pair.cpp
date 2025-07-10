#include <iostream>
#include <utility>
using namespace std;

void learnPair(){

    // Declare a pair of two ints
    pair<int, int> pair1 = {1, 2};

    // Access elements using .first and .second
    cout << pair1.first << " " << pair1.second;
    cout << endl;

    pair<pair<int, int>, int> pair2= {{1,2}, 3};
    cout << pair2.first.first << " " << pair2.first.second << " " << pair2.second;
    
}

int main(){

    learnPair();
    cout << endl;
    
    return 0;
}