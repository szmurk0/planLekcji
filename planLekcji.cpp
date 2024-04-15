//  // ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  === ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  === \\
// ||                                                                                                                                                                                                                 ||
// ||                                                                                                   Witam w Projekcie Planu Lekcji!!!                                                                             || 
// ||                                                                                                                                                                                                                 ||
// ||  Program ten posiada 8 funkcji, z czego można wyróżnić:                                                                                                                                                         ||
// ||  - wyczyscKonsole() -> Głównym celem tej funkcji jest "czyszczenie" konsoli, przez co wszystko wygląda bardziej czysto w efekcie ładniej.                                                                       ||
// ||       Funkcja ta posiada jedną linijkę kodu, lecz dwie funkcje w niej:                                                                                                                                          ||
// ||            - \033[2J powoduje wyczyszczenie ekranu, gdzie                                                                                                                                                       ||
// ||            - \033[1;1H ustawia kursor na początek pierwszej linijki kolejnego wiersza                                                                                                                           ||
// ||                                                                                                                                                                                                                 ||
// ||       Ciąg ten znaków nazywamy sekwencją ucieczki ANSI, sekwencje te są używane do sterowania konsolą terminala.                                                                                                ||
// ||       Znalazłem tą funkcję patrząc na "Przydatne funkcje w C++", bardzo mi się spodobała również pomyślałem że tutaj będzie się dobrze sprawować, awięc jest.                                                   ||
// ||                                                                                                                                                                                                                 ||
// ||  - odczytajPlanLekcji() -> Funkcja ta wypisuje wszystkie lekcje z danego dnia (wybranego przez użytkownika).                                                                                                    ||
// ||       Jest odpowiedzialna za odczytanie planu lekcji z pliku "data.txt" dla danego dnia tygodnia i wyświetlenie go na standardowym wyjściu.                                                                     ||
// ||       Zasada działania tej funkcji:                                                                                                                                                                             ||
// ||            - Otwiera plik "data.txt" w trybie odczytu.                                                                                                                                                          ||
// ||            - Sprawdza, czy udało się otworzyć plik, jeżeli nie udało się to wyświetla komunikat o błędzie.                                                                                                      ||
// ||            - Iteruje po kolejnych liniach pliku, przeszukując je w poszukiwaniu nazwy podanego dnia tygodnia.                                                                                                   ||
// ||            - Gdy znajdzie linie zawierającą nazwę podanego dnia, zaczyna wypisywać kolejne linie, aż do momentu natrafienia na pustą linię lub linie z nazwami dni tygodnia.                                    ||
// ||            - Wypisuje na standardowym wyjściu (czyli wiadomo, konsoli) znalezione linie, reprezentujące plan lekcji dla danego dnia.                                                                            ||
// ||            - Jeśli nie znaleziono planu dla podanego dnia tygodnia, funkcja wyświetla stosowny komunikat.                                                                                                       ||
// ||                                                                                                                                                                                                                 ||
// ||  - zapisz() -> Jest to funkcja która wielokrotnie się przewija w tym kodzie.                                                                                                                                    ||
// ||       Pozwala na automatyczne zapisywanie danych do pliku, bez potrzeby robienia tego manualnie.                                                                                                                ||
// ||       Zasada działania tej funkcji:                                                                                                                                                                             ||
// ||            - Otwiera plik "data.txt" w trybie zapisu.                                                                                                                                                           ||
// ||            - Sprawdza, czy udało się ten plik otworzyć. Jeśli nie, wypisuje komunikat o błędzie.                                                                                                                ||
// ||            - Przechodzi przez wszystkie przechowywane linie (wszystkie_linie) i zapisuje je do pliku, każdą w osobnej linii (file_out << linia << endl;)                                                        ||
// ||            - Na końcu plik jest zamykany.                                                                                                                                                                       ||
// ||                                                                                                                                                                                                                 ||
// ||  - edytujPlanLekcji() -> Funkcja ta służy do edycji planu lekcji dla danego dnia tygodnia.                                                                                                                      ||
// ||       Funkcja ta polega na:                                                                                                                                                                                     ||
// ||            - Najpierw otwiera plik "data.txt" w trybie odczytu.                                                                                                                                                 ||
// ||            - Wczytuje wszystkie linie z pliku do wektora `wszystkie_linie`.                                                                                                                                     ||
// ||            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia                                                                               ||
// ||            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.                                                                                                                      ||
// ||            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do edycji.                                                                                                                             ||
// ||            - Prosi użytkownika o wybór numeru lekcji do edycji.                                                                                                                                                 ||
// ||            - Po wybraniu lekcji, prosi użytkownika o podanie nowej nazwy przedmiotu.                                                                                                                            ||
// ||            - Aktualizuje wybraną lekcję w wektorze `wszystkie_linie`.                                                                                                                                           ||
// ||            - Zapisuje zmieniony plan lekcji do pliku "data.txt" przez wywołanie funkcji zapisz(),                                                                                                               ||
// ||                która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora `wszystkie_linie` do pliku                                                                                               ||
// ||                                                                                                                                                                                                                 ||
// ||  - usunLekcje() -> Funkcja ta służy do usuwania poszczególnych lekcji wybranych przez użytkownika                                                                                                               ||
// ||       Funkcja ta oparta jest na:                                                                                                                                                                                ||
// ||            - Najpierw otwiera plik "data.txt" w trybie odczytu.                                                                                                                                                 ||
// ||            - Wczytuje wszystkie linie z pliku do wektora wszystkie_linie.                                                                                                                                       ||
// ||            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia                                                                               ||
// ||            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.                                                                                                                      ||
// ||            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do usunięcia.                                                                                                                          ||
// ||            - Prosi użytkownika o wybór numeru lekcji do usunięcia.                                                                                                                                              ||          
// ||            - Po wybraniu lekcji, usuwa nazwę przedmiotu z wybranej lekcji poprzez ustawienie jej na pusty ciąg znaków ("")                                                                                      ||
// ||            - Zapisuje zmieniony plan lekcji do pliku "data.txt" przez wywołanie funkcji zapisz(),                                                                                                               ||
// ||                która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora wszystkie_linie` do pliku.                                                                                               ||
// ||                                                                                                                                                                                                                 ||
// ||  - zapiszLekcje -> Funkcja ta odpowiada za zapisywanie nowych lekcji dla danego dnia tygodnia.                                                                                                                  ||
// ||       Oto działanie funkcji zapiszLekcje():                                                                                                                                                                     ||
// ||            - Najpierw otwiera plik "data.txt" w trybie odczytu                                                                                                                                                  ||
// ||            - Wczytuje wszystkie linie z pliku do wektora `wszystkie_linie`.                                                                                                                                     ||
// ||            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia                                                                               || 
// ||            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.                                                                                                                      ||
// ||            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do zapisania.                                                                                                                          ||
// ||            - Prosi użytkownika o wybór numeru lekcji do zapisania.                                                                                                                                              ||
// ||            - Po wybraniu lekcji, sprawdza czy wybrana lekcja jest pusta (czyli czy nie ma nazwy przedmiotu).                                                                                                    ||
// ||            - Zapisuje nową lekcję do odpowiedniego indeksu w wektorze `wszystkie_linie`.                                                                                                                        ||
// ||            - Zapisuje zmieniony plan lekcji do pliku "data.txt" przez wywołanie funkcji zapisz(),                                                                                                               ||
// ||                która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora wszystkie_linie do pliku.                                                                                                ||
// ||                                                                                                                                                                                                                 ||
// ||                                                                                                                                                                                                                 ||
// ||  - pomoc() -> Funkcja ta wypisuje podstawowe interakcje z programem.                                                                                                                                            ||
// ||                                                                                                                                                                                                                 ||
// ||  - zakoncz() -> Funkcja ta korzysta z biblioteki cstdlib, która posiada funkcję exit(0), która pozwala na bezpieczne zamknięcie programu.                                                                       ||
// ||                                                                                                                                                                                                                 ||
// ||  - main() -> W głównej części programu wywołujemy powyższe funkcje, poprzez wybór użytkownika. Wyświetlają się wszystkie rzeczy, jakie użytkownik może wykonać wraz z numerkami jakie podają, aby przejść dalej ||
// ||                                                                                                                                                                                                                 ||
// ||   Wykorzystane biblioteki:                                                                                                                                                                                      ||
// ||                                                                                                                                                                                                                 ||
// ||   - <iostrean> -> Biblioteka potrzebna do operacji wejścia/wyjścia (input/output)                                                                                                                               ||
// ||                                                                                                                                                                                                                 ||
// ||   - <fstream> -> Biblioteka ta umożliwia operacje na plikach, takie jak odczyt i zapis. Jest wykorzystywana w  odczytajPlanLekcji(), zapisz(), edytujPlanLekcji(), usunLekcje() i zapiszLekcje() ".             ||
// ||                                                                                                                                                                                                                 ||
// ||   - <string> -> Umożliwia manipulację na stringach(łańcuchach znaków). Używana do przechowywania i manipulowania nazwami dni tygodnia oraz nazwami przedmiotów w różnych funkcjach.                             ||
// ||                                                                                                                                                                                                                 ||
// ||   - <cstdlib> -> Ta biblioteka zawiera różne funkcje do zarządzania pamięcią i konwersji typów. W kodzie nie jest używana bezpośrednio, jednakże występuje w wyczyscKonsole().                                  ||
// ||                                                                                                                                                                                                                 ||
// ||   - <locale.h> -> W tym kodzie odpowiada za dodanie polskich znaków do konsoli, czasami nie działa z różnych powodów, lecz jest to porządna biblioteka.                                                         ||
// ||                                                                                                                                                                                                                 ||
// ||   - <vector> -> Biblioteka ta dostarcza wektory, które są używane do przechowywania wszystkich linii z pliku tekstowego w funkcjach zapisz(), edytujPlanLekcji(), usunLekcje() i zapiszLekcje().                ||
// ||                                                                                                                                           -- Program mojego autorstwa, Oskara Szmurło 3P                        ||
//  \\ ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  === ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  === ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  ===  === //

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <locale.h>
using namespace std;

// Gdyż sam w sobie kolor czcionki jest nudny, zamieniam go na cyjanowy
// Tzw makrodefinicja koloru, to akurat znalazłem na necie, gdyż bardzo chciałem zmienić kolor czcionki, lecz nie wiedziałem jak to zrobić.
#define CYAN    "\033[36m"      /* Cyjanowy */
#define RESET   "\033[0m"       /* Reset */

vector<string> wszystkie_linie;

void wyczyscKonsole() { // Pełne wytłumaczenie działania tej funkcji: linijka 6
    cout << "\033[2J\033[1;1H"; 
}

void odczytajPlanLekcji(const string& dzien) { // Pełne wytłumaczenie działania tej funkcji: linijka 14
    setlocale(LC_CTYPE, "Polish");
    ifstream file("data.txt");

    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku.\n";
        return;
    }

    string line;
    bool znaleziono_dzien = false;
    bool end_of_day_reached = false;

    while (getline(file, line) && !end_of_day_reached) {
        if (znaleziono_dzien) {
            if (line.empty()) {
                break;
            }
            cout << line << endl;
        }

        if (line.find(dzien) != string::npos) {
            znaleziono_dzien = true;
            cout << line << endl;
        }
        else if (znaleziono_dzien && (line.find("Poniedzialek") != string::npos ||
            line.find("Wtorek") != string::npos ||
            line.find("Sroda") != string::npos ||
            line.find("Czwartek") != string::npos ||
            line.find("Piatek") != string::npos)) {
            end_of_day_reached = true;
        }
    }

    if (!znaleziono_dzien) {
        cout << "Nie znaleziono planu lekcji dla podanego dnia tygodnia." << endl;
        cout << "Sprawdz, czy poprawnie wpisales/as nazwe dnia tygodnia." << endl;
    }

    file.close();
}

void zapisz() { // Pełne wytłumaczenie działania tej funkcji: linijka 24
    ofstream file_out("data.txt");
    if (!file_out.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu.\n"; 
        return;
    }

    for (const auto& linia : wszystkie_linie) {
        file_out << linia << endl;
    }

    file_out.close();
    cout << "Plan lekcji zapisany pomyslnie.\n";
}


void edytujPlanLekcji(const string& dzien) { // Pełne wytłumaczenie działania tej funkcji: linijka 32
    ifstream file_in("data.txt");
    if (!file_in.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do odczytu.\n";
        return;
    }

    wszystkie_linie.clear();
    string line;
    while (getline(file_in, line)) {
        wszystkie_linie.push_back(line);
    }

    file_in.close();

    int start_line = -1;
    int end_line = -1;
    for (int i = 0; i < wszystkie_linie.size(); ++i) {
        if (wszystkie_linie[i].find(dzien) != string::npos) {
            start_line = i;
        }
        else if (start_line != -1 && (wszystkie_linie[i].empty() || wszystkie_linie[i].find("Poniedzialek") != string::npos ||
            wszystkie_linie[i].find("Wtorek") != string::npos ||
            wszystkie_linie[i].find("Sroda") != string::npos ||
            wszystkie_linie[i].find("Czwartek") != string::npos ||
            wszystkie_linie[i].find("Piatek") != string::npos)) {
            end_line = i;
            break;
        } 
    }

    if (start_line == -1 || end_line == -1) {
        cout << "Nie znaleziono planu dla podanego dnia.\n";
        return;
    }

    cout << "Edytowanie planu lekcji dla dnia: " << dzien << endl;
    for (int i = start_line + 1; i < end_line; ++i) {
        cout << i - start_line << ". " << wszystkie_linie[i] << endl;
    }

    cout << "Wpisz numer lekcji, którą chcesz edytować, lub 0 aby zakończyć: ";
    int numer_lekcji;
    cin >> numer_lekcji;
    cin.ignore();

    while (numer_lekcji != 0) {
        if (numer_lekcji <= 0 || numer_lekcji >= end_line - start_line) {
            cout << "Niepoprawny numer lekcji. Spróbuj ponownie: ";
        }
        else {
            int index = start_line + numer_lekcji;
            string aktualna_lekcja = wszystkie_linie[index];
            size_t pozycja = aktualna_lekcja.find("-");
            if (pozycja != string::npos) {
                pozycja = aktualna_lekcja.find(" ", pozycja);
            }

            if (pozycja != string::npos) {
                string godzina = aktualna_lekcja.substr(0, pozycja + 1);
                cout << "Aktualna lekcja: " << aktualna_lekcja.substr(pozycja + 1) << endl;
                cout << "Wpisz nową nazwę przedmiotu: " << endl;
                cout << "output <<  ";
                getline(cin, line);
                wszystkie_linie[index] = godzina + line;
            }
            else {
                cout << "Nie znaleziono godziny lekcyjnej. Spróbuj ponownie." << endl;
            }

            cout << "Lekcja zaktualizowana. Wpisz kolejny numer lekcji lub 0 aby zakończyć: ";
        }
        cin >> numer_lekcji;
        cin.ignore();
    }

    zapisz();
}

void usunLekcje(const string& dzien) { // Pełne wytłumaczenie działania tej funkcji: linijka 45
    ifstream file_in("data.txt");
    if (!file_in.is_open()) {
        cerr << "Nie udało się otworzyć pliku do odczytu.\n";
        return;
    }

    wszystkie_linie.clear();
    string line;
    while (getline(file_in, line)) {
        wszystkie_linie.push_back(line);
    }
    file_in.close();

    int start_line = -1;
    int end_line = -1;
    for (int i = 0; i < wszystkie_linie.size(); ++i) {
        if (wszystkie_linie[i].find(dzien) != string::npos) {
            start_line = i;
        }
        else if (start_line != -1 && (wszystkie_linie[i].empty() ||
            wszystkie_linie[i].find("Poniedzialek") != string::npos ||
            wszystkie_linie[i].find("Wtorek") != string::npos ||
            wszystkie_linie[i].find("Sroda") != string::npos ||
            wszystkie_linie[i].find("Czwartek") != string::npos ||
            wszystkie_linie[i].find("Piatek") != string::npos)) {
            end_line = i;
            break;
        }
    }

    if (start_line == -1 || end_line == -1) {
        cout << "Nie znaleziono planu dla podanego dnia.\n"; 
        return;
    }

    cout << "Usuwanie lekcji dla dnia: " << dzien << endl;
    for (int i = start_line + 1; i < end_line; ++i) {
        cout << i - start_line << ". " << wszystkie_linie[i] << endl;
    }

    cout << "Wpisz numer lekcji, którą chcesz usunąć, lub 0 aby zakończyć: ";
    int numer_lekcji;
    cin >> numer_lekcji;
    cin.ignore();

    while (numer_lekcji != 0) {
        if (numer_lekcji <= 0 || numer_lekcji >= end_line - start_line) {
            cout << "Niepoprawny numer lekcji. Spróbuj ponownie: ";
        }
        else {
            int index = start_line + numer_lekcji;
            size_t first_space_pos = wszystkie_linie[index].find_first_of(" ");
            if (first_space_pos != string::npos) {
                wszystkie_linie[index] = wszystkie_linie[index].substr(0, first_space_pos);
                cout << "Lekcja usunięta. Wpisz kolejny numer lekcji do usunięcia lub 0 aby zakończyć: ";
            }
            else {
                cout << "Nie można usunąć nazwy lekcji. Nie znaleziono odstępu.\n";
            }
        }
        cin >> numer_lekcji;
        cin.ignore();
    }

    zapisz();
}

 
void zapiszLekcje(const string& dzien) { // Pełne wytłumaczenie działania tej funkcji: linijka 57
    ifstream file_in("data.txt");
    if (!file_in.is_open()) {
        cerr << "Nie udało się otworzyć pliku do odczytu.\n";
        return;
    }

    wszystkie_linie.clear();
    string line;
    while (getline(file_in, line)) {
        wszystkie_linie.push_back(line);
    }
    file_in.close();

    int start_line = -1;
    int end_line = -1;
    for (int i = 0; i < wszystkie_linie.size(); ++i) {
        if (wszystkie_linie[i].find(dzien) != string::npos) {
            start_line = i;
        }
        else if (start_line != -1 && (wszystkie_linie[i].empty() ||
            wszystkie_linie[i].find("Poniedzialek") != string::npos ||
            wszystkie_linie[i].find("Wtorek") != string::npos ||
            wszystkie_linie[i].find("Sroda") != string::npos ||
            wszystkie_linie[i].find("Czwartek") != string::npos ||
            wszystkie_linie[i].find("Piatek") != string::npos)) {
            end_line = i;
            break;
        }
    }

    if (start_line == -1 || end_line == -1) {
        cout << "Nie znaleziono planu dla podanego dnia.\n";
        return;
    }

    cout << "Zapisywanie lekcji dla dnia: " << dzien << endl;
    for (int i = start_line + 1; i < end_line; ++i) {
        cout << i - start_line << ". " << wszystkie_linie[i] << endl;
    }

    cout << "Wpisz numer lekcji, którą chcesz zapisac, lub 0 aby zakończyć: ";
    int numer_lekcji;
    cin >> numer_lekcji;
    cin.ignore();

    while (numer_lekcji != 0) {
        if (numer_lekcji <= 0 || numer_lekcji >= end_line - start_line) {
            cout << "Niepoprawny numer lekcji. Spróbuj ponownie: ";
        }
        else {
            int index = start_line + numer_lekcji;

            if (wszystkie_linie[index].find(" ") == string::npos) {
                cout << "Wpisz nazwę przedmiotu do zapisania " << endl;
                cout << "output <<  ";
                getline(cin, line);
                wszystkie_linie[index] += " " + line;
                cout << "Lekcja zapisana. Wpisz kolejny numer lekcji do zapisania lub 0 aby zakończyć: ";
            }
            else {
                cout << "Nie można zapisywać zajętej lekcji. Wybierz inną lekcję do zapisania lub 0 aby zakończyć: ";
            }
        }
        cin >> numer_lekcji;
        cin.ignore();
    }

    zapisz();
}




void pomoc() { // Pełne wytłumaczenie działania tej funkcji: linijka 71
    cout << "  // === === === === === === === === === === ===   === === === === === === === === === === \\\\" << endl;
    cout << " ||                                                                                         ||" << endl;
    cout << " ||   Plan lekcji opiera się na wielu funkcjach, takich jak:                                ||" << endl;
    cout << " ||      - odczytywanie planu,                                                              ||" << endl;
    cout << " ||      - edytowanie lekcji,                                                               ||" << endl;
    cout << " ||      - usuwanie lekcji,                                                                 ||" << endl;
    cout << " ||      - zapisywanie lekcji,                                                              ||" << endl;
    cout << " ||      - pomocy z planem,                                                                 ||" << endl;
    cout << " ||      - zakończenia programu.                                                            ||" << endl;
    cout << " || 1. Aby dokonać odczytu planu, w odpowiedzi użytkownika należy wpisać 1                  ||" << endl;
    cout << " || 2. Aby dokonać edycji planu, w odpowiedzi użytkownika należy wpisać 2                   ||" << endl;
    cout << " || 3. Aby dokonać usuniecia lekcji, w odpowiedzi użytkownika należy wpisać 3               ||" << endl;
    cout << " || 4. Aby dokonać zapisu planu, w odpowiedzi użytkownika należy wpisać 4                   ||" << endl;
    cout << " || 5. Aby wyszukac pomocy z programem, w odpowiedzi użytkownika należy wpisać 5            ||" << endl;
    cout << " || 6. Aby dokonać zakończenia działania programu, w odpowiedzi użytkownika należy wpisać 6 ||" << endl;
    cout << " ||                                                                                         ||" << endl;
    cout << "  \\\\ === === === === === === === === === === ===   === === === === === === === === === === // \n" << endl;
}

void zakoncz() { // Pełne wytłumaczenie działania tej funkcji: linijka 73
    cout << "Dziękujemy za korzystanie z naszego programu!";
    exit(0);
}

int main() { // Pełne wytłumaczenie działania tej funkcji: linijka 75
    cout << CYAN;
    setlocale(LC_CTYPE, "Polish");
    int wybor;
    string dzien;

    do {
        cout << "  // === === === === === ===  === === === === === === \\\\ " << endl;
        cout << " ||                                                    ||" << endl;
        cout << " || Co chcesz zrobić w naszym programie?               ||" << endl;
        cout << " ||           1. Odczytaj Plan                         ||" << endl;
        cout << " ||           2. Edytuj lekcje                         ||" << endl;
        cout << " ||           3. Usun lekcje                           ||" << endl;
        cout << " ||           4. Zapisz lekcje                         ||" << endl;
        cout << " ||           5. Pomoc                                 ||" << endl;
        cout << " ||           6. Zakończ działanie programu            ||" << endl;
        cout << " ||                                                    ||" << endl;
        cout << "  \\\\ === === === === === ===  === === === === === === // \n" << endl;
        cout << "output << ";
        cin >> wybor;
        cin.ignore();
        wyczyscKonsole();

        switch (wybor) {
        case 1:
            cout << "Podaj dzien tygodnia(Poniedzialek, Wtorek, Sroda, Czwartek, Piatek), dla ktorego chcesz wyswietlic plan lekcji " << endl;
            cout << "output <<  ";
            getline(cin, dzien);
            odczytajPlanLekcji(dzien);
            break;
        case 2:
            cout << "Podaj dzien tygodnia(Poniedzialek, Wtorek, Sroda, Czwartek, Piatek), dla ktorego chcesz edytowac plan lekcji " << endl;
            cout << "output << ";
            getline(cin, dzien);
            edytujPlanLekcji(dzien);
            break;
        case 3:
            cout << "Podaj dzien tygodnia(Poniedzialek, Wtorek, Sroda, Czwartek, Piatek), dla ktorego chcesz usunac lekcje " << endl;
            cout << "output << ";
            getline(cin, dzien);
            usunLekcje(dzien);
            break;
        case 4:
            cout << "Podaj dzien tygodnia(Poniedzialek, Wtorek, Sroda, Czwartek, Piatek), dla ktorego chcesz zapisac lekcje " << endl;
            cout << "output << ";
            getline(cin, dzien);
            zapiszLekcje(dzien);
            break;
        case 5:
            pomoc();
            break;
        case 6:
            zakoncz();
            break;
        default:
            cout << "Niepoprawny wybor funkcji.\n";
            break;
        }

        cout << "Czy chcesz kontynuować korzystanie z programu? (T/N): " << endl;
        cout << "output << ";
        char kontynuacja;
        cin >> kontynuacja;
        cin.ignore();
        if (kontynuacja != 'T' && kontynuacja != 't') {
            break;
        }
        wyczyscKonsole();
    } while (true);

    return 0;
}
