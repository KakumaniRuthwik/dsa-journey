#include<iostream>
using namespace std;

void printPattern_ConcentricNumberSquare(int numberOfLines){
    for(int row = 0; row < (2 * numberOfLines) - 1; row++){
        for(int col = 0; col < (2 * numberOfLines) - 1; col++){

            // Compute distance from all 4 borders
            int top = row;
            int left = col;
            int right = (2 * numberOfLines) - col - 2;
            int bottom = (2 * numberOfLines) - row - 2;

            // Calculate value based on minimum distance from edge
            cout << numberOfLines - (min(min(top, bottom), min(left,right))) << " ";

        }
        cout << "\n";
    }
}

int main(){

    int numberOfLines;
    
    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_ConcentricNumberSquare(numberOfLines);

    cout << "\n";
    return 0;
}