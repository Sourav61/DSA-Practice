// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/

class Solution
{
public:
    // int seive[100007];
    // int distinctPrimeFactors(vector<int> &nums)
    // {
    //     int n = nums.size();

    //     unordered_map<int, int> mp;

    //     int res = 0;

    //     for (int k = 0; k < n; k++)
    //     {
    //         for (int i = 2; i <= sqrt(nums[k]); i++)
    //         {
    //             if (seive[i] == 0)
    //             {
    //                 for (int j = i * i; j <= nums[k]; j += i)
    //                 {
    //                     seive[j] = 1;
    //                 }
    //             }
    //         }
    //         for (int i = 2; i <= nums[k]; i++)
    //         {
    //             if (mp[i] == 0 && seive[i] == 0 && nums[k] % i == 0)
    //             {
    //                 mp[i] = 1;
    //                 res++;
    //             }
    //         }
    //     }

    //     return res;
    // }

    int ps[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int distinctPrimeFactors(vector<int> &nums)
    {
        unordered_set<int> primes;
        for (int n : nums)
        {
            for (int p : ps)
                if (n % p == 0)
                {
                    primes.insert(p);
                    while (n % p == 0)
                        n /= p;
                }
            if (n != 1)
                primes.insert(n);
        }
        return primes.size();
    }
};