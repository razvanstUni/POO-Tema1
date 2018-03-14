#include <iostream>
#include "assets/PQueue.cpp"
using namespace std;

int main() {
    /*
     * Dummy example bilbieflorin@gmail.com
     */
    PQueue q(2,5,1);
    //cin >> q;
    q.insert(5,0);
    q.insert(7,1);
    q.insert(6,3);
    q.insert(1,0);
    cout << q << '\n';

    PQueue q3(2,2,1);
    q3 = q + q3;
    cout << q3 << '\n';
    q3.remove();
    cout << q3;

    cout << "\nMax priority: " << q3.maxPriority();
    cout << "\nMax value: " << q3.maxValue();
    return 0;
}