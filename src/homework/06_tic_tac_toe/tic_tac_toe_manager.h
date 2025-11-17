#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class TicTacToeManager
{
public:
    void save_game(TicTacToe b);
    void get_winner_total(int& x, int& o, int& t);

private:
    vector<TicTacToe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(string winner);
};

#endif