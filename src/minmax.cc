#include "algoritmos.hh"
#include <climits>

int minmax_othello(state_t node, bool color) {

  if (node.terminal()) return node.value();

  int alpha = INT_MAX;

  for( int pos = 0; pos < DIM; ++pos ) {
    //if( (color && node.is_black_move(pos))
	//|| (!color && node.is_white_move(pos)) ) {
      alpha = MAX(INT_MAX, -minmax_othello(node.move(color, pos), color));
    //}
  }

  return alpha;
}
