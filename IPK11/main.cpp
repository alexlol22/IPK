#include <iostream>
#include "Point.h"
#include <SDL2/SDL.h>
#include "sdlwrapper.hh"
#include <vector>
#include "Body.h"
#include "SDL_timer.h"
#include "Forces.h"

using std::cout;
using std::endl;
using std::vector;

void displayBodies(const vector<Body>& bodies, SDLCanvas& canvas){
    for (auto b : bodies){
        canvas.drawCircle(b.centerPos.x, b.centerPos.y, 4, b.color);
        canvas.display();
    }
}

void eulerStep (const Force& force, std::vector<Body>& bodies, double t, double dt){
    for (int i=0; i < bodies.size(); i++){
        auto& b = bodies[i];
        b.centerPos += b.velocity * dt;
        b.velocity += force(bodies, i, dt);
    }
}

int main(){
    const int canvasX = 1300;
    const int canvasY = 800;
    SDLCanvas canvas("TriBodySim", canvasX, canvasY);
    
    // std::vector<Body> bodies = {
    //     {{-100,0}, {0, +1}, 1600, {255,  0,  0}},
    //     {{+100,0}, {0, -1}, 1600, {100,255,255}},
    // };
    std::vector<Body> bodies = {
        {{ 0., 0.}, { 0., 0.}, 1e3, {255, 0, 0}},
        {{ 100., 0.}, { 0.,0.3}, 10., { 0,255, 0}},
        {{-200., 0.}, { 0.,0.2}, 20., { 150, 0, 150}},
        {{ 0.,250.}, {-0.25, 0.}, 10., {255,255, 0}},
    };

    ForceGravity f;
    
    for (auto& b : bodies){
        b.centerPos += {canvasX/2, canvasY/2};
    }
    Uint64 last = SDL_GetTicks();
    while (! canvas.windowClosed()){
        Uint64 current = SDL_GetTicks();
        float currentSecs = (current - last) / 100.0f;
        displayBodies(bodies, canvas);
        eulerStep(f, bodies, last, currentSecs);
        last = current;
    }
}