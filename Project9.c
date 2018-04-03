#include<unistd.h>
#include<stdio.h>
#include<stdbool.h>
front=0;
rear=0;
int enqueue(int size)
{


if((rear==size && front==1)||(front==rear+1))
{
	
	return 0;
}
else if(front==0)
{
 front++;
 rear++;
}
else if(rear==size)
{
	rear=1;
}
else
{
rear=rear+1;	
}

return rear;

}


struct process
{
	int p,en,bt,at,ct,bbt;
	
};

int main()
{ 
 printf("Enter no. of process\n\n");
 int n,gpr,tt=0;
 
 bool w=true;             
 scanf("%d",&n);
 int Rqueue[n],EqualS[n];
 struct process S[n];	
int i,j,l;	
for(i=0;i<n;i++)	
{
  printf("Enter details for process %d \n Arrival time-",i+1);
  scanf("%d",&S[i].at);
  
  printf("\n Burst time-");
  scanf("%d",&S[i].bt);
  S[i].p=0;
  S[i].en=0;
  S[i].bbt=S[i].bt;	
  S[i].ct=0;
}
j=0;                  //Treated as time;



while(w)
{
for(i=0;i<n;i++)             //Assigning process in a Ready Queue on the basis of arrival time 
{
	
	if(S[i].at==j)
	{   enqueue(n);
		Rqueue[rear]=i;
	 
	
	}


}
gpr=0;
                        
for(i=front;i<=rear;i++)                         //Finding Greatest Priority
{  if(S[Rqueue[i]].p>S[gpr].p)
	{   
	  gpr=Rqueue[i];
	  
	}
}
int k=0;
EqualS[k]=gpr;

for(i=front;i<=rear;i++)                         //Finding process with equal Priority
{  if(gpr!=Rqueue[i])
   {
	 if(S[Rqueue[i]].p==S[gpr].p)
	{k++;   
	  EqualS[k]=Rqueue[i];  
	}
  }
}


for(l=0;l<=k;l++)                         //Sorting according to Burst time
{  
  for(i=0;i<=k;i++)
  {if(S[EqualS[l]].bt>S[EqualS[i]].bt)
	  { int temp;
 
        temp= EqualS[i]	;
		EqualS[i] =EqualS[l];
		EqualS[l] = temp; 
      
 	  
	  }
    
}
}

for(l=0;l<=k;l++)                         //Sorting for equal burst time
{  
  
    if(S[EqualS[l]].en==0)
   { 
   	  int temp;
        temp= EqualS[0]	;
		EqualS[0] =EqualS[l];
		EqualS[l] = temp;
   	
	   }    

}






i=EqualS[0];

printf("Process %d Executed from %d to %d \n\n",i+1,j,j+1);
S[i].bt--;
S[i].en++;

if(S[i].bt==0)
{
printf("Process %d Ends \n\n",i+1,j,j+1);
tt++;
S[i].p=-1;
S[i].ct=j+1;
}
else
{
S[i].p++;
}

for(l=front;l<=rear;l++)                        
{  
    if(S[Rqueue[l]].en==0)
	{	   
	  S[Rqueue[l]].p+=2;
	 
	}
	
}


if(tt==n)
{
w=false;
}

j++;
}
int sum=0;
for(i=0;i<n;i++)

{
	
sum=sum+((S[i].ct-S[i].at)-S[i].bbt);
printf("\nWaiting time for process %d is %d ",i+1,((S[i].ct-S[i].at)-S[i].bbt));
}
printf("\nAverage Waiting time is %d ",sum/n);
}
