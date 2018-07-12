/*
 * FsmTimer.h
 *
 *  Created on: 07 мая 2018 г.
 *      Author: aleksandr.yanovskiy
 *
 *
 */

#ifndef LIBRARIES_GRAF_FSMTIMER_TIMER_H_
#define LIBRARIES_GRAF_FSMTIMER_TIMER_H_

#include "Common.h"

namespace graf {

class FsmTimer {
public:
	FsmTimer(unsigned long timeResponce = 0, bool autoStop = false);
	virtual ~FsmTimer();
	void setTime(unsigned long timeResponce);
	bool isTimeOut();
	void start();
	void stop();

private:
	//unsigned char overflowCnt_; //255*50day = 425 year overflow
	bool autoStop_;
	bool stop_;
	unsigned long timeResponce_; //49.71 days
	unsigned long beginTime_;
};

} /* namespace graf */

#endif /* LIBRARIES_GRAF_FSMTIMER_TIMER_H_ */
