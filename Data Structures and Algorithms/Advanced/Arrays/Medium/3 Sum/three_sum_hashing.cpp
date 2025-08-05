#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> three_sum_hashing(vector<int>& nums) {
    int size = nums.size();
    set<vector<int>> tripletSet;

    for (int i = 0; i < size - 1; i++) {
        set<int> complements;

        for (int j = i + 1; j < size; j++) {
            int complement = -(nums[i] + nums[j]);

            if (complements.find(complement) != complements.end()) {
                vector<int> temp = {nums[i], nums[j], complement};
                sort(temp.begin(), temp.end());
                tripletSet.insert(temp);
            }

            complements.insert(nums[j]);
        }
    }

    return vector<vector<int>>(tripletSet.begin(), tripletSet.end());
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = three_sum_hashing(nums);

    for (auto triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}