Configuration docs:
<https://docs.qmk.fm/tap_hold>
<https://docs.qmk.fm/features/mouse_keys>

Keyboard plan:

- rgpb tuning, layer specific
- Setup tap hold homerow mods
- Norwegian letters from english layout?
- Setup symbols layer
- Setup navigation layer
- Setup F# layer
- Setup media keys layer
- Test autoshift
- Test capsword
- Consider leader key

Done:

- Config:
  - reduce tapping term in config
  - use permissive hold
- On default layer:
  - Make CapsLock into Ctrl on hold, Esc on tap
  - Make Tab into Meta-layer on hold, Tab on tap
- On fn layer:
  - Add capslock to fn layer
  - Add tab to fn layer
- On meta layer (for layout shifting without thumb cluster)
  - Add metalayer
- On all custom layers
  - esc = to-default-layer
  - caps-lock = to-default-layer
  - tab = meta layer
  - stop fall-through of unmapped keys
- Add numbers layer (N)
  - Trigger on meta layer with tab+N
- Add mouse layer (M)
  - Trigger on meta layer with tab+M

|Modifier  |Description                             |
|----------|----------------------------------------|
|`MOD_LCTL`|Left Control                            |
|`MOD_LSFT`|Left Shift                              |
|`MOD_LALT`|Left Alt                                |
|`MOD_LGUI`|Left GUI (Windows/Command/Meta key)     |
|`MOD_RCTL`|Right Control                           |
|`MOD_RSFT`|Right Shift                             |
|`MOD_RALT`|Right Alt (AltGr)                       |
|`MOD_RGUI`|Right GUI (Windows/Command/Meta key)    |
|`MOD_HYPR`|Hyper (Left Control, Shift, Alt and GUI)|
|`MOD_MEH` |Meh (Left Control, Shift, and Alt)      |

Key Description
DF(layer) Set the base (default) layer
MO(layer) Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)
OSL(layer) Momentarily activates layer until a key is pressed. See One Shot Keys for details.
LM(layer, mod) Momentarily turn on layer (like MO) with mod active as well. Where mod is a mods_bit. Mods can be viewed here. Example Implementation: LM(LAYER_1, MOD_LALT)
LT(layer, kc) Turn on layer when held, kc when tapped
TG(layer) Toggle layer on or off
TO(layer) Turns on layer and turns off all other layers, except the default layer
TT(layer) Normally acts like MO unless it's tapped multiple times, which toggles layer on

Layershift ideas (make b/n layer-tap keys):
' æ
; ø
\[ å

asdfg 1-5
hjkl; 6-0

colliding at 0

q \`
w \
e \[
r \]
t |

u {
i }

-\_
=+
