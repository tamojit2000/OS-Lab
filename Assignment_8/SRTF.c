#include<stdio.h>

struct Job{
	int AT,BT,CT,TAT,WT;
};

typedef struct Job Job;

Job Job_Array[10];


int get_min_job_till_range(int time,int N){
	int min=999999;
	int i=0,index=0,flag=0;
	for(i=0;i<N;i++){
		if(Job_Array[i].AT<=time && Job_Array[i].BT<min && Job_Array[i].BT>0){
			min=Job_Array[i].BT;
			index=i;
			flag=1;
		}
	}
	if(flag==0){
		return -1;
	}	
	return index;
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

int check_all_not_done(N){
	int i=0;
	for(i=0;i<N;i++){
		if(Job_Array[i].BT>0){
			return 1;
		}
	}
	return 0;
}

void main(){
	int N=6,Timer=0,count=0,tmp_index=0;
	float Avg_TAT,Avg_WT;
	
	Job_Array[0]=(Job){1,9};
	Job_Array[1]=(Job){2,7};
	Job_Array[2]=(Job){3,5};
	Job_Array[3]=(Job){4,1};
	Job_Array[4]=(Job){5,2};
	Job_Array[5]=(Job){6,4};
	
	int Initial_BT[10]={9,7,5,1,2,4};
	
	while(check_all_not_done(N)){
		tmp_index=get_min_job_till_range(Timer,N);
		//printf("\n%d",Timer);
		if(tmp_index!=-1){
			Job_Array[tmp_index].BT--;
			
			Timer++;
			if(Job_Array[tmp_index].BT==0){
				Job_Array[tmp_index].CT=Timer;
				Job_Array[tmp_index].TAT=Job_Array[tmp_index].CT-Job_Array[tmp_index].AT;
				Job_Array[tmp_index].WT=Job_Array[tmp_index].TAT-Initial_BT[tmp_index];
			}
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
