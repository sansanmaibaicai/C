#include<stdio.h>

int is_leap_year(int Y){
	return (Y% 4 == 0 && Y % 100 != 0) || (Y% 400 == 0);
}

int get_days_in_month(int Y,int M){
	int days_in_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(M==2&&is_leap_year(Y)){
		return 29;
	}
	return days_in_month[M-1];
}

int get_first_day(int Y,int M){
	int adjusted_month=M-2;
	int adjusted_year=Y;
    
	if (adjusted_month<=0){
		adjusted_month+=12;
		adjusted_year-=1;
	}

	int K=adjusted_year%100;
	int J=adjusted_year/100;

	int day_of_week=(1+(13*adjusted_month-1)/5+K+K/4+J/4+5*J)%7;

	day_of_week = (day_of_week+5)%7;

	return day_of_week;
}

void print_single_calendar(int Y,int M,int start_day){
	int days_in_month=get_days_in_month(Y,M);
	int first_day=get_first_day(Y,M);
	
	printf("\n");
    	printf("              %d月\n",M);
  	printf("—————————————————————————————————\n");
  	printf("周一 周二 周三 周四 周五 周六 周天\n");
  	printf("—————————————————————————————————\n");
  	
  	for(int i=0;i<first_day;i++){
  		printf("     ");
  	}
  	for(int D=1;D<=days_in_month;D++){
  		printf("%4d ",D);
  		if((D+first_day)%7==0){
  			printf("\n");
  		}
  	}
  	if ((days_in_month + first_day)%7!=0){
        	printf("\n");
        }

	for (int i = 0; i < (start_day-(days_in_month+first_day) %7)%7; i++) {
		printf("\n");
	}
	
  }
  	


void print_calendar(int Y,int start_month){
	for(int i=0;i<3;i++){
		print_single_calendar(Y,start_month+i,0);
		if(i<2){
			printf("      ");
		}
	}

}

int main(){
	int Y;
	printf("请输入一个年份：\n");
	scanf("%d",&Y);
	
	for(int i=0;i<4;i++){
		print_calendar(Y,i*3+1);
		printf("\n");
	}

 	return 0;
}

