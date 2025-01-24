#include <iostream>

using namespace std;

int main(){
    int arr[4], ans = 1000000;
    for(int i = 0; i < 2; i++)
        cin >> arr[i];
    for(int i = 2; i < 4; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] - arr[i - 2];
    }
    for(int i = 0; i < 4; i++)
        ans = min(ans, arr[i]);
    cout << ans;
}