# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalorieTracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalorieTracker_autogen.dir\\ParseCache.txt"
  "CalorieTracker_autogen"
  )
endif()
