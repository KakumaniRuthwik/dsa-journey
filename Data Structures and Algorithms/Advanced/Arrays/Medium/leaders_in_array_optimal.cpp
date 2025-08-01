#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders_optimal(const vector<int>& nums) {
    vector<int> result;
    int size = nums.size();

    int max_so_far = nums[size - 1];
    result.push_back(max_so_far);

    for (int i = size - 2; i >= 0; --i) {
        if (nums[i] > max_so_far) {
            result.push_back(nums[i]);
            max_so_far = nums[i];
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    vector<int> leaders = leaders_optimal(nums);

    cout << "Optimal Leaders: ";
    for (int num : leaders) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}