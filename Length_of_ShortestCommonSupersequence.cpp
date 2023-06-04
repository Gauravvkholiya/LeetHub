#include <bits/stdc++.h>
using namespace std;
int lcs(string a, string b, int m, int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (n == 0 || m == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[m - 1] == b[n - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j]);
            }
        }
    }
    int i = m;
    int j = n;
    string s = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return s.size();
}
int main()
{
    string s = "abcdgh";
    string k = "abedfha";
    int m = s.size();
    int n = k.size();
    int l = lcs(s, k, m, n);
    s = s + k;
    int length = s.size();
    cout<<m+n - l;

    return 0;
}