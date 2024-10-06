#include <iostream>
#include <memory>
using namespace std;

int main(){
    auto x = make_shared<int>();
    *x = 4;
    shared_ptr<int> t(x);
    cout << x.get() << " " << t.get() << endl;

    return 0;
}