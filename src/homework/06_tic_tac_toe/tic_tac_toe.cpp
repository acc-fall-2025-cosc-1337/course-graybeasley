#include "tic_tac_toe.h"

bool TicTacToe::game_over()
{
    return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    for (int i = 0; i < 9; i++)
    {
        cout << pegs[i];
        if ((i + 1) % 3 == 0)
        {
            cout << "\n";
        }
        else
        {
            cout << " | ";
        }
    }
    cout << "\n";
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    for (auto peg : pegs)
    {
        if (peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}