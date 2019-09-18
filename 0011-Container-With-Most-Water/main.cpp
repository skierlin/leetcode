
class Solution {
public:
    int maxArea(vector<int>& height) {

        assert(height.size() >= 2);

        int area = 0;
        for(int i = 0 ; i < height.size() ; i ++)
            for(int j = i + 1; j < height.size() ; j ++)
                area = max(area , min(height[i], height[j]) * (j - i));
        return area;
    }
};

