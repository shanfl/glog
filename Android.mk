LOCAL_PATH := $(call my-dir)  
  
include $(CLEAR_VARS)  
  
LOCAL_MODULE := glog_static 
  
LOCAL_MODULE_FILENAME := libglog  
  
LOCAL_SRC_FILES := src/demangle.cc \
	src/logging.cc \
	src/raw_logging.cc \
	src/signalhandler.cc \
	src/symbolize.cc \
	src/utilities.cc \
	src/vlog_is_on.cc
  
LOCAL_EXPORT_C_INCLUDES :=  
LOCAL_EXPORT_LDLIBS :=  
  
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
	$(LOCAL_PATH)/src
	
	
#LOCAL_C_INCLUDES += system/core/include/cutils
#LOCAL_SHARED_LIBRARIES := libcutil

LOCAL_LIBS := \
	-lpthread
	
include $(BUILD_STATIC_LIBRARY)  