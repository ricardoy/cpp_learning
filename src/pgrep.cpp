#include <iostream>
// #include "queue.h"
#include "queue.cpp"

using namespace std;

class Blah {
    public:
        int value;

        Blah() {
            this->value = 13;
        }
};

int main() {
    ConcurrentQueue<string> q(10);
    q.add("aloha");
    cout << q.remove() << endl;

    ConcurrentQueue<Blah> w(100);
    w.add(Blah());
    cout << w.remove().value << endl;

    cout << "fim" << endl;
}