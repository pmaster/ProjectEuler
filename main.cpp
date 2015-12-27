/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Peter
 *
 * Created on December 26, 2015, 3:25 PM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int EXERCISES_TOTAL = 539;
const int EXERCISES[] = {};
//create array consisting of function types

/*
 * 
 */

double problem001();

int main(int argc, char** argv) {
    int answer, behavior;
    ifstream exercisesTextFileIn;
    ofstream exercisesTextFileOut;
    exercisesTextFileIn.open("exercises.txt"); //don't forget to close
    
    answer = problem001();
    cout << answer << endl;
    cout << problem001() << endl;
    
    return 0;
}

/* Problem 1, Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000. */
double problem001(){
    cout << "Problem 1\nMultiples of 3 and 5\n\n"
            "If we list all the natural numbers below 10 that are multiples\n"
            "of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n";
    double totalSum = 0;
    for (int i = 3; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            totalSum += i;
    return totalSum;
}





//create way to randomly select a random problem