#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool numberOfStudents(vector<int>& nums, int pages ,int m) {
        int size = nums.size();
        int students = 1, studentPages = 0;

        for (int i = 0; i < size; i++) {
            if (studentPages + nums[i] <= pages) {
                studentPages += nums[i];
            } else {
                students++;
                studentPages = nums[i];
            }
        }
        return students <= m;
    }

    int findPages(vector<int> &nums, int m) {
        int size = nums.size();
        if (size < m) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        for (int i = low; i <= high; i++) {
            if (numberOfStudents(nums, i, m)) {
                return i;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    Solution obj;
    cout << "Minimum pages: " << obj.findPages(nums, m) << endl;
    return 0;
}
