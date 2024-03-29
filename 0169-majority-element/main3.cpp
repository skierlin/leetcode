#include <iostream>
#include <vector>

using namespace std;

/// 二分并递归调用
/// 时间复杂度: O(nlogn)
/// 空间复杂度: O(lgn)
class Solution {

public:
    int majorityElement(vector<int>& nums) {


        return majorityElement(nums, 0, nums.size() - 1);
    }

private:
    int majorityElement(const vector<int>& nums, int left, int right){

        int len = right - left + 1;
        if(len <= 2){
            return nums[left];
        }

        int mid = (left + right) / 2;
        int leftMajority = majorityElement(nums, left, mid);
        int rightMajority = majorityElement(nums, mid + 1, right);

        if(leftMajority == rightMajority)
            return leftMajority;

        int leftMajorityCnt = occurance(nums, left, mid, leftMajority);
        int rightMajorityCnt = occurance(nums, mid + 1, right, rightMajority);

        return leftMajorityCnt > rightMajorityCnt ? leftMajority : rightMajority;
    }

    int occurance(const vector<int>& nums, int l, int r, int target){
        int cnt = 0;
        for(int i = l ; i <= r ; i ++)
            if(nums[i] == target)
                cnt ++;
        return cnt;
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;
    return 0;
}
