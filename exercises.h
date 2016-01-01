#ifndef EXERCISES_H_INCLUDED
#define EXERCISES_H_INCLUDED

bool isPerfectSquare(int n);
//takes a positive integer as an argument and returns true
//if the integer is a perfect square and false if not
bool isPrime(int n);
//takes an integer that is greater than 1 and returns true
//if the integer is a prime number and false if not

typedef long double (*Problem)();
const int PROBLEMS_TOTAL = 539;

//use header file for all problem functions, typedef, const declarations, and exercises array
long double problem1();
long double problem2();
long double problem3();
long double problem4();
long double problem5();
long double problem6();
long double problem7();
long double problem8();
long double problem9();
long double problem10();
long double problem11();

#endif // EXERCISES_H_INCLUDED
