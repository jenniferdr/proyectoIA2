#include <climits>
#include <iostream>

#include "othello_cut.h"

extern long long int expanded_nodes;

int minimax(state_t node, bool color) {
  expanded_nodes++;

  if (node.terminal()) return node.value() * (color ? 1 : -1);

  int alpha = INT_MIN;
  bool pass = true;

  for (int pos = 0; pos < DIM; ++pos) {
    if (!(( color && node.is_black_move(pos))
	  or ( !color && node.is_white_move(pos)))) continue;
    pass = false;
    alpha = MAX(alpha, -minimax(node.move(color, pos), !color));
  }

  if (pass) {
    alpha = MAX(alpha, -minimax(node, !color));
  }

  return alpha;
}
