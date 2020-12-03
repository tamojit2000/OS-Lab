#include<stdio.h>

struct Job{
	int Pr,AT,BT,CT,TAT,WT;
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


int get_max_priority(int Time,int N){
	int max=0;
	int i=0,Index=0,flag=0;
	for(i=0;i<N;i++){
		if(Job_Array[i].AT<=Time && Job_Array[i].BT>0 && Job_Array[i].Pr>max){
			max=Job_Array[i].Pr;
			Index=i;
			flag=1;
		}
	}
	if(flag==0){
		return -1;
	}
	return Index;	
}

void main(){
	int N=5,Timer=0,count=0,tmp_index=0;
	float Avg_TAT,Avg_WT;
	
	Job_Array[0]=(Job){4,0,5};
	Job_Array[1]=(Job){3,1,4};
	Job_Array[2]=(Job){6,1,3};
	Job_Array[3]=(Job){8,2,6};
	Job_Array[4]=(Job){5,3,8};
	
	int Initial_BT[]={5,4,3,6,8};
	
	while(count<N){
		tmp_index=get_max_priority(Timer,N);
		if(tmp_index!=-1){
			Job_Array[tmp_index].BT=Job_Array[tmp_index].BT-1;
			Timer++;
			if(Job_Array[tmp_index].BT==0){
				count++;
				Job_Array[tmp_index].CT=Timer;
				Job_Array[tmp_index].TAT=Job_Array[tmp_index].CT-Job_Array[tmp_index].AT;
				Job_Array[tmp_index].WT=Job_Array[tmp_index].TAT-Initial_BT[tmp_index];
			}
		}
		
	}
	
	printf("\n%s \t%s \t%s \t%s \t%s","AT","BT","CT","TAT","WT");
	for(count=0;count<N;count++){
		printf("\n%d \t%d \t%d \t%d \t%d",Job_Array[count].AT,Initial_BT[count],Job_Array[count].CT,Job_Array[count].TAT,Job_Array[count].WT);
	}	
	
	Avg_TAT=get_avg_TAT(N);
	Avg_WT=get_avg_WT(N);
	
	printf("\n\nAvg TAT: %f \tAvg WT: %f",Avg_TAT,Avg_WT);
	
	
}
