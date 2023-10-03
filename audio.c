#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<portaudio.h>
#define SAMPLE_RATE(58000)
#define NUM_CHANNELS(1)
#define FRAMES_PER_BUFFER(256)
#define RECORDING_TIME(4.5)
Static int audioCallback(const void *inputBuffer,void *outputBuffer,unsigned long framesPerBuffer,const PaStreamCallbackTimeInfo *TimeInfo,PaSreamCallbackTimeInfo *timeInfo,PaStreamCallbackFlags statusFlags,
void *userData){
float *in=(float *)inputBuffer;
(void)outputBuffer;
(void)timeInfo;
(void)statusFlags;
(void)userData;
return paContinue;
}
int main(void)
{
PaError err;
PaStream *stream;
err=Pa_Initialize();
if(err!=paNoError){
fprint(stderr,"port:%s\n",pa_GetErrorText(err));
return 1;
}
Pa_Sleep(RECORDING_TIME*1000);
err=Pa_StartStream(stream);
if(err!=paNoError)
{
fprintf(stderr,"port:%s\n",pa_GetErrorText(err));
return 1;
}
Pa_Sleep(RECORDING_TIME*1000);
err=Pa_StopStream(stream);
if(err!=paNoError)
{
fprintf(stderr,"port:%s\n",pa_GetErrorText(err));
return 1;
}
err=Pa_closeStream(stream);
if(err!=paNoError)
{
fprintf(stderr,"port:%s\n",pa_GetErrorText(err));
return 1;
}
Pa_Terminate();
return 0;
}
