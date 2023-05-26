// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_TELACHECKIN;
lv_obj_t *ui_NOMEDASALA1;
lv_obj_t *ui_STATUS1;
//void ui_event_BOTAO1( lv_event_t * e);
lv_obj_t *ui_BOTAO1;
lv_obj_t *ui_TITULOBOTAO1;
lv_obj_t *ui_TELACHECKIN_TEXTODOBOTAO1;
lv_obj_t *ui_TELAOCUPADA;
lv_obj_t *ui_NOMEDASALA;
lv_obj_t *ui_STATUS;
//void ui_event_BOTAO( lv_event_t * e);
lv_obj_t *ui_BOTAO;
lv_obj_t *ui_TITULOBOTAO;
//void ui_event_TELALIVRE( lv_event_t * e);
lv_obj_t *ui_TELALIVRE;
lv_obj_t *ui_NOMEDASALA2;
lv_obj_t *ui_STATUS2;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
// #if LV_COLOR_16_SWAP !=1
//     #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
// #endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_BOTAO1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_TELAOCUPADA, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
}
}
void ui_event_BOTAO( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_TELALIVRE, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
}
}
void ui_event_TELALIVRE( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_TELACHECKIN, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
}
}

///////////////////// SCREENS ////////////////////
void ui_TELACHECKIN_screen_init(void)
{
ui_TELACHECKIN = lv_obj_create(NULL);
lv_obj_clear_flag( ui_TELACHECKIN, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_TELACHECKIN, lv_color_hex(0x040404), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TELACHECKIN, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_TELACHECKIN, lv_color_hex(0xFAA403), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_TELACHECKIN, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_TELACHECKIN, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_TELACHECKIN, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NOMEDASALA1 = lv_label_create(ui_TELACHECKIN);
lv_obj_set_width( ui_NOMEDASALA1, LV_SIZE_CONTENT);  /// 100
lv_obj_set_height( ui_NOMEDASALA1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NOMEDASALA1, 0 );
lv_obj_set_y( ui_NOMEDASALA1, 25 );
lv_obj_set_align( ui_NOMEDASALA1, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_NOMEDASALA1," RIO DE JANEIRO");
lv_obj_clear_flag( ui_NOMEDASALA1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_text_font(ui_NOMEDASALA1, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_STATUS1 = lv_label_create(ui_TELACHECKIN);
lv_obj_set_width( ui_STATUS1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_STATUS1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_STATUS1, 0 );
lv_obj_set_y( ui_STATUS1, 90 );
lv_obj_set_align( ui_STATUS1, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_STATUS1,"Check In");
lv_obj_set_style_text_decor(ui_STATUS1, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_STATUS1, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BOTAO1 = lv_btn_create(ui_TELACHECKIN);
lv_obj_set_width( ui_BOTAO1, 100);
lv_obj_set_height( ui_BOTAO1, 50);
lv_obj_set_x( ui_BOTAO1, 0 );
lv_obj_set_y( ui_BOTAO1, 88 );
lv_obj_set_align( ui_BOTAO1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_BOTAO1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_BOTAO1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_BOTAO1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BOTAO1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_BOTAO1, lv_color_hex(0xF5EFEF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BOTAO1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TITULOBOTAO1 = lv_label_create(ui_TELACHECKIN);
lv_obj_set_width( ui_TITULOBOTAO1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TITULOBOTAO1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TITULOBOTAO1, 0 );
lv_obj_set_y( ui_TITULOBOTAO1, 88 );
lv_obj_set_align( ui_TITULOBOTAO1, LV_ALIGN_CENTER );
lv_label_set_text(ui_TITULOBOTAO1,"Confirmar");
lv_obj_set_style_text_color(ui_TITULOBOTAO1, lv_color_hex(0xF4EBEB), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TITULOBOTAO1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TELACHECKIN_TEXTODOBOTAO1 = lv_label_create(ui_TELACHECKIN);
lv_obj_set_width( ui_TELACHECKIN_TEXTODOBOTAO1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TELACHECKIN_TEXTODOBOTAO1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_TELACHECKIN_TEXTODOBOTAO1, LV_ALIGN_CENTER );

lv_obj_add_event_cb(ui_BOTAO1, ui_event_BOTAO1, LV_EVENT_ALL, NULL);

}
void ui_TELAOCUPADA_screen_init(void)
{
ui_TELAOCUPADA = lv_obj_create(NULL);
lv_obj_clear_flag( ui_TELAOCUPADA, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_TELAOCUPADA, lv_color_hex(0x040404), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TELAOCUPADA, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_TELAOCUPADA, lv_color_hex(0xFA0303), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_TELAOCUPADA, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_TELAOCUPADA, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_TELAOCUPADA, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NOMEDASALA = lv_label_create(ui_TELAOCUPADA);
lv_obj_set_width( ui_NOMEDASALA, LV_SIZE_CONTENT);  /// 100
lv_obj_set_height( ui_NOMEDASALA, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NOMEDASALA, 0 );
lv_obj_set_y( ui_NOMEDASALA, 25 );
lv_obj_set_align( ui_NOMEDASALA, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_NOMEDASALA," RIO DE JANEIRO");
lv_obj_clear_flag( ui_NOMEDASALA, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_text_font(ui_NOMEDASALA, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_STATUS = lv_label_create(ui_TELAOCUPADA);
lv_obj_set_width( ui_STATUS, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_STATUS, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_STATUS, 0 );
lv_obj_set_y( ui_STATUS, 90 );
lv_obj_set_align( ui_STATUS, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_STATUS,"Ocupada");
lv_obj_set_style_text_decor(ui_STATUS, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_STATUS, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BOTAO = lv_btn_create(ui_TELAOCUPADA);
lv_obj_set_width( ui_BOTAO, 100);
lv_obj_set_height( ui_BOTAO, 50);
lv_obj_set_x( ui_BOTAO, 0 );
lv_obj_set_y( ui_BOTAO, 88 );
lv_obj_set_align( ui_BOTAO, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_BOTAO, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_BOTAO, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_BOTAO, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BOTAO, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_BOTAO, lv_color_hex(0xF5EFEF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BOTAO, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TITULOBOTAO = lv_label_create(ui_TELAOCUPADA);
lv_obj_set_width( ui_TITULOBOTAO, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TITULOBOTAO, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TITULOBOTAO, 0 );
lv_obj_set_y( ui_TITULOBOTAO, 88 );
lv_obj_set_align( ui_TITULOBOTAO, LV_ALIGN_CENTER );
lv_label_set_text(ui_TITULOBOTAO,"Encerrar");
lv_obj_set_style_text_color(ui_TITULOBOTAO, lv_color_hex(0xF4EBEB), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TITULOBOTAO, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_BOTAO, ui_event_BOTAO, LV_EVENT_ALL, NULL);

}
void ui_TELALIVRE_screen_init(void)
{
ui_TELALIVRE = lv_obj_create(NULL);
lv_obj_clear_flag( ui_TELALIVRE, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_TELALIVRE, lv_color_hex(0x040404), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TELALIVRE, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_TELALIVRE, lv_color_hex(0x2EA739), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_TELALIVRE, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_TELALIVRE, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_TELALIVRE, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_NOMEDASALA2 = lv_label_create(ui_TELALIVRE);
lv_obj_set_width( ui_NOMEDASALA2, LV_SIZE_CONTENT);  /// 100
lv_obj_set_height( ui_NOMEDASALA2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_NOMEDASALA2, 0 );
lv_obj_set_y( ui_NOMEDASALA2, 25 );
lv_obj_set_align( ui_NOMEDASALA2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_NOMEDASALA2," RIO DE JANEIRO");
lv_obj_clear_flag( ui_NOMEDASALA2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_text_font(ui_NOMEDASALA2, LV_FONT_MONTSERRAT_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_STATUS2 = lv_label_create(ui_TELALIVRE);
lv_obj_set_width( ui_STATUS2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_STATUS2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_STATUS2, 0 );
lv_obj_set_y( ui_STATUS2, 100 );
lv_obj_set_align( ui_STATUS2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_STATUS2,"Livre");
lv_obj_set_style_text_decor(ui_STATUS2, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_STATUS2, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_TELALIVRE, ui_event_TELALIVRE, LV_EVENT_ALL, NULL);

}

void ui_init( void )
{LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_TELACHECKIN_screen_init();
ui_TELAOCUPADA_screen_init();
ui_TELALIVRE_screen_init();
lv_disp_load_scr( ui_TELACHECKIN);
}
