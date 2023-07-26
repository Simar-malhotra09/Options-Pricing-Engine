#include <iostream>
#include "RandomWalkGenerator.h"
#include "RandomWalkGenerator.cpp"

using namespace std;



int main(){
    // 100 steps starting @ $30
    RandomWalkGenerator rw(10, 30, 0.1);
    vector<double> walk = rw.generateWalk();

    for (int i=0; i<walk.size(); ++i){
        cout << ", " << i << ", " << walk[i] <<endl;
    }

    cout << endl;
    return 0;
}