#include "othello_cut.h"
#include <climits>

using namespace std;

extern long long int expanded_nodes;

int alphabeta(state_t node, int alpha, int beta, bool color) {

  expanded_nodes++;

  if (node.terminal()) {
    return node.value();
  }

  bool pass = true;

  if (color) { // color = true representa las negras, el cual es MAX
    for( int pos = 0; pos < DIM or (pos == DIM and pass); ++pos ) {
      if (node.is_black_move(pos)) {
	pass = false;
	int val = alphabeta(node.move(color, pos), alpha, beta, !color);
	alpha = MAX(alpha, val);
	if (beta <= alpha) break;
      }
    }

    return alpha;

  } else {

    for( int pos = 0; pos < DIM or (pos == DIM and pass); ++pos ) {
      if( (node.is_white_move(pos)) ) {
	pass = false;
	int val = alphabeta(node.move(color, pos), alpha, beta, !color);
	beta = MIN(beta, val);
	if (beta <= alpha) break;
      }
    }

    return beta;
  }
}
