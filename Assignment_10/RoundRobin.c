#include<stdio.h>

#define MAX 100

typedef struct Job{
	int Id,Include,AT,BT,CT,TAT,WT;
}Job;

typedef struct ReadyQueue{
	Job arr[9999999];
	int front,rear;
}ReadyQueue;

Job Job_Array[MAX];

ReadyQueue Q;


void Add_to_Q(Job J){
	if(Q.front==-1){
		Q.front=0;
		Q.rear=0;
		Q.arr[Q.rear]=J;
	}
	else{
		Q.rear++;
		Q.arr[Q.rear]=J;
	}
}

Job Pop_from_Q(){
	return Q.arr[Q.front++];
}



void Get_Jobs(int Time,int N){
	int i=0;
	for(i=0;i<N;i++){
		if(Job_Array[i].BT>0 && Job_Array[i].AT<=Time && Job_Array[i].Include==0){
			Job_Array[i].Include=1;
			Add_to_Q(Job_Array[i]);
		}
	}
}

float get_avg_TAT(int N){
	float f=0;
	int i=0;
	for(i=0;i<N;i++){
		f=f+Job_Array[i].TAT;
	}
	return f/(N);
}

float get_avg_WT(int N){
	float f=0;
	int i=0;
	for(i=0;i<N;i++){
		f=f+Job_Array[i].WT;
	}
	return f/(N);
}


void main(){
	
	int N=6,Timer=0,TQ=2,count=0;
	Job tmp_Job;
	float Avg_TAT,Avg_WT;
	
	Q.front=-1;
	Q.rear=-1;
	
	Job_Array[0]=(Job){0,0,0,4};
	Job_Array[1]=(Job){1,0,1,5};
	Job_Array[2]=(Job){2,0,2,2};
	Job_Array[3]=(Job){3,0,3,1};
	Job_Array[4]=(Job){4,0,4,6};
	Job_Array[5]=(Job){5,0,6,3};
	
	int BT_Copy[]={4,5,2,1,6,3};
	
	Get_Jobs(Timer,N);
	
	while(1){
	
		tmp_Job=Pop_from_Q();
		if(tmp_Job.BT>TQ){
			Timer=Timer+TQ;
			tmp_Job.BT=tmp_Job.BT-TQ;
			Get_Jobs(Timer,N);
			Add_to_Q(tmp_Job);
			Job_Array[tmp_Job.Id]=tmp_Job;
			
		}else{
			Timer=Timer+tmp_Job.BT;
			tmp_Job.BT=0;
			tmp_Job.CT=Timer;
			tmp_Job.TAT=tmp_Job.CT-tmp_Job.AT;
			tmp_Job.WT=tmp_Job.TAT-BT_Copy[tmp_Job.Id];
			Job_Array[tmp_Job.Id]=tmp_Job;
			Get_Jobs(Timer,N);
		}
		
		
		
		
		
		if(Q.front>Q.rear){
			break;
		}
		
	}
	
	printf("\n%s \t%s \t%s \t%s \t%s","AT","BT","CT","TAT","WT");
	for(count=0;count<N;count++){
		printf("\n%d \t%d \t%d \t%d \t%d",Job_Array[count].AT,BT_Copy[count],Job_Array[count].CT,Job_Array[count].TAT,Job_Array[count].WT);
	}
	
	
	
	Avg_TAT=get_avg_TAT(N);
	Avg_WT=get_avg_WT(N);
	
	printf("\n\nAvg TAT: %f \tAvg WT: %f",Avg_TAT,Avg_WT);
	
	
	
	
}
