void moveSensors(int sets[])
{
    int moved = moveSensor("ri", 0);

    if (moved > 0) {
        // モータの回転方向が互いに逆になるように配置するため、
        // 右のモータを基準にし、もう一方のモータは逆方向に動かす
        moveSensor("le", -moved);
    } else {
        moved = -moveSensor("le", 0);
        moveSensor("ri", moved);
    }

    return moved;
}