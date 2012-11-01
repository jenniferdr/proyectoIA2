#include "algoritmos.hh"
#include <iostream>

using namespace std;

int expanded_nodes = 0;

int alphabeta_othello(state_t node, int alpha, int beta, bool color) {

  expanded_nodes++;
  cout << expanded_nodes << endl;

  if (node.terminal()) {
    //    cout << node << endl;
    return node.value();
  }

  if (color) { // color = true representa las negras, el cual es MAX

    for( int pos = 0; pos < DIM; ++pos ) {
      if (node.is_black_move(pos)) {
	alpha = MAX(alpha, alphabeta_othello(node.move(color, pos),
					     alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }
    return alpha;

  } else {

    for( int pos = 0; pos < DIM; ++pos ) {
      if( (node.is_white_move(pos)) ) {
	beta = MIN(beta, alphabeta_othello(node.move(color, pos),
					   alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }
    return beta;

  }
}
