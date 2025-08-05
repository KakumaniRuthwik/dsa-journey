#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_array(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {1, 0, 2, 1, 0};

    sort_array(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}