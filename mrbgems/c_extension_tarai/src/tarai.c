#include <mruby.h>
#include <stdio.h>
#include "mruby/variable.h"

/* Original tak function */
mrb_int tak(mrb_int x, mrb_int y, mrb_int z)
{
    if (x <= y) {
        return z;
    } else {
        tak(tak(x-1, y, z), tak(y-1, z, x), tak(z-1, x, y));
    }
}

/* Takeuchi's tarai function */
mrb_int tarai(mrb_int x, mrb_int y, mrb_int z)
{
    if (x <= y) {
        return y;
    } else {
        tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y));
    }
}

static mrb_value
mrb_c_tak(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, z;
    mrb_get_args(mrb, "iii", &x, &y, &z);
    return mrb_fixnum_value(tak(x, y, z));
}

static mrb_value
mrb_c_tarai(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, z;
    mrb_get_args(mrb, "iii", &x, &y, &z);
    return mrb_fixnum_value(tarai(x, y, z));
}

void
mrb_c_extension_tarai_gem_init(mrb_state* mrb) {
  struct RClass *class_ctarai = mrb_define_module(mrb, "CTarai");
  mrb_define_class_method(mrb, class_ctarai, "tak", mrb_c_tak, ARGS_REQ(3));
  mrb_define_class_method(mrb, class_ctarai, "tarai", mrb_c_tarai, ARGS_REQ(3));
}

void
mrb_c_extension_tarai_gem_final(mrb_state* mrb) {
}
