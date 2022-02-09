#include <stdio.h>
#include<stdlib.h>
/*
AUTHOR: Joshua Wade West
HW #: HW7 Problem 1
FOR: CS 2413 Lab- Section 502
*/
int Heap_Size = 0;

void Insertion(int *Array,int Value);
void Heapify(int *Array,int Insert);
int Delete(int *Array);
void Scheduling(int *Array);
void Create_BinaryTree(int *Array,int size);




int main(void){

int i,n,o,skip=2;

printf("\nEnter the size of the Heap: ");//user inserts the size of the heap

scanf("%d",&n);//the size is stored in 'n', where it will be what Heap_size leads to

int *Array=(int *)calloc(n+1, sizeof(int));//creates a pointer Array that is formed from memory blocks

Create_BinaryTree(Array,n);//Function call to create the tree, uses the array and n(the size of the heap) 

Scheduling(Array);//function call to schedule the heap, uses the Array 

/*POST FUNCTIONS*/

printf("\n\nNew Heap:\n");//outputs the final heap

for(o = 1; o <= Heap_Size; o++){ 
  
if (o == 1){printf("%d ", Array[o]) ; printf("\n");}/*Out puts the head of the heap*/

else if (o == skip+1){printf("%d ", Array[o]) ; printf("\n");skip=2*(o);}/*out puts the last value in a 'row' in a heap*/

else{
  printf("%d ", Array[o]);//outputs a heap value
}}

return 0;

}/*End of MAIN*/




//inserts values into the heap
void Insertion(int *Array,int Value){

int Mid,Full,Temp;

Array[Heap_Size + 1] = Value;//inputs the users numbers into the array 

Mid = (Heap_Size + 1) / 2;//Mid = 1/2 of the heap+1
Full= Heap_Size + 1;//Full = the heap+1

Heap_Size = Heap_Size + 1;//increase the value of heap by 1

while(Mid > 0){//while the value of Mid is more than 0

if(Array[Mid] < Array[Full]){/*if A_Mid is less than A_FULL*/

Temp = Array[Mid];//int TEMP == A_MID

Array[Mid] = Array[Full];//A_MID == A_FULL

Array[Full] = Temp;//A_FULL = Temp

Full = Mid;//FULL = old MID

Mid = Mid / 2;// MID/2

}/*end of IF*/

else{break;}
}/*End of WHILE*/}/*END OF Insertion*/



//Function to Heapify the tree
void Heapify(int *Array, int Insert){

int Left, Right, Max, Temp;

Left = Insert * 2;//Left is the insert value * 2

Right = Insert * 2 + 1;//Right is the insert value * 2 and + 1

Max = Insert;//Max is the Insert value


/*if A_Max is less than A_Left AND Right is <= The heap*/
if( Array[Max] < Array[Left] && Right <= Heap_Size){Left=Max;}//Left is equal to Max

/*if A_Max is less than A_Right AND Right is <= The heap*/
if( Array[Max] < Array[Right] && Right <= Heap_Size){Max=Right;}//Max is equal to thr Right value

/*If max is not the same as the insert value*/
if(Max != Insert){

Temp= Array[Max];//Temp stores the A_Max value

Array[Max] = Array[Insert];//A_Max == A_Insert

Array[Insert] = Temp;//input temp back into A_Insert

Heapify(Array,Max);//Heapify again using Max as the New Insert

}/*END OF IF*/}/*END OF Heapify*/





//Function to Delete a value
int Delete(int *Array){

int Temp;

Temp=Array[1];//i == the first array value

Array[1] = Array[Heap_Size];//set A_1 to the A_Hsize

Array[Heap_Size]=Temp;//set the A_Hsize to i

Heap_Size=Heap_Size-1;//decrease the heapsize by 1

Heapify(Array,1);//reHeapify

return Temp;

}/*END OF Delete*/



//function to schedule to current heap
void Scheduling(int *Array){


Insertion(Array,Delete(Array)-2);//function call Insert, using the array value and the Delete function value - 1


}/*END OF Scheduling*/




//Function to Create a Binary Tree using the User's Values
void Create_BinaryTree(int *Array,int size){

int i,Value;

printf("\nEnter %d Values: ", size);//asks user for the values they want

for(i=1;i<=size;i++){//for the length of the heap

scanf("%d",&Value);//inputs a value

Insertion(Array,Value);//amd inserts the value into the tree

}/*End of FOR*/}/*END OF Create_BinaryTree*/
