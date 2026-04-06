    cmake_minimum_required(VERSION 3.10)

    project(DeviceMonitor VERSION 1.0)

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON) 

    find_package(CURL REQUIRED)


    add_executable(Device_agent 
        src/main.cpp
        src/collectors/MemCollector.cpp
        src/transport/HttpClient.cpp    
        src/utils/TimeUtils.cpp 
    )

target_link_libraries(Device_agent PRIVATE CURL::libcurl)



