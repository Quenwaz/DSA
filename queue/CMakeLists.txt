cmake_minimum_required(VERSION 3.5)

project(queue LANGUAGES CXX)


message(STATUS ----------------------------)
message(STATUS PROJECT_NAME=${PROJECT_NAME})

file(GLOB_RECURSE SRCCPP "*.cpp" "*.cc")

message(STATUS SRCCPP=${SRCCPP})

add_executable(${PROJECT_NAME}
  ${SRCCPP}
)



target_link_libraries(${PROJECT_NAME})
