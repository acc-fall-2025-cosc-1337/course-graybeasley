#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

#include <iostream>
#include <memory>

int main()
{
    TicTacToeManager manager;
    std::string play_again = "Y";

    while (play_again == "Y" || play_again == "y")
    {
        int game_type;
        std::cout << "Play TicTacToe 3 or 4? Enter 3 or 4: ";
        std::cin >> game_type;

        std::unique_ptr<TicTacToe> game;

        if (game_type == 3)
            game = std::make_unique<TicTacToe3>();
        else
            game = std::make_unique<TicTacToe4>();

        std::string first_player;
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;

        game->start_game(first_player);

        int position;
        while (!game->game_over())
        {
            game->display_board();
            std::cout << "\nEnter position: ";
            std::cin >> position;
            game->mark_board(position);
        }

        game->display_board();
        std::cout << "Winner: " << game->get_winner() << "\n";

        manager.save_game(std::move(game));

        std::cout << "Play again? (Y/N): ";
        std::cin >> play_again;
    }

    int x, o, t;
    manager.get_winner_total(x, o, t);
    std::cout << "\nTotals - X: " << x << "  O: " << o << "  Ties: " << t << "\n";

    return 0;
}