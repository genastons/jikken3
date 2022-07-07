void partial_move(Servo servo, int rotate)
{
    delay(15);
    servo.write(rotate);
    delay(5);
    servo.write(90);
}
