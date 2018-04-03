#include<unistd.h>
#include<stdio.h>
#include<stdbool.h>


struct process
{
	int en,bt,at,ct;
	
};

int main()
{   
 int n,n1,gpr,tts=0,tt=0,nps=0,npt=0,y;
 printf("Enter no. of process For students\n\n");
 scanf("%d",&n);
          
 printf("Enter no. of process For Teachers\n\n");
 scanf("%d",&n1);
 int RSqueue[n],rears=0,fronts=0,RTqueue[n1],reart=0,frontt=0;
 struct process S[n],T[n1];	
 int i,j,k,l;	
 int bts=0,btt=0; 

for(i=0;i<n;i++)	
{ printf("Enter details for Student %d's Query \n Arrival time (B/w 10am to 12am in Mins.)-",i+1); 
  scanf("%d",&S[i].at);
  
  printf("\n Burst time-");
  scanf("%d",&S[i].bt);
  bts+=S[i].bt;
  S[i].en=0;
  S[i].ct=0;
}
for(i=0;i<n1;i++)	
{ printf("Enter details for Faculty %d's Query \n Arrival time (B/w 10am to 12am in Mins.)-",i+1); 
  scanf("%d",&T[i].at);
  
  printf("\n Burst time-");
  scanf("%d",&T[i].bt);
  btt+=T[i].bt;
  T[i].en=0;
  T[i].ct=0;
}
int SortQS[n],z=0,SortQT[n1],z1=0;
for(j=0;j<120;j++)	
{ 

      
      for(i=0;i<n;i++)             //Queue for Student's Requests	
         { 
		   if(S[i].at==j)
		    { 
			  SortQS[z]=i;
			  z++;
			  nps++;
			  
		    }
		 }
		 
      for(i=0;i<n1;i++)             //Queue for Faculty's Requests	
         {    
		   if(T[i].at==j)
		    { 
			  npt++;
			  SortQT[z1]=i;
		      z1++;
			}
		 }

if(nps>=1 && (tts<=tt || npt==0) &&tts<=60 )                                                   //for student's queue
{                                                  
 for(k=0;k<z-1;k++)                             //Sorting For Queries which are least Executed
    {   
    
   
     for(y=0;y<z-k;y++) 
    {  
	   if(S[SortQS[k]].en>S[SortQS[y]].en)
	    { 
		int temp;	  
		 temp= SortQS[k]; 
		 SortQS[k]=SortQS[y];
		 SortQS[y]=temp;	
		
       
		}
    }

    
	
	}
  

int a=-1;

for(k=0;k<z;k++)
{ 
   if(S[SortQS[k]].bt!=0)
   {  
    a=SortQS[k];
     break;    
   }

}



printf("\nStudent %d's Query Executed from %d to %d \n\n",a+1,j,j+1);
S[a].bt--;
S[a].en++;
tts++;

if(S[a].bt==0)
{
printf("\n Student's Process %d Ends \n\n",a+1,j,j+1);
nps--;
S[a].ct=j+1;
}

  
}

else if(npt>=1 && (tt<=tts || nps==0) &&tt<=60 )                               //For Faculty's Queue
{ 
  
   for(k=0;k<z1-1;k++)                             //Sorting For Queries which are least Executed
  {   
    
     for(y=0;y<z1-k;y++) 
    {   
			  
	   if(T[SortQT[k]].en>T[SortQT[y]].en)
	    { 
			  
		 int temp;
	     temp= SortQT[k];
		 SortQT[k]=SortQT[y];
		 SortQT[y]=temp;	
		}
    }
  
     }
  


int aa=-1;
for(k=0;k<z1;k++)
{  
   if(T[SortQT[k]].bt!=0)
   { 
			  
    aa=SortQT[k];
     break;    
   }

}



printf("Faculty %d's Query Executed from %d to %d \n\n",aa+1,j,j+1);
T[aa].bt--;
T[aa].en++;
tt++;
if(T[aa].bt==0)
{
printf("Faculty's Process %d Ends \n\n",aa+1,j,j+1);
npt--;
T[aa].ct=j+1;
}

}

}

printf("\nTotal time spent on queries is %d Minutes \n",tt+tts);

printf("\nAverage Query time is %d Minutes \n",(tt+tts));

}








