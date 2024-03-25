#include <iostream>
#include <locale.h>
#include <cstdio>
#include <cstdlib>
#include "mainPlan.cpp"

using namespace std;

// 1 Funkcja, której celem jest odczytywanie planu lekcji
int odczytajPlan() {
    return 0;
}

// 2 Funkcja, której zadaniem będzie edytowanie planu lekcji
int edytujPlan() {
    return 0;
}

// 3 Funkcja, będzie odpowiadać za zapisywanie planu lekcji
int zapiszPlan() {
    return 0;
}

// 4 Funkcja będzie wypisywać działanie programu oraz jak się nim obsługiwać
int pomoc() {
    cout << "Plan lekcji opiera się na wielu funkcjach, takich jak: " << endl;
    cout << "odczytywanie planu \n edytowanie planu \n zapisywanie planu \n pomocy z planem \n zakończenia programu" << endl;
    cout << "Aby dokonać odczytu planu, w odpowiedzi użytkownika należy wpisać 1" << endl;
    cout << "Aby dokonać edycji planu, w odpowiedzi użytkownika należy wpisać 2" << endl;
    cout << "Aby dokonać zapisu planu, w odpowiedzi użytkownika należy wpisać 3" << endl;
    cout << "Aby dokonać zakończenia działania programu, w odpowiedzi użytkownika należy wpisać 5" << endl;
}

// 5 Funkcja ta odpowiada za zakończenie działania programu
int zakoncz() {
    abort();
}
