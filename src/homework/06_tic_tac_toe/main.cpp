#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main()
{
    TicTacToeManager manager;
    string first_player;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        TicTacToe game;
        do
        {
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        } while (first_player != "X" && first_player != "O");

        game.start_game(first_player);

        int position;
        while (!game.game_over())
        {
            cout << "Enter position (1-9): ";
            cin >> position;
            game.mark_board(position);
            game.display_board();
        }

        manager.save_game(game);
        cout << "Game over! Winner: " << game.get_winner() << "\n";

        cout << "Play again? (y/n): ";
        cin >> choice;
    }

    cout << "Goodbye!\n";
    return 0;
}