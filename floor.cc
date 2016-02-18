#include "floor.h"
#include "enemy.h"
#include "player.h"
//#include "potion.h"
//#include "treasure.h"
#include "merchant.h"
#include "werewolf.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "phoenix.h"
#include "nami.h"
//#include "dragon.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

floor::floor(){
  numfloor=1;
  grid=new char* [25];
  for (int r=0; r<25; r++){
    grid[r]=new char [79];
    for (int c=0; c<79; c++){
      grid[r][c]=' ';
    }
  }
  earray=new enemy*[20];
  tarray=new treasure*[10];
  parray=new potion*[10];
  lastpoint='.';
  createfloor();
  for(int i=0; i<20; i++){
    setearray(i);
  }
  for(int i=0; i<10; i++){
    settarray(i);
  }
  for(int i=0; i<10; i++){
    setparray(i);
  }
}

void floor::setearray(int i){
  int r;
  int c;
  int n = rand() % 5 + 1;
  int z = rand() % 18 + 1;
  if(n == 1){             
    r = rand() % 6 + 2;
    c = rand() % 28 + 2;
    while(grid[r][c] != '.'){
        r = rand() % 6 + 2;
        c = rand() % 28 + 2;
    }
  }
  if(n == 2){             
    r = rand() % 9 + 14;
    c = rand() % 23 + 3;
    while(grid[r][c] != '.'){
      r = rand() % 9 + 14;
      c = rand() % 23 + 3;
    }
  }
  if(n == 3){            
    r = rand() % 5 + 9;
    c = rand() % 14 + 37;
    while(grid[r][c] != '.'){
      r = rand() % 5 + 9;
      c = rand() % 14 + 37;
    }
  }
  if(n == 4){            
    c = rand() % 41 + 36;
    r = rand() % 8 + 15;
    while(grid[r][c] != '.'){
      c = rand() % 41 + 36;
      r = rand() % 8 + 15;
    }
  }
  if(n == 5){          
    r = rand() % 6 + 2;
    c = rand() % 39 + 38;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 39 + 38;
    }
  }
  if(z <= 3){
    earray[i] = new werewolf(r, c);
    grid[r][c] = 'W';
    earray[i]->setfloor(this);
  }
  else if(z <= 6){
    earray[i] = new vampire(r, c);
    grid[r][c] = 'V';
    earray[i]->setfloor(this);
  }
  else if(z <= 11){
    earray[i] = new goblin(r, c);
    grid[r][c] = 'N';
    earray[i]->setfloor(this);    
  }
  else if(z <= 13){
    earray[i] = new troll(r, c);
    grid[r][c] = 'T';
    earray[i]->setfloor(this);
  }
  else if(z <= 15){
    earray[i] = new phoenix(r, c);
    grid[r][c] = 'X';
    earray[i]->setfloor(this);
  }
  else{
    earray[i] = new merchant(r, c);
    grid[r][c] = 'M';
    earray[i]->setfloor(this);
  }
}

void floor::settarray(int i){
//cout<<"treasure"<<endl;
  int r;
  int c;
  int n = rand() % 5 + 1;
  int z = rand() % 8;
  if(n == 1){             
    r = rand() % 6 + 2;
    c = rand() % 28 + 2;
    while(grid[r][c] != '.'){
        r = rand() % 6 + 2;
        c = rand() % 28 + 2;
    }
  }
  if(n == 2){             
    r = rand() % 9 + 14;
    c = rand() % 23 + 3;
    while(grid[r][c] != '.'){
      r = rand() % 9 + 14;
      c = rand() % 23 + 3;
    }
  }
  if(n == 3){            
    r = rand() % 5 + 9;
    c = rand() % 14 + 37;
    while(grid[r][c] != '.'){
      r = rand() % 5 + 9;
      c = rand() % 14 + 37;
    }
  }
  if(n == 4){            
    c = rand() % 41 + 36;
    r = rand() % 8 + 15;
    while(grid[r][c] != '.'){
      c = rand() % 41 + 36;
      r = rand() % 8 + 15;
    }
  }
  if(n == 5){          
    r = rand() % 6 + 2;
    c = rand() % 39 + 38;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 39 + 38;
    }
  }
  if (z <= 4){
    tarray[i] = new treasure(r, c, 1);
    grid[r][c] = 'G';
  }
  else if(z <= 6){
    tarray[i] = new treasure(r, c, 2);
    grid[r][c] = 'G';
    //setdragon(x, y);
  }
  else if(z <= 7){
    tarray[i] = new treasure(r, c, 3);
    grid[r][c] = 'G';
    int dx = 0;
    int dy = 0;
    while(grid[dx][dy]!='.'){
      int random = rand() % 8;
      if(random == 5){ 
        dx = r + 1;
        dy = c;
      }
      else if(random == 1){
        dx = r - 1;
        dy = c;
      }
      else if(random == 3){
        dy = c + 1;
        dx = r;
      }
      else if(random == 7){
        dy = c - 1; 
        dx = r;
      }
      else if(random == 2) {
        dy = c + 1;
        dx = r - 1;  
      }
      else if(random == 0){
        dx = r - 1;
        dy = c - 1;
      }
      else if(random == 4){
        dx = r + 1;
        dy = c + 1;
      }
      else if(random == 6){
        dy = c - 1;
        dx = r + 1;
      }
    }
    enemy* newdragon = new dragon(dx, dy);
    tarray[i]->pick = 0;
    tarray[i]->mydragon = newdragon;
    grid[dx][dy] = 'D';
  }
}

void floor::setparray(int i){
//cout<<"potion"<<endl;
  int r;
  int c;
  int n = rand() % 5 + 1;
  int z = rand() % 6;
  if(n == 1){             
    r = rand() % 6 + 2;
    c = rand() % 28 + 2;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 28 + 2;
    }
  }
  if(n == 2){             
    r = rand() % 9 + 14;
    c = rand() % 23 + 3;
    while(grid[r][c] != '.'){
      r = rand() % 9 + 14;
      c = rand() % 23 + 3;
    }
  }
  if(n == 3){            
    r = rand() % 5 + 9;
    c = rand() % 14 + 37;
    while(grid[r][c] != '.'){
      r = rand() % 5 + 9;
      c = rand() % 14 + 37;
    }
  }
  if(n == 4){            
    r = rand() % 8 + 15;
    c = rand() % 41 + 36;    
    while(grid[r][c] != '.'){
      c = rand() % 40 + 36;
      r = rand() % 8 + 15;
    }
  }
  if(n == 5){            
    r = rand() % 6 + 2;
    c = rand() % 39 + 38;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 39 + 38;
    }
  }
//cout<<"chamber"<<i<<endl;
  if(z == 0){
    parray[i] = new potion(r, c, "RH");
    grid[r][c] = 'P';
  }
  else if(z == 1){
    parray[i] = new potion(r, c, "BA");
    grid[r][c] = 'P';
  }
  else if(z == 2){
    parray[i] = new potion(r, c, "BD");
    grid[r][c] = 'P';
  }
  else if(z == 3){
    parray[i] = new potion(r, c, "PH");
    grid[r][c] = 'P';
  }
  else if(z == 4){
    parray[i] = new potion(r, c, "WA");
    grid[r][c] = 'P';
  }
  else{
    parray[i] = new potion(r, c, "WD");
    grid[r][c] = 'P';
  }
}

void floor::setstair(int i){
  int ii = rand() % 5 + 1;
  int r1;
  int c1;
  while(ii == i){
    ii = rand() % 5 + 1;
  }
  if(ii == 1){ 
    r1=rand() % 6 + 2;            
    c1 = rand() % 28 + 2;
    while(grid[r1][c1] != '.'){
      r1 = rand() % 6 + 2;
      c1 = rand() % 28 + 2;
    }
  }
  if(ii == 2){             
    r1 = rand() % 9 + 14;
    c1 = rand() % 23 + 3;
    while(grid[r1][c1] != '.'){
      r1 = rand() % 9 + 14;
      c1 = rand() % 23 + 3;
    }
  }
  if(ii == 3){            
    r1 = rand() % 5 + 9;
    c1 = rand() % 14 + 37;
    while(grid[r1][c1] != '.'){
      r1 = rand() % 5 + 9;
      c1 = rand() % 14 + 37;
    }
  }
  if(ii == 4){            
    c1 = rand() % 41 + 36;
    r1 = rand() % 8 + 15;
    while(grid[r1][c1] != '.'){
      c1 = rand() % 41 + 36;
      r1 = rand() % 8 + 15;
    }
  }
  if(ii == 5){            
    r1 = rand() % 6 + 2;
    c1 = rand() % 39 + 38;
    while(grid[r1][c1] != '.'){
      r1 = rand() % 6 + 2;
      c1 = rand() % 39 + 38;
     }
  }
  grid[r1][c1] = '\\';
}

int floor::setplayer(player* p){
  int i = rand() % 5 + 1;
  int r;
  int c;
  if(i == 1){             
    c = rand() % 28 + 2;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 28 + 2;
    }
  }
  if(i == 2){            
    r = rand() % 9 + 14;
    c = rand() % 23 + 3;
    while(grid[r][c] != '.'){
      r = rand() % 9 + 14;
      c = rand() % 23 + 3;
    }
  }
  if(i == 3){            
    r = rand() % 5 + 9;
    c = rand() % 14 + 37;
    while(grid[r][c] != '.'){
      r = rand() % 5 + 9;
      c = rand() % 14 + 37;
    }
  }
  if(i == 4){            
    c = rand() % 41 + 36;
    r = rand() % 8 + 15;
    while(grid[r][c] != '.'){
      c = rand() % 41 + 36;
      r = rand() % 8 + 15;
    }
  }
  if(i == 5){            
    r = rand() % 6 + 2;
    c = rand() % 39 + 38;
    while(grid[r][c] != '.'){
      r = rand() % 6 + 2;
      c = rand() % 39 + 38; 
    }
  }
  p->setx(r);
  p->sety(c);
  grid[r][c] ='@';
  return i;
}

/*void floor::setdragon(int x, int y){
  int random=rand()%8;
  if(random==5) setx(getx()+1);
  else if(random==1) setx(getx()-1);
  else if(random==3) sety(gety()+1);
  else if(random==7) sety(gety()-1);
  else if(random==2) {
    sety(gety()+1);
    setx(getx()-1);
  }
  else if(random==0){
    setx(getx()-1);
    sety(gety()-1);
  }
  else if(random==4){
    setx(getx()+1);
    sety(gety()+1);
  }
  else if(random==6){
    sety(gety()-1);
    setx(getx()+1);
  }
  if(f->grid[getx()][gety()]!='.'){
    setx(tmpx);
    sety(tmpy);
    setdragon(getx(), gety());
  //cout<<"move b2"<<endl;
  }
  else{
    d.push_back(new dragon(getx(),gety()));
  //cout<<"move c"<<endl;
    int curx=getx();
    int cury=gety();
    f->grid[curx][cury]='D';
    }
}*/

void floor::createfloor(){
	//path
	  for(int r = 8;r<=13;r++){
   		grid[r][13] = '#';
   	}
   	for(int r = 5;r<=7;r++){
   		grid[r][33] = '#';
   	}
   	for(int r = 8;r<=20;r++){
   		grid[r][31] = '#';
   	}
   	for(int r = 11;r<=16;r++){
   		grid[r][54] = '#';
   	}
   	for(int r = 14;r<=17;r++){
	   	grid[r][43] = '#';
   	}
   	grid[14][69] = '#';
   	for(int c = 14;c<=30;c++){
   		grid[11][c] = '#';
   	}
   	for(int c = 26;c<=35;c++){
   		grid[20][c] = '#';
   	}
   	for(int c = 32;c<=53;c++){
   		grid[16][c] = '#';
   	}
   	for(int c = 32;c<=43;c++){
   		grid[8][c] = '#';
   	}
   	for(int c = 30;c<=37;c++){
   		grid[4][c] = '#';
   	}
   	for(int c = 54;c<=59;c++){
   		grid[11][c] = '#';
   	}
	//chamber 1
	for (int r=0; r<25; r++){
		grid[r][0]='|';
		grid[r][78]='|';
	}
	for (int r=1; r<=77; r++){
		grid[0][r]='-';
		grid[24][r]='-';
	}
	for (int r=2; r<=7; r++){
		grid[r][2]='|';
		grid[r][29]='|';
	}
	for (int r=2; r<=7; r++){
		for (int c=3; c<=28;c++){
			if (r==2 || r==7){
				grid[r][c]='-';
			}else {
				grid[r][c]='.';
			}
		}
	}
	//chamber 2
	for (int r=14; r<=22; r++){
		grid[r][3]='|';
		grid[r][25]='|';
	}
	for (int r=14; r<=22; r++){
		for (int c=4; c<=24; c++){
			if (r==14 || r==22){
				grid[r][c]='-';
			}else {
				grid[r][c]='.';
			}
		}
	}
	//chamber 3
	for(int r = 18;r<=22;r++){
         grid[r][36] ='|';
         grid[r][76] = '|';
   }
   for(int r = 15;r<=18;r++){
         grid[r][64] = '|';
         grid[r][76] = '|';
     for(int c = 65;c<=75;c++){
        if(r==15){
          grid[r][c] ='-';
        }else{
          grid[r][c] = '.';
        }
     }  
   }
   for(int c = 37;c<=63;c++){
        grid[18][c]='-';
   }
   for(int r=19;r<=22;r++){
       for(int c=37;c<=75;c++){
          if(r == 22){
            grid[r][c]='-';
          }else{
            grid[r][c]='.';
          }
       }
   }
   //chamber 4
    for(int r = 9;r<=13;r++){
        grid[r][37] = '|';
        grid[r][50] = '|';
   }
   for(int r = 9;r<=13;r++){
       for(int c = 38;c<=49;c++){
         if(r == 9 || r==13){
            grid[r][c] ='-';
         }else{
            grid[r][c] ='.';
         }
       }
   }
   //chamber 5
   for(int r = 2;r<=13;r++){
    if(r==2||r==3){
      for(int c = 39;c<=61;c++){
       if(r==2){
       	grid[r][c] = '-';
       }else{
       	grid[r][c] = '.';
       }
      }
    }
    else if(r==4){
      for(int c = 39;c<=62;c++){
      	grid[r][c] = '.';
      }
      for(int c = 63;c<=69;c++){
      	grid[r][c] = '-';
      }
    }
    else if(r == 5||r == 6){
      for(int c = 39;c<=72;c++){
      	grid[r][c] = '.';
      }
    }
    else if(r==7){
      for(int c = 39;c<=59;c++){
      	grid[r][c]= '-';
      }
      for(int c = 61;c<=75;c++){
      	grid[r][c] = '.';
      }
    }
    else if(r == 13){
       for(int c = 61;c<=75;c++){
       	grid[r][c] = '-';
       }
    }
    else{
       for(int c = 61;c<=75;c++){
       	grid[r][c] = '.';
       }
     }
   }
   grid[5][71] = '-';
   grid[5][72] = '-';
   grid[6][74] = '-';
   grid[6][75] = '-';
   for(int r = 2;r<=4;r++){
   	grid[r][38] = '|';
   	grid[r][62] = '|';
   }
   grid[4][70] = '|';
   grid[5][70] = '|';
   grid[5][73] = '|';
   grid[6][73] = '|';
   grid[6][76] = '|';
   for(int r = 5;r<=7;r++){
   	grid[r][38] = '|';
   }
   for(int r = 7;r<=13;r++){
   	grid[r][60] = '|';
   	grid[r][76] = '|';
   }
   //door
    grid[4][29]='+';
    grid[4][38]='+';
    grid[9][43]='+';
    grid[13][43]='+';
    grid[11][60]='+';
    grid[7][13]='+';
    grid[14][13]='+';
    grid[20][25]='+';
    grid[20][36]='+';
    grid[18][43]='+';
    grid[15][69]='+';
    grid[13][69]='+';
    grid[7][43]='+';
}

floor::~floor(){
	for (int r=0; r<25; r++){
		delete [] grid[r];
	}
	delete [] grid;
  for(int i=0; i<20; i++){
    delete earray[i];
  }
  delete [] earray;
  for(int i=0; i<10; i++){
    delete tarray[i];
  }
  delete [] tarray;
  for(int i=0; i<10; i++){
    delete parray[i];
  }
  delete [] parray;
}


void floor::makemove(player* p, string str){
  int tmpx=p->getx();
  int tmpy=p->gety();
  int result=p->move(str);
//cout<<"finish move"<<endl;
  if(result > 0){
//cout<<"before check"<<endl;
    checkaround(p);
    for(int i=0; i<20; i++){
//cout<<"for loop"<<endl;
      if(earray[i]->movebit==1 && earray[i]->isalive()==1){
//cout<<"before minions move"<<endl;
//cout<<earray[i]->getx()<<" y "<<earray[i]->gety()<<endl;
        earray[i]->move();
//cout<<"minions move"<<endl;
      }
      else{
        earray[i]->movebit=1;
      }
    }
  }
  else{
    p->action="invalid move!";
  }

}

void floor::checkaround(player* p){
  int x=p->getx();
  int y=p->gety();
  for(int i=x-1; i<=x+1; i++){
    for(int j=y-1; j<=y+1; j++){
      if(grid[i][j]=='G'){
        for(int m=0; m<10; m++){
          if(tarray[m]->x==i && tarray[m]->y==j && 
              tarray[m]->exist==1 && tarray[m]->type==3){
            if((tarray[m]->mydragon)->isalive()==1){
              (tarray[m]->mydragon)->hostile=1;
              for (int n=tarray[m]->mydragon->getx()-1; n<tarray[m]->mydragon->getx()+1; n++){
                for (int a=tarray[m]->mydragon->gety()-1; a<tarray[m]->mydragon->gety()+1; a++){
                  if (n == x && a == y){
                    (tarray[m]->mydragon)->hit(p);
                    if((tarray[m]->mydragon)->gethp()!=0){
                      p->hit(tarray[m]->mydragon);
                    }
                    else{
                      tarray[m]->pick=1;
                      int dx=(tarray[m]->mydragon)->getx();
                      int dy=(tarray[m]->mydragon)->gety();
                      grid[dx][dy]='.';
                    }
                  }
                }
              }
            }
          }
        }
      }
      /*else if(grid[i][j]=='P'){
        cout<<"There is a potion near you."<<endl;
      }
     /* else if(grid[i][j]=='M'){
        cout<<"There is a merchant near you."<<endl;
      }*/
      else{
        for(int n=0; n<20; n++){
          if(earray[n]->getx()==i && earray[n]->gety()==j &&
            earray[n]->isalive()==1){
            if(earray[n]->ishostile()==1){
              earray[n]->movebit=0;
              earray[n]->hit(p);
              if(earray[n]->gethp()!=0){
                p->hit(earray[n]);
              }
              else{
//cout<<"in"<<endl;
                int ex=earray[n]->getx();
                int ey=earray[n]->gety();
                if (earray[n]->getrace()=="Merchant"){
                  grid[ex][ey]='G';
                }
                else{
                  grid[ex][ey]='.';
                }
              }
            }
          }
        }
      }
    }
  }
}

void floor::hit(player* p, string str){
  int x=p->getx();
  int y=p->gety();
  if(str=="so") x++;
  else if(str=="no") x--;
  else if(str=="ea") y++;
  else if(str=="we") y--;
  else if(str=="ne") {
    y++;
    x--;
  }
  else if(str=="nw"){
    x--;
    y--;
  }
  else if(str=="se"){
    x++;
    y++;
  }
  else if(str=="sw"){
    y--;
    x++;
  }
  if(grid[x][y]=='D'){
//cout<<"a"<<endl;
    for(int i=0; i<10; i++){
//cout<<"a"<<i<<endl;
//cout<<"dragon"<<endl;
      if(tarray[i]->type==3 && (tarray[i]->mydragon)->getx()==x 
        && (tarray[i]->mydragon)->gety()==y){
//cout<<"b"<<endl;
        (tarray[i]->mydragon)->hit(p);
        if((tarray[i]->mydragon)->isalive()==1){
          p->hit((tarray[i]->mydragon));
        }
        else{
          grid[x][y]='.';
          tarray[i]->pick=1;
        }
      } 
    }
  }
  else{
    int flag=0;
    for(int i=0; i<20; i++){
      if(earray[i]->getx()==x && earray[i]->gety()==y){
        if(earray[i]->isalive()==1){
          flag=1;
//cout<<"start to hit"<<endl;
          earray[i]->hit(p);
          earray[i]->hostile=1;
//cout<<"finish hit"<<endl;
          earray[i]->movebit=0;
          if(earray[i]->isalive()==1){
            p->hit(earray[i]);
          }
          else{
            if(earray[i]->getrace()=="Merchant"){
                grid[x][y]='G';
                for(int i=0; i<20; i++){
                  earray[i]->hostile=1;
                }
                p->mhostile=1;
            }
            else{
              grid[x][y]='.';
            }
          }
          break;
        }
      }
    }
    if(flag==1){
      for(int i=0; i<20; i++){
        if(earray[i]->movebit==1 && earray[i]->isalive()==1){
          earray[i]->move();
        }
        earray[i]->movebit=1;
      }
    }
    else if(flag==0){
      p->action="invalid attack!";
    }
  }
}

void floor::printfloor(player* p){
  for(int i=0; i<25; i++){
    for(int j=0; j<79; j++){
      cout<<grid[i][j];
    }
    cout<<endl;
  }
  cout<<"Race: "<< p->getrace()<<" Gold: "<<p->getgold();
  cout<<"                                                   Floor: "<<numfloor<<endl;
  cout<<"HP: " << p->hp<<endl;
  cout<<"Atk: "<< p->getatk()<<endl;
  cout<<"Def: "<< p->getdef()<<endl;
  cout<<"Action: "<<p->action<<endl;
  p->action.clear();
}
