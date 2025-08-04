#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrderMatrix(vector<vector<int>>& matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, left = 0;
    int right = m - 1, bottom = n - 1;

    vector<int> result;

    while(top <= bottom && left <= right){
        
        // Traverse from Left to Right (Top Row)
        for(int index = left; index <= right; index++){
            result.push_back(matrix[top][index]);
        }
        top++;

        // Traverse from Top to Bottom (Right Column)
        for(int index = top; index <= bottom; index++){
            result.push_back(matrix[index][right]);
        }
        right--;

        // Traverse from Right to Left (Bottom Row)
        if(top <= bottom){
            for(int index = right; index >= left; index--){
                result.push_back(matrix[bottom][index]);
            }
            bottom--;
        }

        // Traverse from Bottom to Top (Left Column)
        if(left <= right){
            for(int index = bottom; index >= top; index--){
                result.push_back(matrix[index][left]);
            }
            left++;
        }
    }

    return result;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int> result = spiralOrderMatrix(matrix);

    for(auto num : result){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}