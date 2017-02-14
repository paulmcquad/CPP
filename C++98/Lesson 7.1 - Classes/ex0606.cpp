// Example 6-6: Using bit-fields for a control word.
// Intel x87 FPU control word.
struct fpu_control {
  enum precision_control { single, double_prec=2, extended };
  enum rounding_control  { nearest, down, up, truncate };
  int                            : 4; // reserved
  rounding_control  round_ctl    : 2;
  precision_control prec_ctl     : 2;
  int                            : 2; // reserved
  bool              precision    : 1;
  bool              underflow    : 1;
  bool              overflow     : 1;
  bool              zero_divide  : 1;
  bool              denormal     : 1;
  bool              invalid_op   : 1;
};
