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
#include "math.h"
#include <vector> //problems: 2
using namespace std;

typedef long double (*Problem)();
const int EXERCISES_TOTAL = 539;

long double problem1();
long double problem2();
long double problem3();
long double problem4();
long double problem5();

Problem exercises[EXERCISES_TOTAL + 1] = {problem1, problem2, problem3, problem4,
    problem5};

/*
 *
 */

int main(int argc, char** argv) {
    int problemNumber = 0, behavior;
    long double answer;
    ifstream exercisesTextFileIn;
    ofstream exercisesTextFileOut;
    exercisesTextFileIn.open("exercises.txt"); //don't forget to close
    
    cout << "What exercise would you like to see?" << endl;
    cin >> problemNumber;
    answer = exercises[problemNumber - 1]();
    cout << fixed << answer << endl; //or skip answer altogether and print 'problemX()'
    
    return 0;
}


//create way to randomly select a random problem


/* Problem 1, Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000. */
long double problem1(){
    double totalSum = 0;
    for (int i = 3; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            totalSum += i;
    return totalSum;
}

long double problem2(){ //longs versus ints? ints appear to work fine. vector size limit?
    int counter = 2; //because fib[0] and fib[1] are initialized out of the loop
    long totalSum = 0;
    vector<int> fibonacci(100);
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; fibonacci[i-1] <= 4000000; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        counter++;}
    for (int i = 0; i < counter; i++)
        if (fibonacci[i] % 2 == 0)
            totalSum += fibonacci[i];
    return totalSum;
}

bool problem3_primeNumTester(long long numToBeTested);

long double problem3(){
    long long largestPrimeFactor, promptNumber = 600851475143;
    
    for (long long i = 2; i < ceil(sqrt(promptNumber)); i++)
        if (promptNumber % i == 0)
            if (problem3_primeNumTester(i))
                largestPrimeFactor = i;    
    return largestPrimeFactor;
}

bool problem3_primeNumTester(long long numToBeTested){
    for (long long i = 2; i < ceil(sqrt(numToBeTested)); i++)
        if (numToBeTested % i == 0)
            return false;
    return true;
}

long double problem4(){ //given that 234432 = 444*528
    long double largestPalindrome = 234432;
    for (int i = 999; i > 444; i--)
        for (int j = 999; j > 528; j--)
            if (i*j>largestPalindrome)
                if (((i*j/1000)%100)%10 == (((i*j/100)%1000)%100)%10)
                    if ((i*j/10000)%10 == ((((i*j/10)%10000)%1000)%100)%10)
                        if (i*j/100000 == (((((i*j)%100000)%10000)%1000)%100)%10)
                            largestPalindrome = i*j;
    return largestPalindrome;
}

long double problem5(){//given that 2520 is the smallest # divisible by 1 thru 10
    long double smallestDivisible = 2519;
    bool divisibleByAll;
    do{
        smallestDivisible++;
        divisibleByAll = true;
        for (int i = 20; i >= 11 && divisibleByAll; i--)
            if (int(smallestDivisible) % i != 0)
                divisibleByAll = false;
    } while (!divisibleByAll);    
    return smallestDivisible;
}