#include<bits/stdc++.h>
using namespace std;
class Caro{
    public:
        
        Caro(int r, int c){    
            row = r;
            cell = c;        
            filled=0;
            turn=true;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    player1[i][j] = false;
                    player2[i][j] = false;
                }
            }
        }
        void play(){
            print();
            while(filled<(row*cell)){
                if(turn) cout << "player1 turn\n";
                else cout << "player2 turn\n";
                cout << "select where you want to go\n";
                cout << "row: ";
                cin >> markrow;
                cout << endl << "collumn: ";
                cin >> markcell;
                cout<<endl;
                if(mark(markrow,markcell) == false) continue;
                print();
                if(turn) {
                    if(check(player1)) {
                        cout << "player1 wins"<< endl << "game over";
                        return;    
                    }
                } else
                    if(check(player2)) {
                        cout << "player2 wins"<< endl << "game over";
                        return;
                    }
                turn = !turn;          
            }
            cout << "draw\n";
            cout << "game over";
            return;
        }
    private:
        int markrow,markcell;
        int row, cell;
        int filled;
        bool turn;
        bool player1[100][100];
        bool player2[100][100];
        bool mark(int r, int c){
            if(player1[r][c]==true || player2[r][c]==true){
                cout << "this spot is occupied" << endl;
                
                return false;
            }
            if(turn==true){
                player1[r][c] = true;
            }
            else player2[r][c] = true;
            filled++;
            return true;
        }
        void print(){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < cell; j++){
                    cout << " -";
                }
                cout << endl;
                for(int j = 0; j < cell; j++){
                    cout << "|";
                    if(player1[i][j]) cout << "x";
                    else if(player2[i][j]) cout << "o";
                    else cout << " ";
                }
                cout << "|";
                cout <<endl;
            }
            for(int j = 0; j < cell; j++){
                cout << " -";
            }
            cout << endl;
        }
        bool check(bool table[][100]){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < cell; j++){
                    if(table[i][j] == table[i+1][j] && table[i+1][j] == table[i+2][j] && table[i+2][j] == table[i+3][j] && table[i+4][j] == table[i+3][j] && table[i][j] == true){
                        return true;
                    }
                    if(table[i][j] == table[i][j+1] && table[i][j+2] == table[i][j+1] && table[i][j+2] == table[i][j+3] && table[i][j+4] == table[i][j+3] && table[i][j] == true){
                        return true;
                    }
                    if(table[i][j] == table[i+1][j+1] && table[i+2][j+2] == table[i+1][j+1] && table[i+2][j+2] == table[i+3][j+3] && table[i+4][j+4] == table[i+3][j+3] && table[i][j] == true){
                        
                        return true;
                    }
                    if(i>=4){
                        if(table[i-4][j+4] == table[i-3][j+3] && table[i-2][j+2] == table[i-3][j+3] && table[i-1][j+1] == table[i-2][j+2] && table[i-1][j+1] == table[i][j] && table[i][j] == true){                            
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};
int main(){
    int ro, ce;
    cout << "Welcome to caro, in this game you have to connect 5 marks into a line to win\n";
    cout << "please choose the size of your board, max is 50x50 \n";
    cout << "rows: ";
    cin >> ro;
    cout << endl;
    cout << "collumn: ";
    cin >> ce;
    Caro game(ro, ce);
    game.play();
    return 0;
}