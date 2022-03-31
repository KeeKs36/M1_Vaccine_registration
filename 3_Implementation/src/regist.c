#include <stdio.h>
#include "regist.h"

int regist_status(long aadhar){

    // Checks for registration details of new patients    
    v[0].aadhar=aadhar;
    int i=1;
    while(i<=1000){
        if(v[i].aadhar==v[0].aadhar){
            if(v[i].vaccine_type==0)
                return 0;
            else
                return 1;
        }
        i++;
    }
    return -1;
}

// Checks how many doses should be given
int vaccine_status(int i){
     
    if (v[i].vaccine_doses==0){
        v[i].vaccine_doses++;
        return 1;}
    else if(v[i].vaccine_doses==1){
        v[i].vaccine_doses++;
        return 2;}
    else if (v[i].vaccine_doses==2){
        return 3;}
    else
        return 0;

}
