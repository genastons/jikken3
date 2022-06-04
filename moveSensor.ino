int moveSensor(String side, int moved_count) 
{
    if (side == "ri") {
        int ECHO = ECHO_RI;
        int TRIG = TRIG_RI;
        int servo = servo_ri;
    } else if (side == "le") {
        int ECHO = ECHO_LE;
        int TRIG = TRIG_LE;
        int servo = servo_le;
    }

    int count = 0;

    // 他のモータが先に動いている時、その分だけ移動して終わる
    // 左右のモータで回転方向逆なので符号反転してpartial_moveに渡す
    if (moved_count > 0) {
        for (int i = 0; i < moved_count; i++) {
            // 先に動かした方の処理の実行時間次第で、delayを入れる
            // delay(10);
            partial_move(servo, -ROTATE);
        }
        return 0;
    }

    while (count < MOVE_LIMIT) {
        // 体までの距離を求め、それが基準値以上だったら座ってない判定
        if (getDist(TRIG, ECHO) >= NO_SEATED_DIST) {
            partial_move(servo, ROTATE);
            count++;
            continue;
        }
        break;
    }
    return count;
}