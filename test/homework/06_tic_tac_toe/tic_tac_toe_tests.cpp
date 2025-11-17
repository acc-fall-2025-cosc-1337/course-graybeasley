#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test tie game")
{
    TicTacToe game;
    game.start_game("X");
    vector<int> moves = {1,2,3,4,5,7,6,9,8};

    for (int pos : moves)
        game.mark_board(pos);
    
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager get winner total")
{
    TicTacToeManager manager;


    TicTacToe g1;
    g1.start_game("X");
    g1.mark_board(1);
    g1.mark_board(2);
    g1.mark_board(4);
    g1.mark_board(5);
    g1.mark_board(7);
    REQUIRE(g1.game_over());
    manager.save_game(g1);

 
    TicTacToe g2;
    g2.start_game("O");
    g2.mark_board(1);
    g2.mark_board(2);
    g2.mark_board(3);
    g2.mark_board(5);
    g2.mark_board(4);
    g2.mark_board(8);
    REQUIRE(g2.game_over());
    manager.save_game(g2);

   
    TicTacToe g3;
    g3.start_game("X");
    vector<int> tie_moves = {1,2,3,4,5,7,6,9,8};
    for (int pos : tie_moves)
        g3.mark_board(pos);
    REQUIRE(g3.game_over());
    manager.save_game(g3);


    int o_total, x_total, t_total;
    manager.get_winner_total(o_total, x_total, t_total);

    REQUIRE(x_total == 1);
    REQUIRE(o_total == 1);
    REQUIRE(t_total == 1);
}