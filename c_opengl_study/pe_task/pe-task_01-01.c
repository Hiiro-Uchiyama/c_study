#include <stdio.h>
#include <math.h>

int main (){

    int height;
    int lower = 150;
    int upper = 190;
    int step = 5;

    double weightStd;
    double weightIdeal;
    double weightModel;

    printf("身長 標準体重 美容体重 モデル体重\n\n");

    for (height = lower; height <= upper; height += step){
        weightStd = (height - 100) * 0.9;
        printf("%3dcm %2.2fkg", height, weightStd);

        weightIdeal = pow(height / 100.0, 2.0) * 20;
        printf("%2.2fkg", weightIdeal);

        weightModel = pow(height / 100.0, 2.0) * 19;
        printf("%2.2fkg\n", weightModel);
    }
    return 0;
}
