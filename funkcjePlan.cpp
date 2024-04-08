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


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale.h>

using namespace std;

struct Zajecie {
    string godzina;
    string nazwa;
};

map<int, vector<Zajecie>> planZajec; // Poprawiono typ klucza na int

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

    string linia;
    int numerDnia;
    while (getline(plik, linia)) {
        if (linia.empty()) continue;

        if (isdigit(linia[0])) {
            stringstream ss(linia);
            ss >> numerDnia; // Zapisujemy numer dnia tygodnia
            ss.ignore(1); // Pomijamy spacje
            string nazwaDnia;
            ss >> nazwaDnia; // Nazwa dnia nie jest już potrzebna, ale musimy ją odczytać
            planZajec[numerDnia] = vector<Zajecie>();
        }
        else {
            istringstream iss(linia);
            string godzina, nazwa;
            getline(iss, godzina, ' ');
            iss.ignore(3); // Pomijamy "-"
            getline(iss, nazwa);
            if (nazwa != "---") {
                planZajec[numerDnia].push_back({ godzina, nazwa });
            }
        }
    }
    plik.close();
}

void Menu() {
    setlocale(LC_CTYPE, "Polish");
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
    } // &nbsp;
}

void Odczytaj() {
    int numerDnia;
    cout << "Podaj numer dnia tygodnia (1-Poniedzialek, 2-Wtorek, ...): ";
    cin >> numerDnia;

    auto it = planZajec.find(numerDnia);
    if (it == planZajec.end()) {
        cout << "Nie znaleziono planu na dzien numer " << numerDnia << ".\n";
        return;
    }

    cout << "Plan zajec na dzien numer " << numerDnia << ":\n";
    for (const auto& zajecie : it->second) {
        cout << zajecie.godzina << " - " << zajecie.nazwa << "\n";
    }
}

void Edytuj() {
    // Example implementation
    int numerDnia;
    cout << "Podaj numer dnia tygodnia do edycji: ";
    cin >> numerDnia;

    // Check if the day exists in the schedule
    auto it = planZajec.find(numerDnia);
    if (it == planZajec.end()) {
        cout << "Nie ma takiego dnia w planie.\n";
        return;
    }

    // Present options for the day
    cout << "1. Dodaj zajecie\n";
    cout << "2. Edytuj zajecie\n";
    cout << "3. Usun zajecie\n";
    int opcja;
    cin >> opcja;
    switch (opcja) {
    case 1:
        // Dodawanie Klasy
        break;
    case 2:
        // IEdytowanie Klasy
        break;
    case 3:
        // Usuwanie klasy
        break;
    default:
        cout << "Nieznana opcja!\n";
        break;
    }
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
    int numerDnia; // Poprawiono typ zmiennej na int
    cout << "Podaj numer dnia tygodnia: ";
    cin >> numerDnia;

    auto& zajecia = planZajec[numerDnia];
    auto it = remove_if(zajecia.begin(), zajecia.end(), [](const Zajecie& z) {
        // Tutaj wpisz warunek usuwania zajęć
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
