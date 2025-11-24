#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>

class TicTacToe
{
public:
    TicTacToe(int size);

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_winner() const;
    void display_board() const;

protected:
    std::vector<std::string> pegs;
    std::string winner;
    std::string next_player;

    bool check_board_full();
    void set_next_player();

    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    void clear_board();
};

#endif