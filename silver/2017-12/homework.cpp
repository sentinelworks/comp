#include <iostream>
#include <fstream>
using namespace std;

int N;
int a[100001];
float highest[100001];

int min_value(int k)
{
    int mins = a[k];

    for (int i = k+1; i<=N; ++i) if (mins > a[i]) mins = a[i];
    return mins;
}

int result(ofstream &out)
{
    int sum = 0;
    int mins = min_value(1);

    for (int i =1; i<= N; i++) sum += a[i];

    for (int k = 1; k<= N-2; ++k) {
        sum -= a[k];
        if (mins == a[k]) mins = min_value(k+1);
        highest[k] = (sum - mins);
        highest[k] /= (N-k-1); 
    }

    //output

    float big = highest[1];
    for (int k = 2; k<=N-2; ++k) if (big < highest[k]) big = highest[k];

    for (int k = 1; k<= N-2; ++k) {
        if(big == highest[k]) out << k << endl;
    }

    return 0;
}

int main()
{
    ifstream in("homework.in");
    ofstream out("homework.out");
    in >> N;
    for (int i=1; i<=N; ++i) {
        in >> a[i];
    }

    result(out);

    return 0;
}
