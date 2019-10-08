
class Solution {
public:
    int reverse(int x) {

        if(x == 0)
            return x;

        int sign = x > 0 ? 1 : -1;

        long long num = abs(x);
        long long reverseNum = 0;
        while(num){
            reverseNum = reverseNum * 10 + num % 10;
            num /= 10;
        }

        reverseNum *= sign;
        if(reverseNum > INT_MAX || reverseNum < INT_MIN)
            return 0;
        return reverseNum;
    }
};

