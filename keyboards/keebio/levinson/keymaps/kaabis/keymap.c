#include QMK_KEYBOARD_H

// regex for finding layer comments: ((?<=\*\s)[\.|')].*)|((?<=^\[)\w+)
// optional formatting:
// 1. search for '$
// 2. replace by '\n

// ANCHOR - Layers
enum my_layers {
  MAIN = 0, LSPCE, TVPNT,
  UMLUT, CHAR, NUMP, FROW,
  NUMB, HTKEY, HUB, SECR
};

// ANCHOR - Macro declarations
enum custom_keycodes {
  HMAIL = SAFE_RANGE, GMAIL, ADBE_AE, PATH2EX, P2EJLSY,
  MY_RSET,
  MY_DOT, MY_COMM, MY_QUES, MY_QUOT, MY_QUOT_TG, MY_SPMIN, MY_CURR,
  MY_INS, PAUSE, OSM_ESC, LAYR_TG, MOUSE_U, MOUSE_D,
  TVP_DESL, PS_B, PS_E, PS_B_E,
  COUNT_UP
};

// ANCHOR - Unicode Map
enum unicode_names {
    AE_S, AE_L,
    OE_S, OE_L,
    UE_S, UE_L,
    AGRV_S, AGRV_L,
    EACU_S, EACU_L,
    EGRV_S, EGRV_L,
    OCIR_S, OCIR_L,
    SGER,
    GUIL_L, GUIL_R,
    BULLET,
    CCOPYR, REGIST,
    E_SQ_R, E_TICK, E_THUP
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_S]   = 0x00E4,  // ä
    [AE_L]   = 0x00C4,  // Ä
    [OE_S]   = 0x00F6,  // ö
    [OE_L]   = 0x00D6,  // Ö
    [UE_S]   = 0x00FC,  // ü
    [UE_L]   = 0x00DC,  // Ü
    [AGRV_S] = 0x00E0,  // à
    [AGRV_L] = 0x00C0,  // À
    [EACU_S] = 0x00E9,  // é
    [EACU_L] = 0x00C9,  // É
    [EGRV_S] = 0x00E8,  // è
    [EGRV_L] = 0x00C8,  // È
    [OCIR_S] = 0x00F4,  // ô
    [OCIR_L] = 0x00D4,  // Ô
    [SGER]   = 0x00DF,  // ß
    [GUIL_L] = 0x00AB,  // «
    [GUIL_R] = 0x00BB,  // »
    [BULLET] = 0x2022,  // •
    [CCOPYR] = 0x00A9,  // ©
    [REGIST] = 0x00AE,  // ®
    [E_SQ_R] = 0x1F7E5, // 🟥
    [E_TICK] = 0x2705,  // ✅
    [E_THUP] = 0x1F44D  // 👍
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// LAYER - Main
[MAIN] = LAYOUT_ortho_4x12( \
  LT(HTKEY,KC_ESC), KC_Q,    KC_W,            KC_E,           KC_R,   KC_T,            KC_Y,            KC_U,  KC_I,             KC_O,    KC_P,              KC_BSPC,        \
  LGUI_T(KC_TAB),   KC_A,    KC_S,            KC_D,           KC_F,   KC_G,            KC_H,            KC_J,  KC_K,             KC_L,    LT(UMLUT,KC_MINS), KC_ENT,         \
  KC_LSFT,          KC_Z,    KC_X,            KC_C,           KC_V,   KC_B,            KC_N,            KC_M,  MY_COMM,          MY_DOT,  MY_QUES,           RSFT_T(KC_UP),  \
  OSL(HTKEY),       KC_LALT, LT(HUB,KC_LGUI), CTL_T(KC_BSPC), KC_SPC, LT(NUMB,KC_ENT), LT(CHAR,KC_SPC), KC_NO, LT(NUMP,KC_LEFT), KC_RALT, LT(FROW,KC_RIGHT), RCTL_T(KC_DOWN) \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * |E|HTKEY| Q     | W     | E     | R     | T     | | Y     | U     | I     | O     | P     | Bksp  |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |Tab|Gui| A     | S     | D     | F     | G     | | H     | J     | K     | L     |-|UMLUT| Enter |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | Shift | Z     | X     | C     | V     | B     | | N     | M     |  , ;  |  . :  |  ? !  |Up|Shft|
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | HTKEY | Alt   |Gui|HUB|Bsp|Ctl| Space |En|NUMB| |  Space|CHAR   |Le|NUMP| Alt   |Ri|FROW|Do|Ctrl|
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Space
[LSPCE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, SFT_T(KC_SPC), _______, _______, _______, _______, _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ | _____ | _____ | _____ | _____ | _____ | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ |Spc|Sft| _____ | | _____________ | _____ | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - TvPaint
[TVPNT] = LAYOUT_ortho_4x12( \
  _______, KC_COMM, S(KC_S), C(KC_LEFT), C(KC_RIGHT), LCA_T(KC_H), KC_LBRC, _______, _______, _______, _______, _______, \
  _______, C(KC_L), C(KC_B), S(KC_E),    KC_U,        ALT_T(KC_D), KC_F,    _______, _______, _______, _______, _______, \
  _______, C(KC_R), S(KC_L), KC_T,       TVP_DESL,    S(KC_K),     KC_A,    _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,    _______,     _______,     _______, KC_NO,   _______, _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ |Pick L.| Save  |Prev I.|Next I.|{Rota.}| | FlipX | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |OniSkin|{Break}|TgBrush| Undo  |Pan/Br.| | Fill  | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |{Invrt}|{Lasso}|{Move }|Desl+Br| Clear | | Shake | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | | _____________ | _____ | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 * {}: in TVPaint, those features don't have shortcuts assigned by default.
 */
// LAYER - Umlaut
[UMLUT] = LAYOUT_ortho_4x12( \
  _______, _______,           _______, XP(EACU_S,EACU_L), X(REGIST), _______,   _______, XP(UE_S,UE_L), X(E_THUP), XP(OE_S,OE_L),     _______, _______,   \
  _______, XP(AE_S,AE_L),     X(SGER), XP(EGRV_S,EGRV_L), _______,   _______,   _______, X(GUIL_L),     X(GUIL_R), XP(OCIR_S,OCIR_L), _______, X(BULLET), \
  _______, XP(AGRV_S,AGRV_L), _______, X(CCOPYR),         _______,   _______,   _______, _______,       _______,   _______,           _______, _______,   \
  _______, _______,           _______, _______,           X(E_SQ_R), X(E_TICK), _______, KC_NO,         _______,   _______,           _______, _______    \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ | _____ | _____ |  é É  |  (R)  | _____ | | _____ |  ü Ü  | TH.UP |  ö Ö  | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |  ä Ä  |  ß    |  è È  | _____ | _____ | | _____ |   «   |   »   |  ô Ô  |[UMLUT]|   •   |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |  à À  | _____ |  (c)  | _____ | _____ | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | SQU.R | TICK  | | _____________ | _____ | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Characters
[CHAR] = LAYOUT_ortho_4x12( \
  _______, KC_BSLS,  KC_PIPE, KC_LBRC, KC_LPRN, KC_LCBR, KC_SLSH, MY_QUOT, KC_UP,   KC_LABK, KC_RABK,  KC_DEL,  \
  _______, KC_PERC,  KC_AMPR, KC_RBRC, KC_RPRN, KC_RCBR, KC_AT,   KC_LEFT, KC_DOWN, KC_RGHT, MY_SPMIN, _______, \
  _______, KC_TILDE, KC_GRAVE, KC_HASH, KC_PLUS, KC_ASTR, DM_PLY1, DM_PLY2, KC_EQL,  KC_CIRC, MY_CURR,  _______, \
  _______, _______,  _______,  _______, _______, _______, _______, KC_NO,   KC_SPC,  _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ |   \   |   |   |   [   |   (   |   {   | |   /   |  ' "  | up    |   <   |   >   | Del   |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |   %   |   &   |   ]   |   )   |   }   | |   @   | left  | down  | right |  ‒ -> | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |   ~   |   `   |   #   |   +   |   *   | | Macr1 | Macr2 |   =   |   ^   |  $ €  | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | |[  CHARACTER  ]| Space | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Numpad
[NUMP] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_P7,   KC_P8, KC_P9,            KC_PAST, \
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_PEQL, KC_P4,   KC_P5, KC_P6,            KC_PENT, \
  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_P1,   KC_P2, KC_P3,            KC_PPLS, \
  _______, _______, _______, _______, _______, _______, KC_RALT, KC_NO,   _______, KC_P0, LT(FROW,KC_PDOT), KC_PMNS  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ | _____ | _____ | _____ | _____ | _____ | |NumLock| Num/  | Num7  | Num8  | Num9  | Num*  |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | |       | Num=  | Num4  | Num5  | Num6  |*NEnt *|
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | |       |       | Num1  | Num2  | Num3  | Num+  |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | |      Alt      |[NUMP ]| Num0  |*Num. *| Num-  |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - FRow
[FROW] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12, \
  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11, \
  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10, \
  _______, _______, _______, _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | _____ | _____ | _____ | _____ | _____ | _____ | |       |       | F7    | F8    | F8    | F12   |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____________ | _____ | _____ | |       |       | F4    | F5    | F6    | F11   |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____________ | _____ | _____ | |       |       | F1    | F2    | F3    | F10   |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | _____ | _____ | _____ | |     _____     | _____ | _____ |[FROW ]| _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Numbers
[NUMB] = LAYOUT_ortho_4x12( \
  KC_HOME, KC_END,  KC_7,    KC_8,    KC_9,   COUNT_UP, _______, _______, _______, _______, _______, _______, \
  KC_PGUP, KC_PGDN, KC_4,    KC_5,    KC_6,   KC_0,     _______, _______, _______, _______, _______, _______, \
  _______, XXXXXXX, KC_1,    KC_2,    KC_3,   KC_DOT,   _______, _______, KC_SCLN, KC_COLN, KC_EXLM, _______, \
  _______, _______, _______, KC_DEL, XXXXXXX, _______,  _______, KC_NO,   _______, _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * | home  | end   | 7     | 8     | 9     |Count+1| | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | pgUp  | pgDwn | 4     | 5     | 6     | 0     | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ |       | 1     | 2     | 3     | .     | | _____ | _____ |   ;   |   :   |   !   | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * | _____ | _____ | _____ | Del   |       |[NUMB ]| | _____________ | _____ | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Hotkeys (+ Left Mirrored)
[HTKEY] = LAYOUT_ortho_4x12( \
  OSM_ESC,                KC_P,                   KC_O,    KC_I,    KC_U,    KC_Y,                            _______,   _______, _______, _______, _______, _______, \
  XXXXXXX,                KC_MINS,                KC_L,    KC_K,    KC_J,    KC_H,                            _______,   _______, _______, _______, _______, _______, \
  OSM(MOD_LCTL|MOD_LSFT), MY_QUES,                MY_DOT,  MY_COMM, KC_M,    KC_N,                            _______,   _______, _______, _______, _______, _______, \
  _______,                OSM(MOD_LCTL|MOD_LALT), C(KC_X), C(KC_C), C(KC_V), OSM(MOD_LCTL|MOD_LALT|MOD_LSFT), OSL(SECR), KC_NO,   _______, _______, _______, _______  \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * |EscHTKY| P     | O     | I     | U     | Y     | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |       |   -   | L     | K     | J     | H     | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |Ctl+Sft|  ? !  |  . :  |  , ;  | M     | N     | | _____ | _____ | _____ | _____ | _____ | _____ |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |[HTKEY]|Ctl+Alt| Cut   | Copy  | Paste |Ctl+A+S| |     SECRET    | _____ | _____ | _____ | _____ |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Hub
[HUB] = LAYOUT_ortho_4x12( \
  MY_RSET,    DM_PLY1,      DM_PLY2,   TO(TVPNT), XXXXXXX,   KC_BRIU, DM_RSTP, MY_QUOT_TG, MOUSE_U,  XXXXXXX, KC_SLEP, LALT(KC_F4), \
  G(KC_TAB),  C(S(KC_TAB)), C(KC_TAB), XXXXXXX,   KC_UP,     KC_BRID, KC_BTN1, KC_BTN2,    MOUSE_D,  XXXXXXX, XXXXXXX, MY_INS,      \
  XXXXXXX,    KC_VOLD,      KC_VOLU,   KC_LEFT,   KC_DOWN,   KC_RGHT, DM_REC1, DM_REC2,    PAUSE,    XXXXXXX, XXXXXXX, KC_CAPS,     \
  G(KC_PSCR), KC_MUTE,      _______,   KC_MPLY,   TG(LSPCE), KC_PENT, XXXXXXX, KC_NO,      TG(NUMP), XXXXXXX, XXXXXXX, XXXXXXX      \
),
/* .-----------------------------------------------. .-----------------------------------------------.
 * |ResetKB| Macr1 | Macr2 | TVPNT |       | Br +  | | StopR | Tgl" '|Mouse +|       | Sleep | Exit  |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |Gui+Tab| < Tab | Tab > |       | up    | Br -  | | LMB   | RMB   |Mouse –|       |       | Insrt |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |       | Vol - | Vol + | left  | down  | right | | RecM1 | RecM2 |+ Pause|       |       | Caps  |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |PrntScr| Mute  |[ HUB ]|M. Play|Tgl Spc|NumEnt | |               |LckNUMP|       |       |       |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
// LAYER - Secret
[SECR] = LAYOUT_ortho_4x12( \
  XXXXXXX, XXXXXXX, XXXXXXX, PATH2EX, P2EJLSY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, ADBE_AE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, HMAIL,   GMAIL,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)
/* .-----------------------------------------------. .-----------------------------------------------.
 * |       |       |       |Path2Ex|P2EjlsY|       | |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |       |AfterEf|       |       |       |       | |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |       |       | Hmail | Gmail |       |       | |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |       |       |( Hub )|       |       |       | |    [SECRET]   |       |       |       |       |
 * '-----------------------------------------------' '-----------------------------------------------'
 */
};

// ANCHOR - Variables
static bool shift_held = false; // Shift being held? Let's store this in a bool.

// bool for MY_INS
bool my_ins_on = false;

// bool for the MY_QUOT and MY_QUOT_TG keys
bool my_quot_switched_default = true;
bool my_quot_switched = true;


bool ps_eraser = false;

// last used macro layer
static bool inside_macro = false;
int last_macro_layer = 0;


// ANCHOR - Macro functions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case HMAIL:
        if (record->event.pressed) SEND_STRING("dan.wenger@hotmail.com");
        break;
    case GMAIL:
        if (record->event.pressed) SEND_STRING("uptodan@gmail.com");
        break;
    case ADBE_AE:
        if (record->event.pressed) SEND_STRING("after effects");
        break;
    case PATH2EX: // Open selected Path in Windows Explorer
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")); // copy path
            SEND_STRING(SS_LGUI("e")); // open explorer
            _delay_ms(1000); // wait for explorer to startup
        }
        else {
            SEND_STRING(SS_LCTL("l")); // focus on explorer path
            SEND_STRING(SS_LCTL("v")); // paste path
            tap_code(KC_ENT); // enter
        }
        break;
    case P2EJLSY: // Open selected Path in Windows Explorer (jls Y: to VPN Path)
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c")); // copy path
            SEND_STRING(SS_LGUI("e")); // open explorer
            _delay_ms(1000); // wait for explorer to startup
        }
        else {
            SEND_STRING(SS_LCTL("l")); // focus on explorer path
            SEND_STRING(SS_LCTL("v")); // paste path
            // delete first two characters (Y:)
            tap_code(KC_HOME);
            tap_code(KC_DEL);
            tap_code(KC_DEL);
            // replace with jls local path
            SEND_STRING("\\\\jlsstgb.jls.local\\Content_Services");

            tap_code(KC_ENT); // enter
        }
        break;
    case MY_SPMIN: // ‒ / ->
        if (record->event.pressed) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            if (shift_held) {
                SEND_STRING("->");
            } else {
                send_unicode_string("–"); // -> GEDSTR
            }
        }
        break;
    case MY_RSET:
        if (record->event.pressed) {
            layer_clear(); // turns off any locked layers and returns to MAIN
            clear_oneshot_mods(); // resets any OSModifiers that may be pressed

            my_quot_switched = my_quot_switched_default; // sets quote order back to default
            if (my_ins_on) { // disables Insert Mode
                my_ins_on = false;
                tap_code(KC_INS);
            }
            clear_keyboard(); // ...just to be safe
        }
        break;
    case KC_LSFT:
        shift_held = record->event.pressed;
        return true;
        break;
    case KC_RSFT:
        shift_held = record->event.pressed;
        return true;
        break;
    case SFT_T(KC_SPC):
        shift_held = record->event.pressed;
        return true;
        break;
    case MY_DOT: // . :
        if (record->event.pressed) {
            if (shift_held) {
                register_code(KC_SCLN);
            } else {
                register_code(KC_DOT);
            }
        }
        else {
            unregister_code(KC_SCLN);
            unregister_code(KC_DOT);
        }
        break;
    case MY_COMM: // , ;
        if (record->event.pressed) {
            if (shift_held) {
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                register_code(KC_SCLN);
            } else {
                register_code(KC_COMM);
            }
        }
        else {
            unregister_code(KC_SCLN);
            unregister_code(KC_COMM);
        }
        break;
    case MY_QUES: // ? !
        if (record->event.pressed) {
            if (shift_held) {
                register_code(KC_1);
            } else {
                register_code(KC_LSFT);
                register_code(KC_SLSH);
            }
        }
        else {
            if (!shift_held) {
                unregister_code(KC_LSFT);
            }
            unregister_code(KC_1);
            unregister_code(KC_SLSH);
        }
        break;
    case MY_QUOT: // ' " (or " ')
        if (record->event.pressed) {
            if (my_quot_switched) {
                if (shift_held) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    register_code(KC_QUOT);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_QUOT);
                }
            } else {
                register_code(KC_QUOT);
            }
        }
        else {
            if (my_quot_switched) {
                if (shift_held) {
                    register_code(KC_LSFT);
                } else {
                    unregister_code(KC_LSFT);
                }
            }
            unregister_code(KC_QUOT);
        }
        break;
    case MY_QUOT_TG: // switches Quote shift order
        if (record->event.pressed) {
            my_quot_switched = !my_quot_switched;
        }
        break;
    case MY_CURR: // $ €
        if (record->event.pressed) {
            if (shift_held) {
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                register_code(KC_RALT);      // €
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P8);
                unregister_code(KC_RALT);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_4); // $
            }
        }
        break;
    case MY_INS: // Handles Insert Key press
        if (record->event.pressed) {
            my_ins_on = !my_ins_on;
            tap_code(KC_INS);
        }
        break;
    case PAUSE: // short delay for macro recording
        if (record->event.pressed) {
            _delay_ms(250);
        }
        break;
    case OSM_ESC: // cancel OSM action
        if (record->event.pressed) {
            clear_oneshot_mods();
        }
        break;
    case LAYR_TG: // Toggles between MAIN and last macro layer (determined by "last_macro_layer")
        if (record->event.pressed) {
            if (inside_macro) {
                inside_macro = false;
                layer_off(TVPNT);
                tap_code(KC_LGUI);
            }
            else {
                switch (last_macro_layer) {
                    case 1:
                        layer_on(TVPNT);
                        break;
                }
            }
        }
        break;
    case MOUSE_U: // clicks, moves cursor up an increment
        if (record->event.pressed) {
            register_code(KC_MS_BTN1);
            tap_code(KC_MS_U);
        }
        else {
            unregister_code(KC_MS_BTN1);
            tap_code(KC_MS_D);
        }
        break;
    case MOUSE_D: // clicks, moves cursor down an increment
        if (record->event.pressed) {
            register_code(KC_MS_BTN1);
            tap_code(KC_MS_D);
        }
        else {
            unregister_code(KC_MS_BTN1);
            tap_code(KC_MS_U);
        }
        break;
    case TVP_DESL: // Delesect & Switch to Brush
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("d")"d");
        }
        break;
    case PS_B: // Brush (with boolean set)
        if (record->event.pressed) {
            ps_eraser = false;
            register_code(KC_B);
        }
        else {
            unregister_code(KC_B);
        }
        break;
    case PS_E: // Eraser (with boolean set)
        if (record->event.pressed) {
            ps_eraser = true;
            register_code(KC_E);
        }
        else {
            unregister_code(KC_E);
        }
        break;
    case PS_B_E: // Switch between Brush and Eraser
        if (record->event.pressed) {
            if (ps_eraser) {
                register_code(KC_B);
            } else {
                register_code(KC_E);
            }
        }
        else {
            if (ps_eraser) {
                unregister_code(KC_B);
                ps_eraser = false;
            } else {
                unregister_code(KC_E);
                ps_eraser = true;
            }
        }
        break;
    case COUNT_UP:
        if (record->event.pressed) {
            SEND_STRING("NEW KEY");
        }
        break;
    }
    return true;
}

// ANCHOR - tap/hold config per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCA_T(KC_H): //tvp rotate/reset rot.
            return 90;
        case ALT_T(KC_D): //tvp pan/brush
            return 90;
        default:
            return TAPPING_TERM;
    }
}

// ANCHOR - set last used macro layer variables
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case TVPNT:
        inside_macro = true;
        last_macro_layer = 1;
        break;
    }
  return state;
}
