# CMakeList.txt : CMake project for FinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


project ("FinalProject")
add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO)
# Add source to this project's executable.
add_executable (FinalProject "FinalProject.cpp" "FinalProject.h" "Test.cpp" "Test.h" "UniformTest.h" "NormalTest.h" "UniformTest.cpp" "NormalTest.cpp")
# add_executable (TestNana "TestNana.cpp" "TestNana.h")
target_include_directories(FinalProject PUBLIC "C:\\Users\\hglol\\Desktop\\Fall2023\\C++ Programming\\Week 8\\nana_1.7.4\\nana\\include")
target_link_directories(FinalProject PUBLIC "C:\\Users\\hglol\\Desktop\\Fall2023\\C++ Programming\\Week 8\\nana_1.7.4\\nana\\build\\bin")


target_link_libraries(FinalProject debug "nana_v143_Debug_x64" optimized "nana_v143_Release_x64")


# TODO: Add tests and install targets if needed.
