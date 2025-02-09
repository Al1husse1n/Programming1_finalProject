#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;
string generatepal();
bool checkpal();
void checkorgenerate();
void Calculator();
string caesarCipher();
void displayBoard();
void checkers();
void password();
void typing();
bool isLeapYear();
void agecalc();
void convertTemperature();
void convertMass();
void convertLength();
void chooseConverter();
void random_gen();
void displayMenu() {
    int choice;

    do {
        cout<<endl;
        cout << "Utility Application Menu:"<<endl;
        cout << "1. Palindrome String Generator and Checker"<<endl;
        cout << "2. Arithmetic Calculator"<<endl;
        cout << "3. Caesar Cipher Encryption and Decryption"<<endl;
        cout << "4. Checkers Game"<<endl;
        cout << "5. Password Generator and Strength Checker"<<endl;
        cout << "6. Typing Speed and Accuracy Tester"<<endl;
        cout << "7. Age Calculator"<<endl;
        cout << "8. Unit Converter"<<endl;
        cout << "9. Number Guessing Game"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Please enter your choice (0-9): ";

        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                checkorgenerate();
                break;
            case 2:
                Calculator();
                break;
            case 3:
                cout<<caesarCipher();
                break;
            case 4:
                checkers();
                break;
            case 5:
                password();
                break;
            case 6:
                typing();
                break;
            case 7:
                agecalc();
                break;
            case 8:
                chooseConverter();
                break;
            case 9:
                random_gen();
                break;
            case 0:
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

string generatepal(){
    string str,reversed_str;
    cout<<"Input a Non-palindrome string, and i will generate a palindrome: ";
    getline(cin,str);
    for(int i = str.length()-1; i>=0; i--){
        reversed_str+=str[i];
    }
    return str + reversed_str;
}

bool checkpal(){
    string str,str1;
    cout<<"Input a string to check if it's a palindrome: ";
    getline(cin,str);
    for(int i = 0; i<str.length(); i++){
        if(str[i] != ' '){
            str1 += tolower(str[i]);
        }
    }
    for(int i = 0; i< str1.length(); i++){
        if(str1[i] != str1[str1.length()-1-i]){
            return false;
        }
    }
    return true;
}
void checkorgenerate(){
    int ch;
    cout<<"Do you want to check if a string is palindrome(press 1) or generate a palindrome(press 2): ";
    cin>>ch;
    cin.ignore();
    if(ch == 1){
        if(checkpal() == 1){
            cout<<"It's a palindrome"<<endl;
        }
        else{
            cout<<"It's not a palindrome"<<endl;
        }
    }
    else if(ch == 2){
        cout<<generatepal();
    }
    else{
        cout<<"Invalid input";
    }
}
string caesarCipher() {
    string text,result = "";
    int shift;
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter shift number: ";
    cin >> shift;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        else if (isdigit(c)) {
            c = (c - '0' + shift) % 10 + '0';
        }
        else {
            c = (c + shift) % 128;
        }
        result += c;
    }
    return result;
}
void displayBoard(string b[80]){
        for(int i = 0; i<80; i++){
                string x = b[i];
            if((i+1)% 10 == 0){
                cout<<x<< endl;
                cout<<endl;
            }
            else{
                cout<<x + "  ";
            }
        }
    }

void checkers(){
    int s ;
    int c ;
    bool boo;
    char cap;
    char sma;
    string mov;
    string small = "abcdefghijklmnopqrstuvwxyz";
    int lenOfs = 12;
    string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lenOfc = 12;
    string board[80] = {
        "|","0","a","0","b","0","c","0","d","|",   //0 is black, small soldier1, capital soldier2 , _ red
        "|","e","0","f","0","g","0","h","0","|",
        "|","0","l","0","k","0","j","0","i","|",
        "|","_","0","_","0","_","0","_","0","|",
        "|","0","_","0","_","0","_","0","_","|",
        "|","I","0","J","0","K","0","L","0","|",
        "|","0","H","0","G","0","F","0","E","|",
        "|","A","0","B","0","C","0","D","0","|"
        };
    int len = sizeof(board);

    displayBoard(board);
    cout<<endl;
    cout << "Player one, Your soldiers will be the capital letters"<<endl;
    cout << "Player two, Your soldiers will be the small letters"<< endl;
    cout << "if you want to quit, you can enter q"<<endl;
    cout<<endl;
       while(lenOfc > 0 && lenOfs > 0){
            c = 0;
            s = 0;
        while(c == 0){
            cout<< "player one, which letter do you want to move: enter a capital letter ";
            cin>> cap;
            string str(1,toupper(cap));
            boo = 0;
            for(int i = 0; i<len; i++){
                    if(i == len -1 && board[i]!= str){
                        boo += 1;
                    }
                    else if(board[i] == str){
                        break;
                    }
            }
            if(str == "Q"){
                cout<<"Player one lost";
                return;
            }
            else if(boo){
                cout<<"soldier not found"<<endl;
                continue;
            }
            cout << "To move your soldier, enter TR{top right), TL(top left) ";
            cin>> mov;
            mov[0] = toupper(mov[0]);
            if(mov.length() == 2){
            mov[1] = toupper(mov[1]);
            }
            if(mov== "Q"){
                cout<<"Player one lost";
                return;
            }
            else if(mov != "TR" && mov != "TL"){
                cout<<"enter a valid input"<<endl;
            }
            else{
                int indexOfcap;
                for(int i = 0; i<len; i++){
                    if(board[i] == str){
                        indexOfcap = i;
                        break;
                    }
                }
                if(mov == "TR"){
                        string tr = board[indexOfcap - 9];
                        if(tr == "|"){
                            cout<<"move is out of bounds"<<endl;
                        }
                        else if(tr == "_"){
                            board[indexOfcap - 9] = str;
                            board[indexOfcap] =  "_";
                            cout<<endl;
                            displayBoard(board);
                            cout<<endl;
                            c+=1;
                        }
                        else if(capital.find(tr)!= string::npos){
                            cout<<"invalid move"<<endl;
                        }
                        else if(small.find(tr) != string::npos){
                            string trtr = board[indexOfcap - 18];
                            if(capital.find(trtr) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else if(small.find(trtr) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else{
                                lenOfs -=1;
                                board[indexOfcap - 18] = str;
                                board[indexOfcap - 9] = "_";
                                board[indexOfcap] = "_";
                                cout<<endl;
                                displayBoard(board);
                                cout<<endl;
                                cout<<"player one you have "<<lenOfc<<"/12 soldiers remaining."<<endl;
                                cout<<"player two you have "<<lenOfs<<"/12 soldiers remaining."<<endl;

                            }
                        }
                }
                if(mov == "TL"){
                        string tl = board[indexOfcap - 11];
                        if(tl == "|"){
                            cout<<"move is out of bounds"<<endl;
                        }
                        else if(tl == "_"){
                            board[indexOfcap - 11] = str;
                            board[indexOfcap] =  "_";
                            cout<<endl;
                            displayBoard(board);
                            cout<<endl;
                            c+=1;
                        }
                        else if(capital.find(tl)!= string::npos){
                            cout<<"invalid move"<<endl;
                        }
                        else if(small.find(tl) != string::npos){
                            string tltl = board[indexOfcap - 22];
                            if(capital.find(tltl) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else if(small.find(tltl) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else{
                                lenOfs -= 1;
                                board[indexOfcap - 22] = str;
                                board[indexOfcap - 11] = "_";
                                board[indexOfcap] = "_";
                                cout<<endl;
                                displayBoard(board);
                                cout<<endl;
                                cout<<"player one you have "<<lenOfc<<"/12 soldiers remaining."<<endl;
                                cout<<"player two you have "<<lenOfs<<"/12 soldiers remaining."<<endl;

                            }
                        }
                }
            }

        }
        while(s == 0){
            cout<< "player two, which letter do you want to move : enter a small letter ";
            cin>>sma;
            string str(1,tolower(sma));
            boo = 0;
            for(int i = 0; i<len; i++){
                    if(i == len -1 && board[i]!= str){
                        boo += 1;
                    }
                    else if(board[i] == str){
                        break;
                    }
                }
            if(str == "q"){
                cout<<"Player two lost";
                return;
            }
            else if(boo){
                cout<<"soldier not found"<<endl;
                continue;
            }
            cout << "To move your soldier, enter BR{bottom right), BL(bottom left) ";
            cin>> mov;
            mov[0] = toupper(mov[0]);
            if(mov.length() == 2){
            mov[1] = toupper(mov[1]);
            }
            if(mov== "Q"){
                cout<<"Player two lost";
                return;
            }
            else if(mov != "BR" && mov != "BL"){
                cout<<"enter a valid input"<<endl;
            }
            else{
                int indexOfsma;
                for(int i = 0; i<len; i++){
                    if(board[i] == str){
                        indexOfsma = i;
                        break;
                    }
                }
                if(mov == "BR"){
                        string br = board[indexOfsma + 11];
                        if(br == "|"){
                            cout<<"move is out of bounds"<<endl;
                        }
                        else if(br == "_"){
                            board[indexOfsma + 11] = str;
                            board[indexOfsma] =  "_";
                            cout<<endl;
                            displayBoard(board);
                            cout<<endl;
                            s+=1;
                        }
                        else if(small.find(br)!= string::npos){
                            cout<<"invalid move"<<endl;
                        }
                        else if(capital.find(br) != string::npos){
                            string brbr = board[indexOfsma + 22];
                            if(capital.find(brbr) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else if(small.find(brbr) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else{
                                lenOfc -= 1;
                                board[indexOfsma + 22] = str;
                                board[indexOfsma + 11] = "_";
                                board[indexOfsma] = "_";
                                cout<<endl;
                                displayBoard(board);
                                cout<<endl;
                                cout<<"player one you have "<<lenOfc<<"/12 soldiers remaining."<<endl;
                                cout<<"player two you have "<<lenOfs<<"/12 soldiers remaining."<<endl;

                            }
                        }
                }
                if(mov == "BL"){
                        string bl = board[indexOfsma + 9];
                        if(bl == "|"){
                            cout<<"move is out of bounds"<<endl;
                        }
                        else if(bl == "_"){
                            board[indexOfsma + 9] = str;
                            board[indexOfsma] =  "_";
                            cout<<endl;
                            displayBoard(board);
                            cout<<endl;
                            s+=1;
                        }
                        else if(small.find(bl)!= string::npos){
                            cout<<"invalid move"<<endl;;
                        }
                        else if(capital.find(bl) != string::npos){
                            string blbl = board[indexOfsma + 18];
                            if(capital.find(blbl) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else if(small.find(blbl) != string::npos){
                                cout<<"invalid move"<<endl;
                            }
                            else{
                                lenOfc -= 1;
                                board[indexOfsma + 18] = str;
                                board[indexOfsma + 9] = "_";
                                board[indexOfsma] = "_";
                                cout<<endl;
                                displayBoard(board);
                                cout<<endl;
                                cout<<"player one you have "<<lenOfc<<"/12 soldiers remaining."<<endl;
                                cout<<"player two you have "<<lenOfs<<"/12 solldiers remaining."<<endl;

                            }
                        }
                }
            }

        }

        }
    if(lenOfs == 0){
        cout<<"congratulations player one, you have won"<<endl;
    }
    else{
        cout<<"congratulations player two, you have won"<<endl;
    }

}
void password() {
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Check password strength\n";
    cout << "2. Generate a password\n";
    cin >> choice;

    if (choice == 1) {
        string password;
        cout << "Enter a password: ";
        cin >> password;

        bool hasUpperCase = false, hasLowerCase = false, hasDigit = false, hasSpecialChar = false;
        const string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

        for (char ch : password) {
            if (isupper(ch)) hasUpperCase = true;
            if (islower(ch)) hasLowerCase = true;
            if (isdigit(ch)) hasDigit = true;
            if (specialChars.find(ch) != string::npos) hasSpecialChar = true;
        }

        int typesCount = hasUpperCase + hasLowerCase + hasDigit + hasSpecialChar;
        string strength;

        if (password.length() >= 8 && typesCount == 4) {
            strength = "Very Strong";
        } else if (password.length() >= 10 && typesCount >= 3) {
            strength = "Strong";
        } else if (password.length() >= 12 && typesCount >= 2) {
            strength = "Medium";
        } else if (password.length() >= 14 && typesCount >= 1) {
            strength = "Weak";
        } else {
            strength = "Very Weak";
        }

        cout << "Password strength: " << strength << endl;
    } else if (choice == 2) {
        int length;
        cout << "Enter the desired password length: ";
        cin >> length;

        const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
        string password;
        srand(time(0));

        for (int i = 0; i < length; ++i) {
            password += chars[rand() % chars.length()];
        }

        cout << "Generated password: " << password << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}
void Calculator() {
    char op;
	double result,first_num,second_num;
    double *first_Number = new double;
    double *second_Number = new double;
    char *operater = new char;
    cout<<"Enter your first number: ";
    cin>>*first_Number;
    cin.ignore();
    cout<<"Enter The operation(+, -, *, /, %) : ";
    cin>>*operater;
    cout<<"Enter your second number: ";
    cin>>*second_Number;
	switch (*operater) {
	case '+': result = *first_Number + *second_Number;
		cout << *first_Number << " + " << *second_Number << " = " <<result;
		break;

	case '-':result = *first_Number - *second_Number;
		cout << *first_Number << " - " << *second_Number << " = " << result;
		break;
	case '/':
	    if(*second_Number==0){
            cout<<"You can't divide a number by zero"<<endl;
	    }
	    else{
	    result = *first_Number / *second_Number;
		cout << *first_Number << " / " << *second_Number << " = " << result;
	    }
		break;
	case '*':result = *first_Number * *second_Number;
		cout << *first_Number << " * " << *second_Number << " = " << result;
		break;
	case '%':result = fmod(*first_Number, *second_Number);
		cout << *first_Number << " % " << *second_Number << " = " << result;
		break;
	default: cout << "Invalid input";
	}
    delete first_Number;
    delete second_Number;
    delete operater;
}

void typing() {
    string test_sentence = "The quick brown fox jumps over the lazy dog.";
    string user_input;
    int correct_chars = 0;

    cout << "Type the following sentence as quickly and accurately as you can:" << endl;
    cout << test_sentence << endl;

    auto start = high_resolution_clock::now();

    getline(cin, user_input);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start).count();


    int min_length = min(test_sentence.length(), user_input.length());
    for (int i = 0; i < min_length; ++i) {
        if (test_sentence[i] == user_input[i]) {
            correct_chars++;
        }
    }

    double typing_speed = (user_input.length() / (double)duration) * 60;

    double accuracy = (correct_chars / (double)test_sentence.length()) * 100;

    cout << "Time taken: " << duration << " seconds" << endl;
    cout << "Typing speed: " << typing_speed << " characters per minute" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;

}
bool isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}


void agecalc() {
    time_t now = time(0);
    tm now_tm;
    localtime_s(&now_tm, &now);

    int birth_year, birth_month, birth_day;
    cout << "Enter your birth year: ";
    cin >> birth_year;
    cout << "Enter your birth month(number): ";
    cin >> birth_month;
    cout << "Enter your birth day: ";
    cin >> birth_day;

    tm birth_tm = {};
    birth_tm.tm_year = birth_year - 1900;
    birth_tm.tm_mon = birth_month - 1;
    birth_tm.tm_mday = birth_day;

    time_t birth_time = mktime(&birth_tm);

    double seconds = difftime(now, birth_time);

    int leap_years = 0;
    for (int year = birth_year; year <= now_tm.tm_year + 1900; year++) {
        if (isLeapYear(year)) {
            leap_years++;
        }
    }

    int years = seconds / (60 * 60 * 24 * 365);
    seconds -= years * 60 * 60 * 24 * 365;
    int months = seconds / (60 * 60 * 24 * 30);
    seconds -= months * 60 * 60 * 24 * 30;
    int days = seconds / (60 * 60 * 24);
    seconds -= days * 60 * 60 * 24;
    int weeks = days / 7;
    days %= 7;
    int hours = seconds / (60 * 60);
    seconds -= hours * 60 * 60;
    int minutes = seconds / 60;
    seconds -= minutes * 60;
    days += leap_years;


    cout << "Your age is: " << years << " years, " << months << " months, " << weeks << " weeks, "
        << days << " days, " << hours << " hours, " << minutes << " minutes, " << (int)seconds << " seconds." << endl;

}


void chooseConverter() {
    int choice;
    do{
        cout << "Unit Converter" << endl;
        cout << "1. Temperature (Celsius, Fahrenheit, Kelvin)" << endl;
        cout << "2. Mass (Kilograms, Pounds, Grams)" << endl;
        cout << "3. Length (Meters, Kilometers, Miles, Inches)" << endl;
        cout << "0. Exit the application."<<endl;
        cout << "Choose a conversion category (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertMass();
                break;
            case 3:
                convertLength();
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid category (1-3)." << endl;
        }
    }while(choice !=0);
}

void convertTemperature() {
    double value, result;
    string from, to;

    cout << "\nEnter temperature value: ";
    cin >> value;

    cout << "Convert from (Celsius, Fahrenheit, Kelvin): ";
    cin >> from;

    cout << "Convert to (Celsius, Fahrenheit, Kelvin): ";
    cin >> to;

    if (from == "Celsius") {
        if (to == "Fahrenheit")
            result = (value * 9.0 / 5.0) + 32;
        else if (to == "Kelvin")
            result = value + 273.15;
        else
            result = value;
    }
    else if (from == "Fahrenheit") {
        if (to == "Celsius"|| to == "celsius" || to == "CELSIUS")
            result = (value - 32) * 5.0 / 9.0;
        else if (to == "Kelvin")
            result = (value - 32) * 5.0 / 9.0 + 273.15;
        else
            result = value;
    }
    else if (from == "Kelvin") {
        if (to == "Celsius" )
            result = value - 273.15;
        else if (to == "Fahrenheit")
            result = (value - 273.15) * 9.0 / 5.0 + 32;
        else
            result = value;
    } else {
        cout << "Invalid unit!" << endl;
        return;
    }

    cout << "Converted Value: " << result << " " << to << endl;
}

void convertMass() {
    double value, result;
    string from, to;

    cout << "\nEnter mass value: ";
    cin >> value;

    cout << "Convert from (Kilograms, Pounds, Grams): ";
    cin >> from;

    cout << "Convert to (Kilograms, Pounds, Grams): ";
    cin >> to;

    if (from == "Kilograms") {
        if (to == "Pounds")
            result = value * 2.20462;
        else if (to == "Grams")
            result = value * 1000;
        else
            result = value;
    }
    else if (from == "Pounds" ) {
        if (to == "Kilograms")
            result = value / 2.20462;
        else if (to == "Grams")
            result = value * 453.592;
        else
            result = value;
    }
    else if (from == "Grams") {
        if (to == "Kilograms")
            result = value / 1000;
        else if (to == "Pounds")
            result = value / 453.592;
        else
            result = value;
    } else {
        cout << "Invalid unit!" << endl;
        return;
    }

    cout << "Converted Value: " << result << " " << to << endl;
}

void convertLength() {
    double value, result;
    string from, to;

    cout << "\nEnter length value: ";
    cin >> value;

    cout << "Convert from (Meters, Kilometers, Miles, Inches): ";
    cin >> from;

    cout << "Convert to (Meters, Kilometers, Miles, Inches): ";
    cin >> to;

    if (from == "Meters") {
        if (to == "Kilometers")
            result = value / 1000;
        else if (to == "Miles")
            result = value / 1609.34;
        else if (to == "Inches")
            result = value * 39.3701;
        else
            result = value;
    }
    else if (from == "Kilometers") {
        if (to == "Meters")
            result = value * 1000;
        else if (to == "Miles")
            result = value / 1.60934;
        else if (to == "Inches")
            result = value * 39370.1;
        else
            result = value;
    }
    else if (from == "Miles") {
        if (to == "Meters")
            result = value * 1609.34;
        else if (to == "Kilometers")
            result = value * 1.60934;
        else if (to == "Inches")
            result = value * 63360;
        else
            result = value;
    }
    else if (from == "Inches") {
        if (to == "Meters")
            result = value / 39.3701;
        else if (to == "Kilometers")
            result = value / 39370.1;
        else if (to == "Miles")
            result = value / 63360;
        else
            result = value;
    } else {
        cout << "Invalid unit!" << endl;
        return;
    }

    cout << "Converted Value: " << result << " " << to << endl;
}
void random_gen(){
    cout<<"This is a number guessing game"<<endl;
    int random_num, random_min, random_max, n, input_num, tries = 1;
    cout<<"Enter the minimum value: ";
    cin>>random_min;
    cout<<"Enter the maximum value: ";
    cin>>random_max;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(random_min, random_max);
    do{
         random_num = distr(gen);
    }while (random_num == 0);

    n = 0;
    cout<<"We'll start guessing the number, You can enter 0  if you dont want to continue"<<endl;
    cout<<"Guess the number between "<<random_min<<" and "<<random_max<<" , attempt number "<<tries<<": ";
    cin>>input_num;
    while(n<1){
       if(input_num == 0){
            cout<<"You quit the game, try again later"<<endl;
            n+=1;
        }
        else if(random_num == input_num){
            cout<<"Good job!,You've guessed the correct number after "<<tries<<" attempts, The correct number was "<<random_num<<endl;
            n+=1;
        }
        else if(input_num > random_num){
            cout<<"Your number was a bit higher, try again"<<endl;
            tries+=1;
            cout<<"Guess the number, attempt number "<<tries<< ": ";
            cin>>input_num;
        }
          else if(input_num < random_num){
            cout<<"Your number was a bit lower, try again"<<endl;
            tries+=1;
            cout<<"Guess the number, attempt number "<<tries<<": ";
            cin>>input_num;
        }
    }

}

int main() {
    displayMenu();
    return 0;
}
