class Solution {
public:
    long mod = 1e9 + 7;

    int pow(long long num, long long p) {
        if (p == 0) {
            return 1;
        }
        long long temp = pow(num, p / 2);
        temp = (temp*temp) % mod;

        if (p % 2) {
            temp = (temp * (num % mod)) % mod;
        }
        return (temp % mod);
    }

    int minNonZeroProduct(int p) {
        long long num = (1ll << p) - 1;
        return (num % mod) * pow(num-1, num/2) % mod;
    }
};
