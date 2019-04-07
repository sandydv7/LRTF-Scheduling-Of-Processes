// LRTF Algorithm When All Process Arrive at same time 


#include<stdio.h>
#include<stdlib.h>

// Global Variables

int TOTAL_TIME = 0; 
int PRE_TOTAL = 0;

struct Process { 
    int ProcessNo; 
    int ProcessID;
    int ArrivalTime; 
    int BurstTime; 
    int InitAT;
    int InitBT; 
    int WaitingTime; 
    int TurnAroundTime; 
    int CompletionTime; 
};


// Used functions in this Program
int Max_Burst(struct Process[], int x, int y);

int ExcutionOFProcesses(struct Process[] ,int);


// sort Processes As per Their Process's ID 
int comparator(const void *p, const void *q)  
{ 
    int l = ((struct Process *)p)->ProcessID; 
    int r = ((struct Process *)q)->ProcessID;  
    return (l - r); 
}
int main() 
{ 
	
  	printf("\n\n Enter the Number of Processes ::");
  	
    int var_i;
	int number_of_processes;
	
	scanf("%d",&number_of_processes); 
	
	struct Process Prr_Arr[number_of_processes];
	
	for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
    	
    	Prr_Arr[var_i].ProcessNo=var_i+1; 
    	
    }
 
    for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
    	
    	printf("\n\n\tEnter the %dth Process ID::",var_i+1);
    	scanf("%d",&Prr_Arr[var_i].ProcessID); 
    	
    	Prr_Arr[var_i].ArrivalTime =0;
        Prr_Arr[var_i].InitAT=Prr_Arr[var_i].ArrivalTime;	
        
        printf("\tEnter the %dth Proccess Burst Time::",var_i+1);
        scanf("%d",&Prr_Arr[var_i].BurstTime);
        Prr_Arr[var_i].InitBT = Prr_Arr[var_i].BurstTime; 
        PRE_TOTAL += Prr_Arr[var_i].BurstTime;
        
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
  
    
    TOTAL_TIME += Prr_Arr[0].ArrivalTime; 
  
   
    PRE_TOTAL += Prr_Arr[0].ArrivalTime; 
    ExcutionOFProcesses(Prr_Arr,number_of_processes); 
    int totalWT = 0; 
    int totalTAT = 0; 
    for (var_i = 0; var_i < number_of_processes; var_i++) { 
        
		 
        Prr_Arr[var_i].TurnAroundTime = Prr_Arr[var_i].CompletionTime - Prr_Arr[var_i].InitAT; 
        Prr_Arr[var_i].WaitingTime = Prr_Arr[var_i].TurnAroundTime - Prr_Arr[var_i].InitBT; 
  
       
        totalWT += Prr_Arr[var_i].WaitingTime; 
  
       
        totalTAT += Prr_Arr[var_i].TurnAroundTime; 
    } 
    
    printf ("\n\n\t\tResult of Execution ... \n\n"); 
  
    
    printf("\t\tPNo\tProcessID\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\n"); 
  
    for (var_i = 0; var_i < number_of_processes; var_i++) 
	{ 
        printf("\t\t%d",Prr_Arr[var_i].ProcessNo); 
        printf("\t%d", Prr_Arr[var_i].ProcessID);
        printf("\t\t",Prr_Arr[var_i].InitAT); 
        printf("\t\t%d\t\t",Prr_Arr[var_i].InitBT); 
        
        printf("%d\t\t",Prr_Arr[var_i].CompletionTime);
        printf("%d\t\t",Prr_Arr[var_i].TurnAroundTime); 
        printf("%d\t",Prr_Arr[var_i].WaitingTime ); 
        printf("\n");
    } 
  
    printf("\n");
    printf("\n\n\t\tTotal TAT     ::  %d\n",totalTAT); 
    printf("\t\tAverage TAT   ::  %f\n",(float)totalTAT / (number_of_processes)); 
    printf("\t\tTotal WT      ::  %d\n",totalWT); 
    printf("\t\tAverage WT    ::  %f\n",(float)totalWT /(number_of_processes)); 
    return 0; 
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
    while (TOTAL_TIME != PRE_TOTAL) { 
        index = Max_Burst(P,i,number_p); 
        printf("\n\n\tProcess executing at time %d is : P%d\t",TOTAL_TIME,P[index].ProcessNo);
  
        --P[index].BurstTime; 
        ++TOTAL_TIME ;
        
        
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
            P[index].CompletionTime = TOTAL_TIME; 
            printf("\t\tProcess P%d has been completed at %d",P[index].ProcessNo ,TOTAL_TIME); 
        } 
        printf("\n"); 
  
        if (TOTAL_TIME == PRE_TOTAL) 
            break;
    } 
} 

   
