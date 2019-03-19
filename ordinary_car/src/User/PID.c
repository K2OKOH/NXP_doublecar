#include "include.h"

float encoder_P = 3,encoder_D = 0;
int16 en_err_now=0,en_err_next=0,en_err_last=0;
int32 encoder_out = 0;

int32 motor_encoder_PD(int16 speed,int16 quad)
{
  en_err_now = (speed - quad);
  encoder_out+=(int32)(encoder_P*(en_err_now-en_err_next)+encoder_D*(en_err_now-2*en_err_next+en_err_last));
  en_err_last=en_err_next;
  en_err_next=en_err_now;
  return encoder_out;
}