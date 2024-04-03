#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pl = pair<ll, int>;

#define f first
#define s second

int main() {
    int n, k; 
    cin >> n >> k;
 
    vector<ll> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
	
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    for (int i = 0; i < k; i++) pq.push({t[i], i});

    int cur_cow = k;
    pl last;
    vector<vector<int>> events;
    
    while (true) {
        vector<pl> ev;
        do {
            ev.push_back(pq.top());
            pq.pop();
        } while (!pq.empty() && pq.top().f == ev[0].f);
        
        if (ev.size() > 1) {
            vector<int> farmers;
            for (pl e : ev) farmers.push_back(e.s);
            events.push_back(farmers);
        }
        
        if (cur_cow + ev.size() > n) {
            last = ev[0];
            break;
        }

        for (pl e : ev) {
            pq.push({e.f + t[cur_cow], e.s});
            cur_cow++;
        }
    }

    cout << last.f << "\n";
    
    vector<bool> can_interview(k, false);
    can_interview[last.s] = true;
    
    for (int i = (int)events.size()-1; i >= 0; i--) {
        bool intersect = false;
        for (int j : events[i]) {
            if (can_interview[j]) {
                intersect = true;
                break;
            }
        }
        if (intersect) {
            for (int j : events[i]) {
                can_interview[j] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        cout << can_interview[i] << "";
    }
    cout << "\n";
}

