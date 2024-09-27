#include <stdio.h>
#include <stdbool.h>

int main(void) {
  
    int class_points[] = {92, 52, 59, 0, 50, 5, 21, 80, 58, 52, 68, 99, 21, 57, 1, 80, 49, 65, 51, 5, 54, 47, 59, 53};
    int your_points = 50;


    float average, sum = 0;
    int count = 0;

    for (int i = 0; i < sizeof(class_points) / sizeof(class_points[0]); i++){
    sum += class_points[i];
    count++;
    }

    average = sum / count;
    if (your_points > average){
        printf("true");
        return 0;
    }
    
    printf("false");
    return 0;
}