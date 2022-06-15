void init() {
    if (started  = 1) return 0;
    getData();
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        st = NO_SEATED;
    } else if (abs(dist_hi, dist_lo) > 20) { // 姿勢を伸ばしてもらう
        st = INITIALIZING; 
    } else {
        delay(100);
        getData();
        orig_dist_hi = dist_hi;
        orig_dist_lo = dist_lo;

        // 腰幅まで移動する
//        width = 500 - 100 * (moveSensor("ri", 0) + moveSensor("le", 0)) / MOVE_LIMIT;
        started = 1;
    }

    Serial.Write(255);
    Serial.Write(st);
    continue;
}
