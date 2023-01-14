#include <raylib.h>
#include "event.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>

static int counter = 0;

std::string t = "";
std::atomic_bool control;

void increamenter(){

   t = std::to_string(counter++);
}

std::chrono::seconds getPresentSecondsCount(){
    auto t = std::chrono::high_resolution_clock::now().time_since_epoch();

    return std::chrono::duration_cast<std::chrono::seconds>(t);
}

int main(){
    
    control.store(true);
    EventPoller poller;

    poller.pollEvent();


    std::thread thr([](){
        auto start = getPresentSecondsCount();

        while (control.load())
        {
            auto now = getPresentSecondsCount();
            if(now >= start + std::chrono::seconds(1)){
                increamenter();
                start = getPresentSecondsCount();
            }

        }
    });
    
    InitWindow(600, 800, "Test");

    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLUE);
        Vector2 v1{300, 400};

        DrawTextEx(GetFontDefault(), t.data(), v1, 40, 20, MAROON);
        
        EndDrawing();
    }
    
    CloseWindow();
    control.store(false);
    thr.join();
}