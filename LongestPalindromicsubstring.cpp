#include<bits/stdc++.h>
using namespace std;
string lcs (string a,string b,int n ,int m )
{
    int t[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
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
    string k = "";
    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            k.push_back(a[i - 1]);
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
    reverse(k.begin(), k.end());
    return k;
}
int main()
{
    string s;
    cout<<"enter the string ";
    cin>>s;
    cout<<s.size();
    string y =s;
    reverse(s.begin(),s.end());
    int m = 5;
    int n = 5;
    string k = lcs(s,y,n,m);
    cout<<"the lps is :"<<endl;
    cout<<k;
return 0;
}