//Fidkn KhalilbayliS
#include<stdio.h>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<string.h>
#include<conio.h>
#define row 9
#define col 9
using namespace std;
bool sudokuChecker(int sudoku[row][col]) ;

bool sudokuChecker(int sudoku[row][col]) {
	int sum, counter=0;

	//checking columns
		for(int j = 0;j < col-1;j++){
			for(int i = 0;i < row;i++){
				for(int k = 0;k < row - i;k++){
					if(sudoku[row][col] == sudoku[row][col+1+k])
						return false ;
				}
			}	
		}
		
    //checking rows                 	
			for(int i = 0; i < row - 1; i++){	
				for(int j = 0; j < col; j++){
					for(int k = 0; k < row - j; k++){
						if(sudoku[row][col] == sudoku[row+1+k][col])
					return false;
			}	
		}
	}
	
	//checking each 3x3 matrix
	//here if the sum of 3x3 matrices is 45 (which is also the sum of the numbers from 1 to 9) then the counter is increased by one
	// in the end of this summation if the counter is 9 namely if the sum of each 3x3 matrix is 45 then true is returned to main 
		for(int e = 0; e <= 6; e+= 3){
				for(int d = 0; d<= 6;d+= 3){
				  	sum = 0;
 					for(int c = 0; c < 3; c++){
						for(int b = 0; b < 3; b++)	
							sum+= sudoku[c+e][b+d];	
					}
					if(sum==45)
						counter++;
				}
		} 
	if (counter==9)
		return true;
	else
		return false;
}

int main(){	
		FILE * file;
		int number,sudoku[9][9];	
		file = fopen("example_sudoku.txt", "r+");
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){				
				fscanf(file, "%d", &number);		
				sudoku[i][j] = number;
				cout << sudoku[i][j]<<" ";
	  		}		
			cout<<endl<<endl;
		}

		if (sudokuChecker(sudoku)==false)
			cout<<"The sudoku is INVALID"<<endl;
		else
			cout<<"The sudoku is VALID"<<endl;			
		fclose(file);
		return 0;
}
