#include "awtk.h"
#include <time.h>
#define RENYJ_TRACE( format, args... )do {fprintf(stderr,  "RENYJ_TRACE >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args);}while(0)

int question_index = 0;
char *question_list[]=
{
    "python 如何实现树状结构?",
    "Unix 编程艺术中对我来说最实用的原则是哪个?",
    "当前阶段能够最快速提升自己的方向是哪三个?",
    "今天的工作状态是否满意?为什么?",
};

static ret_t on_close(void* ctx, event_t* e) {
  widget_t* win = (widget_t*)ctx;
  (void)e;
  return window_close(win);
}


static ret_t on_next(void *ctx,event_t *e)
{
    widget_t* win = (widget_t*)ctx;
    (void)e;
    question_index++;
    question_index = question_index%4;
    RENYJ_TRACE("NEXT_DEBUG--->win->name=%s",win->name);
    widget_t *display_widget = widget_lookup(win,"check_out_show_text",1);
    //rich_text_set_prop(display_widget,"text",);
    char string[128]="";
    snprintf(string,128,"<font size=\"40\">%s</font>",question_list[question_index]);
    rich_text_set_text(display_widget, string);
    return 0;
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
            widget_t* win = widget_get_window(widget);
            widget_on(widget, EVT_CLICK, on_next, win);
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

