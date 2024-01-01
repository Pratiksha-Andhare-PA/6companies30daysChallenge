class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long int low = 1, high = INT_MAX;
        int ans = INT_MAX;
        long long int lcm = ((long long)divisor1*divisor2)/__gcd(divisor1,divisor2);

        while(low <= high){
            int mid = low + (high-low)/2;
            int notd1 = mid - mid/divisor1;   //not divisible by divisor1
            int notd2 = mid - mid/divisor2;   //not divisible by divisor2
            int notboth = mid - mid/lcm;      //not divisible by both

            if(notd1 >= uniqueCnt1 && notd2 >= uniqueCnt2 && notboth >= (uniqueCnt1+uniqueCnt2)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
