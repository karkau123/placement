#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
using namespace std;

int solve(int n, ll k, vector<ll> &arr)
{
    bool ae = true;
    int i = 0;
    while (i < n)
    {
        if (arr[i] != k)
        {
            ae = false;
            break;
        }
        i++;
    }

    if (ae)
    {
        return 0;
    }

    int ff = -1, ss = n;
    i = 0;
    while (i < n)
    {
        if (arr[i] != k)
        {
            if (ff == -1)
            {
                ff = i;
            }
            ss = i;
        }
        i++;
    }

    if (ff == ss)
    {
        return 1;
    }
    else
    {
        bool same = true, allDivisible = true;
        ll firstXOR = (arr[ff] ^ k);
        int i = ff;
        while (i <= ss)
        {
            if (arr[i] % k != 0)
                allDivisible = false;
            if ((arr[i] ^ k) != firstXOR)
                same = false;
            i++;
        }

        if (same || allDivisible)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;

        vll arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << solve(n, k, arr) << endl;
    }
    return 0;
}
