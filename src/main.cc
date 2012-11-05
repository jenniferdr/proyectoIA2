// Game of Othello -- Example of main
// Universidad Simon Bolivar, 2012.
// Author: Blai Bonet
// Last Revision: 10/23/12
// Modified by:

#include <climits>
#include <cstdlib>
#include <iostream>

#include "othello_cut.h"

extern int alphabeta(state_t node, int alpha, int beta, bool color);
extern int negascout(state_t node, int alpha, int beta, bool color);
int minimax(state_t node, bool color) { return 0; }

using namespace std;

long long int expanded_nodes = 0;

int main(int argc, const char **argv) {
    state_t state;

    state_t states_pv[32];

    for( int i = 0; PV[i] != -1; ++i ) {
        bool player = i % 2 == 0; // black moves first!
        int pos = PV[i];
	states_pv[i] = state;
	/*        cout << state;
        cout << (player ? "Black" : "White")
             << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
             << endl;*/
        state = state.move(player, pos);
	//        cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;

    }

    /*cout << state;
    cout << "Value of the game = " << state.value() << endl;
    cout << "#bits per state = " << sizeof(state) * 8 << endl;*/

    int depth = atoi(argv[1]);
    int algoritmo = atoi(argv[2]);
    bool color = depth % 2 == 0;

    cout << "Profundidad: " << depth << endl;
    cout << "Tablero inicial: " << endl;
    cout << states_pv[depth];
    cout << "Jugador: " << (depth%2==0 ? "Negras" : "Blancas") << endl;
    cout << "Algoritmo: ";
    switch (algoritmo) {
    case 1:
      cout << "minimax" << endl;
      cout << "Minmax del nodo: " << minimax(states_pv[depth], color) << endl;
      break;
    case 2:
      cout << "alpha-beta pruning" << endl;
      cout << "Minmax del nodo: "
	   << alphabeta(states_pv[depth], INT_MIN, INT_MAX, color) << endl;
      break;
    case 3:
      cout << "negascout" << endl;
      cout << "Minmax del nodo: "
	   << negascout(states_pv[depth], INT_MIN, INT_MAX, color) << endl;
      break;
    default:
      cout << "Error" << endl;
      return 0;
    }

    /*    if( argc > 1 ) {
        int n = atoi(argv[1]);
        cout << endl << "Apply " << n << " random movements at empty board:";
        state = state_t();
        for( int i = 0; i < n; ++i ) {
            bool player = i % 2 == 0; // black moves first
            int pos = state.get_random_move(player);
            state = state.move(player, pos);
            cout << " " << pos;
        }
        cout << endl << state;
	}*/

    return 0;
}
