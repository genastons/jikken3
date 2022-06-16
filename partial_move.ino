void partial_move(Servo servo, int rotate)
{
    delay(15);
    servo.write(rotate);
    delay(10);
    servo.write(90);
    return 0;
}
