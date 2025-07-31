#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> unionArrayBruteForce(const vector<int>& nums1, const vector<int>& nums2) {
    set<int> s;
    for (int num : nums1) s.insert(num);
    for (int num : nums2) s.insert(num);
    return vector<int>(s.begin(), s.end());
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 4, 4, 5, 6};
    
    vector<int> result = unionArrayBruteForce(nums1, nums2);

    cout << "Union: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}