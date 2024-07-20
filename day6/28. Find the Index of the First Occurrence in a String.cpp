using ll = long long;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 33;
const ll RADIX1 = 26;
const ll RADIX2 = 27;

class Solution {
public:
    pair<ll, ll> hash_val(const string &str, ll m) {
        ll hash1 = 0, hash2 = 0;
        ll factor1 = 1, factor2 = 1;

        for(ll i = m - 1; i >= 0; --i) {
            hash1 = (hash1 + (str[i] - 'a') * factor1) % mod1;
            factor1 = (factor1 * RADIX1) % mod1;
            hash2 = (hash2 + (str[i] - 'a') * factor2) % mod2;
            factor2 = (factor2 * RADIX2) % mod2;
        }
        return { hash1 % mod1, hash2 % mod2 };
    }

    int strStr(const string &haystack, const string &needle) {
        ll n = haystack.size(), m = needle.size();
        if (n < m) return -1;
        if (m == 0) return 0;

        ll MAX_WT1 = 1, MAX_WT2 = 1;
        for (ll i = 1; i < m; ++i) {
            MAX_WT1 = (MAX_WT1 * RADIX1) % mod1;
            MAX_WT2 = (MAX_WT2 * RADIX2) % mod2;
        }

        pair<ll, ll> hash_needle = hash_val(needle, m);
        pair<ll, ll> hash_hay = hash_val(haystack.substr(0, m), m);

        if (hash_needle == hash_hay && haystack.substr(0, m) == needle) return 0;

        for (ll i = 1; i <= n - m; ++i) {
            hash_hay.first = (((hash_hay.first - (haystack[i - 1] - 'a') * MAX_WT1 % mod1 + mod1) * RADIX1 + (haystack[i + m - 1] - 'a')) % mod1);
            hash_hay.second = (((hash_hay.second - (haystack[i - 1] - 'a') * MAX_WT2 % mod2 + mod2) * RADIX2 + (haystack[i + m - 1] - 'a')) % mod2);

            if (hash_needle == hash_hay && haystack.substr(i, m) == needle) return i;
        }

        return -1;
    }
};
