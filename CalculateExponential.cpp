#include "CalculateExponential.hpp"

#include <cmath>

double CalculateFactorial(double count){ //recursive function

if(count==1){
	return 1.0; 
	}
	else{
	// n>1
	return count*CalculateFactorial(count-1); 
	}
}






void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
	int rows = 3;
	int cols = 3;
	int n = 3;
	int count = 1;

	ComplexNumber **Temp; //idendenty //Allocate memmory for A
	Temp = new ComplexNumber* [rows]; 
	for (int i=0; i <rows; i++){
		Temp[i] = new ComplexNumber [cols];
	}

	ComplexNumber **newMat; //idendenty //Allocate memmory for A
	newMat = new ComplexNumber* [rows]; 
	for (int i=0; i <rows; i++){
		newMat[i] = new ComplexNumber [cols];
	}

	ComplexNumber **oldMat; //idendenty //Allocate memmory for A
	oldMat = new ComplexNumber* [rows]; 
	for (int i=0; i <rows; i++){
		oldMat[i] = new ComplexNumber [cols];
	}


	//idententy matrix allocate
	ComplexNumber **I; //idendenty //Allocate memmory for A
	I = new ComplexNumber* [rows]; 
	for (int i=0; i <n; i++){
		I[i] = new ComplexNumber [cols];
	}

	ComplexNumber z(1,0); // complex 1 1 1 numbers
	I[0][0] = z;
	I[1][1] = z;
	I[2][2] = z;
	ComplexNumber z2(0,0);


	for (int i = 0; i < rows; i++){//copy the A
		for (int j = 0; j<rows;j++){
			Temp[i][j] = A[i][j];
		}
	}
	// ComplexNumber z0(0,0);
	// for (int i =0;i <rows;i++){
	// 	for(int j=0;j<cols;j++){
	// 		res[i][j] = res[i][j] + I[i][j];
	// 	}
	// }

	// for (int i =0;i <rows;i++){
	// 	for(int j=0;j<cols;j++){
	// 		res[i][j] = res[i][j] + A[i][j];
	// 	}
	// }





	for (int i=0;i <rows;i++){
		for(int j=0;j<cols;j++){
			oldMat[i][j] = I[i][j];
		}
	}


	for (int k = 0; k<nMax; k++){
	if (k==0){
		for (int i =0;i <rows;i++){
		for(int j=0;j<cols;j++){
			res[i][j] = res[i][j] + I[i][j];
			}
		}
		count = 0;
	}
	else {
		if(k==1){
			count = 1;
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					res[i][j] = A[i][j];
				}
			}
		}
		else{
		for(int i=0; i<rows;i++){ //make Anew = Aold*A
			for (int j=0;j<cols;j++){
				newMat[i][j] = z2;
				for (int k = 0; k<rows; k++){
					newMat[i][j] = newMat[i][j] + Temp[i][k]*oldMat[k][j];
					
				}
			}
		}



		//update OldMat = NewMat
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				oldMat[i][j] = newMat[i][j];
			}
		}

		ComplexNumber fac(1/CalculateFactorial(count),0);
		//std::cout << fac;
		for(int i =0;i<rows;i++){
			for(int j=0;j<cols;j++){
				res[i][j]= res[i][j]+newMat[i][j]*fac;
			}
		}
		count +=1;
	}
}
}
// for (int i=0; i <rows;i++){
// 		for(int j=0;j<cols;j++){
// 			std::cout << newMat[i][j];
// 			if (j==rows-1){
// 				std::cout << "\n";
// 			}
// 		}
// 	}


	

/*
		for(int i=0;i <rows;i++){
			for(int j=0;j<cols;j++){
				oldMat[i][j] = newMat[i][j];

			}
		}


		ComplexNumber k(1/CalculateFactorial(count),0);
		for(int i =0;i<rows;i++){
			for(int j=0;j<cols;j++){
				res[i][j]=res[i][j]+newMat[i][j]*k;
			}
		}

		count+=1;

		}


		}

	

*/

	for(int i = 0;i<rows;i++){
		delete[] Temp[i];
	}
	 delete[] Temp;

	for(int i=0;i<rows;i++){
		delete[] newMat[i];

	}	 
	delete newMat;

	for(int i=0;i<rows;i++){
		delete[] oldMat[i];

	}	 
	delete oldMat;
	
	for(int i=0;i<rows;i++){
		delete[] I[i];
	}
	delete[] I;
}


/*
	n = 3;
		ComplexNumber **I; //idendenty
	I = new ComplexNumber* [n]; 

	for (int i=0; i <n; i++){
		I[i] = new ComplexNumber [n];
	}

	
	ComplexNumber** Temp; //when k =1
	Temp = new ComplexNumber* [n]; // Matrix B 
	for (int i = 0; i < n; i++){
		Temp[i] = new ComplexNumber [n];
	}
	for(int i=0;i<n;i++){ //allocate A1 to Temp
		for(int j=0;j<n;j++){
			Temp[i][j]=A[i][j];
		}
	}
	int count = 0;
	for (int k=0;k<nMax;k++){

	//first when k == 0 identity matrix
	if (k == 0){ //for A^0 = I
		I[0][0] = ComplexNumber(1);
		I[1][1] = ComplexNumber(1);
		I[2][2] = ComplexNumber(1);

		for (int i =0; i <n ; i++){
			for (int j=0 ; j<n;j++){
					A[i][j]=I[i][j];
				}

			}

		count +=1; // count 1 , factorial return 1
		
	*/

	/*
	for (int i;i<n;i++){
		for(int j; j<n;j++){
			//calculate Exp(A) fact n=1
			res[i][j] = exp(A[i][j]) //when n=0 exp(A) = A^0/1
			}
		
		} 
	}*/








/*		if (k==0){
			for (int i = 0; i<rows; i++){
				for(int j=0;j<cols;j++){
					A[i][j] = I[i][j]; //A^0
					res[i][j] = A[i][j];

				}

			}
		}
		else if(k==1) { //update A[i][j] = A 

			for(int i =0;i<rows;i++){
				for(int j=0;j<cols;j++){
					A[i][j] = Temp[i][j];
				}
			}
			for(int i=0;i<rows;i++){
				for(int j=0; j<cols;j++){
					res[i][j]= res[i][j] + A[i][j];

				}
			}

			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					oldMat[i][j]=A[i][j];
				}
			}


		}*/


















/*
	else if (k==1){
			for (int i =0; i <n; i++){
				A[i][j] = Temp[i][j]//back
			}

			for(int i =0;i<n;i++){
				for(int j = 0; j<n;j++){
					A[i][j] =0;
					for(int k; k<n;k++){
						A[i][j]+= A[i][k]*A[k][j];
					}
				}
			}

	}
	else{


	}



	}





}

	
	*/


/*
		//else if k = 1 then   
	for (int i = 0 ; i < ARows; i++){
		for(int j=0; j < ACols; j++){
			res[i][j] = 0; 
			for (int k = 0; k < ACols; k++){ // this is how you multipy to matricies
					res[i][j]+=  A[i][k]*B[k][j]; // can also for a vector
			}

		std::cout << res[i][j]<< "\n ";

		}
	}
	// then do k >2 




}


void Multiply(double**res , double** A, 
	double** B,int ARows, int ACols , int BRows, int BCols){
	
	double** B; 
	B = new double* [BRows]; // Matrix B 
	for (int i = 0; i < BRows; i++){
		B[i] = new double [BCols];
	}

	int ARows = 3, ACols = 3, BRows = 3, BCols=3; 
	double** A; //For A Matrix 
	A = new double* [ARows]; // Matrix B 
	for (int i = 0; i < ARows; i++){
	A[i] = new double [ACols];
	}



	// giving that matrix of two matricies

	for (int i = 0 ; i < ARows; i++){
		for(int j=0; j < ACols; j++){
			//res[i][j] +=A[i][j]*B[i][j]; 
			// std::cout << res[i][j] << " "; 
			res[i][j] = 0; 
			for (int k = 0; k < ACols; k++){ // this is how you multipy to matricies
					res[i][j]+=  A[i][k]*B[k][j]; // can also for a vector
			}

		std::cout << res[i][j]<< "\n ";

		}
	}

}*/


	//get the faculty function, inside here(recursive)
		
	//make allocate matrix
		// if the A 1 is one 
		// or k !=0 
			//put the first matrix as the **A
	//make identiy A0 - do this 
	//make k=2 then A0 + A1
	//make k>2 then iterate the sum
		//one matrix sum 

	//forumalate k>2;
		//recursive function
		//



