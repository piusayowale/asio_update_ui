
#include "event.h"

#include <boost/asio.hpp>
#include <thread>
#include <iostream>

class EventPoller::Poller{
    public:
    explicit Poller():
        context{},
        work_gaurd{boost::asio::make_work_guard(context)}
        {

        }
        void postWork(Func f){
            context.post(f);
        }
        void runPoll(){
            thr = new std::thread([&](){
                    context.run();
            });
            
        }
        ~Poller(){
            work_gaurd.reset();
            if(thr){
                thr->join();
            }
            delete thr;
        }
    private:
    boost::asio::io_context context;
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work_gaurd;
    std::thread *  thr;
};


EventPoller::EventPoller():
    poll{ new EventPoller::Poller()}
{

}

void EventPoller::postWork(Func f){
        poll->postWork(f);
}

void EventPoller::pollEvent(){
    poll->runPoll();
}

EventPoller::~EventPoller(){
    delete poll;
}