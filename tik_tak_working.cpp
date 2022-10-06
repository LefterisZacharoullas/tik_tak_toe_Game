//###########################################
//###    Tic Tac Toc Game by LEFTERIS     ###
//###########################################
#include <iostream>
using namespace std;

//constants declaration
const int gridSize = 3;

//declare global variables here
char grid[gridSize][gridSize];
int x,y, stop=0 , index1=0;

//function declarations
void printGame();
void askUserToPlay();
void printMenu();
void saveMove(int x, int y);
bool checkGameState();
void computersMove();
void printGameOver();

int main(){
    //initialize two dimensional array
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<gridSize; j++){
            grid[i][j]=' ';
        }
    }
    //set initial computer position
    grid[1][1] = 'o';

   do{
        printMenu();
        printGame();
        askUserToPlay();
        saveMove(x,y);
        computersMove();
        printGame();
   }while(checkGameState());


    return 0;
}

void printGame(){
    cout<<endl;
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<gridSize; j++){
            cout<<grid[i][j]<<" | ";
        }
        cout<<endl;
    }

}

void askUserToPlay(){

    bool wrongMove = true;
    do{
        cout<<endl<<"Enter the x:row, y:column position "<<endl<<"     of your next move (e.g. 0 1): ";
        cin>>x>>y;
        if( grid[x][y] == 'x' || grid[x][y] == 'o' || x>2 || x<0 || y>2 || y<0){
            cout<<endl<<"Wrong Move!!! Try again."<<endl;
        }
        else{
            wrongMove = false;
        }
    }while (wrongMove);
}

void printMenu(){
    cout<<endl;
    cout<<"*************************************"<<endl;
    cout<<"*********  Tic Tac Toe Game   *******"<<endl;
    cout<<"*******  Can you beat my code?  *****"<<endl;
    cout<<"*************************************"<<endl;
}

void saveMove(int x, int y){
    grid[x][y]='x';
}

bool checkGameState(){
    
    int numberX=0 ;

    //Cheking rows  
    for(int i=0; i<gridSize; i++){
        if(grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x' || grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o' ){
            printGameOver();
            return false;
        }
    } 
    //cheking columns 
    for(int i=0; i<gridSize; i++){
        if(grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x' || grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o' ){
            printGameOver();
            return false;
        }
    } 
    //elenxo tes diagonios  
    if ((grid[1][1] == 'o' && grid[0][0] == 'o' && grid[2][2] == 'o') || (grid[2][0] == 'o' && grid[1][1] == 'o' && grid[0][2] == 'o') ){
        printGameOver();
        return false ;
    }     
    //elenxo gis isopalia
    if(stop == 4){
        printGameOver();
        return false ;
    }
        
   return true ;
}

void printGameOver(){
    cout<<endl;
    cout<<"*************************************"<<endl;
    cout<<"*************  GAME OVER ************"<<endl;
    cout<<"********** !!! TRY AGAIN !!!  ******"<<endl;
    cout<<"*************************************"<<endl;
    cout<<endl;
}

void computersMove(){
    
    index1=0 ;
    stop++ ;
    
    for( index1=0; index1 < gridSize; index1++){
        for(int i=0; i<gridSize; i++){
            for(int j=i+1; j<gridSize; j++){

                if(grid[index1][i] == grid[index1][j]){

                    if(grid[index1][j] == 'o' && grid[index1][gridSize - j - i] == ' '){
                        grid[index1][gridSize - j - i] = 'o' ;
                    
                        return  ;
                    }

                    else if(grid[index1][j] == 'x' && grid[index1][gridSize - j - i] == ' '){
                        grid[index1][gridSize - j - i] = 'o' ;
                    
                        return  ;
                    }


                }

                if(grid[i][index1] == grid[j][index1]){
                
                    if(grid[j][index1] == 'o' && grid[gridSize - j - i][index1] == ' '){
                        grid[gridSize - j - i][index1] = 'o' ;
                    
                        return ;
                    }

                    else if(grid[j][index1] == 'x' && grid[gridSize - j - i][index1] == ' '){
                        grid[gridSize - j - i][index1] = 'o' ;
                    
                        return  ;
                    }

                }


            }
        }
    }

    if( index1 == 3){
        for(int i=0; i<gridSize; i++){
            for(int j=0; j<gridSize; j++){
                if(grid[i][j] == ' '){
                    grid[i][j] = 'o';
                    return;
                }
            }
        }   
    }

}
