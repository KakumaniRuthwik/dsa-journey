#include<iostream>
using namespace std;

void printPattern_SolidRectangle(int numberOfLines){
    for(int row = 0; row < numberOfLines; row++){
        for(int col = 0; col < numberOfLines; col++){
            cout << "* ";
        }
        cout << "\n";
    }
}


int main(){

    int numberOfLines;

    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_SolidRectangle(numberOfLines);
    return 0;
}
