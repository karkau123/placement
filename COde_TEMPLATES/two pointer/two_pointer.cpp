#include <bits/stdc++.h>
#define ll long long int
#define lp(i, a, b) for (ll i = a; i < b; i++)
#define lpa(i, a, b, x) for (ll i = a; i < b; i += x)
#define pl(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))
#define all(v) v.begin(), v.end()
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define ff first
#define ss second
using namespace std;

// Given a string s, find the length of the longest  substring  without repeating characters.
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int i = 0, j = 0, maxi = 0;
    set<char> st;
    while (j < n)
    {
        if (st.find(s[j]) == st.end())
        {
            st.insert(s[j]);
            j++;
        }
        else
        {
            while (st.find(s[j]) != st.end())
            {
                st.erase(s[i]);
                i++;
            }
        }
        maxi = max(maxi, j - i);
    }
    return maxi;
}

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxi = -1;
    int i = 0;
    int j = 0;
    int cnt_zero = 0;
    while (j < n)
    {
        if (nums[j] == 0)
        {
            cnt_zero++;
        }
        while (cnt_zero > k)
        {
            if (nums[i] == 0)
            {
                cnt_zero--;
            }
            i++;
        }
        maxi = max(maxi, j - i + 1);
        j++;
    }

    return maxi;
}

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.Return the length of the longest substring containing the same letter you can get after performing the above operations.
// TRACKING FREQUENCY
int characterReplacement(string s, int k)
{
    int n = s.size();
    map<char, int> mpp;
    int i = 0, j = 0, maxi = 0, maxfreq = 0;
    while (j < n)
    {
        mpp[s[j]]++;
        maxfreq = max(mpp[s[j]], maxfreq);
        while ((j - i + 1 - maxfreq) > k)
        {
            mpp[s[i]]--;
            if (mpp[s[i]] == 0)
                mpp.erase(s[i]);
            i++;
        }
        maxi = max(maxi, j - i + 1);
        j++;
    }
    return maxi;
}

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.A subarray is a contiguous part of the arra
// PREFIX SUM AND MAP CONCEPT
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];
        if (mpp.find(prefix_sum - goal) != mpp.end())
        {
            cnt += mpp[prefix_sum - goal];
        }
        mpp[prefix_sum] += 1;
    }
    return cnt;
}

// Given an integer array nums and an integer k, return the number of good subarrays of nums.A good array is an array where the number of different integers in that array is exactly k.
// ATMOST ATLEAST CONTRAINTS
class AtMost_pattern
{
    int atmost(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> mpp;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n)
        {
            mpp[nums[j]]++;
            while (mpp.size() > k)
            {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.Return the number of nice sub-arrays.

int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 1)
            nums[i] = 1;
        else
            nums[i] = 0;
    }
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];
        int rem = prefix_sum - k;
     
        if (mpp.find(rem) != mpp.end())
        {
            cnt += mpp[prefix_sum - k];
        }
        mpp[prefix_sum] += 1;
    }
    return cnt;
}




int main()
{

    return 0;
}
