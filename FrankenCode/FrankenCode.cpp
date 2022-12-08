 // Jakie gry zostały ukończone: dodawanie gier, wyświetlanie ukonczonych gier, gry do przejścia 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>

using namespace std;

char m;
string game_name, add_game_to_play_name, game_finished, percent_done;
int gf;

int main()
{ 
    fstream gamesfinished;
    gamesfinished.open("gamesfinished.ini", ios::in);
    if (gamesfinished.good() == false)
    {
        gamesfinished.open("gamesfinished.ini", ios::out);
        {
            gamesfinished << "[FINISHED GAMES]" << endl;
        }
        gamesfinished.close();
    }
    fstream gamestoplay;
    gamestoplay.open("gamestoplay.ini", ios::in);
    if (gamestoplay.good() == false)
    {
        gamestoplay.open("gamestoplay.ini", ios::out);
        {
            gamestoplay << "[GAMES TO PLAY]" << endl;
        }
        gamestoplay.close();
    }
    for (;;)
    {
        system("cls");
        cout << "Games to Go\n"
                "1. Games finished\n"
                "2. Add finished game\n"
                "3. Games to play\n"
                "4. Add game to play\n"
                "5. Update game status\n"
                "6. About\n"
                "7. Exit\n";
        m = _getch();

        switch (m)
        {
        case '1':
        {
            system("cls");
         //   fstream gamesfinished;
         //   gamesfinished.open("gamesfinished.ini", ios::in)
            cout << "There is no finished games. Let's play some or add your results!\n";
            _getch();
        }break;
        case '2':
        {
            system("cls");
            cout << "ADD FINISHED GAME:";
            cout << "Game name:\n";
            cin >> game_name;
            cout << "Did you finished playing this game?\n";
            cout << "1. Yes\n2. No\n";
            cin >> game_finished;

            if (game_finished == "1")
            {
                gf == 1;
            }
            else if (game_finished == "2")
            {
                gf == 0;
            }
            else
            {
                cout << "Unknown command or symbol";
            }
            cout << "On how many percent have you done " + game_name + " ?\n";
            cin >> percent_done;
            
            fstream gamesfinished;
            gamesfinished.open("gamesfinished.ini", ios::out | ios::app);

            gamesfinished << "%" + game_name + "%";
            gamesfinished << " ";
            if (gf == 1)
            {
                gamesfinished << gf + "True";
            }
            else
            {
                gamesfinished << gf + "False";
            }
            gamesfinished << " ";
            gamesfinished << percent_done + "%" << endl;

            gamesfinished.close();
        }break;
        case '3':
        {
            system("cls");
            cout << "There is no games to play\n";
            _getch();
        }break;
        case '4':
        {
            system("cls");
            cout << "What game do you want to play?\n";
            cin >> add_game_to_play_name;
        }break;
        case '5':
        {
            system("cls");
            cout << "Update game status\n";
        }break;
        case '6':
        {
            system("cls");
            cout << "About:\n";
            _getch();
        }break;
        case '7':
        {
            exit(0);
        }
        default:
        {
            system("cls");
            cout << "There is no such option\n";
            _getch();
        }
        }
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
