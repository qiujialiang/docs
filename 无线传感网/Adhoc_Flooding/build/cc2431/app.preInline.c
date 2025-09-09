#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 47 "/opt/tinyos-2.x/tos/chips/mcs51/keil_stdint.h"
typedef signed char int8_t;
typedef short int16_t;



typedef long int32_t;


typedef long long int int64_t;




typedef unsigned char uint8_t;
typedef unsigned short uint16_t;



typedef unsigned long uint32_t;


typedef unsigned long long int uint64_t;
# 43 "/opt/tinyos-2.x/tos/chips/mcs51/stdint.h"
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int_least32_t;









typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned long uint_least32_t;
#line 71
typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;





typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
# 106 "/opt/tinyos-2.x/tos/chips/mcs51/stdint.h" 3
typedef int intptr_t;


typedef unsigned int uintptr_t;









typedef long long int intmax_t;

typedef unsigned long long int uintmax_t;
# 231 "/usr/include/inttypes.h"
#line 228
typedef struct __nesc_unnamed4242 {
  intmax_t quot;
  intmax_t rem;
} imaxdiv_t;
# 385 "/usr/lib/ncc/nesc_nx.h"
typedef struct { char data[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { char data[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { char data[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { char data[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { char data[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { char data[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { char data[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { char data[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { char data[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { char data[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { char data[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { char data[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { char data[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { char data[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { char data[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { char data[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 213 "/usr/lib/gcc-lib/i686-pc-cygwin/3.3.3/include/stddef.h" 3
typedef unsigned int size_t;
# 43 "/usr/lib/gcc-lib/i686-pc-cygwin/3.3.3/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
# 14 "/usr/include/sys/lock.h"
typedef void *_LOCK_T;
# 14 "/usr/include/sys/_types.h"
typedef long _off_t;
__extension__ 
#line 15
typedef long long _off64_t;


typedef int _ssize_t;
# 354 "/usr/lib/gcc-lib/i686-pc-cygwin/3.3.3/include/stddef.h" 3
typedef unsigned int wint_t;
# 35 "/usr/include/sys/_types.h"
#line 27
typedef struct __nesc_unnamed4243 {

  int __count;
  union __nesc_unnamed4244 {

    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;

typedef _LOCK_T _flock_t;


typedef void *_iconv_t;
# 19 "/usr/include/sys/reent.h"
typedef unsigned long __ULong;
# 40 "/usr/include/sys/reent.h" 3
struct _Bigint {

  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm {

  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
  void *_fnargs[32];
  void *_dso_handle[32];

  __ULong _fntypes;


  __ULong _is_cxa;
};









struct _atexit {
  struct _atexit *_next;
  int _ind;

  void (*_fns[32])(void );
  struct _on_exit_args _on_exit_args;
};









struct __sbuf {
  unsigned char *_base;
  int _size;
};






typedef long _fpos_t;



typedef _off64_t _fpos64_t;
#line 166
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void *_cookie;

  _ssize_t __attribute((__cdecl__)) (*_read)(void *_cookie, char *_buf, int _n);
  _ssize_t __attribute((__cdecl__)) (*_write)(void *_cookie, const char *_buf, int _n);

  _fpos_t __attribute((__cdecl__)) (*_seek)(void *_cookie, _fpos_t _offset, int _whence);
  int __attribute((__cdecl__)) (*_close)(void *_cookie);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  int _offset;


  struct _reent *_data;



  _flock_t _lock;
};



struct __sFILE64 {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;

  struct _reent *_data;


  void *_cookie;

  _ssize_t __attribute((__cdecl__)) (*_read)(void *_cookie, char *_buf, int _n);
  _ssize_t __attribute((__cdecl__)) (*_write)(void *_cookie, const char *_buf, int _n);

  _fpos_t __attribute((__cdecl__)) (*_seek)(void *_cookie, _fpos_t _offset, int _whence);
  int __attribute((__cdecl__)) (*_close)(void *_cookie);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  int _flags2;

  _off64_t _offset;
  _fpos64_t __attribute((__cdecl__)) (*_seek64)(void *_cookie, _fpos64_t _offset, int _whence);


  _flock_t _lock;
};

typedef struct __sFILE64 __FILE;




struct _glue {

  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
#line 290
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};
#line 565
struct _reent {

  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];

  int _current_category;
  const char *_current_locale;

  int __sdidinit;

  void __attribute((__cdecl__)) (*__cleanup)(struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union __nesc_unnamed4245 {

    struct __nesc_unnamed4246 {

      unsigned int _unused_rand;
      char *_strtok_last;
      char _asctime_buf[26];
      struct __tm _localtime_buf;
      int _gamma_signgam;
      __extension__ unsigned long long _rand_next;
      struct _rand48 _r48;
      _mbstate_t _mblen_state;
      _mbstate_t _mbtowc_state;
      _mbstate_t _wctomb_state;
      char _l64a_buf[8];
      char _signal_buf[24];
      int _getdate_err;
      _mbstate_t _mbrlen_state;
      _mbstate_t _mbrtowc_state;
      _mbstate_t _mbsrtowcs_state;
      _mbstate_t _wcrtomb_state;
      _mbstate_t _wcsrtombs_state;
    } _reent;



    struct __nesc_unnamed4247 {


      unsigned char *_nextf[30];
      unsigned int _nmalloc[30];
    } _unused;
  } _new;


  struct _atexit *_atexit;
  struct _atexit _atexit0;


  void (**_sig_func)(int );




  struct _glue __sglue;
  __FILE __sf[3];
};
#line 799
struct _reent;
struct _reent;









struct _reent;
# 48 "/opt/tinyos-2.x/tos/platforms/cc2431/stdio.h"
typedef _off_t off_t;
typedef _ssize_t ssize_t;



typedef __FILE FILE;



typedef _fpos64_t fpos_t;
# 11 "/opt/tinyos-2.x/tos/chips/mcs51/string.h"
extern void *memcpy(void *s1, void *s2, int n);
# 325 "/usr/lib/gcc-lib/i686-pc-cygwin/3.3.3/include/stddef.h" 3
typedef short unsigned int wchar_t;
# 28 "/usr/include/stdlib.h"
#line 24
typedef struct __nesc_unnamed4248 {

  int quot;
  int rem;
} div_t;





#line 30
typedef struct __nesc_unnamed4249 {

  long quot;
  long rem;
} ldiv_t;






#line 37
typedef struct __nesc_unnamed4250 {

  long long int quot;
  long long int rem;
} lldiv_t;
# 151 "/usr/lib/gcc-lib/i686-pc-cygwin/3.3.3/include/stddef.h" 3
typedef int ptrdiff_t;
# 27 "/opt/tinyos-2.x/tos/platforms/cc2431/tos.h"
typedef uint8_t bool  ;
enum __nesc_unnamed4251 {
#line 28
  FALSE = 0, TRUE = 1
};









typedef nx_int8_t nx_bool;
uint16_t TOS_NODE_ID = 1;





struct __nesc_attr_atmostonce {
};
#line 47
struct __nesc_attr_atleastonce {
};
#line 48
struct __nesc_attr_exactlyonce {
};
# 18 "/opt/tinyos-2.x/tos/platforms/cc2431/platform.h"
static inline unsigned short nx_16_t_change(unsigned short cvalue);
# 34 "/opt/tinyos-2.x/tos/types/TinyError.h"
enum __nesc_unnamed4252 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2);
# 210 "/opt/tinyos-2.x/tos/chips/mcs51/io8051.h"
 uint8_t volatile EA __attribute((sbitAT0xAF)) ;
#line 232
 uint8_t volatile P0_7 __attribute((sbitAT0x87)) ;
#line 247
 uint8_t volatile P1_2 __attribute((sbitAT0x92)) ;
 uint8_t volatile P1_3 __attribute((sbitAT0x93)) ;
 uint8_t volatile P1_4 __attribute((sbitAT0x94)) ;
# 67 "/opt/tinyos-2.x/tos/chips/cc2430/ioCC2430.h"
enum __nesc_unnamed4253 {
  CC2430_IEN0_EA = 0x7, 
  CC2430_IEN0_STIE = 0x5, 
  CC2430_IEN0_ENCIE = 0x4, 
  CC2430_IEN0_URX1IE = 0x3, 
  CC2430_IEN0_URX0IE = 0x2, 
  CC2430_IEN0_ADCIE = 0x1, 
  CC2430_IEN0_RFERRIE = 0x0
};





enum __nesc_unnamed4254 {
  CC2430_IEN1_P0IE = 0x5, 
  CC2430_IEN1_T4IE = 0x4, 
  CC2430_IEN1_T3IE = 0x3, 
  CC2430_IEN1_T2IE = 0x2, 
  CC2430_IEN1_T1IE = 0x1, 
  CC2430_IEN1_DMAIE = 0x0
};





enum __nesc_unnamed4255 {
  CC2430_IEN2_WDTIE = 0x5, 
  CC2430_IEN2_P1IE = 0x4, 
  CC2430_IEN2_UTX1IE = 0x3, 
  CC2430_IEN2_UTX0IE = 0x2, 
  CC2430_IEN2_P2IE = 0x1, 
  CC2430_IEN2_RFIE = 0x0
};





enum __nesc_unnamed4256 {
  CC2430_IRCON_STIF = 0x7, 
  CC2430_IRCON_P0IF = 0x5, 
  CC2430_IRCON_T4IF = 0x4, 
  CC2430_IRCON_T3IF = 0x3, 
  CC2430_IRCON_T2IF = 0x2, 
  CC2430_IRCON_T1IF = 0x1, 
  CC2430_IRCON_DMAIF = 0x0
};





enum __nesc_unnamed4257 {
  CC2430_IRCON2_WDTIF = 0x4, 
  CC2430_IRCON2_P1IF = 0x3, 
  CC2430_IRCON2_UTX1IF = 0x2, 
  CC2430_IRCON2_UTX0IF = 0x1, 
  CC2430_IRCON2_P2IF = 0x0
};





enum __nesc_unnamed4258 {
  CC2430_RFIM_RREG_PD = 0x7, 
  CC2430_RFIM_TXDONE = 0x6, 
  CC2430_RFIM_FIFOP = 0x5, 
  CC2430_RFIM_SFD = 0x4, 
  CC2430_RFIM_CCA = 0x3, 
  CC2430_RFIM_CSP_WT = 0x2, 
  CC2430_RFIM_CSP_STOP = 0x1, 
  CC2430_RFIM_CSP_INT = 0x0
};





enum __nesc_unnamed4259 {
  CC2430_RFIF_RREG_ON = 0x7, 
  CC2430_RFIF_TXDONE = 0x6, 
  CC2430_RFIF_FIFOP = 0x5, 
  CC2430_RFIF_SFD = 0x4, 
  CC2430_RFIF_CCA = 0x3, 
  CC2430_RFIF_CSP_WT = 0x2, 
  CC2430_RFIF_CSP_STOP = 0x1, 
  CC2430_RFIF_CSP_INT = 0x0
};






enum __nesc_unnamed4260 {
  CC2430_PICTL_PADSC = 0x6, 
  CC2430_PICTL_P2IEN = 0x5, 
  CC2430_PICTL_P0IENH = 0x4, 
  CC2430_PICTL_P0IENL = 0x3, 
  CC2430_PICTL_P2ICON = 0x2, 
  CC2430_PICTL_P1ICON = 0x1, 
  CC2430_PICTL_P0ICON = 0x0
};
#line 196
 uint8_t volatile U0CSR __attribute((sfrAT0x86)) ;










 uint8_t volatile URX1IF __attribute((sbitAT0x8F)) ;



 uint8_t volatile URX0IF __attribute((sbitAT0x8B)) ;

 uint8_t volatile RFERRIF __attribute((sbitAT0x89)) ;




 uint8_t volatile RFIM __attribute((sfrAT0x91)) ;









 uint8_t volatile IEN2 __attribute((sfrAT0x9A)) ;
 uint8_t volatile S1CON __attribute((sfrAT0x9B)) ;
#line 245
 uint8_t volatile RFERRIE __attribute((sbitAT0xA8)) ;

 uint8_t volatile URX0IE __attribute((sbitAT0xAA)) ;
 uint8_t volatile URX1IE __attribute((sbitAT0xAB)) ;
#line 266
 uint8_t volatile T3IE __attribute((sbitAT0xBB)) ;

 uint8_t volatile T1IE __attribute((sbitAT0xB9)) ;
#line 284
 uint8_t volatile SLEEP __attribute((sfrAT0xBE)) ;


 uint8_t volatile U0BUF __attribute((sfrAT0xC1)) ;
 uint8_t volatile U0BAUD __attribute((sfrAT0xC2)) ;

 uint8_t volatile U0UCR __attribute((sfrAT0xC4)) ;
 uint8_t volatile U0GCR __attribute((sfrAT0xC5)) ;
 uint8_t volatile CLKCON __attribute((sfrAT0xC6)) ;




 uint8_t volatile T3CNT __attribute((sfrAT0xCA)) ;
 uint8_t volatile T3CTL __attribute((sfrAT0xCB)) ;
 uint8_t volatile T3CCTL0 __attribute((sfrAT0xCC)) ;
 uint8_t volatile T3CC0 __attribute((sfrAT0xCD)) ;
 uint8_t volatile T3CCTL1 __attribute((sfrAT0xCE)) ;
 uint8_t volatile T3CC1 __attribute((sfrAT0xCF)) ;



 uint8_t volatile TIMIF __attribute((sfrAT0xD8)) ;







 uint8_t volatile T3CH0IF __attribute((sbitAT0xD9)) ;


 uint8_t volatile RFD __attribute((sfrAT0xD9)) ;

 uint8_t volatile T1CC0L __attribute((sfrAT0xDA)) ;
 uint8_t volatile T1CC0H __attribute((sfrAT0xDB)) ;
#line 336
 uint8_t volatile RFST __attribute((sfrAT0xE1)) ;

 uint8_t volatile T1CNTL __attribute((sfrAT0xE2)) ;
 uint8_t volatile T1CNTH __attribute((sfrAT0xE3)) ;
 uint8_t volatile T1CTL __attribute((sfrAT0xE4)) ;
 uint8_t volatile T1CCTL0 __attribute((sfrAT0xE5)) ;
 uint8_t volatile T1CCTL1 __attribute((sfrAT0xE6)) ;
 uint8_t volatile T1CCTL2 __attribute((sfrAT0xE7)) ;






 uint8_t volatile T3IF __attribute((sbitAT0xC3)) ;










 uint8_t volatile UTX1IF __attribute((sbitAT0xEA)) ;
 uint8_t volatile UTX0IF __attribute((sbitAT0xE9)) ;



 uint8_t volatile RFIF __attribute((sfrAT0xE9)) ;








 uint8_t volatile PERCFG __attribute((sfrAT0xF1)) ;



 uint8_t volatile U1CSR __attribute((sfrAT0xF8)) ;
 uint8_t volatile U1DBUF __attribute((sfrAT0xF9)) ;
 uint8_t volatile U1BAUD __attribute((sfrAT0xFA)) ;
 uint8_t volatile U1UCR __attribute((sfrAT0xFB)) ;
 uint8_t volatile U1GCR __attribute((sfrAT0xFC)) ;

 uint8_t volatile P0_DIR __attribute((sfrAT0xFD)) ;
 uint8_t volatile P1_DIR __attribute((sfrAT0xFE)) ;



 uint8_t volatile P0SEL __attribute((sfrAT0xF3)) ;


 uint8_t volatile P1SEL __attribute((sfrAT0xF4)) ;
#line 427
typedef uint16_t uint16_t_xdata;
typedef uint8_t uint8_t_xdata;

typedef uint16_t uint16_t_code;
typedef uint8_t uint8_t_code;
#line 516
enum __nesc_unnamed4261 {
  CC2430_RFPWR_ADI_RADIO_PD = 0x4, 
  CC2430_RFPWR_RREG_RADIO_PD = 0x3, 
  CC2430_RFPWR_RREG_DELAY = 0x0, 
  CC2430_RFPWR_RREG_DELAY_MASK = 0x7
};

enum __nesc_unnamed4262 {
  CC2430_RREG_DELAY_0 = 0x0, 
  CC2430_RREG_DELAY_31 = 0x1, 
  CC2430_RREG_DELAY_63 = 0x2, 
  CC2430_RREG_DELAY_125 = 0x3, 
  CC2430_RREG_DELAY_250 = 0x4, 
  CC2430_RREG_DELAY_500 = 0x5, 
  CC2430_RREG_DELAY_1000 = 0x6, 
  CC2430_RREG_DELAY_2000 = 0x7
};

enum __nesc_unnamed4263 {
  CC2430_MDMCTRL0L_AUTOCRC = 0x5, 
  CC2430_MDMCTRL0L_AUTOACK = 0x4
};

enum __nesc_unnamed4264 {
  CC2430_MDMCTRL0H_FRAME_FILT = 0x6, 
  CC2430_MDMCTRL0H_RESERVED_FRAME_MODE = 0x5, 
  CC2430_MDMCTRL0H_PAN_COORDINATOR = 0x4, 
  CC2430_MDMCTRL0H_ADDR_DECODE = 0x3, 
  CC2430_MDMCTRL0H_CCA_HYST = 0x0
};

enum __nesc_unnamed4265 {
  CC2430_RFSTATUS_TX_ACTIVE = 0x4, 
  CC2430_RFSTATUS_FIFO = 0x3, 
  CC2430_RFSTATUS_FIFOP = 0x2, 
  CC2430_RFSTATUS_SFD = 0x1, 
  CC2430_RFSTATUS_CCA = 0x0
};
# 101 "/opt/tinyos-2.x/tos/chips/mcs51/mcs51hardware.h"
typedef uint8_t __nesc_atomic_t;

static __inline void __nesc_disable_interrupt(void);



static __inline void __nesc_enable_interrupt(void);




__inline __nesc_atomic_t __nesc_atomic_start(void )  ;






__inline void __nesc_atomic_end(__nesc_atomic_t oldSreg)  ;
# 71 "/opt/tinyos-2.x/tos/chips/cc2430/timer/CC2430Timer.h"
enum __nesc_unnamed4266 {
  CC2430_SLEEP_OSC32K_CALDIS = 7, 
  CC2430_SLEEP_XOSC_STB = 6, 
  CC2430_SLEEP_HFRC_STB = 5, 
  CC2430_SLEEP_DIV = 3, 
  CC2430_SLEEP_OSC_PD = 2, 
  CC2430_SLEEP_MODE = 0, 
  CC2430_SLEEP_MODE_MASK = 3
};

enum __nesc_unnamed4267 {
  CC2430_SLEEP_POWERMODE_0 = 0, 
  CC2430_SLEEP_POWERMODE_1 = 1, 
  CC2430_SLEEP_POWERMODE_2 = 2, 
  CC2430_SLEEP_POWERMODE_3 = 3
};

enum __nesc_unnamed4268 {
  CC2430_CLKCON_OSC32K = 7, 
  CC2430_CLKCON_OSC = 6, 
  CC2430_CLKCON_TICKSPD = 3, 
  CC2430_CLKCON_CLKSPD = 0, 
  CC2430_CLKCON_TICKSPD_MASK = 0x38
};




enum cc2430_tick_spd_t {
  CC2430_TICKF_DIV_1 = 0x0 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_2 = 0x1 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_4 = 0x2 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_8 = 0x3 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_16 = 0x4 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_32 = 0x5 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_64 = 0x6 << CC2430_CLKCON_TICKSPD, 
  CC2430_TICKF_DIV_128 = 0x7 << CC2430_CLKCON_TICKSPD
};










enum __nesc_unnamed4269 {
  CC2430_T1CTL_CH2IF = 0x7, 
  CC2430_T1CTL_CH1IF = 0x6, 
  CC2430_T1CTL_CH0IF = 0x5, 
  CC2430_T1CTL_OVFIF = 0x4, 
  CC2430_T1CTL_DIV = 0x2, 
  CC2430_T1CTL_MODE = 0x0, 
  CC2430_T1CTL_MODE_MASK = 0x3, 
  CC2430_T1CTL_DIV_MASK = 0xc, 
  CC2430_T1CTL_IF_MASK = 0xf0
};






enum cc2430_timer1_mode_t {
  CC2430_TIMER1_MODE_OFF = 0x0 << CC2430_T1CTL_MODE, 
  CC2430_TIMER1_MODE_FREE = 0x1 << CC2430_T1CTL_MODE, 
  CC2430_TIMER1_MODE_MODULO = 0x2 << CC2430_T1CTL_MODE, 
  CC2430_TIMER1_MODE_UPDOWN = 0x3 << CC2430_T1CTL_MODE
};






enum cc2430_timer1_if_t {
  CC2430_T1_CH2IF = (unsigned char )(1 << CC2430_T1CTL_CH2IF), 
  CC2430_T1_CH1IF = (unsigned char )(1 << CC2430_T1CTL_CH1IF), 
  CC2430_T1_CH0IF = (unsigned char )(1 << CC2430_T1CTL_CH0IF), 
  CC2430_T1_OVFIF = (unsigned char )(1 << CC2430_T1CTL_OVFIF)
};





enum cc2430_timer1_prescaler_t {
  CC2430_TIMER1_DIV_1 = 0x0 << CC2430_T1CTL_DIV, 
  CC2430_TIMER1_DIV_8 = 0x1 << CC2430_T1CTL_DIV, 
  CC2430_TIMER1_DIV_32 = 0x2 << CC2430_T1CTL_DIV, 
  CC2430_TIMER1_DIV_128 = 0x3 << CC2430_T1CTL_DIV
};





enum __nesc_unnamed4270 {
  CC2430_T1CCTLx_CPSEL = 0x7, 
  CC2430_T1CCTLx_IM = 0x6, 
  CC2430_T1CCTLx_CMP = 0x3, 
  CC2430_T1CCTLx_MODE = 0x2, 
  CC2430_T1CCTLx_CAP = 0x0
};










enum cc2430_timerMAC_mode_t {
  CC2430_TIMERMAC_MODE_IDLE = 0x0, 
  CC2430_TIMERMAC_MODE_RUN = 0x1
};





enum cc2430_timerMAC_T2CNF_t {
  CC2430_T2CNF_CMPIF = 0x7, 
  CC2430_T2CNF_PERIF = 0x6, 
  CC2430_T2CNF_OFCMPIF = 0x5, 
  CC2430_T2CNF_CMSEL = 0x3, 
  CC2430_T2CNF_SYNC = 0x1, 
  CC2430_T2CNF_RUN = 0x0
};






enum cc2430_timerMAC_T2PEROF2_t {
  CC2430_T2PEROF2_CMPIM = 0x7, 
  CC2430_T2PEROF2_PERIM = 0x6, 
  CC2430_T2PEROF2_OFCMPIM = 0x5
};

enum cc2430_timerMAC_if_t {
  CC2430_TMAC_CMPIF = (unsigned char )(1 << CC2430_T2CNF_CMPIF), 
  CC2430_TMAC_PERIF = (unsigned char )(1 << CC2430_T2CNF_PERIF), 
  CC2430_TMAC_OFCMPIF = (unsigned char )(1 << CC2430_T2CNF_OFCMPIF)
};

enum cc2430_timerMAC_interval_t {
  CC2430_TIMERWDT_32768 = 0, 
  CC2430_TIMERWDT_8192 = 1, 
  CC2430_TIMERWDT_512 = 2, 
  CC2430_TIMERWDT_64 = 3
};
#line 240
enum __nesc_unnamed4271 {
  CC2430_TIMIF_OVFIM = 0x6
};

enum cc2430_timer34_if_t {
  CC2430_TIMIF_T4CH1IF = 0x5, 
  CC2430_TIMIF_T4CH0IF = 0x4, 
  CC2430_TIMIF_T4OVFIF = 0x3, 
  CC2430_TIMIF_T3CH1IF = 0x2, 
  CC2430_TIMIF_T3CH0IF = 0x1, 
  CC2430_TIMIF_T3OVFIF = 0x0
};






enum cc2430_timer3_4_mode_t {
  CC2430_TIMER3_4_MODE_FREE = 0x0, 
  CC2430_TIMER3_4_MODE_DOWN = 0x1, 
  CC2430_TIMER3_4_MODE_MODULO = 0x2, 
  CC2430_TIMER3_4_MODE_UPDOWN = 0x3
};





enum __nesc_unnamed4272 {
  CC2430_T34CTL_DIV = 0x5, 
  CC2430_T34CTL_START = 0x4, 
  CC2430_T34CTL_OVFIM = 0x3, 
  CC2430_T34CTL_WDTIF = 0x3, 
  CC2430_T34CTL_CLR = 0x2, 
  CC2430_T34CTL_MODE = 0x0, 
  CC2430_T34CTL_MODE_MASK = 0x3, 
  CC2430_T34CTL_DIV_MASK = 0xe0
};





enum cc2430_timer3_4_prescaler_t {
  CC2430_TIMER3_4_DIV_1 = 0x0 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_2 = 0x1 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_4 = 0x2 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_8 = 0x3 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_16 = 0x4 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_32 = 0x5 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_64 = 0x6 << CC2430_T34CTL_DIV, 
  CC2430_TIMER3_4_DIV_128 = 0x7 << CC2430_T34CTL_DIV
};










enum __nesc_unnamed4273 {
  CC2430_WDCTL_CLR = 0x4, 
  CC2430_WDCTL_EN = 0x3, 
  CC2430_WDCTL_MODE = 0x2, 
  CC2430_WDCTL_INT = 0x0, 
  CC2430_WDCTL_INT_MASK = 0x3
};

enum cc2430_timerWDT_mode_t {
  CC2430_TIMERWDT_MODE_WDT = 0x0 << CC2430_WDCTL_MODE, 
  CC2430_TIMERWDT_MODE_TIMER = 0x1 << CC2430_WDCTL_MODE
};
# 32 "Adhoc_APP.h"
#line 28
typedef struct __nesc_unnamed4274 {
  uint16_t App_Seq;
  uint16_t Sender_Addr;
  uint16_t App_Data[4];
} Adhoc_APP_Msg;

enum __nesc_unnamed4275 {
#line 34
  SERIAL_ADHOC = 10
};
# 29 "/opt/tinyos-2.x/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4276 {
} 
#line 29
TMilli;
typedef struct __nesc_unnamed4277 {
} 
#line 30
T32khz;
typedef struct __nesc_unnamed4278 {
} 
#line 31
TMicro;
# 30 "/opt/tinyos-2.x/tos/types/Leds.h"
enum __nesc_unnamed4279 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 25 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430.h"
#line 17
typedef struct cc2430_header_t {
  uint8_t length;
  uint16_t fcf;
  uint8_t dsn;
  uint16_t destpan;
  uint16_t dest;
  uint16_t src;
  uint8_t type;
} cc2430_header_t;



#line 27
typedef struct cc2430_footer_t {
  uint16_t crc;
} cc2430_footer_t;








#line 31
typedef struct cc2430_metadata_t {
  uint8_t tx_power;
  char rssi;
  uint8_t lqi;
  bool crc;
  bool ack;
  uint16_t time;
} cc2430_metadata_t;




#line 40
typedef struct cc2430_packet_t {
  cc2430_header_t packet;
  uint8_t data[28];
} cc2430_packet_t;
#line 87
enum ieee154_fcf_type_enums {
  IEEE154_TYPE_BEACON = 0, 
  IEEE154_TYPE_DATA = 1, 
  IEEE154_TYPE_ACK = 2, 
  IEEE154_TYPE_MAC_CMD = 3
};

enum iee154_fcf_addr_mode_enums {
  IEEE154_ADDR_NONE = 0, 
  IEEE154_ADDR_SHORT = 2, 
  IEEE154_ADDR_EXT = 3
};

enum ieee154_fcf_enums {
  IEEE154_FCF_FRAME_TYPE = 0, 
  IEEE154_FCF_SECURITY_ENABLED = 3, 
  IEEE154_FCF_FRAME_PENDING = 4, 
  IEEE154_FCF_ACK_REQ = 5, 
  IEEE154_FCF_INTRAPAN = 6, 
  IEEE154_FCF_DEST_ADDR_MODE = 10, 
  IEEE154_FCF_SRC_ADDR_MODE = 14
};
#line 121
enum __nesc_unnamed4280 {
#line 121
  RF_IDLE = 0x01, RF_TX = 0x02, RF_RX = 0x03
};
# 6 "/opt/tinyos-2.x/tos/types/AM.h"
typedef unsigned char nx_am_id_t;
typedef unsigned char nx_am_group_t;
typedef unsigned short nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4281 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4282 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 72 "/opt/tinyos-2.x/tos/platforms/cc2431/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4283 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4284 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4285 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 110
#line 98
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 112
typedef struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  unsigned char length;
  nx_am_group_t group;
  nx_am_id_t type;
} serial_header_t;




#line 120
typedef struct serial_packet {
  serial_header_t header;
  unsigned char data[];
} serial_packet_t;

static uint16_t crcByte(uint16_t crc, uint8_t b);
# 11 "/opt/tinyos-2.x/tos/platforms/cc2431/platform_message.h"
#line 8
typedef union message_header {
  cc2430_header_t cc2430;
  serial_header_t serial;
} message_header_t;



#line 13
typedef union message_footer {
  cc2430_footer_t cc2430;
} message_footer_t;



#line 17
typedef union message_metadata {
  cc2430_metadata_t cc2430;
} message_metadata_t;
# 19 "/opt/tinyos-2.x/tos/types/message.h"
#line 14
typedef struct message_t {
  unsigned char header[sizeof(message_header_t )];
  unsigned char data[28];
  unsigned char footer[sizeof(message_footer_t )];
  unsigned char metadata[sizeof(message_metadata_t )];
} message_t;
# 45 "Adhoc_Route.h"
#line 36
typedef struct __nesc_unnamed4286 {
  uint16_t FrameControl;
  uint16_t FinalDstAddr;
  uint16_t OrigiSrcAddr;
  uint8_t Sequence;
  uint8_t TTL;
  uint16_t Dst2_for_multihop;
  uint16_t Dst3_for_multihop;
  Adhoc_APP_Msg AppData;
} __attribute((packed))  Route_Msg;





#line 47
typedef struct __nesc_unnamed4287 {
  uint16_t FrameControl;
  uint16_t OrigiSrcAddr;
  uint16_t HopNum_from_Sink;
} __attribute((packed))  Hello_Frame;





#line 53
typedef struct __nesc_unnamed4288 {
  uint16_t FinalDstAddr;
  uint16_t OrigiSrcAddr;
  uint8_t Sequence;
} __attribute((packed))  Route_Table;







#line 59
typedef struct __nesc_unnamed4289 {
  uint16_t Naddr;
  uint16_t HopNum_from_Sink;
  char RSSI;
  uint8_t LQI;
  uint16_t Insert_time;
} __attribute((packed))  NeighborTable;

enum __nesc_unnamed4290 {
#line 67
  RF_FLOODING_DATA = 11, RF_GOSSIPING_DATA = 12, RF_TREE_DATA = 13, RF_HELLO_FRAME = 14
};
typedef TMilli Adhoc_APPM$Timer$precision_tag;
enum HilTimerMilliC$__nesc_unnamed4291 {
  HilTimerMilliC$TIMER_COUNT = 4U
};
typedef TMilli /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$precision_tag;
typedef uint16_t FloodingM$SeedInit$parameter;
typedef TMilli FloodingM$Timer$precision_tag;
typedef uint16_t RandomC$SeedInit$parameter;
typedef uint16_t CC2430ActiveMessageM$SeedInit$parameter;
typedef TMicro HAL_CC2430ControlM$BusyWait$precision_tag;
typedef uint16_t HAL_CC2430ControlM$BusyWait$size_type;
typedef TMilli HAL_CC2430ControlM$TX_TimeOut$precision_tag;
typedef TMilli HAL_CC2430ControlM$ACK_TimeOut$precision_tag;
typedef TMicro BusyWaitMicroC$BusyWait$precision_tag;
typedef uint16_t BusyWaitMicroC$BusyWait$size_type;
enum AMQueueP$__nesc_unnamed4292 {
  AMQueueP$NUM_CLIENTS = 1U
};
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t PlatformP$Init$init(void);
# 31 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static   void HplCC2430GeneralIOC$P13$toggle(void);



static   void HplCC2430GeneralIOC$P13$makeOutput(void);
#line 29
static   void HplCC2430GeneralIOC$P13$set(void);





static   void HplCC2430GeneralIOC$P07$makeOutput(void);
#line 30
static   void HplCC2430GeneralIOC$P07$clr(void);




static   void HplCC2430GeneralIOC$P14$makeOutput(void);
#line 29
static   void HplCC2430GeneralIOC$P14$set(void);
static   void HplCC2430GeneralIOC$P14$clr(void);
static   void HplCC2430GeneralIOC$P12$toggle(void);



static   void HplCC2430GeneralIOC$P12$makeOutput(void);
#line 29
static   void HplCC2430GeneralIOC$P12$set(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t SchedulerBasicP$TaskBasic$postTask(
# 45 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
uint8_t arg_0x1a420d78);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void SchedulerBasicP$TaskBasic$default$runTask(
# 45 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
uint8_t arg_0x1a420d78);
# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static  void SchedulerBasicP$Scheduler$init(void);
#line 61
static  void SchedulerBasicP$Scheduler$taskLoop(void);
#line 54
static  bool SchedulerBasicP$Scheduler$runNextTask(void);
# 59 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
static   void McuSleepC$McuSleep$sleep(void);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void Adhoc_APPM$Rout_Send$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static  void Adhoc_APPM$Boot$booted(void);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void Adhoc_APPM$Serial_Send$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *Adhoc_APPM$Rout_Receive$receive(message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  void Adhoc_APPM$SControl$startDone(error_t arg_0x1a7f1030);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *Adhoc_APPM$Serial_Receive$receive(message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 72 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void Adhoc_APPM$Timer$fired(void);
#line 72
static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$default$fired(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
uint8_t arg_0x1a8627e8);
# 53 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startPeriodic(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
uint8_t arg_0x1a8627e8, 
# 53 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
uint32_t arg_0x1a7966d8);








static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startOneShot(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
uint8_t arg_0x1a8627e8, 
# 62 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
uint32_t arg_0x1a796ca8);




static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$stop(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
uint8_t arg_0x1a8627e8);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Init$init(void);
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
static   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$fired(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$runTask(void);
#line 64
static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$runTask(void);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
static   void HplSCS_Clock_Timer1P$Alarm$start(uint8_t arg_0x1a872b80);
#line 13
static   uint8_t HplSCS_Clock_Timer1P$Alarm$getNow(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t HplSCS_Clock_Timer1P$Init$init(void);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t NoSCSuartDBGC$StdControl$start(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t LedsP$Init$init(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
static   void LedsP$Leds$led0Toggle(void);
#line 72
static   void LedsP$Leds$led1Toggle(void);










static   void LedsP$Leds$led2Off(void);
#line 78
static   void LedsP$Leds$led2On(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void FloodingM$RecvToAPP_task$runTask(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t FloodingM$SendFromAPP$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void *FloodingM$SendFromAPP$getPayload(message_t *arg_0x1a7e3b18);
#line 99
static  void FloodingM$SendToMAC$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void FloodingM$Forwarding_task$runTask(void);
# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  void FloodingM$CommControl$startDone(error_t arg_0x1a7f1030);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *FloodingM$RecvFromMAC$receive(message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t FloodingM$StdControl$start(void);
# 72 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void FloodingM$Timer$fired(void);
# 41 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
static   uint16_t RandomC$Random$rand16(void);
# 53 "/opt/tinyos-2.x/tos/interfaces/ParameterInit.nc"
static  error_t RandomC$SeedInit$init(RandomC$SeedInit$parameter arg_0x1a9671d8);
# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  error_t CC2430ActiveMessageM$SplitControl$start(void);
# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static  uint8_t CC2430ActiveMessageM$Packet$payloadLength(message_t *arg_0x1a9d4bd0);
#line 108
static  void *CC2430ActiveMessageM$Packet$getPayload(message_t *arg_0x1a9d1010, uint8_t *arg_0x1a9d11b8);
#line 83
static  void CC2430ActiveMessageM$Packet$setPayloadLength(message_t *arg_0x1a9d3260, uint8_t arg_0x1a9d33e8);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t CC2430ActiveMessageM$AMSend$send(
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f23d8, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void *CC2430ActiveMessageM$AMSend$getPayload(
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f23d8, 
# 125 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e3b18);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *CC2430ActiveMessageM$Snoop$default$receive(
# 18 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f14e0, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
static  void CC2430ActiveMessageM$CC2430_TX_RX$sendPacketDone(uint8_t *arg_0x1aa164e0, error_t arg_0x1aa16668);

static  void CC2430ActiveMessageM$CC2430_TX_RX$receivedPacket(uint8_t *arg_0x1aa16b20);
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
static  void CC2430ActiveMessageM$BackoffTimer$fired(void);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *CC2430ActiveMessageM$Receive$default$receive(
# 17 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f2d08, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void CC2430ActiveMessageM$Backoff_Task$runTask(void);
# 57 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static  am_addr_t CC2430ActiveMessageM$AMPacket$address(void);









static  am_addr_t CC2430ActiveMessageM$AMPacket$destination(message_t *arg_0x1a803190);
#line 92
static  void CC2430ActiveMessageM$AMPacket$setDestination(message_t *arg_0x1a803d38, am_addr_t arg_0x1a803ec8);
#line 136
static  am_id_t CC2430ActiveMessageM$AMPacket$type(message_t *arg_0x1a801740);
#line 151
static  void CC2430ActiveMessageM$AMPacket$setType(message_t *arg_0x1a801cc8, am_id_t arg_0x1a801e50);
#line 125
static  bool CC2430ActiveMessageM$AMPacket$isForMe(message_t *arg_0x1a801010);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$receivedPacketTask$runTask(void);
# 24 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430Control.nc"
static  void HAL_CC2430ControlM$CC2430Control$enableAddrDecode(void);
#line 22
static  void HAL_CC2430ControlM$CC2430Control$enableAutoAck(void);




static  uint8_t HAL_CC2430ControlM$CC2430Control$GetCCA(void);
# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   void HAL_CC2430ControlM$InterruptRFErr$fired(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$TX_TimeOutStopTask$runTask(void);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
static  void HAL_CC2430ControlM$CC2430_TX_RX$sendPacket(uint8_t *arg_0x1aa16030);
# 72 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void HAL_CC2430ControlM$TX_TimeOut$fired(void);
#line 72
static  void HAL_CC2430ControlM$ACK_TimeOut$fired(void);
# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   void HAL_CC2430ControlM$InterruptTXDone$fired(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$ReceivedPacketDone$runTask(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t HAL_CC2430ControlM$Init$init(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$ACK_TimerOutSetTask$runTask(void);
# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   void HAL_CC2430ControlM$InterruptFIFOP$fired(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$sendPacketDoneFAILTask$runTask(void);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t HAL_CC2430ControlM$StdControl$start(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void HAL_CC2430ControlM$sendPacketDoneSUCCTask$runTask(void);
#line 64
static  void HAL_CC2430ControlM$transmitTask$runTask(void);
# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   error_t Hpl_CC2430InterruptsC$InterruptRFErr$enableRisingEdge(void);
#line 42
static   error_t Hpl_CC2430InterruptsC$InterruptTXDone$enableRisingEdge(void);
#line 57
static   void Hpl_CC2430InterruptsC$InterruptCCA$default$fired(void);
#line 42
static   error_t Hpl_CC2430InterruptsC$InterruptFIFOP$enableRisingEdge(void);
# 55 "/opt/tinyos-2.x/tos/lib/timer/BusyWait.nc"
static   void BusyWaitMicroC$BusyWait$wait(BusyWaitMicroC$BusyWait$size_type arg_0x1aa90e00);
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
static   void SCSuartDBGM$HPLUART$get(uint8_t arg_0x1ab72270);





static   void SCSuartDBGM$HPLUART$putDone(void);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBG.nc"
static   void SCSuartDBGM$SCSuartDBG$UARTSend(uint8_t *arg_0x1a8868c0, uint8_t arg_0x1a886a48);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t SCSuartDBGM$StdControl$start(void);
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
static   void HalCC2430SimpleUartP$uart1$default$get(uint8_t arg_0x1ab72270);





static   void HalCC2430SimpleUartP$uart1$default$putDone(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t HalCC2430SimpleUartP$Init$init(void);
# 41 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
static   error_t HalCC2430SimpleUartP$uart0$put(uint8_t arg_0x1ab76cb8);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
static  void Hpl_Backoff_Timer3M$Backoff$start(uint8_t arg_0x1aa133b0);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t Hpl_Backoff_Timer3M$Init$init(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void Hpl_Backoff_Timer3M$EventFired$runTask(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void */*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$getPayload(message_t *arg_0x1a7e3b18);
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *arg_0x1abd4a28, error_t arg_0x1abd4bb0);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(
# 43 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
am_id_t arg_0x1abf8bc8, 
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 64 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(
# 39 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
uint8_t arg_0x1abf9f28, 
# 64 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t *arg_0x1abd6920, uint8_t arg_0x1abd6aa8);
#line 114
static  void */*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$getPayload(
# 39 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
uint8_t arg_0x1abf9f28, 
# 114 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t *arg_0x1abd3698);
#line 89
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(
# 39 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
uint8_t arg_0x1abf9f28, 
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t *arg_0x1abd4a28, error_t arg_0x1abd4bb0);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Init$init(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void);
# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$start(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$runTask(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$send(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
am_id_t arg_0x1ac4ae98, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 99
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$default$sendDone(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
am_id_t arg_0x1ac4ae98, 
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$default$receive(
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
am_id_t arg_0x1ac49850, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGIdle.nc"
static   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGIdle$UARTIdle(void);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$runTask(void);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGRecv.nc"
static   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGRecv$UARTRecv(uint8_t arg_0x1a8f1e38);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMPacket$setSource(message_t *arg_0x1a802600, am_addr_t arg_0x1a802790);
# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static   void PlatformP$VDD_PW_CTRL$makeOutput(void);
#line 30
static   void PlatformP$VDD_PW_CTRL$clr(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t PlatformP$LedsInit$init(void);
# 10 "/opt/tinyos-2.x/tos/platforms/cc2431/PlatformP.nc"
static inline  error_t PlatformP$Init$init(void);
# 100 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P07$clr(void);
#line 100
static __inline   void HplCC2430GeneralIOC$P07$makeOutput(void);



static __inline   void HplCC2430GeneralIOC$P12$set(void);
#line 104
static inline   void HplCC2430GeneralIOC$P12$toggle(void);
#line 104
static __inline   void HplCC2430GeneralIOC$P12$makeOutput(void);
static __inline   void HplCC2430GeneralIOC$P13$set(void);
#line 105
static inline   void HplCC2430GeneralIOC$P13$toggle(void);
#line 105
static __inline   void HplCC2430GeneralIOC$P13$makeOutput(void);
static __inline   void HplCC2430GeneralIOC$P14$set(void);
#line 106
static __inline   void HplCC2430GeneralIOC$P14$clr(void);
#line 106
static __inline   void HplCC2430GeneralIOC$P14$makeOutput(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t RealMainP$SoftwareInit$init(void);
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static  void RealMainP$Boot$booted(void);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t RealMainP$PlatformInit$init(void);
# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static  void RealMainP$Scheduler$init(void);
#line 61
static  void RealMainP$Scheduler$taskLoop(void);
#line 54
static  bool RealMainP$Scheduler$runNextTask(void);
# 52 "/opt/tinyos-2.x/tos/system/RealMainP.nc"
int main(void)   ;
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void SchedulerBasicP$TaskBasic$runTask(
# 45 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
uint8_t arg_0x1a420d78);
# 59 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
static   void SchedulerBasicP$McuSleep$sleep(void);
# 50 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
enum SchedulerBasicP$__nesc_unnamed4293 {

  SchedulerBasicP$NUM_TASKS = 16U
};



volatile uint8_t SchedulerBasicP$m_head;
volatile uint8_t SchedulerBasicP$m_tail;
volatile uint8_t SchedulerBasicP$m_next[SchedulerBasicP$NUM_TASKS];
#line 72
static __inline uint8_t SchedulerBasicP$popTask(void);
#line 91
static inline bool SchedulerBasicP$isWaiting(uint8_t id);




static inline bool SchedulerBasicP$pushTask(uint8_t id);
#line 118
static inline  void SchedulerBasicP$Scheduler$init(void);
#line 130
static  bool SchedulerBasicP$Scheduler$runNextTask(void);
#line 145
static inline  void SchedulerBasicP$Scheduler$taskLoop(void);
#line 166
static   error_t SchedulerBasicP$TaskBasic$postTask(uint8_t id);




static   void SchedulerBasicP$TaskBasic$default$runTask(uint8_t id);
# 51 "/opt/tinyos-2.x/tos/chips/cc2430/McuSleepC.nc"
static inline   void McuSleepC$McuSleep$sleep(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t Adhoc_APPM$Rout_Send$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void *Adhoc_APPM$Rout_Send$getPayload(message_t *arg_0x1a7e3b18);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t Adhoc_APPM$RControl$start(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t Adhoc_APPM$Serial_Send$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static  void Adhoc_APPM$Serial_Packet$setSource(message_t *arg_0x1a802600, am_addr_t arg_0x1a802790);
# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  error_t Adhoc_APPM$SControl$start(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
static   void Adhoc_APPM$Leds$led0Toggle(void);
#line 72
static   void Adhoc_APPM$Leds$led1Toggle(void);










static   void Adhoc_APPM$Leds$led2Off(void);
#line 78
static   void Adhoc_APPM$Leds$led2On(void);
# 53 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void Adhoc_APPM$Timer$startPeriodic(uint32_t arg_0x1a7966d8);
# 39 "Adhoc_APPM.nc"
message_t Adhoc_APPM$RF_MSG;
#line 39
message_t Adhoc_APPM$Serial_MSG;
uint16_t Adhoc_APPM$APP_Seq;

static inline  void Adhoc_APPM$Boot$booted(void);





static inline  void Adhoc_APPM$SControl$startDone(error_t error);







static  void Adhoc_APPM$Timer$fired(void);
#line 75
static inline  void Adhoc_APPM$Rout_Send$sendDone(message_t *msg, error_t error);





static inline  message_t *Adhoc_APPM$Rout_Receive$receive(message_t *msg, void *payload, uint8_t len);
#line 103
static inline  void Adhoc_APPM$Serial_Send$sendDone(message_t *msg, error_t error);
static inline  message_t *Adhoc_APPM$Serial_Receive$receive(message_t *msg, void *payload, uint8_t len);
# 72 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$fired(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
uint8_t arg_0x1a8627e8);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliInit$init(void);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
static   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$start(uint8_t arg_0x1a872b80);
#line 13
static   uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$getNow(void);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$SCSuartSTD$start(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$postTask(void);
#line 56
static   error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$postTask(void);
# 113 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
enum /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_unnamed4294 {
#line 113
  SCS_VTimerP$0$HandleFire = 0U
};
#line 113
typedef int /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_sillytask_HandleFire[/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire];


enum /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_unnamed4295 {
#line 116
  SCS_VTimerP$0$signalOneTimer = 1U
};
#line 116
typedef int /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_sillytask_signalOneTimer[/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer];
#line 26
enum /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_unnamed4296 {
#line 26
  SCS_VTimerP$0$NUM_TIMERS = 4, SCS_VTimerP$0$maxTimerInterval = 230
};
uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$setIntervalFlag;
#line 28
uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval;
int8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head;
#line 29
int8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail;
uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_size;
uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue[/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS];







#line 33
typedef struct /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$__nesc_unnamed4297 {
  int32_t ticks;
  int32_t ticksLeft;
  bool isoneshot : 1;
  bool mState : 1;
  bool nothing : 6;
} /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Timer_t;
 /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Timer_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS];



static inline  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Init$init(void);
#line 59
static error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$startTimer(uint8_t id, uint32_t interval, bool isoneshot);
#line 90
static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startPeriodic(uint8_t num, uint32_t dt);



static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startOneShot(uint8_t num, uint32_t dt);



static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$stop(uint8_t num);










static inline   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$default$fired(uint8_t num);




static inline void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$enqueue(uint8_t value);
static inline uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$dequeue(void);

inline static void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$adjustInterval(void);

static inline   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$fired(void);





static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$runTask(void);
#line 150
static inline void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$enqueue(uint8_t value);







static inline uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$dequeue(void);









static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$runTask(void);





inline static void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$adjustInterval(void);
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
static   void HplSCS_Clock_Timer1P$Alarm$fired(void);
# 18 "/opt/tinyos-2.x/tos/platforms/cc2431/HplSCS_Clock_Timer1P.nc"
enum HplSCS_Clock_Timer1P$__nesc_unnamed4298 {
#line 18
  HplSCS_Clock_Timer1P$mscale = 125
};
static inline  error_t HplSCS_Clock_Timer1P$Init$init(void);
#line 59
static inline   uint8_t HplSCS_Clock_Timer1P$Alarm$getNow(void);







static   void HplSCS_Clock_Timer1P$Alarm$start(uint8_t dt);
#line 80
void __vector_9(void)   __attribute((interrupt)) ;
# 13 "/opt/tinyos-2.x/tos/platforms/cc2431/NoSCSuartDBGC.nc"
static inline  error_t NoSCSuartDBGC$StdControl$start(void);
# 31 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static   void LedsP$Led0$toggle(void);



static   void LedsP$Led0$makeOutput(void);
#line 29
static   void LedsP$Led0$set(void);

static   void LedsP$Led1$toggle(void);



static   void LedsP$Led1$makeOutput(void);
#line 29
static   void LedsP$Led1$set(void);





static   void LedsP$Led2$makeOutput(void);
#line 29
static   void LedsP$Led2$set(void);
static   void LedsP$Led2$clr(void);
# 45 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline  error_t LedsP$Init$init(void);
#line 73
static inline   void LedsP$Leds$led0Toggle(void);
#line 88
static inline   void LedsP$Leds$led1Toggle(void);




static inline   void LedsP$Leds$led2On(void);




static inline   void LedsP$Leds$led2Off(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t FloodingM$RecvToAPP_task$postTask(void);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void FloodingM$SendFromAPP$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 41 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
static   uint16_t FloodingM$Random$rand16(void);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t FloodingM$SendToMAC$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void *FloodingM$SendToMAC$getPayload(message_t *arg_0x1a7e3b18);
# 53 "/opt/tinyos-2.x/tos/interfaces/ParameterInit.nc"
static  error_t FloodingM$SeedInit$init(FloodingM$SeedInit$parameter arg_0x1a9671d8);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t FloodingM$Forwarding_task$postTask(void);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *FloodingM$RecvToAPP$receive(message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  error_t FloodingM$CommControl$start(void);
# 151 "FloodingM.nc"
enum FloodingM$__nesc_unnamed4299 {
#line 151
  FloodingM$RecvToAPP_task = 2U
};
#line 151
typedef int FloodingM$__nesc_sillytask_RecvToAPP_task[FloodingM$RecvToAPP_task];




enum FloodingM$__nesc_unnamed4300 {
#line 156
  FloodingM$Forwarding_task = 3U
};
#line 156
typedef int FloodingM$__nesc_sillytask_Forwarding_task[FloodingM$Forwarding_task];
#line 38
message_t FloodingM$SendMsg;
#line 38
message_t FloodingM$RecvMsg;
#line 38
message_t FloodingM$ForwardMsg[5];
Route_Msg FloodingM$NWKF;
uint16_t FloodingM$Next_Addr;
uint8_t FloodingM$Forward_Buff_Index;
uint8_t FloodingM$RTable_Index;
uint8_t FloodingM$mySequence;
Route_Table FloodingM$RTable[20];

static inline  error_t FloodingM$StdControl$start(void);
#line 69
static inline  void FloodingM$CommControl$startDone(error_t error);



static void FloodingM$insertMSGtoRTable(message_t *msg);
#line 87
static bool FloodingM$isRecvPrevious(message_t *msg);
#line 107
static inline  error_t FloodingM$SendFromAPP$send(am_addr_t addr, message_t *msg, uint8_t len);
#line 141
static  void *FloodingM$SendFromAPP$getPayload(message_t *msg);



static inline  void FloodingM$SendToMAC$sendDone(message_t *msg, error_t error);





static inline  void FloodingM$RecvToAPP_task$runTask(void);




static inline  void FloodingM$Forwarding_task$runTask(void);




static inline  message_t *FloodingM$RecvFromMAC$receive(message_t *msg, void *payload, uint8_t len);
#line 214
static inline  void FloodingM$Timer$fired(void);
# 20 "/opt/tinyos-2.x/tos/platforms/cc2431/RandomC.nc"
 uint8_t RandomC$RSeq;
 uint16_t RandomC$Rseed;
 uint16_t RandomC$randValue16;
 uint32_t RandomC$randValue32;

static  error_t RandomC$SeedInit$init(uint16_t param);
#line 41
static   uint16_t RandomC$Random$rand16(void);
# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  void CC2430ActiveMessageM$SplitControl$startDone(error_t arg_0x1a7f1030);
# 24 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430Control.nc"
static  void CC2430ActiveMessageM$CC2430Control$enableAddrDecode(void);
#line 22
static  void CC2430ActiveMessageM$CC2430Control$enableAutoAck(void);




static  uint8_t CC2430ActiveMessageM$CC2430Control$GetCCA(void);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void CC2430ActiveMessageM$AMSend$sendDone(
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f23d8, 
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *CC2430ActiveMessageM$Snoop$receive(
# 18 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f14e0, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
static  void CC2430ActiveMessageM$CC2430_TX_RX$sendPacket(uint8_t *arg_0x1aa16030);
# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
static  void CC2430ActiveMessageM$BackoffTimer$start(uint8_t arg_0x1aa133b0);
# 41 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
static   uint16_t CC2430ActiveMessageM$Random$rand16(void);
# 53 "/opt/tinyos-2.x/tos/interfaces/ParameterInit.nc"
static  error_t CC2430ActiveMessageM$SeedInit$init(CC2430ActiveMessageM$SeedInit$parameter arg_0x1a9671d8);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t *CC2430ActiveMessageM$Receive$receive(
# 17 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
am_id_t arg_0x1a9f2d08, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t CC2430ActiveMessageM$Backoff_Task$postTask(void);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t CC2430ActiveMessageM$SubStdControl$start(void);
# 60 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
enum CC2430ActiveMessageM$__nesc_unnamed4301 {
#line 60
  CC2430ActiveMessageM$Backoff_Task = 4U
};
#line 60
typedef int CC2430ActiveMessageM$__nesc_sillytask_Backoff_Task[CC2430ActiveMessageM$Backoff_Task];
#line 35
 uint8_t CC2430ActiveMessageM$RF_Status;
#line 35
 uint8_t CC2430ActiveMessageM$MAC_Seq;
#line 35
 uint8_t CC2430ActiveMessageM$NumReTX;

 bool CC2430ActiveMessageM$AckEnable;
 message_t *CC2430ActiveMessageM$TX_Ready_Msg;

static inline  error_t CC2430ActiveMessageM$SplitControl$start(void);
#line 60
static inline  void CC2430ActiveMessageM$Backoff_Task$runTask(void);









static inline  void CC2430ActiveMessageM$BackoffTimer$fired(void);
#line 87
static  error_t CC2430ActiveMessageM$AMSend$send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len);
#line 133
static  void CC2430ActiveMessageM$CC2430_TX_RX$sendPacketDone(uint8_t *TXpacket, error_t err);
#line 154
static inline  void *CC2430ActiveMessageM$AMSend$getPayload(am_id_t id, message_t *m);
#line 176
static inline  void CC2430ActiveMessageM$CC2430_TX_RX$receivedPacket(uint8_t *RXPacket);
#line 218
static inline  am_addr_t CC2430ActiveMessageM$AMPacket$address(void);



static inline  am_addr_t CC2430ActiveMessageM$AMPacket$destination(message_t *msg);









static inline  void CC2430ActiveMessageM$AMPacket$setDestination(message_t *msg, am_addr_t addr);









static inline  bool CC2430ActiveMessageM$AMPacket$isForMe(message_t *msg);




static inline  am_id_t CC2430ActiveMessageM$AMPacket$type(message_t *msg);




static inline  void CC2430ActiveMessageM$AMPacket$setType(message_t *msg, am_id_t type);




static inline   message_t *CC2430ActiveMessageM$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);



static inline   message_t *CC2430ActiveMessageM$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);









static inline  uint8_t CC2430ActiveMessageM$Packet$payloadLength(message_t *msg);



static inline  void CC2430ActiveMessageM$Packet$setPayloadLength(message_t *msg, uint8_t len);







static  void *CC2430ActiveMessageM$Packet$getPayload(message_t *msg, uint8_t *len);
# 55 "/opt/tinyos-2.x/tos/lib/timer/BusyWait.nc"
static   void HAL_CC2430ControlM$BusyWait$wait(HAL_CC2430ControlM$BusyWait$size_type arg_0x1aa90e00);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t HAL_CC2430ControlM$receivedPacketTask$postTask(void);
# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   error_t HAL_CC2430ControlM$InterruptRFErr$enableRisingEdge(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t HAL_CC2430ControlM$TX_TimeOutStopTask$postTask(void);
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
static  void HAL_CC2430ControlM$CC2430_TX_RX$sendPacketDone(uint8_t *arg_0x1aa164e0, error_t arg_0x1aa16668);

static  void HAL_CC2430ControlM$CC2430_TX_RX$receivedPacket(uint8_t *arg_0x1aa16b20);
# 62 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static  void HAL_CC2430ControlM$TX_TimeOut$startOneShot(uint32_t arg_0x1a796ca8);




static  void HAL_CC2430ControlM$TX_TimeOut$stop(void);
#line 62
static  void HAL_CC2430ControlM$ACK_TimeOut$startOneShot(uint32_t arg_0x1a796ca8);




static  void HAL_CC2430ControlM$ACK_TimeOut$stop(void);
# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   error_t HAL_CC2430ControlM$InterruptTXDone$enableRisingEdge(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t HAL_CC2430ControlM$ReceivedPacketDone$postTask(void);
#line 56
static   error_t HAL_CC2430ControlM$ACK_TimerOutSetTask$postTask(void);
# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   error_t HAL_CC2430ControlM$InterruptFIFOP$enableRisingEdge(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t HAL_CC2430ControlM$sendPacketDoneFAILTask$postTask(void);
#line 56
static   error_t HAL_CC2430ControlM$sendPacketDoneSUCCTask$postTask(void);
#line 56
static   error_t HAL_CC2430ControlM$transmitTask$postTask(void);
# 56 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
enum HAL_CC2430ControlM$__nesc_unnamed4302 {
#line 56
  HAL_CC2430ControlM$sendPacketDoneSUCCTask = 5U
};
#line 56
typedef int HAL_CC2430ControlM$__nesc_sillytask_sendPacketDoneSUCCTask[HAL_CC2430ControlM$sendPacketDoneSUCCTask];
enum HAL_CC2430ControlM$__nesc_unnamed4303 {
#line 57
  HAL_CC2430ControlM$sendPacketDoneFAILTask = 6U
};
#line 57
typedef int HAL_CC2430ControlM$__nesc_sillytask_sendPacketDoneFAILTask[HAL_CC2430ControlM$sendPacketDoneFAILTask];
#line 145
enum HAL_CC2430ControlM$__nesc_unnamed4304 {
#line 145
  HAL_CC2430ControlM$transmitTask = 7U
};
#line 145
typedef int HAL_CC2430ControlM$__nesc_sillytask_transmitTask[HAL_CC2430ControlM$transmitTask];
#line 206
enum HAL_CC2430ControlM$__nesc_unnamed4305 {
#line 206
  HAL_CC2430ControlM$TX_TimeOutStopTask = 8U
};
#line 206
typedef int HAL_CC2430ControlM$__nesc_sillytask_TX_TimeOutStopTask[HAL_CC2430ControlM$TX_TimeOutStopTask];



enum HAL_CC2430ControlM$__nesc_unnamed4306 {
#line 210
  HAL_CC2430ControlM$ACK_TimerOutSetTask = 9U
};
#line 210
typedef int HAL_CC2430ControlM$__nesc_sillytask_ACK_TimerOutSetTask[HAL_CC2430ControlM$ACK_TimerOutSetTask];
#line 249
enum HAL_CC2430ControlM$__nesc_unnamed4307 {
#line 249
  HAL_CC2430ControlM$ReceivedPacketDone = 10U
};
#line 249
typedef int HAL_CC2430ControlM$__nesc_sillytask_ReceivedPacketDone[HAL_CC2430ControlM$ReceivedPacketDone];



enum HAL_CC2430ControlM$__nesc_unnamed4308 {
#line 253
  HAL_CC2430ControlM$receivedPacketTask = 11U
};
#line 253
typedef int HAL_CC2430ControlM$__nesc_sillytask_receivedPacketTask[HAL_CC2430ControlM$receivedPacketTask];
#line 39
static inline void HAL_CC2430ControlM$CC2430AddressFilterEnable(void);

static inline void HAL_CC2430ControlM$CC2430SetPanid(uint16_t id);
static inline void HAL_CC2430ControlM$CC2430SetShortaddr(uint16_t shortAddr);
static inline void HAL_CC2430ControlM$CC2430Reset(void);
static inline void HAL_CC2430ControlM$CC2430RFEnable(void);
static inline void HAL_CC2430ControlM$CC2430RFDisable(void);
static inline void HAL_CC2430ControlM$CC2430ExternalOscillator(void);
static inline void HAL_CC2430ControlM$CC2430RxEnable(void);

static inline void HAL_CC2430ControlM$CC2430ChannelSet(uint8_t channel);
static inline void HAL_CC2430ControlM$CC2430PALevelSet(uint8_t new_power);
static inline void HAL_CC2430ControlM$CC2430ControlSet(void);


static inline void HAL_CC2430ControlM$flushRXBufferTask(void);
static inline void HAL_CC2430ControlM$flushTXBufferTask(void);



 uint8_t *HAL_CC2430ControlM$transmitPacketPtr;
#line 59
 uint8_t HAL_CC2430ControlM$transmitPacket[128];
#line 59
 uint8_t HAL_CC2430ControlM$receivedPacket[128];
 uint8_t HAL_CC2430ControlM$currentPower;
#line 60
 uint8_t HAL_CC2430ControlM$currentChannel;
#line 60
 uint8_t HAL_CC2430ControlM$SendDoneError;
 bool HAL_CC2430ControlM$transmitInProgress;
#line 61
 bool HAL_CC2430ControlM$WaitACK_Flag;


static inline  error_t HAL_CC2430ControlM$Init$init(void);
#line 102
static inline  error_t HAL_CC2430ControlM$StdControl$start(void);
#line 128
static inline void HAL_CC2430ControlM$flushRXBufferTask(void);




static inline void HAL_CC2430ControlM$flushTXBufferTask(void);



static inline   void HAL_CC2430ControlM$InterruptRFErr$fired(void);







static inline  void HAL_CC2430ControlM$transmitTask$runTask(void);
#line 187
static inline  void HAL_CC2430ControlM$CC2430_TX_RX$sendPacket(uint8_t *packet);










static inline  void HAL_CC2430ControlM$sendPacketDoneSUCCTask$runTask(void);



static inline  void HAL_CC2430ControlM$sendPacketDoneFAILTask$runTask(void);



static inline  void HAL_CC2430ControlM$TX_TimeOutStopTask$runTask(void);



static inline  void HAL_CC2430ControlM$ACK_TimerOutSetTask$runTask(void);



static inline   void HAL_CC2430ControlM$InterruptTXDone$fired(void);
#line 229
static  void HAL_CC2430ControlM$TX_TimeOut$fired(void);








static  void HAL_CC2430ControlM$ACK_TimeOut$fired(void);










static inline  void HAL_CC2430ControlM$ReceivedPacketDone$runTask(void);



static inline  void HAL_CC2430ControlM$receivedPacketTask$runTask(void);
#line 317
static inline   void HAL_CC2430ControlM$InterruptFIFOP$fired(void);
#line 359
static inline  void HAL_CC2430ControlM$CC2430Control$enableAutoAck(void);

static inline  void HAL_CC2430ControlM$CC2430Control$enableAddrDecode(void);


static inline  uint8_t HAL_CC2430ControlM$CC2430Control$GetCCA(void);
#line 376
static inline void HAL_CC2430ControlM$CC2430AddressFilterEnable(void);

static inline void HAL_CC2430ControlM$CC2430SetPanid(uint16_t id);



static inline void HAL_CC2430ControlM$CC2430SetShortaddr(uint16_t shortAddr);




static inline void HAL_CC2430ControlM$CC2430Reset(void);
#line 400
static inline void HAL_CC2430ControlM$CC2430RFEnable(void);
#line 412
static inline void HAL_CC2430ControlM$CC2430RFDisable(void);
#line 431
static inline void HAL_CC2430ControlM$CC2430ExternalOscillator(void);








static inline void HAL_CC2430ControlM$CC2430RxEnable(void);
#line 463
static inline void HAL_CC2430ControlM$CC2430ChannelSet(uint8_t channel);
#line 478
static inline void HAL_CC2430ControlM$CC2430PALevelSet(uint8_t new_power);








static inline void HAL_CC2430ControlM$CC2430ControlSet(void);
# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static   void Hpl_CC2430InterruptsC$InterruptRFErr$fired(void);
#line 57
static   void Hpl_CC2430InterruptsC$InterruptTXDone$fired(void);
#line 57
static   void Hpl_CC2430InterruptsC$InterruptCCA$fired(void);
#line 57
static   void Hpl_CC2430InterruptsC$InterruptFIFOP$fired(void);
# 73 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
static inline   error_t Hpl_CC2430InterruptsC$InterruptFIFOP$enableRisingEdge(void);
static inline   error_t Hpl_CC2430InterruptsC$InterruptTXDone$enableRisingEdge(void);





static inline   error_t Hpl_CC2430InterruptsC$InterruptRFErr$enableRisingEdge(void);
#line 96
void __vector_0(void)   __attribute((interrupt)) ;






void __vector_16(void)   __attribute((interrupt)) ;
#line 134
static inline    void Hpl_CC2430InterruptsC$InterruptCCA$default$fired(void);
# 12 "/opt/tinyos-2.x/tos/platforms/cc2431/BusyWaitMicroC.nc"
 uint8_t volatile BusyWaitMicroC$MicroValue_;
static __inline   void BusyWaitMicroC$BusyWait$wait(uint16_t dt);
# 41 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
static   error_t SCSuartDBGM$HPLUART$put(uint8_t arg_0x1ab76cb8);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static  error_t SCSuartDBGM$Init$init(void);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGIdle.nc"
static   void SCSuartDBGM$SCSuartDBGIdle$UARTIdle(void);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGRecv.nc"
static   void SCSuartDBGM$SCSuartDBGRecv$UARTRecv(uint8_t arg_0x1a8f1e38);
# 46 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGM.nc"
 bool SCSuartDBGM$state = 0;
 uint8_t SCSuartDBGM$str_buff[127];
 uint16_t SCSuartDBGM$buff_start = 0;
 uint16_t SCSuartDBGM$buff_end = 0;

static inline  error_t SCSuartDBGM$StdControl$start(void);
#line 63
static inline   void SCSuartDBGM$HPLUART$get(uint8_t data);



static inline   void SCSuartDBGM$HPLUART$putDone(void);
#line 85
static   void SCSuartDBGM$SCSuartDBG$UARTSend(uint8_t *data, uint8_t len);
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
static   void HalCC2430SimpleUartP$uart1$get(uint8_t arg_0x1ab72270);





static   void HalCC2430SimpleUartP$uart1$putDone(void);
#line 47
static   void HalCC2430SimpleUartP$uart0$get(uint8_t arg_0x1ab72270);





static   void HalCC2430SimpleUartP$uart0$putDone(void);
# 22 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
static inline  error_t HalCC2430SimpleUartP$Init$init(void);
#line 105
static inline   error_t HalCC2430SimpleUartP$uart0$put(uint8_t data);




void __vector_2(void)   __attribute((interrupt)) ;




void __vector_7(void)   __attribute((interrupt)) ;
#line 132
void __vector_3(void)   __attribute((interrupt)) ;




void __vector_14(void)   __attribute((interrupt)) ;






static inline    void HalCC2430SimpleUartP$uart1$default$get(uint8_t data);
static inline    void HalCC2430SimpleUartP$uart1$default$putDone(void);
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
static  void Hpl_Backoff_Timer3M$Backoff$fired(void);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t Hpl_Backoff_Timer3M$EventFired$postTask(void);
# 51 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_Backoff_Timer3M.nc"
enum Hpl_Backoff_Timer3M$__nesc_unnamed4309 {
#line 51
  Hpl_Backoff_Timer3M$EventFired = 12U
};
#line 51
typedef int Hpl_Backoff_Timer3M$__nesc_sillytask_EventFired[Hpl_Backoff_Timer3M$EventFired];
#line 21
static inline  error_t Hpl_Backoff_Timer3M$Init$init(void);
#line 51
static inline  void Hpl_Backoff_Timer3M$EventFired$runTask(void);






static inline  void Hpl_Backoff_Timer3M$Backoff$start(uint8_t dt);
#line 80
void __vector_11(void)   __attribute((interrupt)) ;
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 64 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static  error_t /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t *arg_0x1abd6920, uint8_t arg_0x1abd6aa8);
#line 114
static  void */*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$getPayload(message_t *arg_0x1abd3698);
# 92 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t *arg_0x1a803d38, am_addr_t arg_0x1a803ec8);
#line 151
static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t *arg_0x1a801cc8, am_id_t arg_0x1a801e50);
# 45 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static  error_t /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err);







static inline  void */*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$getPayload(message_t *m);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(
# 43 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
am_id_t arg_0x1abf8bc8, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90);
#line 125
static  void */*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$getPayload(
# 43 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
am_id_t arg_0x1abf8bc8, 
# 125 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e3b18);
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(
# 39 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
uint8_t arg_0x1abf9f28, 
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t *arg_0x1abd4a28, error_t arg_0x1abd4bb0);
# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static  uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t *arg_0x1a9d4bd0);
#line 83
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t *arg_0x1a9d3260, uint8_t arg_0x1a9d33e8);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void);
# 67 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static  am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t *arg_0x1a803190);
#line 136
static  am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t *arg_0x1a801740);
# 143 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4310 {
#line 143
  AMQueueImplP$0$errorTask = 13U
};
#line 143
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask];
#line 51
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4311 {
  AMQueueImplP$0$QUEUE_EMPTY = 255
};



#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4312 {
  message_t *msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY;
/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[1];
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void);

static inline  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Init$init(void);




static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void);
#line 96
static inline  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, uint8_t len);
#line 143
static inline  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void);







static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void);
#line 166
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 179
static inline  void */*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$getPayload(uint8_t id, message_t *m);



static inline   void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$startDone(error_t arg_0x1a7f1030);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$postTask(void);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$sendDone(
# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
am_id_t arg_0x1ac4ae98, 
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static  message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$receive(
# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
am_id_t arg_0x1ac49850, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static   error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$postTask(void);
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBG.nc"
static   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBG$UARTSend(uint8_t *arg_0x1a8868c0, uint8_t arg_0x1a886a48);
# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$StdControl$start(void);
# 138 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
enum /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$__nesc_unnamed4313 {
#line 138
  SerialActiveMessageP$0$SendDoneTask = 14U
};
#line 138
typedef int /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$__nesc_sillytask_SendDoneTask[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask];










enum /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$__nesc_unnamed4314 {
#line 149
  SerialActiveMessageP$0$SignalToUARTRecv = 15U
};
#line 149
typedef int /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$__nesc_sillytask_SignalToUARTRecv[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv];
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving;
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex;
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Escape_Flag;
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[127];
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvAckType;
#line 31
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvSeq;
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[127];
#line 32
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sendingid;
#line 32
 uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendProcessing;
 message_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag;
#line 33
 message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sending_msg;

static inline  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$start(void);
#line 55
static inline serial_header_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$getHeader(message_t *msg);





static inline  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$send(am_id_t id, am_addr_t dest, message_t *msg, uint8_t len);
#line 122
static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$default$sendDone(uint8_t id, message_t *msg, error_t result);










static inline   message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$default$receive(uint8_t id, message_t *msg, void *payload, uint8_t len);




static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$runTask(void);




static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGIdle$UARTIdle(void);





static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$runTask(void);








static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGRecv$UARTRecv(uint8_t recv_Char);
#line 265
static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMPacket$setSource(message_t *amsg, am_addr_t addr);
# 112 "/opt/tinyos-2.x/tos/chips/mcs51/mcs51hardware.h"
 __inline __nesc_atomic_t __nesc_atomic_start(void )
#line 112
{
  __nesc_atomic_t tmp = EA;

  EA = 0;
  return tmp;
}

 __inline void __nesc_atomic_end(__nesc_atomic_t oldSreg)
#line 119
{
  EA = oldSreg;
}

# 118 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
static inline  void SchedulerBasicP$Scheduler$init(void)
{
  /* atomic removed: atomic calls only */
  {
    uint8_t i;

#line 123
    for (i = 0; i < sizeof SchedulerBasicP$m_next; i++) 
      SchedulerBasicP$m_next[i] = 255;
    SchedulerBasicP$m_head = 255;
    SchedulerBasicP$m_tail = 255;
  }
}

# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static  void RealMainP$Scheduler$init(void){
#line 46
  SchedulerBasicP$Scheduler$init();
#line 46
}
#line 46
# 106 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P14$set(void)
#line 106
{
#line 106
  P1_4 = 1;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led2$set(void){
#line 29
  HplCC2430GeneralIOC$P14$set();
#line 29
}
#line 29
# 105 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P13$set(void)
#line 105
{
#line 105
  P1_3 = 1;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led1$set(void){
#line 29
  HplCC2430GeneralIOC$P13$set();
#line 29
}
#line 29
# 104 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P12$set(void)
#line 104
{
#line 104
  P1_2 = 1;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led0$set(void){
#line 29
  HplCC2430GeneralIOC$P12$set();
#line 29
}
#line 29
# 106 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P14$makeOutput(void)
#line 106
{
#line 106
  P1_DIR |= (unsigned char )(unsigned char )(1 << 4);
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led2$makeOutput(void){
#line 35
  HplCC2430GeneralIOC$P14$makeOutput();
#line 35
}
#line 35
# 105 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P13$makeOutput(void)
#line 105
{
#line 105
  P1_DIR |= (unsigned char )(unsigned char )(1 << 3);
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led1$makeOutput(void){
#line 35
  HplCC2430GeneralIOC$P13$makeOutput();
#line 35
}
#line 35
# 104 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P12$makeOutput(void)
#line 104
{
#line 104
  P1_DIR |= (unsigned char )(unsigned char )(1 << 2);
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led0$makeOutput(void){
#line 35
  HplCC2430GeneralIOC$P12$makeOutput();
#line 35
}
#line 35
# 45 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline  error_t LedsP$Init$init(void)
#line 45
{
  /* atomic removed: atomic calls only */
#line 46
  {
    ;
    LedsP$Led0$makeOutput();
    LedsP$Led1$makeOutput();
    LedsP$Led2$makeOutput();
    LedsP$Led0$set();
    LedsP$Led1$set();
    LedsP$Led2$set();
  }
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static  error_t PlatformP$LedsInit$init(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = LedsP$Init$init();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 100 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P07$clr(void)
#line 100
{
#line 100
  P0_7 = 0;
}

# 30 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void PlatformP$VDD_PW_CTRL$clr(void){
#line 30
  HplCC2430GeneralIOC$P07$clr();
#line 30
}
#line 30
# 100 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P07$makeOutput(void)
#line 100
{
#line 100
  P0_DIR |= (unsigned char )(unsigned char )(1 << 7);
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void PlatformP$VDD_PW_CTRL$makeOutput(void){
#line 35
  HplCC2430GeneralIOC$P07$makeOutput();
#line 35
}
#line 35
# 10 "/opt/tinyos-2.x/tos/platforms/cc2431/PlatformP.nc"
static inline  error_t PlatformP$Init$init(void)
#line 10
{
  uint8_t new_clkcon;




  TOS_NODE_ID = 1;



  SLEEP = (SLEEP & (unsigned char )~CC2430_SLEEP_MODE_MASK) | CC2430_SLEEP_POWERMODE_0;


  SLEEP &= (unsigned char )~ (unsigned char )(1 << CC2430_SLEEP_OSC_PD);
  while (!(SLEEP & (unsigned char )(1 << CC2430_SLEEP_XOSC_STB))) ;

  new_clkcon = 0x0;
  new_clkcon = (new_clkcon & (unsigned char )~CC2430_CLKCON_TICKSPD_MASK) | CC2430_TICKF_DIV_1;
  new_clkcon &= (unsigned char )~ (unsigned char )(1 << CC2430_CLKCON_OSC32K);
  new_clkcon &= (unsigned char )~ (unsigned char )(1 << CC2430_CLKCON_OSC);

  new_clkcon |= (unsigned char )(1 << CC2430_CLKCON_TICKSPD);

  CLKCON = new_clkcon;
  while (CLKCON != new_clkcon) ;

  PlatformP$VDD_PW_CTRL$makeOutput();
  PlatformP$VDD_PW_CTRL$clr();


  PlatformP$LedsInit$init();
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static  error_t RealMainP$PlatformInit$init(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = PlatformP$Init$init();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 54 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static  bool RealMainP$Scheduler$runNextTask(void){
#line 54
  unsigned char result;
#line 54

#line 54
  result = SchedulerBasicP$Scheduler$runNextTask();
#line 54

#line 54
  return result;
#line 54
}
#line 54
# 103 "Adhoc_APPM.nc"
static inline  void Adhoc_APPM$Serial_Send$sendDone(message_t *msg, error_t error)
#line 103
{
}

# 122 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$default$sendDone(uint8_t id, message_t *msg, error_t result)
#line 122
{
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$sendDone(am_id_t arg_0x1ac4ae98, message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068){
#line 99
  switch (arg_0x1ac4ae98) {
#line 99
    case SERIAL_ADHOC:
#line 99
      Adhoc_APPM$Serial_Send$sendDone(arg_0x1a7e4eb8, arg_0x1a7e3068);
#line 99
      break;
#line 99
    default:
#line 99
      /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$default$sendDone(arg_0x1ac4ae98, arg_0x1a7e4eb8, arg_0x1a7e3068);
#line 99
      break;
#line 99
    }
#line 99
}
#line 99
# 138 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$runTask(void)
#line 138
{
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendProcessing = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$sendDone(/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sendingid, /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sending_msg, SUCCESS);
}

# 104 "Adhoc_APPM.nc"
static inline  message_t *Adhoc_APPM$Serial_Receive$receive(message_t *msg, void *payload, uint8_t len)
#line 104
{
#line 104
  return msg;
}

# 133 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline   message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$default$receive(uint8_t id, message_t *msg, void *payload, uint8_t len)
#line 133
{
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static  message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$receive(am_id_t arg_0x1ac49850, message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010){
#line 67
  struct message_t *result;
#line 67

#line 67
  switch (arg_0x1ac49850) {
#line 67
    case SERIAL_ADHOC:
#line 67
      result = Adhoc_APPM$Serial_Receive$receive(arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67
      break;
#line 67
    default:
#line 67
      result = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$default$receive(arg_0x1ac49850, arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67
      break;
#line 67
    }
#line 67

#line 67
  return result;
#line 67
}
#line 67
# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBG.nc"
inline static   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBG$UARTSend(uint8_t *arg_0x1a8868c0, uint8_t arg_0x1a886a48){
#line 30
  SCSuartDBGM$SCSuartDBG$UARTSend(arg_0x1a8868c0, arg_0x1a886a48);
#line 30
}
#line 30
# 149 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$runTask(void)
#line 149
{
  cc2430_header_t *CC2430_pack = (cc2430_header_t *)&/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag;

#line 151
  if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvAckType == SERIAL_PROTO_PACKET_ACK) {
      uint8_t ACKpacket[6] = { 0x7E, 0x43, 0x00, 0x9F, 0x58, 0x7E };

#line 153
      /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBG$UARTSend(ACKpacket, 6);
    }
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Receive$receive(CC2430_pack->type, &/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag, /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag.data, CC2430_pack->length);
}

# 98 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline   void LedsP$Leds$led2Off(void)
#line 98
{
  LedsP$Led2$set();
  ;
#line 100
  ;
}

# 83 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
inline static   void Adhoc_APPM$Leds$led2Off(void){
#line 83
  LedsP$Leds$led2Off();
#line 83
}
#line 83
# 75 "Adhoc_APPM.nc"
static inline  void Adhoc_APPM$Rout_Send$sendDone(message_t *msg, error_t error)
#line 75
{
  if (error == SUCCESS) {
      Adhoc_APPM$Leds$led2Off();
    }
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void FloodingM$SendFromAPP$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068){
#line 99
  Adhoc_APPM$Rout_Send$sendDone(arg_0x1a7e4eb8, arg_0x1a7e3068);
#line 99
}
#line 99
# 145 "FloodingM.nc"
static inline  void FloodingM$SendToMAC$sendDone(message_t *msg, error_t error)
#line 145
{
  FloodingM$SendFromAPP$sendDone(msg, error);
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068){
#line 99
  FloodingM$SendToMAC$sendDone(arg_0x1a7e4eb8, arg_0x1a7e3068);
#line 99
}
#line 99
# 57 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err)
#line 57
{
  /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(m, err);
}

# 183 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static inline   void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 183
{
}

# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(uint8_t arg_0x1abf9f28, message_t *arg_0x1abd4a28, error_t arg_0x1abd4bb0){
#line 89
  switch (arg_0x1abf9f28) {
#line 89
    case 0U:
#line 89
      /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(arg_0x1abd4a28, arg_0x1abd4bb0);
#line 89
      break;
#line 89
    default:
#line 89
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(arg_0x1abf9f28, arg_0x1abd4a28, arg_0x1abd4bb0);
#line 89
      break;
#line 89
    }
#line 89
}
#line 89
# 143 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static inline  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void)
#line 143
{
  message_t *msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg;

#line 145
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current, msg, FAIL);
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
}

#line 68
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void)
#line 68
{
  uint16_t i;
  uint8_t initial = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current;

#line 71
  if (initial == /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY) {
      initial = 0;
    }
  i = initial;
  for (; i < initial + 1; i++) {
      uint8_t client = (uint8_t )i % 1;

#line 77
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[client].msg != (void *)0) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = client;
          return;
        }
    }
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY;
}

# 271 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  uint8_t CC2430ActiveMessageM$Packet$payloadLength(message_t *msg)
#line 271
{
  return ((cc2430_header_t *)msg)->length;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static  uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t *arg_0x1a9d4bd0){
#line 67
  unsigned char result;
#line 67

#line 67
  result = CC2430ActiveMessageM$Packet$payloadLength(arg_0x1a9d4bd0);
#line 67

#line 67
  return result;
#line 67
}
#line 67
# 91 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
static inline bool SchedulerBasicP$isWaiting(uint8_t id)
{
  return SchedulerBasicP$m_next[id] != 255 || SchedulerBasicP$m_tail == id;
}

static inline bool SchedulerBasicP$pushTask(uint8_t id)
{
  if (!SchedulerBasicP$isWaiting(id)) 
    {
      if (SchedulerBasicP$m_head == 255) 
        {
          SchedulerBasicP$m_head = id;
          SchedulerBasicP$m_tail = id;
        }
      else 
        {
          SchedulerBasicP$m_next[SchedulerBasicP$m_tail] = id;
          SchedulerBasicP$m_tail = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 247 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  am_id_t CC2430ActiveMessageM$AMPacket$type(message_t *msg)
#line 247
{
  cc2430_header_t *header = (cc2430_header_t *)msg;

#line 249
  return header->type;
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void CC2430ActiveMessageM$AMSend$sendDone(am_id_t arg_0x1a9f23d8, message_t *arg_0x1a7e4eb8, error_t arg_0x1a7e3068){
#line 99
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(arg_0x1a9f23d8, arg_0x1a7e4eb8, arg_0x1a7e3068);
#line 99
}
#line 99
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t CC2430ActiveMessageM$Backoff_Task$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(CC2430ActiveMessageM$Backoff_Task);
#line 56

#line 56
  return result;
#line 56
}
#line 56
inline static   error_t HAL_CC2430ControlM$transmitTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$transmitTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 187 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$CC2430_TX_RX$sendPacket(uint8_t *packet)
#line 187
{
  if (packet[0] > 127 || HAL_CC2430ControlM$transmitInProgress == TRUE) {
    return;
    }
#line 190
  memcpy(HAL_CC2430ControlM$transmitPacket, packet, packet[0]);
  HAL_CC2430ControlM$transmitPacketPtr = HAL_CC2430ControlM$transmitPacket;
  HAL_CC2430ControlM$transmitTask$postTask();
}

# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
inline static  void CC2430ActiveMessageM$CC2430_TX_RX$sendPacket(uint8_t *arg_0x1aa16030){
#line 14
  HAL_CC2430ControlM$CC2430_TX_RX$sendPacket(arg_0x1aa16030);
#line 14
}
#line 14
# 364 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  uint8_t HAL_CC2430ControlM$CC2430Control$GetCCA(void)
#line 364
{
#line 364
  return * (uint8_t_xdata *)0xDF62 & (unsigned char )(1 << CC2430_RFSTATUS_CCA);
}

# 27 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430Control.nc"
inline static  uint8_t CC2430ActiveMessageM$CC2430Control$GetCCA(void){
#line 27
  unsigned char result;
#line 27

#line 27
  result = HAL_CC2430ControlM$CC2430Control$GetCCA();
#line 27

#line 27
  return result;
#line 27
}
#line 27
# 70 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void CC2430ActiveMessageM$BackoffTimer$fired(void)
#line 70
{
  if (CC2430ActiveMessageM$CC2430Control$GetCCA() == 1) {
      CC2430ActiveMessageM$CC2430_TX_RX$sendPacket((uint8_t *)CC2430ActiveMessageM$TX_Ready_Msg);
    }
  else {
      if (CC2430ActiveMessageM$NumReTX < 4) {
          CC2430ActiveMessageM$NumReTX++;
          CC2430ActiveMessageM$Backoff_Task$postTask();
        }
      else 
#line 78
        {
          CC2430ActiveMessageM$RF_Status = RF_IDLE;
          CC2430ActiveMessageM$NumReTX = 0;
          CC2430ActiveMessageM$AMSend$sendDone(CC2430ActiveMessageM$AMPacket$type((message_t *)CC2430ActiveMessageM$TX_Ready_Msg), (message_t *)CC2430ActiveMessageM$TX_Ready_Msg, FAIL);
        }
    }
}

# 16 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
inline static  void Hpl_Backoff_Timer3M$Backoff$fired(void){
#line 16
  CC2430ActiveMessageM$BackoffTimer$fired();
#line 16
}
#line 16
# 51 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_Backoff_Timer3M.nc"
static inline  void Hpl_Backoff_Timer3M$EventFired$runTask(void)
#line 51
{
#line 51
  Hpl_Backoff_Timer3M$Backoff$fired();
}

# 128 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline void HAL_CC2430ControlM$flushRXBufferTask(void)
#line 128
{
  RFST = 0xE6;
  RFST = 0xE6;
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t HAL_CC2430ControlM$ReceivedPacketDone$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$ReceivedPacketDone);
#line 56

#line 56
  return result;
#line 56
}
#line 56
inline static   error_t HAL_CC2430ControlM$sendPacketDoneSUCCTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$sendPacketDoneSUCCTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 98 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$stop(uint8_t num)
#line 98
{
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[num].mState = 0;
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void HAL_CC2430ControlM$ACK_TimeOut$stop(void){
#line 67
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$stop(3U);
#line 67
}
#line 67
# 13 "/opt/tinyos-2.x/tos/platforms/cc2431/BusyWaitMicroC.nc"
static __inline   void BusyWaitMicroC$BusyWait$wait(uint16_t dt)
#line 13
{
  while (dt) {
      BusyWaitMicroC$MicroValue_ = 0;
      BusyWaitMicroC$MicroValue_ = 0;
      BusyWaitMicroC$MicroValue_ = 0;
      dt--;
    }
}

# 55 "/opt/tinyos-2.x/tos/lib/timer/BusyWait.nc"
inline static   void HAL_CC2430ControlM$BusyWait$wait(HAL_CC2430ControlM$BusyWait$size_type arg_0x1aa90e00){
#line 55
  BusyWaitMicroC$BusyWait$wait(arg_0x1aa90e00);
#line 55
}
#line 55
# 253 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$receivedPacketTask$runTask(void)
#line 253
{
  uint8_t frameLength;
#line 254
  uint8_t correlation;
#line 254
  uint8_t i;


  frameLength = RFD;

  if (frameLength < 127) {
      HAL_CC2430ControlM$receivedPacket[0] = frameLength;
    }
  else {

      HAL_CC2430ControlM$flushRXBufferTask();
      RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_FIFOP);
      return;
    }


  if (frameLength > * (uint8_t_xdata *)0xDF53) {
      for (i = 0; i < 20; i++) {
          HAL_CC2430ControlM$BusyWait$wait(320);
          if (frameLength <= * (uint8_t_xdata *)0xDF53) {
            break;
            }
        }
      if (frameLength > * (uint8_t_xdata *)0xDF53) {
          HAL_CC2430ControlM$flushRXBufferTask();
          RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_FIFOP);
          return;
        }
    }


  for (i = 0; i < frameLength; i++) {
      if (0 < * (uint8_t_xdata *)0xDF53 && * (uint8_t_xdata *)0xDF53 < 129) {
          HAL_CC2430ControlM$receivedPacket[i + 1] = RFD;
        }
      else 
#line 288
        {
          HAL_CC2430ControlM$flushRXBufferTask();
          RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_FIFOP);
          return;
        }
    }


  if (HAL_CC2430ControlM$receivedPacket[frameLength] & 0x80) {



      if ((HAL_CC2430ControlM$receivedPacket[1] & 0x03) == IEEE154_TYPE_ACK) {
          if (HAL_CC2430ControlM$WaitACK_Flag) {
              HAL_CC2430ControlM$ACK_TimeOut$stop();
              HAL_CC2430ControlM$WaitACK_Flag = 0;
              HAL_CC2430ControlM$transmitInProgress = FALSE;
              HAL_CC2430ControlM$sendPacketDoneSUCCTask$postTask();
            }
        }
      else {
          HAL_CC2430ControlM$ReceivedPacketDone$postTask();
        }
    }

  HAL_CC2430ControlM$flushRXBufferTask();
  RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_FIFOP);
}

# 261 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline   message_t *CC2430ActiveMessageM$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 261
{
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static  message_t *CC2430ActiveMessageM$Snoop$receive(am_id_t arg_0x1a9f14e0, message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010){
#line 67
  struct message_t *result;
#line 67

#line 67
    result = CC2430ActiveMessageM$Snoop$default$receive(arg_0x1a9f14e0, arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67

#line 67
  return result;
#line 67
}
#line 67
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t FloodingM$Forwarding_task$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(FloodingM$Forwarding_task);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 154 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void *CC2430ActiveMessageM$AMSend$getPayload(am_id_t id, message_t *m)
#line 154
{
  return CC2430ActiveMessageM$Packet$getPayload(m, (void *)0);
}

# 125 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void */*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$getPayload(am_id_t arg_0x1abf8bc8, message_t *arg_0x1a7e3b18){
#line 125
  void *result;
#line 125

#line 125
  result = CC2430ActiveMessageM$AMSend$getPayload(arg_0x1abf8bc8, arg_0x1a7e3b18);
#line 125

#line 125
  return result;
#line 125
}
#line 125
# 179 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static inline  void */*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$getPayload(uint8_t id, message_t *m)
#line 179
{
  return /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$getPayload(0, m);
}

# 114 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static  void */*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$getPayload(message_t *arg_0x1abd3698){
#line 114
  void *result;
#line 114

#line 114
  result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$getPayload(0U, arg_0x1abd3698);
#line 114

#line 114
  return result;
#line 114
}
#line 114
# 65 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline  void */*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$getPayload(message_t *m)
#line 65
{
  return /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$getPayload(m);
}

# 125 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void *FloodingM$SendToMAC$getPayload(message_t *arg_0x1a7e3b18){
#line 125
  void *result;
#line 125

#line 125
  result = /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$getPayload(arg_0x1a7e3b18);
#line 125

#line 125
  return result;
#line 125
}
#line 125
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t FloodingM$RecvToAPP_task$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(FloodingM$RecvToAPP_task);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 161 "FloodingM.nc"
static inline  message_t *FloodingM$RecvFromMAC$receive(message_t *msg, void *payload, uint8_t len)
#line 161
{

  Route_Msg *pack = (Route_Msg *)FloodingM$SendToMAC$getPayload(msg);

  if (pack->FinalDstAddr == TOS_NODE_ID) {


      if (!FloodingM$isRecvPrevious(msg)) 

        {
          memcpy((void *)&FloodingM$RecvMsg, (void *)msg, sizeof(message_t ));
          FloodingM$insertMSGtoRTable(msg);
          FloodingM$RecvToAPP_task$postTask();
        }
    }
  else {
      if (!FloodingM$isRecvPrevious(msg)) {
          if (pack->TTL > 0) {
              pack->TTL--;

              FloodingM$Forward_Buff_Index++;
              FloodingM$Forward_Buff_Index %= 5;
              memcpy((void *)&FloodingM$ForwardMsg[FloodingM$Forward_Buff_Index], (void *)msg, sizeof(message_t ));


              {
                Route_Msg Forward_NWKF;

                memcpy(&Forward_NWKF, FloodingM$SendToMAC$getPayload(&FloodingM$ForwardMsg[FloodingM$Forward_Buff_Index]), sizeof(Route_Msg ));
                Forward_NWKF.FrameControl = 5;
                if (Forward_NWKF.Dst2_for_multihop == 0xFFFE) {
                    Forward_NWKF.Dst2_for_multihop = TOS_NODE_ID;
                  }
                else 
#line 193
                  {
                    Forward_NWKF.Dst3_for_multihop = Forward_NWKF.Dst2_for_multihop;
                    Forward_NWKF.Dst2_for_multihop = TOS_NODE_ID;
                  }
                memcpy(FloodingM$SendToMAC$getPayload(&FloodingM$ForwardMsg[FloodingM$Forward_Buff_Index]), &Forward_NWKF, sizeof(Route_Msg ));
              }

              FloodingM$Forwarding_task$postTask();
            }
        }
    }
  return msg;
}

# 257 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline   message_t *CC2430ActiveMessageM$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 257
{
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static  message_t *CC2430ActiveMessageM$Receive$receive(am_id_t arg_0x1a9f2d08, message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010){
#line 67
  struct message_t *result;
#line 67

#line 67
  switch (arg_0x1a9f2d08) {
#line 67
    case 11:
#line 67
      result = FloodingM$RecvFromMAC$receive(arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67
      break;
#line 67
    default:
#line 67
      result = CC2430ActiveMessageM$Receive$default$receive(arg_0x1a9f2d08, arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67
      break;
#line 67
    }
#line 67

#line 67
  return result;
#line 67
}
#line 67
# 222 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  am_addr_t CC2430ActiveMessageM$AMPacket$destination(message_t *msg)
#line 222
{
  cc2430_header_t *header = (cc2430_header_t *)msg;

#line 224
  return header->dest;
}

#line 218
static inline  am_addr_t CC2430ActiveMessageM$AMPacket$address(void)
#line 218
{
  return TOS_NODE_ID;
}

#line 242
static inline  bool CC2430ActiveMessageM$AMPacket$isForMe(message_t *msg)
#line 242
{
  return CC2430ActiveMessageM$AMPacket$destination(msg) == CC2430ActiveMessageM$AMPacket$address() || 
  CC2430ActiveMessageM$AMPacket$destination(msg) == AM_BROADCAST_ADDR;
}

#line 176
static inline  void CC2430ActiveMessageM$CC2430_TX_RX$receivedPacket(uint8_t *RXPacket)
#line 176
{
  message_t *msg = (message_t *)RXPacket;
  cc2430_header_t *header = (cc2430_header_t *)msg->header;
  cc2430_metadata_t *metadata = (cc2430_metadata_t *)msg->metadata;

#line 198
  header->length -= 12;

  metadata->rssi = (char )msg->data[header->length];
  metadata->lqi = msg->data[header->length + 1] & 0x7F;
  metadata->crc = (msg->data[header->length + 1] & 0x80) >> 7;





  if (CC2430ActiveMessageM$AMPacket$isForMe(msg)) {
      CC2430ActiveMessageM$Receive$receive(CC2430ActiveMessageM$AMPacket$type(msg), msg, msg->data, header->length);
    }
  else {
      CC2430ActiveMessageM$Snoop$receive(CC2430ActiveMessageM$AMPacket$type(msg), msg, msg->data, header->length);
    }
}

# 17 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
inline static  void HAL_CC2430ControlM$CC2430_TX_RX$receivedPacket(uint8_t *arg_0x1aa16b20){
#line 17
  CC2430ActiveMessageM$CC2430_TX_RX$receivedPacket(arg_0x1aa16b20);
#line 17
}
#line 17
# 249 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$ReceivedPacketDone$runTask(void)
#line 249
{
  HAL_CC2430ControlM$CC2430_TX_RX$receivedPacket(HAL_CC2430ControlM$receivedPacket);
}

# 94 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startOneShot(uint8_t num, uint32_t dt)
#line 94
{
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$startTimer(num, dt, TRUE);
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void HAL_CC2430ControlM$ACK_TimeOut$startOneShot(uint32_t arg_0x1a796ca8){
#line 62
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startOneShot(3U, arg_0x1a796ca8);
#line 62
}
#line 62
# 210 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$ACK_TimerOutSetTask$runTask(void)
#line 210
{
  HAL_CC2430ControlM$ACK_TimeOut$startOneShot(0x10);
}

# 105 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static inline   void HplCC2430GeneralIOC$P13$toggle(void)
#line 105
{
#line 105
  if (P1_3 == 0) {
#line 105
    P1_3 = 1;
    }
  else {
#line 105
    P1_3 = 0;
    }
}

# 31 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led1$toggle(void){
#line 31
  HplCC2430GeneralIOC$P13$toggle();
#line 31
}
#line 31
# 88 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline   void LedsP$Leds$led1Toggle(void)
#line 88
{
  LedsP$Led1$toggle();
  ;
#line 90
  ;
}

# 72 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
inline static   void Adhoc_APPM$Leds$led1Toggle(void){
#line 72
  LedsP$Leds$led1Toggle();
#line 72
}
#line 72
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  error_t FloodingM$SendToMAC$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90){
#line 69
  unsigned char result;
#line 69

#line 69
  result = /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(arg_0x1a7e5a58, arg_0x1a7e5c08, arg_0x1a7e5d90);
#line 69

#line 69
  return result;
#line 69
}
#line 69
# 107 "FloodingM.nc"
static inline  error_t FloodingM$SendFromAPP$send(am_addr_t addr, message_t *msg, uint8_t len)
#line 107
{

  Route_Msg Route_M;
  void *DataPayLoad = FloodingM$SendToMAC$getPayload(msg);
  error_t return_status;

  Route_M.FrameControl = 4;
  Route_M.FinalDstAddr = addr;
  Route_M.OrigiSrcAddr = TOS_NODE_ID;
  Route_M.Sequence = FloodingM$mySequence;
  Route_M.TTL = 5;
  Route_M.Dst2_for_multihop = 0xFFFE;
  Route_M.Dst3_for_multihop = 0xFFFE;
  memcpy((void *)& Route_M.AppData, DataPayLoad, len);
  memcpy(FloodingM$SendToMAC$getPayload(&FloodingM$SendMsg), (uint8_t *)&Route_M, sizeof(Route_Msg ));

  FloodingM$mySequence++;
  FloodingM$mySequence %= 0xFF;

  return_status = FloodingM$SendToMAC$send(FloodingM$Next_Addr, &FloodingM$SendMsg, sizeof(Route_Msg ));
  if (return_status == SUCCESS) {
    FloodingM$insertMSGtoRTable(&FloodingM$SendMsg);
    }
  return return_status;
}

# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  error_t Adhoc_APPM$Rout_Send$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90){
#line 69
  unsigned char result;
#line 69

#line 69
  result = FloodingM$SendFromAPP$send(arg_0x1a7e5a58, arg_0x1a7e5c08, arg_0x1a7e5d90);
#line 69

#line 69
  return result;
#line 69
}
#line 69
# 232 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void CC2430ActiveMessageM$AMPacket$setDestination(message_t *msg, am_addr_t addr)
#line 232
{
  cc2430_header_t *header = (cc2430_header_t *)msg;

#line 234
  header->dest = addr;
}

# 92 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t *arg_0x1a803d38, am_addr_t arg_0x1a803ec8){
#line 92
  CC2430ActiveMessageM$AMPacket$setDestination(arg_0x1a803d38, arg_0x1a803ec8);
#line 92
}
#line 92
# 252 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void CC2430ActiveMessageM$AMPacket$setType(message_t *msg, am_id_t type)
#line 252
{
  cc2430_header_t *header = (cc2430_header_t *)msg;

#line 254
  header->type = type;
}

# 151 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static  void /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t *arg_0x1a801cc8, am_id_t arg_0x1a801e50){
#line 151
  CC2430ActiveMessageM$AMPacket$setType(arg_0x1a801cc8, arg_0x1a801e50);
#line 151
}
#line 151
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(am_id_t arg_0x1abf8bc8, am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90){
#line 69
  unsigned char result;
#line 69

#line 69
  result = CC2430ActiveMessageM$AMSend$send(arg_0x1abf8bc8, arg_0x1a7e5a58, arg_0x1a7e5c08, arg_0x1a7e5d90);
#line 69

#line 69
  return result;
#line 69
}
#line 69
# 67 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static  am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t *arg_0x1a803190){
#line 67
  unsigned short result;
#line 67

#line 67
  result = CC2430ActiveMessageM$AMPacket$destination(arg_0x1a803190);
#line 67

#line 67
  return result;
#line 67
}
#line 67
#line 136
inline static  am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t *arg_0x1a801740){
#line 136
  unsigned char result;
#line 136

#line 136
  result = CC2430ActiveMessageM$AMPacket$type(arg_0x1a801740);
#line 136

#line 136
  return result;
#line 136
}
#line 136
# 275 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void CC2430ActiveMessageM$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 275
{
  ((cc2430_header_t *)msg)->length = len;
}

# 83 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t *arg_0x1a9d3260, uint8_t arg_0x1a9d33e8){
#line 83
  CC2430ActiveMessageM$Packet$setPayloadLength(arg_0x1a9d3260, arg_0x1a9d33e8);
#line 83
}
#line 83
# 96 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static inline  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, uint8_t len)
#line 96
{

  if (clientId > 1) {
#line 98
      return FAIL;
    }
#line 99
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg != (void *)0) {
#line 99
      return EBUSY;
    }
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current == /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(msg);

      ;
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[clientId].msg = (void *)0;
        }
      return err;
    }
  return SUCCESS;
}

# 64 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static  error_t /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t *arg_0x1abd6920, uint8_t arg_0x1abd6aa8){
#line 64
  unsigned char result;
#line 64

#line 64
  result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(0U, arg_0x1abd6920, arg_0x1abd6aa8);
#line 64

#line 64
  return result;
#line 64
}
#line 64
# 106 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static __inline   void HplCC2430GeneralIOC$P14$clr(void)
#line 106
{
#line 106
  P1_4 = 0;
}

# 30 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led2$clr(void){
#line 30
  HplCC2430GeneralIOC$P14$clr();
#line 30
}
#line 30
# 93 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline   void LedsP$Leds$led2On(void)
#line 93
{
  LedsP$Led2$clr();
  ;
#line 95
  ;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
inline static   void Adhoc_APPM$Leds$led2On(void){
#line 78
  LedsP$Leds$led2On();
#line 78
}
#line 78
# 59 "/opt/tinyos-2.x/tos/platforms/cc2431/HplSCS_Clock_Timer1P.nc"
static inline   uint8_t HplSCS_Clock_Timer1P$Alarm$getNow(void)
#line 59
{
  uint16_t r;

  (
#line 61
  (uint8_t *)&r)[0] = T1CNTL;
  ((uint8_t *)&r)[1] = T1CNTH;
  r = r / HplSCS_Clock_Timer1P$mscale;
  return r;
}

# 13 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
inline static   uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$getNow(void){
#line 13
  unsigned char result;
#line 13

#line 13
  result = HplSCS_Clock_Timer1P$Alarm$getNow();
#line 13

#line 13
  return result;
#line 13
}
#line 13
# 67 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void HAL_CC2430ControlM$TX_TimeOut$stop(void){
#line 67
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$stop(2U);
#line 67
}
#line 67
# 206 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$TX_TimeOutStopTask$runTask(void)
#line 206
{
  HAL_CC2430ControlM$TX_TimeOut$stop();
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void HAL_CC2430ControlM$TX_TimeOut$startOneShot(uint32_t arg_0x1a796ca8){
#line 62
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startOneShot(2U, arg_0x1a796ca8);
#line 62
}
#line 62
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t HAL_CC2430ControlM$sendPacketDoneFAILTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$sendPacketDoneFAILTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 133 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline void HAL_CC2430ControlM$flushTXBufferTask(void)
#line 133
{
  RFST = 0xE7;
#line 134
  ;
}









static inline  void HAL_CC2430ControlM$transmitTask$runTask(void)
#line 145
{
  uint8_t i;


  HAL_CC2430ControlM$flushTXBufferTask();


  if (!(* (uint8_t_xdata *)0xDF62 & (unsigned char )(1 << CC2430_RFSTATUS_CCA))) {
      HAL_CC2430ControlM$SendDoneError = 0x20;
      HAL_CC2430ControlM$sendPacketDoneFAILTask$postTask();
      return;
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 158
    {
      if (HAL_CC2430ControlM$transmitPacketPtr[1] & 0x20) {
          HAL_CC2430ControlM$WaitACK_Flag = 1;
        }
      else 
#line 161
        {
          HAL_CC2430ControlM$WaitACK_Flag = 0;
        }





      RFD = HAL_CC2430ControlM$transmitPacketPtr[0];

      for (i = 1; i < HAL_CC2430ControlM$transmitPacketPtr[0]; i++) {
          RFD = HAL_CC2430ControlM$transmitPacketPtr[i];
        }

      HAL_CC2430ControlM$transmitInProgress = TRUE;


      RFST = 0xE3;

      HAL_CC2430ControlM$TX_TimeOut$startOneShot(0x28);
    }
#line 181
    __nesc_atomic_end(__nesc_atomic); }


  return;
}

# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430_TX_RX.nc"
inline static  void HAL_CC2430ControlM$CC2430_TX_RX$sendPacketDone(uint8_t *arg_0x1aa164e0, error_t arg_0x1aa16668){
#line 15
  CC2430ActiveMessageM$CC2430_TX_RX$sendPacketDone(arg_0x1aa164e0, arg_0x1aa16668);
#line 15
}
#line 15
# 202 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$sendPacketDoneFAILTask$runTask(void)
#line 202
{
  HAL_CC2430ControlM$CC2430_TX_RX$sendPacketDone(HAL_CC2430ControlM$transmitPacketPtr, HAL_CC2430ControlM$SendDoneError);
}

#line 198
static inline  void HAL_CC2430ControlM$sendPacketDoneSUCCTask$runTask(void)
#line 198
{
  HAL_CC2430ControlM$CC2430_TX_RX$sendPacketDone(HAL_CC2430ControlM$transmitPacketPtr, SUCCESS);
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t Hpl_Backoff_Timer3M$EventFired$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(Hpl_Backoff_Timer3M$EventFired);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 58 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_Backoff_Timer3M.nc"
static inline  void Hpl_Backoff_Timer3M$Backoff$start(uint8_t dt)
#line 58
{
  uint8_t r;

  if (dt == 0) {
      Hpl_Backoff_Timer3M$EventFired$postTask();
      return;
    }
  else {
#line 64
    if (dt >= 12) {
        r = 254;
      }
    else 
#line 66
      {
        r = dt * 20;
#line 67
        ;
      }
    }
  T3CNT = 0;
  T3CC0 = r;
  T3IE = 1;
  T3CTL |= (unsigned char )(1 << CC2430_T34CTL_START);
}

# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Backoff.nc"
inline static  void CC2430ActiveMessageM$BackoffTimer$start(uint8_t arg_0x1aa133b0){
#line 14
  Hpl_Backoff_Timer3M$Backoff$start(arg_0x1aa133b0);
#line 14
}
#line 14
# 41 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
inline static   uint16_t CC2430ActiveMessageM$Random$rand16(void){
#line 41
  unsigned short result;
#line 41

#line 41
  result = RandomC$Random$rand16();
#line 41

#line 41
  return result;
#line 41
}
#line 41
# 60 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  void CC2430ActiveMessageM$Backoff_Task$runTask(void)
#line 60
{
  uint16_t Ran_Backoff = CC2430ActiveMessageM$Random$rand16();

#line 62
  Ran_Backoff %= 12;




  CC2430ActiveMessageM$BackoffTimer$start(Ran_Backoff);
}

# 156 "FloodingM.nc"
static inline  void FloodingM$Forwarding_task$runTask(void)
#line 156
{
  if (FloodingM$SendToMAC$send(FloodingM$Next_Addr, &FloodingM$ForwardMsg[FloodingM$Forward_Buff_Index], sizeof(Route_Msg )) == SUCCESS) {
    FloodingM$insertMSGtoRTable(&FloodingM$ForwardMsg[FloodingM$Forward_Buff_Index]);
    }
}

# 104 "/opt/tinyos-2.x/tos/chips/cc2430/pins/HplCC2430GeneralIOC.nc"
static inline   void HplCC2430GeneralIOC$P12$toggle(void)
#line 104
{
#line 104
  if (P1_2 == 0) {
#line 104
    P1_2 = 1;
    }
  else {
#line 104
    P1_2 = 0;
    }
}

# 31 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static   void LedsP$Led0$toggle(void){
#line 31
  HplCC2430GeneralIOC$P12$toggle();
#line 31
}
#line 31
# 73 "/opt/tinyos-2.x/tos/platforms/cc2431/LedsP.nc"
static inline   void LedsP$Leds$led0Toggle(void)
#line 73
{
  LedsP$Led0$toggle();
  ;
#line 75
  ;
}

# 56 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
inline static   void Adhoc_APPM$Leds$led0Toggle(void){
#line 56
  LedsP$Leds$led0Toggle();
#line 56
}
#line 56
# 18 "/opt/tinyos-2.x/tos/platforms/cc2431/platform.h"
static inline unsigned short nx_16_t_change(unsigned short cvalue)
#line 18
{
  unsigned char *base = (unsigned char *)&cvalue;

#line 20
  return ((unsigned short )base[0] << 8) | base[1];
}

# 55 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline serial_header_t */*SerialActiveMessageC.AM*/SerialActiveMessageP$0$getHeader(message_t *msg)
#line 55
{
  char *ptr = (char *)msg;

#line 57
  ptr += 4;
  return (serial_header_t *)ptr;
}

static inline  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$send(am_id_t id, am_addr_t dest, message_t *msg, uint8_t len)
#line 61
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$getHeader(msg);
  uint8_t SendInsert = 0;
#line 63
  uint8_t i;
#line 63
  uint8_t *pack;
#line 63
  uint8_t PacketLen = len + sizeof(serial_header_t );
  uint16_t txCRC = 0;

  if (len > 28) {
    return FALSE;
    }
  pack = (uint8_t *)header;

  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sendingid = id;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Sending_msg = msg;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendProcessing = 1;

  header->dest = nx_16_t_change(dest);

  header->group = 0;
  header->type = id;
  header->length = len;

  SendInsert = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x7E;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = SERIAL_PROTO_PACKET_NOACK;
  txCRC = crcByte(txCRC, SERIAL_PROTO_PACKET_NOACK);
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = TOS_SERIAL_ACTIVE_MESSAGE_ID;
  txCRC = crcByte(txCRC, TOS_SERIAL_ACTIVE_MESSAGE_ID);

  for (i = 0; i < PacketLen; i++) {
      if (pack[i] == 0x7D) {
          /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x7D;
          /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x5D;
          txCRC = crcByte(txCRC, 0x7D);
        }
      else {
#line 93
        if (pack[i] == 0x7E) {
            /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x7D;
            /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x5E;
            txCRC = crcByte(txCRC, 0x7E);
          }
        else 
#line 97
          {
            /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = pack[i];
            txCRC = crcByte(txCRC, pack[i]);
          }
        }
    }
#line 102
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = (uint8_t )(txCRC & 0x00FF);
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = (uint8_t )((txCRC & 0xFF00) >> 8);
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff[SendInsert++] = 0x7E;

  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBG$UARTSend(/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendBuff, SendInsert);

  return SUCCESS;
}

# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  error_t Adhoc_APPM$Serial_Send$send(am_addr_t arg_0x1a7e5a58, message_t *arg_0x1a7e5c08, uint8_t arg_0x1a7e5d90){
#line 69
  unsigned char result;
#line 69

#line 69
  result = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMSend$send(SERIAL_ADHOC, arg_0x1a7e5a58, arg_0x1a7e5c08, arg_0x1a7e5d90);
#line 69

#line 69
  return result;
#line 69
}
#line 69
# 265 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMPacket$setSource(message_t *amsg, am_addr_t addr)
#line 265
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$getHeader(amsg);

#line 267
  header->src = addr;
}

# 110 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static  void Adhoc_APPM$Serial_Packet$setSource(message_t *arg_0x1a802600, am_addr_t arg_0x1a802790){
#line 110
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$AMPacket$setSource(arg_0x1a802600, arg_0x1a802790);
#line 110
}
#line 110
# 125 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static  void *Adhoc_APPM$Rout_Send$getPayload(message_t *arg_0x1a7e3b18){
#line 125
  void *result;
#line 125

#line 125
  result = FloodingM$SendFromAPP$getPayload(arg_0x1a7e3b18);
#line 125

#line 125
  return result;
#line 125
}
#line 125
# 81 "Adhoc_APPM.nc"
static inline  message_t *Adhoc_APPM$Rout_Receive$receive(message_t *msg, void *payload, uint8_t len)
#line 81
{

  uint8_t Serial_Len;

  if (TOS_NODE_ID == 0) {
      Adhoc_APP_Msg *pack = (Adhoc_APP_Msg *)Adhoc_APPM$Rout_Send$getPayload(&Adhoc_APPM$Serial_MSG);





      memcpy((void *)pack, payload, sizeof(Adhoc_APP_Msg ));
      Serial_Len = sizeof(Adhoc_APP_Msg );


      Adhoc_APPM$Serial_Packet$setSource(&Adhoc_APPM$Serial_MSG, pack->Sender_Addr);
      if (Adhoc_APPM$Serial_Send$send(0, &Adhoc_APPM$Serial_MSG, Serial_Len) == SUCCESS) {
        Adhoc_APPM$Leds$led0Toggle();
        }
    }
#line 100
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static  message_t *FloodingM$RecvToAPP$receive(message_t *arg_0x1a7f6ca0, void *arg_0x1a7f6e40, uint8_t arg_0x1a7f5010){
#line 67
  struct message_t *result;
#line 67

#line 67
  result = Adhoc_APPM$Rout_Receive$receive(arg_0x1a7f6ca0, arg_0x1a7f6e40, arg_0x1a7f5010);
#line 67

#line 67
  return result;
#line 67
}
#line 67
# 151 "FloodingM.nc"
static inline  void FloodingM$RecvToAPP_task$runTask(void)
#line 151
{
  memcpy(&FloodingM$NWKF, FloodingM$SendToMAC$getPayload(&FloodingM$RecvMsg), sizeof(Route_Msg ));
  FloodingM$RecvToAPP$receive(&FloodingM$RecvMsg, (void *)& FloodingM$NWKF.AppData, sizeof(Route_Msg ));
}

# 14 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
inline static   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$start(uint8_t arg_0x1a872b80){
#line 14
  HplSCS_Clock_Timer1P$Alarm$start(arg_0x1a872b80);
#line 14
}
#line 14
# 174 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
inline static void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$adjustInterval(void)
#line 174
{
  uint8_t i;
#line 175
  uint8_t val = /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$maxTimerInterval;

#line 176
  for (i = 0; i < /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS; i++) {
      if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].mState && /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticksLeft < (uint32_t )val) {
          val = (uint8_t )/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticksLeft;
        }
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 181
    {
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval = val;
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$start(/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval);
    }
#line 184
    __nesc_atomic_end(__nesc_atomic); }
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 150 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$enqueue(uint8_t value)
#line 150
{
  if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail == /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS - 1) {
    /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail = -1;
    }
#line 153
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail++;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_size++;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue[(uint8_t )/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail] = value;
}

#line 125
static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$runTask(void)
#line 125
{
  uint8_t i;

#line 127
  for (i = 0; i < /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS; i++) {
      if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].mState) {




          /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticksLeft -= /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval;


          if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticksLeft <= 2) {
              if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].isoneshot == TRUE) {
                  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].mState = 0;
                }
              else 
#line 139
                {
                  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticksLeft += /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].ticks;
                }
              /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$enqueue(i);
              /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$postTask();
            }
        }
    }
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$adjustInterval();
}

# 214 "FloodingM.nc"
static inline  void FloodingM$Timer$fired(void)
#line 214
{
}

# 109 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$default$fired(uint8_t num)
#line 109
{
}

# 72 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$fired(uint8_t arg_0x1a8627e8){
#line 72
  switch (arg_0x1a8627e8) {
#line 72
    case 0U:
#line 72
      Adhoc_APPM$Timer$fired();
#line 72
      break;
#line 72
    case 1U:
#line 72
      FloodingM$Timer$fired();
#line 72
      break;
#line 72
    case 2U:
#line 72
      HAL_CC2430ControlM$TX_TimeOut$fired();
#line 72
      break;
#line 72
    case 3U:
#line 72
      HAL_CC2430ControlM$ACK_TimeOut$fired();
#line 72
      break;
#line 72
    default:
#line 72
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$default$fired(arg_0x1a8627e8);
#line 72
      break;
#line 72
    }
#line 72
}
#line 72
# 158 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline uint8_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$dequeue(void)
#line 158
{
  if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_size == 0) {
    return /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS;
    }
#line 161
  if (/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head == /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS - 1) {
    /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head = -1;
    }
#line 163
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head++;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_size--;
  return /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue[(uint8_t )/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head];
}

static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$runTask(void)
#line 168
{
  uint8_t itimer = /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$dequeue();

#line 170
  if (itimer < /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS) {
    /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$fired(itimer);
    }
}

# 48 "/opt/tinyos-2.x/tos/types/TinyError.h"
static inline error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 13 "/opt/tinyos-2.x/tos/platforms/cc2431/NoSCSuartDBGC.nc"
static inline  error_t NoSCSuartDBGC$StdControl$start(void)
#line 13
{
#line 13
  return SUCCESS;
}

# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$SCSuartSTD$start(void){
#line 73
  unsigned char result;
#line 73

#line 73
  result = NoSCSuartDBGC$StdControl$start();
#line 73

#line 73
  return result;
#line 73
}
#line 73
# 20 "/opt/tinyos-2.x/tos/platforms/cc2431/HplSCS_Clock_Timer1P.nc"
static inline  error_t HplSCS_Clock_Timer1P$Init$init(void)
#line 20
{

  uint8_t *defaultPtr;
  uint16_t default_set = 230 * HplSCS_Clock_Timer1P$mscale;


  T1CCTL1 = 0;
  T1CCTL2 = 0;
  T1CNTL = 0;
  T1CNTH = 0;
  T1CCTL0 = 0;
  T1CTL = 0;




  T1CTL = (unsigned char )CC2430_TIMER1_DIV_128;


  T1IE = 1;
  TIMIF |= (unsigned char )(1 << CC2430_TIMIF_OVFIM);

  defaultPtr = (uint8_t *)&default_set;
  T1CC0L = defaultPtr[0];
  T1CC0H = defaultPtr[1];

  T1CTL |= CC2430_T1_CH0IF;
  T1CTL |= CC2430_TIMER1_MODE_MODULO;


  T1CCTL0 |= (unsigned char )(1 << CC2430_T1CCTLx_IM) | (unsigned char )(1 << CC2430_T1CCTLx_MODE);

  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliInit$init(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = HplSCS_Clock_Timer1P$Init$init();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 44 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline  error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Init$init(void)
#line 44
{
  uint8_t i;

#line 46
  for (i = 0; i < /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS; i++) 
    /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[i].mState = 0;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$setIntervalFlag = 0;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_head = /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_tail = -1;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$queue_size = 0;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval = /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$maxTimerInterval;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliInit$init();
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$SCSuartSTD$start();
  return SUCCESS;
}

# 80 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
static inline   error_t Hpl_CC2430InterruptsC$InterruptRFErr$enableRisingEdge(void)
#line 80
{
  /* atomic removed: atomic calls only */
#line 81
  {
    RFERRIF = 0;
    RFERRIE = 1;
  }
  return SUCCESS;
}

# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   error_t HAL_CC2430ControlM$InterruptRFErr$enableRisingEdge(void){
#line 42
  unsigned char result;
#line 42

#line 42
  result = Hpl_CC2430InterruptsC$InterruptRFErr$enableRisingEdge();
#line 42

#line 42
  return result;
#line 42
}
#line 42
# 74 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
static inline   error_t Hpl_CC2430InterruptsC$InterruptTXDone$enableRisingEdge(void)
#line 74
{
  /* atomic removed: atomic calls only */
#line 74
  {
#line 74
    RFIM |= (unsigned char )(1 << CC2430_RFIM_TXDONE);
#line 74
    RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_TXDONE);
#line 74
    IEN2 |= (unsigned char )(1 << CC2430_IEN2_RFIE);
  }
#line 74
  return SUCCESS;
}

# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   error_t HAL_CC2430ControlM$InterruptTXDone$enableRisingEdge(void){
#line 42
  unsigned char result;
#line 42

#line 42
  result = Hpl_CC2430InterruptsC$InterruptTXDone$enableRisingEdge();
#line 42

#line 42
  return result;
#line 42
}
#line 42
# 412 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline void HAL_CC2430ControlM$CC2430RFDisable(void)
#line 412
{
  * (uint8_t_xdata *)0xDF17 |= (unsigned char )(1 << CC2430_RFPWR_RREG_RADIO_PD);
}

#line 376
static inline void HAL_CC2430ControlM$CC2430AddressFilterEnable(void)
#line 376
{
#line 376
  * (uint8_t_xdata *)0xDF02 |= (unsigned char )(1 << CC2430_MDMCTRL0H_ADDR_DECODE);
}

#line 478
static inline void HAL_CC2430ControlM$CC2430PALevelSet(uint8_t new_power)
#line 478
{
  * (uint8_t_xdata *)0xDF0B = (uint8_t )new_power;
}

#line 463
static inline void HAL_CC2430ControlM$CC2430ChannelSet(uint8_t channel)
#line 463
{
  uint16_t freq;


  freq = (uint16_t )channel - 11;
  freq *= 5;
  freq += 357;
  freq |= 0x4000;

  * (uint8_t_xdata *)0xDF10 = (uint8_t )((freq & 0xFF00) >> 8);
  * (uint8_t_xdata *)0xDF11 = (uint8_t )(freq & 0x00FF);
}

#line 487
static inline void HAL_CC2430ControlM$CC2430ControlSet(void)
#line 487
{

  * (uint8_t_xdata *)0xDF02 &= (unsigned char )~ (unsigned char )(1 << CC2430_MDMCTRL0H_ADDR_DECODE);


  * (uint8_t_xdata *)0xDF03 |= (unsigned char )(1 << CC2430_MDMCTRL0L_AUTOCRC);


  * (uint8_t_xdata *)0xDF4F = 0x7F;





  return;
}

#line 378
static inline void HAL_CC2430ControlM$CC2430SetPanid(uint16_t id)
#line 378
{
  * (uint8_t_xdata *)0xDF4B = (uint8_t )((id & 0xFF00) >> 8);
  * (uint8_t_xdata *)0xDF4C = (uint8_t )(id & 0x00FF);
}

#line 382
static inline void HAL_CC2430ControlM$CC2430SetShortaddr(uint16_t shortAddr)
#line 382
{
  * (uint8_t_xdata *)0xDF4D = (uint8_t )((shortAddr & 0xFF00) >> 8);
  * (uint8_t_xdata *)0xDF4E = (uint8_t )(shortAddr & 0x00FF);
}

#line 431
static inline void HAL_CC2430ControlM$CC2430ExternalOscillator(void)
#line 431
{
  SLEEP &= (unsigned char )~ (unsigned char )(1 << CC2430_SLEEP_OSC_PD);
  CLKCON &= (unsigned char )~ (unsigned char )(1 << CC2430_CLKCON_CLKSPD);

  while (!(SLEEP & (unsigned char )(1 << CC2430_SLEEP_XOSC_STB))) ;
}

#line 387
static inline void HAL_CC2430ControlM$CC2430Reset(void)
#line 387
{

  * (uint8_t_xdata *)0xDF17 &= (unsigned char )~ (unsigned char )(1 << CC2430_RFPWR_RREG_RADIO_PD);
  * (uint8_t_xdata *)0xDF17 |= (unsigned char )(1 << CC2430_RFPWR_RREG_RADIO_PD);



  while (RFIF & (unsigned char )(1 << CC2430_RFIF_RREG_ON)) ;
}

#line 64
static inline  error_t HAL_CC2430ControlM$Init$init(void)
#line 64
{

  HAL_CC2430ControlM$CC2430Reset();


  HAL_CC2430ControlM$CC2430ExternalOscillator();


  HAL_CC2430ControlM$CC2430SetShortaddr(TOS_NODE_ID);


  HAL_CC2430ControlM$CC2430SetPanid(TOS_AM_GROUP);


  HAL_CC2430ControlM$CC2430ControlSet();


  HAL_CC2430ControlM$currentChannel = 26;
  HAL_CC2430ControlM$CC2430ChannelSet(HAL_CC2430ControlM$currentChannel);


  HAL_CC2430ControlM$currentPower = 0x5F;
  HAL_CC2430ControlM$CC2430PALevelSet(HAL_CC2430ControlM$currentPower);


  HAL_CC2430ControlM$CC2430AddressFilterEnable();




  HAL_CC2430ControlM$CC2430RFDisable();

  HAL_CC2430ControlM$InterruptTXDone$enableRisingEdge();
  HAL_CC2430ControlM$InterruptRFErr$enableRisingEdge();

  return SUCCESS;
}

# 21 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_Backoff_Timer3M.nc"
static inline  error_t Hpl_Backoff_Timer3M$Init$init(void)
#line 21
{


  T3CCTL0 = 0;
  T3CC0 = 0;
  T3CCTL1 = 0;
  T3CC1 = 0;
  T3CNT = 0;
  T3CTL = 0;


  T3CTL = CC2430_TIMER3_4_DIV_128;
  T3CTL |= (unsigned char )(1 << CC2430_T34CTL_START);
  T3CTL |= CC2430_TIMER3_4_MODE_MODULO;




  T3IF = 1;
  T3CH0IF = 1;


  T3CCTL0 |= (unsigned char )(1 << CC2430_T1CCTLx_IM) | (unsigned char )(1 << CC2430_T1CCTLx_MODE);

  return SUCCESS;
}

# 63 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static inline  error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Init$init(void)
#line 63
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY;
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static  error_t RealMainP$SoftwareInit$init(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Init$init();
#line 51
  result = ecombine(result, Hpl_Backoff_Timer3M$Init$init());
#line 51
  result = ecombine(result, HAL_CC2430ControlM$Init$init());
#line 51
  result = ecombine(result, /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$Init$init());
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 90 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline  void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startPeriodic(uint8_t num, uint32_t dt)
#line 90
{
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$startTimer(num, dt, FALSE);
}

# 53 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static  void Adhoc_APPM$Timer$startPeriodic(uint32_t arg_0x1a7966d8){
#line 53
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$startPeriodic(0U, arg_0x1a7966d8);
#line 53
}
#line 53
# 48 "Adhoc_APPM.nc"
static inline  void Adhoc_APPM$SControl$startDone(error_t error)
#line 48
{
  if (TOS_NODE_ID != 0) {
    Adhoc_APPM$Timer$startPeriodic(3000);
    }
}

# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static  void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$startDone(error_t arg_0x1a7f1030){
#line 88
  Adhoc_APPM$SControl$startDone(arg_0x1a7f1030);
#line 88
}
#line 88
# 22 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
static inline  error_t HalCC2430SimpleUartP$Init$init(void)
#line 22
{
#line 56
  PERCFG |= 0x00;


  P0SEL |= 0x0C;

  U0BAUD = 216;
  U0GCR = 10;

  U0CSR |= 0x80u | 0x40u;
  U0UCR |= 0x02u | 0x80u;


  UTX0IF = 0;
  URX0IF = 0;


  URX0IE = 1;

  IEN2 |= 1 << CC2430_IEN2_UTX0IE;





  PERCFG |= 0x02;


  P1SEL |= 0xC0;

  U1BAUD = 216;
  U1GCR = 10;

  U1CSR |= 0x80u | 0x40u;
  U1UCR |= 0x02u | 0x80u;


  UTX1IF = 0;
  URX1IF = 0;


  URX1IE = 1;

  IEN2 |= 1 << CC2430_IEN2_UTX1IE;

  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static  error_t SCSuartDBGM$Init$init(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = HalCC2430SimpleUartP$Init$init();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 51 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGM.nc"
static inline  error_t SCSuartDBGM$StdControl$start(void)
#line 51
{
  SCSuartDBGM$state = 0;
  SCSuartDBGM$buff_start = 0;
  SCSuartDBGM$buff_end = 0;
  SCSuartDBGM$Init$init();
  return SUCCESS;
}

# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$StdControl$start(void){
#line 73
  unsigned char result;
#line 73

#line 73
  result = SCSuartDBGM$StdControl$start();
#line 73

#line 73
  return result;
#line 73
}
#line 73
# 35 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline  error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$start(void)
#line 35
{
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Escape_Flag = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvAckType = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvSeq = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendProcessing = 0;
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$StdControl$start();
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$startDone(SUCCESS);
  return SUCCESS;
}

# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static  error_t Adhoc_APPM$SControl$start(void){
#line 79
  unsigned char result;
#line 79

#line 79
  result = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SplitControl$start();
#line 79

#line 79
  return result;
#line 79
}
#line 79
# 69 "FloodingM.nc"
static inline  void FloodingM$CommControl$startDone(error_t error)
#line 69
{
}

# 88 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static  void CC2430ActiveMessageM$SplitControl$startDone(error_t arg_0x1a7f1030){
#line 88
  FloodingM$CommControl$startDone(arg_0x1a7f1030);
#line 88
}
#line 88
# 53 "/opt/tinyos-2.x/tos/interfaces/ParameterInit.nc"
inline static  error_t CC2430ActiveMessageM$SeedInit$init(CC2430ActiveMessageM$SeedInit$parameter arg_0x1a9671d8){
#line 53
  unsigned char result;
#line 53

#line 53
  result = RandomC$SeedInit$init(arg_0x1a9671d8);
#line 53

#line 53
  return result;
#line 53
}
#line 53
# 359 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$CC2430Control$enableAutoAck(void)
#line 359
{
#line 359
  * (uint8_t_xdata *)0xDF03 |= (unsigned char )(unsigned char )(1 << CC2430_MDMCTRL0L_AUTOACK);
}

# 22 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430Control.nc"
inline static  void CC2430ActiveMessageM$CC2430Control$enableAutoAck(void){
#line 22
  HAL_CC2430ControlM$CC2430Control$enableAutoAck();
#line 22
}
#line 22
# 361 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline  void HAL_CC2430ControlM$CC2430Control$enableAddrDecode(void)
#line 361
{
#line 361
  HAL_CC2430ControlM$CC2430AddressFilterEnable();
}

# 24 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430Control.nc"
inline static  void CC2430ActiveMessageM$CC2430Control$enableAddrDecode(void){
#line 24
  HAL_CC2430ControlM$CC2430Control$enableAddrDecode();
#line 24
}
#line 24
# 73 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
static inline   error_t Hpl_CC2430InterruptsC$InterruptFIFOP$enableRisingEdge(void)
#line 73
{
#line 73
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 73
    {
#line 73
      RFIM |= (unsigned char )(1 << CC2430_RFIM_FIFOP);
#line 73
      RFIF &= (unsigned char )~ (unsigned char )(1 << CC2430_RFIF_FIFOP);
#line 73
      IEN2 |= (unsigned char )(1 << CC2430_IEN2_RFIE);
    }
#line 74
    __nesc_atomic_end(__nesc_atomic); }
#line 73
  return SUCCESS;
}

# 42 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   error_t HAL_CC2430ControlM$InterruptFIFOP$enableRisingEdge(void){
#line 42
  unsigned char result;
#line 42

#line 42
  result = Hpl_CC2430InterruptsC$InterruptFIFOP$enableRisingEdge();
#line 42

#line 42
  return result;
#line 42
}
#line 42
# 440 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline void HAL_CC2430ControlM$CC2430RxEnable(void)
#line 440
{

  RFST = 0xE6;
  RFST = 0xE6;


  HAL_CC2430ControlM$InterruptFIFOP$enableRisingEdge();


  RFST = 0xE2;
}

#line 400
static inline void HAL_CC2430ControlM$CC2430RFEnable(void)
#line 400
{

  * (uint8_t_xdata *)0xDF17 = 0x04;




  while (* (uint8_t_xdata *)0xDF17 & 0x10) ;
}

#line 102
static inline  error_t HAL_CC2430ControlM$StdControl$start(void)
#line 102
{


  HAL_CC2430ControlM$CC2430RFEnable();


  HAL_CC2430ControlM$CC2430RxEnable();

  HAL_CC2430ControlM$transmitInProgress = FALSE;
  HAL_CC2430ControlM$WaitACK_Flag = 0;

  return SUCCESS;
}

# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static  error_t CC2430ActiveMessageM$SubStdControl$start(void){
#line 73
  unsigned char result;
#line 73

#line 73
  result = HAL_CC2430ControlM$StdControl$start();
#line 73

#line 73
  return result;
#line 73
}
#line 73
# 40 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static inline  error_t CC2430ActiveMessageM$SplitControl$start(void)
#line 40
{
  CC2430ActiveMessageM$AckEnable = 1;
  CC2430ActiveMessageM$SubStdControl$start();
  CC2430ActiveMessageM$CC2430Control$enableAddrDecode();
  CC2430ActiveMessageM$CC2430Control$enableAutoAck();
  CC2430ActiveMessageM$RF_Status = RF_IDLE;
  CC2430ActiveMessageM$NumReTX = 0;
  CC2430ActiveMessageM$MAC_Seq = TOS_NODE_ID * 13;
  CC2430ActiveMessageM$SeedInit$init(CC2430ActiveMessageM$MAC_Seq);
  CC2430ActiveMessageM$SplitControl$startDone(SUCCESS);
  return SUCCESS;
}

# 79 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static  error_t FloodingM$CommControl$start(void){
#line 79
  unsigned char result;
#line 79

#line 79
  result = CC2430ActiveMessageM$SplitControl$start();
#line 79

#line 79
  return result;
#line 79
}
#line 79
# 41 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
inline static   uint16_t FloodingM$Random$rand16(void){
#line 41
  unsigned short result;
#line 41

#line 41
  result = RandomC$Random$rand16();
#line 41

#line 41
  return result;
#line 41
}
#line 41
# 53 "/opt/tinyos-2.x/tos/interfaces/ParameterInit.nc"
inline static  error_t FloodingM$SeedInit$init(FloodingM$SeedInit$parameter arg_0x1a9671d8){
#line 53
  unsigned char result;
#line 53

#line 53
  result = RandomC$SeedInit$init(arg_0x1a9671d8);
#line 53

#line 53
  return result;
#line 53
}
#line 53
# 46 "FloodingM.nc"
static inline  error_t FloodingM$StdControl$start(void)
#line 46
{
  uint8_t i;
  uint16_t random_num;

  FloodingM$SeedInit$init(TOS_NODE_ID);
  random_num = FloodingM$Random$rand16();

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    {
      FloodingM$Next_Addr = AM_BROADCAST_ADDR;
      FloodingM$Forward_Buff_Index = 0;
      FloodingM$RTable_Index = 0;
      FloodingM$mySequence = (uint8_t )(random_num % 0xFF);
      for (i = 0; i < 20; i++) {
          FloodingM$RTable[i].FinalDstAddr = 0xFFFE;
          FloodingM$RTable[i].OrigiSrcAddr = 0xFFFE;
          FloodingM$RTable[i].Sequence = 0xFF;
        }
    }
#line 63
    __nesc_atomic_end(__nesc_atomic); }
  FloodingM$CommControl$start();
  return SUCCESS;
}

# 73 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static  error_t Adhoc_APPM$RControl$start(void){
#line 73
  unsigned char result;
#line 73

#line 73
  result = FloodingM$StdControl$start();
#line 73

#line 73
  return result;
#line 73
}
#line 73
# 42 "Adhoc_APPM.nc"
static inline  void Adhoc_APPM$Boot$booted(void)
#line 42
{
  Adhoc_APPM$APP_Seq = 0;
  Adhoc_APPM$RControl$start();
  Adhoc_APPM$SControl$start();
}

# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
inline static  void RealMainP$Boot$booted(void){
#line 49
  Adhoc_APPM$Boot$booted();
#line 49
}
#line 49
# 103 "/opt/tinyos-2.x/tos/chips/mcs51/mcs51hardware.h"
static __inline void __nesc_disable_interrupt(void)
#line 103
{

  EA = 0;
}

#line 107
static __inline void __nesc_enable_interrupt(void)
#line 107
{

  EA = 1;
}

# 51 "/opt/tinyos-2.x/tos/chips/cc2430/McuSleepC.nc"
static inline   void McuSleepC$McuSleep$sleep(void)
#line 51
{

  __nesc_enable_interrupt();






  SLEEP = (SLEEP & (unsigned char )~CC2430_SLEEP_MODE_MASK) | CC2430_SLEEP_POWERMODE_1;

  __nesc_disable_interrupt();
}

# 59 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
inline static   void SchedulerBasicP$McuSleep$sleep(void){
#line 59
  McuSleepC$McuSleep$sleep();
#line 59
}
#line 59
# 72 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
static __inline uint8_t SchedulerBasicP$popTask(void)
{
  if (SchedulerBasicP$m_head != 255) 
    {
      uint8_t id = SchedulerBasicP$m_head;

#line 77
      SchedulerBasicP$m_head = SchedulerBasicP$m_next[SchedulerBasicP$m_head];
      if (SchedulerBasicP$m_head == 255) 
        {
          SchedulerBasicP$m_tail = 255;
        }
      SchedulerBasicP$m_next[id] = 255;
      return id;
    }
  else 
    {
      return 255;
    }
}

#line 145
static inline  void SchedulerBasicP$Scheduler$taskLoop(void)
{
  for (; ; ) 
    {
      uint8_t nextTask;

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          while ((nextTask = SchedulerBasicP$popTask()) == 255) 
            {
              SchedulerBasicP$McuSleep$sleep();
            }
        }
#line 157
        __nesc_atomic_end(__nesc_atomic); }
      SchedulerBasicP$TaskBasic$runTask(nextTask);
    }
}

# 61 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static  void RealMainP$Scheduler$taskLoop(void){
#line 61
  SchedulerBasicP$Scheduler$taskLoop();
#line 61
}
#line 61
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 119 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static inline   void /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$fired(void)
#line 119
{
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$postTask();
}

# 15 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_Clock.nc"
inline static   void HplSCS_Clock_Timer1P$Alarm$fired(void){
#line 15
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$fired();
#line 15
}
#line 15
# 137 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline   void HAL_CC2430ControlM$InterruptRFErr$fired(void)
#line 137
{
  HAL_CC2430ControlM$flushRXBufferTask();
  HAL_CC2430ControlM$flushTXBufferTask();
}

# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   void Hpl_CC2430InterruptsC$InterruptRFErr$fired(void){
#line 57
  HAL_CC2430ControlM$InterruptRFErr$fired();
#line 57
}
#line 57
# 134 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
static inline    void Hpl_CC2430InterruptsC$InterruptCCA$default$fired(void)
#line 134
{
}

# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   void Hpl_CC2430InterruptsC$InterruptCCA$fired(void){
#line 57
  Hpl_CC2430InterruptsC$InterruptCCA$default$fired();
#line 57
}
#line 57
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t HAL_CC2430ControlM$receivedPacketTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$receivedPacketTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 317 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline   void HAL_CC2430ControlM$InterruptFIFOP$fired(void)
#line 317
{
  HAL_CC2430ControlM$receivedPacketTask$postTask();
}

# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   void Hpl_CC2430InterruptsC$InterruptFIFOP$fired(void){
#line 57
  HAL_CC2430ControlM$InterruptFIFOP$fired();
#line 57
}
#line 57
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t HAL_CC2430ControlM$ACK_TimerOutSetTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$ACK_TimerOutSetTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
inline static   error_t HAL_CC2430ControlM$TX_TimeOutStopTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(HAL_CC2430ControlM$TX_TimeOutStopTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 214 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static inline   void HAL_CC2430ControlM$InterruptTXDone$fired(void)
#line 214
{



  HAL_CC2430ControlM$TX_TimeOutStopTask$postTask();

  if (HAL_CC2430ControlM$WaitACK_Flag == 1) {
      HAL_CC2430ControlM$ACK_TimerOutSetTask$postTask();
    }
  else {
#line 223
    if (HAL_CC2430ControlM$transmitInProgress) {
        HAL_CC2430ControlM$transmitInProgress = FALSE;
        HAL_CC2430ControlM$sendPacketDoneSUCCTask$postTask();
      }
    }
}

# 57 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static   void Hpl_CC2430InterruptsC$InterruptTXDone$fired(void){
#line 57
  HAL_CC2430ControlM$InterruptTXDone$fired();
#line 57
}
#line 57
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 158 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGRecv$UARTRecv(uint8_t recv_Char)
#line 158
{
  if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving == 0) {
      if (recv_Char == 0x7E) {
          /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving = 1;
          /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex = 0;
        }
    }
  else 
#line 164
    {
      if (recv_Char == 0x7E) {

          /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving = 0;
          if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex > sizeof(serial_header_t )) {
              serial_packet_t *pack = (serial_packet_t *)&/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[3];
              cc2430_header_t *CC2430_pack = (cc2430_header_t *)&/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag;

#line 171
              /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvAckType = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[0];
              /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvSeq = /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[1];
#line 184
              if (pack->header.length > 28) {
                return;
                }
              CC2430_pack->length = pack->header.length;
              CC2430_pack->destpan = TOS_AM_GROUP;
              CC2430_pack->dest = pack->header.dest;
              CC2430_pack->src = TOS_NODE_ID;
              CC2430_pack->type = pack->header.type;

              memcpy(/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$UartRecvMessag.data, pack->data, pack->header.length);

              /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$postTask();
            }
        }
      else {
#line 198
        if (recv_Char == 0x7D) {
            /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Escape_Flag = 1;
          }
        else {
#line 201
          if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Escape_Flag == 1) {
              /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Escape_Flag = 0;
              if (recv_Char == 0x5D) {
                  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex++] = 0x7D;
                }
              else {
#line 205
                if (recv_Char == 0x5E) {
                    /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex++] = 0x7E;
                  }
                else 
#line 207
                  {
                    /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex++] = 0x7D;
                  }
                }
            }
          else {
#line 211
            if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex == 127) {
                /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$NowReceiving = 0;
              }
            else {
                /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$RecvBuff[/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$Rindex++] = recv_Char;
              }
            }
          }
        }
    }
}

# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGRecv.nc"
inline static   void SCSuartDBGM$SCSuartDBGRecv$UARTRecv(uint8_t arg_0x1a8f1e38){
#line 30
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGRecv$UARTRecv(arg_0x1a8f1e38);
#line 30
}
#line 30
# 63 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGM.nc"
static inline   void SCSuartDBGM$HPLUART$get(uint8_t data)
#line 63
{
  SCSuartDBGM$SCSuartDBGRecv$UARTRecv(data);
}

# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
inline static   void HalCC2430SimpleUartP$uart0$get(uint8_t arg_0x1ab72270){
#line 47
  SCSuartDBGM$HPLUART$get(arg_0x1ab72270);
#line 47
}
#line 47
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static   error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$postTask(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = SchedulerBasicP$TaskBasic$postTask(/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask);
#line 56

#line 56
  return result;
#line 56
}
#line 56
# 143 "/opt/tinyos-2.x/tos/platforms/cc2431/SerialActiveMessageP.nc"
static inline   void /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGIdle$UARTIdle(void)
#line 143
{
  if (/*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendProcessing == 1) {
      /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$postTask();
    }
}

# 30 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGIdle.nc"
inline static   void SCSuartDBGM$SCSuartDBGIdle$UARTIdle(void){
#line 30
  /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SCSuartDBGIdle$UARTIdle();
#line 30
}
#line 30
# 105 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
static inline   error_t HalCC2430SimpleUartP$uart0$put(uint8_t data)
#line 105
{
  U0BUF = data;
  return SUCCESS;
}

# 41 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
inline static   error_t SCSuartDBGM$HPLUART$put(uint8_t arg_0x1ab76cb8){
#line 41
  unsigned char result;
#line 41

#line 41
  result = HalCC2430SimpleUartP$uart0$put(arg_0x1ab76cb8);
#line 41

#line 41
  return result;
#line 41
}
#line 41
# 67 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGM.nc"
static inline   void SCSuartDBGM$HPLUART$putDone(void)
#line 67
{
  SCSuartDBGM$buff_start++;

  if (SCSuartDBGM$buff_start > 127 - 1) {
    SCSuartDBGM$buff_start = 0;
    }
  if (SCSuartDBGM$buff_end > 127 - 1) {
    SCSuartDBGM$buff_end = 0;
    }
  if (SCSuartDBGM$buff_start != SCSuartDBGM$buff_end) {
      SCSuartDBGM$HPLUART$put(SCSuartDBGM$str_buff[SCSuartDBGM$buff_start]);
    }
  else {
      SCSuartDBGM$state = 0;
      SCSuartDBGM$SCSuartDBGIdle$UARTIdle();
    }
}

# 53 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
inline static   void HalCC2430SimpleUartP$uart0$putDone(void){
#line 53
  SCSuartDBGM$HPLUART$putDone();
#line 53
}
#line 53
# 144 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
static inline    void HalCC2430SimpleUartP$uart1$default$get(uint8_t data)
#line 144
{
}

# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
inline static   void HalCC2430SimpleUartP$uart1$get(uint8_t arg_0x1ab72270){
#line 47
  HalCC2430SimpleUartP$uart1$default$get(arg_0x1ab72270);
#line 47
}
#line 47
# 145 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
static inline    void HalCC2430SimpleUartP$uart1$default$putDone(void)
#line 145
{
}

# 53 "/opt/tinyos-2.x/tos/lib/serial/SerialByteComm.nc"
inline static   void HalCC2430SimpleUartP$uart1$putDone(void){
#line 53
  HalCC2430SimpleUartP$uart1$default$putDone();
#line 53
}
#line 53
# 52 "/opt/tinyos-2.x/tos/system/RealMainP.nc"
  int main(void)
#line 52
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {






      RealMainP$Scheduler$init();





      RealMainP$PlatformInit$init();
      while (RealMainP$Scheduler$runNextTask()) ;





      RealMainP$SoftwareInit$init();
      while (RealMainP$Scheduler$runNextTask()) ;
    }
#line 76
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  RealMainP$Boot$booted();


  RealMainP$Scheduler$taskLoop();




  return -1;
}

# 130 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
static  bool SchedulerBasicP$Scheduler$runNextTask(void)
{
  uint8_t nextTask;

  /* atomic removed: atomic calls only */
#line 134
  {
    nextTask = SchedulerBasicP$popTask();
    if (nextTask == 255) 
      {
        {
          unsigned char __nesc_temp = 
#line 138
          FALSE;

#line 138
          return __nesc_temp;
        }
      }
  }
#line 141
  SchedulerBasicP$TaskBasic$runTask(nextTask);
  return TRUE;
}

#line 171
static   void SchedulerBasicP$TaskBasic$default$runTask(uint8_t id)
{
}

# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static  void SchedulerBasicP$TaskBasic$runTask(uint8_t arg_0x1a420d78){
#line 64
  switch (arg_0x1a420d78) {
#line 64
    case /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire:
#line 64
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$HandleFire$runTask();
#line 64
      break;
#line 64
    case /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer:
#line 64
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$signalOneTimer$runTask();
#line 64
      break;
#line 64
    case FloodingM$RecvToAPP_task:
#line 64
      FloodingM$RecvToAPP_task$runTask();
#line 64
      break;
#line 64
    case FloodingM$Forwarding_task:
#line 64
      FloodingM$Forwarding_task$runTask();
#line 64
      break;
#line 64
    case CC2430ActiveMessageM$Backoff_Task:
#line 64
      CC2430ActiveMessageM$Backoff_Task$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$sendPacketDoneSUCCTask:
#line 64
      HAL_CC2430ControlM$sendPacketDoneSUCCTask$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$sendPacketDoneFAILTask:
#line 64
      HAL_CC2430ControlM$sendPacketDoneFAILTask$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$transmitTask:
#line 64
      HAL_CC2430ControlM$transmitTask$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$TX_TimeOutStopTask:
#line 64
      HAL_CC2430ControlM$TX_TimeOutStopTask$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$ACK_TimerOutSetTask:
#line 64
      HAL_CC2430ControlM$ACK_TimerOutSetTask$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$ReceivedPacketDone:
#line 64
      HAL_CC2430ControlM$ReceivedPacketDone$runTask();
#line 64
      break;
#line 64
    case HAL_CC2430ControlM$receivedPacketTask:
#line 64
      HAL_CC2430ControlM$receivedPacketTask$runTask();
#line 64
      break;
#line 64
    case Hpl_Backoff_Timer3M$EventFired:
#line 64
      Hpl_Backoff_Timer3M$EventFired$runTask();
#line 64
      break;
#line 64
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask:
#line 64
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask();
#line 64
      break;
#line 64
    case /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask:
#line 64
      /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SendDoneTask$runTask();
#line 64
      break;
#line 64
    case /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv:
#line 64
      /*SerialActiveMessageC.AM*/SerialActiveMessageP$0$SignalToUARTRecv$runTask();
#line 64
      break;
#line 64
    default:
#line 64
      SchedulerBasicP$TaskBasic$default$runTask(arg_0x1a420d78);
#line 64
      break;
#line 64
    }
#line 64
}
#line 64
# 85 "/opt/tinyos-2.x/tos/platforms/cc2431/SCSuartDBGM.nc"
static   void SCSuartDBGM$SCSuartDBG$UARTSend(uint8_t *data, uint8_t len)
#line 85
{
  uint8_t i;

  if (SCSuartDBGM$buff_start > 127 - 1) {
    SCSuartDBGM$buff_start = 0;
    }
  for (i = 0; i < len; i++) {
      if (SCSuartDBGM$buff_end > 127 - 1) {
        SCSuartDBGM$buff_end = 0;
        }
#line 94
      SCSuartDBGM$str_buff[SCSuartDBGM$buff_end] = data[i];
      SCSuartDBGM$buff_end++;
    }

  if (SCSuartDBGM$state == 0) {
      SCSuartDBGM$state = 1;
      SCSuartDBGM$HPLUART$put(SCSuartDBGM$str_buff[SCSuartDBGM$buff_start]);
    }
}

# 151 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void)
#line 151
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current != /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$QUEUE_EMPTY) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(nextMsg);

#line 159
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask();
        }
    }
}

# 87 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static  error_t CC2430ActiveMessageM$AMSend$send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len)
#line 87
{
  cc2430_header_t *header = (cc2430_header_t *)msg;




  if (addr == TOS_NODE_ID) {
    return FAIL;
    }
  if (len > 28) {
    return ESIZE;
    }
  if (CC2430ActiveMessageM$RF_Status != RF_IDLE) {
    return EBUSY;
    }
  header->length = 12 + len;

  header->fcf &= (uint16_t )(1 << IEEE154_FCF_ACK_REQ);


  if (CC2430ActiveMessageM$AckEnable && addr != AM_BROADCAST_ADDR) {
    header->fcf &= (uint16_t )(1 << IEEE154_FCF_ACK_REQ);
    }
  else {
#line 110
    header->fcf &= (uint16_t )~(1 << IEEE154_FCF_ACK_REQ);
    }
#line 111
  header->fcf |= (((IEEE154_TYPE_DATA << IEEE154_FCF_FRAME_TYPE) | (
  1 << IEEE154_FCF_INTRAPAN)) | (
  IEEE154_ADDR_SHORT << IEEE154_FCF_DEST_ADDR_MODE)) | (
  IEEE154_ADDR_SHORT << IEEE154_FCF_SRC_ADDR_MODE);

  header->dsn = CC2430ActiveMessageM$MAC_Seq++;
  header->destpan = TOS_AM_GROUP;
  header->dest = addr;
  header->src = TOS_NODE_ID;
  header->type = id;




  CC2430ActiveMessageM$TX_Ready_Msg = msg;
  CC2430ActiveMessageM$RF_Status = RF_TX;
  CC2430ActiveMessageM$NumReTX = 0;
  CC2430ActiveMessageM$Backoff_Task$postTask();

  return SUCCESS;
}

# 166 "/opt/tinyos-2.x/tos/platforms/cc2431/SchedulerBasicP.nc"
static   error_t SchedulerBasicP$TaskBasic$postTask(uint8_t id)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 168
    {
#line 168
      {
        unsigned char __nesc_temp = 
#line 168
        SchedulerBasicP$pushTask(id) ? SUCCESS : EBUSY;

        {
#line 168
          __nesc_atomic_end(__nesc_atomic); 
#line 168
          return __nesc_temp;
        }
      }
    }
#line 171
    __nesc_atomic_end(__nesc_atomic); }
}

# 166 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/AMQueueImplP.nc"
static  void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 166
{
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current].msg == msg) {
      uint8_t last = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current;

#line 169
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[last].msg = (void *)0;
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, err);
    }
}

# 283 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static  void *CC2430ActiveMessageM$Packet$getPayload(message_t *msg, uint8_t *len)
#line 283
{
  if (len != (void *)0) {
      *len = CC2430ActiveMessageM$Packet$payloadLength(msg);
    }
  return msg->data;
}

# 87 "FloodingM.nc"
static bool FloodingM$isRecvPrevious(message_t *msg)
#line 87
{
  Route_Msg pack;
  bool return_status = 0;
  uint8_t i;

  memcpy(&pack, FloodingM$SendToMAC$getPayload(msg), sizeof(Route_Msg ));
  for (i = 0; i < 20; i++) {

      if (
#line 94
      FloodingM$RTable[i].FinalDstAddr == pack.FinalDstAddr && 
      FloodingM$RTable[i].OrigiSrcAddr == pack.OrigiSrcAddr && 
      FloodingM$RTable[i].Sequence == pack.Sequence) 
        {
          return_status = 1;
          break;
        }
    }
  return return_status;
}

#line 73
static void FloodingM$insertMSGtoRTable(message_t *msg)
#line 73
{
  Route_Msg pack;

#line 75
  memcpy(&pack, FloodingM$SendToMAC$getPayload(msg), sizeof(Route_Msg ));

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 77
    {
      FloodingM$RTable[FloodingM$RTable_Index].FinalDstAddr = pack.FinalDstAddr;
      FloodingM$RTable[FloodingM$RTable_Index].OrigiSrcAddr = pack.OrigiSrcAddr;
      FloodingM$RTable[FloodingM$RTable_Index].Sequence = pack.Sequence;

      FloodingM$RTable_Index++;
      FloodingM$RTable_Index %= 20;
    }
#line 84
    __nesc_atomic_end(__nesc_atomic); }
}

# 59 "/opt/tinyos-2.x/tos/platforms/cc2431/SCS_VTimerP.nc"
static error_t /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$startTimer(uint8_t id, uint32_t interval, bool isoneshot)
#line 59
{
  uint8_t diff;

#line 61
  if (id >= /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$NUM_TIMERS) {
    return FALSE;
    }
  if (interval == 0) {
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$TimerMilli$fired(id);
      return SUCCESS;
    }

  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[id].ticks = interval;
  /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[id].isoneshot = isoneshot;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 72
    {
      diff = /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$getNow();
      interval += diff;
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[id].ticksLeft = interval;
      /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mTimerList[id].mState = 1;




      if (interval < (uint32_t )/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval) {
          /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval = (uint8_t )interval;
          /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$MilliAlarm$start(/*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$mInterval);
          /*HilTimerMilliC.VTimerP*/SCS_VTimerP$0$setIntervalFlag = 0;
        }
    }
#line 86
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 238 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/HAL_CC2430ControlM.nc"
static  void HAL_CC2430ControlM$ACK_TimeOut$fired(void)
#line 238
{
  HAL_CC2430ControlM$transmitInProgress = FALSE;
  HAL_CC2430ControlM$WaitACK_Flag = 0;
  HAL_CC2430ControlM$flushTXBufferTask();
  HAL_CC2430ControlM$SendDoneError = 0x22;
  HAL_CC2430ControlM$sendPacketDoneFAILTask$postTask();
}

#line 229
static  void HAL_CC2430ControlM$TX_TimeOut$fired(void)
#line 229
{


  HAL_CC2430ControlM$transmitInProgress = FALSE;
  HAL_CC2430ControlM$flushTXBufferTask();
  HAL_CC2430ControlM$SendDoneError = 0x21;
  HAL_CC2430ControlM$sendPacketDoneFAILTask$postTask();
}

# 56 "Adhoc_APPM.nc"
static  void Adhoc_APPM$Timer$fired(void)
#line 56
{

  Adhoc_APP_Msg APP_M;

  APP_M.App_Seq = Adhoc_APPM$APP_Seq++;
  APP_M.Sender_Addr = TOS_NODE_ID;
  APP_M.App_Data[0] = 0xAABB;
  APP_M.App_Data[1] = 0xCCDD;
  APP_M.App_Data[2] = 0xEEFF;
  APP_M.App_Data[3] = 0x1234;
  memcpy(Adhoc_APPM$Rout_Send$getPayload(&Adhoc_APPM$RF_MSG), (uint8_t *)&APP_M, sizeof(Adhoc_APP_Msg ));

  Adhoc_APPM$Leds$led1Toggle();

  if (Adhoc_APPM$Rout_Send$send(0, &Adhoc_APPM$RF_MSG, sizeof(Adhoc_APP_Msg )) == SUCCESS) {
      Adhoc_APPM$Leds$led2On();
    }
}

# 141 "FloodingM.nc"
static  void *FloodingM$SendFromAPP$getPayload(message_t *msg)
#line 141
{
  return FloodingM$SendToMAC$getPayload(msg);
}

# 45 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static  error_t /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 47
{
  /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(msg, dest);
  /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(msg, 11);
  return /*FloodingC.AMSenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(msg, len);
}

# 67 "/opt/tinyos-2.x/tos/platforms/cc2431/HplSCS_Clock_Timer1P.nc"
static   void HplSCS_Clock_Timer1P$Alarm$start(uint8_t dt)
#line 67
{
  uint8_t *rPtr;
  uint16_t r = dt * HplSCS_Clock_Timer1P$mscale;

  rPtr = (uint8_t *)&r;
  T1CC0L = rPtr[0];
  T1CC0H = rPtr[1];
}

# 133 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/CC2430ActiveMessageM.nc"
static  void CC2430ActiveMessageM$CC2430_TX_RX$sendPacketDone(uint8_t *TXpacket, error_t err)
#line 133
{
  CC2430ActiveMessageM$RF_Status = RF_IDLE;
  CC2430ActiveMessageM$NumReTX = 0;




  CC2430ActiveMessageM$AMSend$sendDone(CC2430ActiveMessageM$AMPacket$type((message_t *)CC2430ActiveMessageM$TX_Ready_Msg), (message_t *)CC2430ActiveMessageM$TX_Ready_Msg, err);
}

# 41 "/opt/tinyos-2.x/tos/platforms/cc2431/RandomC.nc"
static   uint16_t RandomC$Random$rand16(void)
#line 41
{
  RandomC$randValue16 = (uint16_t )RandomC$randValue16 * 133;
  RandomC$randValue16 += RandomC$RSeq++;
  return RandomC$randValue16;
}

# 125 "/opt/tinyos-2.x/tos/platforms/cc2431/Serial.h"
static uint16_t crcByte(uint16_t crc, uint8_t b)
#line 125
{
  uint8_t i;

  crc = crc ^ (b << 8);
  i = 8;
  do 
    if (crc & 0x8000) {
      crc = (crc << 1) ^ 0x1021;
      }
    else {
#line 134
      crc = crc << 1;
      }
  while (
#line 135
  --i);

  return crc;
}

# 25 "/opt/tinyos-2.x/tos/platforms/cc2431/RandomC.nc"
static  error_t RandomC$SeedInit$init(uint16_t param)
#line 25
{
  uint16_t CurrentT = (uint16_t )T1CNTL << 8;

#line 27
  CurrentT |= T1CNTH;
  RandomC$Rseed = param + TOS_NODE_ID + CurrentT;
  RandomC$randValue32 = RandomC$Rseed + 17;
  RandomC$randValue16 = RandomC$Rseed + 31;
  RandomC$RSeq = TOS_NODE_ID;
  return SUCCESS;
}

# 80 "/opt/tinyos-2.x/tos/platforms/cc2431/HplSCS_Clock_Timer1P.nc"
  __attribute((interrupt)) void __vector_9(void)
#line 80
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 81
    {
      if (T1CTL & CC2430_T1_OVFIF) {
          T1CTL &= (unsigned char )~CC2430_T1_OVFIF;
        }

      if (T1CCTL0 & (unsigned char )(1 << CC2430_T1CCTLx_IM) && T1CTL & CC2430_T1_CH0IF) {
          T1CTL &= (unsigned char )~CC2430_T1_CH0IF;
          HplSCS_Clock_Timer1P$Alarm$fired();
        }
    }
#line 90
    __nesc_atomic_end(__nesc_atomic); }
}

# 96 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_CC2430InterruptsC.nc"
  __attribute((interrupt)) void __vector_0(void)
#line 96
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 97
    {
      RFERRIF = 0;
      Hpl_CC2430InterruptsC$InterruptRFErr$fired();
    }
#line 100
    __nesc_atomic_end(__nesc_atomic); }
}

  __attribute((interrupt)) void __vector_16(void)
#line 103
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 105
    {
      uint8_t RFIF_RFIM = RFIF & RFIM;







      RFIF = 0;

      if (RFIF_RFIM & (unsigned char )(1 << CC2430_RFIF_CCA)) {
          Hpl_CC2430InterruptsC$InterruptCCA$fired();
        }

      if (RFIF_RFIM & (unsigned char )(1 << CC2430_RFIF_FIFOP)) {
          Hpl_CC2430InterruptsC$InterruptFIFOP$fired();
        }

      if (RFIF_RFIM & (unsigned char )(1 << CC2430_RFIF_TXDONE)) {
          Hpl_CC2430InterruptsC$InterruptTXDone$fired();
        }


      S1CON = 0;
    }
#line 130
    __nesc_atomic_end(__nesc_atomic); }
}

# 110 "/opt/tinyos-2.x/tos/platforms/cc2431/HalCC2430SimpleUartP.nc"
  __attribute((interrupt)) void __vector_2(void)
#line 110
{
  URX0IF = 0;
  HalCC2430SimpleUartP$uart0$get(U0BUF);
}

  __attribute((interrupt)) void __vector_7(void)
#line 115
{
  if (!(U0CSR & 0x1)) {
      UTX0IF = 0;
      HalCC2430SimpleUartP$uart0$putDone();
    }
}











  __attribute((interrupt)) void __vector_3(void)
#line 132
{
  URX1IF = 0;
  HalCC2430SimpleUartP$uart1$get(U1DBUF);
}

  __attribute((interrupt)) void __vector_14(void)
#line 137
{
  if (!(U1CSR & 0x1)) {
      UTX1IF = 0;
      HalCC2430SimpleUartP$uart1$putDone();
    }
}

# 80 "/opt/tinyos-2.x/tos/platforms/cc2431/RF/Hpl_Backoff_Timer3M.nc"
  __attribute((interrupt)) void __vector_11(void)
#line 80
{

  if (T3CCTL0 & (unsigned char )(1 << CC2430_T1CCTLx_MODE) && T3CH0IF) {
      T3CH0IF = 0;
      T3IE = 0;
      T3CTL &= (uint8_t )~ (unsigned char )(1 << CC2430_T34CTL_START);
      Hpl_Backoff_Timer3M$EventFired$postTask();
    }
}

