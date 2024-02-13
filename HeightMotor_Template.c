/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/26/2023 07:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable RE_HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHightMotor_Move
 *
 */

void RE_HeightMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;
	
	/* Server Call Points */
	if (step == MOTOR_STEP_PLUS){
		status = Rte_Call_rpSetHeight_IoSetForward();
	}
	else if (step == MOTOR_STEP_MINUS){
		status = Rte_Call_rpSetHeight_IoSetReverse();
	}
	else {
		// unexpected input
	}
	
	
	
	
}

