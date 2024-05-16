cmake_minimum_required(VERSION 3.15...3.27)

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

add_definitions (-DPROJECT_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")

find_package( OpenCV REQUIRED )
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

include_directories (${AudioFile_SOURCE_DIR})
include_directories (${OpenCV_INCLUDE_DIRS})

add_subdirectory(matplotplusplus)

file (COPY res/test1.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_library(audio_visualization STATIC src/audio_visualization.cpp)
add_library(signal_generator STATIC src/signal_generator.cpp)
add_library(Bilinear_interpolation STATIC src/Bilinear_interpolation.cpp)
add_library(signal_filtration STATIC src/signal_filtration.cpp)

python_add_library(_core MODULE src/binder.cpp WITH_SOABI)

target_link_libraries(audio_visualization PUBLIC matplot)
target_link_libraries(signal_generator PUBLIC matplot)
target_link_libraries(_core PRIVATE pybind11::headers)
target_link_libraries(_core PUBLIC audio_visualization)
target_link_libraries(_core PUBLIC signal_generator)
target_link_libraries(_core PUBLIC Bilinear_interpolation)
target_link_libraries(Bilinear_interpolation PUBLIC ${OpenCV_LIBS})
target_link_libraries(signal_filtration PUBLIC ${OpenCV_LIBS})
target_link_libraries(_core PUBLIC signal_filtration)

target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

set_property(TARGET matplot PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET audio_visualization PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET Bilinear_interpolation PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET signal_generator PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET signal_filtration PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS _core DESTINATION signal_processing)