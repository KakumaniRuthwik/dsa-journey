#include <iostream>
#include <vector>
using namespace std;

int missing_number(const vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing number is: " << missing_number(nums) << endl;
    return 0;
}