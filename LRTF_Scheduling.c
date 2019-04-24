// LRTF Algorithm When All Process Arrive at same time 


#include<stdio.h>
#include<stdlib.h>

struct Process { 
    int ProcessNo; 
    int ProcessID;
    int ArrivalTime; 
    int BurstTime; 
    int InitAT;
    int InitBT; 
    int WaitingTime; 
    int TurnAroundTime;
};

// Used functions in this Program
int Max_Burst(struct Process[], int x, int y);

int ExcutionOFProcesses(struct Process[] ,int k);


// sort Processes As per Their Process's ID 
int comparator(const void *p, const void *q)  
{ 
    int l = ((struct Process *)p)->ProcessID; 
    int r = ((struct Process *)q)->ProcessID;  
    return (l - r); 
}
int inTotal = 0; 
int fiTotal = 0;

void main() 
{ 
	
  	printf("\n\n Enter the Number of Processes ::");
  	
    int var_i;
	int number_of_processes;
	
	scanf("%d",&number_of_processes); 
	
	struct Process Prr_Arr[number_of_processes];
	 
    for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
    	
    	Prr_Arr[var_i].ProcessNo=var_i+1;
    	
    	printf("\n\n\tEnter the %dth Process ID::",var_i+1);
    	scanf("%d",&Prr_Arr[var_i].ProcessID); 
    	
    	while(1){
    		if(Prr_Arr[var_i].ProcessID<0){
    		printf("\nProcess ID Can't be Negative.. Enter Again::");
    		scanf("%d",&Prr_Arr[var_i].ProcessID); 
			}
			else{
				break;
			}
		}
    	
    	Prr_Arr[var_i].ArrivalTime =0;
        Prr_Arr[var_i].InitAT=Prr_Arr[var_i].ArrivalTime;	
        
        printf("\tEnter the %dth Proccess Burst Time::",var_i+1);
        scanf("%d",&Prr_Arr[var_i].BurstTime);
        
        while(1){
    		if(Prr_Arr[var_i].BurstTime<0){
    		printf("\nProcess Burst Time Can't be Negative.. Enter Again::");
    		scanf("%d",&Prr_Arr[var_i].BurstTime); 
			}
			else{
				break;
			}
		}
        Prr_Arr[var_i].InitBT = Prr_Arr[var_i].BurstTime; 
        fiTotal += Prr_Arr[var_i].BurstTime;
        
        //cout<<endl<<endl;
        
    } 
    printf("\n\n\t\tInitial Table...\n\n");
    printf("\t\tPNo\t\t\tProcessID\t\tArrivalTime\t\tBurstTime\n"); 
  
    for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
        printf("\t\t%d\t",Prr_Arr[var_i].ProcessNo); 
        
        printf("\t\t%d\t",Prr_Arr[var_i].ProcessID);
        
        printf("\t\t%d\t",Prr_Arr[var_i].ArrivalTime); 
        
        printf("\t\t%d\t",Prr_Arr[var_i].BurstTime); 
        
        printf("\n"); 
    } 
    printf("\n"); 
  
   	int size;
   	size=sizeof(Prr_Arr)/sizeof(Prr_Arr[0]);
   	
    qsort((void*)Prr_Arr, size, sizeof(Prr_Arr[0]), comparator); 
    
    ExcutionOFProcesses(Prr_Arr,number_of_processes); 
    
    int TOT_WT = 0; 
    int TOT_TAT = 0; 
    for (var_i = 0; var_i < number_of_processes; var_i++) { 
        
		 
        Prr_Arr[var_i].TurnAroundTime = Prr_Arr[var_i].TurnAroundTime - Prr_Arr[var_i].InitAT; 
        Prr_Arr[var_i].WaitingTime = Prr_Arr[var_i].TurnAroundTime - Prr_Arr[var_i].InitBT; 
  
       
        TOT_WT += Prr_Arr[var_i].WaitingTime; 
  
       
        TOT_TAT += Prr_Arr[var_i].TurnAroundTime; 
    } 
    
    printf ("\n\n\t\tResult of Execution ... \n\n"); 
  
    
    printf("\t\tPNo\tProcessID\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\n"); 
  
    for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
        printf("\t\t%d",Prr_Arr[var_i].ProcessNo); 

        printf("\t%d", Prr_Arr[var_i].ProcessID);

        printf("\t\t%d",Prr_Arr[var_i].InitAT); 

        printf("\t\t%d\t\t",Prr_Arr[var_i].InitBT); 
        
        printf("%d\t",Prr_Arr[var_i].WaitingTime ); 

        printf("\t%d",Prr_Arr[var_i].TurnAroundTime);         
        printf("\n");
    } 
    printf("\n");
    printf("\n\n\t\tTotal WatingTime      ::  %d\n",TOT_WT); 
    printf("\t\tAverage WatingTime    ::  %f\n",(float)TOT_WT /(number_of_processes));
    printf("\t\tTotal TurnAroundTime     ::  %d\n",TOT_TAT); 
    printf("\t\tAverage TurnAroundTime   ::  %f\n",(float)TOT_TAT / (number_of_processes)); 
     
    
} 

//defination of Used functions

//find maximum Bursts
int Max_Burst(struct Process P[],int at,int number_p) 
{ 
    int max = 0;
	int i;
	int max_burst; 
    max_burst=P[0].BurstTime;
    for (i = 0; i < number_p; i++) 
	{ 
            if (P[i].BurstTime > max_burst) 
			{
            	max = i;
            	max_burst=P[i].BurstTime;
            }
    } 
    
    return max;
}

//process running status

int ExcutionOFProcesses(struct Process P[],int number_p) 
{ 
  
	
    int index;  
    int k;
    int j;
    int i = P[0].ArrivalTime; 
    while (inTotal != fiTotal) { 
        index = Max_Burst(P,i,number_p); 
        printf("\n\n\tProcess executing at time %d is : P%d\t",inTotal,P[index].ProcessNo);
  
        --P[index].BurstTime; 
        ++inTotal ;
        
        
        for (j=0;j<number_p;j++)
		{
        		if(P[j].ArrivalTime<=i)
				{
        			P[j].ArrivalTime+=1;
				}
		}
		
		printf("\n\tPNo\tProcessID\tCurentTime\tRequiresBurst\n");
		
		for (k = 0; k < number_p; k++) 
		{ 
        	printf("\t%d\t",P[k].ProcessNo); 
        	printf(" %d\t\t",P[k].ProcessID);
        	printf("%d\t\t",P[k].ArrivalTime);
        	printf("%d\t\t",P[k].BurstTime);
        	printf("\n");
   		} 
    	printf("\n"); 
        i++; 
        if (P[index].BurstTime == 0) { 
            P[index].TurnAroundTime = inTotal; 
            printf("\t\tProcess P%d has been completed at %d",P[index].ProcessNo ,inTotal); 
        } 
        printf("\n"); 
  
        if (inTotal == fiTotal) 
            break;
    } 
} 
