#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
#include "assets/inc/strings/zh_CN.data"
#include "assets/inc/strings/en_US.data"
#include "assets/inc/styles/default.data"
#include "assets/inc/styles/keyboard.data"
#include "assets/inc/ui/import.data"
#include "assets/inc/ui/kb_int.data"
#include "assets/inc/ui/check_out.data"
#include "assets/inc/ui/kb_hex.data"
#include "assets/inc/ui/kb_ufloat.data"
#include "assets/inc/ui/calibration_win.data"
#include "assets/inc/ui/eagle_eye_main.data"
#include "assets/inc/ui/kb_phone.data"
#include "assets/inc/ui/kb_default.data"
#include "assets/inc/ui/kb_uint.data"
#include "assets/inc/ui/kb_ascii.data"
#include "assets/inc/ui/keyboard.data"
#include "assets/inc/ui/kb_float.data"
#ifdef WITH_STB_IMAGE
#include "assets/inc/images/clock_bg_am.res"
#include "assets/inc/images/dialog_bg.res"
#include "assets/inc/images/black_box.res"
#include "assets/inc/images/softkey_background.res"
#include "assets/inc/images/icon_disconnected.res"
#include "assets/inc/images/link_down.res"
#include "assets/inc/images/menu_bg.res"
#include "assets/inc/images/horizontal_line.res"
#include "assets/inc/images/arrow_down_n.res"
#include "assets/inc/images/icon_big_titlebar.res"
#include "assets/inc/images/arrow_doub.res"
#include "assets/inc/images/icon_connected.res"
#include "assets/inc/images/eagle_eye1.res"
#include "assets/inc/images/bar_dark.res"
#include "assets/inc/images/icon_list_focus.res"
#include "assets/inc/images/link_up.res"
#include "assets/inc/images/main_button.res"
#include "assets/inc/images/bg0_bright.res"
#include "assets/inc/images/clock_bg_pm.res"
#include "assets/inc/images/bar_bright.res"
#include "assets/inc/images/title.res"
#include "assets/inc/images/eagle_eye.res"
#include "assets/inc/images/bg0_dark.res"
#else
#endif/*WITH_STB_IMAGE*/
#if defined(WITH_STB_FONT) || defined(WITH_FT_FONT)
#include "assets/inc/fonts/default1.res"
#include "assets/inc/fonts/default.res"
#else/*WITH_STB_FONT or WITH_FT_FONT*/
#endif/*WITH_STB_FONT or WITH_FT_FONT*/
#endif/*WITH_FS_RES*/

ret_t assets_init(void) {
  assets_manager_t* rm = assets_manager();

#ifdef WITH_FS_RES
  assets_manager_preload(rm, ASSET_TYPE_FONT, "default");
  assets_manager_preload(rm, ASSET_TYPE_STYLE, "default");
#else
  assets_manager_add(rm, font_default1);
  assets_manager_add(rm, font_default);
  assets_manager_add(rm, image_clock_bg_am);
  assets_manager_add(rm, image_dialog_bg);
  assets_manager_add(rm, image_black_box);
  assets_manager_add(rm, image_softkey_background);
  assets_manager_add(rm, image_icon_disconnected);
  assets_manager_add(rm, image_link_down);
  assets_manager_add(rm, image_menu_bg);
  assets_manager_add(rm, image_horizontal_line);
  assets_manager_add(rm, image_arrow_down_n);
  assets_manager_add(rm, image_icon_big_titlebar);
  assets_manager_add(rm, image_arrow_doub);
  assets_manager_add(rm, image_icon_connected);
  assets_manager_add(rm, image_eagle_eye1);
  assets_manager_add(rm, image_bar_dark);
  assets_manager_add(rm, image_icon_list_focus);
  assets_manager_add(rm, image_link_up);
  assets_manager_add(rm, image_main_button);
  assets_manager_add(rm, image_bg0_bright);
  assets_manager_add(rm, image_clock_bg_pm);
  assets_manager_add(rm, image_bar_bright);
  assets_manager_add(rm, image_title);
  assets_manager_add(rm, image_eagle_eye);
  assets_manager_add(rm, image_bg0_dark);
  assets_manager_add(rm, style_default);
  assets_manager_add(rm, style_keyboard);
  assets_manager_add(rm, ui_import);
  assets_manager_add(rm, ui_kb_int);
  assets_manager_add(rm, ui_check_out);
  assets_manager_add(rm, ui_kb_hex);
  assets_manager_add(rm, ui_kb_ufloat);
  assets_manager_add(rm, ui_calibration_win);
  assets_manager_add(rm, ui_eagle_eye_main);
  assets_manager_add(rm, ui_kb_phone);
  assets_manager_add(rm, ui_kb_default);
  assets_manager_add(rm, ui_kb_uint);
  assets_manager_add(rm, ui_kb_ascii);
  assets_manager_add(rm, ui_keyboard);
  assets_manager_add(rm, ui_kb_float);
  assets_manager_add(rm, strings_zh_CN);
  assets_manager_add(rm, strings_en_US);
#endif

  tk_init_assets();
  return RET_OK;
}
