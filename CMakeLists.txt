cmake_minimum_required( VERSION 3.23 )
project( M5AtomPaHubQuadLight )

set( CMAKE_CXX_STANDARD 14 )

include_directories( .
   "C:/Users/Adam Howell/Documents/Arduino/libraries/M5-DLight/src/"
   "C:/Users/Adam Howell/Documents/Arduino/libraries/M5Atom/src/"
   "C:/Users/Adam Howell/AppData/Local/Arduino15/packages/m5stack/hardware/esp32/2.1.1/cores/esp32/"
   "C:/Users/Adam Howell/AppData/Local/Arduino15/packages/m5stack/hardware/esp32/2.1.1/libraries/Wire/src/"
)

add_executable( M5AtomPaHubQuadLight
   M5AtomPaHubQuadLight.ino
   M5AtomPaHubQuadLight.ino )

set_target_properties( M5AtomPaHubQuadLight PROPERTIES LINKER_LANGUAGE CXX )
