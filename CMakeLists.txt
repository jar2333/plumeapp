cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wx_cmake_fetchcontent_template LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(wxBUILD_SHARED OFF)

FetchContent_Declare(
   wxWidgets
   GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
   GIT_SHALLOW ON
)

FetchContent_Declare(
   MultiMarkdown
   GIT_REPOSITORY https://github.com/fletcher/MultiMarkdown-6.git
   GIT_SHALLOW ON
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_SHALLOW ON
  GIT_TAG "origin/main"
)

FetchContent_MakeAvailable(wxWidgets MultiMarkdown googletest)

set(SRCS src/main.cpp)

if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(main WIN32 ${SRCS} main.exe.manifest)
endif()

# Add the MultiMarkdown include directory
target_include_directories(
    main 
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${multimarkdown_SOURCE_DIR}/src
)

target_link_libraries(main PRIVATE wxcore wxnet libMultiMarkdown)
