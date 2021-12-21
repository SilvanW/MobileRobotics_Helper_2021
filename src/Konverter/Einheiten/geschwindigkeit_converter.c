/*geschwindigkeit_converter.c

Autor: Corsin Monn
Firma: FHGR Mobile Robotics
Date: 2021/12/13
Version: 0.1
Changelog:

*/
#include <stdio.h> 
#include <stdlib.h>		
#include <string.h>

#include "geschwindigkeit_converter.h"

void mps_to_kmph(float v){
    float vu = v * 3.6;
    printf("%.3f m/s = %.3f km/h\n", v, vu);
    return;
}
/*void mps_to_fps(float v){
    vu = v * 3.281;
    printf("%.3f m/s = %.3f fps\n", v, vu);
    return 0;
}*/
void mps_to_mph(float v){
    float vu = v * 2.237;
    printf("%.3f m/s = %.3f mph\n", v, vu);
    return;
}
void mps_to_knot(float v){
    float vu = v * 1.944;
    printf("%.3f m/s = %.3f Knoten\n", v, vu);
    return;
}

void kmph_to_mps(float v){
    float vu = v / 3.6;
    printf("%.3f km/h = %.3f m/s\n", v, vu);
    return;
}
void kmph_to_mph(float v){
    float vu = v / 1.609;
    printf("%.3f km/h = %.3f mph\n", v, vu);
    return;
}
void kmph_to_knot(float v){
    float vu = v / 1.852;
    printf("%.3f km/h = %.3f Knoten\n", v, vu);
    return;
}
void kmph_to_fps(float v){
    float vu = v / 1.097;
    printf("%.3f km/h = %.3f fps\n", v, vu);
    return;
}

/*void mph_to_fps(float v){
    vu = v * 1.467;
    printf("%.3f mph = %.3f fps\n", v, vu);
    return 0;
}*/
void mph_to_mps(float v){
    float vu = v /2.237;
    printf("%.3f mph = %.3f m/s\n", v, vu);
    return;
}
void mph_to_kmph(float v){
    float vu = v * 1.609;
    printf("%.3f mph = %.3f km/h\n", v, vu);
    return;
}
void mph_to_knot(float v){
    float vu = v /1.151;
    printf("%.3f mph = %.3f Knoten\n", v, vu);
    return;
}

void knot_to_mph(float v){
    float vu = v * 1.151;
    printf("%.3f Knoten = %.3f mph\n", v, vu);
    return;
}
/*void knot_to_fps(float v){
    vu = v * 1.688;
    printf("%.3f Knoten = %.3f fps\n", v, vu);
    return 0;
}*/
void knot_to_mps(float v){
    float vu = v / 1.944;
    printf("%.3f Knoten = %.3f m/s\n", v, vu);
    return;
}
void knot_to_kmph(float v){
    float vu = v * 1.852;
    printf("%.3f Knoten = %.3f km/h\n", v, vu);
    return;
}

/*void fps_to_mph(float v){
    vu = v / 1.467;
    printf("%.3f fps = %.3f mph\n", v, vu);
    return 0;
}
void fps_to_mps(float v){
    vu = v / 3.281;
    printf("%.3f fps = %.3f m/s\n", v, vu);
    return 0;
}
void fps_to_kmph(float v){
    vu = v * 1.097;
    printf("%.3f fps = %.3f km/h\n", v, vu);
    return 0;
}
void fps_to_knot(float v){
    vu = v / 1.688;
    printf("%.3f fps = %.3f Knoten\n", v, vu);
    return 0;
}*/
