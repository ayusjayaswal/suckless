/*
██████╗ ██╗    ██╗███╗   ███╗
██╔══██╗██║    ██║████╗ ████║
██║  ██║██║ █╗ ██║██╔████╔██║ 
██║  ██║██║███╗██║██║╚██╔╝██║ Author: Ayush Jayaswal
██████╔╝╚███╔███╔╝██║ ╚═╝ ██║ Dwm Config File
╚═════╝  ╚══╝╚══╝ ╚═╝     ╚═╝
*/
/* appearance */
static const unsigned int borderpx = 2;   /* border pixel of windows */
static const unsigned int snap     = 32;  /* snap pixel */
static const unsigned int gappx    = 6;   /* pixel gap between clients */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 1;   /* 0 means bottom bar */
static const int horizpadbar       = 6;   /* horizontal padding for statusbar */
static const int vertpadbar        = 7;   /* vertical padding for statusbar */
static const char *fonts[]     = { "JetBrainsMono Nerd Font:weight=bold:size=9:antialias=true:hinting=true",
                                    "Mononoki:size=9:antialias=true:autohint=true",
                                    "Hack:size=8:antialias=true:autohint=true",
                                    "Symbola:size=10:antialias=true:autohint=true"
                                  };
static const char col_1[]  = "#282828"; 
static const char col_2[]  = "#ff9d57"; 
/* static const char col_2[]  = "#ff7376"; */
static const char col_3[]  = "#ebdbb2";
static const char col_4[]  = "#625e5e";
static const char col_5[]  = "#cf844e";
/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * 0xdd adds adds a bit more transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0xbb; 
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_3, col_1, col_1 },
	[SchemeSel]  = { col_1, col_2, col_5 },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; 
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "Pcmanfm",     NULL,       NULL,       0,          True,           -1 },
    { "XCalc",     NULL,       NULL,       0,          True,           -1 },
};
/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "匿" ,    tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "ﬕ",      monocle },
    { "",      dwindle },
    { "",      spiral },
	{ "恵",     centeredmaster },
    { " ",     centeredfloatingmaster },
	/* { "",      grid }, */
	{ NULL,     NULL },
};
/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* dmenu */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* If you are using the standard dmenu program, use the following. */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "   ", NULL };
static const char *termcmd[]     = { "alacritty", NULL };
static const char *termzsh[]     = { "st", NULL };
static Key keys[] = {
	/* modifier             chain key  key        function        argument */
	{ MODKEY|ShiftMask,     -1,        XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,               -1,        XK_Return, spawn,          {.v = termzsh } },
	{ MODKEY|ControlMask,   -1,        XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,               -1,        XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,     -1,        XK_s,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,     -1,        XK_w,      rotatestack,    {.i = -1 } },
	{ MODKEY,               -1,        XK_s,      focusstack,     {.i = +1 } },
	{ MODKEY,               -1,        XK_w,      focusstack,     {.i = -1 } },
	{ MODKEY,               -1,        XK_d,      setmfact,       {.f = -0.05} }, /*Decrease master*/
	{ MODKEY,               -1,        XK_i,      setmfact,       {.f = +0.05} }, /*Increase master*/
	{ MODKEY,               -1,        XK_backslash,    view,           {0} },
	{ MODKEY,		        -1,        XK_x,      killclient,     {0} },

    /* Layout manipulation */
	{ MODKEY,               -1,        XK_Tab,    cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,     -1,        XK_Tab,    cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,     -1,        XK_space,  togglefloating, {0} },
    /* Switch to specific layouts */
	{ MODKEY,               -1,        XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,               -1,        XK_f,      fullscreen,      {0} }, 
    { MODKEY,               -1,        XK_u,      setlayout,      {.v = &layouts[3]} },
 	{ MODKEY,               -1,        XK_c,      setlayout,      {.v = &layouts[5]} },

	{ MODKEY,               -1,        XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     -1,        XK_0,      tag,            {.ui = ~0 } },
	
    /* Keybindings for programs using the format SUPER + ALT + "key" */
	
	TAGKEYS(                -1,        XK_1,                      0)
	TAGKEYS(                -1,        XK_2,                      1)
	TAGKEYS(                -1,        XK_3,                      2)
	TAGKEYS(                -1,        XK_4,                      3)
	TAGKEYS(                -1,        XK_5,                      4)
	TAGKEYS(                -1,        XK_6,                      5)
	TAGKEYS(                -1,        XK_7,                      6)
	TAGKEYS(                -1,        XK_8,                      7)
	TAGKEYS(                -1,        XK_9,                      8)
	{ MODKEY|ShiftMask,     -1,        XK_q,	  quit,		      {0} },
    { MODKEY|ShiftMask,     -1,        XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask   button          function        argument */
	{ ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,     0,           Button2,        zoom,           {0} },
	{ ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
	{ ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
	{ ClkTagBar,       0,           Button1,        view,           {0} },
	{ ClkTagBar,       0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
	{ ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};

