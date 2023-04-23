#include <stdio.h>
#include <string.h>



int toInt(char* Roman);


int main(){
    char Roman[1000];
    scanf("%s", Roman);
    printf("%d", toInt(Roman));
}

int toInt(char* Roman){
    int value = 0; 
    int previousValue = 0;
    for (unsigned int i = 0; i < strlen(Roman); i++) {
        int currentValue = 0;
        switch (Roman[i])
        {
        case 'I': currentValue += 1; break;
        case 'V': currentValue += 5; break;
        case 'X': currentValue += 10; break;
        case 'L': currentValue += 50; break;
        case 'C': currentValue += 100; break;
        case 'D': currentValue += 500; break;
        case 'M': currentValue += 1000; break;
        default: return -1; break;
        }
        value += currentValue;
        if (currentValue > previousValue) {
            value -= previousValue *2;
        }
        previousValue = currentValue;
    }
    return value;
}