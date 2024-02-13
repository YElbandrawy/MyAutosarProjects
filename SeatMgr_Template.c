/**
 *
 * \file SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/5/2024 06:23 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMgr.h"

uint8_t AdjustNeeded( SensorPositionType position, MultiStateBtnType weight, StepMotorStepType* step){
	uint8_t RetVal = FALSE;

	switch (position){
		case SENSOR_POSITION_STEP_0:
			if ( weight > 60){
				(*step) = MOTOR_STEP_PLUS ;
				RetVal = TRUE ;
			}
			break ;
		
		case SENSOR_POSITION_STEP_1:
			if ( weight > 80){
				(*step) = MOTOR_STEP_PLUS ;
				RetVal = TRUE ;
			}
			else if(weight < 60){
				(*step) = MOTOR_STEP_MINUS ;
				RetVal = TRUE ;
			}
			else{
				RetVal = FALSE;  //No need to Move motor
			}
			break ;
		
		case SENSOR_POSITION_STEP_2:
			if (weight > 100){
				(*step) = MOTOR_STEP_PLUS ;
				RetVal = TRUE ;
			}
			else if(weight < 80){	
				(*step) = MOTOR_STEP_MINUS ;
				RetVal = TRUE ;	
			}
			else{
				RetVal = FALSE; //No need to Move motor
			}
			break ;
		
		case SENSOR_POSITION_STEP_3:
			if ( Weight < 100){
				(*step) = MOTOR_STEP_MINUS ;
				RetVal = TRUE ;
			}
			break ;
	}
}	
	

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */
void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	uint8_t AdjustStatus;

	/* Server Call Points */
	status = Rte_Call_rpHeightSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	AdjustStatus = AdjustNeeded( position , weight , &step );
	if(AdjustStatus)
	{
		status = Rte_Call_rpHeightMotor_Move(step);	
	}
	
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	uint8_t AdjustStatus;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	AdjustStatus = AdjustNeeded( position , weight , &step );
	if(AdjustStatus)
	{
		status = Rte_Call_rpInclineMotor_Move(step);
	}
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	uint8_t AdjustStatus;
	
	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	AdjustStatus = AdjustNeeded( position , weight , &step );
	if(AdjustStatus)
	{
		status = Rte_Call_rpSlideMotor_Move(step);
		uint8_t AdjustStatus;
	}
	
}


/**
 *
 * Runnable Seatmanager_SetHight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void Seatmanager_SetHight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	MultiStateBtnType DE_HeightBtnState;
	
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	
	switch(DE_HeightBtnState){
		case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
		
		case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(step);
	
}


/**
 *
 * Runnable Seatmanager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void Seatmanager_SetIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	MultiStateBtnType DE_InclineBtnState;

	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	
	switch(DE_InclineBtnState){
		case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
		
		case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(step);
	
}


/**
 *
 * Runnable Seatmanager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void Seatmanager_SetSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	MultiStateBtnType DE_SlideBtnState;
	
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	
	switch(DE_SlideBtnState){
		case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
		
		case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(step);
	
}