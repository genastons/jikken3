void init() {
    if (started  = 1) return 0;
    getData();
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        passToProcessing(NO_SEATED, NO_SEATED, NO_SEATED);
    } else {
        delay(100);
        orig_dist_hi = dist_hi;
        orig_dist_lo = dist_lo;

        // 腰幅の決定を行う。
        width = 500 - 100 * (moveSensor("ri", 0) + moveSensor("le", 0)) / MOVE_LIMIT;
        started = 1;
    }
}
