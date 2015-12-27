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
#include <vector> //problems: 2

using namespace std;

const int EXERCISES_TOTAL = 539;
const int EXERCISES[] = {};
//create array consisting of function types

/*
 * 
 */

double problem1();
double problem2();

int main(int argc, char** argv) {
    int answer, behavior;
    ifstream exercisesTextFileIn;
    ofstream exercisesTextFileOut;
    exercisesTextFileIn.open("exercises.txt"); //don't forget to close
    
    answer = problem2();
    cout << answer << endl; //or skip answer altogether and print 'problemX()'
    
    return 0;
}


//create way to randomly select a random problem


/* Problem 1, Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000. */
double problem1(){
    cout << "Problem 1\nMultiples of 3 and 5\n\n"
            "If we list all the natural numbers below 10 that are multiples\n"
            "of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n";
    double totalSum = 0;
    for (int i = 3; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            totalSum += i;
    return totalSum;
}

double problem2(){ //longs versus ints? ints appear to work fine. vector size limit?
    int counter = 2;
    long totalSum = 0;
    vector<int> fibonacci(100);
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; fibonacci[i-1] <= 4000000; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        cout << fibonacci[i] << endl;
        counter++;}
    for (int i = 0; i < counter; i++)
        if (fibonacci[i] % 2 == 0){
            cout << fibonacci[i] << endl;
            totalSum += fibonacci[i];}
    return totalSum;
}