#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    vector<int> get_floor_and_ceil(vector<int>& nums, int x) {
        int floor = -1, ceil = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= x && nums[i] > floor){
                floor = nums[i];
            }
            if (nums[i] >= x && (ceil == -1 || nums[i] < ceil)){ 
                ceil = nums[i];
            }
        }
        return {floor, ceil};
    }
};

int main() {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    SolutionBrute sb;
    vector<int> result = sb.get_floor_and_ceil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}