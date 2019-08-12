
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

