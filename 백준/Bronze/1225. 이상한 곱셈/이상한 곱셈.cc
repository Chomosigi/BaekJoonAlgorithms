#include <iostream>

using namespace std;

int main(){
    string n, m;
    long long int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n.size(); i++)
    {
        for(int j = 0; j < m.size(); j++)
            ans += (n[i] - '0') * (m[j] - '0');
    }
    cout << ans;
}