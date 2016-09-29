/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: TylerShipman
 *
 * Created on September 22, 2016, 10:08 AM
 */

#include <stdio.h>
#include <stdlib.h>



double mean(int values[], int size);
int findMax(int values[], int size);


/*
 * 
 */
int main(int argc, char** argv) {
    int userChoice;
    double userScaleFactor;
    FILE* fp_r;
    FILE* fp_w;
    FILE* fp_Stats;
    FILE* fp_Centered;
    FILE* fp_Normalized;
    char inputFileName[80];
    char outputFileName[80];
    char outputStatsFile[80];
    char outputCentered[80];
    char outputNormalized[80];
    int i = 0;
    int sizeOfFile;
    int maxValue;
    double meanValue;
    int fileMax = 0;
    
    
    
    
    
    
    printf("Please enter a number 1-11 to choose the corresponding file:\n");
    scanf("%d", &userChoice);
    
    if(userChoice < 10){
        
        sprintf(inputFileName, "Raw_data_0%d.txt", userChoice);
        
    }
    else{
        
        sprintf(inputFileName, "Raw_data_%d.txt", userChoice);
    
    }
    
    
    fp_r = fopen(inputFileName,"r");
    if(fp_r == NULL){
        
        printf("\n\nError opening file. Please restart the program and try again.\n\n");
        return -1;
        
    }
    
    fscanf(fp_r, "%d %d", &sizeOfFile, &maxValue);
    
    int fileValues[sizeOfFile];
    int scaledFileValues[sizeOfFile];
    double centeredFileValues[sizeOfFile];
    double normalizedFileValues[sizeOfFile];
    
    for(i = 0; i < sizeOfFile; i++){
         
        fscanf(fp_r, "%d", &fileValues[i]);
            
    }
    
    printf("\n\n");
    
    for(i = 0; i <sizeOfFile; i++){
        
        printf("%d\n", fileValues[i]);
        
    }
    
    
    printf("\n\nEnter a scale factor:\n");
    scanf("%lf", &userScaleFactor);
    
    for(i = 0; i < sizeOfFile; i++){
        
        scaledFileValues[i] = fileValues[i] * userScaleFactor;
        
    }
    
    printf("\n\n");
    
    for(i = 0; i <sizeOfFile; i++){
        
        printf("%d\n", scaledFileValues[i]);
        
    }

    if(userChoice < 10){

        sprintf(outputFileName, "Offset_data_0%d.txt", userChoice);
    
    }
    else{
        
        sprintf(outputFileName, "Offset_data_%d.txt", userChoice);
    
    }
    
    fp_w = fopen(outputFileName, "ab+");
    
    fprintf(fp_w, "%d %d\n", sizeOfFile, maxValue);
    
    for(i = 0; i < sizeOfFile; i++){
        
        fprintf(fp_w, "%d\n", scaledFileValues[i]);
        
    }
    
    
    
    
    if(userChoice < 10){
        
        sprintf(outputStatsFile, "Statistics_data_0%d.txt", userChoice);
        
    }
    else{
        
        sprintf(outputStatsFile, "Statistics_data_%d.txt", userChoice);
    
    }
    
    fp_Stats = fopen(outputStatsFile, "ab+");
    
    meanValue = mean(fileValues,sizeOfFile);
    fileMax = findMax(fileValues,sizeOfFile);
    
    fprintf(fp_Stats, "%lf %d", meanValue, fileMax);
    
    if(userChoice < 10){
        
        sprintf(outputCentered, "Centered_data_0%d.txt", userChoice);
        
    }
    else{
        
        sprintf(outputCentered, "Centered_data_%d.txt", userChoice);
    
    }
    
    fp_Centered = fopen(outputCentered, "ab+");
    
    for(i = 0; i < sizeOfFile; i++){
        
        centeredFileValues[i] = (double)(fileValues[i]) - meanValue;
        
    }
    
    fprintf(fp_Centered, "%d %d\n", sizeOfFile, maxValue);
    
    for(i = 0; i < sizeOfFile; i++){
        
        fprintf(fp_Centered, "%lf\n", centeredFileValues[i]);
        
    }
    
    if(userChoice < 10){
        
        sprintf(outputNormalized, "Normalized_data_0%d.txt", userChoice);
        
    }
    else{
        
        sprintf(outputNormalized, "Normalized_data_%d.txt", userChoice);
    
    }
    
    
    fp_Normalized = fopen(outputNormalized, "ab+");
    
    for(i = 0; i < sizeOfFile; i++){
        
        normalizedFileValues[i] = (double)(fileValues[i])/ maxValue;
        
    }
    
    fprintf(fp_Normalized, "%d %d\n", sizeOfFile, maxValue);
    
    for(i = 0; i < sizeOfFile; i++){
        
        fprintf(fp_Normalized, "%lf\n", normalizedFileValues[i]);
        
    }
    
    
    
    
    
    fclose(fp_Normalized);
    fclose(fp_Centered);
    fclose(fp_Stats);
    fclose(fp_r);
    fclose(fp_w);
    return (EXIT_SUCCESS);
}

double mean(int values[],int size){
    int i = 0;
    double sum = 0;
    double average = 0;
    for(i = 0; i < size; i++){
        
        sum += (double) values[i];
        
    }
    
    average = sum /(double) size;
    
    return average;
    
}
int findMax(int values[],int size){
    
    int maximum = values[0];
    int i = 0;
    for(i = 1; i < size; i++){
        
        if(maximum < values[i]){
            maximum = values[i];
        }
    }
    
    return maximum;
    
    
}