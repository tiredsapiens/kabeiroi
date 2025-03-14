#include "platform.h"


#if KPLATFORM_WINDOWS

#include <windows.h>
#incude <windowsx.h>
typedeftruct internal_state{
  HINSTANCE h_instance;
  HWND hwnd;
}internal_state;
n
b8 platform_startup(platform_state *plat_state,const char * application_name,i32 x, i32 y, i32 width, i32 height){

}
#endif
