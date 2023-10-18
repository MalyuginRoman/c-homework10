#include "async.h"

void async::CoutObserver::update(Status s){
    if(s == Status::stop){
        std::cout<<"bulk: ";
        for(auto i : cb->commands){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
}
void async::LogObserver::update(Status s){
    if(s == Status::start){
        beginTime = boost::lexical_cast<std::string>(time(nullptr));
        fileName = beginTime + std::to_string(bulkCounter);
        fileName.append(".log");
    }
    else if(s == Status::stop){
        std::ofstream bulkFile(fileName, std::ios::out | std::ios::app);
        bulkFile<<"bulk: ";
        for(auto i : cb->commands){
            bulkFile<<i<<" ";
        }
        bulkFile<<std::endl;
        ++bulkCounter;
        bulkFile.close();
    }
}
