#include<iostream>
#include<vector>
using namespace std;

void learnVector(){
    
    // Declaring Vector array
    vector<int> arr = {0,1,2,3}; 

    // Pushing element at the end.
    arr.push_back(4);
    arr.push_back(5);

    arr.insert(arr.begin(),10);

    // finding size of the array
    cout << "Size of Array: " << arr.size() << endl; // .size()

    //Method 1: For Loop
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;

    /* Method 2 : Iterator
        vector<int>::iterator beginItr = arr.begin();
        vector<int>::iterator endItr = arr.end();
        
        (or)
        
        auto beginItr = arr.begin();
        auto endItr = arr.end();
    */

    auto beginItr = arr.begin();
    auto endItr = arr.end();
    for(auto i = beginItr; i < endItr; i++){
        cout << *i << " ";
    }
    cout << endl;

    // Method 3: For each loop

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    // Printing from backside
    cout << "Reversed: " ;
    for(auto i = arr.rbegin(); i < arr.rend(); i++){
        cout << *i << " ";
    }
    cout << endl;

    arr.clear();

    cout << "Cleared: " ;
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

}

int main(){

    learnVector();

    return 0;
}