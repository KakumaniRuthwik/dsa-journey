#include <iostream>
#include <vector>
using namespace std;

// Function to count inversions using brute force
long long count_inversions_brute(vector<int>& nums) {
    int n = nums.size();
    long long count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 3, 7, 1, 3, 5};
    long long result = count_inversions_brute(nums);
    cout << "Number of inversions: " << result << endl;
    return 0;
}