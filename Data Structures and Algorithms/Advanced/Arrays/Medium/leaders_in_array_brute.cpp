#include <iostream>
#include <vector>
using namespace std;

vector<int> leaders_brute(const vector<int>& nums) {
    vector<int> result;
    int size = nums.size();

    for (int i = 0; i < size; ++i) {
        bool is_leader = true;
        for (int j = i + 1; j < size; ++j) {
            if (nums[i] <= nums[j]) {
                is_leader = false;
                break;
            }
        }
        if (is_leader) {
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    vector<int> leaders = leaders_brute(nums);

    cout << "Brute Force Leaders: ";
    for (int num : leaders) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}