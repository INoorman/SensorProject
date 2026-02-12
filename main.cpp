#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Sensor{
public:
    int id;
    int value;

    // function for generating random sensor data
    int generateData() {
        value = rand() % 100; // generate random value between 0 and 99
        return value;
    }

};

class DataLogger{
public:
    std::vector <int> data;
    // circular buffer
    void log(int value){
        if (data.size() < 10) {
            data.push_back(value);        // voeg toe als er plek is
        } else {
        // circular buffer: overschrijf oudste waarde
            data.erase(data.begin());     // verwijder eerste
            data.push_back(value);        // voeg nieuwe toe
        }         
    }

    void print(int sensorId){
        for(int i = 0; i < data.size(); i++){
            std::cout << "Sensor " << sensorId << " Data: " << data[i] << std::endl;
        }
    }
};

int main() {
    srand(time(0));  // seed the random number generator
    Sensor sensors[3];
    DataLogger loggers[3];

    // assign ids
    for(int i = 0; i < 3; i++){
        sensors[i].id = i;
    }

    // read data x times per sensor
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 3; j++){ 
            int data = sensors[j].generateData(); 
            loggers[j].log(data); 
        }
    }

    // print all values per sensor
    for(int i = 0; i < 3; i++){ loggers[i].print(i); }

    return 0;
}