void determinePosture(void)
{
    if ((dist_hi > NO_SEATED_DIST) && (dist_lo > NO_SEATED_DIST)) {
        st = NO_SEATED;
    } else if () { // 調べろ  
        status = BAD_POSTURE;
    } else if (abs(dist_ri - dist_le) > TWIST) {
        status = TWISTED;
    }
    return 0;
}