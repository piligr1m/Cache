cmake_minimum_required(VERSION 3.4)    # Минимальная версия CMake

set(CMAKE_CXX_STANDARD 17)             # Стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # Обязательность установки указанного стандарта (если OFF (по умолчанию), то воспринимается как совет)
git submodule add https://github.com/hunter-packages/gate.git tools/gate
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.7.0.tar.gz"
    SHA1 "e730118c7ec65126398f8d4f09daf9366791ede0"
    )
    project(MyAwesomeProject)
    string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")
    hunter_add_package(GTest) 
    find_package(GTest CONFIG REQUIRED)
    find_package(Threads)
    add_executable(
  tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)
