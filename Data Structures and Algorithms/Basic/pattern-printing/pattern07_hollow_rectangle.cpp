#include<iostream>
using namespace std;

void printPattern_HollowRectangle(int numberOfLines){
    for(int row = 0; row < numberOfLines; row++){
        for(int col = 0; col < numberOfLines; col++){
            if(row == 0 || row == numberOfLines - 1 || col == 0 || col == numberOfLines - 1){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

int main(){

    int numberOfLines;

    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_HollowRectangle(numberOfLines);

    return 0;
}