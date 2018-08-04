#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> name;

struct measure
{
    int days;
    string name;
    int change;
    bool operator < (const measure &o) const {
        return days < o.days;
    }
};

int change(int g[])
{
    int m = g[0];

    if (g[1]>m) m = g[1];
    if (g[2]>m) m = g[2];

    int lead = 0;
    if (g[0] == m) lead |= 1;
    if (g[1] == m) lead |= 2;
    if (g[2] == m) lead |= 4;

    return lead;
}

int main()
{
    ifstream in("measurement.in");
    ofstream out("measurement.out");

    int N;
    in >> N;
    measure m[N];

    for (int i=0; i< N; ++i) {
        in >> m[i].days >> m[i].name >> m[i].change;
    }

    for (int i=0; i< N; ++i) {
        cout << m[i].days << ' ' << m[i].name << ' ' << m[i].change << "\n";
    }

    sort(m, m+N);

    int gallon[3];
    int cnt = 0;
    for (int i = 0; i < 3; ++i) gallon[i] = 7;
    int lead = 7;

    for (int i=0; i< N; ++i) {
        if (m[i].name == "Bessie") {
            gallon[0] += m[i].change;
        } else if (m[i].name == "Elsie") {
            gallon[1] += m[i].change;
        } else {
            gallon[2] += m[i].change;
        }
        int nc = change(gallon);

        if (nc != lead) {
            lead = nc;
            cnt++;
        }
    }

    cout << cnt << endl;
    out << cnt << endl;

    return 0;
}
