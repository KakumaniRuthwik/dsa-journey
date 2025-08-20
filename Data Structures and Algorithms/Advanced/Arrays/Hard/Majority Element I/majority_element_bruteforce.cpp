#include <iostream>
#include <vector>
using namespace std;

int majorityElementBruteForce(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        int elementCount = 0;
        for (int j = 0; j < size; j++) {
            if (nums[i] == nums[j]) {
                elementCount++;
            }
        }
        if (elementCount > size / 2) {
            return nums[i];
        }
    }
    return -1; // Should never happen as per problem guarantee
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element (Brute Force): " 
         << majorityElementBruteForce(nums) << endl;
    return 0;
}