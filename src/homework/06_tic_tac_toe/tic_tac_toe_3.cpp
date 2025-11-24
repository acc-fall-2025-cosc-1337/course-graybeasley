#include "tic_tac_toe_3.h"

TicTacToe3::TicTacToe3() : TicTacToe(3)
{
}

bool TicTacToe3::check_column_win()
{
    for (int col = 0; col < 3; col++)
    {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 3] &&
            pegs[col + 3] == pegs[col + 6])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe3::check_row_win()
{
    for (int row = 0; row < 9; row += 3)
    {
        if (pegs[row] != " " &&
            pegs[row] == pegs[row + 1] &&
            pegs[row + 1] == pegs[row + 2])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe3::check_diagonal_win()
{
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8])
        return true;

    if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6])
        return true;

    return false;
}