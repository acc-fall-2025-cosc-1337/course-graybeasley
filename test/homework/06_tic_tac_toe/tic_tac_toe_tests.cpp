#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>


TEST_CASE("Test first player set to X") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    REQUIRE(board->get_winner() == "");
}

TEST_CASE("Test first player set to O") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("O");
    REQUIRE(board->get_winner() == "");
}

TEST_CASE("Test TicTacToe3 tie game") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    std::vector<int> moves = {1,2,3,4,5,7,6,9,8};
    for (int pos : moves)
        board->mark_board(pos);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C");
}

TEST_CASE("Test TicTacToe3 win by first column") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(4);
    board->mark_board(5);
    board->mark_board(7);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}


TEST_CASE("Test TicTacToe4 tie game 4") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    // fill 4x4 board with no winner
    std::vector<int> moves = {1,2,3,4,5,6,7,8,9,10,11,12,13,15,14,16};
    for (int pos : moves)
        board->mark_board(pos);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C");
}

TEST_CASE("Test TicTacToe4 win by first column 4") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(6);
    board->mark_board(9);
    board->mark_board(10);
    board->mark_board(13);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test TicTacToe4 win by first row 4") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe4>();
    board->start_game("O");

    board->mark_board(1);
    board->mark_board(5);
    board->mark_board(2);
    board->mark_board(6);
    board->mark_board(3);
    board->mark_board(7);
    board->mark_board(4);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "O");
}

TEST_CASE("Test TicTacToe4 win by diagonal 4") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe4>();
    board->start_game("X");

    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(6);
    board->mark_board(3);
    board->mark_board(11);
    board->mark_board(4);
    board->mark_board(16);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}



TEST_CASE("Test TicTacToeManager winner totals") {
    TicTacToeManager manager;

    auto g1 = std::make_unique<TicTacToe3>();
    g1->start_game("X");
    g1->mark_board(1);
    g1->mark_board(2);
    g1->mark_board(4);
    g1->mark_board(5);
    g1->mark_board(7);
    REQUIRE(g1->game_over());
    manager.save_game(std::move(g1));

    auto g2 = std::make_unique<TicTacToe4>();
    g2->start_game("O");
    g2->mark_board(1);
    g2->mark_board(2);
    g2->mark_board(3);
    g2->mark_board(5);
    g2->mark_board(4);
    g2->mark_board(8);
    REQUIRE(g2->game_over());
    manager.save_game(std::move(g2));

    auto g3 = std::make_unique<TicTacToe3>();
    g3->start_game("X");
    std::vector<int> tie_moves = {1,2,3,4,5,7,6,9,8};
    for (int pos : tie_moves)
        g3->mark_board(pos);
    REQUIRE(g3->game_over());
    manager.save_game(std::move(g3));

    int x_total, o_total, t_total;
    manager.get_winner_total(x_total, o_total, t_total);

    REQUIRE(x_total == 1);
    REQUIRE(o_total == 1);
    REQUIRE(t_total == 1);
}