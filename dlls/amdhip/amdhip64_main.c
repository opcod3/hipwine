/*
 * Copyright (C) 2024-2026 Luigi Sciolla
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <dlfcn.h>
#include <stdarg.h>
#include <assert.h>
#include "windef.h"
#include "winbase.h"
#include "wine/debug.h"

#include "hip/hip_runtime_api.h"
#include "hip/hip_deprecated.h"

#include <pthread.h>
// static pthread_mutex_t stream_callback_mutex   = PTHREAD_MUTEX_INITIALIZER;

// #define HIPERR_ASSERT(x) assert(x)
#define HIPERR_ASSERT(x)

WINE_DEFAULT_DEBUG_CHANNEL(amdhip64);

#define TRACE_RET()                                                            \
  do {                                                                         \
    if (TRACE_ON(amdhip64)) {                                                  \
      TRACE(" : %s\n", hipGetErrorName(err));                                  \
    }                                                                          \
  } while (0)

void **__hipRegisterFatBinary(const void *data);
void ** WINAPI wine___hipRegisterFatBinary(const void *binary) {
  TRACE("(%p)", binary);
  void **ret = __hipRegisterFatBinary(binary);
  TRACE(" -> %p\n", ret);
  return ret;
}

void __hipRegisterFunction(void **modules, const void *hostFunction,
                           char *deviceFunction, const char *deviceName,
                           unsigned int threadLimit, uint3 *tid, uint3 *bid,
                           dim3 *blockDim, dim3 *gridDim, int *wSize);

void WINAPI wine___hipRegisterFunction(void **modules, const void *hostFunction,
                                       char *deviceFunction,
                                       const char *deviceName,
                                       unsigned int threadLimit, uint3 *tid,
                                       uint3 *bid, dim3 *blockDim,
                                       dim3 *gridDim, int *wSize) {
  __hipRegisterFunction(modules, hostFunction, deviceFunction, deviceName,
                        threadLimit, tid, bid, blockDim, gridDim, wSize);
  // TRACE("(%p, %p, %s, %s, %d)\n", modules, hostFunction, deviceFunction,
  // deviceName, threadLimit); TRACE("(%p, %s)\n", modules, deviceName);
  TRACE("\n");
}

void __hipUnregisterFatBinary(void **modules);
void WINAPI wine___hipUnregisterFatBinary(void **modules) {
  TRACE("(%p)\n", modules);
  __hipUnregisterFatBinary(modules);
}

hipError_t WINAPI wine_hipGetDevice(int *deviceId) {
  return hipGetDevice(deviceId);
}

hipError_t WINAPI wine_hipGetDeviceCount(int *count) {
  hipError_t err = hipGetDeviceCount(count);
  TRACE("(%p, %d)", count, *count);

  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGet(hipDevice_t *device, int ordinal) {
  TRACE("(%p, %d)", device, ordinal);
  hipError_t err = hipDeviceGet(device, ordinal);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipGetDeviceProperties(void *prop, int deviceId) {
  TRACE("Should not be called!");
  HIPERR_ASSERT(false);
  //    TRACE("(%p, %d)", prop, deviceId);
  hipError_t err = hipGetDevicePropertiesR0000(prop, deviceId);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipGetDevicePropertiesR0600(hipDeviceProp_tR0600 *prop,
                                                   int deviceId) {
  TRACE("()");
  hipError_t err = hipGetDevicePropertiesR0600(prop, deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipInit(unsigned int flags) {
  TRACE("(%d)", flags);
  hipError_t err = hipInit(flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDriverGetVersion(int *driverVersion) {
  hipError_t err = hipDriverGetVersion(driverVersion);
  TRACE("(%p): %d", driverVersion, *driverVersion);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceTotalMem(size_t *bytes, hipDevice_t device) {
  hipError_t err = hipDeviceTotalMem(bytes, device);
  TRACE("(%lld, %d)", *bytes, device);
  // printf("\n hipDeviceTotalMem: %lld", *bytes);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGetName(char *name, int len,
                                        hipDevice_t device) {
  TRACE("(%p, %d, %d)", name, len, device);
  hipError_t err = hipDeviceGetName(name, len, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGetUuid(hipUUID *uuid, hipDevice_t device) {
  TRACE("()");
  hipError_t err = hipDeviceGetUuid(uuid, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipCtxCreate(hipCtx_t *ctx, unsigned int flags,
                                    hipDevice_t device) {
  TRACE("()");
  hipError_t err = hipCtxCreate(ctx, flags, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipRuntimeGetVersion(int *runtimeVersion) {
  TRACE("()");
  hipError_t err = hipRuntimeGetVersion(runtimeVersion);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipSetDevice(int deviceId) {
  TRACE("(%d)", deviceId);
  hipError_t err = hipSetDevice(deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipDeviceGetAttribute(int *pi, hipDeviceAttribute_t attr,
                                             int deviceId) {
  TRACE("()\n");
  hipError_t err = hipDeviceGetAttribute(pi, attr, deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipCtxPushCurrent(hipCtx_t ctx) {
  TRACE("()");
  hipError_t err = hipCtxPushCurrent(ctx);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipEventCreateWithFlags(hipEvent_t *event,
                                               unsigned int flags) {
  TRACE("()\n");
  hipError_t err = hipEventCreateWithFlags(event, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMalloc(void **ptr, size_t size) {
  TRACE("(%p, %ld)", ptr, size);
  hipError_t err = hipMalloc(ptr, size);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipHostMalloc(void **ptr, size_t size,
                                     unsigned int flags) {
  TRACE("(%p, %ld, %d)", ptr, size, flags);
  hipError_t err = hipHostMalloc(ptr, size, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipEventRecord(hipEvent_t event, hipStream_t stream) {
  hipError_t err = hipEventRecord(event, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipEventSynchronize(hipEvent_t event) {
  hipError_t err = hipEventSynchronize(event);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamCreate(hipStream_t *stream) {
  TRACE("(%p)", stream);
  hipError_t err = hipStreamCreate(stream);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipStreamCreateWithFlags(hipStream_t *stream,
                                                unsigned int flags) {
  hipError_t err = hipStreamCreateWithFlags(stream, flags);
  HIPERR_ASSERT(err == 0);
  return err;
}
hipError_t WINAPI wine_hipMemcpyAsync(void *dst, const void *src,
                                      size_t sizeBytes, hipMemcpyKind kind,
                                      hipStream_t stream) {
  hipError_t err = hipMemcpyAsync(dst, src, sizeBytes, kind, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpy(void *dst, const void *src, size_t sizeBytes,
                                 hipMemcpyKind kind) {
  TRACE("(%p, %p, %lld, %d)", dst, src, sizeBytes, kind);
  hipError_t err = hipMemcpy(dst, src, sizeBytes, kind);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFree(void *ptr) {
  TRACE("(%p)", ptr);
  hipError_t err = hipFree(ptr);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipStreamDestroy(hipStream_t stream) {
  hipError_t err = hipStreamDestroy(stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamQuery(hipStream_t stream) {
  hipError_t err = hipStreamQuery(stream);
  return err;
}

hipError_t WINAPI wine_hipEventDestroy(hipEvent_t event) {
  hipError_t err = hipEventDestroy(event);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipCtxPopCurrent(hipCtx_t *ctx) {
  TRACE("(%p)", ctx);
  hipError_t err = hipCtxPopCurrent(ctx);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMemGetInfo(size_t *free, size_t *total) {
  hipError_t err = hipMemGetInfo(free, total);

  // Disable free memory fixup
  int64_t free_fix = *free - (1024l * 1024l * 1024l * 2l);

  if (free_fix > 0) {
    *free = free_fix;
  } else {
    *free = 0;
  }

  HIPERR_ASSERT(err == 0);
  TRACE("\nmemGetInfo: free (%.3fmb), total (%.3fmb)",
        (float)(*free) / (1024.f * 1024.f),
        (float)(*total) / (1024.f * 1024.f));
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipHostGetDevicePointer(void **devPtr, void *hstPtr,
                                               unsigned int flags) {
  TRACE("()");
  hipError_t err = hipHostGetDevicePointer(devPtr, hstPtr, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleLoadData(hipModule_t *module,
                                         const void *image) {
  TRACE("()");
  hipError_t err = hipModuleLoadData(module, image);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleGetFunction(hipFunction_t *function,
                                            hipModule_t module,
                                            const char *kname) {
  TRACE("()");
  hipError_t err = hipModuleGetFunction(function, module, kname);
  // HIPERR_ASSERT(err == 0);n
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFuncGetAttribute(int *value,
                                           hipFunction_attribute attrib,
                                           hipFunction_t hfunc) {
  TRACE("()");
  hipError_t err = hipFuncGetAttribute(value, attrib, hfunc);
  // HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceReset(void) {
  TRACE("()");
  hipError_t err = hipDeviceReset();
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceSetCacheConfig(hipFuncCache_t cacheConfig) {
  TRACE("()");
  hipError_t err = hipDeviceSetCacheConfig(cacheConfig);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceSetLimit(enum hipLimit_t limit, size_t value) {
  TRACE("()");
  hipError_t err = hipDeviceSetLimit(limit, value);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFuncSetCacheConfig(const void *func,
                                             hipFuncCache_t config) {
  TRACE("()");
  hipError_t err = hipFuncSetCacheConfig(func, config);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMemcpyHtoD(hipDeviceptr_t dst, void *src,
                                     size_t sizeBytes) {
  TRACE("(%p, %p, %lld)", dst, src, sizeBytes);
  hipError_t err = hipMemcpyHtoD(dst, src, sizeBytes);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleGetGlobal(hipDeviceptr_t *dptr, size_t *bytes,
                                          hipModule_t hmod, const char *name) {
  hipError_t err = hipModuleGetGlobal(dptr, bytes, hmod, name);
  // TRACE("(%p, %lld, %p, %s)", *dptr, *bytes, hmod, name);
  HIPERR_ASSERT(err == 0);

  // if (err != 0) {
  //     if (dptr != NULL) {
  //         *dptr = (void*)0xDEADBEEF;
  //     }

  //     if (bytes != NULL) {
  //         *bytes = 0;
  //     }
  // }

  // TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMemsetD8(hipDeviceptr_t dest, unsigned char value,
                                   size_t count) {
  return hipMemsetD8(dest, value, count);
}

hipError_t WINAPI wine_hipMemsetD8Async(hipDeviceptr_t dest,
                                        unsigned char value, size_t count,
                                        hipStream_t stream) {
  TRACE("(%p, %d, %lld, %p)\n", dest, value, count, stream);
  hipError_t err = hipMemsetD8Async(dest, value, count, stream);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipArrayCreate(
    hipArray_t *pHandle, const HIP_ARRAY_DESCRIPTOR *pAllocateArray) {
  hipError_t err = hipArrayCreate(pHandle, pAllocateArray);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipModuleUnload(hipModule_t module) {
  hipError_t err = hipModuleUnload(module);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipHostFree(void *ptr) {
  hipError_t err = hipHostFree(ptr);
  assert(err == 0);
  return err;
}

hipError_t WINAPI
wine_hipDestroyTextureObject(hipTextureObject_t textureObject) {
  hipError_t err = hipDestroyTextureObject(textureObject);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipDeviceComputeCapability(int *major, int *minor,
                                                  hipDevice_t device) {
  hipError_t err = hipDeviceComputeCapability(major, minor, device);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipFreeArray(hipArray_t array) {
  hipError_t err = hipFreeArray(array);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipCtxDestroy(hipCtx_t ctx) {
  hipError_t err = hipCtxDestroy(ctx);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipModuleLaunchKernel(
    hipFunction_t f, unsigned int gridDimX, unsigned int gridDimY,
    unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY,
    unsigned int blockDimZ, unsigned int sharedMemBytes, hipStream_t stream,
    void **kernelParams, void **extra) {
  TRACE("()");
  hipError_t err = hipModuleLaunchKernel(
      f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ,
      sharedMemBytes, stream, kernelParams, extra);
  assert(err == 0);
  TRACE_RET();
  return err;
};

hipError_t WINAPI wine_hipMemcpyDtoH(void *dst, hipDeviceptr_t src,
                                     size_t sizeBytes) {
  hipError_t err = hipMemcpyDtoH(dst, src, sizeBytes);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyDtoDAsync(hipDeviceptr_t dst,
                                          hipDeviceptr_t src, size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyDtoDAsync(dst, src, sizeBytes, stream);
  assert(err == 0);
  return err;
};

hipError_t WINAPI wine_hipMemcpyDtoHAsync(void *dst, hipDeviceptr_t src,
                                          size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyDtoHAsync(dst, src, sizeBytes, stream);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamSynchronize(hipStream_t stream) {
  hipError_t err = hipStreamSynchronize(stream);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamWaitEvent(hipStream_t stream, hipEvent_t event,
                                          unsigned int flags) {
  hipError_t err = hipStreamWaitEvent(stream, event, flags);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipMemoryType fixMem(hipMemoryType memType) {
  switch (memType) {
  case 0:
    return 1;
  case 1:
    return 2;
  case 2:
    return 10;
    break;
  case 3:
    return 11;
  case 4:
    return 3;
  }
}

void fixMem_i(hipMemoryType *m) { *m = fixMem(*m); }

// Very weird shit is happening, wtf
hipError_t WINAPI wine_hipMemcpyParam2D(const hip_Memcpy2D *pCopy) {

  // hip_Memcpy2D local = *pCopy;
  // fixMem(&(local.srcMemoryType));
  // fixMem(&(local.dstMemoryType));

  // hip_Memcpy2D local = *pCopy;
  // fixMem_i(&(local.srcMemoryType));
  // fixMem_i(&(local.dstMemoryType));
  // hipError_t err = hipMemcpyParam2D(&local);

  // No need for hip 5.0 fixup
  hipError_t err = hipMemcpyParam2D(pCopy);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyParam2DAsync(const hip_Memcpy2D *pCopy,
                                             hipStream_t stream) {
  hipError_t err = hipMemcpyParam2DAsync(pCopy, stream);
  return err;
}

const char *WINAPI wine_hipGetErrorString(hipError_t hipError) {
  return hipGetErrorString(hipError);
}

hipError_t WINAPI wine_hipGetLastError(void) { return hipGetLastError(); }

hipError_t WINAPI wine_hipTexObjectCreate(
    hipTextureObject_t *pTexObject, const HIP_RESOURCE_DESC *pResDesc,
    const HIP_TEXTURE_DESC *pTexDesc,
    const HIP_RESOURCE_VIEW_DESC *pResViewDesc) {
  hipError_t err =
      hipTexObjectCreate(pTexObject, pResDesc, pTexDesc, pResViewDesc);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyHtoDAsync(hipDeviceptr_t dst, void *src,
                                          size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyHtoDAsync(dst, src, sizeBytes, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipArray3DCreate(
    hipArray_t *array, const HIP_ARRAY3D_DESCRIPTOR *pAllocateArray) {
  hipError_t err = hipArray3DCreate(array, pAllocateArray);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipChannelFormatDesc WINAPI wine_hipCreateChannelDesc(int x, int y, int z,
                                                      int w,
                                                      hipChannelFormatKind f) {
  return hipCreateChannelDesc(x, y, z, w, f);
}

hipError_t WINAPI wine_hipModuleGetTexRef(textureReference **texRef, hipModule_t hmod,
                                   const char *name) {
  return hipModuleGetTexRef(texRef, hmod, name);
}

hipError_t WINAPI wine_hipUnbindTexture(const textureReference* tex) {
  return hipUnbindTexture(tex);
}

hipError_t WINAPI wine_hipTexRefSetFormat(textureReference *texRef,
                                           hipArray_Format fmt,
                                           int NumPackedComponents) {
  return hipTexRefSetFormat(texRef, fmt, NumPackedComponents);
}

hipError_t WINAPI wine_hipTexRefSetAddress(size_t *ByteOffset,
                                            textureReference *texRef,
                                            hipDeviceptr_t dptr,
                                            size_t bytes) {
  return hipTexRefSetAddress(ByteOffset, texRef, dptr, bytes);
}

hipError_t WINAPI wine_hipTexRefSetFlags(textureReference *texRef,
                                          unsigned int Flags) {
  return hipTexRefSetFlags(texRef, Flags);
}

typedef struct HIP_MEMCPY3D_v5 {
  unsigned int srcXInBytes;
  unsigned int srcY;
  unsigned int srcZ;
  unsigned int srcLOD;
  hipMemoryType srcMemoryType;
  const void *srcHost;
  hipDeviceptr_t srcDevice;
  hipArray_t srcArray;
  unsigned int srcPitch;
  unsigned int srcHeight;
  unsigned int dstXInBytes;
  unsigned int dstY;
  unsigned int dstZ;
  unsigned int dstLOD;
  hipMemoryType dstMemoryType;
  void *dstHost;
  hipDeviceptr_t dstDevice;
  hipArray_t dstArray;
  unsigned int dstPitch;
  unsigned int dstHeight;
  unsigned int WidthInBytes;
  unsigned int Height;
  unsigned int Depth;
} HIP_MEMCPY3D_v5;

// hipError_t WINAPI wine_hipDrvMemcpy3D(const HIP_MEMCPY3D_v5 *pCopy)
// {
//     HIP_MEMCPY3D local = {
//         .srcXInBytes = pCopy->srcXInBytes,
//         .srcY = pCopy->srcY,
//         .srcZ = pCopy->srcZ,
//         .srcLOD = pCopy->srcLOD,
//         .srcMemoryType = fixMem(pCopy->srcMemoryType),
//         .srcHost = pCopy->srcHost,
//         .srcDevice = pCopy->srcDevice,
//         .srcArray = pCopy->srcArray,
//         .srcPitch = pCopy->srcPitch,
//         .srcHeight = pCopy->srcHeight,
//         .dstXInBytes = pCopy->dstXInBytes,
//         .dstY = pCopy->dstY,
//         .dstZ = pCopy->dstZ,
//         .dstLOD = pCopy->dstLOD,
//         .dstMemoryType = fixMem(pCopy->dstMemoryType),
//         .dstHost = pCopy->dstHost,
//         .dstDevice = pCopy->dstDevice,
//         .dstArray = pCopy->dstArray,
//         .dstPitch = pCopy->dstPitch,
//         .dstHeight = pCopy->dstHeight,
//         .WidthInBytes = pCopy->WidthInBytes,
//         .Height = pCopy->Height,
//         .Depth = pCopy->Depth,
//     };

//     hipError_t err = hipDrvMemcpy3D(&local);
//     HIPERR_ASSERT(err == 0);
//     return err;
// }

hipError_t WINAPI wine_hipDrvMemcpy3D(const HIP_MEMCPY3D *pCopy) {
  hipError_t err = hipDrvMemcpy3D(pCopy);
  HIPERR_ASSERT(err == 0);
  return err;
}
hipError_t WINAPI wine_hipEventQuery(hipEvent_t event) {
  return hipEventQuery(event);
}

hipError_t WINAPI wine_hipDeviceSynchronize() { return hipDeviceSynchronize(); }

hipError_t WINAPI wine_hipStreamIsCapturing(
    hipStream_t stream, hipStreamCaptureStatus *pCaptureStatus) {
  return hipStreamIsCapturing(stream, pCaptureStatus);
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    break;
  case DLL_PROCESS_DETACH:
    if (reserved)
      break;
    break;
  case DLL_THREAD_ATTACH:
    break;
  case DLL_THREAD_DETACH:
    break;
  }

  return TRUE;
}
