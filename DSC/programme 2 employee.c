
#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

typedef struct e{
    char    name[30];
    int     empId;
    char    dept[30];
    float   salary;
}employee;
 void addsal(employee *emp,int n);
int main()
{
  
    employee *emp;
    printf("no. of employee ");
    int a; scanf("%d",&a);
    emp=(employee*)malloc(a*sizeof(employee));
    for(int i=0;i<a;i++){ 

    printf("\nEnter details  of emp %d:\n",i+1);
    printf("Name ?:");          scanf("%s",(emp+i)->name);
    printf("ID ?:");            scanf("%d",&(emp+i)->empId);
     printf("dept ?:");          scanf("%s",(emp+i)->dept);
    printf("Salary ?:");        scanf("%f",&(emp+i)->salary);
    }
    for(int i=0;i<a;i++){  

    printf("\nEntered detail of emp %d:\n",i+1);
    printf("Name: %s"   ,(emp+i)->name);
    printf("Id: %d"     ,(emp+i)->empId);
    printf("Dept: %s"   ,(emp+i)->dept); 
    printf("Salary: %f\n",(emp+i)->salary);
    }
    addsal(emp,a);
    return 0;
}
void addsal(employee *array,int n) {
  double sum = 0.0;char dept[30];
   printf("enter Dept:");
  scanf("%s",dept);
  for (int i = 0; i < n; i++) {
    if (strcmp(((array+i)->dept), dept) == 0) { // compare the departments
      sum += (array+i)->salary; // add the salary to the sum
    }
  }
 printf("Sum=%f", sum); 
}
