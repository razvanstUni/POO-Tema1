#include <iostream>
#include "PQueue.cpp"
using namespace std;

int main() {
    /*
     * Dummy example
     */
    PQueue q;
    q.insert(5,0);
    q.insert(7,1);
    q.insert(6,0);
    q.insert(1,0);
    cout << q << '\n';

    PQueue q2;
    q2.insert(4,2);
    q2.insert(2,0);
    cout << q2 << '\n';

    PQueue q3;
    q3 = q + q2;
    cout << q3 << '\n';
    q3.remove();
    cout << q3;

    //cout << q.maxPriority();
    return 0;
}