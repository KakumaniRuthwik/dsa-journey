#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum_brute(vector<int>& nums, int target) {
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1}; // If no valid pair is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = two_sum_brute(nums, target);

    if (result[0] != -1) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}