#include <random>
#include <iostream>

using namespace std;

int main() {
    random_device rd;   // non-deterministic generator
    int counter = 0;
    int a, b, positiveAnswer, negativeAnswer, rightPositiveAnswer, rightNegativeAnswer;

    do {
        counter++;

        for (int i = 0; i < 2; i++) {
            mt19937 gen(rd());  // to seed mersenne twister.
            uniform_int_distribution<> dist(-9, 9); // distribute results between 1 and 6 inclusive.

            if (i == 0) { a = dist(gen); }
            else { b = dist(gen); }
        }
        
        rightPositiveAnswer = a + b;
        rightNegativeAnswer = a - b;

        do {
            cout << endl << "  Solve: " << a << " + " << b << " = ";
            cin >> positiveAnswer;
            if (rightPositiveAnswer == positiveAnswer) { cout << endl << "  TRUE!" << endl; }
            else { cout << endl << "  FALSE!" << endl; }
        } while (rightPositiveAnswer != positiveAnswer);

        do {
            cout << endl << "  Solve: " << a << " - " << b << " = ";
            cin >> negativeAnswer;
            if (rightNegativeAnswer == negativeAnswer) { cout << endl << "  TRUE!" << endl; }
            else { cout << endl << "  FALSE!" << endl; }
        } while (rightNegativeAnswer != negativeAnswer);

        cout << endl;
        system("pause");
        system("cls");

    } while (counter != 3);

    return 0;
}