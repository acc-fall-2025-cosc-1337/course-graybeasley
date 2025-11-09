#include <string>
#include <vector>
#include <iostream>
using std::string; 
using std::vector; 
using std::cout; 

class TicTacToe
{
public:
    void start_game(string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    string get_player() const;
    string get_winner() const; 

private:
    string player;
    string winner; 
    vector<string> pegs = vector<string>(9, " ");

    void clear_board();
    void set_next_player();
    bool check_board_full();
    bool check_column_win();   
    bool check_row_win();      
    bool check_diagonal_win(); 
    void set_winner();         
};