#include<bits/stdc++.h>
using namespace std;


//finds the length of the longest increasing subsequence in a given array of integers

void lis(vector<int> &v)
{
    int n = v.size();

    if (n == 1) {
        cout << 1;
        return;
    }

    int mx = 1, l = 1; //maximum length, length

    for(int i = 1; i < n; ++i) {
        if (v[i] > v[i - 1]) ++l;
        else {
            mx = max(l, mx);
            l = 1;
        }
    }

    cout << max(l, mx);

    return;
}

int main(){
    string s;
    int n, t;
    vector<int> v;
    cout << "insert a list of integers separated and preceded by its the size\n";
    cin >> n;
    while (n-- > 0) {
        cin >> t;
        v.push_back(t);
    }
    lis(v);
}