#include <stdio.h>

int main(void) {
    const float BOSS_HEALTH = 3500;
    float damage_per_hit = 87.4;
    float hits_per_sedond = 3.5; 
    float dps = damage_per_hit * hits_per_sedond;
    
    printf("Your DPS is: %.2f !\n", dps);
    printf("You need %.2f seconds to kill him !\n\n", BOSS_HEALTH / dps);
    return 0;
}