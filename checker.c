#include <stdio.h>
#include <assert.h>

int checkTemp(float temp)
{
  if(temp < 0 || temp > 45) 
  {
    printf("Temperature out of range!\n");
    return 0;
  }
  return 1;
}
int checkSoc(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}
int checkChargeRate(float cr)
{
  if(cr > 0.8)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(checkTemp(temperature) && checkSoc(soc) && checkChargeRate(chargeRate)) 
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
