/*
 *prime.c
 *
 *素数即为只有1和其本身作为因子的数。因此，使用for循环来遍历2到x之内的所有数
 *若2到x内有可以被x整除的数,则该数不是素数
 */




#include<stdio.h>

int main()
{
	int x;
	int i;
	printf("Please enter a number.\n");
	scanf("%d",&x);
	
	if(x>0){
		for(i=2;i<x;i++){
			if(x%i==0) break;
			//即x是否能够整除i，若可以整除，则找到一个因子，循环结束
		}
		if(i<x){
			printf("No\n.");
			//若该因子小于x，则不符合素数的条件，该数不是素数，输出no
		}else{
			printf("Yes\n",x);
			//若该因子等于x，则说明在2到n内无其他因子，该数为素数，输出yes
		}
	
	}else{
		printf("Wrong number!\n");
		//若输入的数字不是正数，则报错
	}
	
	return 0;
}
