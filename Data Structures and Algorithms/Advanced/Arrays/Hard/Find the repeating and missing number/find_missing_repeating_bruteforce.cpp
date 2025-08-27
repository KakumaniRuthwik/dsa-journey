#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int size = nums.size();
        int missing = -1;
        int repeating = -1;

        for (int i = 1; i <= size; i++) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (i == nums[j]) {
                    count++;
                }
            }

            if (count == 2) {
                repeating = i;
            } else if (count == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }
        }

        return {repeating, missing};
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 5, 4, 1, 1};
    vector<int> result = obj.findMissingRepeatingNumbers(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}