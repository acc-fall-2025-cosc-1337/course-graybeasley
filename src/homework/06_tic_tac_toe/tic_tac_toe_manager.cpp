#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
        x_win++;
    else if (winner == "O")
        o_win++;
    else
        ties++;
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}