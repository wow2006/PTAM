add_executable(
  test_tracking
  testTracker.cpp
)

target_link_libraries(
  test_tracking
  PUBLIC
  GTest::GTest
  GTest::Main
  PTAM
)

add_test(
  NAME PTAM_Tests
  COMMAND test_tracking
)
