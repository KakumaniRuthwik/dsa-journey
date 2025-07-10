#include<iostream>
using namespace std;

void printPattern_InvertedNumberedRightPyramid(int numberOfLines){
    for(int row = numberOfLines; row >= 1; row--){
        for(int col = 1; col <= row; col++){
            cout << col << " ";
        }
        cout << "\n";
    }
}

int main(){

    int numberOfLines;
    
    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_InvertedNumberedRightPyramid(numberOfLines);
    cout << "\n";

    return 0;
}