#include <iostream>
using namespace std;

struct game {
    int Year = 0;
    bool isPopuler = false;
    string Name;
};

int main(){
    struct game GTA = {1999, true, "GTA V"};
    auto [year, popularity, name] {GTA};
    cout << year << popularity << name;

    return 0;
}