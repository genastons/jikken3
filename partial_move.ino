void partial_move(int servo, rotate)
{
    delay(15);
    servo.write(rotate);
    delay(10);
    servo.write(90);
    return 0;
}