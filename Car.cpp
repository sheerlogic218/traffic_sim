#include <cmath>
#include <vector>
#include "Car.h"

// Constant for time step
extern const float DT = 0.1f;




Car::Car(int id, float x, float y) {
    this->id = id;
    prev_coord[0] = x;
    prev_coord[1] = y;
    coord[0] = x;
    coord[1] = y;
    velocity[0] = 0.0;
    velocity[1] = 0.0;
    acceleration[0] = 0.0;
    acceleration[1] = 0.0;
    throttle = 0.0;   // forwards and backwards acceleration
    direction = 0.0;
    steering_angle = 0.0;   // turns the car
}

Car::Car(int id, float x, float y, float vx, float vy, float ax, float ay) {
    this->id = id;
    prev_coord[0] = x -vx * DT;
    prev_coord[1] = y -vy * DT;
    coord[0] = x;
    coord[1] = y;
    velocity[0] = vx;
    velocity[1] = vy;
    acceleration[0] = ax;
    acceleration[1] = ay;
    throttle = 0;   // forwards and backwards acceleration
    direction = 0;
    steering_angle = 0;   // turns the car
}

void Car::set_throttle(float throttle) {
    this->throttle = throttle;
}

float Car::get_throttle() {
    return throttle;
}

float Car::get_direction() {
    return direction;
}
void Car::set_steering_angle(float steering_angle) {
    this->steering_angle = steering_angle;
}
float Car::get_steering_angle() {
    return steering_angle;
}

void Car::update_direction() {
    direction += steering_angle * DT;
}
 
void Car::calculate_acceleration() {
    acceleration[0] = throttle * cos(direction) * cos(steering_angle);
    acceleration[1] = throttle * sin(direction) * cos(steering_angle);
}

void Car::update_pos() {
    update_direction();
    calculate_acceleration();
    temp_coord[0] = coord[0];
    temp_coord[1] = coord[1];
    coord[0] = 2 * coord[0] - prev_coord[0] + acceleration[0] * DT * DT;
    coord[1] = 2 * coord[1] - prev_coord[1] + acceleration[1] * DT * DT;
    prev_coord[0] = temp_coord[0];
    prev_coord[1] = temp_coord[1];
    velocity[0] = (coord[0] - prev_coord[0]) / DT;
    velocity[1] = (coord[1] - prev_coord[1]) / DT;
}


float Car::get_x() {
    return coord[0];
}

float Car::get_y() {
    return coord[1];
}

float Car::get_vx() {
    return velocity[0];
}

float Car::get_vy() {
    return velocity[1];
}
