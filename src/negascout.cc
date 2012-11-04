#include "algoritmos.hh"

int negascout(state_t node,int alpha,int beta,bool color){

  if(node.terminal()){
    return node.value();
  }

  //int m= INT_MIN; // Cota inferior 
  int b= beta;

  if(color){ // Generar jugadas del turno black

    for(int poss=0; poss <= DIM; ++poss){
      if(!node.is_black_move(poss)) continue;
      int a= -negascout(node.move(color,poss),-b,-alpha,!color);
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node.move(color,poss),-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
    }
    return alpha;

  }else{ // Generar jugadas del turno white

    for(int poss=0; poss <= DIM; ++poss){
      if(!node.is_white_move(poss)) continue;
      int a= -negascout(node.move(color,poss),-b,-alpha,!color);
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node.move(color,poss),-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
    }
    return alpha;

  }

}
