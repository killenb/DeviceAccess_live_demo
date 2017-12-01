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

}
