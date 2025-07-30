#include <iostream>
#include <vector>
using namespace std;

int missing_number(const vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0);

    for (int num : nums) {
        freq[num]++;
    }

    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) return i;
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing number is: " << missing_number(nums) << endl;
    return 0;
}