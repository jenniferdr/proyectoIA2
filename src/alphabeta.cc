#include "othello_cut.h"

using namespace std;

extern int expanded_nodes;

int alphabeta(state_t node, int alpha, int beta, bool color) {

  expanded_nodes++;

  if (node.terminal()) {
    return node.value();
  }

  bool pass = true;

  if (color) {

    for( int pos = 0; pos < DIM; ++pos ) {
      if (node.is_black_move(pos)) {
	pass = false;
	alpha = MAX(alpha, alphabeta(node.move(color, pos),
				     alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }

    if (pass) {
      alpha = MAX(alpha, alphabeta(node, alpha, beta, !color));
    }
    return alpha;

  } else {

    for( int pos = 0; pos < DIM; ++pos ) {
      if( (node.is_white_move(pos)) ) {
	pass = false;
	beta = MIN(beta, alphabeta(node.move(color, pos),
				   alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }

    if (pass) {
      beta = MIN(beta, alphabeta(node, alpha, beta, !color));
    }
    return beta;
  }
}
