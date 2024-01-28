#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<bits/stdc++.h>
#include<mmsystem.h>
using namespace std;
#define MAX_LENGTH 1000
const char LEFT='a';
const char UP='w';
const char DOWN='s';
const char RIGHT='d';

int consoleWidth, consoleHeight;
void initScreen(){
	HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hconsole, &csbi);
	consoleHeight=csbi.srWindow.Bottom-csbi.srWindow.Top + 1;
	consoleWidth=csbi.srWindow.Right-csbi.srWindow.Left + 1;
}
struct Point{
	int xcoord;
	int ycoord;
	Point(){
	}
	Point(int x, int y){
		xcoord=x;
		ycoord=y;
	}
};
class Snake{
	private:
		int length;
		char direction;
	public:
	    Point body[MAX_LENGTH];
	Snake(int x, int y){
		length=1;
		body[0]=Point(x,y);
		direction=RIGHT;
	}
	int getlength(){
		return length;
	}
	void getdirection(char newdir){
		if(newdir==UP && direction!=DOWN){ 
			direction=newdir;
		}
		else if(newdir==DOWN && direction!=UP){ 
			direction=newdir;
		}
		else if(newdir==LEFT && direction!=RIGHT){ 
			direction=newdir;
		}
		else if(newdir==RIGHT && direction!=LEFT){ 
			direction=newdir;
		}
	}
	bool move(Point food){
		for(int i=length-1; i>0; i--){ //if length = 12 then body index will be 11
			body[i]=body[i-1]; //position of the second last body part is given to the last one
		}
		switch(direction){
			int val;
			case UP:
			    val=body[0].ycoord;
			    body[0].ycoord=val-1;	//because when moving up, y coordinate decreases
			    break;
			case DOWN:
				val=body[0].ycoord;
				body[0].ycoord=val+1;
				break;
			case RIGHT:
				val=body[0].xcoord;
				body[0].xcoord=val+1;
				break;
			case LEFT:
				val=body[0].xcoord;
				body[0].xcoord=val-1;
				break;
		}
		//if snake bites itself
		for(int i=1; i<length; i++){
			if(body[0].xcoord==body[i].xcoord && body[0].ycoord==body[i].ycoord){
				return false;
			}
		}
		//if snake eats food
		if(food.xcoord==body[0].xcoord && food.ycoord==body[0].ycoord){
			body[length]=Point(body[length-1].xcoord, body[length-1].ycoord); //position of the previously last one is given to the new one.
			length++; //length has to be increased later
			//the loop again runs and the bosy is moved forward itself so the coordinates of new and last one do not become same 
		}
		return true;
	}
};
class Board{
	private:
		Snake *snake; //dynamic memory
		const char SNAKE_BODY='O';
		int score;
		Point food; //stat memory
		const char FOOD='o';
	public:
		Board(){
			spawnfood();
			snake=new Snake(10,7);
			score=0;
		}
		~Board(){
			delete snake;
		}
		int getscore(){
			return score;
		}
		void spawnfood(){
			int x=rand()%consoleWidth; //function for generating a random number from 1 to 1 less than the width of the screen
			                           //width because x coordinate
			int y=rand()%consoleHeight; //height because y coordinate
			food=Point(x, y); //constructor of point class is called where x and y coordinates are set
		}
		void displayCurrentScore(){
			gotoxy(consoleWidth/2, 0);
			cout<<"WELCOME TO THE GAME!"<<endl;
			gotoxy(consoleWidth/2, 1);
			cout<<"  Current score: "<<score;
		}
		void gotoxy(int x, int y){
			COORD coord;
			coord.X=x;
			coord.Y=y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //to get food on a random point
		}
		void draw(){
			system("cls"); //to clear the previous body
			for(int i=0; i<snake->getlength(); i++){ //if length is 12 then body will be 1 less always
				gotoxy(snake->body[i].xcoord, snake->body[i].ycoord); //if i=1 then the coordinates at 1 will be called
				cout<<SNAKE_BODY;
			}
			gotoxy(food.xcoord, food.ycoord);
			cout<<FOOD;
			displayCurrentScore();
		}
		bool update(){ //to check if game should go on or not
			bool isAlive = snake->move(food); //returns boolean value
			if(isAlive==false){
				return false;
			}
			if(food.xcoord==snake->body[0].xcoord && food.ycoord==snake->body[0].ycoord){
			score++;
			spawnfood();}
			return true;
		}
		void getInput(){ //for getting direction
			if(kbhit()){ //kbhit=function in conio class
				int key=getch(); //storing the charater got in variable "key"
				switch(key){
					case 'a':
						snake->getdirection(LEFT);
						break;
					case 'w':
						snake->getdirection(UP);
						break;
					case 's':
						snake->getdirection(DOWN);
						break;
					case 'd':
						snake->getdirection(RIGHT);
						break;
				}
			}
		}
};

int main(){
	srand(time(0));
	initScreen();
	Board *board=new Board(); //constructor
	while(board->update()){
		board->getInput();
		board->draw();
		Sleep(1);
	}
	cout<<"\n\t\tGAME OVER!"<<endl;
	cout<<"\t\tFINAL SCORE: "<<board->getscore();
	return 0;
}
