//11. Write a program to calculate sum of n numbers using thread library.
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<cmath>
#include<pthread.h>
using namespace std;

int sum1=0; //Final Sum
int sum2=0;
int *arr;  // For storing input array
int sizeArr; // size of the array

void *runner(void *i){
	int id=*(int*)i;
	if (id==0){
		for (int j=0; j<(int)(sizeArr/2); j++)
			sum1+= arr[j];	
		cout<<endl<<"Sum computed by thread 1: "<<sum1;
	}else{
		for (int j=(int)(sizeArr/2); j<sizeArr; j++)
			sum2+= arr[j];	
		cout<<endl<<"Sum computed by thread 2: "<<sum2;
	}
    return NULL;
}

void input(){
   cout<<"Enter Size of the array: ";
   cin>>sizeArr;
   arr = new int[sizeArr];
   cout<<"\nEnter Array Elements: \n";

   for(int i = 0; i<sizeArr; i++){
        cout<<"\narr["<<i<<"]: ";
        cin>>arr[i];
    }
}

int main(){ 
    pthread_t t1, t2;
    int tNum1 = 0, tNum2 = 1;
    input();
    pthread_create(&t1,NULL,runner,&tNum1);
    pthread_create(&t2,NULL,runner,&tNum2);
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
   	
    cout<<"\n\nFinal Sum: "<<sum1 + sum2;
    return 0;
}
