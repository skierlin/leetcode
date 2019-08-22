class Solution {
public:
    int singleNumber(vector<int>& nums) {

        assert(nums.size()%2 == 1);

        unordered_set<int> hashtable;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(hashtable.find(nums[i]) == hashtable.end())
                hashtable.insert(nums[i]);
            else
                hashtable.erase(nums[i]);

        assert(hashtable.size() == 1);
        return *hashtable.begin();
    }
};
