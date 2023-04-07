
//Author: Christopher Hill For the EEE4120F course at UCT
//modified by: Bina Mukuyamba and S'thabiso Lushaba 
#include<fstream>
#include <cstdlib>
#include<stdio.h>
#include<iostream>

using namespace std;



//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}




int main(void){



	//New code for prac 2.2
	bool displayMatrices = true;
	int Size = 3; //changed from 3
	string string_Size = to_string(Size);
	int countA = Size*Size;
	int matrixA[countA];
	createKnownSquareMatrix(Size,matrixA, displayMatrices);
	cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
	

	
	
	int countB = Size*Size;
	int matrixB[countB];
	createKnownSquareMatrix(Size, matrixB, displayMatrices);
	cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
	
	
	
	int output[countA];
	
	//TODO: code your golden standard matrix multiplication here
		
	clock_t start, end;
	start = clock(); //timer implemented
	//runs 10 times using script_GoldenStd.py
		for (int i = 0; i <Size; i++) {
        for (int j = 0; j < Size; j++) {
            int sum = 0;
            for (int k = 0; k <Size; k++)
                sum = sum + matrixA[i * Size + k] * matrixB[k * Size + j];
            output[i * Size + j] = sum;
        }
		 }
	
	end = clock();
	float duration;
	duration = ((float) end - start)/CLOCKS_PER_SEC; //calculates duration

//write output to a txt file
	string filename("GoldStdOutput_" + string_Size + "x" + string_Size +".txt");
	ofstream myfile;
	myfile.open(filename, std::ios_base::app);
	
	//This if statement will display the matrix in output	and add it to .txt file
	if(displayMatrices){
		printf("\nOutput in the output_buffer \n");
		myfile << "\nOutput in the output_buffer \n"; //add to .txt file
		for(int j=0; j<countA; j++) {
			printf("%i \t " ,output[j]);
			myfile << output[j] << " \t"; //add to .txt file separate columns by tab
			if(j%Size == (Size-1)){
				printf("\n");
				myfile << "\n"; //add a new line
			}
		}
	}

	//print run time
	printf("Run Time: %0.8f sec \n", duration);
	myfile << "Run Time: " << duration << "sec \n"; //adds run time to .txt
	myfile.close();
	return 0;
	
	return 0;
}
