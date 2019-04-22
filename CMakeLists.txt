cmake_minimum_required(VERSION 3.12)

project(performance VERSION 0.1 LANGUAGES CXX)

add_library(PerformanceTest SHARED
        include/performance/Pass.hpp

        src/Pass.cpp
        )
add_library(performance::PerformanceTest ALIAS PerformanceTest)

find_package(LLVM 7.0 REQUIRED CONFIG)

target_include_directories(PerformanceTest
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${LLVM_INCLUDE_DIRS})

target_compile_features(PerformanceTest PRIVATE cxx_std_17 cxx_range_for cxx_auto_type)
target_compile_options(PerformanceTest PRIVATE -fno-rtti)

##
## INSTALL
## install header files, generate and install cmake config files for find_package()
##
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/performance)

install(
        TARGETS PerformanceTest
        EXPORT performance-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
        EXPORT performance-targets
        NAMESPACE performance::
        DESTINATION ${INSTALL_CONFIGDIR}
)

##
## Config Version file
##
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/performanceConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/performanceConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/performanceConfig.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/performanceConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/performanceConfig.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
        )

##
## Export
##
export(
        EXPORT performance-targets
        NAMESPACE performance::
        FILE ${CMAKE_CURRENT_BINARY_DIR}/performanceTargets.cmake
)

export(PACKAGE performance)