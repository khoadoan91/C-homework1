/*
 * Kyle Doan
 * August 2nd, 2015
 * Homework 1
 * Calculate the binary operation.
 */

#include <stdio.h>

double binToDec(char c) {
    double value = 0.0, frac = 0.0, cur = 0.5;
    
    while (c != '.') {
        value *= 2.0;
        value += c - '0';
        scanf("%c", &c);
    }
    
    scanf("%c", &c);
    
    while (c != ' ' && c != '\n') {
        if (c == '1') {
            frac += cur;
        }
        cur /= 2;
        scanf("%c", &c);
    }
    return value + frac;
}

void convertToBin(double num) {
    double curPower = 1.0;
    int i = 0;
    
    if (num < 1) {
        printf("0");
    }
    while (num >= curPower) {
        curPower *= 2;
    }
    curPower /= 2;
    
    while ((curPower > 0.5) || (num != 0 && i < 20)) {
        if (curPower == 0.5) {
            printf(".");
        }
        if (num - curPower >= 0) {
            num -= curPower;
            printf("1");
        } else {
            printf("0");
        }
        curPower /= 2;
        if (curPower < 0.5) {
            i++;
        }
    }
    if (num == 0 && curPower == 0.5) {
        printf(".0");
    }
    printf("\n");   
}


double calculateOper(double first, double second, char c) {
    if (c == '+')
        return first + second;
    else if (c == '-')
        return first - second;
    else if (c == '*')
        return first * second;
    else if (c == '/')
        return first / second;
    else
        return -131;
}

int main() {
    double firstDec, secDec, resultDec;
    char myChar, oper;
    do {
        printf("> ");
        scanf(" %c", &myChar);
        
        if (myChar != 'Q') {
            firstDec = binToDec(myChar);
        
            scanf("%c", &oper);
        
            scanf(" %c", &myChar);
            secDec = binToDec(myChar);
        
            resultDec = calculateOper(firstDec, secDec, oper);
            convertToBin(resultDec);
        }
    } while (myChar != 'Q');
    return 0;
}
