#include "awtk.h"
#include "../res/assets.inc"

#define RENYJ_TRACE( format, args... )do {fprintf(stderr,  "RENYJ_TRACE >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args);}while(0)

extern int eagle_eye_lcd_init();
int main()
{
	int lcd_w =455;
	int lcd_h = 787;
	char res_root[MAX_PATH + 1];
	char app_root[MAX_PATH + 1];
	path_app_root(app_root);
	memset(res_root, 0x00, sizeof(res_root));
	path_build(res_root, MAX_PATH, app_root, "res", NULL);
	tk_init(lcd_w, lcd_h, APP_MOBILE, "EagleEye", res_root);

	/* 初始化资源 */
	assets_init();
	/* 初始化扩展控件 */
	tk_ext_widgets_init();
	eagle_eye_lcd_init();
	/* 进入awtk事件循环 */
	tk_run();
	return 0;
}
