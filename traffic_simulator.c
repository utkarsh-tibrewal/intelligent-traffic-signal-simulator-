#include<stdio.h>

struct lane{
    char direction[50];
    int vehicle;
    int pedestrian;
    int green_time;
}; 

void printIntersection(struct lane Lanes[],int totalLanes);

int calculateGreentime(int vehicle,int pedestrian);

void inputTrafficData(struct lane Lanes[],int totalLanes);

void SavetoFile(struct lane Lanes[], int totalLanes);

int main(){
    struct lane Lanes[4] = {
      {"North", 0, 0, 0},
      {"South", 0, 0, 0},
      {"East", 0 ,0 ,0},
      {"West", 0 ,0, 0},
    };
    
    int choice;

    do{
        printf("\n=========================================\n");
        printf("Intelligent Traffic Signal Simulator\n");
        printf("\n=========================================\n");
        printf("1.Enter Traffic Data And Calculate.\n");
        printf("2.Display Current Intersection Status.\n");
        printf("3.Save Current cycle to log file.\n");
        printf("4.Exit \n");
        printf("Enter your choice(1-4): ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            inputTrafficData(Lanes,4);
            break;
            case 2:
            printIntersection(Lanes,4);
            break;
            case 3:
            SavetoFile(Lanes,4);
            break;
            case 4:
            printf("Exiting Simulation. Goodbye!\n");
            break;
            default:
            printf("Invalid choice! Please Enter a number a between 1 and 4\n");
            break;
        }
    }while(choice!=4);

    return 0;
}
    
void printIntersection(struct lane Lanes[],int totalLanes){
    printf("%12s %10s %12s %10s\n","Direction","Vehicle","Pedestrian", "GreenTime");
    for(int i=0;i<totalLanes;i++){
        printf("%12s %10d %12d %10d\n",Lanes[i].direction,Lanes[i].vehicle,Lanes[i].pedestrian,Lanes[i].green_time);
    }
}

int calculateGreentime(int vehicle,int pedestrian){
    int basetime = 10; //In Seconds
    basetime += (vehicle/5)*2;
    if(pedestrian>3){
        basetime += 5;
    }
    if(basetime>60){
        basetime = 60;
    }
    return basetime;
}

void inputTrafficData(struct lane Lanes[],int totalLanes){
    for(int i=0;i<totalLanes;i++){
        printf("Enter data for %s lane: \n",Lanes[i].direction);
        printf("Enter vehicle count: ");
        scanf("%d",&Lanes[i].vehicle);
        while(Lanes[i].vehicle<0){
            printf("Invalid Entry!,Enter Again\n");
            printf("Enter vehicle count: ");
            scanf("%d",&Lanes[i].vehicle);
        }
        printf("Enter no. of pedestrian: ");
        scanf("%d",&Lanes[i].pedestrian);
        while(Lanes[i].pedestrian<0){
            printf("Invalid Entry!,Enter Again\n");
            printf("Enter no. of pedestrian: ");
            scanf("%d",&Lanes[i].pedestrian);
        }

        Lanes[i].green_time = calculateGreentime(Lanes[i].vehicle,Lanes[i].pedestrian);
    }
}

void SavetoFile(struct lane Lanes[], int totalLanes){
    FILE *fptr;
    fptr = fopen("traffic_log.txt","a");
    if(fptr==NULL){
        printf("Error Opening File");
        return;
    }

    fprintf(fptr,"\n\n");
    fprintf(fptr,"==========================================================================\n");
       fprintf(fptr,"              Intelligent Traffic Signal Simulator\n");
       fprintf(fptr,"                          TRAFFIC REPORT\n");
       fprintf(fptr,"==========================================================================\n\n");

    fprintf(fptr,"%12s %10s %12s %10s\n","Direction","Vehicle","Pedestrian","Green-Time");

    for(int i=0;i<totalLanes;i++){
        fprintf(fptr,"%12s %10d %12d %10d\n",Lanes[i].direction,Lanes[i].vehicle,Lanes[i].pedestrian,Lanes[i].green_time);
    }

    fclose(fptr);

    printf("Data succesfully logged to traffic_log.txt!\n");

}