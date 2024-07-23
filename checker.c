#include <stdio.h>
#include <assert.h>

void printMessage(const char * batteryParameter, const char * message)
{
    printf("\n%s : %s", batteryParameter, message);
}

void checkTolerance(float value, float min, float max, const char * batteryParameter)
{
    float warningTolerance = (max * 5) / 100;
    if((value <= (min + warningTolerance)) || (value >= (max - warningTolerance)))
    {
        printMessage(batteryParameter, "Warning Tolerance limit reached");
    }
}

int isInRange(float value, float min, float max, const char * batteryParameter) 
{
    int calculatedValue = (value >= min && value <= max);
    if(!calculatedValue)
    {
        printMessage(batteryParameter, "Out of Range");
    }
    else
    {
        checkTolerance(value, min, max, batteryParameter);
    }
    return calculatedValue;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    return isInRange(temperature, 0, 45, "Temperature") && isInRange(soc, 20, 80, "SoC") && isInRange(chargeRate, 0, 0.8, "ChargeRate");
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
