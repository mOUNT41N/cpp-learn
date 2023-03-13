cmake_minimum_required(VERSION 3.0.0)
project(wms VERSION 0.1.0)

include(CTest)
enable_testing()

aux_source_directory(. SOURCE_DIR)
add_executable(main ${SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
