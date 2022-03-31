add_executable(Ctests main_tests.cpp tests.cpp)
target_link_libraries(Ctests gtest_main gtest gmock Threads::Threads)