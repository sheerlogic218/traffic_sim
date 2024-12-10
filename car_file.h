#include <cmath>
#include <vector>


using namespace std;

const float DT = 0.1;

class car {
private:
    int id;
    float coord[2];
    float prev_coord[2];
    float velocity[2];
    float acceleration[2];
    float throttle = 0;   // forwards and backwards acceleration
    float direction = 0.0;
    float steering_angle = 0.0;   // turns the car


public:
    car(int id, int x, int y, int vx = 0, int vy = 0, int ax = 0, int ay = 0) {
        this->id = id;
        coord[0] = x;
        coord[1] = y;
        velocity[0] = vx;
        velocity[1] = vy;
        acceleration[0] = ax;
        acceleration[1] = ay;
    }

    void set_throttle(int throttle) {
        this->throttle = throttle;
    }
    int get_throttle() {
        return throttle;
    }

    float get_direction() {
        return direction;
    }

    void set_steering_angle(float steering_angle) {
        this->steering_angle = steering_angle;
    }
    float get_steering_angle() {
        return steering_angle;
    }

    void calculate_acceleration() {
        acceleration[0] = throttle * cos(direction);
        acceleration[1] = throttle * sin(direction);
    }



    void update_pos() {
        coord[0] = 2 * coord[0] - prev_coord[0] + acceleration[0] * DT * DT;
        coord[1] = 2 * coord[1] - prev_coord[1] + acceleration[1] * DT * DT;
        prev_coord[0] = coord[0];
        prev_coord[1] = coord[1];
        velocity[0] = (coord[0] - prev_coord[0]) / DT;
        velocity[1] = (coord[1] - prev_coord[1]) / DT;
    }

};

class traffic {
public:
    vector <car> cars;
    int number_of_cars;
    traffic(int num) {
        this->number_of_cars = num;
        for (int i = 0; i < number_of_cars; i++) {
            car c(i, 0, 0);
            cars.push_back(c);
        }
    }

};