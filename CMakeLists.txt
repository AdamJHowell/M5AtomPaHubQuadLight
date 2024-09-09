cmake_minimum_required( VERSION 3.23 )
project( M5AtomPaHubQuadLight )

set( CMAKE_CXX_STANDARD 14 )

include_directories( .
   C:/Users/Adam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.5/cores/arduino/
   C:/Code/Arduino/libraries/
   C:/Code/Arduino/libraries/Servo/src/
   "C:/Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino/"
   "C:/Program Files (x86)/Arduino/hardware/tools/avr/lib/gcc/avr/7.3.0/include/"
   "C:/Users/Adam Howell/Documents/Arduino/libraries/M5-DLight/src/"
   "C:/Users/Adam Howell/Documents/Arduino/libraries/M5Atom/src/"
   "C:/Users/Adam Howell/AppData/Local/Arduino15/packages/m5stack/hardware/esp32/2.1.1/cores/esp32/"
   "C:/Users/Adam Howell/AppData/Local/Arduino15/packages/m5stack/hardware/esp32/2.1.1/libraries/Wire/src/"
   "C:/Users/Adam Howell/Documents/Arduino/libraries/ClosedCube_TCA9548A/src/"
)

add_executable( M5AtomPaHubQuadLight
   M5AtomPaHubQuadLight.ino )

set_target_properties( M5AtomPaHubQuadLight PROPERTIES LINKER_LANGUAGE CXX )
