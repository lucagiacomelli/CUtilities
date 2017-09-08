#include <stdio.h>
#include "utilities.h"


// Return an int from a date in format %dd-%mm-%YYYY
int get_weekday(char * str) {
    struct tm tm;
    memset((void *) &tm, 0, sizeof(tm));
    if (strptime(str, "%d-%m-%Y", &tm) != NULL) {
        time_t t = mktime(&tm);
        if (t >= 0) {
            return localtime(&t)->tm_wday; // Sunday=0, Monday=1, etc.
        }
    }
    return -1;
}

// Return the number of seconds from midnight from a formatted string %YYYY-%MM-%DD %HH:%MM:%SS 
int getSeconds(char * time) {
    char buffH[3];
    char buffM[3];
    char buffS[3];
    memcpy( buffH, &time[11], 2);
    buffH[2] = '\0';
    memcpy( buffM, &time[14], 2);
    buffM[2] = '\0';
    memcpy( buffS, &time[17], 2);
    buffS[2] = '\0';
    
    //printf("substring for hour: %s\n", buffH);
    //printf("substring for minutes: %s\n", buffM);
    //printf("substring for seconds: %s\n", buffS);
    
    int hrs = atoi( buffH );
    int min = atoi( buffM );
    int sec = atoi( buffS );
    
    int result  = hrs * 3600 + min * 60 + sec;
    //printf("%d\n", result);
    return result;
}


// Return the string %HH:%MM:%SS from the number of seconds from the midnight 
char* getTimeFromSeconds(int seconds) {
    int hr=0,min,sec;
    if(seconds>3600){
        min = seconds/60;
        sec = seconds%60;
        hr = min/60;
        min = min%60;
        //printf("Converted format %d hour %d mins %d secs",hr,min,sec);
    }
    else{
        min = seconds/60;
        sec = seconds%60;
        //printf("Converted format %d mins %d secs",min,sec);
    }
    
    char h[15];
    if(hr < 10)
    sprintf(h, "0%d", hr);
    else
    sprintf(h, "%d", hr);
    
    char m[15];
    if(min < 10)
    sprintf(m, "0%d", min);
    else
    sprintf(m, "%d", min);
    
    char s[15];
    if(sec < 10)
    sprintf(s, "0%d", sec);
    else
    sprintf(s, "%d", sec);
    
    char* result = malloc(60);
    strcpy(result,h);
    strcat(result, ":");
    strcat(result, m);
    strcat(result, ":");
    strcat(result, s);
    
    return result;
}


// Convert time from format %Y-%m-%d %H:%M:%S into UTC format
char* getUTCTime(char * time) {
    //printf("%s\n", time);
    struct tm  ts;
    //char result[100];
    char* result = (char* ) malloc(100);
    
    if (strptime(time, "%Y-%m-%d %H:%M:%S", &ts) == NULL){
        printf("%s\n", "Error in the conversion");
    }
    
    strftime(result, 100, "%FT%T%z", &ts);
    //printf("UTC time %s\n", result);
    return result;
}
