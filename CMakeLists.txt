cmake_minimum_required(VERSION 3.18.0)

project(firmware LANGUAGES C ASM)

add_executable(${PROJECT_NAME})


# 하위 디렉토리를 빌드에 포함시킨다. 
# 하위 디렉토리에는 CMakeLists.txt 파일이 있어야 한다. 
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/freertos)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sample)


# 다른 CMake 스크립트 파일의 내용을 현재 위치에 포함시켜 실행한다. 
# 표준 모듈을 로드할 때도 사용된다.
include(${CMAKE_CURRENT_LIST_DIR}/cmake/post.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/rfp.cmake)
