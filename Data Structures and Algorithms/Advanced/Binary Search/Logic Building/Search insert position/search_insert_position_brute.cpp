#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target) {

    // size of nums
    int size = nums.size();

    // Iterate the loop
    for (int index = 0; index < size; index++) {

        // if target found or should be inserted here
        if(nums[index] >= target){
            return index;
        }
    }

    // return size if target not found
    // because insertion point is after the last element
    return size;
}