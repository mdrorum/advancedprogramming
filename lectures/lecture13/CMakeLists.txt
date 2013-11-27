cmake_minimum_required (VERSION 2.6)

project (lecture13)

add_definitions(-std=c++11)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


################################# library
add_executable(qtapp qtapp.cpp)
TARGET_LINK_LIBRARIES(qtapp ${QT_LIBRARIES})


################################# compiling
QT4_WRAP_UI(UISrcs qtcompiled.ui)
QT4_WRAP_CPP(MOCSrcs ui_qtcompiled.h)
ADD_EXECUTABLE(qtcompiled qtcompiled.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(qtcompiled ${QT_LIBRARIES})

