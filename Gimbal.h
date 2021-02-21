#ifndef GIMBAL_H_
#define GIMBAL_H_

#include <Servo.h>



class Gimbal
{
  public:
    Gimbal()
    {

    }

    void init(int ServoPortX, int ServoPortY)
    {
      this->ServoPortX = ServoPortX;
      this->ServoPortY = ServoPortY;
      ServoX.attach(ServoPortX);
      ServoY.attach(ServoPortY);
      Center();
      Center();
    }

    void Center()
    {
      SetX(0);
      SetY(0);
    }

    void Test()
    {
      Center();
      Center();

      delay(500);

      SetX(10);
      SetY(0);
      delay(250);
      Center();

      delay(500);

      SetX(0);
      SetY(10);
      delay(250);
      Center();

      delay(500);

      SetX(20);
      SetY(20);
      delay(250);
      Center();

      delay(500);

      SetX(40);
      SetY(40);
      delay(250);
      Center();

      delay(500);

      SetX(-40);
      SetY(-40);
      delay(250);
      Center();

    }

    void SetX(float deg = 0)
    {

      if (deg > XMinDeg && deg < XMaxDeg)
      {
        ServoX.write(deg + ServoOffsetX);
      }
      else if (deg <= XMinDeg)
      {
        ServoX.write(ServoOffsetX + XMinDeg);
      }
      else if (deg >= XMaxDeg)
      {
        ServoX.write(ServoOffsetX + XMaxDeg);
      }

    }

    void SetY(float deg = 0)
    {
      if (deg > YMinDeg && deg < YMaxDeg)
      {
        ServoY.write(deg + ServoOffsetY);
      }
      else if (deg <= YMinDeg)
      {
        ServoY.write(ServoOffsetY + YMinDeg);
      }
      else if (deg >= YMaxDeg)
      {
        ServoY.write(ServoOffsetY + YMaxDeg);
      }
    }

  private:
    int ServoPortX = 0;

    int ServoPortY = 0;

    int YMaxDeg = 30;
    int YMinDeg = -30;

    int XMaxDeg = 30;
    int XMinDeg = -30;

    int ServoOffsetX = 100;
    int ServoOffsetY = 90;

    Servo ServoX;
    Servo ServoY;
};

#endif /*GIMBAL_H_*/
