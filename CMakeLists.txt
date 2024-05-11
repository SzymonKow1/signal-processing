cmake_minimum_required(VERSION 3.15...3.27)

project(
  ${signal_processing}
  VERSION ${signal_processing_version}
  LANGUAGES CXX)

include_directories (${AudioFile_SOURCE_DIR})

add_definitions (-DPROJECT_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

add_subdirectory(matplotplusplus)

file (COPY res/test-audio.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_library(audio_visualization STATIC src/audio_visualization.cpp)
set_property(TARGET audio_visualization PROPERTY POSITION_INDEPENDENT_CODE ON)

python_add_library(_core MODULE src/binder.cpp WITH_SOABI)

target_link_libraries(audio_visualization PUBLIC matplot)
target_link_libraries(_core PRIVATE pybind11::headers)
target_link_libraries(_core PUBLIC audio_visualization)
#target_link_libraries (audio_visualization PRIVATE AudioFile)

target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

set_property(TARGET matplot PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS _core DESTINATION signal_processing)