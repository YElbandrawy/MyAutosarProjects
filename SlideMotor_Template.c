/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/26/2023 07:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable RE_SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void RE_SlideMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;
	
	/* Server Call Points */
	if (step == MOTOR_STEP_PLUS){
		status = Rte_Call_rpSetSlide_IoSetForward();
	}
	else if (step == MOTOR_STEP_MINUS){
		status = Rte_Call_rpSetSlide_IoSetReverse();
	}
	else {
		// unexpected input
	}
}

