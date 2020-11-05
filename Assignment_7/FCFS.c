#include<stdio.h>

void main(){
	int CT[10],TAT[10],WT[10];
	
	int AT[10]={2,3,3,9,12,15};
	int BT[10]={3,2,1,4,5,6};
	
	int Timer=0;
	int n=6;
	
	float avgTAT=0.0,avgWT=0.0;	
	
	
	int i=0;
	
	while (i<n){
		if (Timer>=AT[i]){
			Timer=Timer+BT[i];
			CT[i]=Timer;
			TAT[i]=CT[i]-AT[i];
			WT[i]=TAT[i]-BT[i];
			avgTAT=avgTAT+TAT[i];
			avgWT=avgWT+WT[i];
			i++;
		}else{
			Timer++;
		}
		
	}
	
	for(i=0;i<n;i++){
		printf("\n===============\n\n");
		printf("\nP %d",i+1);
		printf("\nAT %d",AT[i]);
		printf("\nBT %d",BT[i]);
		printf("\nCT %d",CT[i]);
		printf("\nTAT %d",TAT[i]);
		printf("\nWT %d",WT[i]);
	}
	
	printf("\n\nAvg TAT %f \nAvg WT %f",avgTAT/n,avgWT/n);
	
}
