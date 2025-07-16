#include <vector>
using namespace std;

vector<int> insertionSort(vector<int>& nums) {
    int numsLength = nums.size();

    for (int row = 1; row < numsLength; row++) {
        int key = nums[row];
        int col = row - 1;

        while (col >= 0 && nums[col] > key) {
            nums[col + 1] = nums[col];  // Shift right
            col--;
        }

        nums[col + 1] = key;  // Insert key at correct position
    }

    return nums;
}