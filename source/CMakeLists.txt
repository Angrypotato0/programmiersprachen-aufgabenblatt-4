# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  beispiel.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(example glfw ${COPY_BINARY})

# Build tests
add_executable(tests
  tests.cpp)
add_executable(beispiel
  beispiel.cpp)
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp)
target_link_libraries(example
  m
  )
add_executable(aufgabe5
  aufgabe5.cpp)	
target_link_libraries(tests
  ${GLFW_LIBRARIES})


