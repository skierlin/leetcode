class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int n = nums1.size(), m = nums2.size();
        if(n == 0) return m % 2 ? nums2[m / 2] : (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
        int half = (n + m) / 2;

        int l = 0, r = n;
        while(l <= r){
            int mid = (l + r) / 2;

            int i1 = mid, i2 = half - i1;

            int leftMax = i1 == 0 ? nums2[i2 - 1] :
                          i2 == 0 ? nums1[i1 - 1] : max(nums1[i1 - 1], nums2[i2 - 1]);
            int rightMin = i1 == n ? nums2[i2] :
                           i2 == m ? nums1[i1] : min(nums1[i1], nums2[i2]);

            if(leftMax <= rightMin){
                if((n + m) % 2 == 1)
                    return rightMin;
                else{
                    int nums1Left = i1 == 0 ? INT_MIN :
                                    i1 == 1 ? nums1[i1 - 1] : max(nums1[i1 - 1], nums1[i1 - 2]);
                    int nums1Right = i1 == n ? INT_MAX :
                                     i1 == n - 1 ? nums1[i1] : min(nums1[i1], nums1[i1 + 1]);
                    int nums2Left = i2 == 0 ? INT_MIN :
                                    i2 == 1 ? nums2[i2 - 1] : max(nums2[i2 - 1], nums2[i2 - 2]);
                    int nums2Right = i2 == m ? INT_MAX :
                                     i2 == m - 1 ? nums2[i2] : min(nums2[i2], nums2[i2 + 1]);
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            }
            else if(nums1[i1] == rightMin)
                l = mid + 1;
            else
                r = mid - 1;
        }
        assert(false);
        return -1;
    }
};

