#include <iostream>
#include <vector>
using namespace std;

int reversePairs(vector<int>& nums) {
    int size = nums.size();
    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(nums[i] > 2 * nums[j]){
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << reversePairs(nums) << endl;
    return 0;
}