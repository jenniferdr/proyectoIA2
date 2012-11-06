#include "othello_cut.h"

extern long long int expanded_nodes;

int negascout2(state_t node,int alpha,int beta,bool color){

  if(node.terminal()){
    return (color?1:-1)*node.value();
  }

  int b= beta;
  bool firstChild=true;
  bool pass=true;

  if(color){
    for(int pos=0; pos<DIM ;++pos){
      if(!node.is_black_move(pos)) continue;
      int score= -negascout2(node.move(color,pos),-b,-alpha,!color);

      if(alpha<score && score<beta && !(firstChild))
	score= -negascout2(node.move(color,pos),-beta,-alpha,!color);
      
      alpha= (alpha>=score?alpha:score);

      if(alpha>=beta)
	return alpha;

      beta= alpha+1; // Ventana nula
      pass=false;
      firstChild=false;
    }
    
  }else{
    for(int pos=0; pos<DIM ;++pos){
      if(!node.is_white_move(pos)) continue;
      int score= -negascout2(node.move(color,pos),-b,-alpha,!color);

      if(alpha<score && score<beta && !(firstChild))
	score= -negascout2(node.move(color,pos),-beta,-alpha,!color);
      
      alpha=(alpha>=score?alpha:score);

      if(alpha>=beta)
	return alpha;

      beta= alpha+1; // Ventana nula
      pass=false;
      firstChild=false;
    }
    
  }

  if(pass){
      int score= -negascout2(node,-b,-alpha,!color);

      if(alpha<score && score<beta && !(firstChild))
	score= -negascout2(node,-beta,-alpha,!color);
      
      alpha=  (alpha>=score?alpha:score);

      if(alpha>=beta)
	return alpha;

      beta= alpha+1; // Ventana nula
      pass=false;
      firstChild=false;
  }
  return alpha;
}
