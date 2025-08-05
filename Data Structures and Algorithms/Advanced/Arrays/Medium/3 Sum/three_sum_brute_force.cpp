#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> three_sum(vector<int>& nums) {
    int size = nums.size();
    set<vector<int>> triplet_set;

    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    
                    // Manual sort to reduce overhead of std::sort
                    if (temp[0] > temp[1]) swap(temp[0], temp[1]);
                    if (temp[1] > temp[2]) swap(temp[1], temp[2]);
                    if (temp[0] > temp[1]) swap(temp[0], temp[1]);

                    triplet_set.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(triplet_set.begin(), triplet_set.end());
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = three_sum(nums);

    cout << "Triplets with sum 0 are:" << endl;
    for (auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}