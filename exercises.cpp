#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> //problems: 2
#include <string> //problem 8, 13
#include "math.h"
#include "stdlib.h" //problems: 8
#include "exercises.h"

using namespace std;

bool isPerfectSquare(int n){
    if (int(sqrt(n)) == sqrt(n))
        return true;
    return false;
}

bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

long getTriangleNumber(int n){
    long nthTriangleNumber = 0;
    for (int i = 1; i <= n; i++)
        nthTriangleNumber += i;
    return nthTriangleNumber;
}

int getNumDivisors(long n){
    int numDivisors = 0;//
    for (int i = 1; i < sqrt(n); i++)
        if (n % i == 0)
                numDivisors += 2;
    if (isPerfectSquare(n))
        numDivisors += 1;
    return numDivisors;
}

long long getSumString(string n){
    long long sum = 0;
    for (int i = 0; i < n.length(); i++)
        sum += n[i] - 48;
    return sum;
}

long long getNumCollatzTerms(long long n){
    int numCollatzTerms = 1; //1, rather than 0, to account for starting term
    while (n != 1){
        if (n % 2 == 0)
            n = n/2;
        else
            n = n*3 + 1;
        numCollatzTerms++;}
    return numCollatzTerms;
}

int notSolved(){
    return -1;
}

/*
 *
*/

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

bool problem3_primeNumTester(long long numToBeTested); //MOVE TO HEADER?

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

long double problem9(){ //a + b + sqrt(a*a+b*b) = 1000 is the same as b = (1000 * (a - 500)) / (a - 1000) for a < 1000
    long double b, desiredSumABC = 1000 /*changeable*/;
    for (int a = 1; a < .5*desiredSumABC; a++){
        b = (1000 * (a - 500)) / (a - 1000);
        if (isPerfectSquare(a*a+b*b))
            return a*b*(sqrt(a*a+b*b));}
    return 0;//error
}

long double problem10(){
    long double sumPrimes = 0, maxValuePlusOne = 2000000; //change this
    for (int i = 2; i < maxValuePlusOne; i++)
        if (isPrime(i))
            sumPrimes += i;
    return sumPrimes;
}

long double problem11(){
    return notSolved();
}

long double problem12(){
    int i = 1, numOfDivisorsToExceed = 500; //nth triangle number -- change this
    while (getNumDivisors(getTriangleNumber(i)) <= numOfDivisorsToExceed)
        i++;
    return getTriangleNumber(i);
}

long double problem13(){
	return notSolved();
}

long double problem14(){//if the highest chain length has multiple corresponding numbers, returns the smaller one
    int highestChainLength = 0;
	long highestChainLengthNum, maxNum = 1000000; //largest num to test -- change this
	//for (int i = 1; i <= maxNum; i++){
	for (int i = maxNum; i >= 1; i--)
            if (highestChainLength < getNumCollatzTerms(i)){
                highestChainLength = getNumCollatzTerms(i);
                highestChainLengthNum = i;}
	return highestChainLengthNum;
}

long double problem15(){
	return notSolved();
}

long double problem16(){
	return notSolved();
}

long double problem17(){
	return notSolved();
}

long double problem18(){
    return notSolved();
}

//consider a method to find startDateDistFromSunday given that the start date is jan 1st 1901, and jan 1st 1900 was a monday
//also look at line 260
long double problem19(){//count how many sundays fall on the first of the month from 1/1/1901 - 12/31/2000
    //1st of Jan, 1901 was a Monday
    //months: january31, february28/29, march31, april30, may31, june30, july31, august31, september30, october31, november30, december31
    //leap year is every year that's divisible by 4 and not 400, and means that february contains 29 days
    int dd = 1, mm = 1, yy = 1901, lastDD = 31, lastMM = 12, lastYY = 2000, startDateDistFromSunday = 2, foundCounter = 0, iterations = 0;
    //change dd/mm/yy/startDateDistFromSunday for start date and lastDD/lastMM/lastYY for end date
    int minNumDaysPerMonth[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//indice 0 is -1 to line up indices with month for intuitiveness
    //note: Feb. sometimes has 29; if 28 is exceeded during Feb., we check to see if there's a 29th day
    while (yy < 2001){//(yy < lastYY || mm < lastMM || dd <= lastDD){
        if (dd == 1 && (startDateDistFromSunday + iterations) % 7 == 0){
            foundCounter++;//if the first day of the month is a Sunday, increase count}
            cout << dd << "/" << mm << "/" << yy << "\tfound: " << foundCounter << "\tdays from Sunday: " << (startDateDistFromSunday+iterations) % 7 << endl;}
            if (++dd > minNumDaysPerMonth[mm]){
            if (dd > 29 || /*check if the month is February and it's a leap year:*/!(mm == 2 && yy % 4 == 0 && (!(yy % 100 == 0) || (yy % 400 == 0)))){
                dd = 1;
                if (++mm > 12){
                    mm = 1;
                    yy++;
                }
            }
        }
        iterations++;
    }
	return foundCounter;
}

long double problem20(){
	return notSolved();
}

long double problem21(){
	return notSolved();
}

long double problem22(){
	return notSolved();
}

long double problem23(){
	return notSolved();
}

long double problem24(){
	return notSolved();
}

long double problem25(){
	return notSolved();
}

long double problem26(){
	return notSolved();
}

long double problem27(){
	return notSolved();
}

long double problem28(){
	return notSolved();
}

long double problem29(){
	return notSolved();
}

long double problem30(){
	return notSolved();
}

long double problem31(){
	return notSolved();
}

long double problem32(){
	return notSolved();
}

long double problem33(){
	return notSolved();
}

long double problem34(){
	return notSolved();
}

long double problem35(){
	return notSolved();
}

long double problem36(){
	return notSolved();
}

long double problem37(){
	return notSolved();
}

long double problem38(){
	return notSolved();
}

long double problem39(){
	return notSolved();
}

long double problem40(){
	return notSolved();
}

long double problem41(){
	return notSolved();
}

long double problem42(){
	return notSolved();
}

long double problem43(){
	return notSolved();
}

long double problem44(){
	return notSolved();
}

long double problem45(){
	return notSolved();
}

long double problem46(){
	return notSolved();
}

long double problem47(){
	return notSolved();
}

long double problem48(){
	return notSolved();
}

long double problem49(){
	return notSolved();
}

long double problem50(){
	return notSolved();
}

long double problem51(){
	return notSolved();
}

long double problem52(){
	return notSolved();
}

long double problem53(){
	return notSolved();
}

long double problem54(){
	return notSolved();
}

long double problem55(){
	return notSolved();
}

long double problem56(){
	return notSolved();
}

long double problem57(){
	return notSolved();
}

long double problem58(){
	return notSolved();
}

long double problem59(){
	return notSolved();
}

long double problem60(){
	return notSolved();
}

long double problem61(){
	return notSolved();
}

long double problem62(){
	return notSolved();
}

long double problem63(){
	return notSolved();
}

long double problem64(){
	return notSolved();
}

long double problem65(){
	return notSolved();
}

long double problem66(){
	return notSolved();
}

long double problem67(){
	return notSolved();
}

long double problem68(){
	return notSolved();
}

long double problem69(){
	return notSolved();
}

long double problem70(){
	return notSolved();
}

long double problem71(){
	return notSolved();
}

long double problem72(){
	return notSolved();
}

long double problem73(){
	return notSolved();
}

long double problem74(){
	return notSolved();
}

long double problem75(){
	return notSolved();
}

long double problem76(){
	return notSolved();
}

long double problem77(){
	return notSolved();
}

long double problem78(){
	return notSolved();
}

long double problem79(){
	return notSolved();
}

long double problem80(){
	return notSolved();
}

long double problem81(){
	return notSolved();
}

long double problem82(){
	return notSolved();
}

long double problem83(){
	return notSolved();
}

long double problem84(){
	return notSolved();
}

long double problem85(){
	return notSolved();
}

long double problem86(){
	return notSolved();
}

long double problem87(){
	return notSolved();
}

long double problem88(){
	return notSolved();
}

long double problem89(){
	return notSolved();
}

long double problem90(){
	return notSolved();
}

long double problem91(){
	return notSolved();
}

long double problem92(){
	return notSolved();
}

long double problem93(){
	return notSolved();
}

long double problem94(){
	return notSolved();
}

long double problem95(){
	return notSolved();
}

long double problem96(){
	return notSolved();
}

long double problem97(){
	return notSolved();
}

long double problem98(){
	return notSolved();
}

long double problem99(){
	return notSolved();
}

long double problem100(){
	return notSolved();
}

long double problem101(){
	return notSolved();
}

long double problem102(){
	return notSolved();
}

long double problem103(){
	return notSolved();
}

long double problem104(){
	return notSolved();
}

long double problem105(){
	return notSolved();
}

long double problem106(){
	return notSolved();
}

long double problem107(){
	return notSolved();
}

long double problem108(){
	return notSolved();
}

long double problem109(){
	return notSolved();
}

long double problem110(){
	return notSolved();
}

long double problem111(){
	return notSolved();
}

long double problem112(){
	return notSolved();
}

long double problem113(){
	return notSolved();
}

long double problem114(){
	return notSolved();
}

long double problem115(){
	return notSolved();
}

long double problem116(){
	return notSolved();
}

long double problem117(){
	return notSolved();
}

long double problem118(){
	return notSolved();
}

long double problem119(){
	return notSolved();
}

long double problem120(){
	return notSolved();
}

long double problem121(){
	return notSolved();
}

long double problem122(){
	return notSolved();
}

long double problem123(){
	return notSolved();
}

long double problem124(){
	return notSolved();
}

long double problem125(){
	return notSolved();
}

long double problem126(){
	return notSolved();
}

long double problem127(){
	return notSolved();
}

long double problem128(){
	return notSolved();
}

long double problem129(){
	return notSolved();
}

long double problem130(){
	return notSolved();
}

long double problem131(){
	return notSolved();
}

long double problem132(){
	return notSolved();
}

long double problem133(){
	return notSolved();
}

long double problem134(){
	return notSolved();
}

long double problem135(){
	return notSolved();
}

long double problem136(){
	return notSolved();
}

long double problem137(){
	return notSolved();
}

long double problem138(){
	return notSolved();
}

long double problem139(){
	return notSolved();
}

long double problem140(){
	return notSolved();
}

long double problem141(){
	return notSolved();
}

long double problem142(){
	return notSolved();
}

long double problem143(){
	return notSolved();
}

long double problem144(){
	return notSolved();
}

long double problem145(){
	return notSolved();
}

long double problem146(){
	return notSolved();
}

long double problem147(){
	return notSolved();
}

long double problem148(){
	return notSolved();
}

long double problem149(){
	return notSolved();
}

long double problem150(){
	return notSolved();
}

long double problem151(){
	return notSolved();
}

long double problem152(){
	return notSolved();
}

long double problem153(){
	return notSolved();
}

long double problem154(){
	return notSolved();
}

long double problem155(){
	return notSolved();
}

long double problem156(){
	return notSolved();
}

long double problem157(){
	return notSolved();
}

long double problem158(){
	return notSolved();
}

long double problem159(){
	return notSolved();
}

long double problem160(){
	return notSolved();
}

long double problem161(){
	return notSolved();
}

long double problem162(){
	return notSolved();
}

long double problem163(){
	return notSolved();
}

long double problem164(){
	return notSolved();
}

long double problem165(){
	return notSolved();
}

long double problem166(){
	return notSolved();
}

long double problem167(){
	return notSolved();
}

long double problem168(){
	return notSolved();
}

long double problem169(){
	return notSolved();
}

long double problem170(){
	return notSolved();
}

long double problem171(){
	return notSolved();
}

long double problem172(){
	return notSolved();
}

long double problem173(){
	return notSolved();
}

long double problem174(){
	return notSolved();
}

long double problem175(){
	return notSolved();
}

long double problem176(){
	return notSolved();
}

long double problem177(){
	return notSolved();
}

long double problem178(){
	return notSolved();
}

long double problem179(){
	return notSolved();
}

long double problem180(){
	return notSolved();
}

long double problem181(){
	return notSolved();
}

long double problem182(){
	return notSolved();
}

long double problem183(){
	return notSolved();
}

long double problem184(){
	return notSolved();
}

long double problem185(){
	return notSolved();
}

long double problem186(){
	return notSolved();
}

long double problem187(){
	return notSolved();
}

long double problem188(){
	return notSolved();
}

long double problem189(){
	return notSolved();
}

long double problem190(){
	return notSolved();
}

long double problem191(){
	return notSolved();
}

long double problem192(){
	return notSolved();
}

long double problem193(){
	return notSolved();
}

long double problem194(){
	return notSolved();
}

long double problem195(){
	return notSolved();
}

long double problem196(){
	return notSolved();
}

long double problem197(){
	return notSolved();
}

long double problem198(){
	return notSolved();
}

long double problem199(){
	return notSolved();
}

long double problem200(){
	return notSolved();
}

long double problem201(){
	return notSolved();
}

long double problem202(){
	return notSolved();
}

long double problem203(){
	return notSolved();
}

long double problem204(){
	return notSolved();
}

long double problem205(){
	return notSolved();
}

long double problem206(){
	return notSolved();
}

long double problem207(){
	return notSolved();
}

long double problem208(){
	return notSolved();
}

long double problem209(){
	return notSolved();
}

long double problem210(){
	return notSolved();
}

long double problem211(){
	return notSolved();
}

long double problem212(){
	return notSolved();
}

long double problem213(){
	return notSolved();
}

long double problem214(){
	return notSolved();
}

long double problem215(){
	return notSolved();
}

long double problem216(){
	return notSolved();
}

long double problem217(){
	return notSolved();
}

long double problem218(){
	return notSolved();
}

long double problem219(){
	return notSolved();
}

long double problem220(){
	return notSolved();
}

long double problem221(){
	return notSolved();
}

long double problem222(){
	return notSolved();
}

long double problem223(){
	return notSolved();
}

long double problem224(){
	return notSolved();
}

long double problem225(){
	return notSolved();
}

long double problem226(){
	return notSolved();
}

long double problem227(){
	return notSolved();
}

long double problem228(){
	return notSolved();
}

long double problem229(){
	return notSolved();
}

long double problem230(){
	return notSolved();
}

long double problem231(){
	return notSolved();
}

long double problem232(){
	return notSolved();
}

long double problem233(){
	return notSolved();
}

long double problem234(){
	return notSolved();
}

long double problem235(){
	return notSolved();
}

long double problem236(){
	return notSolved();
}

long double problem237(){
	return notSolved();
}

long double problem238(){
	return notSolved();
}

long double problem239(){
	return notSolved();
}

long double problem240(){
	return notSolved();
}

long double problem241(){
	return notSolved();
}

long double problem242(){
	return notSolved();
}

long double problem243(){
	return notSolved();
}

long double problem244(){
	return notSolved();
}

long double problem245(){
	return notSolved();
}

long double problem246(){
	return notSolved();
}

long double problem247(){
	return notSolved();
}

long double problem248(){
	return notSolved();
}

long double problem249(){
	return notSolved();
}

long double problem250(){
	return notSolved();
}

long double problem251(){
	return notSolved();
}

long double problem252(){
	return notSolved();
}

long double problem253(){
	return notSolved();
}

long double problem254(){
	return notSolved();
}

long double problem255(){
	return notSolved();
}

long double problem256(){
	return notSolved();
}

long double problem257(){
	return notSolved();
}

long double problem258(){
	return notSolved();
}

long double problem259(){
	return notSolved();
}

long double problem260(){
	return notSolved();
}

long double problem261(){
	return notSolved();
}

long double problem262(){
	return notSolved();
}

long double problem263(){
	return notSolved();
}

long double problem264(){
	return notSolved();
}

long double problem265(){
	return notSolved();
}

long double problem266(){
	return notSolved();
}

long double problem267(){
	return notSolved();
}

long double problem268(){
	return notSolved();
}

long double problem269(){
	return notSolved();
}

long double problem270(){
	return notSolved();
}

long double problem271(){
	return notSolved();
}

long double problem272(){
	return notSolved();
}

long double problem273(){
	return notSolved();
}

long double problem274(){
	return notSolved();
}

long double problem275(){
	return notSolved();
}

long double problem276(){
	return notSolved();
}

long double problem277(){
	return notSolved();
}

long double problem278(){
	return notSolved();
}

long double problem279(){
	return notSolved();
}

long double problem280(){
	return notSolved();
}

long double problem281(){
	return notSolved();
}

long double problem282(){
	return notSolved();
}

long double problem283(){
	return notSolved();
}

long double problem284(){
	return notSolved();
}

long double problem285(){
	return notSolved();
}

long double problem286(){
	return notSolved();
}

long double problem287(){
	return notSolved();
}

long double problem288(){
	return notSolved();
}

long double problem289(){
	return notSolved();
}

long double problem290(){
	return notSolved();
}

long double problem291(){
	return notSolved();
}

long double problem292(){
	return notSolved();
}

long double problem293(){
	return notSolved();
}

long double problem294(){
	return notSolved();
}

long double problem295(){
	return notSolved();
}

long double problem296(){
	return notSolved();
}

long double problem297(){
	return notSolved();
}

long double problem298(){
	return notSolved();
}

long double problem299(){
	return notSolved();
}

long double problem300(){
	return notSolved();
}

long double problem301(){
	return notSolved();
}

long double problem302(){
	return notSolved();
}

long double problem303(){
	return notSolved();
}

long double problem304(){
	return notSolved();
}

long double problem305(){
	return notSolved();
}

long double problem306(){
	return notSolved();
}

long double problem307(){
	return notSolved();
}

long double problem308(){
	return notSolved();
}

long double problem309(){
	return notSolved();
}

long double problem310(){
	return notSolved();
}

long double problem311(){
	return notSolved();
}

long double problem312(){
	return notSolved();
}

long double problem313(){
	return notSolved();
}

long double problem314(){
	return notSolved();
}

long double problem315(){
	return notSolved();
}

long double problem316(){
	return notSolved();
}

long double problem317(){
	return notSolved();
}

long double problem318(){
	return notSolved();
}

long double problem319(){
	return notSolved();
}

long double problem320(){
	return notSolved();
}

long double problem321(){
	return notSolved();
}

long double problem322(){
	return notSolved();
}

long double problem323(){
	return notSolved();
}

long double problem324(){
	return notSolved();
}

long double problem325(){
	return notSolved();
}

long double problem326(){
	return notSolved();
}

long double problem327(){
	return notSolved();
}

long double problem328(){
	return notSolved();
}

long double problem329(){
	return notSolved();
}

long double problem330(){
	return notSolved();
}

long double problem331(){
	return notSolved();
}

long double problem332(){
	return notSolved();
}

long double problem333(){
	return notSolved();
}

long double problem334(){
	return notSolved();
}

long double problem335(){
	return notSolved();
}

long double problem336(){
	return notSolved();
}

long double problem337(){
	return notSolved();
}

long double problem338(){
	return notSolved();
}

long double problem339(){
	return notSolved();
}

long double problem340(){
	return notSolved();
}

long double problem341(){
	return notSolved();
}

long double problem342(){
	return notSolved();
}

long double problem343(){
	return notSolved();
}

long double problem344(){
	return notSolved();
}

long double problem345(){
	return notSolved();
}

long double problem346(){
	return notSolved();
}

long double problem347(){
	return notSolved();
}

long double problem348(){
	return notSolved();
}

long double problem349(){
	return notSolved();
}

long double problem350(){
	return notSolved();
}

long double problem351(){
	return notSolved();
}

long double problem352(){
	return notSolved();
}

long double problem353(){
	return notSolved();
}

long double problem354(){
	return notSolved();
}

long double problem355(){
	return notSolved();
}

long double problem356(){
	return notSolved();
}

long double problem357(){
	return notSolved();
}

long double problem358(){
	return notSolved();
}

long double problem359(){
	return notSolved();
}

long double problem360(){
	return notSolved();
}

long double problem361(){
	return notSolved();
}

long double problem362(){
	return notSolved();
}

long double problem363(){
	return notSolved();
}

long double problem364(){
	return notSolved();
}

long double problem365(){
	return notSolved();
}

long double problem366(){
	return notSolved();
}

long double problem367(){
	return notSolved();
}

long double problem368(){
	return notSolved();
}

long double problem369(){
	return notSolved();
}

long double problem370(){
	return notSolved();
}

long double problem371(){
	return notSolved();
}

long double problem372(){
	return notSolved();
}

long double problem373(){
	return notSolved();
}

long double problem374(){
	return notSolved();
}

long double problem375(){
	return notSolved();
}

long double problem376(){
	return notSolved();
}

long double problem377(){
	return notSolved();
}

long double problem378(){
	return notSolved();
}

long double problem379(){
	return notSolved();
}

long double problem380(){
	return notSolved();
}

long double problem381(){
	return notSolved();
}

long double problem382(){
	return notSolved();
}

long double problem383(){
	return notSolved();
}

long double problem384(){
	return notSolved();
}

long double problem385(){
	return notSolved();
}

long double problem386(){
	return notSolved();
}

long double problem387(){
	return notSolved();
}

long double problem388(){
	return notSolved();
}

long double problem389(){
	return notSolved();
}

long double problem390(){
	return notSolved();
}

long double problem391(){
	return notSolved();
}

long double problem392(){
	return notSolved();
}

long double problem393(){
	return notSolved();
}

long double problem394(){
	return notSolved();
}

long double problem395(){
	return notSolved();
}

long double problem396(){
	return notSolved();
}

long double problem397(){
	return notSolved();
}

long double problem398(){
	return notSolved();
}

long double problem399(){
	return notSolved();
}

long double problem400(){
	return notSolved();
}

long double problem401(){
	return notSolved();
}

long double problem402(){
	return notSolved();
}

long double problem403(){
	return notSolved();
}

long double problem404(){
	return notSolved();
}

long double problem405(){
	return notSolved();
}

long double problem406(){
	return notSolved();
}

long double problem407(){
	return notSolved();
}

long double problem408(){
	return notSolved();
}

long double problem409(){
	return notSolved();
}

long double problem410(){
	return notSolved();
}

long double problem411(){
	return notSolved();
}

long double problem412(){
	return notSolved();
}

long double problem413(){
	return notSolved();
}

long double problem414(){
	return notSolved();
}

long double problem415(){
	return notSolved();
}

long double problem416(){
	return notSolved();
}

long double problem417(){
	return notSolved();
}

long double problem418(){
	return notSolved();
}

long double problem419(){
	return notSolved();
}

long double problem420(){
	return notSolved();
}

long double problem421(){
	return notSolved();
}

long double problem422(){
	return notSolved();
}

long double problem423(){
	return notSolved();
}

long double problem424(){
	return notSolved();
}

long double problem425(){
	return notSolved();
}

long double problem426(){
	return notSolved();
}

long double problem427(){
	return notSolved();
}

long double problem428(){
	return notSolved();
}

long double problem429(){
	return notSolved();
}

long double problem430(){
	return notSolved();
}

long double problem431(){
	return notSolved();
}

long double problem432(){
	return notSolved();
}

long double problem433(){
	return notSolved();
}

long double problem434(){
	return notSolved();
}

long double problem435(){
	return notSolved();
}

long double problem436(){
	return notSolved();
}

long double problem437(){
	return notSolved();
}

long double problem438(){
	return notSolved();
}

long double problem439(){
	return notSolved();
}

long double problem440(){
	return notSolved();
}

long double problem441(){
	return notSolved();
}

long double problem442(){
	return notSolved();
}

long double problem443(){
	return notSolved();
}

long double problem444(){
	return notSolved();
}

long double problem445(){
	return notSolved();
}

long double problem446(){
	return notSolved();
}

long double problem447(){
	return notSolved();
}

long double problem448(){
	return notSolved();
}

long double problem449(){
	return notSolved();
}

long double problem450(){
	return notSolved();
}

long double problem451(){
	return notSolved();
}

long double problem452(){
	return notSolved();
}

long double problem453(){
	return notSolved();
}

long double problem454(){
	return notSolved();
}

long double problem455(){
	return notSolved();
}

long double problem456(){
	return notSolved();
}

long double problem457(){
	return notSolved();
}

long double problem458(){
	return notSolved();
}

long double problem459(){
	return notSolved();
}

long double problem460(){
	return notSolved();
}

long double problem461(){
	return notSolved();
}

long double problem462(){
	return notSolved();
}

long double problem463(){
	return notSolved();
}

long double problem464(){
	return notSolved();
}

long double problem465(){
	return notSolved();
}

long double problem466(){
	return notSolved();
}

long double problem467(){
	return notSolved();
}

long double problem468(){
	return notSolved();
}

long double problem469(){
	return notSolved();
}

long double problem470(){
	return notSolved();
}

long double problem471(){
	return notSolved();
}

long double problem472(){
	return notSolved();
}

long double problem473(){
	return notSolved();
}

long double problem474(){
	return notSolved();
}

long double problem475(){
	return notSolved();
}

long double problem476(){
	return notSolved();
}

long double problem477(){
	return notSolved();
}

long double problem478(){
	return notSolved();
}

long double problem479(){
	return notSolved();
}

long double problem480(){
	return notSolved();
}

long double problem481(){
	return notSolved();
}

long double problem482(){
	return notSolved();
}

long double problem483(){
	return notSolved();
}

long double problem484(){
	return notSolved();
}

long double problem485(){
	return notSolved();
}

long double problem486(){
	return notSolved();
}

long double problem487(){
	return notSolved();
}

long double problem488(){
	return notSolved();
}

long double problem489(){
	return notSolved();
}

long double problem490(){
	return notSolved();
}

long double problem491(){
	return notSolved();
}

long double problem492(){
	return notSolved();
}

long double problem493(){
	return notSolved();
}

long double problem494(){
	return notSolved();
}

long double problem495(){
	return notSolved();
}

long double problem496(){
	return notSolved();
}

long double problem497(){
	return notSolved();
}

long double problem498(){
	return notSolved();
}

long double problem499(){
	return notSolved();
}

long double problem500(){
	return notSolved();
}

long double problem501(){
	return notSolved();
}

long double problem502(){
	return notSolved();
}

long double problem503(){
	return notSolved();
}

long double problem504(){
	return notSolved();
}

long double problem505(){
	return notSolved();
}

long double problem506(){
	return notSolved();
}

long double problem507(){
	return notSolved();
}

long double problem508(){
	return notSolved();
}

long double problem509(){
	return notSolved();
}

long double problem510(){
	return notSolved();
}

long double problem511(){
	return notSolved();
}

long double problem512(){
	return notSolved();
}

long double problem513(){
	return notSolved();
}

long double problem514(){
	return notSolved();
}

long double problem515(){
	return notSolved();
}

long double problem516(){
	return notSolved();
}

long double problem517(){
	return notSolved();
}

long double problem518(){
	return notSolved();
}

long double problem519(){
	return notSolved();
}

long double problem520(){
	return notSolved();
}

long double problem521(){
	return notSolved();
}

long double problem522(){
	return notSolved();
}

long double problem523(){
	return notSolved();
}

long double problem524(){
	return notSolved();
}

long double problem525(){
	return notSolved();
}

long double problem526(){
	return notSolved();
}

long double problem527(){
	return notSolved();
}

long double problem528(){
	return notSolved();
}

long double problem529(){
	return notSolved();
}

long double problem530(){
	return notSolved();
}

long double problem531(){
	return notSolved();
}

long double problem532(){
	return notSolved();
}

long double problem533(){
	return notSolved();
}

long double problem534(){
	return notSolved();
}

long double problem535(){
	return notSolved();
}

long double problem536(){
	return notSolved();
}

long double problem537(){
	return notSolved();
}

long double problem538(){
	return notSolved();
}

long double problem539(){
	return notSolved();
}

long double problem540(){
	return notSolved();
}

long double problem541(){
	return notSolved();
}

long double problem542(){
	return notSolved();
}

long double problem543(){
	return notSolved();
}

long double problem544(){
	return notSolved();
}

long double problem545(){
	return notSolved();
}

long double problem546(){
	return notSolved();
}

long double problem547(){
	return notSolved();
}

long double problem548(){
	return notSolved();
}

long double problem549(){
	return notSolved();
}

long double problem550(){
	return notSolved();
}

long double problem551(){
	return notSolved();
}

long double problem552(){
	return notSolved();
}

long double problem553(){
	return notSolved();
}

long double problem554(){
	return notSolved();
}

long double problem555(){
	return notSolved();
}

long double problem556(){
	return notSolved();
}

long double problem557(){
	return notSolved();
}

long double problem558(){
	return notSolved();
}

long double problem559(){
	return notSolved();
}

long double problem560(){
	return notSolved();
}

long double problem561(){
	return notSolved();
}

long double problem562(){
	return notSolved();
}

long double problem563(){
	return notSolved();
}

long double problem564(){
	return notSolved();
}

long double problem565(){
	return notSolved();
}

long double problem566(){
	return notSolved();
}

long double problem567(){
	return notSolved();
}

long double problem568(){
	return notSolved();
}

long double problem569(){
	return notSolved();
}

long double problem570(){
	return notSolved();
}

long double problem571(){
	return notSolved();
}

long double problem572(){
	return notSolved();
}

long double problem573(){
	return notSolved();
}

long double problem574(){
	return notSolved();
}

long double problem575(){
	return notSolved();
}

long double problem576(){
	return notSolved();
}

long double problem577(){
	return notSolved();
}

long double problem578(){
	return notSolved();
}

long double problem579(){
	return notSolved();
}

long double problem580(){
	return notSolved();
}

long double problem581(){
	return notSolved();
}

long double problem582(){
	return notSolved();
}

long double problem583(){
	return notSolved();
}

long double problem584(){
	return notSolved();
}

long double problem585(){
	return notSolved();
}

long double problem586(){
	return notSolved();
}

long double problem587(){
	return notSolved();
}

long double problem588(){
	return notSolved();
}

long double problem589(){
	return notSolved();
}

long double problem590(){
	return notSolved();
}

long double problem591(){
	return notSolved();
}

long double problem592(){
	return notSolved();
}

long double problem593(){
	return notSolved();
}

long double problem594(){
	return notSolved();
}

long double problem595(){
	return notSolved();
}

long double problem596(){
	return notSolved();
}

long double problem597(){
	return notSolved();
}

long double problem598(){
	return notSolved();
}

long double problem599(){
	return notSolved();
}

long double problem600(){
	return notSolved();
}
