#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment2

int main()
{
    double y_axis, initial_speed, delta_t, sim_speed, sim_distance, actual_distance, t;
    bool matched;
    sim_distance = 0;
    delta_t = 0.01;
    t = 1.0;

    do  // Input validation
    {
        cout << "The speed can only be in the range [50,150]" << endl << "Enter your speed: ";
        cin >> initial_speed;
        cin.ignore(10000, '\n');
        sim_speed = initial_speed;
    }
    while(initial_speed > 150 || initial_speed < 50);

    while(sim_distance >= 0)
    {
        system("cls");
        matched = 1;
        y_axis = ((initial_speed * initial_speed) / (2 * 9.81));  // 2as = (v^2() - (u^2)  // finding maximum height
        for(int j = 0; j <= y_axis; y_axis -= 10)  // printing y-axis till maximum value  // y-axis represents distance above ground
        {
            y_axis = ((round(y_axis / 10.0)) * 10.0);  // rounding to nearest 10
            cout << setw(4) << setfill('0') << y_axis;
            if(matched == 1)
            {
                for(int mili_s = 1; mili_s <= 100; ++mili_s)  // 100 mili seconds
                {
                    sim_distance = sim_distance + (sim_speed * delta_t);  // updating value for simulated distance
                    sim_speed = sim_speed - (9.8 * delta_t);  // updating value for simulated speed
                }

                actual_distance = (initial_speed * t) - (0.5 * 9.8 * t * t);  // s = ut - (1 / 2)gt^2
                matched = 0;
            }

            if(((round(sim_distance / 10.0)) * 10.0) == y_axis)  // comparing to y-axis
            {
                cout << "    *    ";
                cout << "Time = " << t;
                cout << "    Simulated Distance = "  << sim_distance;
                cout << "    Actual Distance = " << actual_distance;
                t = t + 1;
            }
            cout << endl;
        }
        
        cout << "Rounded sim_distance = " << ((round(sim_distance / 10.0)) * 10.0) << endl;
        matched = 1;
        cout << "Press <ENTER> to continue";
        cin.get(); // waiting for user input
    }
    return 0;
}