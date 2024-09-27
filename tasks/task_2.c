#include <stdio.h>

int age_when_shool_ended(int age, int year){
    return (year - age + 17);
}

int age_when_you_retire(int age, int year){    
    return (year + (65 - age));
}

int go_to_army(int age, char gender){
    if (gender == 'm' || gender == 'M'){
        if (age >= 18 && age <= 30){
            return 1;
        }
        else
            return 0;
    }
    else if (gender == 'f' || gender == 'F')
        return 0;

    return 2;
}


int main(void){
    int year = 2024;
    int age, shool, retire;
    int army;
    char gender;

    printf("How old are you?\n>> ");
    scanf("%d", &age);

    printf("Choose your gender\n>> ");
    scanf(" %c", &gender);

    if (age < 0){
        printf("You're under 0");
        return 0;
    }
    
    shool = age_when_shool_ended(age, year);
    retire = age_when_you_retire(age, year);
    army = go_to_army(age, gender);

    printf("You ended shool in %d\n", shool);
    printf("You will be get a posobie in %d\n", retire);

    switch (army){
    case 0:
        printf("No army(");
        break;
    case 1:
        printf("Go to army, son..");
        break;
    default:
        printf("You are something..");
    }

    return 0;
}