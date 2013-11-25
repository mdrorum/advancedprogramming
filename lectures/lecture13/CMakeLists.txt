cmake_minimum_required (VERSION 2.6)

project (lecture13)

add_definitions(-std=c++11)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


QT4_WRAP_CPP(qtapp_HEADERS_MOC ${qtapp_HEADERS})

QT4_WRAP_UI(qtapp_UIS_H ${qtapp_UIS})

add_executable(qtapp qtapp.cpp)

TARGET_LINK_LIBRARIES(qtapp ${QT_LIBRARIES})


