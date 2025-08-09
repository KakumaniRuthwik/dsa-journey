#include <bits/stdc++.h>
using namespace std;

void helperFunc(int ind, vector<int> &nums, vector<vector<int>> &ans) {
    if (ind == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++) {
        swap(nums[ind], nums[i]);
        helperFunc(ind + 1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> getAllPermutations(vector<int> &nums) {
    vector<vector<int>> ans;
    helperFunc(0, nums, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

void nextPermutationBrute(vector<int> &nums) {
    vector<vector<int>> allPerms = getAllPermutations(nums);
    int index = -1;
    for (int i = 0; i < allPerms.size(); i++) {
        if (nums == allPerms[i]) {
            index = i;
            break;
        }
    }
    if (index == allPerms.size() - 1) nums = allPerms[0];
    else nums = allPerms[index + 1];
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Given array: ";
    for (int x : nums) cout << x << " ";

    nextPermutationBrute(nums);

    cout << "\nNext Permutation: ";
    for (int x : nums) cout << x << " ";
}