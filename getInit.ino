int getInit() {
  Serial.println(100);
    if (started == 1) {
      return 0;
    } else {
      getData();
      if((dist_hi > 1500)|| (dist_ri > 1500) || (dist_le > 1500)) {
        Serial.write('e');
        return 0;
      }
      
      if ((dist_hi > NO_SEATED_DIST) || (dist_ri > NO_SEATED_DIST)|| (dist_le > NO_SEATED_DIST)) {
          st = status::NO_SEATED;
      } else if (abs(dist_hi - dist_lo) > 90) { // 姿勢を伸ばしてもらう
          st = status::INITIALIZING;
      } else {
          delay(100);
          getData();
          orig_dist = dist_lo;
          started = 1;
          return 0;
      }
      dist_hi = dist_lo = deg_hi = deg_si = 0;
    
    }
}
