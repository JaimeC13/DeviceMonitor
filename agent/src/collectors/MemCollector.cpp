#include  "MemCollector.hpp"
#include <fstream>
#include <string>
#include <sstream>


double MemCollector::getMemUsage(){
    std::ifstream file("/proc/meminfo");
    std::string line;
    long long total = 0, available = 0;  // Use long long to handle large memory values


    if (!file.is_open()) { // file.is_open() checks if the file was opened successfully
        return 0.0; // Return 0.0 to indicate an error
    }

    while (std::getline(file, line)){
        if(line.find("MemTotal:")!= std::string::npos){
            std::istringstream ss(line); //convert on string to stream
            std::string label;
            ss >> label >> total; // Extract the label and total memory value
        }
        else if(line.find("MemAvailable:")!= std::string::npos){ // .fined() checks if the substring "MemAvailable:" is present in the line
            std::istringstream ss(line); //convert on string to stream
            std::string label;
            ss >> label >> available; // Extract the label and available memory value
        }

        if(total > 0 && available > 0){ // Check if both total and available memory values were successfully extracted
            break; // Exit the loop early if we have both values
        }


    }

    
    file.close(); // Close the file after reading

    if (total == 0) return 0.0;

    return (double) (total - available) / total * 100.0;
 
}