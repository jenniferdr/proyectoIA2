#include "algoritmos.hh"
#include <climits>


int F_othello(state_t node, int D) {
	int q;
	
	if (node.terminal() || D == 0) return node.value();
	
	int alpha = -(INT_MAX);
	
	for( int pos = 0; pos < DIM; ++pos ) {
			q = G_othello(node.move(color, pos), D-1);
			alpha = MAX(q,alpha);
		}
		return alpha;
	}

int G_othello(state_t node, int N) {
	int w;
	
	if (node.terminal() || N == 0) return node.value();
	
	int alpha = INT_MAX;
	
	for( int pos = 0; pos < DIM; ++pos ) {
			w = F_othello(node.move(color, pos), N-1)
			alpha = MAX(w,alpha);
		}
		return alpha;
	}
