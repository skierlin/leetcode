#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// 使用unordered_map（哈希表）
/// 时间复杂度 O(n)
/// 空间复杂度 O(n)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> records;
        for(int num: nums)
            records[num] ++;

        for(pair<int, int> record: records)
            if(record.second > nums.size()/2)
                return record.first;
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;

    return 0;
}
