#include<iostream>
using namespace std;

void printPattern_NumberCrown(int numberOfLines){
    for(int row = 1; row <= numberOfLines; row++){
        for(int leftcol = 1; leftcol <= row; leftcol++){
            cout << leftcol;
        }
        
        for(int spaces = 1; spaces <= 2 * (numberOfLines - row); spaces++){
            cout << " ";
        }

        for(int rightcol = row; rightcol >= 1; rightcol--){
            cout << rightcol;
        }

        cout << "\n";
    }
    
}

int main(){

    int numberOfLines;

    cout << "Enter number of lines: ";
    cin >> numberOfLines;

    printPattern_NumberCrown(numberOfLines);

    return 0;
}

