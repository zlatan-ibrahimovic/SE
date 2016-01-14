# Install script for directory: /net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
        message(STATUS "")
        execute_process(COMMAND ${CMAKE_COMMAND} -E  "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl.pc" "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl.pc")
    
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
        message(STATUS "")
        execute_process(COMMAND ${CMAKE_COMMAND} -E  "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl-config" "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl-config")
    
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/CMakeFiles/CMakeRelink.dir/libsotl.so")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libsotl" TYPE FILE FILES "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/include/sotl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/net/cremi/hanaba/M1/S2/pmc/project/pmcproject/trunk/fichiers/libsotl/libsotl-config")
endif()

