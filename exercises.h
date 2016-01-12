#ifndef EXERCISES_H_INCLUDED
#define EXERCISES_H_INCLUDED

bool isPerfectSquare(int n);
//takes a positive integer as an argument and returns true
//if the integer is a perfect square and false if not
bool isPrime(long long n);
//takes an integer and returns false if the number is less
//than 2 or not a prime number, true if else

long getTriangleNumber(int n);
//takes a positive integer, n, and returns the
//nth triangle number

int getNumDivisors(long n);
//takes a positive integer and returns its number of divisors

long long getSumString(std::string n);
//takes a string of numbers and return the sum of every digit

long long getNumCollatzTerms(long long n);
//takes a positive integer and returns the number of terms in
//its Collatz sequence (if odd, multiply by 3 and add 1; if
//even, divide by 2; repeat until the number 1 is reached and
//return the amount of terms (including n and 1))

long long factorial(int n);
//takes a nonnegative integer and returns its factorial

long long getSumProperDivisors(long long n);
//takes a nonnegative integer and returns the sum of its proper
//divisors, the positive numbers which are less than the integer
//that divide evenly into the integer

bool getAmicability(long long n);
//takes a positive integer and returns true if amicable, false
//if not. amicable numbers definition: d(a) = b && d(b) = a &&
//a != b, for d(n) defined as the sum of proper divisors of n
//(numbers less than n which divide evenly into n)

long getAlphabeticalSum(std::string s);
//takes a string of characters and returns the alphabetical
//sum of all the alphabetical chars in the string. "alpha"
//would return a sum of 1+12+16+8+1=38

long double quadraticFormulaTermGenerator(long double a, long double b, long double c, long double n);
//outputs the simplified expression of the form
//an^2 + bn + c

void getDiagonalSums(std::vector<std::vector<int> > squareMatrix, int matrixLength, int &majorDiagonalSum, int &minorDiagonalSum);
//takes a square 2-dimensional vector of ints, its length, and the
//addresses of two variables containing ints and sets those two
//variables to respectively contain the sums of the major and
//minor diagonals of the matrix

bool equalsSumOfNthPowerOfDigits(long long n, int power);
//takes two positive integers and calculates the sum of the power
//represented by the second number of the number's digits and returns
//true if the first number and the sum are equal, false if else

typedef long double (*Problem)();
const int PROBLEMS_TOTAL = 600;

//use header file for all problem functions, typedef, const declarations, and exercises array
long double problem1(), problem2(), problem3(), problem4(), problem5(), problem6(), problem7(), problem8(), problem9(), problem10(), problem11(), problem12(), problem13(), problem14(), problem15(), problem16(), problem17(), problem18(), problem19(), problem20(), problem21(), problem22(), problem23(), problem24(), problem25(), problem26(), problem27(), problem28(), problem29(), problem30(), problem31(), problem32(), problem33(), problem34(), problem35(), problem36(), problem37(), problem38(), problem39(), problem40(), problem41(), problem42(), problem43(), problem44(), problem45(), problem46(), problem47(), problem48(), problem49(), problem50(), problem51(), problem52(), problem53(), problem54(), problem55(), problem56(), problem57(), problem58(), problem59(), problem60(), problem61(), problem62(), problem63(), problem64(), problem65(), problem66(), problem67(), problem68(), problem69(), problem70(), problem71(), problem72(), problem73(), problem74(), problem75(), problem76(), problem77(), problem78(), problem79(), problem80(), problem81(), problem82(), problem83(), problem84(), problem85(), problem86(), problem87(), problem88(), problem89(), problem90(), problem91(), problem92(), problem93(), problem94(), problem95(), problem96(), problem97(), problem98(), problem99(), problem100(), problem101(), problem102(), problem103(), problem104(), problem105(), problem106(), problem107(), problem108(), problem109(), problem110(), problem111(), problem112(), problem113(), problem114(), problem115(), problem116(), problem117(), problem118(), problem119(), problem120(), problem121(), problem122(), problem123(), problem124(), problem125(), problem126(), problem127(), problem128(), problem129(), problem130(), problem131(), problem132(), problem133(), problem134(), problem135(), problem136(), problem137(), problem138(), problem139(), problem140(), problem141(), problem142(), problem143(), problem144(), problem145(), problem146(), problem147(), problem148(), problem149(), problem150(), problem151(), problem152(), problem153(), problem154(), problem155(), problem156(), problem157(), problem158(), problem159(), problem160(), problem161(), problem162(), problem163(), problem164(), problem165(), problem166(), problem167(), problem168(), problem169(), problem170(), problem171(), problem172(), problem173(), problem174(), problem175(), problem176(), problem177(), problem178(), problem179(), problem180(), problem181(), problem182(), problem183(), problem184(), problem185(), problem186(), problem187(), problem188(), problem189(), problem190(), problem191(), problem192(), problem193(), problem194(), problem195(), problem196(), problem197(), problem198(), problem199(), problem200(), problem201(), problem202(), problem203(), problem204(), problem205(), problem206(), problem207(), problem208(), problem209(), problem210(), problem211(), problem212(), problem213(), problem214(), problem215(), problem216(), problem217(), problem218(), problem219(), problem220(), problem221(), problem222(), problem223(), problem224(), problem225(), problem226(), problem227(), problem228(), problem229(), problem230(), problem231(), problem232(), problem233(), problem234(), problem235(), problem236(), problem237(), problem238(), problem239(), problem240(), problem241(), problem242(), problem243(), problem244(), problem245(), problem246(), problem247(), problem248(), problem249(), problem250(), problem251(), problem252(), problem253(), problem254(), problem255(), problem256(), problem257(), problem258(), problem259(), problem260(), problem261(), problem262(), problem263(), problem264(), problem265(), problem266(), problem267(), problem268(), problem269(), problem270(), problem271(), problem272(), problem273(), problem274(), problem275(), problem276(), problem277(), problem278(), problem279(), problem280(), problem281(), problem282(), problem283(), problem284(), problem285(), problem286(), problem287(), problem288(), problem289(), problem290(), problem291(), problem292(), problem293(), problem294(), problem295(), problem296(), problem297(), problem298(), problem299(), problem300(), problem301(), problem302(), problem303(), problem304(), problem305(), problem306(), problem307(), problem308(), problem309(), problem310(), problem311(), problem312(), problem313(), problem314(), problem315(), problem316(), problem317(), problem318(), problem319(), problem320(), problem321(), problem322(), problem323(), problem324(), problem325(), problem326(), problem327(), problem328(), problem329(), problem330(), problem331(), problem332(), problem333(), problem334(), problem335(), problem336(), problem337(), problem338(), problem339(), problem340(), problem341(), problem342(), problem343(), problem344(), problem345(), problem346(), problem347(), problem348(), problem349(), problem350(), problem351(), problem352(), problem353(), problem354(), problem355(), problem356(), problem357(), problem358(), problem359(), problem360(), problem361(), problem362(), problem363(), problem364(), problem365(), problem366(), problem367(), problem368(), problem369(), problem370(), problem371(), problem372(), problem373(), problem374(), problem375(), problem376(), problem377(), problem378(), problem379(), problem380(), problem381(), problem382(), problem383(), problem384(), problem385(), problem386(), problem387(), problem388(), problem389(), problem390(), problem391(), problem392(), problem393(), problem394(), problem395(), problem396(), problem397(), problem398(), problem399(), problem400(), problem401(), problem402(), problem403(), problem404(), problem405(), problem406(), problem407(), problem408(), problem409(), problem410(), problem411(), problem412(), problem413(), problem414(), problem415(), problem416(), problem417(), problem418(), problem419(), problem420(), problem421(), problem422(), problem423(), problem424(), problem425(), problem426(), problem427(), problem428(), problem429(), problem430(), problem431(), problem432(), problem433(), problem434(), problem435(), problem436(), problem437(), problem438(), problem439(), problem440(), problem441(), problem442(), problem443(), problem444(), problem445(), problem446(), problem447(), problem448(), problem449(), problem450(), problem451(), problem452(), problem453(), problem454(), problem455(), problem456(), problem457(), problem458(), problem459(), problem460(), problem461(), problem462(), problem463(), problem464(), problem465(), problem466(), problem467(), problem468(), problem469(), problem470(), problem471(), problem472(), problem473(), problem474(), problem475(), problem476(), problem477(), problem478(), problem479(), problem480(), problem481(), problem482(), problem483(), problem484(), problem485(), problem486(), problem487(), problem488(), problem489(), problem490(), problem491(), problem492(), problem493(), problem494(), problem495(), problem496(), problem497(), problem498(), problem499(), problem500(), problem501(), problem502(), problem503(), problem504(), problem505(), problem506(), problem507(), problem508(), problem509(), problem510(), problem511(), problem512(), problem513(), problem514(), problem515(), problem516(), problem517(), problem518(), problem519(), problem520(), problem521(), problem522(), problem523(), problem524(), problem525(), problem526(), problem527(), problem528(), problem529(), problem530(), problem531(), problem532(), problem533(), problem534(), problem535(), problem536(), problem537(), problem538(), problem539(), problem540(), problem541(), problem542(), problem543(), problem544(), problem545(), problem546(), problem547(), problem548(), problem549(), problem550(), problem551(), problem552(), problem553(), problem554(), problem555(), problem556(), problem557(), problem558(), problem559(), problem560(), problem561(), problem562(), problem563(), problem564(), problem565(), problem566(), problem567(), problem568(), problem569(), problem570(), problem571(), problem572(), problem573(), problem574(), problem575(), problem576(), problem577(), problem578(), problem579(), problem580(), problem581(), problem582(), problem583(), problem584(), problem585(), problem586(), problem587(), problem588(), problem589(), problem590(), problem591(), problem592(), problem593(), problem594(), problem595(), problem596(), problem597(), problem598(), problem599(), problem600();

#endif // EXERCISES_H_INCLUDED
