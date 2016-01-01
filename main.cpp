/*
 * main.cpp of ProjectEuler
 * Author: Peter Master
 * Created on December 26, 2015
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> //problems: 2
#include <string> //problem 8
#include "math.h"
#include "stdlib.h" //problems: 8
#include "exercises.h"

using namespace std;

//update array of problems and fill
Problem problems[PROBLEMS_TOTAL + 1] = {problem1, problem2, problem3, problem4,
    problem5, problem6, problem7, problem8, problem9, problem10, problem11};

/*
 *
 */

int main(int argc, char** argv) {
    int problemNumber = 0, behavior;
    long double answer;
    ifstream exercisesTextFileIn;
    ofstream exercisesTextFileOut;
    //exercisesTextFileIn.open("exercises.txt"); //don't forget to close

    cout << "What exercise would you like to see?" << endl;
    cin >> problemNumber;
    answer = problems[problemNumber - 1]();
    cout << fixed << answer << endl; //or skip answer altogether and print 'problemX()'

    return 0;
}

//create way to randomly select a random problem
