#include <stdio.h>
void getColorCode(char colorCode[]);
long getResistorValue( char colorCode[], int colorValue[], int r_value );
float Tolerance( char colorCode[], float tolerance);

int main (void)
{
    long r_value = 0; //should be long to store large values
    char colorCode[4];
    int  colorValue[4];
    float tolerance = 0.0;
    printf("This program will calculate the value of a resistor.\n");
    printf("B = Black\nN = Brown\nR= Red\nO = Orange\nY = Yellow\n");
    printf("G = Green\nL = Blue\nV = Violet\nE = Gray\nW = White\n");
    printf("H = gold\nS = silver\n\n");
    printf("Enter the 4-character color description of the resistor: ");
    getColorCode(colorCode);
      r_value =  getResistorValue(colorCode, colorValue, r_value);
      tolerance = Tolerance(colorCode, tolerance);
    printf("\n\nThe resistor with color code %c %c %c %c has a value of %d +/- %.2lf %% Ohms.\n\n",
            colorCode[0], colorCode[1], colorCode[2], colorCode[3], r_value, tolerance);
    return 0;
}
void getColorCode(char colorCode[])
{
    int i;
    for(i = 0; i < 4; i++)
        colorCode[i] = getchar();
}
long getResistorValue( char colorCode[], int colorValue[], int r_value)
{
    int i;
    int j;
    int sum=0;
    long multiplier;
    for( i = 0; i < 2; i++)
    {
        switch (colorCode[i])
        {
            case('b'):
            case('B'):
                colorValue[i] = 0;
                break;
            case('n'):
            case('N'):
                colorValue[i] = 1;
                break;
            case('r'):
            case('R'):
                colorValue[i] = 2;
                break;
            case('o'):
            case('O'):
                colorValue[i] = 3;
                break;
            case('y'):
            case('Y'):
                colorValue[i] = 4;
                break;
            case('g'):
            case('G'):
                colorValue[i] = 5;
                break;
            case('l'):
            case('L'):
                colorValue[i] = 6;
                break;
            case('v'):
            case('V'):
                colorValue[i] = 7;
                break;
            case('e'):
            case('E'):
                colorValue[i] = 8;
                break;
            case('w'):
            case('W'):
                colorValue[i] = 9;
                break;
            default: errormsg();
        }
        sum=(sum*10)+colorValue[i];
    }
        switch (colorCode[2])
         {
            case('b'):
            case('B'):
                multiplier = 1;
                break;
            case('n'):
            case('N'):
                multiplier = 10;
                break;
            case('r'):
            case('R'):
                multiplier = 100;
                break;
            case('o'):
            case('O'):
                multiplier = 1000;
                break;
            case('y'):
            case('Y'):
                multiplier = 10000;
                break;
            case('G'):
            case('g'):
                multiplier = 100000;
                break;
            case('l'):
            case('L'):
                multiplier = 1000000;
                break;
            default: errormsg();
        }
        r_value=sum*multiplier;
    return r_value;
}
float Tolerance(char colorCode[], float tolerance)
{
    float tol=0;
 switch (colorCode[3])
        {
            case('n'):
            case('N'):
                tol = 1;
                break;
            case('r'):
            case('R'):
                tol = 2;
                break;
            case('g'):
            case('G'):
                tol = 0.5;
                break;
            case('l'):
            case('L'):
                tol = 0.25;
                break;
            case('v'):
            case('V'):
                tol = 0.1;
                break;
            case('e'):
            case('E'):
                tol = 0.05;
                break;
            case('h'):
            case('H'):
                tol = 5;
                break;
            case('s'):
            case('S'):
                tol = 10;
                break;
            default: errormsg();
        }
        tolerance = tol;
        return tolerance;
}
char errormsg()
{
    printf("Invalid alphabet entered \n\n");
    while(1);
}
