

#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<ctime>
#include<windows.h>

using namespace std;
const int width=30;
const int height=20;
int x,y,fruitx,fruity,score;
// x and y for our head position
//variables for fruit position: fruitx,fruity
int tailx[100];
int taily[100];
// length of the tail
int ntail;
enum edirecton {stop=0,LEFT,RIGHT,UP,DOWN};
enum edirecton dir;

bool gameover;
void Setup(){
gameover = false;
dir=stop;//snake will not move until we start moving it
x=width/2;
y=height/2;
fruitx=rand()%width;
fruity=rand()%height;
score=0;
}
void Draw(){
system("cls");// for clearing the screen in linux use ("clear")
//for displaying the top border of our screen
for (int i=0;i<width+2;i++){
    cout<<"#";

}cout<<endl;
//for making the field or can say map where our snake moves .IT is similar to the matrix..

for (int i=0;i<height;i++){
    for (int j=0;j<width;j++){
        if (j==0)
            cout<<"#";

            if (i==y && j==x)
    cout<<"0"; // to print the snake initially

    else if (i==fruity && j== fruitx)
        cout<<"F";// to print the fruit ..
else {
    bool print =false;
    for (int k=0;k<ntail;k++){
        if(tailx[k]==j && taily[k]==i){
            cout<<"o";
            print=true;
        }
    }
    if(!print){
        cout<<" ";
    }
}



         if (j==width-1)
            cout<<"#";
    }
    cout<<endl;
}

//for displaying the top border of our screen
for (int i=0;i<width+2;i++){
    cout<<"#";

}  cout<<endl;
  }
  // for giving input by user which makes our snake move in any direction
  // w == up
  //A== left , D== right and S== down
void Input(){
if (_kbhit())
{

    switch (_getch()){
       case'a' :
             dir=LEFT;
              break;

    case 'd':
             dir=RIGHT;
              break;
    case 'w':
              dir=UP;
               break;
    case 's':
            dir=DOWN;
               break;
    case 'x':
           gameover=true;
                break;
                  }

}
           }

void Logic(){

int prevx=tailx[0];
int prevy=taily[0];
int prev2x,prev2y;
tailx[0]=x;
taily[0]=y;

// forloop for cahnging snake on board
for (int i=1;i<=ntail;i++){
    prev2x= tailx[i];
    prev2y=taily[i];
    tailx[i]=prevx;
    taily[i]=prevy;
    prevx=prev2x;//head becomes small
    prevy=prev2y;

}
switch(dir)
{
case LEFT:
    x--;
    break;

case RIGHT:
    x++;
    break;

case UP:
    y--;
    break;

case DOWN:
    y++;
    break;

default:
    break;
}

   // now build logic for game over
   // if snake touches the boundary

 //  if (x>width || x<0 || y> height || y<0 ){
    //gameover=true;
   //}     // to make original game open this comment
     if (x>=width) x=0;
   else if(x<0) x=width-1;
   if (y>=height) y=0;
   else if (y<0) y=height-1;

   // if snake bits itself
   for(int i=0;i<ntail;i++){
    if (tailx[i]==x && taily[i]==y){
        gameover=true;
    }
   }

   // if snake head cooreats fruit they become equal , noe fruit should be at diff position
   if (x==fruitx && y==fruity){
        ntail++;
    score+=10;
    fruitx=rand()%width;
fruity=rand()%height;
   }
}
int main (){
    Setup();
    while (!gameover){
        Draw();
        Input();
        Logic();
        Sleep(20);
        cout<<"SCORE: ";
        cout<<score;
    }

return 0;
}
