/*
 * trigger_suzuki.cpp
 *
 * @date Oct 4, 2021
 * @author Andrey Belomutskiy, (c) 2012-2021
 */

#include "pch.h"

#include "trigger_suzuki.h"

void initializeSuzukiG13B(TriggerWaveform *s) {
	s->initialize(FOUR_STROKE_CRANK_SENSOR, SyncEdge::RiseOnly);

	int w = 5;
	
	s->addToothRiseFall(95, w);

	s->addToothRiseFall(125, w);
	
	s->addToothRiseFall(180, w);

	s->addToothRiseFall(275, w);

	s->addToothRiseFall(305, w);

	s->addToothRiseFall(360, w);

  s->tdcPosition = 180 + 6;
	s->isSynchronizationNeeded = false;
	s->shapeWithoutTdc = true;
}

void initializeSuzukiK6A(TriggerWaveform *s) {
	s->initialize(FOUR_STROKE_CAM_SENSOR, SyncEdge::RiseOnly);
	float w = 5;

  int secondTooth = 15;

  // a bit lame: we start with falling front of first tooth
  s->addEvent360(5, TriggerValue::FALL);

  s->addToothRiseFall(secondTooth, w);
  s->addToothRiseFall(43, w);

  s->addToothRiseFall(120, w);
  s->addToothRiseFall(120 + secondTooth, w);
  s->addToothRiseFall(158, w);
  s->addToothRiseFall(158 + secondTooth, w);

  s->addToothRiseFall(240, w);
  s->addToothRiseFall(240 + secondTooth, w);
  s->addToothRiseFall(283, w);

  // a bit lame: we end with rising front of first tooth
  s->addEvent360(360, TriggerValue::RISE);

	s->setTriggerSynchronizationGap(4.47);
	s->setSecondTriggerSynchronizationGap(0.65);
}
