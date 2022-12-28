//
// Created by shahar on 12/18/22.
//

#include "isort.h"

void shift_element(int* arr, int i) {
    int j2;
    for (int j = i; j >= 0; j--) {
        if(j - 1 == -1) j2 = 0;
        else j2 = j - 1;
        *(arr + j) = *(arr + j2);
    }
}


void insertion_sort(int* arr, int arr_len){
    int value, j, counter;
    for(int i = 1; i < arr_len; i++){
        value = *(arr + i);
        j = i - 1;
        counter = 0;
        while(j >= 0 && value < *(arr + j)){
            counter++;
            j--;
        }
        int* ptr = arr + i - counter;
        shift_element(ptr, counter);
        *(arr + i - counter) = value;
    }
}



