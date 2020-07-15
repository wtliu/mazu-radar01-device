/**
 *   @file  mmw_res.h
 *
 *   @brief
 *      Defines partitioning of hardware resources (HWA, EDMA etc) among the
 *      DPCs and other components in the millimeter wave demo.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2019 Texas Instruments, Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef MMW_DEMO_RES_H
#define MMW_DEMO_RES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/edma/edma.h>
#include <ti/common/sys_common.h>

#define EDMA_INSTANCE_0 0
#define EDMA_INSTANCE_1 1

/*******************************************************************************
 * Resources for Object Detection DPC, currently the only DPC and hwa/edma
 * resource user in the demo.
 *******************************************************************************/
/* EDMA instance used for objdet that is managed by R4F - this is for HWA 1D. This
 * instance is shared with LVDS */
#define DPC_OBJDET_R4F_EDMA_INSTANCE                                  EDMA_INSTANCE_0

/* Shadow base for above instance */
#define DPC_OBJDET_R4F_EDMA_SHADOW_BASE                               EDMA_NUM_DMA_CHANNELS

/* EDMA instance used for objdet that is managed by DSP */
#define DPC_OBJDET_DSP_EDMA_INSTANCE                                  EDMA_INSTANCE_1

/* Shadow base for above instance */
#define DPC_OBJDET_DSP_EDMA_SHADOW_BASE                               EDMA_NUM_DMA_CHANNELS

#define DPC_OBJDET_HWA_WINDOW_RAM_OFFSET                              0
#define DPC_OBJDET_PARAMSET_START_IDX                                 0

/* Range DPU */
#define DPC_OBJDET_DPU_RANGEPROC_PARAMSET_START_IDX                   DPC_OBJDET_PARAMSET_START_IDX

#define DPC_OBJDET_DPU_RANGEPROC_EDMA_INST_ID                         DPC_OBJDET_R4F_EDMA_INSTANCE
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_CH                            EDMA_TPCC0_REQ_DFE_CHIRP_AVAIL
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_SHADOW                        (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 0)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_EVENT_QUE                     0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_SIG_CH                        EDMA_TPCC0_REQ_FREE_0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_SIG_SHADOW                    (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 1)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAIN_SIG_EVENT_QUE                 0

/* FMT2 EDMA resources */
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PING_CH                 EDMA_TPCC0_REQ_HWACC_0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PING_SHADOW_0           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 2)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PING_SHADOW_1           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 3)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PING_SHADOW_2           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 4)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PING_EVENT_QUE          0

#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_0_CH           EDMA_TPCC0_REQ_FREE_1
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_0_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 5)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_0_EVENT_QUE    0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_1_CH           EDMA_TPCC0_REQ_FREE_2
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_1_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 6)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_1_EVENT_QUE    0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_2_CH           EDMA_TPCC0_REQ_FREE_3
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_2_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 7)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PINGDATA_2_EVENT_QUE    0

#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONG_CH                 EDMA_TPCC0_REQ_HWACC_1
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONG_SHADOW_0           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 8)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONG_SHADOW_1           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 9)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONG_SHADOW_2           (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 10)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONG_EVENT_QUE          0

#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_0_CH           EDMA_TPCC0_REQ_FREE_4
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_0_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 11)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_0_EVENT_QUE    0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_1_CH           EDMA_TPCC0_REQ_FREE_5
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_1_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 12)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_1_EVENT_QUE    0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_2_CH           EDMA_TPCC0_REQ_FREE_6
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_2_SHADOW       (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 13)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT2_PONGDATA_2_EVENT_QUE    0

/* FMT1 EDMA resources */
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PING_CH                 EDMA_TPCC0_REQ_HWACC_0
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PING_SHADOW             (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 2)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PING_EVENT_QUE          0

#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PONG_CH                 EDMA_TPCC0_REQ_HWACC_1
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PONG_SHADOW             (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 3)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_FMT1_PONG_EVENT_QUE          0

#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_SIG_CH                       EDMA_TPCC0_REQ_FREE_7
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_SIG_SHADOW                   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 14)
#define DPC_OBJDET_DPU_RANGEPROC_EDMAOUT_SIG_EVENT_QUE                0

/* Doppler DPU */
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_INST_ID                       DPC_OBJDET_DSP_EDMA_INSTANCE
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PING_CH                     EDMA_TPCC1_REQ_FREE_0
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PING_SHADOW                 (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 0)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PING_EVENT_QUE              0

#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PONG_CH                     EDMA_TPCC1_REQ_FREE_2
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PONG_SHADOW                 (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 1)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAIN_PONG_EVENT_QUE              0

#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PING_CH                    EDMA_TPCC1_REQ_FREE_3
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PING_SHADOW                (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 2)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PING_EVENT_QUE             0

#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PONG_CH                    EDMA_TPCC1_REQ_FREE_4
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PONG_SHADOW                (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 3)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMAOUT_PONG_EVENT_QUE             0

#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PING_SIG_CH                   EDMA_TPCC1_REQ_FREE_5
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PING_SIG_SHADOW               (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 4)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PING_SIG_EVENT_QUE            0

#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PONG_SIG_CH                   EDMA_TPCC1_REQ_FREE_6
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PONG_SIG_SHADOW               (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 5)
#define DPC_OBJDET_DPU_DOPPLERPROC_EDMA_PONG_SIG_EVENT_QUE            0

/* Static Clutter DPU */
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMA_INST_ID               DPC_OBJDET_DSP_EDMA_INSTANCE
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PING_CH             EDMA_TPCC1_REQ_FREE_7
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PING_SHADOW         (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 6)
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PING_EVENT_QUE      0

#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PONG_CH             EDMA_TPCC1_REQ_FREE_8
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PONG_SHADOW         (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 7)
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAIN_PONG_EVENT_QUE      0

#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PING_CH            EDMA_TPCC1_REQ_FREE_9
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PING_SHADOW        (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 8)
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PING_EVENT_QUE     0

#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PONG_CH            EDMA_TPCC1_REQ_FREE_10
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PONG_SHADOW        (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 9)
#define DPC_OBJDET_DPU_STATIC_CLUTTER_PROC_EDMAOUT_PONG_EVENT_QUE     0

/* CFARCA DPU */
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_INST_ID                       DPC_OBJDET_DSP_EDMA_INSTANCE
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PING_CH                       EDMA_TPCC1_REQ_FREE_11
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PING_SHADOW                   (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 10)
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PING_EVENT_QUE                0

#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PONG_CH                       EDMA_TPCC1_REQ_FREE_12
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PONG_SHADOW                   (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 11)
#define DPC_OBJDET_DPU_CFARCA_PROC_EDMA_PONG_EVENT_QUE                0

/* AOA DPU */
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_INST_ID                          DPC_OBJDET_DSP_EDMA_INSTANCE
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PING_CH                         EDMA_TPCC1_REQ_FREE_13
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PING_SHADOW                     (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 12)
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PING_EVENT_QUE                  0

#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PONG_CH                         EDMA_TPCC1_REQ_FREE_14
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PONG_SHADOW                     (DPC_OBJDET_DSP_EDMA_SHADOW_BASE + 13)
#define DPC_OBJDET_DPU_AOA_PROC_EDMA_PONG_EVENT_QUE                  0


/*************************LVDS streaming EDMA resources*******************************/
/*EDMA instance used*/
#define MMW_LVDS_STREAM_EDMA_INSTANCE            DPC_OBJDET_R4F_EDMA_INSTANCE

/* CBUFF EDMA trigger channels */
#define MMW_LVDS_STREAM_CBUFF_EDMA_CH_0          EDMA_TPCC0_REQ_CBUFF_0
#define MMW_LVDS_STREAM_CBUFF_EDMA_CH_1          EDMA_TPCC0_REQ_CBUFF_1

/* HW Session*/
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_0     EDMA_TPCC0_REQ_FREE_8
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_1     EDMA_TPCC0_REQ_FREE_9
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_2     EDMA_TPCC0_REQ_FREE_10
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_3     EDMA_TPCC0_REQ_FREE_11
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_4     EDMA_TPCC0_REQ_FREE_12
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_5     EDMA_TPCC0_REQ_FREE_13
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_6     EDMA_TPCC0_REQ_FREE_14
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_7     EDMA_TPCC0_REQ_FREE_15
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_8     EDMA_TPCC0_REQ_FREE_16
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_9     EDMA_TPCC0_REQ_FREE_17
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_CH_10    EDMA_TPCC0_REQ_HWACC_2

/* SW Session*/
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_CH_0     EDMA_TPCC0_REQ_HWACC_3
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_CH_1     EDMA_TPCC0_REQ_HWACC_4
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_CH_2     EDMA_TPCC0_REQ_HWACC_5

/*shadow*/
/*shadow CBUFF trigger channels*/
#define MMW_LVDS_STREAM_CBUFF_EDMA_SHADOW_CH_0   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 15U)
#define MMW_LVDS_STREAM_CBUFF_EDMA_SHADOW_CH_1   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 16U)

/* HW Session*/
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_0   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 17U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_1   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 18U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_2   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 19U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_3   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 20U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_4   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 21U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_5   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 22U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_6   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 23U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_7   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 24U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_8   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 29U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_9   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 30U)
#define MMW_LVDS_STREAM_HW_SESSION_EDMA_SHADOW_CH_10  (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 31U)

/* SW Session*/
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_SHADOW_CH_0   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 32U)
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_SHADOW_CH_1   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 33U)
#define MMW_LVDS_STREAM_SW_SESSION_EDMA_SHADOW_CH_2   (DPC_OBJDET_R4F_EDMA_SHADOW_BASE + 34U)

/*************************LVDS streaming EDMA resources END*******************************/

#ifdef __cplusplus
}
#endif

#endif /* MMW_DEMO_RES_H */

