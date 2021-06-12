#include <iostream>
#include <vector>
using namespace std;

void displayBoard();
bool ifWin();
void playGame();
bool checkCols();
bool checkRows();
bool checkDiag();
bool isBoardFull();
void boardValues();

vector <char> board {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void displayBoard(){
    cout<<" "<<board.at(0)<<" | "<<board.at(1)<<" | "<<board.at(2)<<" \n";
    cout<<"-----------\n";
    cout<<" "<<board.at(3)<<" | "<<board.at(4)<<" | "<<board.at(5)<<" \n";
    cout<<"-----------\n";
    cout<<" "<<board.at(6)<<" | "<<board.at(7)<<" | "<<board.at(8)<<" \n";
}

void boardValues(){
    for(int i = 0; i<9 ; i++){
        cout<<board[i];
    }
    cout<<endl;
}


bool ifWin(){ //checks rows columns and diagonals for winner
    bool winner = false;
    if(checkCols()){
        winner = true;
    }
    else if(checkRows()){
        winner = true;
    }
    else if(checkDiag()){
        winner = true;
    }
    return winner;
}

bool checkCols(){ //checks columns
    bool win=false;
    if(((board.at(0)==board.at(3)) && (board.at(3)==board.at(6)) && board.at(0) != ' ')){
        win = true;
    }
    else if(((board.at(1)==board.at(4)) && (board.at(4)==board.at(7)) && board.at(1) != ' ')){
        win = true;
    }
    else if(((board.at(2)==board.at(5)) && (board.at(5)==board.at(8)) && board.at(2) != ' ')){
        win = true;
    }
    else
        win = false;
        
    return win;
}

bool checkRows(){//checks rows
    bool win=false;
    if(((board.at(0)==board.at(1)) && (board.at(1)==board.at(2)) && board.at(0) != ' ')){
        win = true;
    }
    else if(((board.at(3)==board.at(4)) && (board.at(4)==board.at(5)) && board.at(3) != ' ')){
        win = true;
    }
    else if(((board.at(6)==board.at(7)) && (board.at(7)==board.at(8)) && board.at(6) != ' ')){
        win = true;
    }
    else
        win = false;
        
    return win;
}

bool checkDiag(){//checks diagonals
    bool win=false;
    if(((board.at(0)==board.at(4)) && (board.at(4)==board.at(8)) && board.at(0) != ' ')){
        win = true;
    }
    else if(((board.at(2)==board.at(4)) && (board.at(4)==board.at(6)) && board.at(2) != ' ')){
        win = true;
    }
    else
        win = false;
        
    return win;
}

void playGame(){
    bool winner = false;
    int boardPos {0};
    size_t turn = 1;
    
    cout<< "WELCOME, TO TIC TAK TOE\n";
    while(winner==false){
        cout<<"Enter the position you want to place: " << endl;
        cout<<" 1 | 2 | 3 \n";
        cout<<"-----------\n";
        cout<<" 4 | 5 | 6\n";
        cout<<"-----------\n";
        cout<<" 7 | 8 | 9\n";
        cout<<"Enter here: ";
        cin >> boardPos;
        if(board[boardPos-1]=='X' || board[boardPos-1]=='O'){
            cout<<"Invalid Position"<<endl;
            continue;
        }
        cout<<"\n";
        if(turn==1){
            board[boardPos-1]='X';
            turn=2;
            displayBoard();
            
            if(ifWin()){
                cout<< "player 1 wins"<<endl;
                winner=true;
                continue;
            }
            else if(!ifWin() && isBoardFull()){
                cout<< "Tie"<<endl;
                continue;
                winner=true;
            }
            
            cout<<"\nPlayer 2's turn:"<<endl;
            continue;
        }
        else if (turn==2){
            board[boardPos-1]='O';
            turn=1;
            displayBoard();
            
            if(ifWin()){
                cout<< "player 2 wins"<<endl;
                winner=true;
                continue;
            }
            else if(!ifWin() && isBoardFull()){
                cout<< "Tie"<<endl;
                continue;
                winner=true;
            }
            
            cout<<"\nPlayer 1's turn:"<<endl;
            continue;
        }
        else{
            cout << "turn out of range... game ending.";
            winner=true;
        }
    }
    cout << "Game Over"<<endl;
}

int main(){
    
    playGame();
    return 0;
    
}
