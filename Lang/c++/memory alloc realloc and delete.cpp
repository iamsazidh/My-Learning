#include <iostream>
#include <string.h>
#include <limits>
using namespace std;

int main(){
    int capacity = 5;
    int* numbers = new int[capacity];
    int index = 0;

    while (true)
    {
        cin >> numbers[index];
        if(cin.fail()){
            break;
        }
        index++;
        if(index == capacity){
            capacity *= 2;
            int* temp = new int[capacity];
            for(int i = 0; i <  index; i++) temp[i] = numbers[i];
            delete[] numbers;
            numbers = temp;
        }
    }
    for(int i = 0; i < index; i++) cout << numbers[i] << " ";
    
}