#include <iostream>
#include <fstream>

using namespace std;

struct board
{
    int x0, y0, x1, y1;
};

int area(int x0, int y0, int x1, int y1) 
{
    return (y1-y0)*(x1-x0);
}

int area(board &b)
{
    return area(b.x0, b.y0, b.x1, b.y1);
}

int
overlap(board &b1, board &b2)
{
    if (b2.x0 >= b1.x1 || b2.x1 <= b1.x0 || b2.y0 >= b1.y1 || b2.y1 <= b1.y0) return 0;

    int x0 = max(b1.x0, b2.x0);
    int y0 = max(b1.y0, b2.y0);
    int x1 = min(b1.x1, b2.x1);
    int y1 = min(b1.y1, b2.y1);

    int a = area(x0, y0, x1, y1);
    cout << "overlap " << a << endl;
    return a;
}

int main()
{
    board b[3];  // 2 boards, truck
    ifstream in("billboard.in");
    ofstream out("billboard.out");

    for (int i = 0; i< 3; ++i) {
        in >> b[i].x0;
        in >> b[i].y0;
        in >> b[i].x1;
        in >> b[i].y1;
    }

    int a = area(b[0]) + area(b[1]) - overlap(b[0], b[2]) - overlap(b[1], b[2]);
    cout << a << endl;
    out << a << endl;
}

