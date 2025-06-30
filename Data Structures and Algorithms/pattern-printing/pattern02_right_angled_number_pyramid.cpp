#include<iostream>
using namespace std;

void printPattern_RightAngledNumberPyramid(int numberOfLines){
    for(int row = 1; row <= numberOfLines; row++){
        for(int col = 1; col <= row; col++){
            cout << col << " ";
        }
        cout <<"\n";
    }
}

int main(){

    int numberOfLines;
    
    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_RightAngledNumberPyramid(numberOfLines);
    cout << "\n";

    return 0;
}