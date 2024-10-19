
RGB_MATRIX_EFFECT(gaming)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


 
static bool gaming(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
  }

  rgb_matrix_set_color(16, 0x00, 0xff, 0xff);
  rgb_matrix_set_color(17, 0xff, 0xff, 0x00);
  rgb_matrix_set_color(18, 0x00, 0xff, 0xff);
  rgb_matrix_set_color(31, 0xff, 0xff, 0x00);
  rgb_matrix_set_color(32, 0xff, 0xff, 0x00);
  rgb_matrix_set_color(33, 0xff, 0xff, 0x00);
  rgb_matrix_set_color(61, 0xff, 0xff, 0x00);
  return rgb_matrix_check_finished_leds(led_max);
}

#endif