# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (lcm)

# Add an executable
add_executable(lcm main.cpp)

execute_process(
    COMMAND git describe --contains HEAD
    OUTPUT_VARIABLE CURRENT_BRANCH_GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND git show ${CURRENT_BRANCH_GIT_TAG}
    OUTPUT_VARIABLE CURRENT_BRANCH_TAG_MESSAGE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# @&~ is never used string, so I accept it. it will be replaced \n in main.cpp
string(REPLACE "\n" " @&~\\\n" CURRENT_BRANCH_TAG_MESSAGE ${CURRENT_BRANCH_TAG_MESSAGE})

# version variable set
set(CURRENT_BRANCH_GIT_TAG ${CURRENT_BRANCH_GIT_TAG})
set(CURRENT_BRANCH_TAG_MESSAGE ${CURRENT_BRANCH_TAG_MESSAGE})
configure_file (
    "${PROJECT_SOURCE_DIR}/lcm_version.h.in"
    "${PROJECT_SOURCE_DIR}/lcm_version.h" @ONLY
)