#include <iostream>
#include <vector>

#include "./headers/Record.hpp"
#include "./headers/Point.hpp"

std::vector<Record> buildRecords()
{
    std::vector<Record> records;

    records.push_back(Record(200, 0.75, 5120));
    records.push_back(Record(202, 0.72, 5370));
    records.push_back(Record(204, 0.70, 5560));
    records.push_back(Record(206, 0.68, 5800));
    records.push_back(Record(208, 0.67, 6030));
    records.push_back(Record(210, 0.66, 6240));

    return records;
}


int main(int argc, char** argv)
{
    std::vector<Record> records = buildRecords();

    for (Record r: records) 
    {
        std::cout << r.getTime() << " " << r.getAngle() << " " << r.getRadius() << std::endl;
    }

    std::cout << (records[0].toCartesian()).getX() << std::endl;
    exit(0);
}