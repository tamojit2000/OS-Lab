#include<stdio.h>

struct Job{
	int Status,Pr,AT,BT,CT,TAT,WT;
};

typedef struct Job Job;

Job Job_Array[10];

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

int get_max_priority_index(int Time,int N){
	int i=0,index=0,max=0,flag=0;
	for(i=0;i<N;i++){
		if(Job_Array[i].Status==0 && Job_Array[i].AT<=Time && Job_Array[i].Pr>max){
			max=Job_Array[i].Pr;
			index=i;
			flag=1;
			//printf("K");
		}
	}
	if(flag==0){
		return -1;
	}
	return index;
}


void main(){
	int N=5,Timer=0,count=0,tmp_index=0;
	float Avg_TAT,Avg_WT;
	
	Job_Array[0]=(Job){0,4,0,3};
	Job_Array[1]=(Job){0,3,2,6};
	Job_Array[2]=(Job){0,5,4,8};
	Job_Array[3]=(Job){0,6,6,5};
	Job_Array[4]=(Job){0,8,8,7};
	
	while(count<N){
		tmp_index=get_max_priority_index(Timer,N);
		if(tmp_index!=-1){
			Job_Array[tmp_index].Status=1;
			Timer=Timer+Job_Array[tmp_index].BT;
			Job_Array[tmp_index].CT=Timer;
			Job_Array[tmp_index].TAT=Job_Array[tmp_index].CT-Job_Array[tmp_index].AT;
			Job_Array[tmp_index].WT=Job_Array[tmp_index].TAT-Job_Array[tmp_index].BT;
			count++;
		}
		else{
			Timer++;
		}
		
	}
	
	printf("\n%s \t%s \t%s \t%s \t%s","AT","BT","CT","TAT","WT");
	for(count=0;count<N;count++){
		printf("\n%d \t%d \t%d \t%d \t%d",Job_Array[count].AT,Job_Array[count].BT,Job_Array[count].CT,Job_Array[count].TAT,Job_Array[count].WT);
	}
	
	
	
	Avg_TAT=get_avg_TAT(N);
	Avg_WT=get_avg_WT(N);
	
	printf("\n\nAvg TAT: %f \tAvg WT: %f",Avg_TAT,Avg_WT);	
	
	
	
	
	
}
