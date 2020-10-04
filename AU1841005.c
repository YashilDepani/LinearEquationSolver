#include<stdio.h>
//#include<bits/stdc++.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include "swaping2_rows.h"
#include "subsition_back.h"
//using namespace std;
//declaring global variables

int i,j,k,m,n,binary_pivot[20], cpy_binary_pivot[20];
// 2d matrix
float mat[20][20] ;
float cpy[20][20], nullspace_identity[20][20], null_space_rref[20][20];

//initailizing the answer
float x[20]= {8.0};

//index of columns to be swaped
int idx_column_swap[3][20] ;

//functions
void swaping2_rows(float mat[20][20], int r1, int rowlength, int r2);
void solution_func(float mat[20][20],float x[20], int m, int n);
void null_space(float mat[20][20],int m,int n,int swp[20][20],int binary_pivot[20], int no_free_variable);
int gauss(float mat[20][20],int m, int n,float cpy[20][20], int no_free_variable);
int subsition_back(float mat[20][20],float x[20], int m, int n);



void getDetails()
{
	printf("Enter no. of rows and columns for matrix:\n");
	int m,n;
	scanf("%d %d",&m,&n);

	printf("Enter Augmented matrix:\n");
	for(i=1; i<=m; i++) 
	{
		for(j=1; j<=n+1; j++) 
		{
			scanf("%f",&mat[i][j]);
			cpy[i][j] = 0 ;
		}
	}
	int no_free_variable=0;
	null_space(mat,m,n,idx_column_swap,cpy_binary_pivot,gauss(mat,m,n,cpy,no_free_variable));
}
void null_space(float mat[20][20],int m,int n,int swp[3][20],int cpy_binary_pivot[20], int no_free_variable)
{
	int cnt_of_non_pivot=0;
	for(i=1; i<=n; i++)
	{
		if(cpy_binary_pivot[i]==0)
			cnt_of_non_pivot++;
	}
		
	int size = cnt_of_non_pivot;
	int temporary1=0;
	for(i=1; i<=size; i++)
	{
		for(j=1; j<=size; j++)
		{
			if(i==j)
			
				nullspace_identity[i][j]=1;
			else
				nullspace_identity[i][j]=0;
				//cout<<nullspace_identity[i][j]<<" ";
		}
	//	cout<<"\n";
		
	}
		

	temporary1=0;
	for(i=1; i<=n-no_free_variable; i++) 
	{
		temporary1=1;
		for(j=1; j<=n; j++)
		 {
			if(cpy_binary_pivot[j]==0) 
			{
				//cout<<"-->"<<-mat[i][j]<<" i = "<<i<<" j ="<<j<<"\n";
				null_space_rref[i][temporary1++]=-mat[i][j];
			}
		}
	}
	for(i=1; i<=size; i++) 
	{
		for(j=1; j<=size; j++) 
		{
			null_space_rref[n-no_free_variable+i][j]=nullspace_identity[i][j];
		}
	}
//	printf("%d\n",no_free_variable);
//	cout<<"no_free_variable = "<<no_free_variable<<endl;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=no_free_variable; j++)
		{
		//	cout<<null_space_rref[i][j]<<"\t";
			if(null_space_rref[i][j]==-0)
				null_space_rref[i][j]=0;
		}	
	//	cout<<"\n";
	}
	int zero_counter=0, flag=0;
	int sss=0,  hh1=0, kk=0,hh;
	for(hh1=1; hh1<n; hh1++)
	{
		sss=0;
		for(hh=hh1; hh<=n; hh++)
		{
			for(kk=1; kk<=no_free_variable; kk++)
			{
				if(null_space_rref[hh][kk]==0)
					sss++;
			}
			if(sss==no_free_variable)
			{
				swaping2_rows(null_space_rref,hh,no_free_variable,hh+1);
			}
		}
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=no_free_variable; j++)
		{
			//	cout<<null_space_rref[i][j]<<"\t";
			
		}
	//	cout<<"\n";
		
	}
	for(i=1; i<=n-no_free_variable; i++)
	{
		int row111 = swp[1][i];
		int row222 = swp[2][i];
		swaping2_rows(null_space_rref,row111,no_free_variable,row222);
	}
	printf("\n");
	printf("\n*****************************************\n");
	printf("                NULL SPACE\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=no_free_variable; j++)
			printf("%f\t",null_space_rref[i][j]);
			//cout<<null_space_rref[i][j]<<"\t";
		printf("\n");
	}
	printf("*******************************************\n");
}
int gauss(float mat[20][20],int m, int n,float cpy[20][20], int no_free_variable)
{
	int jjj=0;
	float ratio;
	for(i=0; i<=20; i++)
		binary_pivot[i]=0;
		
	int cnt_ridh=0;
	
	
	/* gaussain elemination */
	
	
	
	int row_pivot=0,column_pivot=0;
	while(1) 
	{
		column_pivot++;
		row_pivot++;
		int flagb=0;
gooo:

		if(column_pivot>n || row_pivot>m)
			break;
		
		if(mat[row_pivot][column_pivot] == 0.0) 
		{

			for(j=row_pivot; j<=m; j++) 
			{
				if(mat[j][column_pivot]!=0) 
				{
					flagb=1;
					swaping2_rows(mat,row_pivot,n+1,j);
					break;
				}
			}
		}
		if(flagb==0 && mat[row_pivot][column_pivot]==0.0)
		{
			column_pivot++;
			goto gooo;
		}
		binary_pivot[column_pivot]++;
		for(jjj=1; jjj<=m; jjj++) 
		{
			if(jjj==row_pivot) 
			{
				continue;
			}
			else
			{
				ratio = mat[jjj][column_pivot]/mat[row_pivot][column_pivot];
				for(k=1; k<=n+1; k++) 
				{
					mat[jjj][k] = mat[jjj][k] - ratio*mat[row_pivot][k];
				}
			}
		}
		for(k=1; k<=n+1; k++)
		{
			if(k==column_pivot)
				continue;
			mat[row_pivot][k] /= mat[row_pivot][column_pivot];
		}
		mat[row_pivot][column_pivot]=1;
		//printf("\n");
	}
	for(k=1; k<=n; k++)
	{
		cpy_binary_pivot[k]=binary_pivot[k];
		if(binary_pivot[k]==0)
			no_free_variable++;
	}
		
	
	int rank_of_mat = 0;
	for(k=1; k<=n; k++)
	{
		rank_of_mat = rank_of_mat + binary_pivot[k] ;
	}
	int non_pivot = n - rank_of_mat ;
	printf("\n\n****************************************************************************\n");
	printf("The rank of the matrix is :%d\n",rank_of_mat);
	printf("****************************************************************************\n");
	//cout<<"rank_of_mat "<<rank_of_mat<<endl;
	
	for(i=1; i<3; i++)
	{
		for(j=1; j<=rank_of_mat; j++) 
		{
			idx_column_swap[i][j] = 1 ;
		}
	}
	printf("\n");
	int v =  0, w =  0 ,prv0 = 0 ,tmpo = 1 ;
	for(i=1; i<=non_pivot; i++) 
	{
		if(binary_pivot[i]==0) 
		{
			for(j=i+1; j<=n; j++) 
			{
				if(binary_pivot[j]==1)
				 {
					idx_column_swap[1][tmpo]=j;
					idx_column_swap[2][tmpo]=i;
					tmpo++;
					binary_pivot[j]=0;
					binary_pivot[i]=1;
					break;
				}
			}
		}
	}
	for(i=1; i<tmpo; i++) 
	{
		for(j=1; j<3; j++) 
		{
		//	cout << idx_column_swap[j][i] << "\t" ;
		}
	//	cout << endl;
	}
	printf("\n");

	printf("****************************************************************************\n");
	printf("RREF of the given Matrix is:\n");
	for(i = 1 ; i < m+1 ; i++)
	{
		for(j  = 1 ; j <= n+1 ; j ++ ) 
		{
			if(mat[i][j]==-0)
				mat[i][j]=0;
			printf("%f\t",mat[i][j]);
			//cout << mat[i][j] << "\t" ;
		}
		printf("\n");
	//	cout << "\n" ;
	}
	printf("****************************************************************************\n");
	// rref of given matrix has occured!

	for(i=1; i<=n; i++)
		x[i]=8.0;
	subsition_back(mat,x,m,n);
	return no_free_variable;
}
void solution_func(float mat[20][20], float x[20],int m, int n) 
{
	printf("\n****************************************************************************\n");
	int free_yas=0;
	printf("Solution:\n");
	for(i=1; i<=n; i++)
	{
		if(x[i]!=8.0)
			printf("x[%d] = %f\n",i, x[i]);
		else
		{
			x[i]=217;
			printf("x[%d] = %f\n",i, x[i]);
		}
		if(x[i]==217)
			free_yas++;
	}
	printf("****************************************************************************\n");
	printf("Number of free variables (nullity) = %d\n",free_yas);
	
	
	if(free_yas==0)
	{
		printf("The given solution is the unique solution\n");
		printf("****************************************************************************\n");
		exit(0);
	}
	else
	{
	//	printf("The given solution is particular solution\n");
		printf("****************************************************************************\n");
	}
		
}
int main() 
{
	getDetails();
	return 0;
}

/*
1 -2 2 3 -1 0
-3 6 -1 1 -7 0
2 -4 5 8 -4 0

*/
/*

	-3 6 -1 1 -7 5
	1 -2 2 3 2.33 6
	2 -4 5 8 -4 11

	*/
