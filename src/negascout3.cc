#include "othello_cut.h"
#include <climits>

extern long long int expanded_nodes;

int F(state_t node,int alpha,int beta,bool color);
int G(state_t node,int alpha,int beta,bool color);

int negascout3(state_t node,int alpha,int beta,bool color){
  if(color){
    return F(node,alpha,beta,color);
  }else{
    return G(node,alpha,beta,color);
  }
}

int F(state_t node,int alpha,int beta,bool color){
  expanded_nodes++;
  if(node.terminal()){
    return node.value();
  }

  int m= INT_MIN;
  bool first=true;
  bool pass=true;

  for(int pos=0; pos<DIM; pos++){
     if (!(( color && node.is_black_move(pos))
	  or ( !color && node.is_white_move(pos)))) continue;

     if(first){
       int g= G(node.move(color,pos),alpha,beta,!color);
       m= m>=g?m:g;
       if(m>=beta) return m;
       first=false;
     }
     
     int t= G(node.move(color,pos),m,m+1,!color);
     if(t>m){
       if(t>=beta){ 
	 m=t;
       }else{
	 m=G(node.move(color,pos),t,beta,!color);
       }
     }
     if(m>=beta) return m;
     pass=false;
  }

  if(pass){
    int g= G(node,alpha,beta,!color);
    m= m>=g?m:g;
    if(m>=beta) return m;
     
    int t= G(node,m,m+1,!color);
    if(t>m){
      if(t>=beta){ 
	m=t;
      }else{
	m=G(node,t,beta,!color);
      }
    }
  }
  return m;
}

int G(state_t node,int alpha,int beta,bool color){
  expanded_nodes++;
  if(node.terminal()){
    return node.value();
  }
  
  int m= INT_MAX;
  bool first=true;
  bool pass=true;
  
  for(int pos=0; pos<DIM; pos++){
    if (!(( color && node.is_black_move(pos))
	  or ( !color && node.is_white_move(pos)))) continue;
    
    if(first){
      int f= F(node.move(color,pos),alpha,beta,!color);
      m= m>=f?f:m;
      if(m<=alpha) return m;
      first=false;
    }
    
    int t= F(node.move(color,pos),m,m+1,!color);
    if(t<=m){
      if(t<=alpha){ 
	m=t;
      }else{
	m=F(node.move(color,pos),alpha,t,!color);
      }
    }
    if(m<=alpha) return m;
    pass=false;
  }
  if(pass){
    int f= F(node,alpha,beta,!color);
    m= m>=f?f:m;
    if(m<=alpha) return m;
    
    int t= F(node,m,m+1,!color);
    if(t<=m){
      if(t<=alpha){ 
	m=t;
      }else{
	m=F(node,alpha,t,!color);
      }
    }
  }
  
  return m;
}
