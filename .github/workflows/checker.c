#include <stdio.h>
#include <assert.h>


int isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isInRange(temperature, 0, 45) && isInRange(soc, 20, 80) && (chargeRate <= 0.8);
}


int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(batteryIsOk(0, 20, 0.7));
  assert(!batteryIsOk(45, 80, 0));
  assert(batteryIsOk(25, 20, 0.8));
  assert(!batteryIsOk(50, 80, 0));
  assert(batteryIsOk(25, 80, 0.7));
  assert(!batteryIsOk(50, 75, 0.9));
}
