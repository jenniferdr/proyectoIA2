// Game of Othello -- Example of main
// Universidad Simon Bolivar, 2012.
// Author: Blai Bonet
// Last Revision: 10/23/12
// Modified by: 

//#include "othello_cut.h" // won't work correctly until .h is fixed!
#include <iostream>
#include <climits>
#include "algoritmos.hh"

using namespace std;

int main(int argc, const char **argv) {
    state_t state;

    state_t pv_states[32];

    //alphabeta_othello(state, INT_MIN, INT_MAX, true);

    cout << "Principal variation:" << endl;
    for( int i = 0; PV[i] != -1; ++i ) {
        bool player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        //cout << state;
	pv_states[i] = state;
	/*        cout << (player ? "Black" : "White")
             << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
             << endl;*/
        state = state.move(player, pos);
	//        cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
    }
    cout << state;
    cout << "Value of the game = " << state.value() << endl;
    cout << "#bits per state = " << sizeof(state) * 8 << endl;

    for ( int i = 32; i >= 0; --i) {
      if (i % 2 != 0) continue;
      cout << "i: " << i << endl;
      cout << "pv: " << PV[i] << endl;
      cout << pv_states[i];
      cout << "minmax val: " << alphabeta_othello(pv_states[i], INT_MIN, INT_MAX, true) << endl;
    }

    if( argc > 1 ) {
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
    }

    return 0;
}
