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
        void set_throttle(int throttle){
            this.throttle = throttle;
        }
        int get_throttle(){
            return throttle;
        }

        float direction = 0;
        float get_direction(){
            return direction;
        }

        float steering_angle = 0;   // turns the car
        void set_steering_angle(float steering_angle){
            this.steering_angle = steering_angle;
        }
        float get_steering_angle(){
            return steering_angle;
        }

        



        void calculate_acceleration(){
            acceleration[0] = throttle*cos(direction);
            acceleration[1] = throttle*sin(direction);
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