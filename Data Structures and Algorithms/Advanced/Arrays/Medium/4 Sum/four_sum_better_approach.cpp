#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
    int size = nums.size();
    set<vector<int>> uniqueSet;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            unordered_set<long long> hashSet;

            for (int k = j + 1; k < size; k++) {
                long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                long long fourth = static_cast<long long>(target) - sum;

                if (hashSet.find(fourth) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                    sort(temp.begin(), temp.end());
                    uniqueSet.insert(temp);
                }

                hashSet.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(uniqueSet.begin(), uniqueSet.end());
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSumBetter(nums, target);

    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}