#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <memory>
#include <vector>

class TicTacToeManager
{
public:
    void save_game(std::unique_ptr<TicTacToe> game);
    void get_winner_total(int& x, int& o, int& t) const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(const std::string& winner);
};

#endif