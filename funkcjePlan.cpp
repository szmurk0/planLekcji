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

- - - - - - - - - Real Cooking


planLekcja.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct Zajecie {
    string godzina;
    string nazwa;
};

map<string, vector<Zajecie>> planZajec;

void WczytajPlanZPliku();
void Odczytaj();
void Edytuj();
void Zapisz();
void Usun();
void Pomoc();
void Zakoncz();

void Menu();

int main() {
    WczytajPlanZPliku();
    Menu();
    return 0;
}

void WczytajPlanZPliku() {
    ifstream plik("data.txt");
    if (!plik.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku data.txt.\n";
        return;
    }

    string linia, dzien;
    while (getline(plik, linia)) {
        if (linia.empty()) continue;

        if (linia.back() == ':') {
            dzien = linia.substr(0, linia.size() - 1);
            planZajec[dzien] = vector<Zajecie>();
        }
        else {
            istringstream iss(linia);
            string godzina, nazwa;
            getline(iss, godzina, ' ');
            iss.ignore(3); // Pomijamy "-"
            getline(iss, nazwa);
            if (nazwa != "---") {
                planZajec[dzien].push_back({ godzina, nazwa });
            }
        }
    }
    plik.close();
}

void Menu() {
    int wybor;
    bool koniec = false;

    while (!koniec) {
        cout << "MÓJ PLAN ZAJĘĆ SZKOLNYCH\n";
        cout << "1. Odczytaj\n";
        cout << "2. Edytuj\n";
        cout << "3. Zapisz\n";
        cout << "4. Usun\n";
        cout << "5. Pomoc\n";
        cout << "6. Zakoncz\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case 1:
            Odczytaj();
            break;
        case 2:
            Edytuj();
            break;
        case 3:
            Zapisz();
            break;
        case 4:
            Usun();
            break;
        case 5:
            Pomoc();
            break;
        case 6:
            koniec = true;
            Zakoncz();
            break;
        default:
            cout << "Nieznana opcja!\n";
            break;
        }
    }
}

void Odczytaj() {
    string dzien;
    cout << "Podaj dzien tygodnia: ";
    cin >> dzien;

    transform(dzien.begin(), dzien.end(), dzien.begin(),
        [](unsigned char c) { return tolower(c); });

    if (planZajec.find(dzien) == planZajec.end()) {
        cout << "Nie znaleziono planu na " << dzien << ".\n";
        return;
    }

    cout << "Plan zajec na " << dzien << ":\n";
    for (const auto& zajecie : planZajec[dzien]) {
        cout << zajecie.godzina << " - " << zajecie.nazwa << "\n";
    }
}

void Edytuj() {
    // Tutaj implementacja funkcji Edytuj.
}

void Zapisz() {
    ofstream plik("data.txt");
    if (!plik.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku data.txt do zapisu.\n";
        return;
    }

    for (const auto& dzien : planZajec) {
        plik << dzien.first << ":\n";
        for (const auto& zajecie : dzien.second) {
            plik << zajecie.godzina << " - " << zajecie.nazwa << "\n";
        }
        plik << "\n";
    }
    plik.close();
    cout << "Zapisano plan zajec.\n";
}

void Usun() {
    string dzien, godzina;
    cout << "Podaj dzien tygodnia: ";
    cin >> dzien;
    cout << "Podaj godzine zajec: ";
    cin >> godzina;

    auto& zajecia = planZajec[dzien];
    auto it = remove_if(zajecia.begin(), zajecia.end(), [&godzina](const Zajecie& z) {
        return z.godzina == godzina;
        });
    if (it != zajecia.end()) {
        zajecia.erase(it, zajecia.end());
        cout << "Usunieto zajecia.\n";
    }
    else {
        cout << "Nie znaleziono zajec o danej godzinie.\n";
    }
}

void Pomoc() {
    cout << "Informacje o programie i instrukcje obsługi.\n \n" << endl;
    cout << "Plan lekcji opiera się na wielu funkcjach, takich jak: \n " << endl;
    cout << "odczytywanie planu \n edytowanie planu \n zapisywanie planu \n pomocy z planem \n zakończenia programu" << endl;
    cout << "Aby dokonać odczytu planu, w odpowiedzi użytkownika należy wpisać 1" << endl;
    cout << "Aby dokonać edycji planu, w odpowiedzi użytkownika należy wpisać 2" << endl;
    cout << "Aby dokonać zapisu planu, w odpowiedzi użytkownika należy wpisać 3" << endl;
    cout << "Aby dokonać zakończenia działania programu, w odpowiedzi użytkownika należy wpisać 5" << endl;
}

void Zakoncz() {
    cout << "Dziękujemy za korzystanie z naszego programu!\n";
}
