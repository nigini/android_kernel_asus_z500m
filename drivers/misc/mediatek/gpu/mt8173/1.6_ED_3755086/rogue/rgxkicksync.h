/*************************************************************************/ /*!
@File           rgxkicksync.h
@Title          Server side of the sync only kick API
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/

#if ! defined (__RGXKICKSYNC_H__)
#define __RGXKICKSYNC_H__

#include "pvrsrv_error.h"
#include "connection_server.h"
#include "sync_server.h"


typedef struct _RGX_SERVER_KICKSYNC_CONTEXT_ RGX_SERVER_KICKSYNC_CONTEXT;

/**************************************************************************/ /*!
@Function       PVRSRVRGXCreateKickSyncContextKM
@Description    Server-side implementation of RGXCreateKicksyncContext
@Return         PVRSRV_OK on success. Otherwise, a PVRSRV_ error code
 */ /**************************************************************************/
IMG_EXPORT
PVRSRV_ERROR PVRSRVRGXCreateKickSyncContextKM(CONNECTION_DATA             * psConnection,
                                              PVRSRV_DEVICE_NODE          * psDeviceNode,
                                              IMG_HANDLE					hMemCtxPrivData,
                                              RGX_SERVER_KICKSYNC_CONTEXT ** ppsKicksyncContext);



/**************************************************************************/ /*!
@Function       PVRSRVRGXDestroyKickSyncContextKM
@Description    Server-side implementation of RGXDestroyKicksyncContext
@Return         PVRSRV_OK on success. Otherwise, a PVRSRV_ error code
 */ /**************************************************************************/
IMG_EXPORT
PVRSRV_ERROR PVRSRVRGXDestroyKickSyncContextKM(RGX_SERVER_KICKSYNC_CONTEXT * psKicksyncContext);


/**************************************************************************/ /*!
@Function       PVRSRVRGXKickSyncKM
@Description    Kicks a sync only command
@Return         PVRSRV_OK on success. Otherwise, a PVRSRV_ error code
 */ /**************************************************************************/
IMG_EXPORT
PVRSRV_ERROR PVRSRVRGXKickSyncKM(RGX_SERVER_KICKSYNC_CONTEXT * psKicksyncContext,
                                 
                                 IMG_UINT32                    ui32ClientFenceCount,
                                 SYNC_PRIMITIVE_BLOCK           ** pauiClientFenceUFOSyncPrimBlock,
                                 IMG_UINT32                  * paui32ClientFenceSyncOffset,
                                 IMG_UINT32                  * paui32ClientFenceValue,
                                 
                                 IMG_UINT32                    ui32ClientUpdateCount,
                                 SYNC_PRIMITIVE_BLOCK           ** pauiClientUpdateUFOSyncPrimBlock,
                                 IMG_UINT32                  * paui32ClientUpdateSyncOffset,
                                 IMG_UINT32                  * paui32ClientUpdateValue,
                                 
                                 IMG_UINT32                    ui32ServerSyncPrims,
                                 IMG_UINT32                  * paui32ServerSyncFlags,
                                 SERVER_SYNC_PRIMITIVE      ** pasServerSyncs,
                                 
                                 IMG_INT32                     i32CheckFenceFD,
                                 IMG_INT32                     i32UpdateTimelineFD,
                                 IMG_INT32                   * pi32UpdateFenceFD,
                                 IMG_CHAR                      szFenceName[32],

                                 IMG_UINT32                    ui32ExternalJobReference,
                                 IMG_UINT32                    ui32InternalJobReference);

#endif /* __RGXKICKSYNC_H__ */

/**************************************************************************//**
 End of file (rgxkicksync.h)
******************************************************************************/
