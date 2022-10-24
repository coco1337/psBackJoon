#include <iostream>
#include <vector>
using namespace std;
int n, t, ans;
vector<int> v(101);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    cin >> t;
    
    for (int i = 0; i < n; ++i) {
        if (v[i] == t) ans++;
    }
    
    cout << ans;
    
    return 0;
}