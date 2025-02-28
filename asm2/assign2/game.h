#include <iostream>
using namespace std;

void welcome();
int money_ball_rack();
void switch_mbr(char sets[7][5], int mbrp);
void sim_shots(char ball_sets[7][5], double ppg);
int calculator_rack_score(char shots[7][5],int row);
int calculator_total_score(char shots[7][5]);
void print_order(int i);
int print_out(char ball_sets[7][5]);
int game(double ppg);
void winner(int p1, int p2);
int play_again();