//
// Created by tung on 21/01/2019.
//

#ifndef FLAPPYBIRD_DEFINES_H
#define FLAPPYBIRD_DEFINES_H

#define SCREEN_W 480 * 0.9
#define SCREEN_H 800 * 0.9
#define FPS 60
#define GRAVITY_Y -980

//background
#define BACKGROUND_PATH "bg.png"

#define PIPE_PATH "pipe.png"
#define PIPE_STEP 1.5
#define SIZE_MAX_PIPE 10
#define DISTANCE_PIPE 200
#define PIPE_CENTER_COLLISION_BITMASK 0x00002
#define TAG_CENTER_PIPE 2
#define TAG_BARRIER 3

//bird
#define BIRD_COLLISION_BITMASK 0x000001
#define VELOCITY_BIRD 400
#define TAG_BIRD 1

//ground
#define GROUND_STEP 1.5

#endif //FLAPPYBIRD_DEFINES_H
