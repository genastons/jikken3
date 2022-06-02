int moveSensor(String side, int servo_moved) {
    if (side == "ri") {
        int ECHO = ECHO_RI;
        int TRIG = TRIG_RI;
        int servo = servo_right;
    } else if (side == "le") {
        int ECHO = ECHO_LE;
        int TRIG = TRIG_LE;
        int servo = servo_left;
    }

    // モータが先に動いている時、その分だけ移動して終わる
    if (servo_moved > 0) {
        int servo_tmp = servo.read();
        servo.write(servo_tmp + servo_moved);
        return 0;
    }

    int servo_pre = servo.read();
    float duration = 0;
    float distance = 0;
    while (true) {

        dititalWrite(TRIG, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
        duration = pulseIn(ECHO, HIGH);
        distance = duration / 2 * 340.0 / 1000;

        int pre = servo.read();
        if (distance > NO_SEATED_DIST) {
            servo.write(pre + DEGREE_TO_1CM);
            continue;
        }
        break;
    }
    return servo.read() - servo_pre;
}