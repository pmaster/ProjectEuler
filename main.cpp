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


using namespace std;

typedef long double (*Problem)();
const int EXERCISES_TOTAL = 539;

long double problem1();
long double problem2();
long double problem3();
long double problem4();
long double problem5();
long double problem6();
long double problem7();
long double problem8();

Problem exercises[EXERCISES_TOTAL + 1] = {problem1, problem2, problem3, problem4,
    problem5, problem6, problem7, problem8};

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
        for (long i = 20/*user inputted number*/; i >= 1 && divisibleByAll; i--)
            if (long(smallestDivisible) % i != 0)
                divisibleByAll = false;
    } while (!divisibleByAll);
    return smallestDivisible;
}

long double problem6(){
    long largestNum = 100; //variable
    long double difference, sumOfSquares = 0, squareOfSum = 0;
    for (long i = 0; i <= largestNum; i++){
        sumOfSquares += i*i;
        squareOfSum += i;
    }
    squareOfSum = squareOfSum*squareOfSum;
    difference = squareOfSum - sumOfSquares;
    return difference;
}

//max value of n for successful program operation? shift from the primes
//array and use
long double problem7(){
    long n = 10001,//variable -- we want the 10001st prime
            nthPrime, lastNonZeroIndex = 0, numBeingTested = 3;
    long *primes = new long[n];
    bool divisibleByNone;
    primes[0] = 2;
    while (lastNonZeroIndex < n){
        divisibleByNone = true;
        //for (long i = 2;
                //i <= sqrt(numBeingTested) && divisibleByNone; i++)
        for (int i = 0;
                i <= lastNonZeroIndex && divisibleByNone; i++)
            //if (numBeingTested % i == 0)
            if (numBeingTested % primes[i] == 0)
                divisibleByNone = false;
        if (divisibleByNone)
            primes[++lastNonZeroIndex] = numBeingTested;
        numBeingTested++;}
    nthPrime = primes[n-1];
    /*for (int i = 0; i < n; i++)
     *   if (primes[i] != 0)
     *      cout << primes[i] << " at index " << i << endl;
     */
    return nthPrime;
}

long double problem8(){
    int numsToMultiply = 13; //changeable
    long double greatestProduct = 0, currentProduct;
    string series = /*changeable*/"7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    int *digits = new int[series.length()];
    for (int i = 0; i < series.length(); i++)
        digits[i] = series[i] - 48;
    for (int i = 0; i < series.length() - numsToMultiply; i++){
        currentProduct = 1;
        for (int j = i; j < i + numsToMultiply; j++)
            currentProduct *= digits[j];
        if (currentProduct > greatestProduct)
            greatestProduct = currentProduct;}
    return greatestProduct;
}
