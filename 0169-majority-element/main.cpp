#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 排序后取中值
/// 时间复杂度 O(nlogn)
/// 空间复杂度 O(1)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;

    return 0;
}
