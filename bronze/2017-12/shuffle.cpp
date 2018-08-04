#include <iostream>
#include <fstream>

using namespace std;

int N;
int id[101], a[101], b[101], c[101];

void pre_shuffle()
{
    for (int i = 1; i<=N; ++i) {
        c[i] = b[a[i]];
    }
    
    for (int i = 1; i<=N; ++i) b[i] = c[i]; 
}

int main()
{
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    in >> N;
    cout << N << endl;

    for (int i = 1; i<= N; ++i) {
        in >> a[i];
        b[i] = i;
    }

    for (int i = 1; i<= N; ++i) {
        in >> id[i];
    }

    for (int i = 0; i< 3; i++) pre_shuffle();

    for (int i = 1; i<= N; ++i) {
        cout << id[b[i]] << endl;
        out << id[b[i]] << endl;
    }
}

