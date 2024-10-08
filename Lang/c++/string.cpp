#include <iostream>
using namespace std;

int main(){
    string name = "Sazid Hasan";
    int spaceIndex = name.find(' ');
    string firstName = name.substr(0, spaceIndex);
    string lastName = name.substr(spaceIndex + 1, name.length() - 1);
    cout << firstName << " " << lastName << endl;

    return 0;
}