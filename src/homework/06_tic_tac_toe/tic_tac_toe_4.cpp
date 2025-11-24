#include "tic_tac_toe_4.h"

TicTacToe4::TicTacToe4() : TicTacToe(4)
{
}

// ----- COLUMN WIN -----
bool TicTacToe4::check_column_win()
{
    for (int col = 0; col < 4; col++)
    {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 4] &&
            pegs[col + 4] == pegs[col + 8] &&
            pegs[col + 8] == pegs[col + 12])
        {
            return true;
        }
    }
    return false;
}

// ----- ROW WIN -----
bool TicTacToe4::check_row_win()
{
    for (int row = 0; row < 16; row += 4)
    {
        if (pegs[row] != " " &&
            pegs[row] == pegs[row + 1] &&
            pegs[row + 1] == pegs[row + 2] &&
            pegs[row + 2] == pegs[row + 3])
        {
            return true;
        }
    }
    return false;
}

// ----- DIAGONAL WIN -----
bool TicTacToe4::check_diagonal_win()
{
    if (pegs[0] != " " &&
        pegs[0] == pegs[5] &&
        pegs[5] == pegs[10] &&
        pegs[10] == pegs[15])
        return true;

    if (pegs[3] != " " &&
        pegs[3] == pegs[6] &&
        pegs[6] == pegs[9] &&
        pegs[9] == pegs[12])
        return true;

    return false;
}