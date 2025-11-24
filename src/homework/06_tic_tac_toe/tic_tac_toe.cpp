#include "tic_tac_toe.h"
#include <iostream>
#include <cmath> 

TicTacToe::TicTacToe(int size) : pegs(size * size, " ")
{
}

void TicTacToe::start_game(std::string first_player)
{
    next_player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = next_player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    next_player = (next_player == "X") ? "O" : "X";
}

bool TicTacToe::game_over()
{
    if (check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_next_player(); // undo last change
        winner = next_player;
        return true;
    }

    if (check_board_full())
    {
        winner = "C";
        return true;
    }

    return false;
}

bool TicTacToe::check_board_full()
{
    for (auto& peg : pegs)
    {
        if (peg == " ")
            return false;
    }
    return true;
}

std::string TicTacToe::get_winner() const
{
    return winner;
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs)
    {
        peg = " ";
    }
}

// ---- These MUST return false since derived classes implement them ----

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::display_board() const
{
    int size = static_cast<int>(std::sqrt(pegs.size()));

    for (int i = 0; i < pegs.size(); i++)
    {
        std::cout << pegs[i];
        if ((i + 1) % size == 0)
            std::cout << "\n";
        else
            std::cout << " | ";
    }
}