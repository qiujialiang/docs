;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.8.0 #5117 (Mar 23 2008) (MINGW32)
; This file was generated Mon Feb 02 16:41:09 2009
;--------------------------------------------------------
	.module app
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl ___vector_11
	.globl ___vector_14
	.globl ___vector_3
	.globl ___vector_7
	.globl ___vector_2
	.globl ___vector_16
	.globl ___vector_0
	.globl ___vector_9
	.globl _UTX0IF
	.globl _UTX1IF
	.globl _T3IF
	.globl _T3CH0IF
	.globl _T1IE
	.globl _T3IE
	.globl _URX1IE
	.globl _URX0IE
	.globl _RFERRIE
	.globl _RFERRIF
	.globl _URX0IF
	.globl _URX1IF
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P0_7
	.globl _EA
	.globl _P1SEL
	.globl _P0SEL
	.globl _P1_DIR
	.globl _P0_DIR
	.globl _U1GCR
	.globl _U1UCR
	.globl _U1BAUD
	.globl _U1DBUF
	.globl _U1CSR
	.globl _PERCFG
	.globl _RFIF
	.globl _T1CCTL2
	.globl _T1CCTL1
	.globl _T1CCTL0
	.globl _T1CTL
	.globl _T1CNTH
	.globl _T1CNTL
	.globl _RFST
	.globl _T1CC0H
	.globl _T1CC0L
	.globl _RFD
	.globl _TIMIF
	.globl _T3CC1
	.globl _T3CCTL1
	.globl _T3CC0
	.globl _T3CCTL0
	.globl _T3CTL
	.globl _T3CNT
	.globl _CLKCON
	.globl _U0GCR
	.globl _U0UCR
	.globl _U0BAUD
	.globl _U0BUF
	.globl _SLEEP
	.globl _S1CON
	.globl _IEN2
	.globl _RFIM
	.globl _U0CSR
	.globl _AMQueueImplP__0__current
	.globl _SCSuartDBGM__buff_end
	.globl _SCSuartDBGM__buff_start
	.globl _SCSuartDBGM__state
	.globl _TOS_NODE_ID
	.globl _crcByte_PARM_2
	.globl _AMQueueEntryP__0__AMSend__send_PARM_3
	.globl _AMQueueEntryP__0__AMSend__send_PARM_2
	.globl _SCS_VTimerP__0__startTimer_PARM_3
	.globl _SCS_VTimerP__0__startTimer_PARM_2
	.globl _CC2430ActiveMessageM__Packet__getPayload_PARM_2
	.globl _AMQueueImplP__0__AMSend__sendDone_PARM_2
	.globl _CC2430ActiveMessageM__AMSend__send_PARM_4
	.globl _CC2430ActiveMessageM__AMSend__send_PARM_3
	.globl _CC2430ActiveMessageM__AMSend__send_PARM_2
	.globl _SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2
	.globl _SerialActiveMessageP__0__UartRecvMessag
	.globl _SerialActiveMessageP__0__SendProcessing
	.globl _SerialActiveMessageP__0__SendBuff
	.globl _SerialActiveMessageP__0__RecvAckType
	.globl _SerialActiveMessageP__0__RecvBuff
	.globl _SerialActiveMessageP__0__Escape_Flag
	.globl _SerialActiveMessageP__0__Rindex
	.globl _SerialActiveMessageP__0__NowReceiving
	.globl _AMQueueImplP__0__queue
	.globl _SCSuartDBGM__str_buff
	.globl _BusyWaitMicroC__MicroValue_
	.globl _HAL_CC2430ControlM__WaitACK_Flag
	.globl _HAL_CC2430ControlM__transmitInProgress
	.globl _HAL_CC2430ControlM__SendDoneError
	.globl _HAL_CC2430ControlM__currentChannel
	.globl _HAL_CC2430ControlM__currentPower
	.globl _HAL_CC2430ControlM__receivedPacket
	.globl _HAL_CC2430ControlM__transmitPacket
	.globl _HAL_CC2430ControlM__transmitPacketPtr
	.globl _CC2430ActiveMessageM__TX_Ready_Msg
	.globl _CC2430ActiveMessageM__AckEnable
	.globl _CC2430ActiveMessageM__NumReTX
	.globl _CC2430ActiveMessageM__MAC_Seq
	.globl _CC2430ActiveMessageM__RF_Status
	.globl _RandomC__randValue16
	.globl _RandomC__Rseed
	.globl _RandomC__RSeq
	.globl _FloodingM__RTable
	.globl _FloodingM__mySequence
	.globl _FloodingM__RTable_Index
	.globl _FloodingM__Forward_Buff_Index
	.globl _FloodingM__Next_Addr
	.globl _FloodingM__NWKF
	.globl _FloodingM__ForwardMsg
	.globl _FloodingM__RecvMsg
	.globl _FloodingM__SendMsg
	.globl _SCS_VTimerP__0__mTimerList
	.globl _SCS_VTimerP__0__queue
	.globl _SCS_VTimerP__0__queue_size
	.globl _SCS_VTimerP__0__queue_tail
	.globl _SCS_VTimerP__0__queue_head
	.globl _SCS_VTimerP__0__mInterval
	.globl _Adhoc_APPM__APP_Seq
	.globl _Adhoc_APPM__Serial_MSG
	.globl _Adhoc_APPM__RF_MSG
	.globl _SchedulerBasicP__m_next
	.globl _SchedulerBasicP__m_tail
	.globl _SchedulerBasicP__m_head
	.globl _main
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (DATA)
_U0CSR	=	0x0086
_RFIM	=	0x0091
_IEN2	=	0x009a
_S1CON	=	0x009b
_SLEEP	=	0x00be
_U0BUF	=	0x00c1
_U0BAUD	=	0x00c2
_U0UCR	=	0x00c4
_U0GCR	=	0x00c5
_CLKCON	=	0x00c6
_T3CNT	=	0x00ca
_T3CTL	=	0x00cb
_T3CCTL0	=	0x00cc
_T3CC0	=	0x00cd
_T3CCTL1	=	0x00ce
_T3CC1	=	0x00cf
_TIMIF	=	0x00d8
_RFD	=	0x00d9
_T1CC0L	=	0x00da
_T1CC0H	=	0x00db
_RFST	=	0x00e1
_T1CNTL	=	0x00e2
_T1CNTH	=	0x00e3
_T1CTL	=	0x00e4
_T1CCTL0	=	0x00e5
_T1CCTL1	=	0x00e6
_T1CCTL2	=	0x00e7
_RFIF	=	0x00e9
_PERCFG	=	0x00f1
_U1CSR	=	0x00f8
_U1DBUF	=	0x00f9
_U1BAUD	=	0x00fa
_U1UCR	=	0x00fb
_U1GCR	=	0x00fc
_P0_DIR	=	0x00fd
_P1_DIR	=	0x00fe
_P0SEL	=	0x00f3
_P1SEL	=	0x00f4
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (DATA)
_EA	=	0x00af
_P0_7	=	0x0087
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_URX1IF	=	0x008f
_URX0IF	=	0x008b
_RFERRIF	=	0x0089
_RFERRIE	=	0x00a8
_URX0IE	=	0x00aa
_URX1IE	=	0x00ab
_T3IE	=	0x00bb
_T1IE	=	0x00b9
_T3CH0IF	=	0x00d9
_T3IF	=	0x00c3
_UTX1IF	=	0x00ea
_UTX0IF	=	0x00e9
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0:
	.ds 4
_CC2430ActiveMessageM__AMSend__send_sloc0_1_0:
	.ds 3
_CC2430ActiveMessageM__AMSend__send_sloc1_1_0:
	.ds 2
_SCS_VTimerP__0__startTimer_sloc0_1_0:
	.ds 2
_SCS_VTimerP__0__startTimer_sloc1_1_0:
	.ds 2
_AMQueueEntryP__0__AMSend__send_sloc0_1_0:
	.ds 3
_AMQueueEntryP__0__AMSend__send_sloc1_1_0:
	.ds 3
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0::
	.ds 2
_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0::
	.ds 3
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_SchedulerBasicP__m_head::
	.ds 1
_SchedulerBasicP__m_tail::
	.ds 1
_SchedulerBasicP__m_next::
	.ds 16
_Adhoc_APPM__RF_MSG::
	.ds 48
_Adhoc_APPM__Serial_MSG::
	.ds 48
_Adhoc_APPM__APP_Seq::
	.ds 2
_SCS_VTimerP__0__mInterval::
	.ds 1
_SCS_VTimerP__0__queue_head::
	.ds 1
_SCS_VTimerP__0__queue_tail::
	.ds 1
_SCS_VTimerP__0__queue_size::
	.ds 1
_SCS_VTimerP__0__queue::
	.ds 4
_SCS_VTimerP__0__mTimerList::
	.ds 36
_FloodingM__SendMsg::
	.ds 48
_FloodingM__RecvMsg::
	.ds 48
_FloodingM__ForwardMsg::
	.ds 240
_FloodingM__NWKF::
	.ds 24
_FloodingM__Next_Addr::
	.ds 2
_FloodingM__Forward_Buff_Index::
	.ds 1
_FloodingM__RTable_Index::
	.ds 1
_FloodingM__mySequence::
	.ds 1
_FloodingM__RTable::
	.ds 100
_RandomC__RSeq::
	.ds 1
_RandomC__Rseed::
	.ds 2
_RandomC__randValue16::
	.ds 2
_CC2430ActiveMessageM__RF_Status::
	.ds 1
_CC2430ActiveMessageM__MAC_Seq::
	.ds 1
_CC2430ActiveMessageM__NumReTX::
	.ds 1
_CC2430ActiveMessageM__AckEnable::
	.ds 1
_CC2430ActiveMessageM__TX_Ready_Msg::
	.ds 3
_HAL_CC2430ControlM__transmitPacketPtr::
	.ds 3
_HAL_CC2430ControlM__transmitPacket::
	.ds 128
_HAL_CC2430ControlM__receivedPacket::
	.ds 128
_HAL_CC2430ControlM__currentPower::
	.ds 1
_HAL_CC2430ControlM__currentChannel::
	.ds 1
_HAL_CC2430ControlM__SendDoneError::
	.ds 1
_HAL_CC2430ControlM__transmitInProgress::
	.ds 1
_HAL_CC2430ControlM__WaitACK_Flag::
	.ds 1
_BusyWaitMicroC__MicroValue_::
	.ds 1
_SCSuartDBGM__str_buff::
	.ds 127
_AMQueueImplP__0__queue::
	.ds 3
_SerialActiveMessageP__0__NowReceiving::
	.ds 1
_SerialActiveMessageP__0__Rindex::
	.ds 1
_SerialActiveMessageP__0__Escape_Flag::
	.ds 1
_SerialActiveMessageP__0__RecvBuff::
	.ds 127
_SerialActiveMessageP__0__RecvAckType::
	.ds 1
_SerialActiveMessageP__0__SendBuff::
	.ds 127
_SerialActiveMessageP__0__SendProcessing::
	.ds 1
_SerialActiveMessageP__0__UartRecvMessag::
	.ds 48
_main__cil_inline_tmp_1656_1_1:
	.ds 2
_main__cil_inline_tmp_1718_1_1:
	.ds 1
_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1721_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask_arg_0x1a420d78_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1737_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1764_1_1:
	.ds 3
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1:
	.ds 2
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1807_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1808_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1809_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1810_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1811_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1812_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1813_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1814_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1819_1_1:
	.ds 2
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1835_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1:
	.ds 3
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1:
	.ds 2
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1:
	.ds 24
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1980_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1:
	.ds 6
_SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2:
	.ds 1
_SCSuartDBGM__SCSuartDBG__UARTSend__data_1_1:
	.ds 3
_AMQueueImplP__0__tryToSend__cil_inline_tmp_2056_1_1:
	.ds 1
_CC2430ActiveMessageM__AMSend__send_PARM_2:
	.ds 2
_CC2430ActiveMessageM__AMSend__send_PARM_3:
	.ds 3
_CC2430ActiveMessageM__AMSend__send_PARM_4:
	.ds 1
_CC2430ActiveMessageM__AMSend__send_id_1_1:
	.ds 1
_CC2430ActiveMessageM__AMSend__send_tmp_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__postTask_id_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__postTask_tmp___1_1_1:
	.ds 2
_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2087_1_1:
	.ds 1
_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1:
	.ds 2
_AMQueueImplP__0__AMSend__sendDone_PARM_2:
	.ds 1
_AMQueueImplP__0__AMSend__sendDone_msg_1_1:
	.ds 3
_AMQueueImplP__0__AMSend__sendDone_last_1_1:
	.ds 1
_CC2430ActiveMessageM__Packet__getPayload_PARM_2:
	.ds 3
_CC2430ActiveMessageM__Packet__getPayload_msg_1_1:
	.ds 3
_FloodingM__isRecvPrevious_msg_1_1:
	.ds 3
_FloodingM__isRecvPrevious_pack_1_1:
	.ds 24
_FloodingM__isRecvPrevious_return_status_1_1:
	.ds 1
_FloodingM__insertMSGtoRTable_msg_1_1:
	.ds 3
_FloodingM__insertMSGtoRTable_pack_1_1:
	.ds 24
_SCS_VTimerP__0__startTimer_PARM_2:
	.ds 4
_SCS_VTimerP__0__startTimer_PARM_3:
	.ds 1
_SCS_VTimerP__0__startTimer_id_1_1:
	.ds 1
_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1:
	.ds 2
_Adhoc_APPM__Timer__fired_APP_M_1_1:
	.ds 12
_Adhoc_APPM__Timer__fired_tmp_1_1:
	.ds 2
_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1:
	.ds 24
_FloodingM__SendFromAPP__getPayload_msg_1_1:
	.ds 3
_AMQueueEntryP__0__AMSend__send_PARM_2:
	.ds 3
_AMQueueEntryP__0__AMSend__send_PARM_3:
	.ds 1
_AMQueueEntryP__0__AMSend__send_dest_1_1:
	.ds 2
_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1:
	.ds 1
_HplSCS_Clock_Timer1P__Alarm__start_dt_1_1:
	.ds 1
_HplSCS_Clock_Timer1P__Alarm__start_r_1_1:
	.ds 2
_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone_err_1_1:
	.ds 1
_RandomC__Random__rand16_tmp_1_1:
	.ds 1
_crcByte_PARM_2:
	.ds 1
_crcByte_crc_1_1:
	.ds 2
_RandomC__SeedInit__init_param_1_1:
	.ds 2
___vector_2__cil_inline_tmp_2326_1_1:
	.ds 1
___vector_2__cil_inline_tmp_2332_1_1:
	.ds 1
___vector_2__cil_inline_tmp_2333_1_1:
	.ds 1
___vector_2__cil_inline_tmp_2334_1_1:
	.ds 1
___vector_2__cil_inline_tmp_2335_1_1:
	.ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
_TOS_NODE_ID::
	.ds 2
_SCSuartDBGM__state::
	.ds 1
_SCSuartDBGM__buff_start::
	.ds 2
_SCSuartDBGM__buff_end::
	.ds 2
_AMQueueImplP__0__current::
	.ds 1
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	ljmp	___vector_0
	.ds	5
	reti
	.ds	7
	ljmp	___vector_2
	.ds	5
	ljmp	___vector_3
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	___vector_7
	.ds	5
	reti
	.ds	7
	ljmp	___vector_9
	.ds	5
	reti
	.ds	7
	ljmp	___vector_11
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	ljmp	___vector_14
	.ds	5
	reti
	.ds	7
	ljmp	___vector_16
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;_cil_inline_tmp_1613      Allocated with name '_main__cil_inline_tmp_1613_1_1'
;_cil_inline_tmp_1614      Allocated with name '_main__cil_inline_tmp_1614_1_1'
;_cil_inline_tmp_1623      Allocated with name '_main__cil_inline_tmp_1623_1_1'
;_cil_inline_tmp_1636      Allocated with name '_main__cil_inline_tmp_1636_1_1'
;_cil_inline_tmp_1638      Allocated with name '_main__cil_inline_tmp_1638_1_1'
;_cil_inline_tmp_1640      Allocated with name '_main__cil_inline_tmp_1640_1_1'
;_cil_inline_tmp_1651      Allocated with name '_main__cil_inline_tmp_1651_1_1'
;_cil_inline_tmp_1656      Allocated with name '_main__cil_inline_tmp_1656_1_1'
;_cil_inline_tmp_1663      Allocated with name '_main__cil_inline_tmp_1663_1_1'
;_cil_inline_tmp_1668      Allocated with name '_main__cil_inline_tmp_1668_1_1'
;_cil_inline_tmp_1673      Allocated with name '_main__cil_inline_tmp_1673_1_1'
;_cil_inline_tmp_1676      Allocated with name '_main__cil_inline_tmp_1676_1_1'
;_cil_inline_tmp_1678      Allocated with name '_main__cil_inline_tmp_1678_1_1'
;_cil_inline_tmp_1692      Allocated with name '_main__cil_inline_tmp_1692_1_1'
;_cil_inline_tmp_1695      Allocated with name '_main__cil_inline_tmp_1695_1_1'
;_cil_inline_tmp_1717      Allocated with name '_main__cil_inline_tmp_1717_1_1'
;_cil_inline_tmp_1718      Allocated with name '_main__cil_inline_tmp_1718_1_1'
;_cil_inline_tmp_1719      Allocated with name '_main__cil_inline_tmp_1719_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	r3,#0x00
00101$:
	mov	ar4,r3
	mov	r5,#0x00
	clr	c
	mov	a,r4
	subb	a,#0x10
	mov	a,r5
	subb	a,#0x00
	jnc	00103$
	mov	a,r3
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	mov	a,#0xFF
	movx	@dptr,a
	inc	r3
	sjmp	00101$
00103$:
	mov	dptr,#_SchedulerBasicP__m_head
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__m_tail
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	r3,_SLEEP
	anl	ar3,#0xFC
	mov	_SLEEP,r3
	mov	r3,_SLEEP
	anl	ar3,#0xFB
	mov	r4,#0x00
	mov	_SLEEP,r3
00104$:
	mov	r3,_SLEEP
	mov	r4,#0x00
	mov	a,r3
	jnb	acc.6,00104$
	mov	_CLKCON,#0x08
00107$:
	mov	r3,_CLKCON
	mov	r4,#0x00
	cjne	r3,#0x08,00107$
	cjne	r4,#0x00,00107$
	mov	r3,_P0_DIR
	orl	ar3,#0x80
	mov	_P0_DIR,r3
	clr	_P0_7
	mov	r3,_P1_DIR
	orl	ar3,#0x04
	mov	_P1_DIR,r3
	mov	r3,_P1_DIR
	orl	ar3,#0x08
	mov	_P1_DIR,r3
	mov	r3,_P1_DIR
	mov	r4,#0x00
	orl	ar3,#0x10
	mov	_P1_DIR,r3
	setb	_P1_2
	setb	_P1_3
	setb	_P1_4
00113$:
	push	ar2
	lcall	_SchedulerBasicP__Scheduler__runNextTask
	mov	a,dpl
	pop	ar2
	jnz	00113$
	mov	dptr,#_AMQueueImplP__0__current
	mov	a,#0xFF
	movx	@dptr,a
	mov	_T3CCTL0,#0x00
	mov	_T3CC0,#0x00
	mov	_T3CCTL1,#0x00
	mov	_T3CC1,#0x00
	mov	_T3CNT,#0x00
	mov	_T3CTL,#0x00
	mov	_T3CTL,#0xE0
	mov	r3,_T3CTL
	orl	ar3,#0x10
	mov	_T3CTL,r3
	mov	r3,_T3CTL
	orl	ar3,#0x02
	mov	_T3CTL,r3
	setb	_T3IF
	setb	_T3CH0IF
	mov	r3,_T3CCTL0
	orl	ar3,#0x44
	mov	_T3CCTL0,r3
	mov	r3,#0x17
	mov	r4,#0xDF
	mov	dptr,#0xDF17
	movx	a,@dptr
	mov	r5,a
	mov	a,#0xF7
	anl	a,r5
	mov	r6,a
	mov	dpl,r3
	mov	dph,r4
	movx	@dptr,a
	mov	dptr,#0xDF17
	mov	a,#0x08
	orl	a,r5
	mov	r3,a
	movx	@dptr,a
00115$:
	mov	r3,_RFIF
	mov	r4,#0x00
	mov	a,r3
	jb	acc.7,00115$
	mov	r3,_SLEEP
	anl	ar3,#0xFB
	mov	_SLEEP,r3
	mov	r3,_CLKCON
	anl	ar3,#0xFE
	mov	r4,#0x00
	mov	_CLKCON,r3
00118$:
	mov	r3,_SLEEP
	mov	r4,#0x00
	mov	a,r3
	jnb	acc.6,00118$
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#0xDF4D
	mov	ar7,r4
	mov	ar6,r7
	mov	a,r6
	movx	@dptr,a
	mov	dptr,#0xDF4E
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#0xDF4B
	clr	a
	movx	@dptr,a
	mov	dptr,#0xDF4C
	mov	a,#0x22
	movx	@dptr,a
	mov	r3,#0x02
	mov	r4,#0xDF
	mov	dptr,#0xDF02
	movx	a,@dptr
	mov	r6,a
	mov	a,#0xF7
	anl	a,r6
	mov	dpl,r3
	mov	dph,r4
	movx	@dptr,a
	mov	r3,#0x03
	mov	r4,#0xDF
	mov	dptr,#0xDF03
	movx	a,@dptr
	mov	r7,a
	orl	ar7,#0x20
	mov	dpl,r3
	mov	dph,r4
	mov	a,r7
	movx	@dptr,a
	mov	dptr,#0xDF4F
	mov	a,#0x7F
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__currentChannel
	mov	a,#0x1A
	movx	@dptr,a
	mov	dptr,#0xDF10
	mov	a,#0x41
	movx	@dptr,a
	mov	dptr,#0xDF11
	mov	a,#0xB0
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__currentPower
	mov	a,#0x5F
	movx	@dptr,a
	mov	dptr,#0xDF0B
	mov	a,#0x5F
	movx	@dptr,a
	mov	dptr,#0xDF02
	orl	ar6,#0x08
	mov	a,r6
	movx	@dptr,a
	mov	dptr,#0xDF17
	orl	ar5,#0x08
	mov	a,r5
	movx	@dptr,a
	mov	r3,_RFIM
	orl	ar3,#0x40
	mov	_RFIM,r3
	mov	r3,_RFIF
	anl	ar3,#0xBF
	mov	_RFIF,r3
	mov	r3,_IEN2
	mov	r4,#0x00
	orl	ar3,#0x01
	mov	_IEN2,r3
	clr	_RFERRIF
	setb	_RFERRIE
	mov	r3,#0x00
00121$:
	cjne	r3,#0x04,00188$
00188$:
	jnc	00123$
	mov	a,r3
	mov	b,#0x09
	mul	ab
	add	a,#_SCS_VTimerP__0__mTimerList
	mov	r4,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__mTimerList >> 8)
	mov	r5,a
	mov	a,#0x08
	add	a,r4
	mov	dpl,a
	clr	a
	addc	a,r5
	mov	dph,a
	movx	a,@dptr
	anl	a,#0xfd
	movx	@dptr,a
	inc	r3
	sjmp	00121$
00123$:
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__queue_head
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__queue_size
	clr	a
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__mInterval
	mov	a,#0xE6
	movx	@dptr,a
	mov	dptr,#_main__cil_inline_tmp_1656_1_1
	mov	a,#0x4E
	movx	@dptr,a
	inc	dptr
	mov	a,#0x70
	movx	@dptr,a
	mov	_T1CCTL1,#0x00
	mov	_T1CCTL2,#0x00
	mov	_T1CNTL,#0x00
	mov	_T1CNTH,#0x00
	mov	_T1CCTL0,#0x00
	mov	_T1CTL,#0x00
	mov	_T1CTL,#0x0C
	setb	_T1IE
	mov	r3,_TIMIF
	orl	ar3,#0x40
	mov	_TIMIF,r3
	mov	dptr,#_main__cil_inline_tmp_1656_1_1
	movx	a,@dptr
	mov	_T1CC0L,a
	mov	dptr,#(_main__cil_inline_tmp_1656_1_1 + 0x0001)
	mov	b,#0x00
	lcall	__gptrget
	mov	_T1CC0H,a
	mov	r3,_T1CTL
	orl	ar3,#0x20
	mov	_T1CTL,r3
	mov	r3,_T1CTL
	orl	ar3,#0x02
	mov	_T1CTL,r3
	mov	r3,_T1CCTL0
	mov	r4,#0x00
	orl	ar3,#0x44
	mov	_T1CCTL0,r3
00127$:
	push	ar2
	lcall	_SchedulerBasicP__Scheduler__runNextTask
	mov	a,dpl
	pop	ar2
	jnz	00127$
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	setb	_EA
	mov	dptr,#_Adhoc_APPM__APP_Seq
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_RandomC__SeedInit__init
	lcall	_RandomC__Random__rand16
	mov	r2,dpl
	mov	r3,dph
	mov	c,_EA
	clr	a
	rlc	a
	mov	r4,a
	clr	_EA
	mov	dptr,#_FloodingM__Next_Addr
	mov	a,#0xFF
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__Forward_Buff_Index
	clr	a
	movx	@dptr,a
	mov	dptr,#_FloodingM__RTable_Index
	movx	@dptr,a
	mov	dptr,#__moduint_PARM_2
	mov	a,#0xFF
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	push	ar4
	lcall	__moduint
	mov	r2,dpl
	mov	r3,dph
	pop	ar4
	mov	dptr,#_FloodingM__mySequence
	mov	a,r2
	movx	@dptr,a
	mov	r2,#0x00
00129$:
	cjne	r2,#0x14,00191$
00191$:
	jnc	00131$
	mov	a,r2
	mov	b,#0x05
	mul	ab
	mov	r3,a
	add	a,#_FloodingM__RTable
	mov	dpl,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	dph,a
	mov	a,#0xFE
	movx	@dptr,a
	inc	dptr
	mov	a,#0xFF
	movx	@dptr,a
	mov	a,r3
	add	a,#_FloodingM__RTable
	mov	r3,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	r5,a
	mov	dpl,r3
	mov	dph,r5
	inc	dptr
	inc	dptr
	mov	a,#0xFE
	movx	@dptr,a
	inc	dptr
	mov	a,#0xFF
	movx	@dptr,a
	mov	dpl,r3
	mov	dph,r5
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	mov	a,#0xFF
	movx	@dptr,a
	inc	r2
	sjmp	00129$
00131$:
	mov	a,r4
	add	a,#0xff
	mov	_EA,c
	mov	dptr,#_CC2430ActiveMessageM__AckEnable
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#0xDF17
	mov	a,#0x04
	movx	@dptr,a
00132$:
	mov	dptr,#0xDF17
	movx	a,@dptr
	mov	r2,a
	jb	acc.4,00132$
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	r3,_RFIM
	orl	ar3,#0x20
	mov	_RFIM,r3
	mov	r3,_RFIF
	anl	ar3,#0xDF
	mov	_RFIF,r3
	mov	r3,_IEN2
	orl	ar3,#0x01
	mov	_IEN2,r3
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	mov	_RFST,#0xE2
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	clr	a
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	movx	@dptr,a
	mov	r2,#0x02
	mov	r3,#0xDF
	mov	dptr,#0xDF02
	movx	a,@dptr
	mov	r4,a
	orl	ar4,#0x08
	mov	dpl,r2
	mov	dph,r3
	mov	a,r4
	movx	@dptr,a
	mov	r2,#0x03
	mov	r3,#0xDF
	mov	dptr,#0xDF03
	movx	a,@dptr
	mov	r4,a
	orl	ar4,#0x10
	mov	dpl,r2
	mov	dph,r3
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__RF_Status
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	clr	a
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	a,r2
	mov	b,#0x0D
	mul	ab
	mov	r2,a
	mov	dptr,#_CC2430ActiveMessageM__MAC_Seq
	movx	@dptr,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_RandomC__SeedInit__init
	mov	dptr,#_SerialActiveMessageP__0__NowReceiving
	clr	a
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Escape_Flag
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__RecvAckType
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__SendProcessing
	clr	a
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__state
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_end
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	r2,_PERCFG
	mov	_PERCFG,r2
	mov	r2,_P0SEL
	orl	ar2,#0x0C
	mov	_P0SEL,r2
	mov	_U0BAUD,#0xD8
	mov	_U0GCR,#0x0A
	mov	r2,_U0CSR
	orl	ar2,#0xC0
	mov	_U0CSR,r2
	mov	r2,_U0UCR
	orl	ar2,#0x82
	mov	_U0UCR,r2
	clr	_UTX0IF
	clr	_URX0IF
	setb	_URX0IE
	mov	r2,_IEN2
	orl	ar2,#0x04
	mov	_IEN2,r2
	mov	r2,_PERCFG
	orl	ar2,#0x02
	mov	_PERCFG,r2
	mov	r2,_P1SEL
	orl	ar2,#0xC0
	mov	_P1SEL,r2
	mov	_U1BAUD,#0xD8
	mov	_U1GCR,#0x0A
	mov	r2,_U1CSR
	orl	ar2,#0xC0
	mov	_U1CSR,r2
	mov	r2,_U1UCR
	orl	ar2,#0x82
	mov	_U1UCR,r2
	clr	_UTX1IF
	clr	_URX1IF
	setb	_URX1IE
	mov	r2,_IEN2
	orl	ar2,#0x08
	mov	_IEN2,r2
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	orl	a,r2
	jz	00148$
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	mov	a,#0xB8
	movx	@dptr,a
	inc	dptr
	mov	a,#0x0B
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_3
	clr	a
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_SCS_VTimerP__0__startTimer
00148$:
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
00145$:
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	cjne	r3,#0xFF,00195$
	cjne	r4,#0x00,00195$
	sjmp	00140$
00195$:
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dptr,#_SchedulerBasicP__m_head
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r4,a
	mov	r5,#0x00
	cjne	r4,#0xFF,00138$
	cjne	r5,#0x00,00138$
	mov	dptr,#_SchedulerBasicP__m_tail
	mov	a,#0xFF
	movx	@dptr,a
00138$:
	mov	a,r3
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_main__cil_inline_tmp_1718_1_1
	mov	a,r3
	movx	@dptr,a
	sjmp	00141$
00140$:
	mov	dptr,#_main__cil_inline_tmp_1718_1_1
	mov	a,#0xFF
	movx	@dptr,a
00141$:
	mov	dptr,#_main__cil_inline_tmp_1718_1_1
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0xFF,00146$
	setb	_EA
	mov	r4,_SLEEP
	anl	ar4,#0xFC
	mov	r5,#0x00
	orl	ar4,#0x01
	mov	_SLEEP,r4
	clr	_EA
	sjmp	00145$
00146$:
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	mov	dpl,r3
	lcall	_SchedulerBasicP__TaskBasic__runTask
	ljmp	00148$
;------------------------------------------------------------
;Allocation info for local variables in function 'SchedulerBasicP__Scheduler__runNextTask'
;------------------------------------------------------------
;_cil_inline_tmp_1721      Allocated with name '_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1721_1_1'
;_cil_inline_tmp_1722      Allocated with name '_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1722_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function SchedulerBasicP__Scheduler__runNextTask
;	-----------------------------------------
_SchedulerBasicP__Scheduler__runNextTask:
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0xFF,00113$
	cjne	r3,#0x00,00113$
	sjmp	00104$
00113$:
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dptr,#_SchedulerBasicP__m_head
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	cjne	r3,#0xFF,00102$
	cjne	r4,#0x00,00102$
	mov	dptr,#_SchedulerBasicP__m_tail
	mov	a,#0xFF
	movx	@dptr,a
00102$:
	mov	a,r2
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1721_1_1
	mov	a,r2
	movx	@dptr,a
	sjmp	00105$
00104$:
	mov	dptr,#_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1721_1_1
	mov	a,#0xFF
	movx	@dptr,a
00105$:
	mov	dptr,#_SchedulerBasicP__Scheduler__runNextTask__cil_inline_tmp_1721_1_1
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0xFF,00107$
	mov	dpl,#0x00
	ret
00107$:
	mov	dpl,r2
	lcall	_SchedulerBasicP__TaskBasic__runTask
	mov	dpl,#0x01
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SchedulerBasicP__TaskBasic__default__runTask'
;------------------------------------------------------------
;------------------------------------------------------------
;	-----------------------------------------
;	 function SchedulerBasicP__TaskBasic__default__runTask
;	-----------------------------------------
_SchedulerBasicP__TaskBasic__default__runTask:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SchedulerBasicP__TaskBasic__runTask'
;------------------------------------------------------------
;sloc0                     Allocated with name '_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0'
;arg_0x1a420d78            Allocated with name '_SchedulerBasicP__TaskBasic__runTask_arg_0x1a420d78_1_1'
;_cil_inline_tmp_1723      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1723_1_1'
;_cil_inline_tmp_1727      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1727_1_1'
;_cil_inline_tmp_1728      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1'
;_cil_inline_tmp_1732      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1732_1_1'
;_cil_inline_tmp_1733      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1733_1_1'
;_cil_inline_tmp_1737      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1737_1_1'
;_cil_inline_tmp_1761      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1761_1_1'
;_cil_inline_tmp_1764      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1764_1_1'
;_cil_inline_tmp_1777      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1777_1_1'
;_cil_inline_tmp_1779      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1779_1_1'
;_cil_inline_tmp_1799      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1'
;_cil_inline_tmp_1800      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1800_1_1'
;_cil_inline_tmp_1803      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1'
;_cil_inline_tmp_1807      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1807_1_1'
;_cil_inline_tmp_1808      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1808_1_1'
;_cil_inline_tmp_1809      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1809_1_1'
;_cil_inline_tmp_1810      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1810_1_1'
;_cil_inline_tmp_1811      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1811_1_1'
;_cil_inline_tmp_1812      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1812_1_1'
;_cil_inline_tmp_1813      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1813_1_1'
;_cil_inline_tmp_1814      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1814_1_1'
;_cil_inline_tmp_1818      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1818_1_1'
;_cil_inline_tmp_1819      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1819_1_1'
;_cil_inline_tmp_1821      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1821_1_1'
;_cil_inline_tmp_1825      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1825_1_1'
;_cil_inline_tmp_1828      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1828_1_1'
;_cil_inline_tmp_1832      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1832_1_1'
;_cil_inline_tmp_1835      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1835_1_1'
;_cil_inline_tmp_1841      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1841_1_1'
;_cil_inline_tmp_1842      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1842_1_1'
;_cil_inline_tmp_1848      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1848_1_1'
;_cil_inline_tmp_1857      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1'
;_cil_inline_tmp_1860      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1860_1_1'
;_cil_inline_tmp_1861      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1861_1_1'
;_cil_inline_tmp_1870      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1'
;_cil_inline_tmp_1871      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1871_1_1'
;_cil_inline_tmp_1874      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1874_1_1'
;_cil_inline_tmp_1877      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1877_1_1'
;_cil_inline_tmp_1892      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1892_1_1'
;_cil_inline_tmp_1893      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1'
;_cil_inline_tmp_1896      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1896_1_1'
;_cil_inline_tmp_1917      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1917_1_1'
;_cil_inline_tmp_1939      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1939_1_1'
;_cil_inline_tmp_1959      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1959_1_1'
;_cil_inline_tmp_1980      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1980_1_1'
;_cil_inline_tmp_1981      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1981_1_1'
;_cil_inline_tmp_1983      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1983_1_1'
;_cil_inline_tmp_1993      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1993_1_1'
;_cil_inline_tmp_1994      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1994_1_1'
;_cil_inline_tmp_2004      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2004_1_1'
;_cil_inline_tmp_2032      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1'
;_cil_inline_tmp_2033      Allocated with name '_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2033_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function SchedulerBasicP__TaskBasic__runTask
;	-----------------------------------------
_SchedulerBasicP__TaskBasic__runTask:
	mov	a,dpl
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask_arg_0x1a420d78_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask_arg_0x1a420d78_1_1
	movx	a,@dptr
	mov  r2,a
	add	a,#0xff - 0x0F
	jnc	00317$
	ljmp	00248$
00317$:
	mov	a,r2
	add	a,r2
	add	a,r2
	mov	dptr,#00318$
	jmp	@a+dptr
00318$:
	ljmp	00101$
	ljmp	00121$
	ljmp	00133$
	ljmp	00148$
	ljmp	00151$
	ljmp	00159$
	ljmp	00160$
	ljmp	00161$
	ljmp	00171$
	ljmp	00172$
	ljmp	00173$
	ljmp	00197$
	ljmp	00230$
	ljmp	00243$
	ljmp	00244$
	ljmp	00245$
00101$:
	mov	r2,#0x00
00111$:
	cjne	r2,#0x04,00319$
00319$:
	jc	00320$
	ljmp	00113$
00320$:
	mov	a,r2
	mov	b,#0x09
	mul	ab
	add	a,#_SCS_VTimerP__0__mTimerList
	mov	r3,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__mTimerList >> 8)
	mov	r4,a
	mov	a,#0x08
	add	a,r3
	mov	r5,a
	clr	a
	addc	a,r4
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	movx	a,@dptr
	jb	acc.1,00321$
	ljmp	00110$
00321$:
	push	ar2
	mov	a,#0x04
	add	a,r3
	mov	r5,a
	clr	a
	addc	a,r4
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	movx	a,@dptr
	mov	_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2),a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3),a
	mov	dptr,#_SCS_VTimerP__0__mInterval
	movx	a,@dptr
	mov	r2,a
	clr	a
	mov	r7,a
	mov	r0,a
	mov	r1,a
	mov	a,_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0
	clr	c
	subb	a,r2
	mov	r2,a
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1)
	subb	a,r7
	mov	r7,a
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2)
	subb	a,r0
	mov	r0,a
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3)
	subb	a,r1
	mov	r1,a
	mov	dpl,r5
	mov	dph,r6
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	clr	c
	mov	a,#0x02
	subb	a,r2
	clr	a
	subb	a,r7
	clr	a
	subb	a,r0
	mov	a,#(0x00 ^ 0x80)
	mov	b,r1
	xrl	b,#0x80
	subb	a,b
	clr	a
	rlc	a
	pop	ar2
	jz	00322$
	ljmp	00110$
00322$:
	mov	a,#0x08
	add	a,r3
	mov	dpl,a
	clr	a
	addc	a,r4
	mov	dph,a
	movx	a,@dptr
	anl	a,#0x01
	mov	r7,a
	cjne	r7,#0x01,00103$
	mov	a,#0x08
	add	a,r3
	mov	dpl,a
	clr	a
	addc	a,r4
	mov	dph,a
	movx	a,@dptr
	anl	a,#0xfd
	movx	@dptr,a
	sjmp	00104$
00103$:
	push	ar2
	mov	dpl,r5
	mov	dph,r6
	movx	a,@dptr
	mov	_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2),a
	inc	dptr
	movx	a,@dptr
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3),a
	mov	dpl,r3
	mov	dph,r4
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r3
	add	a,_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0
	mov	r3,a
	mov	a,r4
	addc	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1)
	mov	r4,a
	mov	a,r2
	addc	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2)
	mov	r2,a
	mov	a,r7
	addc	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3)
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	pop	ar2
00104$:
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0x03,00106$
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	mov	a,#0xFF
	movx	@dptr,a
00106$:
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	movx	a,@dptr
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	inc	a
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__queue_size
	movx	a,@dptr
	mov	dptr,#_SCS_VTimerP__0__queue_size
	inc	a
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__queue_tail
	movx	a,@dptr
	add	a,#_SCS_VTimerP__0__queue
	mov	dpl,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__queue >> 8)
	mov	dph,a
	mov	a,r2
	movx	@dptr,a
	mov	dpl,#0x01
	push	ar2
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar2
00110$:
	inc	r2
	ljmp	00111$
00113$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1
	mov	a,#0xE6
	movx	@dptr,a
	mov	r2,#0x00
00118$:
	cjne	r2,#0x04,00327$
00327$:
	jnc	00120$
	mov	a,r2
	mov	b,#0x09
	mul	ab
	add	a,#_SCS_VTimerP__0__mTimerList
	mov	r3,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__mTimerList >> 8)
	mov	r4,a
	mov	a,#0x08
	add	a,r3
	mov	r5,a
	clr	a
	addc	a,r4
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	movx	a,@dptr
	jnb	acc.1,00117$
	push	ar2
	mov	dpl,r3
	mov	dph,r4
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0,r3
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1),r4
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2),r5
	mov	(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3),r6
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r7,#0x00
	mov	r0,#0x00
	mov	r1,#0x00
	clr	c
	mov	a,_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0
	subb	a,r2
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 1)
	subb	a,r7
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 2)
	subb	a,r0
	mov	a,(_SchedulerBasicP__TaskBasic__runTask_sloc0_1_0 + 3)
	subb	a,r1
	clr	a
	rlc	a
	pop	ar2
	jz	00117$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1
	mov	a,r3
	movx	@dptr,a
00117$:
	inc	r2
	sjmp	00118$
00120$:
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1728_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SCS_VTimerP__0__mInterval
	movx	@dptr,a
	mov	dpl,r3
	push	ar2
	lcall	_HplSCS_Clock_Timer1P__Alarm__start
	pop	ar2
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	ret
00121$:
	mov	dptr,#_SCS_VTimerP__0__queue_size
	movx	a,@dptr
	mov	r2,a
	jnz	00123$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1737_1_1
	mov	a,#0x04
	movx	@dptr,a
	sjmp	00126$
00123$:
	mov	dptr,#_SCS_VTimerP__0__queue_head
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0x03,00125$
	mov	dptr,#_SCS_VTimerP__0__queue_head
	mov	a,#0xFF
	movx	@dptr,a
00125$:
	mov	dptr,#_SCS_VTimerP__0__queue_head
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SCS_VTimerP__0__queue_head
	inc	a
	movx	@dptr,a
	mov	a,r2
	dec	a
	mov	dptr,#_SCS_VTimerP__0__queue_size
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__queue_head
	movx	a,@dptr
	add	a,#_SCS_VTimerP__0__queue
	mov	dpl,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__queue >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1737_1_1
	movx	@dptr,a
00126$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1737_1_1
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x04,00334$
00334$:
	jc	00335$
	ret
00335$:
	mov	r3,#0x00
	cjne	r2,#0x00,00336$
	cjne	r3,#0x00,00336$
	sjmp	00127$
00336$:
	cjne	r2,#0x02,00337$
	cjne	r3,#0x00,00337$
	sjmp	00128$
00337$:
	cjne	r2,#0x03,00338$
	cjne	r3,#0x00,00338$
	sjmp	00129$
00338$:
	ret
00127$:
	ljmp	_Adhoc_APPM__Timer__fired
00128$:
	ljmp	_HAL_CC2430ControlM__TX_TimeOut__fired
00129$:
	ljmp	_HAL_CC2430ControlM__ACK_TimeOut__fired
00133$:
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__RecvMsg
	mov	b,#0x00
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__NWKF
	mov	b,#0x00
	lcall	_memcpy
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1764_1_1
	mov	a,#(_FloodingM__NWKF + 0x000c)
	movx	@dptr,a
	inc	dptr
	mov	a,#((_FloodingM__NWKF + 0x000c) >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	orl	a,r2
	jz	00339$
	ret
00339$:
	mov	dptr,#_Adhoc_APPM__Serial_MSG
	mov	b,#0x00
	lcall	_FloodingM__SendFromAPP__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1764_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_memcpy_PARM_2
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x0C
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	push	ar2
	push	ar3
	push	ar4
	lcall	_memcpy
	pop	ar4
	pop	ar3
	pop	ar2
	mov	a,#0x02
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	dptr,#(_Adhoc_APPM__Serial_MSG + 0x0006)
	mov	b,#0x00
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
	mov	dptr,#_SerialActiveMessageP__0__SendProcessing
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1819_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1819_1_1
	movx	a,@dptr
	mov	r3,a
	mov	r2,#0x00
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1819_1_1 + 0x0001)
	mov	b,#0x00
	lcall	__gptrget
	mov	r5,#0x00
	orl	ar2,a
	mov	a,r5
	orl	ar3,a
	mov	dptr,#(_Adhoc_APPM__Serial_MSG + 0x0004)
	mov	b,#0x00
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
	mov	dptr,#(_Adhoc_APPM__Serial_MSG + 0x0009)
	clr	a
	mov	b,a
	lcall	__gptrput
	mov	dptr,#(_Adhoc_APPM__Serial_MSG + 0x000a)
	mov	b,#0x00
	mov	a,#0x0A
	lcall	__gptrput
	mov	dptr,#(_Adhoc_APPM__Serial_MSG + 0x0008)
	mov	b,#0x00
	mov	a,#0x0C
	lcall	__gptrput
	mov	dptr,#_SerialActiveMessageP__0__SendBuff
	mov	a,#0x7E
	movx	@dptr,a
	mov	dptr,#(_SerialActiveMessageP__0__SendBuff + 0x0001)
	mov	a,#0x45
	movx	@dptr,a
	mov	dptr,#_crcByte_PARM_2
	mov	a,#0x45
	movx	@dptr,a
	mov	dptr,#0x0000
	lcall	_crcByte
	mov	r2,dpl
	mov	r3,dph
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#(_SerialActiveMessageP__0__SendBuff + 0x0002)
	clr	a
	movx	@dptr,a
	mov	dptr,#_crcByte_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_crcByte
	mov	a,dpl
	mov	b,dph
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	mov	r2,#0x00
00140$:
	cjne	r2,#0x13,00340$
00340$:
	jc	00341$
	ljmp	00142$
00341$:
	mov	a,r2
	add	a,#(_Adhoc_APPM__Serial_MSG + 0x0004)
	mov	r3,a
	clr	a
	addc	a,#((_Adhoc_APPM__Serial_MSG + 0x0004) >> 8)
	mov	r4,a
	mov	r5,#0x00
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	cjne	r3,#0x7D,00138$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1807_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1807_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	a,#0x7D
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1808_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1808_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	a,#0x5D
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_crcByte_PARM_2
	mov	a,#0x7D
	movx	@dptr,a
	mov	dpl,r3
	mov	dph,r4
	push	ar2
	lcall	_crcByte
	mov	a,dpl
	mov	b,dph
	pop	ar2
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	ljmp	00139$
00138$:
	mov	a,r2
	add	a,#(_Adhoc_APPM__Serial_MSG + 0x0004)
	mov	r3,a
	clr	a
	addc	a,#((_Adhoc_APPM__Serial_MSG + 0x0004) >> 8)
	mov	r4,a
	mov	r5,#0x00
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	cjne	r3,#0x7E,00135$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1809_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1809_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	a,#0x7D
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1810_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1810_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	a,#0x5E
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_crcByte_PARM_2
	mov	a,#0x7E
	movx	@dptr,a
	mov	dpl,r3
	mov	dph,r4
	push	ar2
	lcall	_crcByte
	mov	a,dpl
	mov	b,dph
	pop	ar2
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	sjmp	00139$
00135$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1811_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1811_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	r3,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	r4,a
	mov	a,r2
	add	a,#(_Adhoc_APPM__Serial_MSG + 0x0004)
	mov	r5,a
	clr	a
	addc	a,#((_Adhoc_APPM__Serial_MSG + 0x0004) >> 8)
	mov	r6,a
	mov	r7,#0x00
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	dpl,r3
	mov	dph,r4
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	a,r2
	add	a,#(_Adhoc_APPM__Serial_MSG + 0x0004)
	mov	r5,a
	clr	a
	addc	a,#((_Adhoc_APPM__Serial_MSG + 0x0004) >> 8)
	mov	r6,a
	mov	r7,#0x00
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	dptr,#_crcByte_PARM_2
	movx	@dptr,a
	mov	dpl,r3
	mov	dph,r4
	push	ar2
	lcall	_crcByte
	mov	a,dpl
	mov	b,dph
	pop	ar2
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
00139$:
	inc	r2
	ljmp	00140$
00142$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1812_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r2
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1812_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	r2,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1803_1_1
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	ar6,r4
	mov	dpl,r2
	mov	dph,r3
	mov	a,r6
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1813_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r2
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1813_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	ar4,r5
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1814_1_1
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	mov	a,r2
	inc	a
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1814_1_1
	movx	a,@dptr
	add	a,#_SerialActiveMessageP__0__SendBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__SendBuff >> 8)
	mov	dph,a
	mov	a,#0x7E
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1799_1_1
	movx	a,@dptr
	mov	dptr,#_SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__SendBuff
	mov	b,#0x00
	lcall	_SCSuartDBGM__SCSuartDBG__UARTSend
	mov	c,_P1_2
	clr	a
	rlc	a
	mov	r2,a
	mov	r3,#0x00
	orl	a,r3
	jnz	00144$
	setb	_P1_2
	ret
00144$:
	clr	_P1_2
	ret
00148$:
	mov	dptr,#_FloodingM__Next_Addr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	b,#0x30
	mul	ab
	add	a,#_FloodingM__ForwardMsg
	mov	r4,a
	clr	a
	addc	a,#(_FloodingM__ForwardMsg >> 8)
	mov	r5,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_2
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_AMQueueEntryP__0__AMSend__send
	mov	a,dpl
	jz	00347$
	ret
00347$:
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	b,#0x30
	mul	ab
	add	a,#_FloodingM__ForwardMsg
	mov	r2,a
	clr	a
	addc	a,#(_FloodingM__ForwardMsg >> 8)
	mov	r3,a
	mov	r4,#0x00
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_FloodingM__insertMSGtoRTable
00151$:
	lcall	_RandomC__Random__rand16
	mov	r2,dpl
	mov	r3,dph
	mov	dptr,#__moduint_PARM_2
	mov	a,#0x0C
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	lcall	__moduint
	mov	r2,dpl
	mov	r3,dph
	mov	a,r2
	jnz	00156$
	mov	dpl,#0x0C
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00156$:
	cjne	r2,#0x0C,00349$
00349$:
	jc	00153$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1835_1_1
	mov	a,#0xFE
	movx	@dptr,a
	sjmp	00157$
00153$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1835_1_1
	mov	a,r2
	mov	b,#0x14
	mul	ab
	movx	@dptr,a
00157$:
	mov	_T3CNT,#0x00
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1835_1_1
	movx	a,@dptr
	mov	_T3CC0,a
	setb	_T3IE
	mov	r2,_T3CTL
	orl	ar2,#0x10
	mov	_T3CTL,r2
	ret
00159$:
	mov	dpl,#0x00
	ljmp	_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone
00160$:
	mov	dptr,#_HAL_CC2430ControlM__SendDoneError
	movx	a,@dptr
	mov	dpl,a
	ljmp	_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone
00161$:
	mov	_RFST,#0xE7
	mov	dptr,#0xDF62
	movx	a,@dptr
	mov	r2,a
	jb	acc.0,00163$
	mov	dptr,#_HAL_CC2430ControlM__SendDoneError
	mov	a,#0x20
	movx	@dptr,a
	mov	dpl,#0x06
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00163$:
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	dptr,#_HAL_CC2430ControlM__transmitPacketPtr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	a,#0x01
	add	a,r3
	mov	r6,a
	clr	a
	addc	a,r4
	mov	r7,a
	mov	ar0,r5
	mov	dpl,r6
	mov	dph,r7
	mov	b,r0
	lcall	__gptrget
	mov	r6,a
	jnb	acc.5,00165$
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	mov	a,#0x01
	movx	@dptr,a
	sjmp	00166$
00165$:
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	clr	a
	movx	@dptr,a
00166$:
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	mov	_RFD,r6
	mov	r7,#0x01
00167$:
	clr	c
	mov	a,r7
	subb	a,r6
	jnc	00169$
	push	ar2
	mov	a,r7
	add	a,r3
	mov	r0,a
	clr	a
	addc	a,r4
	mov	r1,a
	mov	ar2,r5
	mov	dpl,r0
	mov	dph,r1
	mov	b,r2
	lcall	__gptrget
	mov	_RFD,a
	inc	r7
	pop	ar2
	sjmp	00167$
00169$:
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	mov	a,#0x01
	movx	@dptr,a
	mov	_RFST,#0xE3
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	mov	a,#0x28
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_3
	mov	a,#0x01
	movx	@dptr,a
	mov	dpl,#0x02
	push	ar2
	lcall	_SCS_VTimerP__0__startTimer
	pop	ar2
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	ret
00171$:
	mov	dptr,#(_SCS_VTimerP__0__mTimerList + 0x001a)
	movx	a,@dptr
	anl	a,#0xfd
	movx	@dptr,a
	ret
00172$:
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	mov	a,#0x10
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_3
	mov	a,#0x01
	movx	@dptr,a
	mov	dpl,#0x03
	ljmp	_SCS_VTimerP__0__startTimer
00173$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	mov	a,#_HAL_CC2430ControlM__receivedPacket
	movx	@dptr,a
	inc	dptr
	mov	a,#(_HAL_CC2430ControlM__receivedPacket >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__receivedPacket
	movx	a,@dptr
	add	a,#0xf4
	mov	r2,a
	mov	dptr,#_HAL_CC2430ControlM__receivedPacket
	movx	@dptr,a
	mov	a,r2
	add	a,#(_HAL_CC2430ControlM__receivedPacket + 0x000b)
	mov	r3,a
	clr	a
	addc	a,#((_HAL_CC2430ControlM__receivedPacket + 0x000b) >> 8)
	mov	r4,a
	mov	r5,#0x00
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x002a)
	mov	b,#0x00
	mov	a,r3
	lcall	__gptrput
	mov	a,r2
	inc	a
	add	a,#(_HAL_CC2430ControlM__receivedPacket + 0x000b)
	mov	r2,a
	clr	a
	addc	a,#((_HAL_CC2430ControlM__receivedPacket + 0x000b) >> 8)
	mov	r3,a
	mov	r4,#0x00
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	a,#0x7F
	anl	a,r2
	mov	r3,a
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x002b)
	mov	b,#0x00
	mov	a,r3
	lcall	__gptrput
	anl	ar2,#0x80
	mov	a,r2
	rl	a
	anl	a,#0x01
	mov	r2,a
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x002c)
	mov	b,#0x00
	mov	a,r2
	lcall	__gptrput
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x0006)
	mov	b,#0x00
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	a,r2
	cjne	a,ar4,00178$
	mov	a,r3
	cjne	a,ar5,00178$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	sjmp	00179$
00178$:
	cjne	r2,#0xFF,00175$
	cjne	r3,#0xFF,00175$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	sjmp	00179$
00175$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00179$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1870_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	a,r2
	jnz	00358$
	ret
00358$:
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x000a)
	mov	b,#0x00
	lcall	__gptrget
	mov	r2,a
	cjne	r2,#0x0B,00359$
	sjmp	00360$
00359$:
	ret
00360$:
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__receivedPacket
	mov	b,#0x00
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	a,#0x02
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	mov	a,r5
	cjne	a,ar7,00191$
	mov	a,r6
	cjne	a,ar0,00191$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_FloodingM__isRecvPrevious
	mov	a,dpl
	jz	00363$
	ret
00363$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_memcpy_PARM_2
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x30
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__RecvMsg
	mov	b,#0x00
	lcall	_memcpy
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_FloodingM__insertMSGtoRTable
	mov	dpl,#0x02
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00191$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar2
	push	ar3
	push	ar4
	lcall	_FloodingM__isRecvPrevious
	mov	a,dpl
	pop	ar4
	pop	ar3
	pop	ar2
	jz	00364$
	ret
00364$:
	mov	a,#0x07
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jnz	00365$
	ret
00365$:
	dec	r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	__gptrput
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	dptr,#_FloodingM__Forward_Buff_Index
	inc	a
	movx	@dptr,a
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_FloodingM__Forward_Buff_Index
	mov	b,#0x05
	mov	a,r2
	div	ab
	mov	a,b
	movx	@dptr,a
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	b,#0x30
	mul	ab
	add	a,#_FloodingM__ForwardMsg
	mov	r2,a
	clr	a
	addc	a,#(_FloodingM__ForwardMsg >> 8)
	mov	r3,a
	mov	r4,#0x00
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1857_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_memcpy_PARM_2
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x30
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_memcpy
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	b,#0x30
	mul	ab
	add	a,#_FloodingM__ForwardMsg
	mov	r2,a
	clr	a
	addc	a,#(_FloodingM__ForwardMsg >> 8)
	mov	r3,a
	mov	r4,#0x00
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1
	mov	b,#0x00
	lcall	_memcpy
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1
	mov	a,#0x05
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1 + 0x0008)
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	cjne	r2,#0xFE,00184$
	cjne	r3,#0xFF,00184$
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1 + 0x0008)
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	sjmp	00185$
00184$:
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1 + 0x000a)
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1 + 0x0008)
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
00185$:
	mov	dptr,#_FloodingM__Forward_Buff_Index
	movx	a,@dptr
	mov	b,#0x30
	mul	ab
	add	a,#_FloodingM__ForwardMsg
	mov	r2,a
	clr	a
	addc	a,#(_FloodingM__ForwardMsg >> 8)
	mov	r3,a
	mov	r4,#0x00
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1893_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_memcpy
	mov	dpl,#0x03
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00197$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1980_1_1
	mov	a,_RFD
	movx	@dptr,a
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x7F,00368$
00368$:
	jnc	00199$
	mov	dptr,#_HAL_CC2430ControlM__receivedPacket
	mov	a,r2
	movx	@dptr,a
	sjmp	00200$
00199$:
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	r3,_RFIF
	anl	ar3,#0xDF
	mov	_RFIF,r3
	ret
00200$:
	mov	dptr,#0xDF53
	movx	a,@dptr
	mov	r3,a
	clr	c
	subb	a,r2
	clr	a
	rlc	a
	mov	r2,a
	jz	00302$
	mov	r4,#0x00
00206$:
	cjne	r4,#0x14,00371$
00371$:
	jnc	00208$
	mov	r5,#0x40
	mov	r6,#0x01
00201$:
	mov	a,r5
	orl	a,r6
	jz	00203$
	mov	dptr,#_BusyWaitMicroC__MicroValue_
	clr	a
	movx	@dptr,a
	clr	a
	movx	@dptr,a
	clr	a
	movx	@dptr,a
	dec	r5
	cjne	r5,#0xff,00201$
	dec	r6
	sjmp	00201$
00203$:
	mov	a,r2
	jz	00208$
	inc	r4
	sjmp	00206$
00208$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1980_1_1
	movx	a,@dptr
	mov	r2,a
	clr	c
	mov	a,r3
	subb	a,r2
	jnc	00302$
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	r2,_RFIF
	anl	ar2,#0xDF
	mov	_RFIF,r2
	ret
00302$:
	clr	c
	clr	a
	subb	a,r3
	clr	a
	rlc	a
	mov	r2,a
	cjne	r3,#0x81,00376$
00376$:
	clr	a
	rlc	a
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_1980_1_1
	movx	a,@dptr
	mov	r4,a
	mov	r5,#0x00
00219$:
	clr	c
	mov	a,r5
	subb	a,r4
	jnc	00221$
	mov	a,r2
	jz	00217$
	mov	a,r3
	jz	00214$
	mov	a,r5
	inc	a
	add	a,#_HAL_CC2430ControlM__receivedPacket
	mov	dpl,a
	clr	a
	addc	a,#(_HAL_CC2430ControlM__receivedPacket >> 8)
	mov	dph,a
	mov	a,_RFD
	movx	@dptr,a
	sjmp	00218$
00214$:
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	r6,_RFIF
	anl	ar6,#0xDF
	mov	_RFIF,r6
	ret
00217$:
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	r6,_RFIF
	anl	ar6,#0xDF
	mov	_RFIF,r6
	ret
00218$:
	inc	r5
	sjmp	00219$
00221$:
	mov	a,r4
	add	a,#_HAL_CC2430ControlM__receivedPacket
	mov	dpl,a
	clr	a
	addc	a,#(_HAL_CC2430ControlM__receivedPacket >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	jnb	acc.7,00228$
	mov	dptr,#(_HAL_CC2430ControlM__receivedPacket + 0x0001)
	movx	a,@dptr
	mov	r2,a
	anl	ar2,#0x03
	cjne	r2,#0x02,00225$
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	movx	a,@dptr
	mov	r2,a
	jz	00228$
	mov	dptr,#(_SCS_VTimerP__0__mTimerList + 0x0023)
	movx	a,@dptr
	anl	a,#0xfd
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	clr	a
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	movx	@dptr,a
	mov	dpl,#0x05
	lcall	_SchedulerBasicP__TaskBasic__postTask
	sjmp	00228$
00225$:
	mov	dpl,#0x0A
	lcall	_SchedulerBasicP__TaskBasic__postTask
00228$:
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	r2,_RFIF
	anl	ar2,#0xDF
	mov	_RFIF,r2
	ret
00230$:
	mov	dptr,#0xDF62
	movx	a,@dptr
	mov	r2,a
	anl	ar2,#0x01
	cjne	r2,#0x01,00241$
	mov	dptr,#_CC2430ActiveMessageM__TX_Ready_Msg
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov  r5,a
	add	a,#0xff - 0x7F
	jnc	00386$
	ret
00386$:
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	movx	a,@dptr
	mov	r6,a
	cjne	r6,#0x01,00387$
	ret
00387$:
	mov	r6,#0x00
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__transmitPacket
	mov	b,#0x00
	lcall	_memcpy
	mov	dptr,#_HAL_CC2430ControlM__transmitPacketPtr
	mov	a,#_HAL_CC2430ControlM__transmitPacket
	movx	@dptr,a
	inc	dptr
	mov	a,#(_HAL_CC2430ControlM__transmitPacket >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x07
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00241$:
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x04,00388$
00388$:
	jnc	00238$
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	mov	a,r2
	inc	a
	movx	@dptr,a
	mov	dpl,#0x04
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00238$:
	mov	dptr,#_CC2430ActiveMessageM__RF_Status
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	clr	a
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__TX_Ready_Msg
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_PARM_2
	mov	a,#0x01
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_AMQueueImplP__0__AMSend__sendDone
00243$:
	mov	dptr,#_AMQueueImplP__0__current
	movx	a,@dptr
	mov	b,#0x03
	mul	ab
	add	a,#_AMQueueImplP__0__queue
	mov	dpl,a
	clr	a
	addc	a,#(_AMQueueImplP__0__queue >> 8)
	mov	dph,a
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	ljmp	_AMQueueImplP__0__tryToSend
00244$:
	mov	dptr,#_SerialActiveMessageP__0__SendProcessing
	clr	a
	movx	@dptr,a
	ret
00245$:
	mov	dptr,#_SerialActiveMessageP__0__RecvAckType
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x44,00249$
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1
	mov	a,#0x7E
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1 + 0x0001)
	mov	a,#0x43
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1 + 0x0002)
	clr	a
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1 + 0x0003)
	mov	a,#0x9F
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1 + 0x0004)
	mov	a,#0x58
	movx	@dptr,a
	mov	dptr,#(_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1 + 0x0005)
	mov	a,#0x7E
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2
	mov	a,#0x06
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__runTask__cil_inline_tmp_2032_1_1
	mov	b,#0x00
	ljmp	_SCSuartDBGM__SCSuartDBG__UARTSend
00248$:
	ljmp	_SchedulerBasicP__TaskBasic__default__runTask
00249$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SCSuartDBGM__SCSuartDBG__UARTSend'
;------------------------------------------------------------
;len                       Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2'
;_data                     Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend__data_1_1'
;i                         Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend_i_1_1'
;_cil_inline_tmp_2051      Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend__cil_inline_tmp_2051_1_1'
;sloc0                     Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0'
;sloc1                     Allocated with name '_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0'
;------------------------------------------------------------
;	-----------------------------------------
;	 function SCSuartDBGM__SCSuartDBG__UARTSend
;	-----------------------------------------
_SCSuartDBGM__SCSuartDBG__UARTSend:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_SCSuartDBGM__SCSuartDBG__UARTSend__data_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	clr	c
	mov	a,#0x7E
	subb	a,r2
	clr	a
	subb	a,r3
	jnc	00115$
	mov	dptr,#_SCSuartDBGM__buff_start
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00115$:
	mov	dptr,#_SCSuartDBGM__SCSuartDBG__UARTSend__data_1_1
	movx	a,@dptr
	mov	_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0 + 2),a
	mov	dptr,#_SCSuartDBGM__SCSuartDBG__UARTSend_PARM_2
	movx	a,@dptr
	mov	r5,a
	mov	r6,#0x00
00105$:
	clr	c
	mov	a,r6
	subb	a,r5
	jnc	00107$
	mov	dptr,#_SCSuartDBGM__buff_end
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	clr	c
	mov	a,#0x7E
	subb	a,r7
	clr	a
	subb	a,r0
	jnc	00104$
	mov	dptr,#_SCSuartDBGM__buff_end
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00104$:
	push	ar5
	mov	dptr,#_SCSuartDBGM__buff_end
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	mov	a,r7
	add	a,#_SCSuartDBGM__str_buff
	mov	_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0,a
	mov	a,r0
	addc	a,#(_SCSuartDBGM__str_buff >> 8)
	mov	(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0 + 1),a
	mov	a,r6
	add	a,_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0
	mov	r5,a
	clr	a
	addc	a,(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0 + 1)
	mov	r1,a
	mov	r2,(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc1_1_0 + 2)
	mov	dpl,r5
	mov	dph,r1
	mov	b,r2
	lcall	__gptrget
	mov	dpl,_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0
	mov	dph,(_SCSuartDBGM__SCSuartDBG__UARTSend_sloc0_1_0 + 1)
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_end
	mov	a,#0x01
	add	a,r7
	movx	@dptr,a
	clr	a
	addc	a,r0
	inc	dptr
	movx	@dptr,a
	inc	r6
	pop	ar5
	sjmp	00105$
00107$:
	mov	dptr,#_SCSuartDBGM__state
	movx	a,@dptr
	mov	r2,a
	jnz	00109$
	mov	dptr,#_SCSuartDBGM__state
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	a,r2
	add	a,#_SCSuartDBGM__str_buff
	mov	dpl,a
	mov	a,r3
	addc	a,#(_SCSuartDBGM__str_buff >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	_U0BUF,a
00109$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'AMQueueImplP__0__tryToSend'
;------------------------------------------------------------
;nextMsg                   Allocated with name '_AMQueueImplP__0__tryToSend_nextMsg_1_1'
;_cil_inline_tmp_2055      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2055_1_1'
;_cil_inline_tmp_2056      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2056_1_1'
;_cil_inline_tmp_2061      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2061_1_1'
;_cil_inline_tmp_2067      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2067_1_1'
;_cil_inline_tmp_2073      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2073_1_1'
;_cil_inline_tmp_2080      Allocated with name '_AMQueueImplP__0__tryToSend__cil_inline_tmp_2080_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function AMQueueImplP__0__tryToSend
;	-----------------------------------------
_AMQueueImplP__0__tryToSend:
	mov	dptr,#_AMQueueImplP__0__current
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_AMQueueImplP__0__tryToSend__cil_inline_tmp_2056_1_1
	movx	@dptr,a
	cjne	r2,#0xFF,00102$
	mov	dptr,#_AMQueueImplP__0__tryToSend__cil_inline_tmp_2056_1_1
	clr	a
	movx	@dptr,a
00102$:
	mov	dptr,#_AMQueueImplP__0__tryToSend__cil_inline_tmp_2056_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,a
	mov	r4,#0x00
00105$:
	mov	ar5,r2
	mov	r6,#0x00
	inc	r5
	cjne	r5,#0x00,00123$
	inc	r6
00123$:
	clr	c
	mov	a,r3
	subb	a,r5
	mov	a,r4
	subb	a,r6
	jnc	00107$
	mov	a,r3
	clr	a
	mov	r5,a
	mov	b,#0x03
	mul	ab
	add	a,#_AMQueueImplP__0__queue
	mov	dpl,a
	clr	a
	addc	a,#(_AMQueueImplP__0__queue >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	cjne	r6,#0x00,00125$
	cjne	r7,#0x00,00125$
	sjmp	00104$
00125$:
	mov	dptr,#_AMQueueImplP__0__current
	mov	a,r5
	movx	@dptr,a
	sjmp	00108$
00104$:
	inc	r3
	cjne	r3,#0x00,00105$
	inc	r4
	sjmp	00105$
00107$:
	mov	dptr,#_AMQueueImplP__0__current
	mov	a,#0xFF
	movx	@dptr,a
00108$:
	mov	dptr,#_AMQueueImplP__0__current
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0xFF,00127$
	ret
00127$:
	mov	a,r2
	mov	b,#0x03
	mul	ab
	add	a,#_AMQueueImplP__0__queue
	mov	dpl,a
	clr	a
	addc	a,#(_AMQueueImplP__0__queue >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	a,#0x0A
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,#0x06
	add	a,r2
	mov	r6,a
	clr	a
	addc	a,r3
	mov	r7,a
	mov	ar0,r4
	mov	dpl,r6
	mov	dph,r7
	mov	b,r0
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r0,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_2
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_3
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_4
	mov	a,r0
	movx	@dptr,a
	mov	dpl,r5
	lcall	_CC2430ActiveMessageM__AMSend__send
	mov	a,dpl
	jz	00112$
	mov	dpl,#0x0D
	ljmp	_SchedulerBasicP__TaskBasic__postTask
00112$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CC2430ActiveMessageM__AMSend__send'
;------------------------------------------------------------
;sloc0                     Allocated with name '_CC2430ActiveMessageM__AMSend__send_sloc0_1_0'
;sloc1                     Allocated with name '_CC2430ActiveMessageM__AMSend__send_sloc1_1_0'
;addr                      Allocated with name '_CC2430ActiveMessageM__AMSend__send_PARM_2'
;msg                       Allocated with name '_CC2430ActiveMessageM__AMSend__send_PARM_3'
;len                       Allocated with name '_CC2430ActiveMessageM__AMSend__send_PARM_4'
;id                        Allocated with name '_CC2430ActiveMessageM__AMSend__send_id_1_1'
;tmp                       Allocated with name '_CC2430ActiveMessageM__AMSend__send_tmp_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function CC2430ActiveMessageM__AMSend__send
;	-----------------------------------------
_CC2430ActiveMessageM__AMSend__send:
	mov	a,dpl
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_id_1_1
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_2
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	_CC2430ActiveMessageM__AMSend__send_sloc1_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_CC2430ActiveMessageM__AMSend__send_sloc1_1_0 + 1),a
	mov	a,r2
	cjne	a,_CC2430ActiveMessageM__AMSend__send_sloc1_1_0,00102$
	mov	a,r3
	cjne	a,(_CC2430ActiveMessageM__AMSend__send_sloc1_1_0 + 1),00102$
	mov	dpl,#0x01
	ret
00102$:
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_4
	movx	a,@dptr
	mov  r6,a
	add	a,#0xff - 0x1C
	jnc	00104$
	mov	dpl,#0x02
	ret
00104$:
	mov	dptr,#_CC2430ActiveMessageM__RF_Status
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x01,00123$
	sjmp	00106$
00123$:
	mov	dpl,#0x05
	ret
00106$:
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_3
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	a,#0x0C
	add	a,r6
	mov	dpl,r7
	mov	dph,r0
	mov	b,r1
	lcall	__gptrput
	mov	a,#0x01
	add	a,r7
	mov	_CC2430ActiveMessageM__AMSend__send_sloc0_1_0,a
	clr	a
	addc	a,r0
	mov	(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1),a
	mov	(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2),r1
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	anl	ar6,#0x20
	mov	r4,#0x00
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	mov	dptr,#_CC2430ActiveMessageM__AckEnable
	movx	a,@dptr
	mov	r4,a
	jz	00111$
	cjne	r2,#0xFF,00125$
	cjne	r3,#0xFF,00125$
	sjmp	00108$
00125$:
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	anl	ar6,#0x20
	mov	r4,#0x00
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	sjmp	00112$
00108$:
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	anl	ar6,#0xDF
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	sjmp	00112$
00111$:
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	anl	ar6,#0xDF
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
00112$:
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	orl	ar6,#0x41
	orl	ar4,#0x88
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	mov	dptr,#_CC2430ActiveMessageM__MAC_Seq
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_tmp_1_1
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__MAC_Seq
	mov	a,r4
	inc	a
	movx	@dptr,a
	mov	a,#0x03
	add	a,r7
	mov	_CC2430ActiveMessageM__AMSend__send_sloc0_1_0,a
	clr	a
	addc	a,r0
	mov	(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1),a
	mov	(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2),r1
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_tmp_1_1
	movx	a,@dptr
	mov	dpl,_CC2430ActiveMessageM__AMSend__send_sloc0_1_0
	mov	dph,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_CC2430ActiveMessageM__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrput
	mov	a,#0x04
	add	a,r7
	mov	r4,a
	clr	a
	addc	a,r0
	mov	r5,a
	mov	ar6,r1
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,#0x22
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	mov	a,#0x06
	add	a,r7
	mov	r4,a
	clr	a
	addc	a,r0
	mov	r5,a
	mov	ar6,r1
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,r2
	lcall	__gptrput
	inc	dptr
	mov	a,r3
	lcall	__gptrput
	mov	a,#0x08
	add	a,r7
	mov	r2,a
	clr	a
	addc	a,r0
	mov	r3,a
	mov	ar4,r1
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_CC2430ActiveMessageM__AMSend__send_sloc1_1_0
	lcall	__gptrput
	inc	dptr
	mov	a,(_CC2430ActiveMessageM__AMSend__send_sloc1_1_0 + 1)
	lcall	__gptrput
	mov	a,#0x0A
	add	a,r7
	mov	r2,a
	clr	a
	addc	a,r0
	mov	r3,a
	mov	ar4,r1
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_id_1_1
	movx	a,@dptr
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrput
	mov	dptr,#_CC2430ActiveMessageM__TX_Ready_Msg
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__RF_Status
	mov	a,#0x02
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	clr	a
	movx	@dptr,a
	mov	dpl,#0x04
	lcall	_SchedulerBasicP__TaskBasic__postTask
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SchedulerBasicP__TaskBasic__postTask'
;------------------------------------------------------------
;id                        Allocated with name '_SchedulerBasicP__TaskBasic__postTask_id_1_1'
;__nesc_atomic             Allocated with name '_SchedulerBasicP__TaskBasic__postTask___nesc_atomic_1_1'
;tmp___1                   Allocated with name '_SchedulerBasicP__TaskBasic__postTask_tmp___1_1_1'
;_cil_inline_tmp_2086      Allocated with name '_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2086_1_1'
;_cil_inline_tmp_2087      Allocated with name '_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2087_1_1'
;_cil_inline_tmp_2092      Allocated with name '_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1'
;_cil_inline_tmp_2094      Allocated with name '_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2094_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function SchedulerBasicP__TaskBasic__postTask
;	-----------------------------------------
_SchedulerBasicP__TaskBasic__postTask:
	mov	a,dpl
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_id_1_1
	movx	@dptr,a
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_id_1_1
	movx	a,@dptr
	mov	r3,a
	add	a,#_SchedulerBasicP__m_next
	mov	dpl,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r4,a
	mov	r5,#0x00
	cjne	r4,#0xFF,00123$
	cjne	r5,#0x00,00123$
	sjmp	00105$
00123$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	sjmp	00106$
00105$:
	mov	dptr,#_SchedulerBasicP__m_tail
	movx	a,@dptr
	mov	r4,a
	clr	a
	mov	r5,a
	mov	r6,a
	mov	a,r4
	cjne	a,ar3,00102$
	mov	a,r5
	cjne	a,ar6,00102$
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	sjmp	00106$
00102$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00106$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2092_1_1
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	a,r3
	jz	00111$
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2087_1_1
	clr	a
	movx	@dptr,a
	sjmp	00112$
00111$:
	mov	dptr,#_SchedulerBasicP__m_head
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	cjne	r3,#0xFF,00108$
	cjne	r4,#0x00,00108$
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_id_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SchedulerBasicP__m_head
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__m_tail
	mov	a,r3
	movx	@dptr,a
	sjmp	00109$
00108$:
	mov	dptr,#_SchedulerBasicP__m_tail
	movx	a,@dptr
	add	a,#_SchedulerBasicP__m_next
	mov	r3,a
	clr	a
	addc	a,#(_SchedulerBasicP__m_next >> 8)
	mov	r4,a
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_id_1_1
	movx	a,@dptr
	mov	r5,a
	mov	dpl,r3
	mov	dph,r4
	movx	@dptr,a
	mov	dptr,#_SchedulerBasicP__m_tail
	mov	a,r5
	movx	@dptr,a
00109$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2087_1_1
	mov	a,#0x01
	movx	@dptr,a
00112$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask__cil_inline_tmp_2087_1_1
	movx	a,@dptr
	mov	r3,a
	jz	00114$
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_tmp___1_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	sjmp	00115$
00114$:
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_tmp___1_1_1
	mov	a,#0x05
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
00115$:
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	mov	dptr,#_SchedulerBasicP__TaskBasic__postTask_tmp___1_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'AMQueueImplP__0__AMSend__sendDone'
;------------------------------------------------------------
;err                       Allocated with name '_AMQueueImplP__0__AMSend__sendDone_PARM_2'
;msg                       Allocated with name '_AMQueueImplP__0__AMSend__sendDone_msg_1_1'
;last                      Allocated with name '_AMQueueImplP__0__AMSend__sendDone_last_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function AMQueueImplP__0__AMSend__sendDone
;	-----------------------------------------
_AMQueueImplP__0__AMSend__sendDone:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_msg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_AMQueueImplP__0__current
	movx	a,@dptr
	mov	r2,a
	mov	b,#0x03
	mul	ab
	add	a,#_AMQueueImplP__0__queue
	mov	r3,a
	clr	a
	addc	a,#(_AMQueueImplP__0__queue >> 8)
	mov	r4,a
	mov	dpl,r3
	mov	dph,r4
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_msg_1_1
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	a,r5
	cjne	a,ar7,00106$
	mov	a,r6
	cjne	a,ar0,00106$
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_last_1_1
	mov	a,r2
	movx	@dptr,a
	mov	dpl,r3
	mov	dph,r4
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	lcall	_AMQueueImplP__0__tryToSend
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_last_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0x00,00106$
	cjne	r3,#0x00,00106$
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_PARM_2
	movx	a,@dptr
	mov	r2,a
	jnz	00106$
	setb	_P1_4
00106$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CC2430ActiveMessageM__Packet__getPayload'
;------------------------------------------------------------
;len                       Allocated with name '_CC2430ActiveMessageM__Packet__getPayload_PARM_2'
;msg                       Allocated with name '_CC2430ActiveMessageM__Packet__getPayload_msg_1_1'
;_cil_inline_tmp_2111      Allocated with name '_CC2430ActiveMessageM__Packet__getPayload__cil_inline_tmp_2111_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function CC2430ActiveMessageM__Packet__getPayload
;	-----------------------------------------
_CC2430ActiveMessageM__Packet__getPayload:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_msg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	ar5,r2
	mov	ar6,r3
	cjne	r5,#0x00,00106$
	cjne	r6,#0x00,00106$
	sjmp	00102$
00106$:
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_msg_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrput
00102$:
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_msg_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	a,#0x0B
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'FloodingM__isRecvPrevious'
;------------------------------------------------------------
;msg                       Allocated with name '_FloodingM__isRecvPrevious_msg_1_1'
;pack                      Allocated with name '_FloodingM__isRecvPrevious_pack_1_1'
;return_status             Allocated with name '_FloodingM__isRecvPrevious_return_status_1_1'
;i                         Allocated with name '_FloodingM__isRecvPrevious_i_1_1'
;_cil_inline_tmp_2133      Allocated with name '_FloodingM__isRecvPrevious__cil_inline_tmp_2133_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function FloodingM__isRecvPrevious
;	-----------------------------------------
_FloodingM__isRecvPrevious:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_FloodingM__isRecvPrevious_msg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_FloodingM__isRecvPrevious_return_status_1_1
	clr	a
	movx	@dptr,a
	mov	dptr,#_FloodingM__isRecvPrevious_msg_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__isRecvPrevious_pack_1_1
	mov	b,#0x00
	lcall	_memcpy
	mov	r2,#0x00
00107$:
	cjne	r2,#0x14,00117$
00117$:
	jnc	00109$
	mov	a,r2
	mov	b,#0x05
	mul	ab
	mov	r3,a
	add	a,#_FloodingM__RTable
	mov	dpl,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#(_FloodingM__isRecvPrevious_pack_1_1 + 0x0002)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r4
	cjne	a,ar6,00106$
	mov	a,r5
	cjne	a,ar7,00106$
	mov	a,r3
	add	a,#_FloodingM__RTable
	mov	r3,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	r4,a
	mov	dpl,r3
	mov	dph,r4
	inc	dptr
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	dptr,#(_FloodingM__isRecvPrevious_pack_1_1 + 0x0004)
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	mov	a,r5
	cjne	a,ar7,00106$
	mov	a,r6
	cjne	a,ar0,00106$
	mov	dpl,r3
	mov	dph,r4
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_FloodingM__isRecvPrevious_pack_1_1 + 0x0006)
	movx	a,@dptr
	mov	r4,a
	mov	a,r3
	cjne	a,ar4,00106$
	mov	dptr,#_FloodingM__isRecvPrevious_return_status_1_1
	mov	a,#0x01
	movx	@dptr,a
	sjmp	00109$
00106$:
	inc	r2
	sjmp	00107$
00109$:
	mov	dptr,#_FloodingM__isRecvPrevious_return_status_1_1
	movx	a,@dptr
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'FloodingM__insertMSGtoRTable'
;------------------------------------------------------------
;msg                       Allocated with name '_FloodingM__insertMSGtoRTable_msg_1_1'
;pack                      Allocated with name '_FloodingM__insertMSGtoRTable_pack_1_1'
;_cil_inline_tmp_2154      Allocated with name '_FloodingM__insertMSGtoRTable__cil_inline_tmp_2154_1_1'
;_cil_inline_tmp_2156      Allocated with name '_FloodingM__insertMSGtoRTable__cil_inline_tmp_2156_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function FloodingM__insertMSGtoRTable
;	-----------------------------------------
_FloodingM__insertMSGtoRTable:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_FloodingM__insertMSGtoRTable_msg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_FloodingM__insertMSGtoRTable_msg_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__insertMSGtoRTable_pack_1_1
	mov	b,#0x00
	lcall	_memcpy
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	dptr,#_FloodingM__RTable_Index
	movx	a,@dptr
	mov	r3,a
	mov	b,#0x05
	mul	ab
	mov	r4,a
	add	a,#_FloodingM__RTable
	mov	r5,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	r6,a
	mov	dptr,#(_FloodingM__insertMSGtoRTable_pack_1_1 + 0x0002)
	movx	a,@dptr
	mov	r7,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	mov	dpl,r5
	mov	dph,r6
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	mov	a,r4
	add	a,#_FloodingM__RTable
	mov	r4,a
	clr	a
	addc	a,#(_FloodingM__RTable >> 8)
	mov	r5,a
	mov	a,#0x02
	add	a,r4
	mov	r6,a
	clr	a
	addc	a,r5
	mov	r7,a
	mov	dptr,#(_FloodingM__insertMSGtoRTable_pack_1_1 + 0x0004)
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	dpl,r6
	mov	dph,r7
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	mov	a,#0x04
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dptr,#(_FloodingM__insertMSGtoRTable_pack_1_1 + 0x0006)
	movx	a,@dptr
	mov	dpl,r4
	mov	dph,r5
	movx	@dptr,a
	mov	dptr,#_FloodingM__RTable_Index
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#_FloodingM__RTable_Index
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_FloodingM__RTable_Index
	mov	b,#0x14
	mov	a,r3
	div	ab
	mov	a,b
	movx	@dptr,a
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SCS_VTimerP__0__startTimer'
;------------------------------------------------------------
;sloc0                     Allocated with name '_SCS_VTimerP__0__startTimer_sloc0_1_0'
;sloc1                     Allocated with name '_SCS_VTimerP__0__startTimer_sloc1_1_0'
;interval                  Allocated with name '_SCS_VTimerP__0__startTimer_PARM_2'
;isoneshot                 Allocated with name '_SCS_VTimerP__0__startTimer_PARM_3'
;id                        Allocated with name '_SCS_VTimerP__0__startTimer_id_1_1'
;_cil_inline_tmp_2161      Allocated with name '_SCS_VTimerP__0__startTimer__cil_inline_tmp_2161_1_1'
;_cil_inline_tmp_2164      Allocated with name '_SCS_VTimerP__0__startTimer__cil_inline_tmp_2164_1_1'
;_cil_inline_tmp_2165      Allocated with name '_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1'
;_cil_inline_tmp_2166      Allocated with name '_SCS_VTimerP__0__startTimer__cil_inline_tmp_2166_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function SCS_VTimerP__0__startTimer
;	-----------------------------------------
_SCS_VTimerP__0__startTimer:
	mov	a,dpl
	mov	dptr,#_SCS_VTimerP__0__startTimer_id_1_1
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__startTimer_id_1_1
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x04,00119$
00119$:
	jc	00102$
	mov	dpl,#0x00
	ret
00102$:
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	a,r3
	orl	a,r4
	orl	a,r5
	orl	a,r6
	jnz	00108$
	mov	ar7,r2
	mov	r0,a
	cjne	r7,#0x00,00122$
	cjne	r0,#0x00,00122$
	sjmp	00103$
00122$:
	cjne	r7,#0x02,00123$
	cjne	r0,#0x00,00123$
	sjmp	00104$
00123$:
	cjne	r7,#0x03,00106$
	cjne	r0,#0x00,00106$
	sjmp	00105$
00103$:
	lcall	_Adhoc_APPM__Timer__fired
	sjmp	00106$
00104$:
	lcall	_HAL_CC2430ControlM__TX_TimeOut__fired
	sjmp	00106$
00105$:
	lcall	_HAL_CC2430ControlM__ACK_TimeOut__fired
00106$:
	mov	dpl,#0x00
	ret
00108$:
	mov	a,r2
	mov	b,#0x09
	mul	ab
	mov	r2,a
	add	a,#_SCS_VTimerP__0__mTimerList
	mov	dpl,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__mTimerList >> 8)
	mov	dph,a
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	mov	a,r2
	add	a,#_SCS_VTimerP__0__mTimerList
	mov	_SCS_VTimerP__0__startTimer_sloc1_1_0,a
	clr	a
	addc	a,#(_SCS_VTimerP__0__mTimerList >> 8)
	mov	(_SCS_VTimerP__0__startTimer_sloc1_1_0 + 1),a
	mov	a,#0x08
	add	a,_SCS_VTimerP__0__startTimer_sloc1_1_0
	mov	_SCS_VTimerP__0__startTimer_sloc0_1_0,a
	clr	a
	addc	a,(_SCS_VTimerP__0__startTimer_sloc1_1_0 + 1)
	mov	(_SCS_VTimerP__0__startTimer_sloc0_1_0 + 1),a
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_3
	movx	a,@dptr
	mov	dpl,_SCS_VTimerP__0__startTimer_sloc0_1_0
	mov	dph,(_SCS_VTimerP__0__startTimer_sloc0_1_0 + 1)
	rrc	a
	movx	a,@dptr
	mov	acc.0,c
	movx	@dptr,a
	mov	c,_EA
	clr	a
	rlc	a
	mov	_SCS_VTimerP__0__startTimer_sloc0_1_0,a
	clr	_EA
	mov	dptr,#_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1
	mov	a,_T1CNTL
	movx	@dptr,a
	mov	dptr,#(_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1 + 0x0001)
	mov	b,#0x00
	mov	a,_T1CNTH
	lcall	__gptrput
	mov	dptr,#_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	mov	dptr,#__divuint_PARM_2
	mov	a,#0x7D
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r1
	mov	dph,r0
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	__divuint
	mov	a,dpl
	mov	b,dph
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	mov	dptr,#_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__startTimer__cil_inline_tmp_2165_1_1
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,#0x00
	mov	r2,#0x00
	mov	r7,#0x00
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	mov	a,r0
	add	a,r3
	movx	@dptr,a
	mov	a,r1
	addc	a,r4
	inc	dptr
	movx	@dptr,a
	mov	a,r2
	addc	a,r5
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	addc	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,#0x04
	add	a,_SCS_VTimerP__0__startTimer_sloc1_1_0
	mov	r2,a
	clr	a
	addc	a,(_SCS_VTimerP__0__startTimer_sloc1_1_0 + 1)
	mov	r3,a
	mov	dptr,#_SCS_VTimerP__0__startTimer_PARM_2
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	mov	dpl,_SCS_VTimerP__0__startTimer_sloc1_1_0
	mov	dph,(_SCS_VTimerP__0__startTimer_sloc1_1_0 + 1)
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	movx	a,@dptr
	orl	a,#0x02
	movx	@dptr,a
	mov	dptr,#_SCS_VTimerP__0__mInterval
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	r0,#0x00
	mov	r1,#0x00
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	subb	a,r3
	mov	a,r6
	subb	a,r0
	mov	a,r7
	subb	a,r1
	jnc	00110$
	mov	dptr,#_SCS_VTimerP__0__mInterval
	mov	a,r4
	movx	@dptr,a
	mov	dpl,r4
	lcall	_HplSCS_Clock_Timer1P__Alarm__start
00110$:
	mov	a,_SCS_VTimerP__0__startTimer_sloc0_1_0
	add	a,#0xff
	mov	_EA,c
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'HAL_CC2430ControlM__ACK_TimeOut__fired'
;------------------------------------------------------------
;------------------------------------------------------------
;	-----------------------------------------
;	 function HAL_CC2430ControlM__ACK_TimeOut__fired
;	-----------------------------------------
_HAL_CC2430ControlM__ACK_TimeOut__fired:
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	clr	a
	movx	@dptr,a
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	movx	@dptr,a
	mov	_RFST,#0xE7
	mov	dptr,#_HAL_CC2430ControlM__SendDoneError
	mov	a,#0x22
	movx	@dptr,a
	mov	dpl,#0x06
	ljmp	_SchedulerBasicP__TaskBasic__postTask
;------------------------------------------------------------
;Allocation info for local variables in function 'HAL_CC2430ControlM__TX_TimeOut__fired'
;------------------------------------------------------------
;------------------------------------------------------------
;	-----------------------------------------
;	 function HAL_CC2430ControlM__TX_TimeOut__fired
;	-----------------------------------------
_HAL_CC2430ControlM__TX_TimeOut__fired:
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	clr	a
	movx	@dptr,a
	mov	_RFST,#0xE7
	mov	dptr,#_HAL_CC2430ControlM__SendDoneError
	mov	a,#0x21
	movx	@dptr,a
	mov	dpl,#0x06
	ljmp	_SchedulerBasicP__TaskBasic__postTask
;------------------------------------------------------------
;Allocation info for local variables in function 'Adhoc_APPM__Timer__fired'
;------------------------------------------------------------
;APP_M                     Allocated with name '_Adhoc_APPM__Timer__fired_APP_M_1_1'
;tmp                       Allocated with name '_Adhoc_APPM__Timer__fired_tmp_1_1'
;_cil_inline_tmp_2174      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2174_1_1'
;_cil_inline_tmp_2184      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1'
;_cil_inline_tmp_2209      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2209_1_1'
;_cil_inline_tmp_2229      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2229_1_1'
;_cil_inline_tmp_2231      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2231_1_1'
;_cil_inline_tmp_2234      Allocated with name '_Adhoc_APPM__Timer__fired__cil_inline_tmp_2234_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function Adhoc_APPM__Timer__fired
;	-----------------------------------------
_Adhoc_APPM__Timer__fired:
	mov	dptr,#_Adhoc_APPM__APP_Seq
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_Adhoc_APPM__Timer__fired_tmp_1_1
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_Adhoc_APPM__APP_Seq
	mov	a,#0x01
	add	a,r2
	movx	@dptr,a
	clr	a
	addc	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_Adhoc_APPM__Timer__fired_tmp_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_Adhoc_APPM__Timer__fired_APP_M_1_1
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 + 0x0002)
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 + 0x0004)
	mov	a,#0xBB
	movx	@dptr,a
	inc	dptr
	mov	a,#0xAA
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 + 0x0006)
	mov	a,#0xDD
	movx	@dptr,a
	inc	dptr
	mov	a,#0xCC
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 + 0x0008)
	mov	a,#0xFF
	movx	@dptr,a
	inc	dptr
	mov	a,#0xEE
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 + 0x000a)
	mov	a,#0x34
	movx	@dptr,a
	inc	dptr
	mov	a,#0x12
	movx	@dptr,a
	mov	dptr,#_Adhoc_APPM__RF_MSG
	mov	b,#0x00
	lcall	_FloodingM__SendFromAPP__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,#_Adhoc_APPM__Timer__fired_APP_M_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_Adhoc_APPM__Timer__fired_APP_M_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x0C
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_memcpy
	mov	c,_P1_3
	clr	a
	rlc	a
	mov	r2,a
	mov	r3,#0x00
	orl	a,r3
	jnz	00102$
	setb	_P1_3
	sjmp	00103$
00102$:
	clr	_P1_3
00103$:
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_Adhoc_APPM__RF_MSG
	mov	b,#0x00
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1
	mov	a,#0x04
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x0002)
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x0004)
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
	mov	dptr,#_FloodingM__mySequence
	movx	a,@dptr
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x0006)
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x0007)
	mov	a,#0x05
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x0008)
	mov	a,#0xFE
	movx	@dptr,a
	inc	dptr
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x000a)
	mov	a,#0xFE
	movx	@dptr,a
	inc	dptr
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x0C
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 + 0x000c)
	mov	b,#0x00
	lcall	_memcpy
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_FloodingM__SendMsg
	mov	b,#0x00
	lcall	_CC2430ActiveMessageM__Packet__getPayload
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	dptr,#_memcpy_PARM_2
	mov	a,#_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_Adhoc_APPM__Timer__fired__cil_inline_tmp_2184_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_memcpy
	mov	dptr,#_FloodingM__mySequence
	movx	a,@dptr
	mov	dptr,#_FloodingM__mySequence
	inc	a
	movx	@dptr,a
	mov	dptr,#_FloodingM__mySequence
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_FloodingM__mySequence
	mov	b,#0xFF
	mov	a,r2
	div	ab
	mov	a,b
	movx	@dptr,a
	mov	dptr,#_FloodingM__Next_Addr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_2
	mov	a,#_FloodingM__SendMsg
	movx	@dptr,a
	inc	dptr
	mov	a,#(_FloodingM__SendMsg >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_3
	mov	a,#0x18
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	lcall	_AMQueueEntryP__0__AMSend__send
	mov	a,dpl
	mov	r2,a
	jnz	00105$
	mov	dptr,#_FloodingM__SendMsg
	mov	b,a
	push	ar2
	lcall	_FloodingM__insertMSGtoRTable
	pop	ar2
00105$:
	mov	a,r2
	jnz	00107$
	clr	_P1_4
00107$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'FloodingM__SendFromAPP__getPayload'
;------------------------------------------------------------
;msg                       Allocated with name '_FloodingM__SendFromAPP__getPayload_msg_1_1'
;_cil_inline_tmp_2255      Allocated with name '_FloodingM__SendFromAPP__getPayload__cil_inline_tmp_2255_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function FloodingM__SendFromAPP__getPayload
;	-----------------------------------------
_FloodingM__SendFromAPP__getPayload:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_FloodingM__SendFromAPP__getPayload_msg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_FloodingM__SendFromAPP__getPayload_msg_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_CC2430ActiveMessageM__Packet__getPayload_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_CC2430ActiveMessageM__Packet__getPayload
;------------------------------------------------------------
;Allocation info for local variables in function 'AMQueueEntryP__0__AMSend__send'
;------------------------------------------------------------
;sloc0                     Allocated with name '_AMQueueEntryP__0__AMSend__send_sloc0_1_0'
;sloc1                     Allocated with name '_AMQueueEntryP__0__AMSend__send_sloc1_1_0'
;msg                       Allocated with name '_AMQueueEntryP__0__AMSend__send_PARM_2'
;len                       Allocated with name '_AMQueueEntryP__0__AMSend__send_PARM_3'
;dest                      Allocated with name '_AMQueueEntryP__0__AMSend__send_dest_1_1'
;_cil_inline_tmp_2270      Allocated with name '_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1'
;_cil_inline_tmp_2286      Allocated with name '_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2286_1_1'
;_cil_inline_tmp_2292      Allocated with name '_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2292_1_1'
;_cil_inline_tmp_2300      Allocated with name '_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2300_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function AMQueueEntryP__0__AMSend__send
;	-----------------------------------------
_AMQueueEntryP__0__AMSend__send:
	mov	r2,dph
	mov	a,dpl
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_dest_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_2
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	a,#0x06
	add	a,r2
	mov	_AMQueueEntryP__0__AMSend__send_sloc1_1_0,a
	clr	a
	addc	a,r3
	mov	(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 1),a
	mov	(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 2),r4
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_dest_1_1
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	dpl,_AMQueueEntryP__0__AMSend__send_sloc1_1_0
	mov	dph,(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 1)
	mov	b,(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 2)
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r1
	lcall	__gptrput
	mov	a,#0x0A
	add	a,r2
	mov	_AMQueueEntryP__0__AMSend__send_sloc0_1_0,a
	clr	a
	addc	a,r3
	mov	(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 1),a
	mov	(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 2),r4
	mov	dpl,_AMQueueEntryP__0__AMSend__send_sloc0_1_0
	mov	dph,(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 2)
	mov	a,#0x0B
	lcall	__gptrput
	mov	dptr,#_AMQueueImplP__0__queue
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	cjne	r0,#0x00,00113$
	cjne	r1,#0x00,00113$
	sjmp	00102$
00113$:
	mov	dptr,#_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1
	mov	a,#0x05
	movx	@dptr,a
	ljmp	00107$
00102$:
	mov	dptr,#_AMQueueImplP__0__queue
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_AMQueueEntryP__0__AMSend__send_PARM_3
	movx	a,@dptr
	mov	r5,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrput
	mov	dptr,#_AMQueueImplP__0__current
	movx	a,@dptr
	mov	r6,a
	cjne	r6,#0xFF,00106$
	mov	dpl,_AMQueueEntryP__0__AMSend__send_sloc0_1_0
	mov	dph,(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 1)
	mov	b,(_AMQueueEntryP__0__AMSend__send_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r6,a
	mov	dpl,_AMQueueEntryP__0__AMSend__send_sloc1_1_0
	mov	dph,(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 1)
	mov	b,(_AMQueueEntryP__0__AMSend__send_sloc1_1_0 + 2)
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r0,a
	mov	dptr,#_AMQueueImplP__0__current
	clr	a
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_2
	mov	a,r7
	movx	@dptr,a
	inc	dptr
	mov	a,r0
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_3
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__AMSend__send_PARM_4
	mov	a,r5
	movx	@dptr,a
	mov	dpl,r6
	lcall	_CC2430ActiveMessageM__AMSend__send
	mov	a,dpl
	mov	r2,a
	jz	00104$
	mov	dptr,#_AMQueueImplP__0__current
	mov	a,#0xFF
	movx	@dptr,a
	mov	dptr,#_AMQueueImplP__0__queue
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00104$:
	mov	dptr,#_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1
	mov	a,r2
	movx	@dptr,a
	sjmp	00107$
00106$:
	mov	dptr,#_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1
	clr	a
	movx	@dptr,a
00107$:
	mov	dptr,#_AMQueueEntryP__0__AMSend__send__cil_inline_tmp_2270_1_1
	movx	a,@dptr
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'HplSCS_Clock_Timer1P__Alarm__start'
;------------------------------------------------------------
;dt                        Allocated with name '_HplSCS_Clock_Timer1P__Alarm__start_dt_1_1'
;r                         Allocated with name '_HplSCS_Clock_Timer1P__Alarm__start_r_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function HplSCS_Clock_Timer1P__Alarm__start
;	-----------------------------------------
_HplSCS_Clock_Timer1P__Alarm__start:
	mov	a,dpl
	mov	dptr,#_HplSCS_Clock_Timer1P__Alarm__start_dt_1_1
	movx	@dptr,a
	mov	dptr,#_HplSCS_Clock_Timer1P__Alarm__start_dt_1_1
	movx	a,@dptr
	mov	dptr,#_HplSCS_Clock_Timer1P__Alarm__start_r_1_1
	mov	b,#0x7D
	mul	ab
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	mov	dptr,#_HplSCS_Clock_Timer1P__Alarm__start_r_1_1
	movx	a,@dptr
	mov	_T1CC0L,a
	mov	dptr,#(_HplSCS_Clock_Timer1P__Alarm__start_r_1_1 + 0x0001)
	mov	b,#0x00
	lcall	__gptrget
	mov	_T1CC0H,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone'
;------------------------------------------------------------
;err                       Allocated with name '_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone_err_1_1'
;_cil_inline_tmp_2305      Allocated with name '_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone__cil_inline_tmp_2305_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone
;	-----------------------------------------
_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone:
	mov	a,dpl
	mov	dptr,#_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone_err_1_1
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__RF_Status
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__NumReTX
	clr	a
	movx	@dptr,a
	mov	dptr,#_CC2430ActiveMessageM__TX_Ready_Msg
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_CC2430ActiveMessageM__CC2430_TX_RX__sendPacketDone_err_1_1
	movx	a,@dptr
	mov	dptr,#_AMQueueImplP__0__AMSend__sendDone_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_AMQueueImplP__0__AMSend__sendDone
;------------------------------------------------------------
;Allocation info for local variables in function 'RandomC__Random__rand16'
;------------------------------------------------------------
;tmp                       Allocated with name '_RandomC__Random__rand16_tmp_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function RandomC__Random__rand16
;	-----------------------------------------
_RandomC__Random__rand16:
	mov	dptr,#_RandomC__randValue16
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#__mulint_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#0x0085
	lcall	__mulint
	mov	a,dpl
	mov	b,dph
	mov	dptr,#_RandomC__randValue16
	movx	@dptr,a
	inc	dptr
	mov	a,b
	movx	@dptr,a
	mov	dptr,#_RandomC__RSeq
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_RandomC__Random__rand16_tmp_1_1
	movx	@dptr,a
	mov	dptr,#_RandomC__RSeq
	mov	a,r2
	inc	a
	movx	@dptr,a
	mov	dptr,#_RandomC__Random__rand16_tmp_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dptr,#_RandomC__randValue16
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_RandomC__randValue16
	mov	a,r2
	add	a,r4
	movx	@dptr,a
	mov	a,r3
	addc	a,r5
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_RandomC__randValue16
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	dpl,r2
	mov	dph,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'crcByte'
;------------------------------------------------------------
;b                         Allocated with name '_crcByte_PARM_2'
;crc                       Allocated with name '_crcByte_crc_1_1'
;i                         Allocated with name '_crcByte_i_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function crcByte
;	-----------------------------------------
_crcByte:
	mov	r2,dph
	mov	a,dpl
	mov	dptr,#_crcByte_crc_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_crcByte_PARM_2
	movx	a,@dptr
	mov	r3,a
	mov	r2,#0x00
	mov	dptr,#_crcByte_crc_1_1
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_crcByte_crc_1_1
	mov	a,r2
	xrl	a,r4
	movx	@dptr,a
	mov	a,r3
	xrl	a,r5
	inc	dptr
	movx	@dptr,a
	mov	r2,#0x08
00107$:
	mov	dptr,#_crcByte_crc_1_1
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	ar5,r3
	mov	ar6,r4
	clr	a
	mov	r7,a
	mov	r0,a
	mov	a,r6
	jb	acc.7,00115$
	mov	a,r7
	jnz	00115$
	mov	a,r0
	jz	00102$
00115$:
	mov	ar5,r3
	mov	a,r4
	xch	a,r5
	add	a,acc
	xch	a,r5
	rlc	a
	mov	r6,a
	mov	dptr,#_crcByte_crc_1_1
	mov	a,#0x21
	xrl	a,r5
	movx	@dptr,a
	mov	a,#0x10
	xrl	a,r6
	inc	dptr
	movx	@dptr,a
	sjmp	00103$
00102$:
	mov	a,r4
	xch	a,r3
	add	a,acc
	xch	a,r3
	rlc	a
	mov	r4,a
	mov	dptr,#_crcByte_crc_1_1
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
00103$:
	djnz	r2,00107$
	mov	dptr,#_crcByte_crc_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	dpl,r2
	mov	dph,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'RandomC__SeedInit__init'
;------------------------------------------------------------
;param                     Allocated with name '_RandomC__SeedInit__init_param_1_1'
;CurrentT                  Allocated with name '_RandomC__SeedInit__init_CurrentT_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function RandomC__SeedInit__init
;	-----------------------------------------
_RandomC__SeedInit__init:
	mov	r2,dph
	mov	a,dpl
	mov	dptr,#_RandomC__SeedInit__init_param_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
	mov	r2,_T1CNTL
	mov	ar3,r2
	mov	r2,#0x00
	mov	r4,_T1CNTH
	mov	r5,#0x00
	mov	a,r4
	orl	ar2,a
	mov	a,r5
	orl	ar3,a
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_RandomC__SeedInit__init_param_1_1
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r4
	add	a,r6
	mov	r6,a
	mov	a,r5
	addc	a,r7
	mov	r7,a
	mov	a,r2
	add	a,r6
	mov	r2,a
	mov	a,r3
	addc	a,r7
	mov	r3,a
	mov	dptr,#_RandomC__Rseed
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_RandomC__randValue16
	mov	a,#0x1F
	add	a,r2
	movx	@dptr,a
	clr	a
	addc	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_RandomC__RSeq
	mov	a,r4
	movx	@dptr,a
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_9'
;------------------------------------------------------------
;_cil_inline_tmp_2308      Allocated with name '___vector_9__cil_inline_tmp_2308_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_9
;	-----------------------------------------
___vector_9:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	r3,_T1CTL
	mov	r4,#0x00
	mov	a,r3
	jnb	acc.4,00102$
	mov	r3,_T1CTL
	anl	ar3,#0xEF
	mov	r4,#0x00
	mov	_T1CTL,r3
00102$:
	mov	r3,_T1CCTL0
	mov	r4,#0x00
	mov	a,r3
	jnb	acc.6,00106$
	mov	r3,_T1CTL
	mov	r4,#0x00
	mov	a,r3
	jnb	acc.5,00106$
	mov	r3,_T1CTL
	anl	ar3,#0xDF
	mov	_T1CTL,r3
	mov	dpl,#0x00
	push	ar2
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar2
00106$:
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_0'
;------------------------------------------------------------
;_cil_inline_tmp_2313      Allocated with name '___vector_0__cil_inline_tmp_2313_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_0
;	-----------------------------------------
___vector_0:
	push	acc
	push	ar2
	push	psw
	mov	psw,#0x00
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	clr	_RFERRIF
	mov	_RFST,#0xE6
	mov	_RFST,#0xE6
	mov	_RFST,#0xE7
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	pop	psw
	pop	ar2
	pop	acc
	reti
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_16'
;------------------------------------------------------------
;RFIF_RFIM                 Allocated with name '___vector_16_RFIF_RFIM_1_1'
;_cil_inline_tmp_2316      Allocated with name '___vector_16__cil_inline_tmp_2316_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_16
;	-----------------------------------------
___vector_16:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
	mov	c,_EA
	clr	a
	rlc	a
	mov	r2,a
	clr	_EA
	mov	r3,_RFIF
	mov	r4,#0x00
	mov	r5,_RFIM
	mov	r6,#0x00
	mov	a,r5
	anl	ar3,a
	mov	a,r6
	anl	ar4,a
	mov	_RFIF,#0x00
	mov	a,r3
	jnb	acc.5,00102$
	mov	dpl,#0x0B
	push	ar2
	push	ar3
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar3
	pop	ar2
00102$:
	mov	a,r3
	jnb	acc.6,00109$
	mov	dpl,#0x08
	push	ar2
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar2
	mov	dptr,#_HAL_CC2430ControlM__WaitACK_Flag
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0x01,00106$
	mov	dpl,#0x09
	push	ar2
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar2
	sjmp	00109$
00106$:
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	movx	a,@dptr
	mov	r3,a
	jz	00109$
	mov	dptr,#_HAL_CC2430ControlM__transmitInProgress
	clr	a
	movx	@dptr,a
	mov	dpl,#0x05
	push	ar2
	lcall	_SchedulerBasicP__TaskBasic__postTask
	pop	ar2
00109$:
	mov	_S1CON,#0x00
	mov	a,r2
	add	a,#0xff
	mov	_EA,c
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_2'
;------------------------------------------------------------
;_cil_inline_tmp_2326      Allocated with name '___vector_2__cil_inline_tmp_2326_1_1'
;_cil_inline_tmp_2330      Allocated with name '___vector_2__cil_inline_tmp_2330_1_1'
;_cil_inline_tmp_2332      Allocated with name '___vector_2__cil_inline_tmp_2332_1_1'
;_cil_inline_tmp_2333      Allocated with name '___vector_2__cil_inline_tmp_2333_1_1'
;_cil_inline_tmp_2334      Allocated with name '___vector_2__cil_inline_tmp_2334_1_1'
;_cil_inline_tmp_2335      Allocated with name '___vector_2__cil_inline_tmp_2335_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_2
;	-----------------------------------------
___vector_2:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
	clr	_URX0IF
	mov	dptr,#___vector_2__cil_inline_tmp_2326_1_1
	mov	a,_U0BUF
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__NowReceiving
	movx	a,@dptr
	mov	r2,a
	jnz	00126$
	mov	dptr,#___vector_2__cil_inline_tmp_2326_1_1
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x7E,00142$
	sjmp	00143$
00142$:
	ljmp	00128$
00143$:
	mov	dptr,#_SerialActiveMessageP__0__NowReceiving
	mov	a,#0x01
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	clr	a
	movx	@dptr,a
	ljmp	00128$
00126$:
	mov	dptr,#___vector_2__cil_inline_tmp_2326_1_1
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x7E,00144$
	sjmp	00145$
00144$:
	ljmp	00123$
00145$:
	mov	dptr,#_SerialActiveMessageP__0__NowReceiving
	clr	a
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	clr	c
	mov	a,#0x07
	subb	a,r3
	clr	a
	subb	a,r4
	jc	00146$
	ljmp	00128$
00146$:
	mov	dptr,#_SerialActiveMessageP__0__RecvBuff
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SerialActiveMessageP__0__RecvAckType
	movx	@dptr,a
	mov	dptr,#(_SerialActiveMessageP__0__RecvBuff + 0x0007)
	mov	b,#0x00
	lcall	__gptrget
	mov  r3,a
	add	a,#0xff - 0x1C
	jnc	00147$
	ljmp	00128$
00147$:
	mov	dptr,#(_SerialActiveMessageP__0__RecvBuff + 0x0007)
	mov	b,#0x00
	lcall	__gptrget
	mov	dptr,#_SerialActiveMessageP__0__UartRecvMessag
	movx	@dptr,a
	mov	dptr,#(_SerialActiveMessageP__0__UartRecvMessag + 0x0004)
	mov	b,#0x00
	mov	a,#0x22
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	mov	dptr,#(_SerialActiveMessageP__0__RecvBuff + 0x0003)
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#(_SerialActiveMessageP__0__UartRecvMessag + 0x0006)
	mov	b,#0x00
	mov	a,r3
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	mov	dptr,#_TOS_NODE_ID
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#(_SerialActiveMessageP__0__UartRecvMessag + 0x0008)
	mov	b,#0x00
	mov	a,r3
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	mov	dptr,#(_SerialActiveMessageP__0__RecvBuff + 0x0009)
	mov	b,#0x00
	lcall	__gptrget
	mov	r3,a
	mov	dptr,#(_SerialActiveMessageP__0__UartRecvMessag + 0x000a)
	mov	b,#0x00
	mov	a,r3
	lcall	__gptrput
	mov	dptr,#(_SerialActiveMessageP__0__RecvBuff + 0x0007)
	mov	b,#0x00
	lcall	__gptrget
	mov	r3,a
	mov	r4,#0x00
	mov	dptr,#_memcpy_PARM_2
	mov	a,#(_SerialActiveMessageP__0__RecvBuff + 0x000a)
	movx	@dptr,a
	inc	dptr
	mov	a,#((_SerialActiveMessageP__0__RecvBuff + 0x000a) >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_memcpy_PARM_3
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#(_SerialActiveMessageP__0__UartRecvMessag + 0x000b)
	mov	b,#0x00
	lcall	_memcpy
	mov	dpl,#0x0F
	lcall	_SchedulerBasicP__TaskBasic__postTask
	ljmp	00128$
00123$:
	cjne	r2,#0x7D,00120$
	mov	dptr,#_SerialActiveMessageP__0__Escape_Flag
	mov	a,#0x01
	movx	@dptr,a
	ljmp	00128$
00120$:
	mov	dptr,#_SerialActiveMessageP__0__Escape_Flag
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0x01,00150$
	sjmp	00151$
00150$:
	ljmp	00117$
00151$:
	mov	dptr,#_SerialActiveMessageP__0__Escape_Flag
	clr	a
	movx	@dptr,a
	cjne	r2,#0x5D,00111$
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#___vector_2__cil_inline_tmp_2332_1_1
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#___vector_2__cil_inline_tmp_2332_1_1
	movx	a,@dptr
	mov	r3,a
	add	a,#_SerialActiveMessageP__0__RecvBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__RecvBuff >> 8)
	mov	dph,a
	mov	a,#0x7D
	movx	@dptr,a
	ljmp	00128$
00111$:
	cjne	r2,#0x5E,00108$
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#___vector_2__cil_inline_tmp_2333_1_1
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#___vector_2__cil_inline_tmp_2333_1_1
	movx	a,@dptr
	mov	r3,a
	add	a,#_SerialActiveMessageP__0__RecvBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__RecvBuff >> 8)
	mov	dph,a
	mov	a,#0x7E
	movx	@dptr,a
	sjmp	00128$
00108$:
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#___vector_2__cil_inline_tmp_2334_1_1
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#___vector_2__cil_inline_tmp_2334_1_1
	movx	a,@dptr
	mov	r3,a
	add	a,#_SerialActiveMessageP__0__RecvBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__RecvBuff >> 8)
	mov	dph,a
	mov	a,#0x7D
	movx	@dptr,a
	sjmp	00128$
00117$:
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	movx	a,@dptr
	mov	r3,a
	cjne	r3,#0x7F,00114$
	mov	dptr,#_SerialActiveMessageP__0__NowReceiving
	clr	a
	movx	@dptr,a
	sjmp	00128$
00114$:
	mov	dptr,#___vector_2__cil_inline_tmp_2335_1_1
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__Rindex
	mov	a,r3
	inc	a
	movx	@dptr,a
	mov	dptr,#___vector_2__cil_inline_tmp_2335_1_1
	movx	a,@dptr
	mov	r3,a
	add	a,#_SerialActiveMessageP__0__RecvBuff
	mov	dpl,a
	clr	a
	addc	a,#(_SerialActiveMessageP__0__RecvBuff >> 8)
	mov	dph,a
	mov	a,r2
	movx	@dptr,a
00128$:
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_7'
;------------------------------------------------------------
;_cil_inline_tmp_2339      Allocated with name '___vector_7__cil_inline_tmp_2339_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_7
;	-----------------------------------------
___vector_7:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
	mov	r2,_U0CSR
	mov	r3,#0x00
	mov	a,r2
	jnb	acc.0,00119$
	ljmp	00111$
00119$:
	clr	_UTX0IF
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SCSuartDBGM__buff_start
	mov	a,#0x01
	add	a,r2
	movx	@dptr,a
	clr	a
	addc	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	clr	c
	mov	a,#0x7E
	subb	a,r2
	clr	a
	subb	a,r3
	jnc	00102$
	mov	dptr,#_SCSuartDBGM__buff_start
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00102$:
	mov	dptr,#_SCSuartDBGM__buff_end
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	clr	c
	mov	a,#0x7E
	subb	a,r2
	clr	a
	subb	a,r3
	jnc	00104$
	mov	dptr,#_SCSuartDBGM__buff_end
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00104$:
	mov	dptr,#_SCSuartDBGM__buff_start
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_SCSuartDBGM__buff_end
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	a,r2
	cjne	a,ar4,00122$
	mov	a,r3
	cjne	a,ar5,00122$
	sjmp	00108$
00122$:
	mov	a,r2
	add	a,#_SCSuartDBGM__str_buff
	mov	dpl,a
	mov	a,r3
	addc	a,#(_SCSuartDBGM__str_buff >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	_U0BUF,a
	sjmp	00111$
00108$:
	mov	dptr,#_SCSuartDBGM__state
	clr	a
	movx	@dptr,a
	mov	dptr,#_SerialActiveMessageP__0__SendProcessing
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,00111$
	mov	dpl,#0x0E
	lcall	_SchedulerBasicP__TaskBasic__postTask
00111$:
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_3'
;------------------------------------------------------------
;_cil_inline_tmp_2345      Allocated with name '___vector_3__cil_inline_tmp_2345_1_1'
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_3
;	-----------------------------------------
___vector_3:
	push	acc
	clr	_URX1IF
	mov	a,_U1DBUF
	pop	acc
	reti
;	eliminated unneeded push/pop psw
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_14'
;------------------------------------------------------------
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_14
;	-----------------------------------------
___vector_14:
	push	acc
	push	ar2
	push	ar3
	mov	r2,_U1CSR
	mov	r3,#0x00
	mov	a,r2
	jb	acc.0,00102$
	clr	_UTX1IF
00102$:
	pop	ar3
	pop	ar2
	pop	acc
	reti
;	eliminated unneeded push/pop psw
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function '__vector_11'
;------------------------------------------------------------
;------------------------------------------------------------
;	-----------------------------------------
;	 function __vector_11
;	-----------------------------------------
___vector_11:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
	mov	r2,_T3CCTL0
	mov	r3,#0x00
	mov	a,r2
	jnb	acc.2,00104$
	jbc	_T3CH0IF,00110$
	sjmp	00104$
00110$:
	clr	_T3IE
	mov	r2,_T3CTL
	anl	ar2,#0xEF
	mov	_T3CTL,r2
	mov	dpl,#0x0C
	lcall	_SchedulerBasicP__TaskBasic__postTask
00104$:
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
__xinit__TOS_NODE_ID:
	.byte #0x01,#0x00
__xinit__SCSuartDBGM__state:
	.db #0x00
__xinit__SCSuartDBGM__buff_start:
	.byte #0x00,#0x00
__xinit__SCSuartDBGM__buff_end:
	.byte #0x00,#0x00
__xinit__AMQueueImplP__0__current:
	.db #0xFF
	.area CABS    (ABS,CODE)
