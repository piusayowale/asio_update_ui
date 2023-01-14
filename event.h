#pragma once

#include <utility>
#include <memory>
#include <functional>

using Func = std::function<void(void)>;

class EventPoller{

    class Poller;

    public:
        EventPoller();

        void postWork(Func f);

        void pollEvent();

        ~EventPoller();

    private:
        Poller* poll;
};