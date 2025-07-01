#include<iostream>
using namespace std;

void printPattern_StarPyramid(int numberOfLines){
    for(int row = 0; row < numberOfLines; row++){
        // Loop for creating spaces
        // Space calculation = (n - 1 - i)
        for(int spaces = 0; spaces < (numberOfLines - 1 - row); spaces++){
            cout << "  ";
        }

        // Loop for stars
        // Stars calculation = (2 * i) + 1
        for(int stars = 0; stars < ((2 * row) + 1); stars++){
            cout << "* ";
        }

        cout << "\n";
    }
}

void printPattern_ReversedStarPyramid(int numberOfLines){
    for(int row = numberOfLines - 1; row >= 0; row--){
        // Loop for creating spaces
        // Space calculation = (n - 1 - i)
        for(int spaces = 0; spaces < (numberOfLines - 1 - row); spaces++){
            cout << "  ";
        }

        // Loop for stars
        // Stars calculation = (2 * i) + 1
        for(int stars = 0; stars < ((2 * row) + 1); stars++){
            cout << "* ";
        }

        cout << "\n";
    }
}

void printPattern_DiamondStar(int numberOfLines){
    printPattern_StarPyramid(numberOfLines);
    printPattern_ReversedStarPyramid(numberOfLines);
}

int main(){

    int numberOfLines;

    cout << "Enter number of lines:";
    cin >> numberOfLines;

    printPattern_DiamondStar(numberOfLines);

    return 0;
}