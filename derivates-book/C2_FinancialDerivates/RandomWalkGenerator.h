#ifndef __CppOptions__RandomWalkGenerator__
#define __CppOptions__RandomWalkGenerator__

//The class has the responsibility of creating a sequence of numbers that represent a random
//walk. This means that starting on a particular value (the initial price), the sequence will change according
//to random increments, as determined by the given step parameter. Finally, the size of the sequence (which
//corresponds to the time to expiration of a contract) is also given as a parameter to the class. This results in a
//class with the following signature to the constructor:

#include <vector> 

class RandomWalkGenerator{
    public:
    //constructor
    RandomWalkGenerator(int size, double start, double step);
    RandomWalkGenerator(const RandomWalkGenerator &p);

    //destructor
    ~RandomWalkGenerator();

    // assignment operator
    RandomWalkGenerator &operator=(const RandomWalkGenerator &p);

    // main method that returns a vector with values of the random walk
    std::vector<double> generateWalk();

    // returns a single step of the random walk
    double computeRandomStep(double currentPrice);

    private:

    int m_numSteps; // the number of steps
    double m_stepSize; // size of each step (in percentage points)
    double m_initialPrice; // starting price 

};

#endif /* defined(__CppOptions__RandomWalkGenerator__) */
