#include <stdio.h>
#include<stdlib.h>
#define MAX_NAME 30
#define MAX_DEP 5

struct Traveler 
{
    int passportID;
    char name[MAX_NAME];
    int riskScore; // 0 (safe) to 100 (high risk)
    int numDependents;
    struct Traveler *dependents[MAX_DEP];
}t;

struct Traveler t1;

void EnterTravler(struct Traveler *t)
{
    printf("Enter Data ");
    printf("ID ");
    scanf("%d", &(t->passportID));
    printf("name ");
    scanf("%s", &(t->name));
    printf("riskscore ");
    scanf("%d", &(t->riskScore));
    printf("numdependents ");
    scanf("%d", &(t->numDependents));
    int x= t->numDependents;

    for (int i = 0; i < x; i++)
    {
        t->dependents[i] = malloc(sizeof(struct Traveler));
        printf("ID ");
        scanf("%d",&(t->dependents[i]->passportID));
        printf("name ");
        scanf("%s", &(t->dependents[i]->name));
        printf("riskscore ");
        scanf("%d",&(t->dependents[i]->riskScore));
    }
};

int isCleared(struct Traveler *t)
{
    if (t->riskScore >= 50)
    {
        return 0;
    }
    for (int i = 0; i < t->numDependents; i++)
    {
        if (t->dependents[i]->riskScore >= 50)
        {
            return 0;
        }
        else return 1;
    }
};
int calculateTotalRisk(struct Traveler *t)
{
    if (t == NULL)
        return 0;

    int sum = t->riskScore;
    for (int i = 0; i < t->numDependents; i++)
    {
        sum += calculateTotalRisk(t->dependents[i]);
    }
    return sum;
}


void printHighRiskMembers(struct Traveler *t)
{
    if (t->riskScore >= 70)
    {
        printf("Passport ID: %d | Name: %s", t->riskScore, t->name);
    }
    else
        printf("No Risk");
};

int main()
{
    printf("Welcome \n");
    struct Traveler *t= malloc(sizeof(struct Traveler));
  
   int n;
   printf("Enter 1 for Input \n");
   printf("Enter 2 for HighRiskMembers \n");
   printf("Enter 3 for Totalrisk \n");
   scanf("%d",&n);
   switch (n)
   {
   case 1:
    EnterTravler(t);
    break;

    case 2:
    printHighRiskMembers(t);
    break;

    case 3:
    calculateTotalRisk(t);
    break;
   
   default:
    break;
   }
   
     if (isCleared(t))
    {
        printf("CLEARED\n");
    }
    else
        printf("DENIED\n");

    printHighRiskMembers(t);

    printf("Total risk :- %d", calculateTotalRisk(t));

    return 0;
}