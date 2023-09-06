#include <stdio.h>
#include <math.h>

int main()
{
    int bl, cr, mu, co;
    scanf("%d %d %d %d\n", &bl, &cr, &mu,&co);
    bl =150 -bl;
    cr = 200 - cr;
    mu = 300 - mu;
    co = 500 - co;
    printf("Need: %d bread loaves, %d croissants, %d muffins, and %d cookies\n", bl, cr, mu, co);
    double tCost = bl*2.50 + cr*1.20 + mu*0.80 + co*0.50;
    int tCostD = tCost;
    double tCostC = tCost - tCostD;
    int tCostCx = round(tCostC*100);
    printf("Cost: %d dollars and %d cents\n", tCostD, tCostCx);
    double blx = (double)bl/ 7;
    double crx = (double)cr /7;
    double mux = (double)mu / 7;
    double cox = (double)co / 7;
    printf("Average sold: %.2f bread loaves, %.2f croissants, %.2f muffins, and %.2f cookies per day\n", blx, crx, mux, cox);
}
