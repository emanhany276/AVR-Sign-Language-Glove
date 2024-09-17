/*
 * DFPLAYER_int.h
 *
 *  Created on: Mar 10, 2024
 *      Author: el bostan
 */

#ifndef DFPLAYER_INT_H_
#define DFPLAYER_INT_H_

void DFPlayer_SendCommand(char command,int parameter);
void DFPlayer_PlayTrack(int track);
void DFPlayer_SetVolume(int volume);


#endif /* DFPLAYER_INT_H_ */
