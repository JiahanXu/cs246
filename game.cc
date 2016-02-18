#include "player.h"
#include "floor.h"
#include "enemy.h"
#include "character.h"
//#include "potion.h"
#include "orc.h"
#include "dwarf.h"
#include "elves.h"
#include "human.h"
#include "nami.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	int quit=0;
	while(!quit){
		cout << "Welcome to ChamberCrawler3000" << endl;
    	cout << "Please choose a race:" << endl;
   		cout << "Human(h), Elves(e), Dwarf(d), Orc(o), Nami(n)" << endl;
    	cout << "Quit(q) Restart(r)" << endl;
		char playertype;
		cin >> playertype;
//cout<<"a"<<endl;
		player* p;
		floor* myfloor[5];
		int curfloor=0;
		for(int i=0; i<5; i++){
//cout<<"a1"<<endl;
			myfloor[i]=new floor();
		}
//cout<<"b"<<endl;
		switch(playertype){
			case 'e':
				p=new elves(0, 0);
				break;
			case 'd':
				p=new dwarf(0, 0);
				break;
			case 'o':
				p=new orc(0, 0);
				break;
			case 'n':
				p=new nami(0, 0);
				break;
			default:
				p=new human(0, 0);
		}
		int i=myfloor[0]->setplayer(p);
//cout<<i<<endl;
		myfloor[0]->setstair(i);
		p->setfloor(myfloor[0]);
//cout<<"c"<<endl;
		while(true){
			myfloor[curfloor]->printfloor(p);
			cout<<"what is your next move?"<<endl;
			string command1, command2;
			cin >> command1;
			if(command1=="u"){
				cin >> command2;
				myfloor[curfloor]->makemove(p, command2);
			}
			else if(command1=="a"){
				cin >> command2;
				myfloor[curfloor]->hit(p, command2);
			}
			else if(command1=="r"){
				break;
			}
			else if(command1=="q"){
				quit=1;
				break;
			}
			else if(command1=="no" || command1=="so" || command1=="ea" || command1=="we"
				|| command1=="ne" || command1=="nw" || command1=="se" || command1=="sw"){
				myfloor[curfloor]->makemove(p, command1);
				//cout<<"you made move "<<command1<<endl;
			}
			else{
				//cout<< "invalid move!"<<endl;
			}
			if(p->isalive()==false){
				myfloor[curfloor]->printfloor(p);
				cout<< "your score is " << p->getgold()<<endl;
				cout<< "Do you want to restart or quit?" << endl;
				string tmp;
				cin >> tmp;
				if (tmp == "q"){
					quit=1;
				}
				break;
			}
			if(p->nextfloor==1){
				curfloor++;
				if(curfloor>4){ 
					cout<<"You win the game!"<<endl;
					cout<< "Do you want to restart or quit?" << endl;
					string tmp;
					cin >> tmp;
					if (tmp == "q"){
						quit=1;
					}
					break;
				}
				else{
					myfloor[curfloor]->numfloor=curfloor+1;
					int r=myfloor[curfloor]->setplayer(p);
//cout<<r<<endl;
					myfloor[curfloor]->setstair(r);
					p->setfloor(myfloor[curfloor]);
					p->nextfloor=0;
				}
			}
			if(p->mhostile==1){
				for(int i=0; i<5; i++){
					for(int j=0; j<20; j++){
						myfloor[i]->earray[j]->hostile=1;
					}
				}
			}
		}
		for(int i=0; i<5; i++){
			delete myfloor[i];
		}
	}
	return 0;
}
