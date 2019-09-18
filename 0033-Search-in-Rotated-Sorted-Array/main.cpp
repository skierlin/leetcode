
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        while(l <= r){
            //cout << "l : " << l << " r : " << r << endl;
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
             //cout << "mid : " << mid << endl;

            if(target < nums[mid]){
                if(nums[l] <= nums[r] || nums[mid] < nums[l])
                    r = mid - 1;
                else if(target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else{ // target > nums[mid]
                if(nums[l] <= nums[r] || nums[mid] > nums[r])
                    l = mid + 1;
                else if(target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};
