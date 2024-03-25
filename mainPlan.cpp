#include <iostream>
#include <locale.h>
#include "funkcjePlan.cpp"

using namespace std;

int wyborAkcja;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    cout << "Witaj w programie Planu Zajęć! \n" << endl;

    cout << "Co chcesz zrobić w naszym programie? " << endl;;
    cout << "1. Odczytaj Plan" << endl;
    cout << "2. Edytuj Plan" << endl;
    cout << "3. Zapisz Plan" << endl;
    cout << "4. Pomoc" << endl;
    cout << "5. Zakończ działanie programu" << endl;
    cout << "Twoja odpowiedź: ";
    cin >> wyborAkcja;

    if (wyborAkcja == 1) {
        odczytajPlan();
    }
    else if (wyborAkcja == 2) {
        edytujPlan();
    }
    else if (wyborAkcja == 3) {
        zapiszPlan();
    }
    else if (wyborAkcja == 4) {
        pomoc();
    }
    else if (wyborAkcja == 5) {
        cout << "Zakończono działanie programu" << endl;
        zakoncz();
    } else {
        cout << "Wprowadź poprawny numer do interakcji którą chcesz wykonać od 1 do 5";
    }


    return 0;
}
