#include "algoritmos.hh"
extern long long int expanded_nodes;

int negascout(state_t node,int alpha,int beta,bool color){

  expanded_nodes++;

  if(node.terminal()){
    return node.value();
  }

  //int m= INT_MIN; // Cota inferior 
  int b= beta;
  bool pass=true;

  if(color){ // Generar jugadas del turno black

    for(int pos=0; pos < DIM; ++pos){
      if(!node.is_black_move(pos)) continue;
      int a= -negascout(node.move(color,pos),-b,-alpha,!color);
      
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node.move(color,pos),-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
      pass=false;
    }
    if(pass){
      int a= -negascout(node,-b,-alpha,!color);
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node,-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
    }
    return alpha;

  }else{ // Generar jugadas del turno white

     for(int pos=0; pos < DIM; ++pos){
      if(!node.is_white_move(pos)) continue;
      int a= -negascout(node.move(color,pos),-b,-alpha,!color);
      
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node.move(color,pos),-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
      pass=false;
    }
    if(pass){
      int a= -negascout(node,-b,-alpha,!color);
      if( a > alpha ) alpha=a;
      if( alpha >= beta ) return alpha;

      if( alpha >= b ){
	// Si fallo la ventana nula hacer nueva busqueda completa
	alpha=-negascout(node,-beta,-alpha,!color);
	if( alpha >= beta ) return alpha;
      }
      b= alpha+1; // Crea la nueva ventana nula
    }
    return alpha;

  }

}
