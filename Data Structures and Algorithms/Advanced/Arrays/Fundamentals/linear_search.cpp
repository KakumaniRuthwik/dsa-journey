#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 7, 2, 9};
    int target = 2;

    int result = linearSearch(nums, target);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}