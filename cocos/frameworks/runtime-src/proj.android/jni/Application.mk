NDK_TOOLCHAIN_VERSION := 4.9

APP_STL := gnustl_static

#APP_STL := c++_static
#NDK_TOOLCHAIN_VERSION=clang3.4

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fexceptions
APP_LDFLAGS := -latomic

APP_ABI := armeabi


ifeq ($(NDK_DEBUG),1)
  APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
  APP_OPTIM := debug
else
  APP_CPPFLAGS += -DNDEBUG
  APP_OPTIM := release
endif
