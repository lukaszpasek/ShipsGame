// ShipsGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Board.h"
#include "Ship.h"

int main()
{
    setlocale(LC_ALL, "pl_PL");
    std::cout << "Witamy w grze statki. Wybierz statki do gry!\n";
    int dzialanie = -1;
    std::vector<std::vector<Ship>> Ships(6);
    while (dzialanie != 0)
    {
        std::cout << "------------------------------------------->\n";
        std::cout << "Wybierz dzialanie:            Gotowych do gry:\n";
        std::cout << "  2->Dodaj 2 masztowiec       "<< Ships[2].size() << ": statków 2 masztowych\n";
        std::cout << "  3->Dodaj 3 masztowiec       "<< Ships[3].size() << ": statków 3 masztowych\n";
        std::cout << "  4->Dodaj 4 masztowiec       "<< Ships[4].size() << ": statków 4 masztowych\n";
        std::cout << "  5->Dodaj 5 masztowiec       "<< Ships[5].size() << ": statków 5 masztowych\n";
        std::cout << "  0->Zacznij gre!\n";
        std::cin >> dzialanie;
        switch (dzialanie) {
        case 2:
            Ships[2].push_back(Ship(2));
            break;
        case 3:
            Ships[3].push_back(Ship(3));
            break;
        case 4:
            Ships[4].push_back(Ship(4));
            break;
        case 5:
            Ships[5].push_back(Ship(5));
            break;
        }
    }

    Board B;
    Board A;
    B.Print();
    /*for (int j = 2; j <= 5; j++)
    {
        for (int i = 0; i < Ships[j].size(); i++)
        {
            while(!B.SetShip(Ships[j][i]));
        }
    }*/
    B.SetShipsAutomatically(Ships);
    A.SetShipsAutomatically(Ships);
    std::cout << "Plansza gracza B:------------------------------------------->\n";
    B.Print();
    std::cout << "Plansza gracza A:------------------------------------------->\n";
    A.Print();

    int czyjaKolej = 1;
    bool isSink = false;
    A.Id = 'A';
    B.Id = 'B';
    while (!isSink)
    {
        if (czyjaKolej>0)
        {
            //B.PrintOpponent();
            while (A.Shot());
        }
        else
        {
            //A.PrintOpponent();
            while (B.Shot());
        }
        czyjaKolej = -czyjaKolej;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
