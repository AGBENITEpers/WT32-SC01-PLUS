#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

class LGFX : public lgfx::LGFX_Device
{

lgfx::Panel_ST7796      _panel_instance;
lgfx::Bus_Parallel8 _bus_instance;//Instância de barramento paralelo de 8 bits (somente ESP32)
lgfx::Light_PWM     _light_instance;
lgfx::Touch_FT5x06           _touch_instance;//Fatkh 06, Fatkh 06, Fatkh 406, Fatta 06, Fattaat, Fattah, Fatt 436

public:
  LGFX(void)
  {
    {//Configure as configurações de controle de barramento.
      auto cfg = _bus_instance.config();//Obtém a estrutura para configuração do barramento.
//Configurações de barramento paralelo de 8 bits
//cfg.i2s_port = I2S_NUM_0; //Selecione a porta I2S a ser usada (I2S_NUM_0 ou I2S_NUM_1) (Use o modo I2S LCD do ESP32)
      cfg.freq_write = 20000000;//Transmite clock (até 20MHz, arredondado para 80MHz dividido por um inteiro)
      cfg.pin_wr =  47;//número do pino conectando WR
      cfg.pin_rd =  -1;//número do pino conectando RD
      cfg.pin_rs = 0;//Número do pino conectando RS(D/C)
      cfg.pin_d0 = 9;//número do pino conectando D0
      cfg.pin_d1 = 46;//número do pino conectando D1
      cfg.pin_d2 = 3;//número do pino conectando D2
      cfg.pin_d3 = 8;//número do pino conectando D3
      cfg.pin_d4 = 18;//número do pino conectando D4
      cfg.pin_d5 = 17;//número do pino conectando D5
      cfg.pin_d6 = 16;//número do pino conectando D6
      cfg.pin_d7 = 15;//número do pino conectando D7
      _bus_instance.config(cfg);//Reflete o valor de configuração para o barramento.
      _panel_instance.setBus(&_bus_instance);//define o barramento para o painel
    }

    {//Define o controle do painel de exibição.
      auto cfg = _panel_instance.config();//Obtém a estrutura para as configurações do painel de exibição.

      cfg.pin_cs           =    -1;//Número do pino onde o CS está conectado (-1 = desabilita)
      cfg.pin_rst          =    4;//número do pino onde o RST está conectado (-1 = desabilita)
      cfg.pin_busy         =    -1;//número do pino onde BUSY está conectado (-1 = desabilita)

//*Os valores de configuração a seguir são valores iniciais gerais para cada painel, portanto, comente quaisquer itens desconhecidos e experimente-os.

      cfg.panel_width      =   320;//largura exibível real
      cfg.panel_height     =   480;//altura exibível real
      cfg.offset_x         =     0;//Deslocamento do painel na direção X
      cfg.offset_y         =     0;//Quantidade de deslocamento do painel na direção Y
      cfg.offset_rotation  =     0;//Deslocamento do valor de rotação 0~7 (4~7 estão de cabeça para baixo)
      cfg.dummy_read_pixel =     8;//número de bits para leitura fictícia antes da leitura do pixel
      cfg.dummy_read_bits  =     1;//número de bits de leitura fictícia antes da leitura de dados não-pixel
      cfg.readable         =  true;//definido como verdadeiro se os dados puderem ser lidos
      cfg.invert           = true;//Definido como verdadeiro se o brilho do painel for invertido
      cfg.rgb_order        = false;//Definido como verdadeiro se o vermelho e o azul do painel forem trocados
      cfg.dlen_16bit       = false;//Definido como verdadeiro para painéis que transmitem comprimento de dados em unidades de 16 bits com paralelo de 16 bits ou SPI
      cfg.bus_shared       =  true;//Se o barramento for compartilhado com o cartão SD, definido como verdadeiro (controle de barramento com drawJpgFile etc.)

//Defina o seguinte somente quando a exibição for deslocada com um driver com um número variável de pixels, como ST7735 ou ILI9163.
//cfg.memory_width = 240; //Largura máxima suportada pelo driver IC
//cfg.memory_height = 320; //Altura máxima suportada pelo driver IC

      _panel_instance.config(cfg);
    }

//*
    {//Define o controle de luz de fundo. (excluir se não for necessário)
      auto cfg = _light_instance.config();//Obtém a estrutura para configurações de luz de fundo.

      cfg.pin_bl = 45;//número do pino ao qual a luz de fundo está conectada
      cfg.invert = false;//verdadeiro para inverter o brilho da luz de fundo
      cfg.freq   = 44100;//frequência PWM da luz de fundo
      cfg.pwm_channel = 7;//Número do canal PWM a ser usado

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);//Defina a luz de fundo no painel.
    }
//*/

//*
    {//Defina as configurações para o controle da tela sensível ao toque. (excluir se não for necessário)
      auto cfg = _touch_instance.config();

      cfg.x_min      = 0;//Valor X mínimo (valor bruto) obtido da tela sensível ao toque
      cfg.x_max      = 319;//valor X máximo (valor bruto) obtido da tela sensível ao toque
      cfg.y_min      = 0;//Valor Y mínimo (valor bruto) obtido da tela sensível ao toque
      cfg.y_max      = 479;//Valor Y máximo (valor bruto) obtido da tela sensível ao toque
      cfg.pin_int    = 7;//número do pino onde INT está conectado
      cfg.bus_shared = true;//Defina true se estiver usando um barramento comum com a tela
      cfg.offset_rotation = 0;//Ajuste quando a tela e a direção do toque não correspondem Definir com um valor de 0 a 7
//Para conexão I2C
      cfg.i2c_port = 1;//Selecione I2C para usar (0 ou 1)
      cfg.i2c_addr = 0x38;//Número do endereço do dispositivo I2C
      cfg.pin_sda  = 6;//número do pino onde o SDA está conectado
      cfg.pin_scl  = 5;//número do pino onde o SCL está conectado
      cfg.freq = 400000;//ajusta o clock I2C

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);//Defina a tela sensível ao toque para o painel.
    }
//*/
    setPanel(&_panel_instance);//define o painel a ser usado
  }
};

//Crie uma instância da classe preparada.
#include "main.h"
#include <lvgl.h>


LGFX tft;

#define screenWidth 480
#define screenHeight 320

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_TELACHECKIN;
lv_obj_t *ui_NOMEDASALA1;
lv_obj_t *ui_STATUS1;
void ui_event_BOTAO1( lv_event_t * e);
lv_obj_t *ui_BOTAO1;
lv_obj_t *ui_TITULOBOTAO1;
lv_obj_t *ui_TELACHECKIN_TEXTODOBOTAO1;
lv_obj_t *ui_TELAOCUPADA;
lv_obj_t *ui_NOMEDASALA;
lv_obj_t *ui_STATUS;
void ui_event_BOTAO( lv_event_t * e);
lv_obj_t *ui_BOTAO;
lv_obj_t *ui_TITULOBOTAO;
void ui_event_TELALIVRE( lv_event_t * e);
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




void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

void my_touch_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    uint16_t touchX, touchY;
    bool touched = tft.getTouch(&touchX, &touchY);
    if (!touched) { data->state = LV_INDEV_STATE_REL; }
    else {
      data->state = LV_INDEV_STATE_PR;
      data->point.x = touchX;
      data->point.y = touchY;
    }
}


static lv_style_t label_style;
static lv_obj_t *headerLabel;
static lv_obj_t * label;


///////////////////// FUNCTIONS ////////////////////
// void ui_event_BOTAO1( lv_event_t * e) {
//     lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
// if ( event_code == LV_EVENT_CLICKED) {
//       _ui_screen_change( ui_TELAOCUPADA, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
// }
// }
// void ui_event_BOTAO( lv_event_t * e) {
//     lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
// if ( event_code == LV_EVENT_CLICKED) {
//       _ui_screen_change( ui_TELALIVRE, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
// }
// }
// void ui_event_TELALIVRE( lv_event_t * e) {
//     lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
// if ( event_code == LV_EVENT_CLICKED) {
//       _ui_screen_change( ui_TELACHECKIN, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
// }
// }


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
lv_obj_set_style_text_font(ui_NOMEDASALA2, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

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
static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);

/*Atualiza o texto*/
    lv_label_set_text_fmt(label, "%"LV_PRId32, lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);/*Alinha o topo do slider*/
}

/**
*Crie um controle deslizante e escreva seu valor em um rótulo.
*/
void lv_example_get_started_3(void)
{
/*Cria um controle deslizante no centro da tela*/

    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_obj_set_width(slider, 200);//Define a largura
    lv_obj_center(slider);//Alinha ao centro do pai (tela)*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);/*Atribuir uma função de evento*/
  

/*Cria um rótulo acima do controle deslizante*/
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);/*Alinha o topo do slider*/


 lv_disp_set_bg_color(NULL, lv_color_black());
  lv_disp_set_bg_opa(NULL, LV_OPA_COVER);

String LVGL_Arduino = "SALA RIO DE JANEIRO";
  //LVGL_Arduino += String('v') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  lv_obj_t *label = lv_label_create(lv_scr_act()); // full screen as the parent
   // set label text
  lv_label_set_text(label, LVGL_Arduino.c_str()); 
  lv_label_set_text(label, LV_FONT_MONTSERRAT_40); 
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);   // Center but 20 from the top


}

void setup() {
  Serial.begin(115200);

  tft.begin();
  tft.setRotation(3);
  tft.setBrightness(255);
  // tft.setBaseColor(0xFF0000U);//NOVO
  // tft.setColor(0x0000FFU);//NOVO
  // tft.fillScreen(0xFF0000U);
  

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
 
 

  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touch_read;
  lv_indev_drv_register(&indev_drv);

 
    
    
    lv_example_get_started_3();
}


void loop() {
  lv_timer_handler();
  delay(5);
}





