#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> Lps(string &pat)
{
    int i = 1;
    int len = 0;
    int n = pat.size();
    vector<int> arr(n);
    arr[0] = 0;
    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            arr[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = arr[len - 1];
            }
            else
            {
                arr[i] = 0;
                i++;
            }
        }
    }
    return arr;
}

vector<int> kmp(string &pat, string &txt)
{
    int i = 0, j = 0;
    vector<int> result;
    int M = pat.size();
    int n = txt.size();
    vector<int> lps = Lps(pat);
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            result.push_back(i - M + 1);
            j = lps[j - 1];
        }
        else if (txt[i] != pat[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
                i++;
        }
    }
    return result;
}

int main()
{
    // output is for 1 based indexing 
    string pat="aaba",txt="aabaacaadaabaaba";
    for(auto i:kmp(pat,txt))
    {
        cout<<i<<" ";
    }
    return 0;
}