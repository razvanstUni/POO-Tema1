#include <iostream>
#include "PQueue.cpp"
using namespace std;

int main() {
    PQueue q;
    q.insert(5,0);
    q.insert(7,1);
    q.insert(6,0);
    q.insert(1,0);

    cout << q;

    PQueue q2;
    q2.insert(4,2);
    q2.insert(2,0);

    q = q + q2;
    //q++;
    //q--;
    q--;
    //q.print();
    q.remove();
    //q.print();
    cout << q.maxPriority();
    return 0;
}