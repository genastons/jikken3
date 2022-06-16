
void init() {
    if (started  = 1) return 0;
    getData();
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        st = status::NO_SEATED;
    } else if (abs(dist_hi - dist_lo) > 20) { // 姿勢を伸ばしてもらう
        st = status::INITIALIZING; 
    } else {
        delay(100);
        getData();
        orig_dist_hi = dist_hi;
        orig_dist_lo = dist_lo;
        started = 1;
    }

    Serial.write(255);
    Serial.write(st);
}
