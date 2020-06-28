#include "awtk.h"
#include <time.h>
#define RENYJ_TRACE( format, args... )do {fprintf(stderr,  "RENYJ_TRACE >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args);}while(0)


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
        if (tk_str_eq(name, "next")) 
        {
            RENYJ_TRACE("AWTK_DEBUG--->");
        }
        else if(tk_str_eq(name, "exit"))
        {
            RENYJ_TRACE("AWTK_DEBUG--->");
            widget_t* win = widget_get_window(widget);
            widget_on(widget, EVT_CLICK, on_close, win);
        }
	 }
	return 0;
} 


static void init_children_widget(widget_t* widget) {
  widget_foreach(widget, init_widget, widget);
}

void on_checkout(widget_t* win)
{
    widget_t* win_menu = window_open("check_out");
    if (win_menu) {
      init_children_widget(win_menu);
     // widget_on(win_menu, EVT_KEY_UP, menu_on_key_up, win_menu);
      return RET_OK;
    }
    return RET_FAIL;
}

