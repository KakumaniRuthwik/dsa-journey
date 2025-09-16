#include <bits/stdc++.h>
using namespace std;

// Helper function to check if allocation is possible with max pages = pages
bool numberOfStudents(vector<int>& nums, int pages, int m) {
    int students = 1, studentPages = 0;
    for (int book : nums) {
        if (studentPages + book <= pages) {
            studentPages += book;
        } else {
            students++;
            studentPages = book;
        }
    }
    return students <= m;
}

// Optimal: O(n * log(sum-max))
int findPages(vector<int> &nums, int m) {
    int n = nums.size();
    if (n < m) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (numberOfStudents(nums, mid, m)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;
    cout << "Minimum pages: " << findPages(nums, m) << endl;
    return 0;
}
