//to solve given LPP using Gauss-Jordan method
#include<iostream>
using namespace std;

//declearing frequently used variables as global
int row_num,col_num;

void printMatrix(float arr[][10]);
void partially_pivot(float arr[][10],int, int);

main(){
	float arr[10][10];
	float diagonal_element,flag;
	int i,j,k,l,step=0,add=0,sub=0,mul=0,div=0;

	cout<<"enter the number of rows \n";
	cin>>row_num;
	
	cout<<"enter the number of columns\n";
	cin>>col_num;
	
	cout<<"enter the items in the matrix : \n";
	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			cout<<"row "<< i << " column "<< j << ":\t";
			cin>>arr[i][j];
			cout<<endl;
		}
	}	

	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			if(i == j){
				partially_pivot(arr,i,j);
				
				diagonal_element = arr[i][j];
				k = i;
				l = j;
				
				for(l=0; l<col_num; l++){
					//for making the diagonal element 1
					arr[k][l] /= diagonal_element;
					div++;
				}
					
				
				for(k=0; k<row_num; k++){
					//setting flag = the element on respective row which is exactly below the concerned diagonal element
					flag = arr[ k ][ j ];
										
					for(l=0; l<col_num; l++)
						if(k != i){
							//performing row operation to male all the elements = 0, except diagonal element 
							arr[k][l]= (arr[k][l]) - flag * (arr[i][l]);
							mul++;
							sub++;
						}
							
				}	
			}
		}
		cout<<"Step:\t"<<step<<endl;
		printMatrix(arr);
		step++;
	}
	//printing result
	for(i=0;i<row_num;i++)
		cout<<arr[i][col_num-1]<<endl;
		cout<<"\nTotal number of"<<endl;
		cout<<"addition ="<<add<<"  subtraction ="<<sub<<"  multiplication ="<<mul<<"  division ="<<div<<endl;
}

//function for partial pivoting 
void partially_pivot(float arr[][10], int pivot_row, int pivot_col){
	float temp;
	int i,large_pivot_row = pivot_row;
	
	for(i=pivot_row; i<row_num ; i++){
		//to find greatest among the pivot column column
		if(arr[i][pivot_col]>arr[large_pivot_row][pivot_col]){
			 large_pivot_row = i;
		}
	}
	
	if(pivot_row != large_pivot_row){
		//to interchange the rows
		for(i=0; i<col_num; i++){
			temp = arr[large_pivot_row][i];
			arr[large_pivot_row][i] = arr[pivot_row][i];
			arr[pivot_row][i] = temp;
		}
	}
}

//function for printing the matrix
void printMatrix(float arr[][10]){
	int i,j;
	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			cout<< arr[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}	
	cout<<endl;
}
