#pragma once
class Rat
{
public:
    Rat(double x, double y, double degrees);
    void Draw();
    void SpinLeft();
    void SpinRight();
    void ScurryForward();

    double x, y;
    double degrees;
    double radius;
};

