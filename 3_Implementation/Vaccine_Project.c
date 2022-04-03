#include "stdio.h"
#include "regist.h"


// code starts to execute
int main(){
    
    int patient_state;         // parameter to check status 
    long aadhar;             // Variable contanting patient's aadhar number
    int vacc1=0,vacc2=0;      //Vaccine 1 and 2
    
    existregist();
    
    int attempt=1000;    // Variable that determines the total number of execution required by EOD
    while(attempt>0){
        
    apply:
    printf("\nLet's save our life by getting vaccinated!!!\n");
    printf("Enter your aadhar number:");
    scanf("%li",&aadhar);
   
    
    patient_state = regist_status(aadhar);
    int i,j=0,vaccstate=0,choice=0,phonenumber;
    
    i=1;
    while(i<=1000){
        if(v[i].aadhar==aadhar)
            j=i;
    i++;
    }
    
    if(patient_state==-1){
        existregist();
        i=1;
        while(i<=1000){
            if(v[i].aadhar==0){
                printf("Fill details for registration\n");
                v[i].aadhar=v[0].aadhar;
                printf("Enter your phone number: ");
                scanf("%d",&v[i].phone_number);
                printf("Enter your age: ");
                scanf("%d",&v[i].age);
                printf("Enter your code: ");
                scanf("%d",&v[i].secret_code);
                break;}
            i++;
        }
        printf("Credentials saved, log in again\n");
        goto apply;
    }
    else if (patient_state==0){
        //Verification
        printf("Confirm user, enter phone number\n");
        previous1:
        scanf("%d",&phonenumber);
        if(phonenumber==v[j].phone_number)
            goto next1;
        else
            printf("Wrong credentials, try again\n");
            goto previous1;
        next1:
        printf("Time for vaccine\nSelect type\n");
        printf("1:Covishield\n2:Covaxin\n");
        scanf("%d",&choice);
        if(v[j].vaccine_type==0){
            switch (choice){
                case 1:
                    v[j].vaccine_type=1;
                    break;
                case 2:
                    v[j].vaccine_type=2;
                    break;
                default:
                    printf("Select option 1 or 2\n");
                    break;
                }
        }
    }
    else{
        // Verification
        printf("Confirm user, enter ph.number\n");
        previous2:
        scanf("%d",&phonenumber);
        if(phonenumber==v[j].phone_number)
            goto next2;
        else
            printf("Wrong credentials, try again\n");
            goto previous2;
        }next2:

    vaccstate=vaccine_status(j);        //State of patient based on being vaccinated

    if(vaccstate==1)
        printf("Please take your first vaccine\nYou have been vaccinated once\n");
    else if (vaccstate==2)
        printf("Please take your second vaccine\nYou have been vaccinated twice\n");
    else if (vaccstate==3)
        printf("You have completed two dozes of vaccination\n");
    
    // Count of total number of vaccine vials used
    if(v[j].vaccine_type==1 && (vaccstate==1 || vaccstate==2))
        vacc1++;
    else if(v[j].vaccine_type==2 && (vaccstate==1 || vaccstate==2))
        vacc2++;
    
    attempt--;
    
    }

    printf("\nFinal list of patients and consumed stock of vaccines\n");
    int i=1;
    while(i<=1000){
        if(v[i].aadhar!=0){
            printf("P%d Aadhar:%li\n",i,v[i].aadhar);
            printf("P%d Phone no:%d\n",i,v[i].phone_number);
            printf("P%d Age:%d\n",i,v[i].age);
            printf("P%d Secret code:%d\n",i,v[i].secret_code);
            printf("P%d Vaccine type:%d\n",i,v[i].vaccine_type);
            printf("P%d Vaccine dozes:%d\n",i,v[i].vaccine_doses);
        }
    i++;
    }
    printf("\nVaccine type 1(COVISHIELD):%d\n",vacc1);
    printf("Vaccine type 2(COVAXIN):%d\n",vacc2);
}
