#include <ChimeraTK/Device.h>
#include <iostream>

int main(){

  ChimeraTK::setDMapFilePath("devices.dmap");
  ChimeraTK::Device d;
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
