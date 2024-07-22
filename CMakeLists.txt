# CMakeList.txt: проект CMake для search_engine; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/609281088cfefc76f9d0ce8
2e1ff6c30cc3591e5.zip
)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("search_engine")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (search_engine "search_engine.cpp" "search_engine.h"  )

gtest_discover_tests(search_engine)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(search_engine PRIVATE gtest_main)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET search_engine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.


