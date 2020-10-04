#include<stdio.h>
#include<conio.h>
int subsition_back(float mat[20][20],float x[20], int m, int n)
{
	int i,j,k;
	/* Obtaining solution_func by Back Subsitution */
	
	int flag_check_infi=0,iterator_j,temporary_count=0,free_variable1=0,motii=0,override_count=0;
	int flag_check_no_solu=0;
	printf("\n");
	printf("\n****************************************************************************\n");
	printf("The system of equation has:\n");
	for(i=1; i<=m; i++) 
	{
		for(j=1; j<=n+1; j++) 
		{
		//	cout << mat[i][j] << " ";
		}
		//cout << endl;
	}
	for(i=m;i>=1;i--)
	{
		temporary_count=0;
		motii=0;
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]!=0 && (x[j]==8.0 || x[j]==217) )
			{
				temporary_count++;
			}
		}
		
	//	cout << temporary_count << endl;
		if(temporary_count==0)
		{
			if(mat[i][n+1]!=0 )
			{
			//	cout<<i<<"\n";
			//	printf("No solution ");
//			printf("No solution\n");
//			printf("The null space consist of singleton 0\n");
				flag_check_no_solu=1;
	//			exit(0);
			}
			else
			{
				continue;
			}
		}
		else
		{
			if(temporary_count==1)
			{
				override_count=0;
				int index_1=-1,index_2=-1;
				for(j=1;j<=n;j++)
				{
					if(x[j]!=8.0)
					{
						mat[i][n+1]=mat[i][n+1]-(mat[i][j]*x[j]);
					}
				}
				
				for(j=1; j<=n; j++)
				{
					if(mat[i][j]!=0 && x[j]==8.0 && x[j]!=217 )
						x[j]=mat[i][n+1]/mat[i][j];
					else
						override_count++;
					
				}
				if(override_count==n)
				{
					for(j=n; j>=1; j--)
					{
						if(mat[i][j]!=0)
						{
							index_1=j;
							break;
						}	
						
					}
					for(j=n; j>=1; j--)
					{
						if(mat[i+1][j]!=0)
						{
							index_2=j;
							break;
						}	
						
					}
					if(index_1==index_2)
					{
						if( (mat[i][n+1]/mat[i][index_1]) != (mat[i+1][n+1]/mat[i+1][index_2]) )
						{
						//	cout<<"No solution '' \n";
							flag_check_no_solu=1;
//							printf("No solution\n");
//							printf("The null space consist of singleton 0\n");
//							exit(0);
						}
					}
					else
						continue;
				}
			}
			else
			{
				override_count=0;
				int index_1=-1,index_2=-1;
				for(j=1;j<=n;j++)
				{
					if(x[j]!=8.0)
					{
						mat[i][n+1]=mat[i][n+1]-(mat[i][j]*x[j]);
					}
				}
				
				flag_check_infi=1;
				free_variable1 = free_variable1+ temporary_count-1;
				for(j=1;j<=n;j++)
				{
					if(motii==(temporary_count-1))
					{
						break;
					}
					if(mat[i][j]!=0 && x[j]==8.0 && x[j]!=217)
					{
						x[j]=217;
						//cout << x[j] << " "<<j<<"x[j] ";  
						mat[i][n+1]=mat[i][n+1]-mat[i][j]*x[j];
						motii++;
					}
					else
						override_count++;
				}
				//ovverride logic
				if(override_count==n)
				{
					for(j=n; j>=1; j--)
					{
						if(mat[i][j]!=0)
						{
							index_1=j;
							break;
						}	
						
					}
					for(j=n; j>=1; j--)
					{
						if(mat[i+1][j]!=0)
						{
							index_2=j;
							break;
						}	
						
					}
					if(index_1==index_2)
					{
						if( (mat[i][n+1]/mat[i][index_1]) != (mat[i+1][n+1]/mat[i+1][index_2]) )
						{
							//cout<<"No solution '' \n";
						//	printf("No solution\n");
						//	printf("The null space consist of singleton 0\n");
							flag_check_no_solu=1;
						//	exit(0);
						}
					}
					else
						continue;					
				}	
				//printf("\n");
				for(iterator_j=j;iterator_j<=n;iterator_j++)
				{
					if(mat[i][iterator_j]!=0 && x[iterator_j] == 8.0)
					{
						x[iterator_j]=mat[i][n+1]/mat[i][iterator_j];
					}
				}
			}
		}
	}
	
	int infi_flag=0;
	for(i=1;i<=n;i++)
	{
		if(x[i] == 8.0 || x[i]-(float)217 == 0)
		{
			infi_flag=1;
		}
	}
	//printf("\n");
	if(flag_check_no_solu==1)
	{
		printf("no solution");
		printf("\n****************************************************************************\n");
	//	printf("The null space consist of singleton 0\n");
		return 0;
	}
	else
	{
		if(infi_flag==0)
		{
			printf("unique solution\n");
			printf("****************************************************************************");
			printf("\nThe null space is singleton zero");
			printf("\n****************************************************************************\n");
			
		}
			
		else
		{
			printf("infinite solution");
			printf("\n****************************************************************************\n");
			printf("\n******particular solution*******");
		}
			
		solution_func(mat,x,m,n);
	}
}
