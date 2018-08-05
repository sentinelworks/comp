#include <iostream>
#include <fstream>
using namespace std;

int N;
int a[100001];
int b[100001];
int c[100001];

int shuffle()
{
    int cnt = 0;

    for (int i = 1; i<=N; ++i) c[i] = 0;

    for (int i = 1; i<=N; ++i) {
        if (b[i] != 0) {
            if (c[a[i]] == 0) {
                cnt++;
                c[a[i]] = 1;
            }
        }
    }

    for (int i = 1; i<=N; ++i) b[i] = c[i];

    cout << cnt << endl;
    return cnt;
}

int main()
{
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    in >> N;
    for (int i=1; i<=N; ++i) {
        in >> a[i];
        b[i] = 1;
    }

    int prev, cnt = N;

    do {
        prev = cnt;
        cnt = shuffle();
    } while (cnt != prev);

    cout << cnt << endl;
    out << cnt << endl;

    return 0;
}
