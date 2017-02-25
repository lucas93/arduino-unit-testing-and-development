set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0) # Default Port, when not specified

include(../../utilities.cmake)

set(SOURCES_MAIN_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../../application")

INCLUDE_DIRECTORIES("${SOURCES_MAIN_DIRECTORY}/BaseClass/")

generate_arduino_firmware(blink
    SRCS blink.cpp blink_lib.cpp "/home/lukasz/workspace/test-repo/application/BaseClass/BaseClass.cpp"
    HDRS blink_lib.h "${SOURCES_MAIN_DIRECTORY}/BaseClass/BaseClass.h"
    ARDLIBS SPI Wire
    BOARD uno)

