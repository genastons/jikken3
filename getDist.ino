int getDist(int trig, int echo) {
    float duration;
    float distance;

    // 連続回転サーボでは動作変える必要あり。だるい
    // とりあえず回転→停止の１セットをカウントして、
    // 逆側のモータをその分回す。
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration / 2 * 340.0 / 1000;
    return distance;
}
