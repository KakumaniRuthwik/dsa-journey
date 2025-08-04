#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> two_sum_hashmap(vector<int>& nums, int target) {
    unordered_map<int, int> freq;

    for (int index = 0; index < nums.size(); index++) {
        int complement = target - nums[index];
        if (freq.find(complement) != freq.end()) {
            return {freq[complement], index};
        }
        freq[nums[index]] = index;
    }

    return {-1, -1}; // No valid pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = two_sum_hashmap(nums, target);

    if (result[0] != -1) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}