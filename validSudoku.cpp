#include <iostream>
using namespace std;

bool isValidSudoku(char sudoku[][]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j]>'0' && sudoku[i][j]<='9'){
                for (int k = j + 1; k < 9; k++){
                    if(sudoku[i][j] == sudoku[i][k]) return false;
                }
            }
            
        }
    }

    for(int j = 0; j < 9; j++){
        for(int i = 0; i < 9; i++){
            if(sudoku[i][j]>'0' && sudoku[i][j]<='9'){
                for (int k = i + 1; k < 9; k++){
                    if(sudoku[i][j] == sudoku[k][j]) return false;
                }
            }
            
        }
    }

    for(int e = 0; e < 3; e++){
        for(int i = e; i < 3; i++){
            for(int j = e; j < 3; j++){
                if(sudoku[i][j]>'0' && sudoku[i][j]<='9'){
                    for (int k = j + 1; k < 9; k++){
                       if(sudoku[i][j] == sudoku[i][k]) return false;
                    }   
                }

            }
        }    
    }

}

int main(){
    char sudoku[9][9];
    cout<<"Please fill in the Sudoku(number or .)"
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>sudoku[i][j];
        }
    }

}