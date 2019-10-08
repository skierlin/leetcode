
class Solution {

private:

    vector<vector<int>> res;
    vector<bool> used;

    void generatePermutation(const vector<int>& nums, int index, vector<int>& p){

        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i ++)
            if(!used[i]){
                used[i] = true;
                p.push_back(nums[i]);
                generatePermutation(nums, index + 1, p );
                p.pop_back();
                used[i] = false;
            }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        if(nums.size() == 0)
            return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

