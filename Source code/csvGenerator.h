#pragma once

/*  
    Generates a csv record of average time and counter
*/
const void recordCSV(double avgTime, double avgCount){
    char csvHeaders[6][20] = {"BUBBLE SORT", "SELECTION SORT", "INSERTION SORT", "MERGE SORT", "SORT 5", "SORT 6"};
    int i;

    FILE *fp = fopen("Results/record.csv", "w+");

    fprintf(fp, " , AVG TIME, AVG COUNT\n");
    for (i = 0; i < 6; i++){
        fprintf(fp, "%s, %f, %f\n", csvHeaders[i], avgTime, avgCount);
        //switch to this ver for final using arrays
        //fprintf(fp, "%s, %f, %f\n", csvHeaders[i], avgTime[i], avgCount[i]);
    }

    fclose(fp);
}