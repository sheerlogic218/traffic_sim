#include <iostream>
#include <cmath>


float dt = 0.1;

class car{
    public:
        int id;
        int coord[2];
        int prev_coord[2];
        int velocity[2];
        int acceleration[2];
        car(int id, int x, int y, int vx = 0, int vy = 0, int ax = 0, int ay = 0){
            this.id =id;
            coord[0] = x;
            coord[1] = y;
            velocity[0] = vx;
            velocity[1] = vy;
            acceleration[0] = ax;
            acceleration[1] = ay;
        }
        int throttle = 0;   // forwards and backwards acceleration
        int turning_direction = 0; // +- 90 degrees, positive is right

        void calculate_acceleration(){
            acceleration[0] = throttle*cos(turning_direction);
            acceleration[1] = throttle*sin(turning_direction);
        }
        
        void update_direction(){
            float angle = atan2(velocity[1], velocity[0]);
            angle += turning_direction;
            velocity[0] = cos(angle);
            velocity[1] = sin(angle);
        }

        void update_pos(){
            coord[0] = 2*coord[0] - prev_coord[0] + acceleration[0]*dt*dt;
            coord[1] = 2*coord[1] - prev_coord[1] + acceleration[1]*dt*dt;
            prev_coord[0] = coord[0];
            prev_coord[1] = coord[1];
            velocity[0] = (coord[0] - prev_coord[0])/dt;
            velocity[1] = (coord[1] - prev_coord[1])/dt;
        }
        
};

class traffic{
    public:
        int number_of_cars;
        traffic(int number_of_cars){
            this.number_of_cars = number_of_cars;
            car cars[number_of_cars];
            for(int i = 0; i < number_of_cars; i++){
                cars[i] = car(i, 0, 0);
            }
        }

}