/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2024 Huawei Technologies Co., Ltd */

#ifndef ROCE_CTX_API_H
#define ROCE_CTX_API_H

#include "roce_compile_macro.h"
#include "roce_wqe_format.h"
#include "roce_xqe_format.h"
#include "rdma_context_format.h"


enum ROCE_TIMER_ID_E {
	ROCE_TIMER_ID_ACK = 0,
	ROCE_TIMER_ID_DCQCN_RCNP,
	ROCE_TIMER_ID_WND_LESS_THAN_MTU,
	ROCE_TIMER_ID_MAX = 4,
	ROCE_TIMER_ID_QP_DEL = 7
};

enum roce_qpc_ulp_type {
	ROCE_ULP_STD = 0,
	ROCE_ULP_PLOG,
	ROCE_ULP_VBS,
	ROCE_ULP_OSD,
	ROCE_ULP_NOFAA
};

enum roce_req_rsp_side {
	ROCE_REQ_SIDE = 0,
	ROCE_RSP_SIDE
};

enum roce_rq_cqe_mask {
	ROCE_CQEMASK_WRITE = 0,
	ROCE_CQEMASK_SEND
};

enum ROCE_FLOWID_E {
	ROCE_FLOWID_0 = 0,
	ROCE_FLOWID_1,
	ROCE_FLOWID_2
};

enum ROCE_STGID_E {
	ROCE_STGID_0 = 0,
	ROCE_STGID_1,
	ROCE_STGID_2,
	ROCE_STGID_3,
	ROCE_STGID_4,
	ROCE_STGID_5,
	ROCE_STGID_6,
	ROCE_STGID_7
};

enum ROCE_EVENT_STG_E {
	ROCE_EVENT_STG_SQ = 0,
	ROCE_EVENT_STG_SQA,
	ROCE_EVENT_STG_RQ,
	ROCE_EVENT_STG_RQA,
	ROCE_EVENT_STG_SQA_2HOST,
	ROCE_EVENT_STG_DCC,
	ROCE_EVENT_STG_VERBS,
	ROCE_EVENT_STG_NO
};

#define ROCE_SQ_STGID ROCE_STGID_0
#define ROCE_RQ_STGID ROCE_STGID_1
#define ROCE_VERBS_STGID ROCE_STGID_2
#define ROCE_DCC_STGID ROCE_STGID_3
#define ROCE_RQ_ACK_STGID ROCE_STGID_4
#define ROCE_SQ_ACK_STGID ROCE_STGID_5
#define ROCE_SQA_2HOST_STGID ROCE_STGID_6
#define ROCE_REBIND_STGID QU_STG_ID_RSVD

/* *********TABLE SIZE******* */
#define WQEBB_SIZE_SHIFT 6 // 64b
#define ROCE_GET_WQBB_NUM_PERWQE(wqe_len_8b) (BYTE8_TO_BYTES(wqe_len_8b) >> WQEBB_SIZE_SHIFT)

#define ROCE_GID_TABLE_SIZE (32)
#define ROCE_MPT_TABLE_SIZE (64)
#define ROCE_MTT_TABLE_SIZE (8)
#define ROCE_CQC_TABLE_SIZE (128)
#define ROCE_SRQC_TABLE_SIZE (64)
#define ROCE_RDMARC_TABLE_SIZE (32)
#define ROCE_QPC_TABLE_SIZE (512)
#define ROCE_WQE_MAX_SIZE (256)
#define ROCE_CM_MAD_MEG_LEN (64)

#define ROCE_MTT_QUERY_SIZE (16)
#define ROCE_PCNT_QUERY_SIZE (16)

#define ROCE_CQE_LEN (64)
#define ROCE_CQE_LEN_SHIFT (6)
#define ROCE_RESIZE_CQE_LEN (64)

#define ROCE_QPC_RRWC_SEG_SIZE (32)
#define ROCE_QPC_RCC_SEG_SIZE (32)
#define ROCE_QPC_SQPC_SEG_SIZE (64)
#define ROCE_QPC_SQC_SEG_SIZE (64)
#define ROCE_QPC_SQAC_SEG_SIZE (64)
#define ROCE_QPC_RQC_SEG_SIZE (64)
#define ROCE_QPC_QPCC_SEG_SIZE (32)
#define ROCE_QPC_HW_SEG_SIZE (ROCE_QPC_RRWC_SEG_SIZE + ROCE_QPC_RCC_SEG_SIZE + \
	ROCE_QPC_SQC_SEG_SIZE + ROCE_QPC_SQAC_SEG_SIZE + ROCE_QPC_RQC_SEG_SIZE + \
	ROCE_QPC_QPCC_SEG_SIZE)
#define ROCE_QPC_TIMER_SEG_SIZE (32)
#define ROCE_QPC_SW_SEG_SIZE (192)
#define ROCE_QPC_SW_DCQCN_SIZE (16)
#define ROCE_QPC_SW_NOFAA_SIZE ROCE_QPC_QPCC_SEG_SIZE
#define ROCE_QPC_SW_SQC_SIZE (20)
#define ROCE_QPC_SW_SQAC_SIZE (36)
#define ROCE_QPC_SW_RQC_SIZE (20)
#define ROCE_QPC_SW_RQAC_SIZE (20)
#define ROCE_QPC_SW_STGID_SIZE (68)

#define ROCE_QPC_EXT_SW_SEG_SIZE (32)

#define ROCE_QPC_RRWC_DW_SIZE (8)
#define ROCE_QPC_RCC_DW_SIZE (8)
#define ROCE_QPC_SQPC_DW_SIZE (16)
#define ROCE_QPC_SQC_DW_SIZE (16)
#define ROCE_QPC_SQAC_DW_SIZE (16)
#define ROCE_QPC_RQC_DW_SIZE (16)
#define ROCE_QPC_QPCC_DW_SIZE (8)
#define ROCE_QPC_TIMER_DW_SIZE (8)
#define ROCE_QPC_SW_DW_SIZE (48)
#define ROCE_QPC_SW_DCQCN_DW_SIZE (8)
#define ROCE_QPC_SW_NOFAA_DW_SIZE ROCE_QPC_QPCC_DW_SIZE

#define ROCE_QPC_SW_SEG_DWORD_LEN (ROCE_QPC_SW_SEG_SIZE >> 2)
#define ROCE_QPC_HW_SEG_DWORD_LEN (ROCE_QPC_HW_SEG_SIZE >> 2)
#define ROCE_QPC_SW_DCQCN_DWORD_LEN (ROCE_QPC_SW_DCQCN_SIZE >> 2)
#define ROCE_QPC_SW_NOFAA_DWORD_LEN (ROCE_QPC_SW_NOFAA_SIZE >> 2)
#define ROCE_QPC_SW_STGID_DWORD_LEN (ROCE_QPC_SW_STGID_SIZE >> 2)
#define ROCE_QPC_DWORD_LEN (ROCE_QPC_TABLE_SIZE >> 2)
#define ROCE_MPT_DWORD_LEN (ROCE_MPT_TABLE_SIZE >> 2)
#define ROCE_CQC_DWORD_LEN (ROCE_CQC_TABLE_SIZE >> 2)
#define ROCE_SRQC_DWORD_LEN (ROCE_SRQC_TABLE_SIZE >> 2)
#define ROCE_GID_DWORD_LEN (ROCE_GID_TABLE_SIZE >> 2)
#define ROCE_CM_MAD_DWORD_LEN (ROCE_CM_MAD_MEG_LEN >> 2)

#define ROCE_RDMARC_MAX_DATA_DW_LEN (ROCE_RDMARC_TABLE_SIZE >> 2)

#define ROCE_SQ_WQE_SEND_TASK_SEG_LEN (16)
#define ROCE_SQ_WQE_UD_SEND_TASK_SEG_LEN (64)
#define ROCE_SQ_WQE_RDMA_TASK_SEG_LEN (32)
#define ROCE_SQ_WQE_ATOMIC_TASK_SEG_LEN (32)
#define ROCE_SQ_WQE_MASK_ATOMIC_CMPSWP_TASK_SEG_LEN (48)
#define ROCE_SQ_WQE_SEND_WRITE_COM_TASK_SEG_LEN (16)

/* ******************************************************** */
enum ROCE_QP_CTX_OFF_E {
	ROCE_CTX_RRWC_OFF = 0,
	ROCE_CTX_RCC_OFF = 32,
	ROCE_CTX_SQC_OFF = 64,
	ROCE_CTX_SQAC_OFF = 128,
	ROCE_CTX_RQC_OFF = 192,
	ROCE_CTX_QPCC_OFF = 256,
	ROCE_CTX_TIMER_OFF = 288,
	ROCE_CTX_SW_OFF = 320,
	ROCE_CTX_SW_SQC_OFF = 400,
	ROCE_CTX_SW_SQAC_OFF = 416,
	ROCE_CTX_SW_RQC_OFF = 448,
	ROCE_CTX_SW_RQAC_OFF = 464
};
#define ROCE_CTX_SQPC_OFF ROCE_CTX_RRWC_OFF

#define ROCE_MISC_RRWC_OFFSET_16B_ALIGN (ROCE_CTX_RRWC_OFF >> 4)
#define ROCE_MISC_RCC_OFFSET_16B_ALIGN (ROCE_CTX_RCC_OFF >> 4)
#define ROCE_MISC_SQC_OFFSET_16B_ALIGN (ROCE_CTX_SQC_OFF >> 4)
#define ROCE_MISC_SQAC_OFFSET_16B_ALIGN (ROCE_CTX_SQAC_OFF >> 4)
#define ROCE_MISC_RQC_OFFSET_16B_ALIGN (ROCE_CTX_RQC_OFF >> 4)
#define ROCE_MISC_QPCC_OFFSET_16B_ALIGN (ROCE_CTX_QPCC_OFF >> 4)
#define ROCE_MISC_TIMERC_OFFSET_16B_ALIGN (ROCE_CTX_TIMER_OFF >> 4)
#define ROCE_MISC_SW_OFFSET_16B_ALIGN (ROCE_CTX_SW_OFF >> 4)
#define ROCE_MISC_SW_OFFSET64_16B_ALIGN ((ROCE_CTX_SW_OFF + 64) >> 4)
#define ROCE_MISC_SW_OFFSET128_16B_ALIGN ((ROCE_CTX_SW_OFF + 128) >> 4)
#define ROCE_MISC_SQPC_OFFSET_16B_ALIGN (ROCE_CTX_SQPC_OFF >> 4)

#ifdef NOF_ROCE_AA_MODE_EN
#define ROCE_WB_CTX_SIZE	QU_WB_CTX_SIZE_224
#else
#define ROCE_WB_CTX_SIZE	QU_WB_CTX_SIZE_192
#endif

#define ROCE_RDMARC_ATOMIC_DATA_LEN (8)

#define ROCE_RDMARC_ATOMIC_DATA_DW_LEN (16 >> 2)
#define ROCE_RDMARC_ATOMIC_STATUS_DW_LEN (4 >> 2)
#define ROCE_RDMARC_ATOMIC_DATA_DW_OFF (16 >> 2)
#define ROCE_RDMARC_ATOMIC_STATUS_DW_OFF (28 >> 2)
/* ************************************************* */
#define ROCE_QPCC_RXE_DW_OFF (4)
#define ROCE_QPCC_RXE_DW_BITMASK (0X01C00000)
#define ROCE_RCC_RXE_DW_OFF (7)
#define ROCE_RRWC_RXE_DW_OFF (7)
#define ROCE_RCC_RAE_DW_BITMASK (~0X08000000)
#define ROCE_RCC_RRE_DW_BITMASK (~0X04000000)
#define ROCE_RRWC_RWE_DW_BITMASK (~0X08000000)

#define ROCE_QP_QPCC_GPAH_DW_OFF (6)
#define ROCE_QP_QPCC_GPAH_DW_BITMASK (~0X00FFFFFF)
#define ROCE_QP_QPCC_GPAL_DW_BITMASK (~0XFFFFFFFF)

#define ROCE_QP_RCC_RCPI_DW_OFF (5)
#define ROCE_QP_RCC_RCPI_DW_BITMASK (~0X000000FF)
#define ROCE_QP_RCC_RCCI_DW_BITMASK (~0X000000FF)

#define ROCE_QP_COM_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_RCC_STATE_DW_OFF (7)
#define ROCE_QP_RCC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_SQC_STATE_DW_OFF (2)
#define ROCE_QP_SQC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_SQAC_STATE_DW_OFF (2)
#define ROCE_QP_SQAC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_SQAC_WQEIDX_DW_OFF (2)
#define ROCE_QP_SQAC_WQEIDX_DW_BITMASK (~0X0000ffff)

#define ROCE_QP_RQC_STATE_DW_OFF (2)
#define ROCE_QP_RQC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_RRWC_STATE_DW_OFF (7)
#define ROCE_QP_RRWC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_QP_RQC_SGEVLD_DW_OFF (0)
#define ROCE_QP_RQC_SGEVLD_DW_BITMASK (~0X80000000)

#define ROCE_MPT_STATE_DW_OFF (2)
#define ROCE_MPT_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_MPT_MWCNT_DW_OFF (10)
#define ROCE_MPT_MWCNT_DW_BITMASK (~0Xffffffff)

#define ROCE_SRQC_STATE_DW_OFF (2)
#define ROCE_SRQC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_CQC_STATE_DW_OFF (2)
#define ROCE_CQC_STATE_DW_BITMASK (~0Xf0000000)

#define ROCE_CQC_TIMEOUT_DW7_OFF (7)
#define ROCE_CQC_TIMEOUT_DW7_BITMASK (~0Xffffffff)

#define ROCE_CQC_TMR_TWID_DW10_OFF (10)
#define ROCE_CQC_TMR_TWID_DW_BITMASK (~0Xffff0000)

#define ROCE_SRQC_ERR_STATE (0x10000000)
#define ROCE_QPC_RQ_COMM_EST_OFF (27) /* *keep the same with qpc rq DW22 */

#define ROCE_RRWC_SGE_VLD (0x80000000)

#define ROCE_VLAN 1

#endif /* ROCE_CTX_API_H */
