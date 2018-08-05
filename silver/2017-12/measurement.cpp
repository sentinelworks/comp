#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct measure
{
    int days;
    int id;
    int change;
    bool operator < (const measure &o) const {
        return days < o.days;
    }
};

int N, G;
map<int, int> name;
measure m[100000];
ofstream out("measurement.out");

int find_max(int g[], int n)
{
    int maxv=g[0];

    for (int i=1;i<n; ++i) if(g[i]>maxv) maxv = g[i];
//    cout << "maxv=" << maxv << endl;
    return maxv;
}

void change(int n)
{
    int g[n];
    bool b[n];

    for (int i=0; i<n; ++i) {
        g[i] = G;
        b[i] = true;
    }

    int maxv = G;
    int t, cnt=0;

    for (int i = 0; i<N; ++i) {
        int k = name[m[i].id];
        g[k] += m[i].change;
        if(g[k] > maxv) maxv = g[k];
        else {
            if(g[k] - m[i].change == maxv) { 
                maxv = find_max(g, n);
            }
        }

        t=0;
        for (int j= 0; j<n; ++j) {
            bool lead = g[j]>=maxv;
            if (lead != b[j]) {
                b[j] = lead;
                t++;
            }
        }
//        cout << " t = " << t << endl;
        if (t>0) cnt++;
    }

    cout << "cnt: " << cnt << endl;
    out << cnt << endl;
}

int main()
{
    ifstream in("measurement.in");

    in >> N >> G;

    int num = 0;
    for (int i=0; i< N; ++i) {
        in >> m[i].days >> m[i].id >> m[i].change;
        if (name.find(m[i].id) == name.end()) {
            name[m[i].id] = num++;
        }
    }

    sort(m, m+N);

#if 0
    for (int i=0; i< N; ++i) {
        cout << m[i].days << ' ' << m[i].id << ' ' << m[i].change << "\n";
    }
#endif

    change(num);

    return 0;
}
