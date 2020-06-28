#include "awtk.h"
#include <time.h>
#define RENYJ_TRACE( format, args... )do {fprintf(stderr,  "RENYJ_TRACE >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args);}while(0)
	

static void init_children_widget(widget_t* widget);
extern void on_import(widget_t* win);
extern void on_checkout(widget_t* win);


static ret_t on_close(void* ctx, event_t* e) {
  widget_t* win = (widget_t*)ctx;
  (void)e;
  return window_close(win);
}


static ret_t init_widget(void* ctx, const void* iter)
{
	widget_t* widget = WIDGET(iter);
	(void)ctx;
	 if (widget->name != NULL) 
	 {
	    const char* name = widget->name;
        if (tk_str_eq(name, "import")) {
          widget_t* win = widget_get_window(widget);
          widget_on(widget, EVT_CLICK, on_import, win);
        }
        else if(tk_str_eq(name, "check_out"))
        {
            widget_t* win = widget_get_window(widget);
            widget_on(widget, EVT_CLICK, on_checkout, win);
        }
	 	RENYJ_TRACE("AWTK_DEBUG--->");
	 }
	return 0;
} 


static void init_children_widget(widget_t* widget) {
  widget_foreach(widget, init_widget, widget);
}


ret_t eagle_eye_lcd_init()
{
	RENYJ_TRACE("AWTK_DEBUG--->");
	widget_t* win = window_open("eagle_eye_main");
	RENYJ_TRACE("AWTK_DEBUG--->");
	if(win)
	{
		RENYJ_TRACE("AWTK_DEBUG--->");
		init_children_widget(win);
        return RET_OK;
	}
    return RET_FAIL;
	
}
