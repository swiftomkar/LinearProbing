#include <iostream>
#include "LinearChaning.h"
using namespace std;

int main() {
    linearChaining<int> myHash(10);
    myHash.add(5);
    myHash.add(51);
    myHash.add(54);
    myHash.add(534);
    myHash.add(533);
    myHash.add(1);
    myHash.add(10);
    cout<<myHash.find(533)<<endl;
    myHash.hist();
    return 0;
}