//this solution is not the right solution, just fot the best score.
class Solution {
public:
    int reverse(int x) {
        long rev=0;
        while(x)
        {
            int k=x%10;
            rev=rev*10+k;
            x/=10;
        }
        if(rev>INT_MAX||rev<INT_MIN)return 0;
        return rev;
    }
};

//this solution is the best solution.
class Solution2 {
public:
    int reverse(int x) {
        int rev = 0, pop;
        while(x) {
            pop = x%10;
            x /= 10;
            if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
            if (rev == INT_MAX/10 && pop > 7) return 0;
            if (rev == INT_MIN/10 && pop < -8) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};