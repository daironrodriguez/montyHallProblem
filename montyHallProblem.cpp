#include <iostream>
#include <iomanip>
#include <ctime> 

using namespace std;

int choice;
int option = 0;
int win = 1;
int car;
int host;
int numGames;
char results;
string gameState;

void dispalyResult(int &choice, int numGames, int car, int host);
void game(int option, int &choice, int &car, int &host, string &gameState);


int main (){
  while(true) {
srand ( time(0) );

  cout <<"1-- Never switch"<< endl;
  cout <<"2-- Always switch"<< endl;
  cout <<"3-- Randomly switch"<< endl;
  cout <<"4-- to Exit"<< endl;
  cout <<"Your choice: ";
  cin >> option;
  if (option == 4)
  {
    break;
  }
  
  cout <<"Play how many games: ";
  cin >> numGames;
  cout <<"Display results of each game [Y]es, [N]o: ";
  cin >> results;
  choice = (rand()%3)+1;
  
  win = 0;
  for(int i =1 ; i < numGames; i++){
    game(option, choice, car, host, gameState);
  	if (results == 'Y' || results == 'y' ){
  		dispalyResult(choice, numGames, car, host);
    }
    car = (rand()%3) +1;
}

  cout <<"Games played: "<<numGames<<  endl;
  cout <<"Games won: "<< win <<  endl;
  cout <<"Percent won: "<<(win*100)/numGames <<"%"<<  endl;
  cout << endl;


}

	return 0;
}



void dispalyResult(int &choice, int numGames, int car, int host){
  cout <<"Beging a new game "<< endl;
  cout <<"Person pick door "<< choice << endl;
  cout <<"Car is behind door "<< car << endl;
  cout <<"Host opens door " << host << endl;
  cout << gameState << endl;
  cout <<"\n";



}

void game(int option, int &choice, int &car, int &host, string &gameState){
  int temp;
	if(option == 2){
    	choice = (rand()%3)+1;
      temp = choice;
    }
	car = (rand()%3) + 1;
	do{
		host = (rand()%3) + 1 ;
    if (option == 3){
      do{
        choice = (rand()%3) + 1;
      }while(choice == host || choice == temp );
    }
	}while (host == choice);

	

	if (choice == car ){
      gameState = "Win";
      win++;
    }else {
  	  gameState = "Loss";
  }

}

