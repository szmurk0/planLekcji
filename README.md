Witam w Projekcie Planu Lekcji!!!

Program ten posiada 8 funkcji, z czego można wyróżnić:

- wyczyscKonsole() -> Głównym celem tej funkcji jest "czyszczenie" konsoli, przez co wszystko wygląda bardziej czysto w efekcie ładniej.
       Funkcja ta posiada jedną linijkę kodu, lecz dwie funkcje w niej:
            - \033[2J powoduje wyczyszczenie ekranu, gdzie
            - \033[1;1H ustawia kursor na początek pierwszej linijki kolejnego wiersza

       Ciąg ten znaków nazywamy sekwencją ucieczki ANSI, sekwencje te są używane do sterowania konsolą terminala.
       Znalazłem tą funkcję patrząc na "Przydatne funkcje w C++", bardzo mi się spodobała również pomyślałem że tutaj będzie się dobrze sprawować, awięc jest.

- odczytajPlanLekcji() -> Funkcja ta wypisuje wszystkie lekcje z danego dnia (wybranego przez użytkownika).
       Jest odpowiedzialna za odczytanie planu lekcji z pliku "plan_lekcji.txt" dla danego dnia tygodnia i wyświetlenie go na standardowym wyjściu.
       Zasada działania tej funkcji:
            - Otwiera plik "plan_lekcji.txt" w trybie odczytu.
            - Sprawdza, czy udało się otworzyć plik, jeżeli nie udało się to wyświetla komunikat o błędzie.
            - Iteruje po kolejnych liniach pliku, przeszukując je w poszukiwaniu nazwy podanego dnia tygodnia.
            - Gdy znajdzie linie zawierającą nazwę podanego dnia, zaczyna wypisywać kolejne linie, aż do momentu natrafienia na pustą linię lub linie z nazwami dni tygodnia.
            - Wypisuje na standardowym wyjściu (czyli wiadomo, konsoli) znalezione linie, reprezentujące plan lekcji dla danego dnia.
            - Jeśli nie znaleziono planu dla podanego dnia tygodnia, funkcja wyświetla stosowny komunikat.

- zapisz() -> Jest to funkcja która wielokrotnie się przewija w tym kodzie.
       Pozwala na automatyczne zapisywanie danych do pliku, bez potrzeby robienia tego manualnie.
       Zasada działania tej funkcji:
            - Otwiera plik "plan_lekcji.txt" w trybie zapisu.
            - Sprawdza, czy udało się ten plik otworzyć. Jeśli nie, wypisuje komunikat o błędzie.
            - Przechodzi przez wszystkie przechowywane linie (wszystkie_linie) i zapisuje je do pliku, każdą w osobnej linii (file_out << linia << endl;)
            - Na końcu plik jest zamykany.

- edytujPlanLekcji() -> Funkcja ta służy do edycji planu lekcji dla danego dnia tygodnia.
       Funkcja ta polega na:
            - Najpierw otwiera plik "plan_lekcji.txt" w trybie odczytu.
            - Wczytuje wszystkie linie z pliku do wektora `wszystkie_linie`.
            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia
            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.
            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do edycji.
            - Prosi użytkownika o wybór numeru lekcji do edycji.
            - Po wybraniu lekcji, prosi użytkownika o podanie nowej nazwy przedmiotu.
            - Aktualizuje wybraną lekcję w wektorze `wszystkie_linie`.
            - Zapisuje zmieniony plan lekcji do pliku "plan_lekcji.txt" przez wywołanie funkcji zapisz(), która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora `wszystkie_linie` do pliku

- usunLekcje() -> Funkcja ta służy do usuwania poszczególnych lekcji wybranych przez użytkownika
       Funkcja ta oparta jest na:
            - Najpierw otwiera plik "plan_lekcji.txt" w trybie odczytu.
            - Wczytuje wszystkie linie z pliku do wektora wszystkie_linie.
            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia
            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.
            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do usunięcia.
            - Prosi użytkownika o wybór numeru lekcji do usunięcia.
            - Po wybraniu lekcji, usuwa nazwę przedmiotu z wybranej lekcji poprzez ustawienie jej na pusty ciąg znaków ("")
            - Zapisuje zmieniony plan lekcji do pliku "plan_lekcji.txt" przez wywołanie funkcji zapisz(), która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora wszystkie_linie` do pliku.

- zapiszLekcje -> Funkcja ta odpowiada za zapisywanie nowych lekcji dla danego dnia tygodnia.
       Oto działanie funkcji zapiszLekcje():
            - Najpierw otwiera plik "plan_lekcji.txt" w trybie odczytu
            - Wczytuje wszystkie linie z pliku do wektora `wszystkie_linie`.
            - Następnie wyszukuje w wektorze indeks początku i końca planu lekcji dla danego dnia tygodnia na podstawie nazwy dnia
            - Jeśli nie znaleziono planu dla podanego dnia, wyświetla odpowiedni komunikat.
            - Jeśli plan lekcji został znaleziony, wyświetla listę lekcji do zapisania.
            - Prosi użytkownika o wybór numeru lekcji do zapisania.
            - Po wybraniu lekcji, sprawdza czy wybrana lekcja jest pusta (czyli czy nie ma nazwy przedmiotu).
            - Zapisuje nową lekcję do odpowiedniego indeksu w wektorze `wszystkie_linie`.
            - Zapisuje zmieniony plan lekcji do pliku "plan_lekcji.txt" przez wywołanie funkcji zapisz(), która otwiera plik w trybie zapisu i zapisuje wszystkie linie z wektora wszystkie_linie do pliku.


- pomoc() -> Funkcja ta wypisuje podstawowe interakcje z programem.

- zakoncz() -> Funkcja ta korzysta z biblioteki cstdlib, która posiada funkcję exit(0), która pozwala na bezpieczne zamknięcie programu.

- main() -> W głównej części programu wywołujemy powyższe funkcje, poprzez wybór użytkownika. Wyświetlają się wszystkie rzeczy, jakie użytkownik może wykonać wraz z numerkami jakie podają, aby przejść dalej

   Wykorzystane biblioteki:

   - <iostream> -> Biblioteka potrzebna do operacji wejścia/wyjścia (input/output) 

   - <fstream> -> Biblioteka ta umożliwia operacje na plikach, takie jak odczyt i zapis. Jest wykorzystywana w  odczytajPlanLekcji(), zapisz(), edytujPlanLekcji(), usunLekcje() i zapiszLekcje() ".

   - <string> -> Umożliwia manipulację na stringach(łańcuchach znaków). Używana do przechowywania i manipulowania nazwami dni tygodnia oraz nazwami przedmiotów w różnych funkcjach.

   - <cstdlib> -> Ta biblioteka zawiera różne funkcje do zarządzania pamięcią i konwersji typów. W kodzie nie jest używana bezpośrednio, jednakże występuje w wyczyscKonsole().

   - <locale.h> -> W tym kodzie odpowiada za dodanie polskich znaków do konsoli, czasami nie działa z różnych powodów, lecz jest to porządna biblioteka.

   - <vector> -> Biblioteka ta dostarcza wektory, które są używane do przechowywania wszystkich linii z pliku tekstowego w funkcjach zapisz(), edytujPlanLekcji(), usunLekcje() i zapiszLekcje().

