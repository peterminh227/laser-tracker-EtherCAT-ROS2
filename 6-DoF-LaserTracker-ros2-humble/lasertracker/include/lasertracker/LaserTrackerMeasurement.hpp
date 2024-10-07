#include <iostream>
#include <cmath>  


class LaserTrackerMeasurement
{

public:
    double angle_hz, angle_vt, distance;
    double quaternion[4];

    LaserTrackerMeasurement()
    {
        angle_hz = 0.;
        angle_vt = 0.;
        distance = 0.;
        for (int i = 0; i < 4; i++)
        {
            quaternion[i] = 0.;
        }
        quaternion[0] = 1.;
    }

    void set_position(double dist, double hz, double vt)
    {
        distance = dist;
        angle_hz = hz;
        angle_vt = vt;
    }

    void set_orientation(double q0, double q1, double q2, double q3)
    {
        quaternion[0] = q0;
        quaternion[1] = q1;
        quaternion[2] = q2;
        quaternion[3] = q3;
    }

    double get_x() const
    {
        return distance * std::cos(angle_vt) * std::cos(angle_hz);
    }

    double get_y() const
    {
        return distance * std::cos(angle_vt) * std::sin(angle_hz);
    }

    double get_z() const
    {
        return distance * std::sin(angle_vt);
    }

    void print() const
    {
        std::cout << "Position: "
                  << "distance=" << distance << ", "
                  << "angle_hz=" << angle_hz << ", "
                  << "angle_vt=" << angle_vt << std::endl;
        std::cout << "Orientation: "
                  << "q0=" << quaternion[0] << ", "
                  << "q1=" << quaternion[1] << ", "
                  << "q2=" << quaternion[2] << ", "
                  << "q3=" << quaternion[3] << std::endl;
    }
};
