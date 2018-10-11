#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int status;
    int a[1000];
    
    for(int i=0;i<1000;i++)
    {
        a[i]=i+1;
    }
    int pid=fork();
    if(pid==0)
    {
        for(int j=0;j<100;j++)
        {
            status = status+a[j];
        }
    }
    else
    {
        pid=fork();
        if(pid==0)
        {
            for(int j=100;j<200;j++)
			{
                status = status+a[j];
            }
        }
        else
        {
            pid=fork();
            if(pid==0)
            {
                for(int j=200;j<300;j++){
                	
                    status = status+a[j];
                }
            }
            else
            {
                pid=fork();
                if(pid==0)
                {   
                    for(int j=300;j<400;j++)
					{
                        status = status+a[j];
                    }
            
                }
                else
                    {
                        pid=fork();
                        if (pid == 0)
						{
                             for(int j=400;j<500;j++){
                             status = status+a[j];
                        }
                        }
                        else
						{
                            pid = fork();
                            if(pid == 0)
							{
                                 for(int j=500;j<600;j++)
                                {
                                	 status = status+a[j];
                                 }        
                            }
                            else
							{
                                pid = fork();
                                if(pid == 0){
                                     for(int j=600;j<700;j++){
            							 status = status+a[j];
                                    }
                                }
                                else
								{
                                     if(pid==0)
                                     {
                                         for(int j=700;j<800;j++)
                                         {
            								status = status+a[j];
                                         }
                                     }
                                     else
									 {
                                          if(pid==0)
                                          {
                                              for(int j=800;j<900;j++)
                                              {
            									status = status+a[j];
                                            }
                                          }
                                          else
										  {
                                               if(pid==0)
                                                {
                                                for(int j=900;j<1000;j++)
                                                  {
            											status = status+a[j];
                                                  }
                                                 }
                                            }
                                        }
                                    }
                                    
                                }
                            }
                        }
                    }
    
                }
    int sum1=wait(&status);
    int sum2=wait(&status);
    int sum3=wait(&status);
    int sum4=wait(&status);
    int sum5=wait(&status);
    int sum6=wait(&status);
    int sum7=wait(&status);
	int sum8=wait(&status);
	int sum9=wait(&status);
	int sum10=wait(&status);
	int sum = sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10;
	printf("sum",sum);
    }
    return 0;
}

