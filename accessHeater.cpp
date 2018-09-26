#include <ChimeraTK/Device.h>
#include <iostream>

int main(){

  ChimeraTK::Device d;
  d.open("sdm://./pci:mtcadummys1=oven.map");
 
  auto heatingCurrent
    = d.getScalarRegisterAccessor<int>("heater/heatingCurrent");

  heatingCurrent.read();  
  std::cout << "Heating current is " << heatingCurrent << std::endl;

  heatingCurrent += 3;
  heatingCurrent.write();

}
