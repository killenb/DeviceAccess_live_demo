#include <mtca4u/Device.h>
#include <mtca4u/Utilities.h> // needed for setDMapFilePath
#include <iostream>

int main(){

  mtca4u::setDMapFilePath("devices.dmap");
  mtca4u::Device d;
  d.open("oven");
 
  auto heatingCurrent
    = d.getScalarRegisterAccessor<int>("heater/heatingCurrent");

  heatingCurrent.read();  
  std::cout << "Heating current is " << heatingCurrent << std::endl;

  heatingCurrent += 3;
  heatingCurrent.write();

  auto temperature
    = d.getScalarRegisterAccessor<float>("heater/temperatureReadback");

  temperature.read();  
  std::cout << "Readback temperature is " << temperature << std::endl;

  auto supplyVoltages
    = d.getOneDRegisterAccessor<int>("heater/supplyVoltages");

  supplyVoltages.read();

  std::cout << "Supply voltages are ";
  for (auto voltage : supplyVoltages){
    std::cout << voltage << " ";
  }
  std::cout << std::endl;

}
