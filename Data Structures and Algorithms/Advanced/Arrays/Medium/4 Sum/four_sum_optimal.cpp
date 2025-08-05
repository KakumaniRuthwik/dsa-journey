#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> four_sum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < size; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        for(int j = i + 1; j < size; j++) {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = size - 1;

            while(k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                } else if(sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = four_sum(nums, target);

    for(const auto& quad : result) {
        for(int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}