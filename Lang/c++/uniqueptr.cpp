#include <iostream>
#include <memory>
using namespace std;

int main(){
    unique_ptr<int[]> x = make_unique<int[]>(2);
    auto y = make_unique<int>();
    x[0] = 6;
    cout  << x.get() << " " << x[0] << endl;

    return 0;
}