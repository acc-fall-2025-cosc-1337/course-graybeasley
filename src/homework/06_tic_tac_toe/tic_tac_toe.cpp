#include "tic_tac_toe.h"

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

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C"; // tie
        return true;
    }
    return false;
}

void TicTacToe::display_board() const
{
    for (int i = 0; i < 9; i += 3)
    {
        cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
    }
    cout << "\n";
}

string TicTacToe::get_player() const
{
    return player;
}

string TicTacToe::get_winner() const
{
    return winner;
}


void TicTacToe::set_next_player()
{
    if (player == "X")
        player = "O";
    else
        player = "X";
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

// --- Win checkers ---
bool TicTacToe::check_column_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win()
{
    for (int i = 0; i < 9; i += 3)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
        return true;
    if (pegs[6] != " " && pegs[6] == pegs[4] && pegs[6] == pegs[2])
        return true;
    return false;
}

void TicTacToe::set_winner()
{
    if (player == "X")
        winner = "O";
    else
        winner = "X";
}