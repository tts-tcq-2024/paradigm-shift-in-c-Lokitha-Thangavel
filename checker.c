#include <stdio.h>
#include <assert.h>

int checkTemp(float temp) {
    return (temp >= 0 && temp <= 45);
}

int checkSoc(float soc) {
    return (soc >= 20 && soc <= 80);
}

int checkChargeRate(float cr) {
    return (cr <= 0.8);
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemp(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}


int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
