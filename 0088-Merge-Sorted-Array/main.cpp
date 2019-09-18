
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() == m + n && nums2.size() == n);

        for(int i = 0; i < n ; i ++ )
            nums1[m + i] = nums2[i];

        sort(nums1.begin(), nums1.end());
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

