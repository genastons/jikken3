void init() {
    getData();
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        passToProcessing("座ってください");
    } else {
        delay(100);
        orig_dist_hi = dist_hi;
        orig_dist_lo = dist_lo;

        // それぞれのモータを初期位置までに戻す処理
        // movedとwidthからどうにか求める

        // 腰幅の決定を行う。
        width = 500 - 100 * (moveSensor("ri", 0) + moveSensor("le", 0)) / MOVE_LIMIT;
}
