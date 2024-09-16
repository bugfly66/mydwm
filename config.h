/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 18;        /* 2 is the default spacing around the bar's font */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10; 
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "monospace:size=12","WenQuanYi Micro Hei:size=12:type=Regular:antialias=true:autohint=true","JetBrainsMono Nerd Font:pixelsize=24:type=Regular;antialias=true:autohint=true","JoyPixels:pixelsize=24:type=Regular:antialias=true:autohint=true",        };
static const char dmenufont[]       = "monospace:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col1[]            = "#63e398";
static const char col2[]            = "#00ffff";
static const char col3[]            = "#ff00ff";
static const char col4[]            = "#ffff00";
static const char col5[]            = "#ffffff";
static const char col6[]            = "#ffffff";
static const char warn[]			= "#eed202";
static const char err[]				= "#ee0000";
static const unsigned int baralpha = 0x99;
static const unsigned int borderalpha = OPAQUE;
enum { SchemeNorm, SchemeSel,SchemeCol1, SchemeCol2, SchemeCol3, SchemeCol4,
       SchemeCol5, SchemeCol6, SchemeWarn,SchemeErr}; /* color schemes */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3,	col_gray1, col_gray2 },
	[SchemeSel]  = { col1,		col_gray1, col_gray2  },
	[SchemeCol1]  = { col1,		col_gray1, col_gray2 },
	[SchemeCol2]  = { col2,		col_gray1, col_gray2 },
	[SchemeCol3]  = { col3,		col_gray1, col_gray2 },
	[SchemeCol4]  = { col4,		col_gray1, col_gray2 },
	[SchemeCol5]  = { col5,		col_gray1, col_gray2 },
	[SchemeCol6]  = { col6,		col_gray1, col_gray2 },
	[SchemeWarn]  = { warn,		col_gray1, col_gray2 },
	[SchemeErr]  = { err,		col_gray1, col_gray2 },
};

static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol3]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol4]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol5]  = { OPAQUE, baralpha, borderalpha },
	[SchemeCol6]  = { OPAQUE, baralpha, borderalpha },
	[SchemeWarn]  = { OPAQUE, baralpha, borderalpha },
	[SchemeErr]  = { OPAQUE, baralpha, borderalpha },
};

/*autostart command*/
static const char *const autostart[] = {
    "xrandr","--output","eDP","--mode","3072x1920","--rate","120",NULL,
	"sh","-c","~/scripts/wp-autochange.sh","&",NULL,
	"sh","-c","~/scripts/tap-to-click.sh","&",NULL,
    "sh","-c","~/scripts/inverse-scroll.sh","&",NULL,
	//"sh","-c","~/scripts/statusbar-refresh.sh","&",NULL,
	"picom","-b",NULL,
	"sudo","chronyd","-q",NULL,
	"fcitx5","&",NULL,
	"sh","-c","~/scripts/musicctl","&",NULL,
	"dunst","-config","~/.config/dunst.conf","&",NULL,
	"dsblocks","&",NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = { " ₁", " ₂", " ₃", " ₄", " ₅", " ₆", " ₇",  " ₈", };
static const unsigned int ulinepad	= 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 4;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define HOMEPATH "/home/zx/"
/* commands */
static char scratchpadname[] = "scratchpad"; 
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "drun", "-theme","rod", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname,"-g", "120x34", NULL };
//static const char *browsercmd[] = {"microsoft-edge-stable", NULL};
static const char *zoterocmd[] = {"zotero", NULL};
static const char *codecmd[] = {"code", NULL};
static const char *volupcmd[]={HOMEPATH"scripts/volume-up.sh",NULL};
static const char *voldowncmd[]={HOMEPATH"scripts/volume-down.sh",NULL};
static const char *voltogglecmd[]={HOMEPATH"scripts/volume-toggle.sh",NULL};
static const char *captogglecmd[] = {HOMEPATH"scripts/capture-toggle.sh",NULL};
static const char *brightnessupcmd[] = {HOMEPATH"scripts/brightness-up.sh",NULL};
static const char *brightnessdowncmd[] = {HOMEPATH"scripts/brightness-down.sh",NULL};
static const char *touchpadtogglecmd[]={HOMEPATH"scripts/toggle-touchpad.sh",NULL};

Autostarttag autostarttaglist[] = {
       {.cmd = termcmd, .tags = 1 << 0 },
       {.cmd = zoterocmd, .tags = 1 << 1 },
       {.cmd = codecmd, .tags = 1 << 2 },
       {.cmd = NULL, .tags = 0 },
};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = voltogglecmd} },
	{ MODKEY,                       XK_F2,     spawn,          {.v = voldowncmd} },
	{ MODKEY,                       XK_F3,     spawn,          {.v = volupcmd} },
	{ MODKEY,                       XK_F4,     spawn,          {.v = captogglecmd} },
	{ MODKEY,                       XK_F5,     spawn,          {.v = brightnessdowncmd}},
	{ MODKEY,                       XK_F6,     spawn,          {.v = brightnessupcmd}},
	{ MODKEY,                       XK_F8,     spawn,          {.v = touchpadtogglecmd}},
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	// { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkStatusText,        0,              Button1,        sigdsblocks,    {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdsblocks,    {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdsblocks,    {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

