# CMakeList.txt: проект CMake для aisd_lab2_var12; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (aisd_lab2_var12 "aisd_lab2_var12.cpp" "hash_table.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET aisd_lab2_var12 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
