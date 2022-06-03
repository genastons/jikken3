void partial_move(int servo, rotate)
{
    delay(10);
    servo.write(rotate);
    delay(10);
    servo.write(90);
    return 0;
}