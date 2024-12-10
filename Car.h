#pragma once
#ifndef CAR_TRAFFIC_H
#define CAR_TRAFFIC_H

#include <cmath>
#include <vector>

// Car class definition
class Car {
    int id;
    float coord[2];
    float prev_coord[2];
    float velocity[2];
    float acceleration[2];
    float throttle;
    float direction;
    float steering_angle;

public:
	Car(int id, float x, float y);
    Car(int id, float x, float y, float vx, float vy, float ax, float ay);
    void set_throttle(float throttle);
    float get_throttle();
    float get_direction();
    void set_steering_angle(float steering_angle);
    float get_steering_angle();
    void calculate_acceleration();
    void update_pos();
};

#endif

