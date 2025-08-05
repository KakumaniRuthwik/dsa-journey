#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSumBruteForce(vector<int>& nums, int target) {
    int size = nums.size();
    set<vector<int>> uniqueSet;

    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; j++) {
            for (int k = j + 1; k < size - 1; k++) {
                for (int l = k + 1; l < size; l++) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        uniqueSet.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(uniqueSet.begin(), uniqueSet.end());
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSumBruteForce(nums, target);

    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}