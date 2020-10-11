//Gauss elimination for solving LPP
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

void printMatrix(float arr[][10],int);

int main()
{
    int n,i,j,k,temp,add=0,sub=0,mul=0,div=0;
    float arr[10][10],c,result[10]={0};
    cout<<"Enter no of equation\t";
    cin>>n;
    cout<<"Coefficient of all : \n";
    for(i=0;i<n;i++)
    {
        cout<<"equation: "<<i+1<< "   ";
        for(j=0;j<=n;j++)
            cin>>arr[i][j];
    }
    
    for(i=n-1;i>0;i--)        // partial pivoting
    {
        if(arr[i-1][0]<arr[i][0])
            for(j=0;j<=n;j++)
            {
                c=arr[i][j];
                arr[i][j]=arr[i-1][j];
                arr[i-1][j]=c;
            }
    }
    
    //display matrix
    printMatrix(arr,n);
    
    //Forward elimination, changing to upper triangular matrix
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++)
        {
            c= (arr[i+1][k]/arr[k][k]) ;
            div++;
            
            for(j=0;j<=n;j++){
            	arr[i+1][j]-=c*arr[k][j];
            	sub++;
            	mul++;
			}
                
        }

     //displaying upper triangular matrix

    printf("\n\n");
    printMatrix(arr,n);
    
    //Backward Substitution method

    for(i=n-1;i>=0;i--)
    {
        c=0;
        for(j=i;j<=n-1;j++){
        	c=c+arr[i][j]*result[j];
        	add++;
        	mul++;
		}
            
            
        result[i]=(arr[i][n]-c)/arr[i][i];
        div++;
    }
    //displaying result
    for(i=0;i<n;i++)
    cout<<result[i]<<endl;
    cout<<"\nTotal number of"<<endl;
	cout<<"addition ="<<add<<"  subtraction ="<<sub<<"  multiplication ="<<mul<<"  division ="<<div<<endl;
    
    getch();
    return 0;
}

//function for displaying matrix
void printMatrix(float arr[][10], int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n+1; j++){
			cout<< arr[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}	
	cout<<endl;
}
