#include "algoritmos.hh"
#include <iostream>

#include <tr1/unordered_map>

using namespace std;

struct stored_info_t {
  // [information to be stored in hash table]
  int minimax;
  int high;
  int low;
  stored_info_t() { } // need at least one ctor without arguments
};

struct hash_function_t : public tr1::hash<state_t> {
  size_t operator()(const state_t &state) const {
    return state.hash();
  }
};

class hash_table_t : public tr1::unordered_map<state_t, stored_info_t, hash_function_t> {
};

int expanded_nodes = 0;

hash_table_t states;

int alphabeta_othello(state_t node, int alpha, int beta, bool color) {

  expanded_nodes++;

  if (node.terminal()) {
    return node.value();
  }

  bool pass = true;

  if (color) { // color = true representa las negras, el cual es MAX
    for( int pos = 0; pos < DIM; ++pos ) {
      if (node.is_black_move(pos)) {
	pass = false;
	alpha = MAX(alpha, alphabeta_othello(node.move(color, pos),
					     alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }

    if (pass) {
      alpha = MAX(alpha, alphabeta_othello(node, alpha, beta, !color));
    }

    return alpha;

  } else {

    for( int pos = 0; pos < DIM; ++pos ) {
      if( (node.is_white_move(pos)) ) {
	pass = false;
	beta = MIN(beta, alphabeta_othello(node.move(color, pos),
					   alpha, beta, !color));
	if (beta <= alpha) break;
      }
    }

    if (pass) {
      beta = MIN(beta, alphabeta_othello(node, alpha, beta, !color));
    }

    return beta;

  }
}
