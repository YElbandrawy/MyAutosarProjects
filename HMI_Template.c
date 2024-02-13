/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/5/2024 06:22 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;
	MultiStateBtnType DE_InclineBtnState;
	MultiStateBtnType DE_SlideBtnState;
	SeatCtrlDataType DE_Height;
	SeatCtrlDataType DE_Incline;
	SeatCtrlDataType DE_Slide;
	
/************************************************************************/
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	if (status == RTE_E_OK){
		switch(DE_Height){
			case 1:
			DE_HeightBtnState = MULTI_STATE_BTN_MINUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
			break;
			
			case 2:
			DE_HeightBtnState =  MULTI_STATE_BTN_PLUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
			break;
			
			default:
			DE_HeightBtnState = MULTI_STATE_BTN_INIT;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
			break;
		}
	}

	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	if (status == RTE_E_OK){
		switch(DE_Incline){
			case 1:
			DE_InclineBtnState = MULTI_STATE_BTN_MINUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
			break;
			
			case 2:
			DE_InclineBtnState =  MULTI_STATE_BTN_PLUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
			break;
			
			default:
			DE_InclineBtnState = MULTI_STATE_BTN_INIT;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
			break;
		}
	}

	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	if (status == RTE_E_OK){
		switch(DE_Slide){
			case 1:
			DE_SlideBtnState = MULTI_STATE_BTN_MINUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
			break;
			
			case 2:
			DE_SlideBtnState =  MULTI_STATE_BTN_PLUS;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
			break;
			
			default:
			DE_SlideBtnState = MULTI_STATE_BTN_INIT;
			(void*)Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
			break;
		}
		
	}
/************************************************************************/

	
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
/******************************************************************************/
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	if (SeatModeBtn == SEAT_MODE_BTN_MANUAL){
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	
	else if (SeatModeBtn == SEAT_MODE_BTN_AUTO){
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}
	
	else
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
	}
	
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
/*********************************************************************************/

	
}

