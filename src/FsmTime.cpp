/*
 * FsmTimer.cpp
 *
 *  Created on: 07 мая 2018 г.
 *      Author: aleksandr.yanovskiy
 */

#include "FsmTimer.h"

namespace graf {

/**
 * timeResponce max interval = 4,294,967,295 milliseconds or 49,7 days
 */
FsmTimer::FsmTimer(unsigned long timeResponce, bool autoStop) {
	LOG_LN(F("C"));
	timeResponce_ = timeResponce;
	autoStop_ = autoStop;
	start();
}

FsmTimer::~FsmTimer() {
	// TODO Auto-generated destructor stub
	LOG_LN(F("D"));
}

/**
 * start timer
  */
void FsmTimer::start() {
	LOG_LN(F("start()"));
	if (timeResponce_ == 0)
		stop();
	else
		stop_ = false;

	beginTime_ = millis();
}

void FsmTimer::stop() {
	LOG_LN(F("stop()"));
	stop_ = true;
}

void FsmTimer::setTime(unsigned long timeResponce) {
	LOG_LN(F("setTime()"));
	timeResponce_ = timeResponce;
	start();
}


/**
 * return true, if time is out
 * if timer not runs, return true always
 */
bool FsmTimer::isTimeOut() {
	LOG_LN(F("isTimeOut()"));

	if ( stop_ )
		return false;

	unsigned long currTime = millis();

	if (currTime >= beginTime_) {
		LOG_LN(F("currTime >= beginTime"));
		if ( (currTime - beginTime_) >= timeResponce_) {
			//time is out
			if (autoStop_)
				stop();
			else
				start();

			return true;
		}
		else
			return false;
	}
	else {
		LOG_LN(F("currTime < beginTime"));
		//overload timer value
		unsigned long maxTime = 0;//~0;

		if ( (maxTime - beginTime_ + currTime) >= timeResponce_ ) {
			//time is out
			if (autoStop_)
				stop();
			else
				start();

			return true;
		}
		else
			return false;
	}
}

} /* namespace graf */
