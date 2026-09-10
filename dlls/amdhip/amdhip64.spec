@ stub __gnu_f2h_ieee
@ stub __gnu_h2f_ieee
@ stub __hipPopCallConfiguration
@ stub __hipPushCallConfiguration
@ stdcall __hipRegisterFatBinary(ptr) wine___hipRegisterFatBinary
@ stdcall __hipRegisterFunction(ptr ptr ptr str long ptr ptr ptr ptr ptr) wine___hipRegisterFunction
@ stub __hipRegisterManagedVar
@ stub __hipRegisterSurface
@ stub __hipRegisterTexture
@ stub __hipRegisterVar
@ stdcall __hipUnregisterFatBinary(ptr) wine___hipUnregisterFatBinary
@ stub amd_dbgapi_get_build_id
@ stub amd_dbgapi_get_build_name
@ stub amd_dbgapi_get_git_hash
@ stub hipApiName
@ stdcall hipArray3DCreate(ptr ptr) wine_hipArray3DCreate
@ stub hipArray3DGetDescriptor
@ stdcall hipArrayCreate(ptr ptr) wine_hipArrayCreate
@ stub hipArrayDestroy
@ stub hipArrayGetDescriptor
@ stub hipArrayGetInfo
@ stub hipBindTexture
@ stub hipBindTexture2D
@ stub hipBindTextureToArray
@ stub hipBindTextureToMipmappedArray
@ stub hipChooseDevice
@ stub hipChooseDeviceR0000
@ stub hipChooseDeviceR0600
@ stub hipConfigureCall
@ stdcall hipCreateChannelDesc(long long long long long) wine_hipCreateChannelDesc
@ stub hipCreateSurfaceObject
@ stub hipCreateTextureObject
@ stdcall hipCtxCreate(ptr long long) wine_hipCtxCreate
@ stdcall hipCtxDestroy(ptr) wine_hipCtxDestroy
@ stub hipCtxDisablePeerAccess
@ stub hipCtxEnablePeerAccess
@ stub hipCtxGetApiVersion
@ stub hipCtxGetCacheConfig
@ stub hipCtxGetCurrent
@ stub hipCtxGetDevice
@ stub hipCtxGetFlags
@ stub hipCtxGetSharedMemConfig
@ stdcall hipCtxPopCurrent(ptr) wine_hipCtxPopCurrent
@ stdcall hipCtxPushCurrent(ptr) wine_hipCtxPushCurrent
@ stub hipCtxSetCacheConfig
@ stub hipCtxSetCurrent
@ stub hipCtxSetSharedMemConfig
@ stub hipCtxSynchronize
@ stub hipDestroyExternalMemory
@ stub hipDestroyExternalSemaphore
@ stub hipDestroySurfaceObject
@ stdcall hipDestroyTextureObject(ptr) wine_hipDestroyTextureObject
@ stub hipDeviceCanAccessPeer
@ stdcall hipDeviceComputeCapability(ptr ptr long) wine_hipDeviceComputeCapability 
@ stub hipDeviceDisablePeerAccess
@ stub hipDeviceEnablePeerAccess
@ stdcall hipDeviceGet(ptr long) wine_hipDeviceGet
@ stdcall hipDeviceGetAttribute(ptr long long) wine_hipDeviceGetAttribute
@ stub hipDeviceGetByPCIBusId
@ stub hipDeviceGetCacheConfig
@ stub hipDeviceGetDefaultMemPool
@ stub hipDeviceGetGraphMemAttribute
@ stub hipDeviceGetLimit
@ stub hipDeviceGetMemPool
@ stdcall hipDeviceGetName(ptr long long) wine_hipDeviceGetName
@ stub hipDeviceGetP2PAttribute
@ stub hipDeviceGetPCIBusId
@ stub hipDeviceGetSharedMemConfig
@ stub hipDeviceGetStreamPriorityRange
@ stdcall hipDeviceGetUuid(ptr long) wine_hipDeviceGetUuid
@ stub hipDeviceGraphMemTrim
@ stub hipDevicePrimaryCtxGetState
@ stub hipDevicePrimaryCtxRelease
@ stub hipDevicePrimaryCtxReset
@ stub hipDevicePrimaryCtxRetain
@ stub hipDevicePrimaryCtxSetFlags
@ stdcall hipDeviceReset() wine_hipDeviceReset
@ stdcall hipDeviceSetCacheConfig(long) wine_hipDeviceSetCacheConfig
@ stub hipDeviceSetGraphMemAttribute
@ stdcall hipDeviceSetLimit(long int64) wine_hipDeviceSetLimit
@ stub hipDeviceSetMemPool
@ stub hipDeviceSetSharedMemConfig
@ stdcall hipDeviceSynchronize() wine_hipDeviceSynchronize
@ stdcall hipDeviceTotalMem(ptr long) wine_hipDeviceTotalMem
@ stdcall hipDriverGetVersion(ptr) wine_hipDriverGetVersion
@ stub hipDrvGetErrorName
@ stub hipDrvGetErrorString
@ stub hipDrvGraphAddMemcpyNode
@ stub hipDrvGraphAddMemsetNode
@ stub hipDrvMemcpy2DUnaligned
@ stdcall hipDrvMemcpy3D(ptr) wine_hipDrvMemcpy3D
@ stub hipDrvMemcpy3DAsync
@ stub hipDrvPointerGetAttributes
@ stub hipEventCreate
@ stdcall hipEventCreateWithFlags(ptr long) wine_hipEventCreateWithFlags
@ stdcall hipEventDestroy(ptr) wine_hipEventDestroy
@ stub hipEventElapsedTime
@ stdcall hipEventQuery(ptr) wine_hipEventQuery
@ stdcall hipEventRecord(ptr ptr) wine_hipEventRecord
@ stub hipEventRecord_spt
@ stdcall hipEventSynchronize(ptr) wine_hipEventSynchronize
@ stub hipExtGetLastError
@ stub hipExtGetLinkTypeAndHopCount
@ stub hipExtLaunchKernel
@ stub hipExtLaunchMultiKernelMultiDevice
@ stub hipExtMallocWithFlags
@ stub hipExtModuleLaunchKernel
@ stub hipExtStreamCreateWithCUMask
@ stub hipExtStreamGetCUMask
@ stub hipExternalMemoryGetMappedBuffer
@ stdcall hipFree(ptr) wine_hipFree
@ stdcall hipFreeArray(ptr) wine_hipFreeArray
@ stub hipFreeAsync
@ stub hipFreeHost
@ stub hipFreeMipmappedArray
@ stdcall hipFuncGetAttribute(ptr long ptr) wine_hipFuncGetAttribute
@ stub hipFuncGetAttributes
@ stub hipFuncSetAttribute
@ stdcall hipFuncSetCacheConfig(ptr long) wine_hipFuncSetCacheConfig
@ stub hipFuncSetSharedMemConfig
@ stub hipGLGetDevices
@ stub hipGetChannelDesc
@ stub hipGetCmdName
@ stdcall hipGetDevice(ptr) wine_hipGetDevice
@ stdcall hipGetDeviceCount(ptr) wine_hipGetDeviceCount
@ stub hipGetDeviceFlags
@ stdcall hipGetDeviceProperties(ptr long) wine_hipGetDeviceProperties
@ stub hipGetDevicePropertiesR0000
@ stdcall hipGetDevicePropertiesR0600(ptr long) wine_hipGetDevicePropertiesR0600
@ stub hipGetErrorName
@ stdcall hipGetErrorString(long) wine_hipGetErrorString
@ stdcall hipGetLastError() wine_hipGetLastError
@ stub hipGetMipmappedArrayLevel
@ stub hipGetStreamDeviceId
@ stub hipGetSymbolAddress
@ stub hipGetSymbolSize
@ stub hipGetTextureAlignmentOffset
@ stub hipGetTextureObjectResourceDesc
@ stub hipGetTextureObjectResourceViewDesc
@ stub hipGetTextureObjectTextureDesc
@ stub hipGetTextureReference
@ stub hipGraphAddChildGraphNode
@ stub hipGraphAddDependencies
@ stub hipGraphAddEmptyNode
@ stub hipGraphAddEventRecordNode
@ stub hipGraphAddEventWaitNode
@ stub hipGraphAddHostNode
@ stub hipGraphAddKernelNode
@ stub hipGraphAddMemAllocNode
@ stub hipGraphAddMemFreeNode
@ stub hipGraphAddMemcpyNode
@ stub hipGraphAddMemcpyNode1D
@ stub hipGraphAddMemcpyNodeFromSymbol
@ stub hipGraphAddMemcpyNodeToSymbol
@ stub hipGraphAddMemsetNode
@ stub hipGraphChildGraphNodeGetGraph
@ stub hipGraphClone
@ stub hipGraphCreate
@ stub hipGraphDebugDotPrint
@ stub hipGraphDestroy
@ stub hipGraphDestroyNode
@ stub hipGraphEventRecordNodeGetEvent
@ stub hipGraphEventRecordNodeSetEvent
@ stub hipGraphEventWaitNodeGetEvent
@ stub hipGraphEventWaitNodeSetEvent
@ stub hipGraphExecChildGraphNodeSetParams
@ stub hipGraphExecDestroy
@ stub hipGraphExecEventRecordNodeSetEvent
@ stub hipGraphExecEventWaitNodeSetEvent
@ stub hipGraphExecHostNodeSetParams
@ stub hipGraphExecKernelNodeSetParams
@ stub hipGraphExecMemcpyNodeSetParams
@ stub hipGraphExecMemcpyNodeSetParams1D
@ stub hipGraphExecMemcpyNodeSetParamsFromSymbol
@ stub hipGraphExecMemcpyNodeSetParamsToSymbol
@ stub hipGraphExecMemsetNodeSetParams
@ stub hipGraphExecUpdate
@ stub hipGraphGetEdges
@ stub hipGraphGetNodes
@ stub hipGraphGetRootNodes
@ stub hipGraphHostNodeGetParams
@ stub hipGraphHostNodeSetParams
@ stub hipGraphInstantiate
@ stub hipGraphInstantiateWithFlags
@ stub hipGraphKernelNodeCopyAttributes
@ stub hipGraphKernelNodeGetAttribute
@ stub hipGraphKernelNodeGetParams
@ stub hipGraphKernelNodeSetAttribute
@ stub hipGraphKernelNodeSetParams
@ stub hipGraphLaunch
@ stub hipGraphLaunch_spt
@ stub hipGraphMemAllocNodeGetParams
@ stub hipGraphMemFreeNodeGetParams
@ stub hipGraphMemcpyNodeGetParams
@ stub hipGraphMemcpyNodeSetParams
@ stub hipGraphMemcpyNodeSetParams1D
@ stub hipGraphMemcpyNodeSetParamsFromSymbol
@ stub hipGraphMemcpyNodeSetParamsToSymbol
@ stub hipGraphMemsetNodeGetParams
@ stub hipGraphMemsetNodeSetParams
@ stub hipGraphNodeFindInClone
@ stub hipGraphNodeGetDependencies
@ stub hipGraphNodeGetDependentNodes
@ stub hipGraphNodeGetEnabled
@ stub hipGraphNodeGetType
@ stub hipGraphNodeSetEnabled
@ stub hipGraphReleaseUserObject
@ stub hipGraphRemoveDependencies
@ stub hipGraphRetainUserObject
@ stub hipGraphUpload
@ stub hipGraphicsGLRegisterBuffer
@ stub hipGraphicsGLRegisterImage
@ stub hipGraphicsMapResources
@ stub hipGraphicsResourceGetMappedPointer
@ stub hipGraphicsSubResourceGetMappedArray
@ stub hipGraphicsUnmapResources
@ stub hipGraphicsUnregisterResource
@ stub hipHccModuleLaunchKernel
@ stub hipHostAlloc
@ stdcall hipHostFree(ptr) wine_hipHostFree
@ stdcall hipHostGetDevicePointer(ptr ptr long) wine_hipHostGetDevicePointer
@ stub hipHostGetFlags
@ stdcall hipHostMalloc(ptr int64 long) wine_hipHostMalloc
@ stub hipHostRegister
@ stub hipHostUnregister
@ stub hipImportExternalMemory
@ stub hipImportExternalSemaphore
@ stdcall hipInit(long) wine_hipInit
@ stub hipIpcCloseMemHandle
@ stub hipIpcGetEventHandle
@ stub hipIpcGetMemHandle
@ stub hipIpcOpenEventHandle
@ stub hipIpcOpenMemHandle
@ stub hipKernelNameRef
@ stub hipLaunchByPtr
@ stub hipLaunchCooperativeKernel
@ stub hipLaunchCooperativeKernelMultiDevice
@ stub hipLaunchCooperativeKernel_spt
@ stub hipLaunchHostFunc
@ stub hipLaunchHostFunc_spt
@ stub hipLaunchKernel
@ stub hipLaunchKernel_spt
@ stdcall hipMalloc(ptr int64) wine_hipMalloc
@ stub hipMalloc3D
@ stub hipMalloc3DArray
@ stub hipMallocArray
@ stub hipMallocAsync
@ stub hipMallocFromPoolAsync
@ stub hipMallocHost
@ stub hipMallocManaged
@ stub hipMallocMipmappedArray
@ stub hipMallocPitch
@ stub hipMemAddressFree
@ stub hipMemAddressReserve
@ stub hipMemAdvise
@ stub hipMemAllocHost
@ stub hipMemAllocPitch
@ stub hipMemCreate
@ stub hipMemExportToShareableHandle
@ stub hipMemGetAccess
@ stub hipMemGetAddressRange
@ stub hipMemGetAllocationGranularity
@ stub hipMemGetAllocationPropertiesFromHandle
@ stdcall hipMemGetInfo(ptr ptr) wine_hipMemGetInfo
@ stub hipMemImportFromShareableHandle
@ stub hipMemMap
@ stub hipMemMapArrayAsync
@ stub hipMemPoolCreate
@ stub hipMemPoolDestroy
@ stub hipMemPoolExportPointer
@ stub hipMemPoolExportToShareableHandle
@ stub hipMemPoolGetAccess
@ stub hipMemPoolGetAttribute
@ stub hipMemPoolImportFromShareableHandle
@ stub hipMemPoolImportPointer
@ stub hipMemPoolSetAccess
@ stub hipMemPoolSetAttribute
@ stub hipMemPoolTrimTo
@ stub hipMemPrefetchAsync
@ stub hipMemPtrGetInfo
@ stub hipMemRangeGetAttribute
@ stub hipMemRangeGetAttributes
@ stub hipMemRelease
@ stub hipMemRetainAllocationHandle
@ stub hipMemSetAccess
@ stub hipMemUnmap
@ stdcall hipMemcpy(ptr ptr int64 long) wine_hipMemcpy
@ stub hipMemcpy2D
@ stub hipMemcpy2DAsync
@ stub hipMemcpy2DAsync_spt
@ stub hipMemcpy2DFromArray
@ stub hipMemcpy2DFromArrayAsync
@ stub hipMemcpy2DFromArrayAsync_spt
@ stub hipMemcpy2DFromArray_spt
@ stub hipMemcpy2DToArray
@ stub hipMemcpy2DToArrayAsync
@ stub hipMemcpy2DToArrayAsync_spt
@ stub hipMemcpy2DToArray_spt
@ stub hipMemcpy2D_spt
@ stub hipMemcpy3D
@ stub hipMemcpy3DAsync
@ stub hipMemcpy3DAsync_spt
@ stub hipMemcpy3D_spt
@ stdcall hipMemcpyAsync(ptr ptr int64 long ptr) wine_hipMemcpyAsync
@ stub hipMemcpyAsync_spt
@ stub hipMemcpyAtoH
@ stub hipMemcpyDtoD
@ stdcall hipMemcpyDtoDAsync(ptr ptr int64 ptr) wine_hipMemcpyDtoDAsync
@ stdcall hipMemcpyDtoH(ptr ptr int64) wine_hipMemcpyDtoH
@ stdcall hipMemcpyDtoHAsync(ptr ptr int64 ptr) wine_hipMemcpyDtoHAsync
@ stub hipMemcpyFromArray
@ stub hipMemcpyFromArray_spt
@ stub hipMemcpyFromSymbol
@ stub hipMemcpyFromSymbolAsync
@ stub hipMemcpyFromSymbolAsync_spt
@ stub hipMemcpyFromSymbol_spt
@ stub hipMemcpyHtoA
@ stdcall hipMemcpyHtoD(ptr ptr int64) wine_hipMemcpyHtoD
@ stdcall hipMemcpyHtoDAsync(ptr ptr int64 ptr) wine_hipMemcpyHtoDAsync
@ stdcall hipMemcpyParam2D(ptr) wine_hipMemcpyParam2D
@ stdcall hipMemcpyParam2DAsync(ptr ptr) wine_hipMemcpyParam2DAsync
@ stub hipMemcpyPeer
@ stub hipMemcpyPeerAsync
@ stub hipMemcpyToArray
@ stub hipMemcpyToSymbol
@ stub hipMemcpyToSymbolAsync
@ stub hipMemcpyToSymbolAsync_spt
@ stub hipMemcpyToSymbol_spt
@ stub hipMemcpyWithStream
@ stub hipMemcpy_spt
@ stub hipMemset
@ stub hipMemset2D
@ stub hipMemset2DAsync
@ stub hipMemset2DAsync_spt
@ stub hipMemset2D_spt
@ stub hipMemset3D
@ stub hipMemset3DAsync
@ stub hipMemset3DAsync_spt
@ stub hipMemset3D_spt
@ stub hipMemsetAsync
@ stub hipMemsetAsync_spt
@ stub hipMemsetD16
@ stub hipMemsetD16Async
@ stub hipMemsetD32
@ stub hipMemsetD32Async
@ stdcall hipMemsetD8(ptr long int64) wine_hipMemsetD8
@ stdcall hipMemsetD8Async(ptr long int64 ptr) wine_hipMemsetD8Async
@ stub hipMemset_spt
@ stub hipMipmappedArrayCreate
@ stub hipMipmappedArrayDestroy
@ stub hipMipmappedArrayGetLevel
@ stdcall hipModuleGetFunction(ptr ptr str) wine_hipModuleGetFunction
@ stdcall hipModuleGetGlobal(ptr ptr ptr str) wine_hipModuleGetGlobal
@ stdcall hipModuleGetTexRef(ptr ptr str) wine_hipModuleGetTexRef
@ stub hipModuleLaunchCooperativeKernel
@ stub hipModuleLaunchCooperativeKernelMultiDevice
@ stdcall hipModuleLaunchKernel(ptr long long long long long long long ptr ptr ptr) wine_hipModuleLaunchKernel
@ stub hipModuleLoad
@ stdcall hipModuleLoadData(ptr ptr) wine_hipModuleLoadData
@ stub hipModuleLoadDataEx
@ stub hipModuleOccupancyMaxActiveBlocksPerMultiprocessor
@ stub hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
@ stub hipModuleOccupancyMaxPotentialBlockSize
@ stub hipModuleOccupancyMaxPotentialBlockSizeWithFlags
@ stdcall hipModuleUnload(ptr) wine_hipModuleUnload
@ stub hipOccupancyMaxActiveBlocksPerMultiprocessor
@ stub hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
@ stub hipOccupancyMaxPotentialBlockSize
@ stub hipPeekAtLastError
@ stub hipPointerGetAttribute
@ stub hipPointerGetAttributes
@ stub hipProfilerStart
@ stub hipProfilerStop
@ stub hipRegisterTracerCallback
@ stdcall hipRuntimeGetVersion(ptr) wine_hipRuntimeGetVersion
@ stdcall hipSetDevice(long) wine_hipSetDevice
@ stub hipSetDeviceFlags
@ stub hipSetupArgument
@ stub hipSignalExternalSemaphoresAsync
@ stub hipStreamAddCallback
@ stub hipStreamAddCallback_spt
@ stub hipStreamAttachMemAsync
@ stub hipStreamBeginCapture
@ stub hipStreamBeginCapture_spt
@ stdcall hipStreamCreate(ptr) wine_hipStreamCreate
@ stdcall hipStreamCreateWithFlags(ptr long) wine_hipStreamCreateWithFlags
@ stub hipStreamCreateWithPriority
@ stdcall hipStreamDestroy(ptr) wine_hipStreamDestroy
@ stub hipStreamEndCapture
@ stub hipStreamEndCapture_spt
@ stub hipStreamGetCaptureInfo
@ stub hipStreamGetCaptureInfo_spt
@ stub hipStreamGetCaptureInfo_v2
@ stub hipStreamGetCaptureInfo_v2_spt
@ stub hipStreamGetDevice
@ stub hipStreamGetFlags
@ stub hipStreamGetFlags_spt
@ stub hipStreamGetPriority
@ stub hipStreamGetPriority_spt
@ stdcall hipStreamIsCapturing(ptr ptr) wine_hipStreamIsCapturing
@ stub hipStreamIsCapturing_spt
@ stdcall hipStreamQuery(ptr) wine_hipStreamQuery
@ stub hipStreamQuery_spt
@ stdcall hipStreamSynchronize(ptr) wine_hipStreamSynchronize
@ stub hipStreamSynchronize_spt
@ stub hipStreamUpdateCaptureDependencies
@ stdcall hipStreamWaitEvent(ptr ptr long) wine_hipStreamWaitEvent
@ stub hipStreamWaitEvent_spt
@ stub hipStreamWaitValue32
@ stub hipStreamWaitValue64
@ stub hipStreamWriteValue32
@ stub hipStreamWriteValue64
@ stdcall hipTexObjectCreate(ptr ptr ptr ptr) wine_hipTexObjectCreate
@ stub hipTexObjectDestroy
@ stub hipTexObjectGetResourceDesc
@ stub hipTexObjectGetResourceViewDesc
@ stub hipTexObjectGetTextureDesc
@ stub hipTexRefGetAddress
@ stub hipTexRefGetAddressMode
@ stub hipTexRefGetFilterMode
@ stub hipTexRefGetFlags
@ stub hipTexRefGetFormat
@ stub hipTexRefGetMaxAnisotropy
@ stub hipTexRefGetMipMappedArray
@ stub hipTexRefGetMipmapFilterMode
@ stub hipTexRefGetMipmapLevelBias
@ stub hipTexRefGetMipmapLevelClamp
@ stdcall hipTexRefSetAddress(ptr ptr ptr int64) wine_hipTexRefSetAddress
@ stub hipTexRefSetAddress2D
@ stub hipTexRefSetAddressMode
@ stub hipTexRefSetArray
@ stub hipTexRefSetBorderColor
@ stub hipTexRefSetFilterMode
@ stdcall hipTexRefSetFlags(ptr long) wine_hipTexRefSetFlags
@ stdcall hipTexRefSetFormat(ptr long long) wine_hipTexRefSetFormat
@ stub hipTexRefSetMaxAnisotropy
@ stub hipTexRefSetMipmapFilterMode
@ stub hipTexRefSetMipmapLevelBias
@ stub hipTexRefSetMipmapLevelClamp
@ stub hipTexRefSetMipmappedArray
@ stub hipThreadExchangeStreamCaptureMode
@ stdcall hipUnbindTexture(ptr) wine_hipUnbindTexture
@ stub hipUserObjectCreate
@ stub hipUserObjectRelease
@ stub hipUserObjectRetain
@ stub hipWaitExternalSemaphoresAsync
