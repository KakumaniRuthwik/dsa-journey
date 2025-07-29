#include <iostream>
#include <vector>
using namespace std;

int remove_duplicates(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;

    int pos1 = 0;

    for (int pos2 = 1; pos2 < size; pos2++) {
        if (nums[pos1] != nums[pos2]) {
            pos1++;
            nums[pos1] = nums[pos2];
        }
    }

    return pos1 + 1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int new_length = remove_duplicates(nums);

    cout << "Length after removing duplicates: " << new_length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < new_length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}