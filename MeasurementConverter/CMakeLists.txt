cmake_minimum_required(VERSION 3.10.0)
project(MeasurementConverter VERSION 0.1.0 LANGUAGES C CXX)

add_library(MeasurementConverter STATIC measurement_converter.cc measurement_converter.h)
target_include_directories(MeasurementConverter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MeasurementConversion measurement_converison_main.cc)
target_link_libraries(MeasurementConversion PRIVATE MeasurementConverter)

